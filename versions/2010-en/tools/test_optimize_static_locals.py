import unittest

from optimize_static_locals import promote_static_locals


ADDRESS = 0x417aa0


def routine(body):
    return ('export function originalExample(memory, dc, rng, options = {}, ...originalArgs) {\n'
            f'  const localFrame=createLocalFrame(32,options.retainedDrawingStack?.[{ADDRESS}]??[]);\n'
            f'{body}\n}}')


class StaticLocalPromotionTests(unittest.TestCase):
    def promote(self, body):
        source = routine(body)
        return source, *promote_static_locals(source, 'originalExample', ADDRESS, 32)

    def test_nested_reads_semantic_float_store_and_exact_fallback(self):
        source, emitted, record = self.promote(
            '  writeLocal(framePointer(localFrame,0),dc,4,"int");\n'
            '  writeLocal(framePointer(localFrame,8),readLocal(framePointer(localFrame,0),4,"int"),8,"float");\n'
            '  return readLocalArgument(framePointer(localFrame,8),8,"float");')
        self.assertTrue(record['eligible'])
        fast, fallback = emitted.split('\n\nfunction originalExampleByteFrame', 1)
        self.assertNotIn('localFrame', fast)
        self.assertIn('scalarStack8=scalarStoreF64(scalarRead(scalarStack0))', fast)
        self.assertIn('return scalarReadArgument(scalarStack8);', fast)
        expected = source.replace('export function originalExample(memory, dc, rng, options = {}, ...originalArgs)',
                                  '(memory, dc, rng, options, originalArgs, retainedLocalBytes)')
        expected = expected.replace(f'createLocalFrame(32,options.retainedDrawingStack?.[{ADDRESS}]??[])',
                                    'createLocalFrame(32,retainedLocalBytes)')
        self.assertEqual(fallback, expected)

    def test_literal_text_does_not_become_an_access_or_escape(self):
        _source, emitted, record = self.promote(
            '  writeLocal(framePointer(localFrame,0),"readLocal(framePointer(localFrame,31),8,\\"float\\")",4,"int");\n'
            '  return readLocal(framePointer(localFrame,0),4,"int");')
        self.assertTrue(record['eligible'])
        self.assertIn('"readLocal(framePointer(localFrame,31),8,\\"float\\")"', emitted)

    def test_cfg_statement_writes_are_promoted(self):
        _source, emitted, record = self.promote(
            '  let pc = 2;\n  for (;;) { switch (pc) {\n'
            '    case 1: { return readLocal(framePointer(localFrame,0),4,"int"); }\n'
            '    case 2: { writeLocal(framePointer(localFrame,0),originalArgs[0],4,"int"); pc = 1; continue; }\n'
            '  } }')
        self.assertTrue(record['eligible'])
        self.assertIn('case 2: { scalarStack0=scalarStoreI32(originalArgs[0]); pc = 1; continue;', emitted)

    def test_unsupported_accesses_keep_source_byte_identical(self):
        rejected = {
            'mixed width': '  writeLocal(framePointer(localFrame,0),dc,4,"int");\n  return readLocal(framePointer(localFrame,0),8,"float");',
            'overlap': '  writeLocal(framePointer(localFrame,0),dc,8,"float");\n  return readLocal(framePointer(localFrame,4),4,"int");',
            'escape': '  writeLocal(framePointer(localFrame,0),dc,4,"int");\n  return framePointer(localFrame,0);',
            'array': '  return readLocal(framePointer(localFrame,index),4,"int");',
            'implicit kind': '  writeLocal(framePointer(localFrame,0),dc,4);',
            'qword integer': '  return readLocal(framePointer(localFrame,0),8,"int");',
            'partial width': '  return readLocal(framePointer(localFrame,0),2,"int");',
            'out of bounds': '  return readLocal(framePointer(localFrame,28),8,"float");',
            'negative offset': '  return readLocal(framePointer(localFrame,-4),4,"int");',
            'assignment result': '  let result = writeLocal(framePointer(localFrame,0),dc,4,"int");',
            'return result': '  return writeLocal(framePointer(localFrame,0),dc,4,"int");',
            'ternary result': '  true ? undefined : writeLocal(framePointer(localFrame,0),dc,4,"int");',
            'comma result': '  let result = (undefined,writeLocal(framePointer(localFrame,0),dc,4,"int"));',
            'shore restore': '  restoreShoreStackFrame(localFrame,options.shoreStack);\n  return readLocal(framePointer(localFrame,0),4,"int");',
            'generated identifier collision': '  let scalarStack0;\n  return readLocal(framePointer(localFrame,0),4,"int");',
        }
        for name, body in rejected.items():
            with self.subTest(name=name):
                source, emitted, record = self.promote(body)
                self.assertFalse(record['eligible'])
                self.assertEqual(source, emitted)


if __name__ == '__main__':
    unittest.main()

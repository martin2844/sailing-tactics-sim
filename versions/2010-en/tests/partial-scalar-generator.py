"""Regression checks for the private slots beside 0x466330's aliased arrays."""
from pathlib import Path
import re
import json
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import translate_drawing as drawing
import floating_drawing as floating
from optimize_static_locals import promote_static_locals, _promote_water_private_locals


class PartialScalarProof(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        # Exercise the real C emitter, rather than copying a hand-written JS
        # fixture that could silently diverge from the authoritative source.
        captured = []
        original = floating.promote_static_locals

        def capture(source, name, address, frame_size, **kwargs):
            if address == 0x466330:
                captured.append(source)
            return source, {'eligible': False}

        try:
            floating.promote_static_locals = capture
            source = (ROOT / 'analysis/drawing-corrections/00466330.c').read_text()
            translator = drawing.Translator('originalDrawing00466330', 0x466330, source)
            translator.generate('originalDrawing00466330')
        finally:
            floating.promote_static_locals = original
        cls.raw = captured[0]

    def promote(self, source=None, **kwargs):
        return promote_static_locals(source if source is not None else self.raw,
            kwargs.get('name', 'originalDrawing00466330Number'),
            kwargs.get('address', 0x466330), kwargs.get('frame_size', 880),
            numeric_floats=kwargs.get('numeric_floats', True))

    def reject(self, source, reason):
        generated, record = self.promote(source)
        self.assertFalse(record['eligible'])
        self.assertEqual(generated, source)
        self.assertIn(reason, record['reason'])

    def byte_body(self):
        expected = self.raw.replace(
            'export function originalDrawing00466330Number(memory, dc, rng, options = {}, ...originalArgs)',
            'function originalDrawing00466330NumberByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)', 1)
        return expected.replace(
            'const localFrame=createLocalFrame(880,options.retainedDrawingStack?.[4612912]??[]);',
            'const localFrame=createLocalFrame(880,retainedLocalBytes);', 1)

    def test_actual_emitter_promotes_nine_disjoint_slots(self):
        generated, record = self.promote()
        self.assertTrue(record['eligible'], record)
        self.assertEqual([row['offset'] for row in record['slots']],
                         [0, 4, 12, 20, 24, 264, 280, 308, 552])
        self.assertEqual(record['scalarAccesses'], 115)
        self.assertEqual(record['induction']['iterations'], 18)
        self.assertEqual(record['retainedByteRanges'], [
            {'start': 256, 'end': 264}, {'start': 272, 'end': 280}])
        self.assertEqual(record['arrays'], [
            {'offset': 396, 'size': 4, 'kind': 'int', 'length': 18},
            {'offset': 476, 'size': 4, 'kind': 'int', 'length': 18},
            {'offset': 568, 'size': 8, 'kind': 'float', 'length': 18},
            {'offset': 728, 'size': 8, 'kind': 'float', 'length': 18}])
        self.assertEqual(record['arrayAccesses'], 128)
        # Eighteen cells stop at548. Nineteen would end exactly at552; the
        # twentieth would overwrite the independently promoted F64 at552.
        self.assertEqual(476 + 17 * 4 + 4, 548)
        self.assertEqual(476 + 18 * 4 + 4, 552)
        self.assertEqual(476 + 19 * 4, 552)
        promoted = generated[:-len(self.byte_body()) - 2]
        for row in record['slots']:
            self.assertNotIn(f'framePointer(localFrame,{row["offset"]})', promoted)
        for offset in [396, 476, 568, 728]:
            self.assertNotIn(f'framePointer(localFrame,{offset})', promoted)
        for offset in [256, 272]:
            self.assertIn(f'framePointer(localFrame,{offset})', promoted)
        self.assertIn('scalarArray396[iVar24>>>2]=scalarStoreI32(r32(0x523660))', promoted)
        self.assertIn('scalarArray476[iVar24>>>2]=scalarStoreI32(r32(0x4fed58))', promoted)
        self.assertIn('scalarFloatWordsNumber(scalarArray568[iVar16>>>3])', promoted)
        self.assertIn('scalarFloatWordsNumber(scalarArray728[iVar16>>>3])', promoted)
        for field in ['events', 'frame', 'dc', 'array']:
            self.assertIn(f"'{field}' in Number.prototype", promoted)
        self.assertIn('const localFrame=createLocalFrame(880,[]);', promoted)
        self.assertIn('scalarStack4=scalarStoreF64(fpFormalF64(originalArgs[0],numberArgumentImages))', promoted)
        self.assertIn('scalarRead(scalarStack264)', promoted)
        self.assertIn('scalarRead(scalarStack4)', promoted)

    def test_first_nine_slot_stage_retains_all_array_bytes(self):
        generated, record = _promote_water_private_locals(self.raw,
            'originalDrawing00466330Number', 0x466330, 880, promote_arrays=False)
        self.assertTrue(record['eligible'])
        self.assertNotIn('arrays', record)
        self.assertEqual(record['scalarAccesses'], 115)
        self.assertEqual(record['retainedByteRanges'], [
            {'start': 396, 'end': 468}, {'start': 476, 'end': 548},
            {'start': 568, 'end': 712}, {'start': 728, 'end': 872}])
        promoted = generated[:-len(self.byte_body()) - 2]
        for offset in [256, 272, 396, 476, 568, 728]:
            self.assertIn(f'framePointer(localFrame,{offset})', promoted)

    def test_retained_path_is_the_complete_unmodified_byte_body(self):
        generated, _record = self.promote()
        expected = self.byte_body()
        self.assertTrue(generated.endswith('\n\n' + expected))
        self.assertIn('if(retainedLocalBytes!=null)return originalDrawing00466330NumberByteFrame(', generated)
        edges = lambda source: re.findall(r'\bpc = (?:(\d+)|[^\n]* \? (\d+) : (\d+)); continue;', source)
        scalar_body = generated[:-len(expected) - 2]
        self.assertEqual(edges(scalar_body), edges(self.raw))

    def test_only_the_reviewed_number_function_is_eligible(self):
        for arguments in [{'numeric_floats': False}, {'address': 0x466331},
                          {'name': 'unreviewedNumber'}, {'frame_size': 881}]:
            generated, record = self.promote(**arguments)
            self.assertFalse(record['eligible'])
            self.assertEqual(generated, self.raw)

    def test_larger_loop_that_can_reach_slot552_is_rejected(self):
        self.reject(self.raw.replace('cCompare(iVar16,137,"<")', 'cCompare(iVar16,153,"<")'),
                    'induction proof')
        self.reject(self.raw.replace('(iVar24 = cAdd(iVar24,4))', '(iVar24 = cAdd(iVar24,8))'),
                    'induction proof')

    def test_missing_initialization_or_other_loop_entry_is_rejected(self):
        self.reject(self.raw.replace('(iVar24 = 0); pc = 188;', '(iVar24 = 4); pc = 188;'),
                    'induction proof')
        self.reject(self.raw.replace('case 3: { (iVar16 = 0); pc = 2;',
                                     'case 3: { (iVar16 = 0); pc = 171;'), 'bypass')
        self.reject(self.raw.replace('let pc = 278;', 'let pc = 171;'), 'initial entry')

    def test_body_cannot_change_induction_variables(self):
        for assignment in ['iVar16 = 8;', 'iVar24 +=4;', '++iVar24;']:
            self.reject(self.raw.replace('case 172: { ', f'case 172: {{ {assignment} '),
                        'changes an induction variable')

    def test_overlapping_fixed_width_view_is_rejected(self):
        self.reject(self.raw.replace('readLocal(framePointer(localFrame,264),8,"float")',
                                     'readLocal(framePointer(localFrame,264),4,"int")', 1),
                    'overlapping byte view')
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { writeLocal(framePointer(localFrame,550),1,4,"int"); '), 'overlapping byte view')

    def test_unproved_address_escape_is_rejected(self):
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { consumeFrame(localFrame); '), 'escapes reviewed byte accesses')
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { readPointer(memory,pointerAdd(framePointer(localFrame,552),0),4); '),
                    'unproved escape')

    def test_dynamic_access_only_occurs_in_the_proved_loop(self):
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { writePointer(memory,cAdd(cI32(framePointer(localFrame,396),false),iVar24),1,4); '),
                    'exceeds the induction proof')
        self.reject(self.raw.replace('readLocalFloatWordsNumber(memory,cAdd(cI32(framePointer(localFrame,568),false),iVar16))',
            'readLocalFloatWordsNumber(memory,cAdd(cI32(framePointer(localFrame,552),false),iVar16))'), 'unproved escape')

    def test_observed_store_result_is_rejected(self):
        self.reject(self.raw.replace('writeLocal(framePointer(localFrame,552)',
                                     '(dVar1=writeLocal(framePointer(localFrame,552)', 1),
                    'write result is observable')

    def test_array_cells_cannot_acquire_an_unaligned_or_reinterpreted_view(self):
        self.reject(self.raw.replace('readLocal(framePointer(localFrame,576),8,"float")',
                                     'readLocal(framePointer(localFrame,576),4,"int")', 1),
                    'overlapping or unaligned view')
        self.reject(self.raw.replace('framePointer(localFrame,576)', 'framePointer(localFrame,574)', 1),
                    'overlapping or unaligned view')
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { writePointer(memory,pointerAdd(framePointer(localFrame,396),cMul(0,4)),1,4); '),
                    'unproved constant write')

    def test_array_cells_cannot_add_an_observed_store_result(self):
        self.reject(self.raw.replace('writeLocal(framePointer(localFrame,704)',
                                     '(dVar1=writeLocal(framePointer(localFrame,704)', 1),
                    'array write result is observable')

    def test_extra_constant_byte_view_cannot_reinterpret_array_cells(self):
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { readPointer(memory,pointerAdd(framePointer(localFrame,568),0),4); '),
                    'unproved escape')
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { readLocalArgument(framePointer(localFrame,568),8,"float"); '),
                    'unreviewed argument load')


if __name__ == '__main__':
    if '--emit-cell-contract' in sys.argv:
        result = unittest.TextTestRunner(stream=sys.stderr).run(unittest.defaultTestLoader.loadTestsFromTestCase(PartialScalarProof))
        if not result.wasSuccessful():
            sys.exit(1)
        generated, _record = promote_static_locals(PartialScalarProof.raw,
            'originalDrawing00466330Number', 0x466330, 880, numeric_floats=True)
        lines = [line.strip() for line in generated.splitlines()
                 if line.startswith('  const scalarArray396=') or line.startswith('  const scalarArrayF64Store=') or line.startswith('  const scalarArrayF64Read=') or line.startswith('  const scalarFloatWordsNumber=')]
        print(json.dumps({'bindings': '\n'.join(lines)}))
    else:
        unittest.main()

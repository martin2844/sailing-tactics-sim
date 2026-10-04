"""Proof guards for private shoreline slots; all buffer aliases remain bytes."""
from pathlib import Path
import re
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import translate_drawing as drawing
import floating_drawing as floating
from optimize_shore_private_locals import promote_shore_private_locals, callee_contracts_match


class ShorePrivateProof(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        captured, original = [], floating.promote_static_locals

        def capture(source, name, address, frame_size, **kwargs):
            if address == 0x47ed40:
                captured.append(source)
            return source, {'eligible': False}

        try:
            floating.promote_static_locals = capture
            source = (ROOT / 'analysis/drawing-corrections/0047ed40.c').read_text()
            translator = drawing.Translator('originalDrawing0047ed40', 0x47ed40, source)
            translator.generate('originalDrawing0047ed40')
        finally:
            floating.promote_static_locals = original
        cls.raw = captured[0]

    def promote(self, source=None):
        return promote_shore_private_locals(source if source is not None else self.raw,
            'originalDrawing0047ed40Number', 0x47ed40, 920)

    def reject(self, source, reason):
        generated, record = self.promote(source)
        self.assertFalse(record['eligible'])
        self.assertEqual(generated, source)
        self.assertIn(reason, record['reason'])

    def byte_body(self):
        return self.raw.replace(
            'export function originalDrawing0047ed40Number(memory, dc, rng, options = {}, ...originalArgs)',
            'function originalDrawing0047ed40NumberByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)', 1).replace(
            'const localFrame=createLocalFrame(920,options.retainedDrawingStack?.[4713792]??[]);',
            'const localFrame=createLocalFrame(920,retainedLocalBytes);', 1)

    def test_actual_shore_emitter_promotes_nine_private_slots(self):
        generated, record = self.promote()
        self.assertTrue(record['eligible'], record)
        self.assertEqual([row['offset'] for row in record['slots']],
                         [0, 4, 8, 256, 260, 268, 272, 276, 280])
        self.assertEqual(record['scalarAccesses'], 326)
        self.assertEqual(record['retainedByteRanges'], [
            {'start': 264, 'end': 268}, {'start': 300, 'end': 920}])
        promoted = generated[:-len(self.byte_body()) - 2]
        for row in record['slots']:
            self.assertNotIn(f'framePointer(localFrame,{row["offset"]})', promoted)
        for offset in [264, 300, 304, 312, 320, 328, 332, 624, 916]:
            self.assertIn(f'framePointer(localFrame,{offset})', promoted)
        self.assertIn('scalarStack0=scalarStoreI32(dc);', promoted)
        self.assertIn('scalarStack280=scalarStoreI32(60), cCompare(', promoted)
        self.assertIn('scalarStack268=scalarStoreI32(cAdd(cDiv(r32(0x4fe2a8),160),r32(0x4da148))), cCompare(', promoted)
        self.assertEqual(record['induction'], {
            'writeIndices': [1, 72], 'readIndices': [1, 71], 'readSteps': [1, 2]})
        # Largest array write is624+72*4, width4; it ends at916, before
        # the named slot916. No escaped byte access can reach below300.
        self.assertEqual(624 + 72 * 4 + 4, 916)

    def test_complete_byte_fallback_and_all_control_edges_are_unchanged(self):
        generated, _record = self.promote()
        expected = self.byte_body()
        self.assertTrue(generated.endswith('\n\n' + expected))
        scalar = generated[:-len(expected) - 2]
        edges = lambda source: re.findall(r'\bpc = (?:(\d+)|[^\n]* \? (\d+) : (\d+)); continue;', source)
        self.assertEqual(edges(scalar), edges(self.raw))
        self.assertIn('if(retainedLocalBytes!=null)return originalDrawing0047ed40NumberByteFrame(', scalar)

    def test_runtime_pointer_contracts_are_pinned_and_reject_wider_or_escaping_writes(self):
        source = (ROOT / 'src/render/typed-c.js').read_text()
        self.assertTrue(callee_contracts_match(source))
        for changed in [source.replace('point.y,4);return point;', 'point.y,8);return point;'),
                        source.replace('export function writeLocalPoint(destination,point) {',
                            'export function writeLocalPoint(destination,point) { consume(destination);')]:
            self.assertNotEqual(changed, source)
            self.assertFalse(callee_contracts_match(changed))

    def test_counter_initialization_step_and_limit_changes_decline(self):
        for before, after in [('0x535a98,4,"int"', '0x535a94,4,"int"'),
                              ('false),5462965,"<"', 'false),5462970,"<"'),
                              ('false),71,"<"', 'false),72,"<"'),
                              ('framePointer(localFrame,276),2,4,"int"', 'framePointer(localFrame,276),0,4,"int"')]:
            changed = self.raw.replace(before, after)
            self.assertNotEqual(changed, self.raw)
            self.reject(changed, 'induction proof')

    def test_external_entry_cannot_bypass_either_array_loop_initialization(self):
        for target in [393, 258]:
            self.reject(self.raw.replace('case 0: { return; }',
                f'case 0: {{ pc = {target}; continue; }}'), 'loop')
        self.reject(self.raw.replace('case 373: { ',
            'case 373: { writeLocal(framePointer(localFrame,260),cNeg(1),4,"int"); '),
                    'unreviewed induction')
        self.reject(self.raw.replace('case 200: { ',
            'case 200: { writeLocal(framePointer(localFrame,264),cNeg(1),4,"int"); '),
                    'unreviewed induction')

    def test_preheader_cannot_invalidate_a_pinned_counter_initialization(self):
        for case, offset, value in [(261, 264, -16), (265, 276, -100),
                                   (428, 268, -200), (426, 260, -24)]:
            self.reject(self.raw.replace(f'case {case}: {{ ',
                f'case {case}: {{ writeLocal(framePointer(localFrame,{offset}),{value},4,"int"); '),
                        'unreviewed induction')

    def test_escaped_aliases_cannot_touch_any_private_slot(self):
        self.reject(self.raw.replace('writeLocalPoint(framePointer(localFrame,320)',
                                     'writeLocalPoint(framePointer(localFrame,280)', 1), 'unproved escape')
        self.reject(self.raw.replace('pointerAdd(framePointer(localFrame,332)',
                                     'pointerAdd(framePointer(localFrame,268)', 1), 'unproved escape')
        self.reject(self.raw.replace('case 3: { ', 'case 3: { consume(localFrame); '),
                    'escapes reviewed callees')

    def test_dynamic_access_requires_nonnegative_proved_loop_index(self):
        self.reject(self.raw.replace('cMul(cAdd(readLocal(framePointer(localFrame,260),4,"int"),1), 4)',
                                     'cMul(cSub(readLocal(framePointer(localFrame,260),4,"int"),1), 4)', 1),
                    'unproved escape')
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { readPointer(memory,pointerAdd(framePointer(localFrame,332),cMul(readLocal(framePointer(localFrame,264),4,"int"),4)),4); '),
                    'outside its proved array loop')

    def test_observed_store_results_and_overlapping_views_decline(self):
        self.reject(self.raw.replace('writeLocal(framePointer(localFrame,280),60,4,"int"), cCompare(',
                                     'consume(writeLocal(framePointer(localFrame,280),60,4,"int")), cCompare('),
                    'write return is observable')
        self.reject(self.raw.replace('readLocal(framePointer(localFrame,268),4,"int")',
                                     'readLocal(framePointer(localFrame,266),4,"int")', 1),
                    'overlapping byte view')
        self.reject(self.raw.replace('case 3: { ',
            'case 3: { readLocal(framePointer(localFrame,264),8,"float"); '),
                    'not a fixed I32 view')


if __name__ == '__main__':
    unittest.main()

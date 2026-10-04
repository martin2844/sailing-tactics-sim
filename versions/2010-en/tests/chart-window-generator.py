import json
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[3]
sys.path[:0] = [str(ROOT / 'versions/2010-en/tools'), str(ROOT / 'tools/python-libs')]
from translate_drawing import Translator
import floating_drawing
from fuse_chart_windows import fuse_chart_windows


def contract():
    path = ROOT / 'versions/2010-en/analysis/drawing-corrections/00468440.c'
    original_pass = floating_drawing.fuse_chart_windows
    floating_drawing.fuse_chart_windows = lambda source, *_: (source, {'eligible': False})
    try:
        producer = Translator('chart-window-test', 0x468440, path.read_text(), has_dc=True)
        generated = producer.generate('originalDrawing00468440')
    finally:
        floating_drawing.fuse_chart_windows = original_pass
    start = generated.index('function originalDrawing00468440Number(')
    end = generated.find('\n}\n', start)
    baseline = generated[start:] if end < 0 else generated[start:end + 3]
    candidate, proof = fuse_chart_windows(baseline, 'originalDrawing00468440Number', 0x468440)
    assert proof['eligible'], proof
    return {'baseline': baseline, 'candidate': candidate, 'proof': proof}


class ChartWindowGenerator(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.contract = contract()

    def test_two_closed_windows_and_conditional_high_word_elimination(self):
        candidate = self.contract['candidate']
        self.assertEqual(candidate.count('originalNumberDrawingIsCurrent(0x43ec20)'), 2)
        self.assertIn('chartColumnHighAbsent=true;', candidate)
        self.assertIn('chartColumnHighAbsent=false; (fVar8 = callNumberDrawingDependencyOwned', candidate)
        self.assertIn('case 68: { if(chartColumnHighAbsent)', candidate)
        self.assertIn('else{writeLocalFloatNumber(framePointer(localFrame,272),wordsAsF64Number', candidate)
        self.assertIn('TStack_38=BigInt(chartPoint.x);TStack_34=BigInt(chartPoint.y);pc=266;', candidate)

    def test_capture_preserves_the_existing_conversion_and_unknown_storage(self):
        candidate = self.contract['candidate']
        self.assertEqual(candidate.count('fpFormalF64(numberArg4,numberArgumentImages)'), 1)
        self.assertIn('const chartScaleImage=fpFormalF64(numberArg4,numberArgumentImages)', candidate)
        for entry in (263, 284):
            line = next(row for row in candidate.splitlines() if row.startswith(f'    case {entry}:'))
            self.assertNotIn('readLocalFloatNumber(framePointer(localFrame,20))', line)
            self.assertEqual(line.count('const chartArguments='), 1)
            self.assertIn('0x43ec20,chartArguments,3,rng,options)', line)

    def test_changed_edges_observers_and_formal_layout_decline_unchanged(self):
        baseline = self.contract['baseline']
        for old, new in [
            ('? 284 : 1;', '? 280 : 1;'),
            ('? 263 : 235;', '? 250 : 235;'),
            ('73,4,"int"', '74,4,"int"'),
            ('case 2: { dc.setBkMode(2);', 'case 2: { readLocalFloatNumber(framePointer(localFrame,272));dc.setBkMode(2);'),
            ('framePointer(localFrame,12),numberArg2', 'framePointer(localFrame,12),numberArg1'),
            ('createLocalFrame(320,', 'createLocalFrame(328,'),
        ]:
            self.assertIn(old, baseline)
            changed = baseline.replace(old, new, 1)
            result, proof = fuse_chart_windows(changed, 'originalDrawing00468440Number', 0x468440)
            self.assertFalse(proof['eligible'])
            self.assertEqual(result, changed)

    def test_other_routines_are_unchanged(self):
        baseline = self.contract['baseline']
        for name, address in [('other', 0x468440), ('originalDrawing00468440Number', 0x468450)]:
            result, proof = fuse_chart_windows(baseline, name, address)
            self.assertFalse(proof['eligible'])
            self.assertEqual(result, baseline)


if __name__ == '__main__':
    if '--emit-window-contract' in sys.argv:
        print(json.dumps(contract()))
    else:
        unittest.main()

#!/usr/bin/env python3
"""Check the compiler boundaries that cannot be exercised by current C calls."""
import sys
from pathlib import Path
import unittest

sys.path[:0] = [str(Path(__file__).resolve().parent),
                str(Path(__file__).resolve().parents[3] / 'tools/python-libs')]
from translate_drawing import Translator
from floating_drawing import floating_argument_flags


class FloatingDrawingBoundaries(unittest.TestCase):
    def test_argument_mask_keeps_position32_separate(self):
        self.assertEqual(floating_argument_flags([]), '0')
        self.assertEqual(floating_argument_flags([0, 31]), '2147483649')
        self.assertEqual(floating_argument_flags([32]), '[32]')
        self.assertEqual(floating_argument_flags([0, 32]), '[0, 32]')

    def test_concat_fusion_requires_byte_pointer_scale_and_pure_indices(self):
        def translate(pointer):
            source = f'''int FUN_0049b8d0() {{
              int local_40[4]; int local_44; int iVar1; double dVar1;
              iVar1=0;
              dVar1=(double)CONCAT44(*(undefined4 *)(({pointer})+4),
                                    *(undefined4 *)({pointer}));
              return (int)(longlong)dVar1;
            }}'''
            translator = Translator('synthetic', 0x49b8d0, source, has_dc=False)
            translator.generate('synthetic')
            return translator.number_optimization['localConcatLoadExpressions']

        self.assertEqual(translate('(int)&local_40 + iVar1'), 1)
        for pointer in ['local_40', '&local_40', '(int)&local_40 + iVar1++',
                        '(int)&local_40 + local_44', '(int)&local_40 + DAT_004da140']:
            with self.subTest(pointer=pointer):
                self.assertEqual(translate(pointer), 0)

    def test_private_fixed_formals_keep_public_rest_and_lazy_retained_contract(self):
        source = '''int FUN_0049b8d0(double param_1,int param_2) {
          double local_8;
          local_8=param_1+(double)param_2;
          return (int)(longlong)local_8;
        }'''
        translator = Translator('synthetic', 0x49b8d0, source, has_dc=False)
        generated = translator.generate('synthetic')
        self.assertIn('export function synthetic(memory, dc, rng, options = {}, ...originalArgs)', generated)
        self.assertIn('function syntheticNumber(memory, dc, rng, options, numberArgumentImages, numberArg0, numberArg1)', generated)
        self.assertIn('syntheticNumberByteFrame(memory,dc,rng,options,[numberArg0,numberArg1],retainedLocalBytes,numberArgumentImages)', generated)
        self.assertIn('function syntheticNumberByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes, numberArgumentImages)', generated)
        self.assertEqual(translator.number_optimization['fixedNumberArguments'], 2)


if __name__ == '__main__':
    unittest.main()

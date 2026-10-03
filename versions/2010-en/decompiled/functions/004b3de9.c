
undefined4 FUN_004b3de9(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = **(int **)(unaff_EBP + -0x1c);
  (**(code **)(iVar1 + 0x90))(*(undefined4 *)(unaff_EBP + -0x14),1);
  (**(code **)(iVar1 + 0x74))();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  (**(code **)(iVar1 + 0x88))
            (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x20),0,0xf101);
  *(undefined4 *)(unaff_EBP + -4) = 7;
  FUN_004b16cb();
  return 0x4b3e31;
}



void FUN_004b6e3d(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  if (*(int *)(extraout_ECX + 0x80) == 0) {
    iVar1 = FUN_004afbe5(0x20);
    *(int *)(unaff_EBP + -0x10) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_004c0b04();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x80) = uVar2;
  }
  (**(code **)(**(int **)(extraout_ECX + 0x80) + 0x14))(*(undefined4 *)(unaff_EBP + 8));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


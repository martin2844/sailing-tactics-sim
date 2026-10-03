
void FUN_0047275d(void)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  if (*(int *)(extraout_ECX + 0x80) == 0) {
    iVar1 = FUN_0046b505(0x20);
    *(int *)(unaff_EBP + -0x10) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_0047c424();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 **)(extraout_ECX + 0x80) = puVar2;
  }
  (**(code **)(**(int **)(extraout_ECX + 0x80) + 0x14))(*(undefined4 *)(unaff_EBP + 8));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


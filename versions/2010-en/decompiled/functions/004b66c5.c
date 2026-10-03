
void FUN_004b66c5(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int extraout_ECX;
  char *pcVar4;
  int unaff_EBP;
  
  FUN_0049bcd8();
  uVar2 = *(uint *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  iVar3 = *(int *)(extraout_ECX + 0x5c);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  iVar1 = iVar3 + uVar2 * 0x14;
  if ((*(byte *)(iVar3 + 0xc + uVar2 * 0x14) & 1) == 0) {
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      if (*(int *)(*(int *)(iVar1 + 0x10) + -8) == 0) goto LAB_004b676f;
      if (*(int *)(unaff_EBP + 0xc) == 0) goto LAB_004b6717;
    }
    iVar3 = FUN_0049bd00(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(unaff_EBP + 0xc));
    if (iVar3 == 0) goto LAB_004b676f;
  }
LAB_004b6717:
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    FUN_004b0530();
  }
  else {
    FUN_004b06ed((Tact2010CString *)(iVar1 + 0x10),*(char **)(unaff_EBP + 0xc));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
    func_0x004b677c();
    return;
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe;
  if ((*(byte *)(iVar1 + 0xb) & 4) == 0) {
    pcVar4 = ((Tact2010CString *)(iVar1 + 0x10))->data;
  }
  else {
    pcVar4 = (char *)0x0;
  }
  (**(code **)(**(int **)(unaff_EBP + -0x14) + 0xa8))(0x401,uVar2 | *(ushort *)(iVar1 + 8),pcVar4);
LAB_004b676f:
  func_0x004b677c();
  return;
}


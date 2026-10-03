
undefined4 FUN_00471fe5(void)

{
  int *this;
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00457418();
  uVar2 = *(uint *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  iVar3 = *(int *)(extraout_ECX + 0x5c);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  iVar1 = iVar3 + uVar2 * 0x14;
  if ((*(byte *)(iVar3 + 0xc + uVar2 * 0x14) & 1) == 0) {
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      if (*(int *)(*(int *)(iVar1 + 0x10) + -8) == 0) goto LAB_0047208f;
      if (*(int *)(unaff_EBP + 0xc) == 0) goto LAB_00472037;
    }
    iVar3 = FUN_00457440(*(byte **)(iVar1 + 0x10),*(byte **)(unaff_EBP + 0xc));
    if (iVar3 == 0) goto LAB_0047208f;
  }
LAB_00472037:
  *(undefined4 *)(unaff_EBP + -4) = 0;
  this = (int *)(iVar1 + 0x10);
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    FUN_0046be50(this);
  }
  else {
    FUN_0046c00d(this,*(LPCSTR *)(unaff_EBP + 0xc));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
    uVar4 = func_0x0047209c();
    return uVar4;
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe;
  if ((*(byte *)(iVar1 + 0xb) & 4) == 0) {
    iVar3 = *this;
  }
  else {
    iVar3 = 0;
  }
  (**(code **)(**(int **)(unaff_EBP + -0x14) + 0xa8))(0x401,uVar2 | *(ushort *)(iVar1 + 8),iVar3);
LAB_0047208f:
  uVar4 = func_0x0047209c();
  return uVar4;
}



undefined4 FUN_00476fb1(void)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  LPSTR pCVar4;
  undefined4 uVar5;
  HMENU pHVar6;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  uVar1 = *(uint *)(unaff_EBP + 8);
  *(uint *)((int)this + 0x8c) = uVar1;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar2 = FUN_0046d861(uVar1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    FUN_0046d90c((int *)((int)this + 0xac),*(byte **)(unaff_EBP + 8),0,'\n');
  }
  iVar3 = FUN_0047b918();
  if ((*(byte *)(iVar3 + 0x18) & 8) == 0) {
    iVar3 = FUN_0046aaa3(8);
  }
  else {
    iVar3 = 1;
  }
  if (iVar3 != 0) {
    pCVar4 = GetIconWndClass(this,*(undefined4 *)(unaff_EBP + 0xc),(ushort)uVar1);
    iVar3 = FUN_00476d9e(this,pCVar4,*(LPCSTR *)((int)this + 0xac),*(DWORD *)(unaff_EBP + 0xc),
                         (int *)&DAT_004ae360,*(int *)(unaff_EBP + 0x10),(LPCSTR)(uVar1 & 0xffff),0,
                         *(LPVOID *)(unaff_EBP + 0x14));
    if (iVar3 != 0) {
      pHVar6 = GetMenu(*(HWND *)((int)this + 0x1c));
      *(HMENU *)((int)this + 0x44) = pHVar6;
      FUN_00476700(this,(LPCSTR)(uVar1 & 0xffff));
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        FUN_0046996c(*(HWND *)((int)this + 0x1c),0x364,0,0,1,1);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + 8));
      uVar5 = 1;
      goto LAB_0047708b;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + 8));
  uVar5 = 0;
LAB_0047708b:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}


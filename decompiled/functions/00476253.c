
undefined4 FUN_00476253(void)

{
  uint uVar1;
  bool bVar2;
  DWORD DVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar5;
  HWND hWndNewParent;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  DVar3 = 0x80c83b00;
  *(undefined4 *)((int)this + 0xb0) = 1;
  if ((uVar1 & 4) != 0) {
    DVar3 = 0x80c83300;
  }
  iVar4 = FUN_00478d74(this,0,(LPCSTR)0x0,&DAT_004ae380,DVar3,(int *)&DAT_004ae360,
                       *(int *)(unaff_EBP + 8),(HMENU)0x0);
  if (iVar4 == 0) {
    *(undefined4 *)((int)this + 0xb0) = 0;
  }
  else {
    GetSystemMenu(*(HWND *)((int)this + 0x1c),0);
    iVar4 = FUN_0046d7e9();
    DeleteMenu(*(HMENU *)(iVar4 + 4),0xf000,0);
    FUN_0046bd7a((undefined4 *)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    bVar2 = FUN_0046d861(0xf011);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      DeleteMenu(*(HMENU *)(iVar4 + 4),0xf060,0);
      AppendMenuA(*(HMENU *)(iVar4 + 4),0,0xf060,*(LPCSTR *)(unaff_EBP + 0xc));
    }
    bVar2 = FUN_00475388((void *)((int)this + 0xcc),*(int *)(unaff_EBP + 8),
                         (-(uint)((uVar1 & 0x5000) != 0) & 0xfffff000) + 0x2000 | uVar1 & 0x40 |
                         0x50000000,(HMENU)0xe81f);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      if (this == (void *)0x0) {
        hWndNewParent = (HWND)0x0;
      }
      else {
        hWndNewParent = *(HWND *)((int)this + 0x1c);
      }
      SetParent(*(HWND *)((int)this + 0xe8),hWndNewParent);
      FUN_004680cc();
      *(undefined4 *)((int)this + 0xb0) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + 0xc));
      uVar5 = 1;
      goto LAB_0047638e;
    }
    *(undefined4 *)((int)this + 0xb0) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046bec5((int *)(unaff_EBP + 0xc));
  }
  uVar5 = 0;
LAB_0047638e:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}


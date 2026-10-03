
void __thiscall FUN_0047568b(void *this,void *param_1,RECT *param_2)

{
  undefined4 uVar1;
  BOOL BVar2;
  uint uVar3;
  CWnd *pCVar4;
  HWND hWndNewParent;
  int iVar5;
  UINT UVar6;
  CHAR local_128 [260];
  tagRECT local_24;
  undefined1 local_14 [12];
  int local_8;
  
  GetWindowRect(*(HWND *)((int)param_1 + 0x1c),&local_24);
  if (*(void **)((int)param_1 + 0x70) == this) {
    if (param_2 == (RECT *)0x0) {
      return;
    }
    BVar2 = EqualRect(&local_24,param_2);
    if (BVar2 != 0) {
      return;
    }
  }
  if ((*(int *)((int)this + 0x78) != 0) && ((*(byte *)((int)param_1 + 0x68) & 0x40) != 0)) {
    *(uint *)((int)this + 100) = *(uint *)((int)this + 100) | 0x40;
  }
  *(uint *)((int)this + 100) = *(uint *)((int)this + 100) & 0xfffffff9;
  uVar3 = *(uint *)((int)this + 100);
  *(uint *)((int)this + 100) = *(uint *)((int)param_1 + 100) & 6 | uVar3;
  if ((uVar3 & 0x40) == 0) {
    FUN_0046adce(param_1,local_128,0x104);
    FUN_00470ec5(*(HWND *)((int)this + 0x1c),local_128);
  }
  uVar1 = *(undefined4 *)((int)param_1 + 100);
  uVar3 = CONCAT22((short)((uint)uVar1 >> 0x10),
                   CONCAT11(((byte)((uint)*(undefined4 *)((int)param_1 + 100) >> 8) ^
                            (byte)((uint)*(undefined4 *)((int)this + 100) >> 8)) & 0xf0 ^
                            (byte)((uint)uVar1 >> 8),(char)uVar1));
  if (*(int *)((int)this + 0x78) == 0) {
    uVar3 = uVar3 & 0xfffffffe | 0xf00;
  }
  else {
    uVar3 = uVar3 | 0xf01;
  }
  FUN_0047c32d(param_1,uVar3);
  iVar5 = -1;
  uVar3 = GetDlgCtrlID(*(HWND *)((int)param_1 + 0x1c));
  iVar5 = FUN_00475fbe(this,uVar3 & 0xffff,iVar5);
  if (0 < iVar5) {
    *(void **)(*(int *)((int)this + 0x80) + iVar5 * 4) = param_1;
  }
  if (param_2 == (RECT *)0x0) {
    if (iVar5 < 1) {
      FUN_00466dbc((void *)((int)this + 0x7c),*(int *)((int)this + 0x84),param_1);
      FUN_00466dbc((void *)((int)this + 0x7c),*(int *)((int)this + 0x84),0);
    }
    UVar6 = 0x115;
    local_8 = 0;
    local_14._4_4_ = -DAT_004ae64c;
    iVar5 = 0;
    local_14._0_4_ = -DAT_004ae648;
  }
  else {
    CopyRect((LPRECT)local_14,param_2);
    ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_14);
    ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_14 + 8));
    if (iVar5 < 1) {
      FUN_00476049(this,param_1,local_14._0_4_,local_14._4_4_,local_14._8_4_,local_8,
                   (int)(local_14._8_4_ - local_14._0_4_) / 2 + local_14._0_4_,
                   (local_8 - local_14._4_4_) / 2 + local_14._4_4_);
    }
    UVar6 = 0x114;
    local_8 = local_8 - local_14._4_4_;
    iVar5 = local_14._8_4_ - local_14._0_4_;
  }
  FUN_0046adfd(param_1,0,local_14._0_4_,local_14._4_4_,iVar5,local_8,UVar6);
  GetParent(*(HWND *)((int)param_1 + 0x1c));
  pCVar4 = FUN_004680cc();
  if (pCVar4 != this) {
    if (this == (void *)0x0) {
      hWndNewParent = (HWND)0x0;
    }
    else {
      hWndNewParent = *(HWND *)((int)this + 0x1c);
    }
    SetParent(*(HWND *)((int)param_1 + 0x1c),hWndNewParent);
    FUN_004680cc();
  }
  if (*(void **)((int)param_1 + 0x70) != (void *)0x0) {
    FUN_004758d2(*(void **)((int)param_1 + 0x70),(int)param_1,-1,0);
  }
  *(void **)((int)param_1 + 0x70) = this;
  pCVar4 = FUN_004786de((int)this);
  *(uint *)(pCVar4 + 0xb8) = *(uint *)(pCVar4 + 0xb8) | 0xc;
  return;
}


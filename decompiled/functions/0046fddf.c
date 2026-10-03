
undefined4 __thiscall FUN_0046fddf(void *this,int param_1)

{
  uint uVar1;
  CWnd *this_00;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = FUN_0046ad0b((int)this);
  if ((((-(uint)(param_1 != 0) & 0x100000) + 0x100000 & uVar1) == 0) &&
     (this_00 = FUN_0046fd81(this,1), this_00 != (CWnd *)0x0)) {
    uVar1 = GetDlgCtrlID(*(HWND *)((int)this + 0x1c));
    uVar2 = uVar1 & 0xffff;
    if ((0xe8ff < uVar2) && (uVar2 < 0xea00)) {
      if (param_1 == 0) {
        iVar3 = (uVar1 & 0xf) + 0xea00;
      }
      else {
        iVar3 = (uVar2 - 0xe900 >> 4) + 0xea10;
      }
      uVar4 = FUN_0046acae(this_00,iVar3);
      return uVar4;
    }
  }
  return 0;
}


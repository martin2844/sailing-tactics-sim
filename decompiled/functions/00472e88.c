
uint __thiscall FUN_00472e88(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  void *pvStack_14;
  void *pvStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  iVar1 = *(int *)this;
  pvStack_14 = this;
  pvStack_10 = this;
  FUN_00456010(&pvStack_14,param_2);
  iVar1 = (**(code **)(iVar1 + 0x6c))();
  if (iVar1 == -1) {
    uVar2 = GetDlgCtrlID(*(HWND *)((int)this + 0x1c));
    uVar2 = -(uint)((uVar2 & 0xffff) != 0) & (uVar2 & 0xffff) + 0x50000;
  }
  else {
    uVar2 = iVar1 + 0x10000;
  }
  return uVar2;
}


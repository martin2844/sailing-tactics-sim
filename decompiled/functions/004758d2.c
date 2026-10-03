
undefined4 __thiscall FUN_004758d2(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  CWnd *this_00;
  int iVar4;
  int *piVar5;
  
  iVar1 = FUN_00475fbe(this,param_1,param_2);
  if (param_3 == 0) {
    FUN_00466e78((void *)((int)this + 0x7c),iVar1,1);
    if ((*(int *)(*(int *)((int)this + 0x80) + -4 + iVar1 * 4) == 0) &&
       (*(int *)(*(int *)((int)this + 0x80) + iVar1 * 4) == 0)) {
      FUN_00466e78((void *)((int)this + 0x7c),iVar1,1);
    }
    FUN_0047587b(this,param_1);
  }
  else {
    iVar3 = *(int *)((int)this + 0x80);
    iVar4 = iVar1 * 4;
    uVar2 = GetDlgCtrlID(*(HWND *)(param_1 + 0x1c));
    *(uint *)(iVar3 + iVar4) = uVar2 & 0xffff;
    iVar3 = FUN_00475fbe(this,*(int *)(*(int *)((int)this + 0x80) + iVar4),iVar1);
    if (0 < iVar3) {
      FUN_00466e78((void *)((int)this + 0x7c),iVar1,1);
      piVar5 = (int *)(iVar4 + *(int *)((int)this + 0x80));
      if ((piVar5[-1] == 0) && (*piVar5 == 0)) {
        FUN_00466e78((void *)((int)this + 0x7c),iVar1,1);
      }
    }
  }
  if (*(int *)(param_1 + 0x74) != 0) {
    this_00 = FUN_004786de((int)this);
    if ((*(int *)((int)this + 0x78) == 0) ||
       (iVar1 = (**(code **)(*(int *)this + 0xe8))(), iVar1 != 0)) {
      *(uint *)(this_00 + 0xb8) = *(uint *)(this_00 + 0xb8) | 0xc;
    }
    else {
      iVar1 = FUN_004753e8(this);
      if (iVar1 == 0) {
        (**(code **)(*(int *)this_00 + 0x60))();
        return 1;
      }
      FUN_0046ae4c(this_00,0);
    }
  }
  return 0;
}


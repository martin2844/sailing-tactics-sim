
undefined4 __thiscall FUN_00473285(void *this,undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  CWnd *pCVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = FUN_0046ad0b((int)this);
  uVar2 = *(uint *)((int)this + 0x60);
  uVar5 = 0;
  if (((uVar2 & 1) == 0) || ((uVar1 & 0x10000000) == 0)) {
    if (((uVar2 & 2) != 0) && ((uVar1 & 0x10000000) == 0)) {
      uVar5 = 0x40;
    }
  }
  else {
    uVar5 = 0x80;
  }
  *(uint *)((int)this + 0x60) = uVar2 & 0xfffffffc;
  if (uVar5 != 0) {
    FUN_0046adfd(this,0,0,0,0,0,uVar5 | 0x17);
  }
  uVar2 = FUN_0046ad0b((int)this);
  if ((uVar2 & 0x10000000) != 0) {
    if ((*(int *)((int)this + 0x70) != 0) &&
       (uVar2 = FUN_0046ad0b(*(int *)((int)this + 0x70)), (uVar2 & 0x10000000) == 0)) {
      return 0;
    }
    pCVar3 = CWnd::GetOwner(this);
    if ((pCVar3 == (CWnd *)0x0) || (iVar4 = (**(code **)(*(int *)pCVar3 + 0xb8))(), iVar4 == 0)) {
      pCVar3 = FUN_004696a2((int)this);
    }
    if (pCVar3 != (CWnd *)0x0) {
      (**(code **)(*(int *)this + 200))(pCVar3,param_1);
    }
    return 0;
  }
  return 0;
}


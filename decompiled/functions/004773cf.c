
undefined4 __thiscall FUN_004773cf(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  CWinThread *pCVar2;
  int *piVar3;
  int iVar4;
  
  FUN_0046a110(this,(short)param_1);
  iVar4 = *(int *)this;
  (**(code **)(iVar4 + 0xf8))();
  if (*(int **)((int)this + 0x68) != (int *)0x0) {
    if (((short)param_1 == 0) || ((short)((uint)param_1 >> 0x10) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    (**(code **)(**(int **)((int)this + 0x68) + 0x60))(uVar1);
  }
  pCVar2 = AfxGetThread();
  if (*(void **)(pCVar2 + 0x1c) == this) {
    piVar3 = (int *)FUN_0047782e((int)this);
    if (piVar3 == (int *)0x0) {
      iVar4 = (**(code **)(iVar4 + 200))();
      piVar3 = (int *)FUN_0047782e(iVar4);
      if (piVar3 == (int *)0x0) {
        return 0;
      }
    }
    (**(code **)(*piVar3 + 0xec))(0,piVar3,piVar3);
  }
  return 0;
}


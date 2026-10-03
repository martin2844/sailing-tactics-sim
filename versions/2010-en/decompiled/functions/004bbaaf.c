
undefined4 __thiscall FUN_004bbaaf(void *this,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  CWinThread *pCVar3;
  int *piVar4;
  
  FUN_004ae7f0(this,param_2,param_3);
  iVar1 = *(int *)this;
  (**(code **)(iVar1 + 0xf8))();
  if (*(int **)((int)this + 0x68) != (int *)0x0) {
    if (((short)param_2 == 0) || ((short)((uint)param_2 >> 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    (**(code **)(**(int **)((int)this + 0x68) + 0x60))(uVar2);
  }
  pCVar3 = AfxGetThread();
  if (*(void **)(pCVar3 + 0x1c) == this) {
    piVar4 = (int *)FUN_004bbf0e();
    if (piVar4 == (int *)0x0) {
      (**(code **)(iVar1 + 200))();
      piVar4 = (int *)FUN_004bbf0e();
      if (piVar4 == (int *)0x0) {
        return 0;
      }
    }
    (**(code **)(*piVar4 + 0xec))(0,piVar4,piVar4);
  }
  return 0;
}


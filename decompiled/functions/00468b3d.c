
void __thiscall FUN_00468b3d(void *this,undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*param_2 == 1) {
    piVar1 = (int *)FUN_0046d7ff(param_2[5]);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))(param_2);
      return;
    }
  }
  else {
    iVar2 = FUN_00469eee();
    if (iVar2 != 0) {
      return;
    }
  }
  FUN_00468021(this);
  return;
}


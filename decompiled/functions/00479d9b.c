
int * __thiscall FUN_00479d9b(void *this,undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_0046cf6a();
  if (piVar1 == (int *)0x0) {
    FUN_00466060();
  }
  iVar2 = (**(code **)(*piVar1 + 0xfc))(this,param_1);
  if (iVar2 == 0) {
    FUN_00470a9a();
  }
  return piVar1;
}


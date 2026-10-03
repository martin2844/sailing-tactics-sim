
int * __thiscall FUN_0046bfbe(void *this,int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(undefined4 **)this != puVar1) {
    piVar3 = *(undefined4 **)this + -3;
    if (((*piVar3 < 0) && (piVar3 != (int *)PTR_DAT_0049f5c0)) || ((int)puVar1[-3] < 0)) {
      FUN_0046bf91(this,puVar1[-2],puVar1);
    }
    else {
      FUN_0046bdfb(this);
      iVar2 = *param_1;
      *(int *)this = iVar2;
      InterlockedIncrement((LONG *)(iVar2 + -0xc));
    }
  }
  return this;
}


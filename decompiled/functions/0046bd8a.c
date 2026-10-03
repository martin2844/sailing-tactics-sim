
int * __thiscall FUN_0046bd8a(void *this,int *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    ppuVar2 = FUN_0046bd74();
    *(undefined **)this = *ppuVar2;
    FUN_0046c00d(this,(LPCSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    InterlockedIncrement((LONG *)(iVar1 + -0xc));
  }
  return this;
}



int __thiscall FUN_004be2cd(void *this,int param_2,LPSTR param_3)

{
  int iVar1;
  
  if (DAT_005381f4 == 0) {
    lstrcpynA(param_3,*(LPCSTR *)((int)this + 200),param_2);
    iVar1 = *(int *)(*(int *)((int)this + 200) + -8);
    if (iVar1 < param_2) {
      param_2 = iVar1;
    }
  }
  else {
    param_2 = FUN_004ac701();
  }
  return param_2;
}



int __thiscall FUN_004b0956(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if ((1 < *(int *)(iVar1 + -0xc)) || (*(int *)(iVar1 + -4) < param_2)) {
    iVar2 = *(int *)(iVar1 + -8);
    if (param_2 < iVar2) {
      param_2 = iVar2;
    }
    FUN_004b04a1(param_2);
    FUN_0049c110(*param_1,iVar1,iVar2 + 1);
    *(int *)(*param_1 + -8) = iVar2;
    FUN_004b050d(iVar1 + -0xc);
  }
  return *param_1;
}


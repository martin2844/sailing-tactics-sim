
int __cdecl FUN_00459dd0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + *param_2;
  iVar1 = param_2[1];
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(param_1 + iVar1) + param_2[2]) + iVar1;
  }
  return iVar2;
}


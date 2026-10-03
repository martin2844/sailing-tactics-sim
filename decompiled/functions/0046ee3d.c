
undefined4 __fastcall FUN_0046ee3d(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  
  DVar1 = GetFileAttributesA((LPCSTR)param_1[8]);
  if ((DVar1 & 1) == 0) {
    iVar2 = param_1[8];
  }
  else {
    iVar2 = 0;
  }
  iVar2 = (**(code **)(*param_1 + 0xa0))(iVar2,1);
  if (iVar2 == 0) {
    return 0;
  }
  return 1;
}


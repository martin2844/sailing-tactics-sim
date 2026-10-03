
int __cdecl FUN_00461740(byte *param_1,byte *param_2,LPWSTR param_3)

{
  int iVar1;
  
  if (param_3 == (LPWSTR)0x0) {
    return 0;
  }
  iVar1 = FUN_004620c0(DAT_004aea70,1,param_1,param_3,param_2,(int)param_3,DAT_004aea6c);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}


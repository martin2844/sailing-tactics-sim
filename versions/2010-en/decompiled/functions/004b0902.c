
undefined4 __thiscall FUN_004b0902(undefined4 param_1,LPCSTR param_2)

{
  int iVar1;
  
  if (param_2 == (LPCSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenA(param_2);
  }
  FUN_004b08a3(iVar1,param_2);
  return param_1;
}


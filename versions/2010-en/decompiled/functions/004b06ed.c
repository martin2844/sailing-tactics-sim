
Tact2010CString * __thiscall FUN_004b06ed(Tact2010CString *original_this,char *param_2)

{
  int iVar1;
  
  if (param_2 == (char *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenA(param_2);
  }
  FUN_004b0671(iVar1,param_2);
  return original_this;
}



Tact2010CString * __thiscall FUN_004b213c(Tact2010CString *param_1,byte param_2)

{
  Tact2010CString *pTVar1;
  
  if ((param_2 & 2) == 0) {
    FUN_004b05a5(param_1);
    pTVar1 = param_1;
    if ((param_2 & 1) == 0) {
      return param_1;
    }
  }
  else {
    FUN_0049b660(param_1,4,param_1[-1].data,FUN_004b05a5);
    pTVar1 = param_1 + -1;
  }
  FUN_004afc21(pTVar1);
  return param_1;
}


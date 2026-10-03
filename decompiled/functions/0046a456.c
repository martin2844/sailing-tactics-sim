
undefined4 FUN_0046a456(HDC param_1,HWND param_2,int param_3,HANDLE param_4,COLORREF param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined1 local_10 [4];
  COLORREF local_c;
  
  if ((((param_1 == (HDC)0x0) || (param_4 == (HANDLE)0x0)) || (param_3 == 1)) ||
     ((param_3 == 0 || (param_3 == 5)))) {
LAB_0046a4c5:
    uVar2 = 0;
  }
  else {
    if (param_3 == 2) {
      bVar1 = FUN_00470ddb(param_2,2);
      if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_0046a4c5;
    }
    GetObjectA(param_4,0xc,local_10);
    SetBkColor(param_1,local_c);
    if (param_5 == 0xffffffff) {
      param_5 = GetSysColor(8);
    }
    SetTextColor(param_1,param_5);
    uVar2 = 1;
  }
  return uVar2;
}



int FUN_004b1562(LPCSTR param_1,LPCSTR param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  CHAR *Buf;
  CHAR local_108 [260];
  
  Buf = param_2;
  if (param_2 == (LPCSTR)0x0) {
    Buf = local_108;
    param_3 = 0x104;
  }
  sVar1 = GetFileTitleA(param_1,Buf,(WORD)param_3);
  if (sVar1 == 0) {
    if (param_2 == (LPCSTR)0x0) {
      iVar2 = lstrlenA(Buf);
      iVar2 = iVar2 + 1;
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = FUN_004c1464(param_1,param_2,param_3);
  }
  return iVar2;
}


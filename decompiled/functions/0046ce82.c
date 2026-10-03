
int FUN_0046ce82(byte *param_1,LPSTR param_2,int param_3)

{
  short sVar1;
  int iVar2;
  CHAR *Buf;
  CHAR local_108 [260];
  
  Buf = param_2;
  if (param_2 == (LPSTR)0x0) {
    Buf = local_108;
    param_3 = 0x104;
  }
  sVar1 = GetFileTitleA((LPCSTR)param_1,Buf,(WORD)param_3);
  if (sVar1 == 0) {
    if (param_2 == (LPSTR)0x0) {
      iVar2 = lstrlenA(Buf);
      iVar2 = iVar2 + 1;
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = FUN_0047cd84(param_1,param_2,param_3);
  }
  return iVar2;
}


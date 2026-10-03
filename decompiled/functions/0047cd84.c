
int FUN_0047cd84(byte *param_1,LPSTR param_2,int param_3)

{
  byte bVar1;
  byte *lpString2;
  int iVar2;
  
  lpString2 = param_1;
  for (; *param_1 != 0; param_1 = FUN_00457e60(param_1)) {
    bVar1 = *param_1;
    if (((bVar1 == 0x5c) || (bVar1 == 0x2f)) || (bVar1 == 0x3a)) {
      lpString2 = FUN_00457e60(param_1);
    }
  }
  if (param_2 == (LPSTR)0x0) {
    iVar2 = lstrlenA((LPCSTR)lpString2);
    iVar2 = iVar2 + 1;
  }
  else {
    lstrcpynA(param_2,(LPCSTR)lpString2,param_3);
    iVar2 = 0;
  }
  return iVar2;
}


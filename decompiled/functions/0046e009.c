
void __cdecl FUN_0046e009(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  byte *lpString2;
  byte *lpString;
  
  iVar1 = lstrlenA((LPCSTR)param_1);
  iVar2 = FUN_0047cd84(param_1,(LPSTR)0x0,0);
  iVar2 = iVar2 + -1;
  lpString2 = param_1 + (iVar1 - iVar2);
  if (param_2 < iVar1) {
    if (param_2 < iVar2) {
      if (param_3 == 0) {
        lpString2 = &DAT_004ae380;
      }
    }
    else {
      lpString = param_1 + 2;
      if ((*param_1 == 0x5c) && (param_1[1] == 0x5c)) {
        for (; *lpString != 0x5c; lpString = FUN_00457e60(lpString)) {
        }
      }
      if (3 < iVar1 - iVar2) {
        do {
          lpString = FUN_00457e60(lpString);
        } while (*lpString != 0x5c);
      }
      iVar1 = (int)lpString - (int)param_1;
      if (iVar1 + 5 + iVar2 <= param_2) {
        while (iVar2 = lstrlenA((LPCSTR)lpString), param_2 < iVar2 + 4 + iVar1) {
          do {
            lpString = FUN_00457e60(lpString);
          } while (*lpString != 0x5c);
        }
        param_1[iVar1] = 0;
        lstrcatA((LPSTR)param_1,"\\...");
        lstrcatA((LPSTR)param_1,(LPCSTR)lpString);
        return;
      }
    }
    lstrcpyA((LPSTR)param_1,(LPCSTR)lpString2);
  }
  return;
}


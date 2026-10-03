
undefined4 __thiscall
FUN_004b227c(int param_1,undefined4 param_2,int param_3,LPCSTR param_4,int param_5,
            undefined4 param_6)

{
  CHAR CVar1;
  undefined4 uVar2;
  LPSTR lpString1;
  int iVar3;
  int iVar4;
  bool bVar5;
  CHAR local_10c [260];
  int local_8;
  
  if (*(int *)(*(int *)(*(int *)(param_1 + 8) + param_3 * 4) + -8) == 0) {
    uVar2 = 0;
  }
  else {
    local_8 = param_1;
    lpString1 = (LPSTR)FUN_004b0956(0x104);
    lstrcpyA(lpString1,*(LPCSTR *)(*(int *)(local_8 + 8) + param_3 * 4));
    iVar3 = FUN_004c1464(lpString1,0,0);
    iVar4 = lstrlenA(lpString1);
    iVar4 = (1 - iVar3) + iVar4;
    bVar5 = false;
    if (iVar4 == param_5) {
      CVar1 = lpString1[iVar4];
      lpString1[param_5] = '\0';
      iVar3 = lstrcmpiA(param_4,lpString1);
      bVar5 = iVar3 == 0;
      lpString1[iVar4] = CVar1;
    }
    if (bVar5) {
      FUN_004b1562(lpString1 + param_5,local_10c,0x104);
      lstrcpynA(lpString1,local_10c,0x104);
    }
    else if (*(int *)(local_8 + 0x18) != -1) {
      FUN_004b1562(lpString1 + iVar4,local_10c,0x104);
      lstrcpynA(lpString1 + iVar4,local_10c,0x104 - iVar4);
      FUN_004b26e9(lpString1,*(undefined4 *)(local_8 + 0x18),param_6);
    }
    FUN_004b09a5(0xffffffff);
    uVar2 = 1;
  }
  return uVar2;
}



undefined4 __thiscall
FUN_0046db9c(void *this,void *param_1,int param_2,LPCSTR param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined4 uVar2;
  byte *lpString1;
  int iVar3;
  int iVar4;
  bool bVar5;
  CHAR local_10c [260];
  void *local_8;
  
  if (*(int *)(*(int *)(*(int *)((int)this + 8) + param_2 * 4) + -8) == 0) {
    uVar2 = 0;
  }
  else {
    local_8 = this;
    lpString1 = (byte *)FUN_0046c276(param_1,0x104);
    lstrcpyA((LPSTR)lpString1,*(LPCSTR *)(*(int *)((int)local_8 + 8) + param_2 * 4));
    iVar3 = FUN_0047cd84(lpString1,(LPSTR)0x0,0);
    iVar4 = lstrlenA((LPCSTR)lpString1);
    iVar4 = (1 - iVar3) + iVar4;
    bVar5 = false;
    if (iVar4 == param_4) {
      bVar1 = lpString1[iVar4];
      lpString1[param_4] = 0;
      iVar3 = lstrcmpiA(param_3,(LPCSTR)lpString1);
      bVar5 = iVar3 == 0;
      lpString1[iVar4] = bVar1;
    }
    if (bVar5) {
      FUN_0046ce82(lpString1 + param_4,local_10c,0x104);
      lstrcpynA((LPSTR)lpString1,local_10c,0x104);
    }
    else if (*(int *)((int)local_8 + 0x18) != -1) {
      FUN_0046ce82(lpString1 + iVar4,local_10c,0x104);
      lstrcpynA((LPSTR)(lpString1 + iVar4),local_10c,0x104 - iVar4);
      FUN_0046e009(lpString1,*(int *)((int)local_8 + 0x18),param_5);
    }
    FUN_0046c2c5(param_1,-1);
    uVar2 = 1;
  }
  return uVar2;
}


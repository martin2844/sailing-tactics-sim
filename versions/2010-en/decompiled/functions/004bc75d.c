
void __thiscall FUN_004bc75d(int param_1,LPCSTR param_2)

{
  uint uVar1;
  int iVar2;
  LPCSTR pCVar3;
  int iVar4;
  CHAR local_208 [516];
  
  uVar1 = FUN_004af3eb();
  if ((uVar1 & 0x4000) == 0) {
    lstrcpyA(local_208,*(LPCSTR *)(param_1 + 0xac));
    if (param_2 != (LPCSTR)0x0) {
      lstrcatA(local_208," - ");
      lstrcatA(local_208,param_2);
      iVar4 = *(int *)(param_1 + 0x40);
      if (0 < iVar4) {
        pCVar3 = ":%d";
        iVar2 = lstrlenA(local_208);
        wsprintfA(local_208 + iVar2,pCVar3,iVar4);
      }
    }
  }
  else {
    local_208[0] = '\0';
    if (param_2 != (LPCSTR)0x0) {
      lstrcpyA(local_208,param_2);
      iVar4 = *(int *)(param_1 + 0x40);
      if (0 < iVar4) {
        pCVar3 = ":%d";
        iVar2 = lstrlenA(local_208);
        wsprintfA(local_208 + iVar2,pCVar3,iVar4);
      }
      lstrcatA(local_208," - ");
    }
    lstrcatA(local_208,*(LPCSTR *)(param_1 + 0xac));
  }
  FUN_004b55a5(*(undefined4 *)(param_1 + 0x1c),local_208);
  return;
}



void __fastcall FUN_0046deef(int param_1)

{
  int iVar1;
  void *this;
  BYTE *pBVar2;
  LPSTR pCVar3;
  int iVar4;
  
  pCVar3 = (LPSTR)FUN_0046b505(*(int *)(*(int *)(param_1 + 0x10) + -8) + 5);
  iVar4 = FUN_0047b918();
  this = *(void **)(iVar4 + 4);
  iVar4 = 0;
  FUN_00472852(this,*(LPCSTR *)(param_1 + 0xc),(LPCSTR)0x0,(BYTE *)0x0);
  if (0 < *(int *)(param_1 + 4)) {
    do {
      iVar1 = iVar4 + 1;
      wsprintfA(pCVar3,*(LPCSTR *)(param_1 + 0x10),iVar1);
      pBVar2 = *(BYTE **)(*(int *)(param_1 + 8) + iVar4 * 4);
      if (*(int *)(pBVar2 + -8) != 0) {
        FUN_00472852(this,*(LPCSTR *)(param_1 + 0xc),pCVar3,pBVar2);
      }
      iVar4 = iVar1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  FUN_0046b541(pCVar3);
  return;
}


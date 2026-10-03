
int FUN_004ad373(int param_1,UINT param_2)

{
  int iVar1;
  HMENU pHVar2;
  int iVar3;
  UINT UVar4;
  int nPos;
  
  iVar1 = GetMenuItemCount(*(HMENU *)(param_1 + 4));
  nPos = 0;
  if (0 < iVar1) {
    do {
      pHVar2 = GetSubMenu(*(HMENU *)(param_1 + 4),nPos);
      iVar3 = FUN_004b1ec9(pHVar2);
      if (iVar3 == 0) {
        UVar4 = GetMenuItemID(*(HMENU *)(param_1 + 4),nPos);
        if (UVar4 == param_2) {
          iVar1 = FUN_004b1edf(*(undefined4 *)(param_1 + 4));
          return iVar1;
        }
      }
      else {
        iVar3 = FUN_004ad373(iVar3,param_2);
        if (iVar3 != 0) {
          return iVar3;
        }
      }
      nPos = nPos + 1;
    } while (nPos < iVar1);
  }
  return 0;
}


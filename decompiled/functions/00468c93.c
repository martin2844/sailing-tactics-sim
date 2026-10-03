
int __cdecl FUN_00468c93(int param_1,UINT param_2)

{
  int iVar1;
  int iVar2;
  UINT UVar3;
  int nPos;
  
  iVar1 = GetMenuItemCount(*(HMENU *)(param_1 + 4));
  nPos = 0;
  if (0 < iVar1) {
    do {
      GetSubMenu(*(HMENU *)(param_1 + 4),nPos);
      iVar2 = FUN_0046d7e9();
      if (iVar2 == 0) {
        UVar3 = GetMenuItemID(*(HMENU *)(param_1 + 4),nPos);
        if (UVar3 == param_2) {
          iVar1 = FUN_0046d7ff(*(uint *)(param_1 + 4));
          return iVar1;
        }
      }
      else {
        iVar2 = FUN_00468c93(iVar2,param_2);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      nPos = nPos + 1;
    } while (nPos < iVar1);
  }
  return 0;
}



void FUN_004b4256(LPRECT param_1,int param_2)

{
  DWORD dwExStyle;
  uint uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    FUN_004ae47a(param_1,0);
  }
  else {
    dwExStyle = FUN_004af405();
    AdjustWindowRectEx(param_1,0,0,dwExStyle);
    uVar1 = FUN_004af3eb();
    if ((uVar1 & 0x200000) != 0) {
      iVar2 = DAT_00538190;
      if ((uVar1 & 0x800000) != 0) {
        iVar2 = DAT_00538190 + -1;
      }
      param_1->right = param_1->right + iVar2;
    }
    if ((uVar1 & 0x100000) != 0) {
      iVar2 = DAT_00538194;
      if ((uVar1 & 0x800000) != 0) {
        iVar2 = DAT_00538194 + -1;
      }
      param_1->bottom = param_1->bottom + iVar2;
    }
  }
  return;
}


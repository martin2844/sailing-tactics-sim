
void __thiscall FUN_0046fb76(void *this,LPRECT param_1,int param_2)

{
  DWORD dwExStyle;
  uint uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    FUN_00469d9a(this,param_1,0);
  }
  else {
    dwExStyle = FUN_0046ad25((int)this);
    AdjustWindowRectEx(param_1,0,0,dwExStyle);
    uVar1 = FUN_0046ad0b((int)this);
    if ((uVar1 & 0x200000) != 0) {
      iVar2 = DAT_004ae638;
      if ((uVar1 & 0x800000) != 0) {
        iVar2 = DAT_004ae638 + -1;
      }
      param_1->right = param_1->right + iVar2;
    }
    if ((uVar1 & 0x100000) != 0) {
      iVar2 = DAT_004ae63c;
      if ((uVar1 & 0x800000) != 0) {
        iVar2 = DAT_004ae63c + -1;
      }
      param_1->bottom = param_1->bottom + iVar2;
    }
  }
  return;
}


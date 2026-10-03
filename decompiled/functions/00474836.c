
void __cdecl FUN_00474836(LPRECT param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1->left;
  if ((param_2 < iVar1) || (iVar1 = param_1->right, iVar1 < param_2)) {
    iVar1 = param_2 - iVar1;
  }
  else {
    iVar1 = 0;
  }
  iVar2 = param_1->top;
  if ((param_3 < iVar2) || (iVar2 = param_1->bottom, iVar2 < param_3)) {
    iVar2 = param_3 - iVar2;
  }
  else {
    iVar2 = 0;
  }
  OffsetRect(param_1,iVar1,iVar2);
  return;
}


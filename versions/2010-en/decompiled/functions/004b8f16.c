
void FUN_004b8f16(LPRECT param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1->left;
  if ((param_2 < iVar1) || (iVar1 = param_1->right, iVar1 < param_2)) {
    param_2 = param_2 - iVar1;
  }
  else {
    param_2 = 0;
  }
  iVar1 = param_1->top;
  if ((param_3 < iVar1) || (iVar1 = param_1->bottom, iVar1 < param_3)) {
    param_3 = param_3 - iVar1;
  }
  else {
    param_3 = 0;
  }
  OffsetRect(param_1,param_2,param_3);
  return;
}


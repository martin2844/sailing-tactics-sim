
int __thiscall FUN_004b48a7(int param_1,int param_2)

{
  int iVar1;
  BOOL BVar2;
  
  iVar1 = 1;
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    iVar1 = RestoreDC(*(HDC *)(param_1 + 4),param_2);
  }
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    if ((iVar1 != 0) && (BVar2 = RestoreDC(*(HDC *)(param_1 + 8),param_2), BVar2 != 0)) {
      return 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


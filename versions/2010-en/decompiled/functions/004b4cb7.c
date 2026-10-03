
int __thiscall FUN_004b4cb7(int param_1,int param_2)

{
  int iVar1;
  HRGN pHVar2;
  
  iVar1 = param_2;
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    if (param_2 == 0) {
      pHVar2 = (HRGN)0x0;
    }
    else {
      pHVar2 = *(HRGN *)(param_2 + 4);
    }
    param_2 = SelectClipRgn(*(HDC *)(param_1 + 4),pHVar2);
  }
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    if (iVar1 == 0) {
      pHVar2 = (HRGN)0x0;
    }
    else {
      pHVar2 = *(HRGN *)(iVar1 + 4);
    }
    param_2 = SelectClipRgn(*(HDC *)(param_1 + 8),pHVar2);
  }
  return param_2;
}


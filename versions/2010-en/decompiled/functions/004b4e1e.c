
UINT __thiscall FUN_004b4e1e(int param_1,UINT param_2)

{
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    SetTextAlign(*(HDC *)(param_1 + 4),param_2);
  }
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    param_2 = SetTextAlign(*(HDC *)(param_1 + 8),param_2);
  }
  return param_2;
}


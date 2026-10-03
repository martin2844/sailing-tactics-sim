
int __thiscall FUN_004b48fc(int *original_dc,int param_2)

{
  HGDIOBJ h;
  int iVar1;
  
  h = GetStockObject(param_2);
  if ((HDC)original_dc[1] != (HDC)original_dc[2]) {
    param_2 = (int)SelectObject((HDC)original_dc[1],h);
  }
  if ((HDC)original_dc[2] != (HDC)0x0) {
    param_2 = (int)SelectObject((HDC)original_dc[2],h);
  }
  iVar1 = FUN_004b50f7(param_2);
  return iVar1;
}


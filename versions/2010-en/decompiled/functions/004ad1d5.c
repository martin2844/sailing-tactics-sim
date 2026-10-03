
void __thiscall FUN_004ad1d5(int param_1,undefined4 param_2)

{
  int iVar1;
  LPSTR lpString;
  int nMaxCount;
  
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    iVar1 = GetWindowTextLengthA(*(HWND *)(param_1 + 0x1c));
    nMaxCount = iVar1 + 1;
    lpString = (LPSTR)FUN_004b09cd(iVar1);
    GetWindowTextA(*(HWND *)(param_1 + 0x1c),lpString,nMaxCount);
    FUN_004b09a5(0xffffffff);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x38) + 0x90))(param_2);
  }
  return;
}


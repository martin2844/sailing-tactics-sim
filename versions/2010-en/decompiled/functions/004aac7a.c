
int __fastcall FUN_004aac7a(int param_1)

{
  bool bVar1;
  HWND hWnd;
  undefined4 uVar2;
  BOOL BVar3;
  int iVar4;
  int iVar5;
  
  hWnd = GetFocus();
  bVar1 = false;
  uVar2 = FUN_004abed1();
  *(undefined4 *)(param_1 + 0x60) = uVar2;
  FUN_004acd09();
  if (*(HWND *)(param_1 + 0x60) != (HWND)0x0) {
    BVar3 = IsWindowEnabled(*(HWND *)(param_1 + 0x60));
    if (BVar3 != 0) {
      bVar1 = true;
      EnableWindow(*(HWND *)(param_1 + 0x60),0);
    }
  }
  iVar4 = FUN_004bfca5();
  if ((*(byte *)(param_1 + 0x92) & 8) == 0) {
    FUN_004accbd(param_1);
  }
  else {
    *(int *)(iVar4 + 0x18) = param_1;
  }
  if (*(int *)(param_1 + 0xa8) == 0) {
    iVar5 = GetSaveFileNameA((LPOPENFILENAMEA)(param_1 + 0x5c));
  }
  else {
    iVar5 = GetOpenFileNameA((LPOPENFILENAMEA)(param_1 + 0x5c));
  }
  *(undefined4 *)(iVar4 + 0x18) = 0;
  if (bVar1) {
    EnableWindow(*(HWND *)(param_1 + 0x60),1);
  }
  BVar3 = IsWindow(hWnd);
  if (BVar3 != 0) {
    SetFocus(hWnd);
  }
  FUN_004abf08();
  if (iVar5 == 0) {
    iVar5 = 2;
  }
  return iVar5;
}


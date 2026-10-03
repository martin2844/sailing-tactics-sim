
undefined4 __thiscall FUN_004abaf0(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  HWND hWnd;
  BOOL BVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_004ad0e8(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_004adeef();
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) {
      return 0;
    }
    if ((((param_2[1] != 0x100) ||
         (((param_2[2] != 0x1b && (param_2[2] != 3)) ||
          (uVar2 = GetWindowLongA((HWND)*param_2,-0x10), (uVar2 & 4) == 0)))) ||
        (iVar1 = FUN_004b5505(*param_2,&DAT_004cd2d8), iVar1 == 0)) ||
       ((hWnd = GetDlgItem(*(HWND *)(param_1 + 0x1c),2), hWnd != (HWND)0x0 &&
        (BVar3 = IsWindowEnabled(hWnd), BVar3 == 0)))) {
      uVar4 = FUN_004aefc9(param_2);
      return uVar4;
    }
    SendMessageA(*(HWND *)(param_1 + 0x1c),0x111,2,0);
  }
  return 1;
}


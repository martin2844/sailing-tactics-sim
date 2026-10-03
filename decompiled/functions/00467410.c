
undefined4 __thiscall FUN_00467410(void *this,LPMSG param_1)

{
  bool bVar1;
  int iVar2;
  CWnd *pCVar3;
  uint uVar4;
  undefined3 extraout_var;
  HWND hWnd;
  BOOL BVar5;
  undefined4 uVar6;
  
  iVar2 = FUN_00468a08(this,param_1);
  if (iVar2 == 0) {
    pCVar3 = FUN_0046980f(this);
    if ((pCVar3 != (CWnd *)0x0) && (*(int *)(pCVar3 + 0x50) != 0)) {
      return 0;
    }
    if ((((param_1->message != 0x100) ||
         (((param_1->wParam != 0x1b && (param_1->wParam != 3)) ||
          (uVar4 = GetWindowLongA(param_1->hwnd,-0x10), (uVar4 & 4) == 0)))) ||
        (bVar1 = FUN_00470e25(param_1->hwnd,"Edit"), CONCAT31(extraout_var,bVar1) == 0)) ||
       ((hWnd = GetDlgItem(*(HWND *)((int)this + 0x1c),2), hWnd != (HWND)0x0 &&
        (BVar5 = IsWindowEnabled(hWnd), BVar5 == 0)))) {
      uVar6 = FUN_0046a8e9(this,param_1);
      return uVar6;
    }
    SendMessageA(*(HWND *)((int)this + 0x1c),0x111,2,0);
  }
  return 1;
}


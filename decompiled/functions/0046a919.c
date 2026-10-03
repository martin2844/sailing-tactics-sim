
int __thiscall FUN_0046a919(void *this,byte param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  HWND hWnd;
  CWinThread *pCVar4;
  BOOL BVar5;
  LRESULT LVar6;
  CWinThread *pCVar7;
  int iVar8;
  LPMSG lpMsg;
  int local_c;
  
  bVar1 = true;
  local_c = 0;
  if ((param_1 & 4) != 0) {
    uVar3 = FUN_0046ad0b((int)this);
    bVar2 = true;
    if ((uVar3 & 0x10000000) == 0) goto LAB_0046a94a;
  }
  bVar2 = false;
LAB_0046a94a:
  hWnd = GetParent(*(HWND *)((int)this + 0x1c));
  *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) | 0x18;
  pCVar4 = AfxGetThread();
  lpMsg = (LPMSG)(pCVar4 + 0x30);
LAB_0046a96b:
  while ((!bVar1 || (BVar5 = PeekMessageA(lpMsg,(HWND)0x0,0,0,0), BVar5 != 0))) {
    do {
      pCVar7 = AfxGetThread();
      iVar8 = (**(code **)(*(int *)pCVar7 + 100))();
      if (iVar8 == 0) {
        AfxPostQuitMessage(0);
        return -1;
      }
      if ((bVar2) && ((*(int *)(pCVar4 + 0x34) == 0x118 || (*(int *)(pCVar4 + 0x34) == 0x104)))) {
        FUN_0046ae4c(this,1);
        UpdateWindow(*(HWND *)((int)this + 0x1c));
        bVar2 = false;
      }
      iVar8 = (**(code **)(*(int *)this + 0x78))();
      if (iVar8 == 0) {
        *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xffffffe7;
        return *(int *)((int)this + 0x2c);
      }
      pCVar7 = AfxGetThread();
      iVar8 = (**(code **)(*(int *)pCVar7 + 0x6c))(lpMsg);
      if (iVar8 != 0) {
        bVar1 = true;
        local_c = 0;
      }
      BVar5 = PeekMessageA(lpMsg,(HWND)0x0,0,0,0);
    } while (BVar5 != 0);
  }
  if (bVar2) {
    FUN_0046ae4c(this,1);
    UpdateWindow(*(HWND *)((int)this + 0x1c));
    bVar2 = false;
  }
  if ((((param_1 & 1) == 0) && (hWnd != (HWND)0x0)) && (local_c == 0)) {
    SendMessageA(hWnd,0x121,0,*(LPARAM *)((int)this + 0x1c));
  }
  if ((param_1 & 2) == 0) goto code_r0x0046a9c5;
  goto LAB_0046a9dd;
code_r0x0046a9c5:
  iVar8 = local_c + 1;
  LVar6 = SendMessageA(*(HWND *)((int)this + 0x1c),0x36a,0,local_c);
  local_c = iVar8;
  if (LVar6 == 0) {
LAB_0046a9dd:
    bVar1 = false;
  }
  goto LAB_0046a96b;
}


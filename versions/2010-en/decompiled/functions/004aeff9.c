
int __thiscall FUN_004aeff9(int *param_1,byte param_2)

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
  if ((param_2 & 4) != 0) {
    uVar3 = FUN_004af3eb();
    bVar2 = true;
    if ((uVar3 & 0x10000000) == 0) goto LAB_004af02a;
  }
  bVar2 = false;
LAB_004af02a:
  hWnd = GetParent((HWND)param_1[7]);
  param_1[9] = param_1[9] | 0x18;
  pCVar4 = AfxGetThread();
  lpMsg = (LPMSG)(pCVar4 + 0x30);
LAB_004af04b:
  while ((!bVar1 || (BVar5 = PeekMessageA(lpMsg,(HWND)0x0,0,0,0), BVar5 != 0))) {
    do {
      pCVar7 = AfxGetThread();
      iVar8 = (**(code **)(*(int *)pCVar7 + 100))();
      if (iVar8 == 0) {
        AfxPostQuitMessage(0);
        return -1;
      }
      if ((bVar2) && ((*(int *)(pCVar4 + 0x34) == 0x118 || (*(int *)(pCVar4 + 0x34) == 0x104)))) {
        FUN_004af52c(1);
        UpdateWindow((HWND)param_1[7]);
        bVar2 = false;
      }
      iVar8 = (**(code **)(*param_1 + 0x78))();
      if (iVar8 == 0) {
        param_1[9] = param_1[9] & 0xffffffe7;
        return param_1[0xb];
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
    FUN_004af52c(1);
    UpdateWindow((HWND)param_1[7]);
    bVar2 = false;
  }
  if ((((param_2 & 1) == 0) && (hWnd != (HWND)0x0)) && (local_c == 0)) {
    SendMessageA(hWnd,0x121,0,param_1[7]);
  }
  if ((param_2 & 2) == 0) goto code_r0x004af0a5;
  goto LAB_004af0bd;
code_r0x004af0a5:
  iVar8 = local_c + 1;
  LVar6 = SendMessageA((HWND)param_1[7],0x36a,0,local_c);
  local_c = iVar8;
  if (LVar6 == 0) {
LAB_004af0bd:
    bVar1 = false;
  }
  goto LAB_004af04b;
}


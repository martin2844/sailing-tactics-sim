
void FUN_004640b0(int param_1,HWND param_2,int *param_3)

{
  int iVar1;
  DWORD DVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  uint uVar5;
  int iVar6;
  HWND pHVar7;
  int iVar8;
  bool bVar9;
  int local_4;
  
  DVar3 = GetCurrentThreadId();
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  if (DAT_004aff94 != DVar3) {
    iVar8 = 0;
    bVar9 = DAT_004aff9c == 0;
    if (0 < DAT_004aff9c) {
      pDVar4 = &DAT_004affa4;
      do {
        DVar2 = DVar3;
        iVar1 = iVar8;
        if (*pDVar4 == DVar3) break;
        pDVar4 = pDVar4 + 5;
        iVar8 = iVar8 + 1;
        DVar2 = DAT_004aff94;
        iVar1 = DAT_004aff98;
      } while (iVar8 < DAT_004aff9c);
      DAT_004aff98 = iVar1;
      DAT_004aff94 = DVar2;
      bVar9 = iVar8 == DAT_004aff9c;
    }
    if (bVar9) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
      CallNextHookEx((HHOOK)0x0,param_1,(WPARAM)param_2,(LPARAM)param_3);
      return;
    }
  }
  iVar8 = DAT_004aff98;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  if (param_1 != 3) goto LAB_0046423c;
  iVar1 = *param_3;
  if (*(int *)(iVar1 + 0x28) != 0x8002) {
    if (((&DAT_004affb0)[iVar8 * 0x14] & 1) == 0) goto LAB_0046423c;
    iVar6 = FUN_00464070(*(HWND *)(iVar1 + 0xc));
    if (iVar6 == 0) {
      if ((*(HWND *)(iVar1 + 0xc) == (HWND)0x0) || (DAT_004aff62 == 0x18)) goto LAB_0046423c;
      pHVar7 = GetParent(*(HWND *)(iVar1 + 0xc));
      iVar6 = FUN_00464070(pHVar7);
      if (iVar6 == 0) goto LAB_0046423c;
    }
    FUN_00464440(param_2,0xffff,1,*(undefined4 *)(iVar1 + 0xc));
    goto LAB_0046423c;
  }
  if (DAT_004aff62 != 0x20) {
    FUN_00462a50(param_2,FUN_00463d40);
    goto LAB_0046423c;
  }
  if (DAT_004aff60 < 0x35f) {
LAB_00464190:
    local_4 = 1;
  }
  else {
    uVar5 = GetWindowLongA(param_2,-0x10);
    local_4 = 0;
    if ((uVar5 & 4) == 0) goto LAB_00464190;
  }
  SendMessageA(param_2,0x11f0,0,(LPARAM)&local_4);
  if (local_4 != 0) {
    FUN_004628b0(param_2,0x463d40);
  }
LAB_0046423c:
  CallNextHookEx((HHOOK)(&DAT_004affa8)[iVar8 * 5],param_1,(WPARAM)param_2,(LPARAM)param_3);
  return;
}


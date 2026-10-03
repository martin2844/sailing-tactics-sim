
void FUN_004a8790(int param_1,HWND param_2,int *param_3)

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
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  if (DAT_00539ad4 != DVar3) {
    iVar8 = 0;
    bVar9 = DAT_00539adc == 0;
    if (0 < DAT_00539adc) {
      pDVar4 = &DAT_00539ae4;
      do {
        DVar2 = DVar3;
        iVar1 = iVar8;
        if (*pDVar4 == DVar3) break;
        pDVar4 = pDVar4 + 5;
        iVar8 = iVar8 + 1;
        DVar2 = DAT_00539ad4;
        iVar1 = DAT_00539ad8;
      } while (iVar8 < DAT_00539adc);
      DAT_00539ad8 = iVar1;
      DAT_00539ad4 = DVar2;
      bVar9 = iVar8 == DAT_00539adc;
    }
    if (bVar9) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
      CallNextHookEx((HHOOK)0x0,param_1,(WPARAM)param_2,(LPARAM)param_3);
      return;
    }
  }
  iVar8 = DAT_00539ad8;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  if (param_1 != 3) goto LAB_004a891c;
  iVar1 = *param_3;
  if (*(int *)(iVar1 + 0x28) != 0x8002) {
    if (((&DAT_00539af0)[iVar8 * 0x14] & 1) == 0) goto LAB_004a891c;
    iVar6 = FUN_004a8750(*(undefined4 *)(iVar1 + 0xc));
    if (iVar6 == 0) {
      if ((*(HWND *)(iVar1 + 0xc) == (HWND)0x0) || (DAT_00539aa2 == 0x18)) goto LAB_004a891c;
      pHVar7 = GetParent(*(HWND *)(iVar1 + 0xc));
      iVar6 = FUN_004a8750(pHVar7);
      if (iVar6 == 0) goto LAB_004a891c;
    }
    FUN_004a8b20(param_2,0xffff,1,*(undefined4 *)(iVar1 + 0xc));
    goto LAB_004a891c;
  }
  if (DAT_00539aa2 != 0x20) {
    FUN_004a7130(param_2,FUN_004a8420);
    goto LAB_004a891c;
  }
  if (DAT_00539aa0 < 0x35f) {
LAB_004a8870:
    local_4 = 1;
  }
  else {
    uVar5 = GetWindowLongA(param_2,-0x10);
    local_4 = 0;
    if ((uVar5 & 4) == 0) goto LAB_004a8870;
  }
  SendMessageA(param_2,0x11f0,0,(LPARAM)&local_4);
  if (local_4 != 0) {
    FUN_004a6f90(param_2,FUN_004a8420);
  }
LAB_004a891c:
  CallNextHookEx((HHOOK)(&DAT_00539ae8)[iVar8 * 5],param_1,(WPARAM)param_2,(LPARAM)param_3);
  return;
}


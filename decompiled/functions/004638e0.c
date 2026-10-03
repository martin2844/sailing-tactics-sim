
uint FUN_004638e0(void)

{
  undefined **lpClassName;
  HDC hdc;
  int iVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  tagWNDCLASSA local_28;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0xc);
  iVar2 = GetDeviceCaps(hdc,0xe);
  DAT_004aff40 = (uint)(3 < iVar1 * iVar2);
  iVar1 = GetSystemMetrics(1);
  if ((iVar1 == 0x15e) && (iVar1 = GetSystemMetrics(0), iVar1 == 0x280)) {
    DAT_004aff40 = 0;
  }
  ReleaseDC((HWND)0x0,hdc);
  if (DAT_004aff40 != 0) {
    DAT_004aff48 = GlobalAddAtomA(&DAT_004a334c);
    if ((DAT_004aff48 != 0) && (DAT_004aff4e = GlobalAddAtomA(s_C3dNew_004a3334), DAT_004aff4e != 0)
       ) {
      DAT_004aff4c = GlobalAddAtomA(&DAT_004a3344);
      DAT_004aff4a = GlobalAddAtomA(&DAT_004a333c);
      if ((DAT_004aff4c == 0) || (DAT_004aff4a == 0)) {
        DAT_004aff40 = 0;
        return 0;
      }
      DAT_004aff52 = GlobalAddAtomA(s_C3dLNew_004a332c);
      DAT_004aff50 = GlobalAddAtomA(s_C3dHNew_004a3324);
      if ((DAT_004aff52 == 0) || (DAT_004aff50 == 0)) {
        DAT_004aff40 = 0;
        return 0;
      }
      DAT_004aff54 = GlobalAddAtomA(&DAT_004a3350);
      if (DAT_004aff54 != 0) {
        iVar1 = GetSystemMetrics(0x2a);
        DAT_004b0a45 = (char)iVar1;
        FUN_00463840();
        iVar1 = FUN_00463bb0(1);
        if (iVar1 != 0) {
          ppuVar5 = &PTR_FUN_004897d4;
          puVar4 = &DAT_004b09a0;
          do {
            lpClassName = ppuVar5 + -5;
            *puVar4 = *ppuVar5;
            ppuVar5 = ppuVar5 + 8;
            GetClassInfoA((HINSTANCE)0x0,(LPCSTR)lpClassName,&local_28);
            puVar4[1] = local_28.lpfnWndProc;
            puVar4 = puVar4 + 6;
          } while (ppuVar5 < &DAT_00489894);
          BVar3 = GetClassInfoA((HINSTANCE)0x0,(LPCSTR)0x8002,&local_28);
          if (BVar3 == 0) {
            DAT_004b0a30 = DefDlgProcA_exref;
          }
          else {
            DAT_004b0a30 = local_28.lpfnWndProc;
          }
          goto LAB_0046397b;
        }
      }
    }
    DAT_004aff40 = 0;
  }
LAB_0046397b:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  return DAT_004aff40;
}


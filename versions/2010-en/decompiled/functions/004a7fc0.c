
uint FUN_004a7fc0(void)

{
  undefined **lpClassName;
  HDC hdc;
  int iVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  tagWNDCLASSA local_28;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0xc);
  iVar2 = GetDeviceCaps(hdc,0xe);
  DAT_00539a80 = (uint)(3 < iVar1 * iVar2);
  iVar1 = GetSystemMetrics(1);
  if ((iVar1 == 0x15e) && (iVar1 = GetSystemMetrics(0), iVar1 == 0x280)) {
    DAT_00539a80 = 0;
  }
  ReleaseDC((HWND)0x0,hdc);
  if (DAT_00539a80 != 0) {
    DAT_00539a88 = GlobalAddAtomA(&DAT_004f150c);
    if ((DAT_00539a88 != 0) && (DAT_00539a8e = GlobalAddAtomA(s_C3dNew_004f14f4), DAT_00539a8e != 0)
       ) {
      DAT_00539a8c = GlobalAddAtomA(&DAT_004f1504);
      DAT_00539a8a = GlobalAddAtomA(&DAT_004f14fc);
      if ((DAT_00539a8c == 0) || (DAT_00539a8a == 0)) {
        DAT_00539a80 = 0;
        return 0;
      }
      DAT_00539a92 = GlobalAddAtomA(s_C3dLNew_004f14ec);
      DAT_00539a90 = GlobalAddAtomA(s_C3dHNew_004f14e4);
      if ((DAT_00539a92 == 0) || (DAT_00539a90 == 0)) {
        DAT_00539a80 = 0;
        return 0;
      }
      DAT_00539a94 = GlobalAddAtomA(&DAT_004f1510);
      if (DAT_00539a94 != 0) {
        iVar1 = GetSystemMetrics(0x2a);
        DAT_0053a585 = (char)iVar1;
        FUN_004a7f20();
        iVar1 = FUN_004a8290(1);
        if (iVar1 != 0) {
          ppuVar5 = &PTR_FUN_004d147c;
          puVar4 = &DAT_0053a4e0;
          do {
            lpClassName = ppuVar5 + -5;
            *puVar4 = *ppuVar5;
            ppuVar5 = ppuVar5 + 8;
            GetClassInfoA((HINSTANCE)0x0,(LPCSTR)lpClassName,&local_28);
            puVar4[1] = local_28.lpfnWndProc;
            puVar4 = puVar4 + 6;
          } while (ppuVar5 < &DAT_004d153c);
          BVar3 = GetClassInfoA((HINSTANCE)0x0,(LPCSTR)0x8002,&local_28);
          if (BVar3 == 0) {
            DAT_0053a570 = DefDlgProcA_exref;
          }
          else {
            DAT_0053a570 = local_28.lpfnWndProc;
          }
          goto LAB_004a805b;
        }
      }
    }
    DAT_00539a80 = 0;
  }
LAB_004a805b:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  return DAT_00539a80;
}


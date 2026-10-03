
void __thiscall FUN_004afd68(HANDLE param_1,LPSTR param_2)

{
  LPVOID pvVar1;
  int iVar2;
  BOOL BVar3;
  SIZE_T dwBytes;
  HGLOBAL hMem;
  PDEVMODEA pDevModeOutput;
  LONG LVar4;
  HANDLE local_8;
  
  if (*(HGLOBAL *)((int)param_1 + 0x98) != (HGLOBAL)0x0) {
    local_8 = param_1;
    pvVar1 = GlobalLock(*(HGLOBAL *)((int)param_1 + 0x98));
    iVar2 = lstrcmpA((LPCSTR)((uint)*(ushort *)((int)pvVar1 + 2) + (int)pvVar1),param_2);
    if (iVar2 == 0) {
      BVar3 = OpenPrinterA(param_2,&local_8,(LPPRINTER_DEFAULTSA)0x0);
      if (BVar3 != 0) {
        if (*(int *)((int)param_1 + 0x94) != 0) {
          FUN_004b568d(*(int *)((int)param_1 + 0x94));
        }
        dwBytes = DocumentPropertiesA((HWND)0x0,local_8,param_2,(PDEVMODEA)0x0,(PDEVMODEA)0x0,0);
        hMem = GlobalAlloc(0x42,dwBytes);
        *(HGLOBAL *)((int)param_1 + 0x94) = hMem;
        pDevModeOutput = GlobalLock(hMem);
        LVar4 = DocumentPropertiesA((HWND)0x0,local_8,param_2,pDevModeOutput,(PDEVMODEA)0x0,2);
        if (LVar4 != 1) {
          FUN_004b568d(*(undefined4 *)((int)param_1 + 0x94));
          *(undefined4 *)((int)param_1 + 0x94) = 0;
        }
        ClosePrinter(local_8);
      }
    }
  }
  return;
}


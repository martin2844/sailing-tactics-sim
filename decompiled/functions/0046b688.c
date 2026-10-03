
void __thiscall FUN_0046b688(void *this,LPSTR param_1)

{
  LPVOID pvVar1;
  int iVar2;
  BOOL BVar3;
  SIZE_T dwBytes;
  HGLOBAL hMem;
  PDEVMODEA pDevModeOutput;
  LONG LVar4;
  void *local_8;
  
  if (*(HGLOBAL *)((int)this + 0x98) != (HGLOBAL)0x0) {
    local_8 = this;
    pvVar1 = GlobalLock(*(HGLOBAL *)((int)this + 0x98));
    iVar2 = lstrcmpA((LPCSTR)((uint)*(ushort *)((int)pvVar1 + 2) + (int)pvVar1),param_1);
    if (iVar2 == 0) {
      BVar3 = OpenPrinterA(param_1,&local_8,(LPPRINTER_DEFAULTSA)0x0);
      if (BVar3 != 0) {
        if (*(HGLOBAL *)((int)this + 0x94) != (HGLOBAL)0x0) {
          FUN_00470fad(*(HGLOBAL *)((int)this + 0x94));
        }
        dwBytes = DocumentPropertiesA((HWND)0x0,local_8,param_1,(PDEVMODEA)0x0,(PDEVMODEA)0x0,0);
        hMem = GlobalAlloc(0x42,dwBytes);
        *(HGLOBAL *)((int)this + 0x94) = hMem;
        pDevModeOutput = GlobalLock(hMem);
        LVar4 = DocumentPropertiesA((HWND)0x0,local_8,param_1,pDevModeOutput,(PDEVMODEA)0x0,2);
        if (LVar4 != 1) {
          FUN_00470fad(*(HGLOBAL *)((int)this + 0x94));
          *(undefined4 *)((int)this + 0x94) = 0;
        }
        ClosePrinter(local_8);
      }
    }
  }
  return;
}


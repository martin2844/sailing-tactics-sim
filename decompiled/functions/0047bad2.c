
int __fastcall FUN_0047bad2(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  byte *pbVar2;
  HGLOBAL pvVar3;
  HGLOBAL hMem;
  LPVOID pvVar4;
  int iVar5;
  int iVar6;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
  EnterCriticalSection(lpCriticalSection);
  iVar5 = *(int *)(param_1 + 4);
  iVar6 = *(int *)(param_1 + 8);
  if ((iVar5 <= iVar6) || ((*(byte *)(*(int *)(param_1 + 0x10) + iVar6 * 8) & 1) != 0)) {
    iVar6 = 1;
    if (1 < iVar5) {
      pbVar2 = *(byte **)(param_1 + 0x10);
      do {
        pbVar2 = pbVar2 + 8;
        if ((*pbVar2 & 1) == 0) break;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar5);
      if (iVar6 < iVar5) goto LAB_0047bbb6;
    }
    iVar5 = iVar5 + 0x20;
    if (*(LPCVOID *)(param_1 + 0x10) == (LPCVOID)0x0) {
      pvVar3 = GlobalAlloc(0x2002,iVar5 * 8);
    }
    else {
      pvVar3 = GlobalHandle(*(LPCVOID *)(param_1 + 0x10));
      GlobalUnlock(pvVar3);
      pvVar3 = GlobalReAlloc(pvVar3,iVar5 * 8,0x2002);
    }
    if (pvVar3 == (HGLOBAL)0x0) {
      hMem = GlobalHandle(*(LPCVOID *)(param_1 + 0x10));
      GlobalLock(hMem);
      LeaveCriticalSection(lpCriticalSection);
      FUN_00466060();
    }
    pvVar4 = GlobalLock(pvVar3);
    _memset((void *)((int)pvVar4 + *(int *)(param_1 + 4) * 8),0,
            (*(int *)(param_1 + 4) * 0x1fffffff + iVar5) * 8);
    *(int *)(param_1 + 4) = iVar5;
    *(LPVOID *)(param_1 + 0x10) = pvVar4;
  }
LAB_0047bbb6:
  if (*(int *)(param_1 + 0xc) <= iVar6) {
    *(int *)(param_1 + 0xc) = iVar6 + 1;
  }
  puVar1 = (uint *)(*(int *)(param_1 + 0x10) + iVar6 * 8);
  *puVar1 = *puVar1 | 1;
  *(int *)(param_1 + 8) = iVar6 + 1;
  LeaveCriticalSection(lpCriticalSection);
  return iVar6;
}


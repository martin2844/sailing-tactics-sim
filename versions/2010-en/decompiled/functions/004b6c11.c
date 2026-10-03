
int __thiscall FUN_004b6c11(HWND param_1,LPCSTR param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  HWND hWnd;
  HWND pHVar5;
  HWND local_8;
  
  local_8 = param_1;
  FUN_004b6be3(0);
  iVar1 = FUN_004adf33(0,&local_8);
  pHVar5 = param_1 + 0x27;
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_004ade0b();
    iVar3 = (**(code **)(*piVar2 + 0xb8))();
    if (iVar3 != 0) {
      pHVar5 = (HWND)(piVar2 + 0x13);
    }
  }
  iVar3 = pHVar5->unused;
  if (param_4 != 0) {
    pHVar5->unused = param_4 + 0x30000;
  }
  if (((param_3 & 0xf0) == 0) &&
     ((uVar4 = param_3 & 0xf, uVar4 < 2 || ((2 < uVar4 && (uVar4 < 5)))))) {
    param_3 = param_3 | 0x30;
  }
  FUN_004bfca5();
  hWnd = (HWND)0x0;
  if (iVar1 != 0) {
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  iVar1 = MessageBoxA(hWnd,param_2,(LPCSTR)param_1[0x1e].unused,param_3);
  pHVar5->unused = iVar3;
  if (local_8 != (HWND)0x0) {
    EnableWindow(local_8,1);
  }
  FUN_004b6be3(1);
  return iVar1;
}


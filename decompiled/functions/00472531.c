
int __thiscall FUN_00472531(void *this,LPCSTR param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  HWND hWnd;
  int *piVar5;
  HWND local_8;
  
  local_8 = this;
  FUN_00472503(0);
  iVar1 = FUN_00469853(0,&local_8);
  piVar5 = (int *)((int)this + 0x9c);
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_0046972b(iVar1);
    iVar3 = (**(code **)(*piVar2 + 0xb8))();
    if (iVar3 != 0) {
      piVar5 = piVar2 + 0x13;
    }
  }
  iVar3 = *piVar5;
  if (param_3 != 0) {
    *piVar5 = param_3 + 0x30000;
  }
  if (((param_2 & 0xf0) == 0) &&
     ((uVar4 = param_2 & 0xf, uVar4 < 2 || ((2 < uVar4 && (uVar4 < 5)))))) {
    param_2 = param_2 | 0x30;
  }
  FUN_0047b5c5();
  hWnd = (HWND)0x0;
  if (iVar1 != 0) {
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  iVar1 = MessageBoxA(hWnd,param_1,*(LPCSTR *)((int)this + 0x78),param_2);
  *piVar5 = iVar3;
  if (local_8 != (HWND)0x0) {
    EnableWindow(local_8,1);
  }
  FUN_00472503(1);
  return iVar1;
}


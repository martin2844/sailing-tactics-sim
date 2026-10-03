
void __thiscall FUN_0046a210(void *this,LPSTR param_1)

{
  CWinThread *pCVar1;
  int iVar2;
  uint uVar3;
  
  pCVar1 = AfxGetThread();
  if (pCVar1 != (CWinThread *)0x0) {
    pCVar1 = AfxGetThread();
    if (*(void **)(pCVar1 + 0x1c) == this) {
      iVar2 = FUN_0047b918();
      FUN_0046b688(*(void **)(iVar2 + 4),param_1);
    }
  }
  uVar3 = FUN_0046ad0b((int)this);
  if ((uVar3 & 0x40000000) == 0) {
    iVar2 = FUN_00467fec();
    FUN_0046996c(*(HWND *)((int)this + 0x1c),*(UINT *)(iVar2 + 4),*(WPARAM *)(iVar2 + 8),
                 *(LPARAM *)(iVar2 + 0xc),1,1);
  }
  return;
}


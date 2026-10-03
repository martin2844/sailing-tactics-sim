
void __thiscall FUN_0047587b(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = -1;
  uVar1 = GetDlgCtrlID(*(HWND *)(param_1 + 0x1c));
  iVar2 = FUN_00475fbe(this,uVar1 & 0xffff,iVar2);
  if (0 < iVar2) {
    FUN_00466e78((void *)((int)this + 0x7c),iVar2,1);
    if ((*(int *)(*(int *)((int)this + 0x80) + -4 + iVar2 * 4) == 0) &&
       (*(int *)(*(int *)((int)this + 0x80) + iVar2 * 4) == 0)) {
      FUN_00466e78((void *)((int)this + 0x7c),iVar2,1);
    }
  }
  return;
}


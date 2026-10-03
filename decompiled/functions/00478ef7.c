
undefined4 __thiscall FUN_00478ef7(void *this,int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0046ad0b((int)this);
  if ((uVar1 & 0x100) == 0) {
    if (DAT_004ae69c != 0) {
      uVar2 = FUN_00468021(this);
      return uVar2;
    }
    if (*(int *)((int)this + 0xc4) != param_1) {
      *(int *)((int)this + 0xc4) = param_1;
      SendMessageA(*(HWND *)((int)this + 0x1c),0x85,0,0);
    }
  }
  else if ((*(byte *)((int)this + 0x25) & 2) != 0) {
    return 0;
  }
  return 1;
}


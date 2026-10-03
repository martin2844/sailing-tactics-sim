
void __thiscall FUN_0046acd8(void *this,LPMSG param_1)

{
  int iVar1;
  
  if ((*(byte *)((int)this + 0x25) & 1) == 0) {
    IsDialogMessageA(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    iVar1 = FUN_0047b918();
    (**(code **)(**(int **)(iVar1 + 0x1038) + 0x24))(this,param_1);
  }
  return;
}


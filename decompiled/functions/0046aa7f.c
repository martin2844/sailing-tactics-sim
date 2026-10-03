
void __thiscall FUN_0046aa7f(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x2c) = param_1;
  if ((*(uint *)((int)this + 0x24) & 0x10) != 0) {
    *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xffffffef;
    PostMessageA(*(HWND *)((int)this + 0x1c),0,0,0);
  }
  return;
}


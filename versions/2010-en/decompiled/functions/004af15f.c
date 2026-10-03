
void __thiscall FUN_004af15f(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  if ((*(uint *)(param_1 + 0x24) & 0x10) != 0) {
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xffffffef;
    PostMessageA(*(HWND *)(param_1 + 0x1c),0,0,0);
  }
  return;
}


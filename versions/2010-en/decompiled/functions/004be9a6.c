
void __thiscall FUN_004be9a6(int param_1,undefined4 param_2)

{
  if ((DAT_005381ec != 0) && ((*(uint *)(param_1 + 100) & 0xff00) == 0x8200)) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffff07f;
  }
  FUN_004c0994(param_2);
  return;
}


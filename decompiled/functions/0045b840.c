
void __cdecl FUN_0045b840(uint param_1)

{
  if ((0x4a256f < param_1) && (param_1 < 0x4a27d1)) {
    FUN_0045b7b0(((int)(param_1 - 0x4a2570) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}


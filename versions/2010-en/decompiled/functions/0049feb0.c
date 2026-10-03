
void FUN_0049feb0(uint param_1)

{
  if ((0x4f072f < param_1) && (param_1 < 0x4f0991)) {
    FUN_0049fe10(((int)(param_1 - 0x4f0730) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}


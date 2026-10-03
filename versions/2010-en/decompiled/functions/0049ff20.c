
void FUN_0049ff20(uint param_1)

{
  if ((0x4f072f < param_1) && (param_1 < 0x4f0991)) {
    FUN_0049fe90(((int)(param_1 - 0x4f0730) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}


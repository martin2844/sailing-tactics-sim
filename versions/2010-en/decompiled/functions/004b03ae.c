
undefined4 FUN_004b03ae(int param_1)

{
  SHORT SVar1;
  
  if ((((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 0x70)) &&
      ((*(uint *)(param_1 + 0xc) >> 0x10 & 0x4000) == 0)) &&
     (((SVar1 = GetKeyState(0x10), -1 < SVar1 && (SVar1 = GetKeyState(0x11), -1 < SVar1)) &&
      (SVar1 = GetKeyState(0x12), -1 < SVar1)))) {
    return 1;
  }
  return 0;
}


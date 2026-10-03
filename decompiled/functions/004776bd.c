
undefined4 FUN_004776bd(HWND param_1,undefined4 param_2)

{
  int iVar1;
  short sVar2;
  CHAR local_10c [260];
  int local_8;
  
  iVar1 = FUN_0047b918();
  iVar1 = *(int *)(iVar1 + 4);
  if (((((ATOM)param_2 != 0) && (sVar2 = (short)((uint)param_2 >> 0x10), sVar2 != 0)) &&
      ((ATOM)param_2 == *(ATOM *)(iVar1 + 0xb0))) && (sVar2 == *(short *)(iVar1 + 0xb2))) {
    GlobalGetAtomNameA(*(ATOM *)(iVar1 + 0xb0),local_10c,0x103);
    GlobalAddAtomA(local_10c);
    GlobalGetAtomNameA(*(ATOM *)(iVar1 + 0xb2),local_10c,0x103);
    GlobalAddAtomA(local_10c);
    SendMessageA(param_1,0x3e4,*(WPARAM *)(local_8 + 0x1c),*(LPARAM *)(iVar1 + 0xb0));
  }
  return 0;
}


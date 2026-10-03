
void __cdecl FUN_00458c50(undefined *param_1)

{
  DWORD *pDVar1;
  undefined **ppuVar2;
  int iVar3;
  
  pDVar1 = FUN_00458ce0();
  iVar3 = 0;
  *pDVar1 = (DWORD)param_1;
  ppuVar2 = (undefined **)&DAT_0049fc18;
  do {
    if (param_1 == *ppuVar2) {
      pDVar1 = FUN_00458cd0();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x49fc1c);
      return;
    }
    ppuVar2 = ppuVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (ppuVar2 < &PTR_DAT_0049fd80);
  if (((undefined *)0x12 < param_1) && (param_1 < (undefined *)0x25)) {
    pDVar1 = FUN_00458cd0();
    *pDVar1 = 0xd;
    return;
  }
  if (((undefined *)0xbb < param_1) && (param_1 < (undefined *)0xcb)) {
    pDVar1 = FUN_00458cd0();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_00458cd0();
  *pDVar1 = 0x16;
  return;
}


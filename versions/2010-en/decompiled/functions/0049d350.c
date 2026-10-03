
void FUN_0049d350(undefined *param_1)

{
  undefined4 *puVar1;
  undefined **ppuVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)FUN_0049d3e0();
  iVar3 = 0;
  *puVar1 = param_1;
  ppuVar2 = (undefined **)&DAT_004eddd8;
  do {
    if (param_1 == *ppuVar2) {
      puVar1 = (undefined4 *)FUN_0049d3d0();
      *puVar1 = *(undefined4 *)(iVar3 * 8 + 0x4edddc);
      return;
    }
    ppuVar2 = ppuVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (ppuVar2 < &PTR_DAT_004edf40);
  if (((undefined *)0x12 < param_1) && (param_1 < (undefined *)0x25)) {
    puVar1 = (undefined4 *)FUN_0049d3d0();
    *puVar1 = 0xd;
    return;
  }
  if (((undefined *)0xbb < param_1) && (param_1 < (undefined *)0xcb)) {
    puVar1 = (undefined4 *)FUN_0049d3d0();
    *puVar1 = 8;
    return;
  }
  puVar1 = (undefined4 *)FUN_0049d3d0();
  *puVar1 = 0x16;
  return;
}


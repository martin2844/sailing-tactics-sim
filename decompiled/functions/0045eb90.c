
void FUN_0045eb90(void)

{
  undefined **ppuVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (DAT_004afde0 == 0) {
    DAT_004afde0 = 0x200;
  }
  else if (DAT_004afde0 < 0x14) {
    DAT_004afde0 = 0x14;
  }
  DAT_004aedc4 = FUN_00458640(DAT_004afde0,4);
  if (DAT_004aedc4 == (int *)0x0) {
    DAT_004afde0 = 0x14;
    DAT_004aedc4 = FUN_00458640(0x14,4);
    if (DAT_004aedc4 == (int *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  iVar3 = 0;
  ppuVar1 = &PTR_DAT_004a2570;
  do {
    *(undefined ***)((int)DAT_004aedc4 + iVar3) = ppuVar1;
    ppuVar1 = ppuVar1 + 8;
    iVar3 = iVar3 + 4;
  } while ((int)ppuVar1 < 0x4a27f0);
  uVar2 = 0;
  puVar4 = &DAT_004a2580;
  do {
    iVar3 = *(int *)((&DAT_004afe00)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
    if ((iVar3 == -1) || (iVar3 == 0)) {
      *puVar4 = 0xffffffff;
    }
    puVar4 = puVar4 + 8;
    uVar2 = uVar2 + 1;
  } while ((int)puVar4 < 0x4a25e0);
  return;
}


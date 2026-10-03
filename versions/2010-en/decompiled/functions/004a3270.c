
void FUN_004a3270(void)

{
  undefined **ppuVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (DAT_00539920 == 0) {
    DAT_00539920 = 0x200;
  }
  else if (DAT_00539920 < 0x14) {
    DAT_00539920 = 0x14;
  }
  DAT_0053891c = FUN_0049cf00(DAT_00539920,4);
  if (DAT_0053891c == 0) {
    DAT_00539920 = 0x14;
    DAT_0053891c = FUN_0049cf00(0x14,4);
    if (DAT_0053891c == 0) {
      __amsg_exit(0x1a);
    }
  }
  iVar3 = 0;
  ppuVar1 = &PTR_DAT_004f0730;
  do {
    *(undefined ***)(DAT_0053891c + iVar3) = ppuVar1;
    ppuVar1 = ppuVar1 + 8;
    iVar3 = iVar3 + 4;
  } while ((int)ppuVar1 < 0x4f09b0);
  uVar2 = 0;
  puVar4 = &DAT_004f0740;
  do {
    iVar3 = *(int *)((&DAT_00539940)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
    if ((iVar3 == -1) || (iVar3 == 0)) {
      *puVar4 = 0xffffffff;
    }
    puVar4 = puVar4 + 8;
    uVar2 = uVar2 + 1;
  } while ((int)puVar4 < 0x4f07a0);
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e0a0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 400;
  piVar3 = &DAT_004a4928;
  iVar4 = 0;
  do {
    iVar1 = FUN_00415a20(0x14);
    *(int *)((int)&DAT_004a8870 + iVar4) = iVar1 + iVar2 + -0x1c2;
    iVar1 = FUN_00415a20(0xf);
    *(int *)((int)&DAT_004a44f0 + iVar4) = iVar1 + 3;
    iVar1 = FUN_00415a20(0x28);
    iVar4 = iVar4 + 4;
    *piVar3 = iVar1 + 0x14;
    iVar2 = iVar2 + 0x32;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 0x19);
  iVar2 = DAT_004aa804 * 0x5a;
  DAT_004a885c = iVar2 + -0x87;
  iVar4 = FUN_00415a20(4);
  DAT_004a44dc = iVar4 + 1;
  DAT_004a8860 = iVar2 + -0x73;
  iVar4 = FUN_00415a20(7);
  DAT_004a44e0 = iVar4 + 3;
  _DAT_004a8864 = iVar2 + -0x52;
  _DAT_004a44e4 = FUN_00415a20(7);
  _DAT_004a44e4 = _DAT_004a44e4 + 3;
  _DAT_004a8868 = iVar2 + -0x46;
  _DAT_004a44e8 = FUN_00415a20(7);
  _DAT_004a44e8 = _DAT_004a44e8 + 3;
  _DAT_004a886c = iVar2 + -0x37;
  iVar2 = FUN_00415a20(4);
  _DAT_004a44ec = iVar2 + 1;
  return;
}


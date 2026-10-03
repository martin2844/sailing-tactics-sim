
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00441400(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 400;
  piVar2 = &DAT_004f4e28;
  iVar3 = 0;
  do {
    iVar1 = FUN_0041e000(0x14);
    *(int *)((int)&DAT_00511570 + iVar3) = iVar1 + iVar4 + -0x1c2;
    iVar1 = FUN_0041e000(0xf);
    *(int *)((int)&DAT_004f4868 + iVar3) = iVar1 + 3;
    iVar1 = FUN_0041e000(0x28);
    iVar3 = iVar3 + 4;
    *piVar2 = iVar1 + 0x14;
    iVar4 = iVar4 + 0x32;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 0x19);
  iVar3 = DAT_005230dc * 0x5a + -0x5a;
  if (DAT_004da1f8 == 0x67) {
    iVar3 = 0x136;
  }
  if (DAT_004da1f8 == 0) {
    DAT_0051155c = iVar3 + -0x2d;
    iVar4 = FUN_0041e000(4);
    DAT_004f4854 = iVar4 + 1;
    DAT_00511560 = iVar3 + -0x19;
    iVar4 = FUN_0041e000(7);
    DAT_004f4858 = iVar4 + 3;
    _DAT_00511564 = iVar3 + 8;
    _DAT_004f485c = FUN_0041e000(7);
    _DAT_004f485c = _DAT_004f485c + 3;
    _DAT_00511568 = iVar3 + 0x14;
    _DAT_004f4860 = FUN_0041e000(7);
    _DAT_004f4860 = _DAT_004f4860 + 3;
    _DAT_0051156c = iVar3 + 0x23;
    iVar3 = FUN_0041e000(4);
    _DAT_004f4864 = iVar3 + 1;
    return;
  }
  DAT_0051155c = iVar3 + -0x2d;
  DAT_00511560 = iVar3 + -0x19;
  _DAT_0051156c = iVar3 + 0x23;
  DAT_004f4854 = 3;
  DAT_004f4858 = 6;
  _DAT_00511564 = iVar3 + 8;
  _DAT_004f485c = 7;
  _DAT_00511568 = iVar3 + 0x14;
  _DAT_004f4860 = 7;
  _DAT_004f4864 = 3;
  return;
}



uint __fastcall FUN_004b96e4(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = 0;
  uVar2 = *(uint *)(param_1 + 0x78) & 0xa000;
  if (*(int *)(param_1 + 0x7c) != 0) {
    uVar2 = (uint)(uVar2 == 0);
  }
  if ((uVar2 == 0) || ((*(uint *)(param_1 + 0x70) & 0xa000) == 0)) {
    if ((*(uint *)(param_1 + 0x70) & 0x5000) == 0) goto LAB_004b973f;
    uVar1 = *(uint *)(param_1 + 0x70) & 0xffff5fff;
    puVar3 = (undefined4 *)(param_1 + 0x38);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x70) & 0xffffafff;
    puVar3 = (undefined4 *)(param_1 + 0x28);
  }
  uVar1 = FUN_004be695(*puVar3,puVar3[1],puVar3[2],puVar3[3],uVar1,0);
LAB_004b973f:
  if ((*(int *)(param_1 + 0x7c) == 0) && (uVar1 == 0)) {
    if ((*(uint *)(param_1 + 0x70) & 0xa000) != 0) {
      uVar2 = FUN_004be695(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
                           *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),
                           *(uint *)(param_1 + 0x70) & 0xffffafff,0);
      uVar1 = FUN_004be695(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
                           *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34),
                           *(uint *)(param_1 + 0x70) & 0xffffafff,0);
      uVar1 = ~-(uint)(uVar1 != uVar2) & uVar1;
    }
    if ((uVar1 == 0) && ((*(uint *)(param_1 + 0x70) & 0x5000) != 0)) {
      uVar2 = FUN_004be695(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
                           *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34),
                           *(uint *)(param_1 + 0x70) & 0xffff5fff,0);
      uVar1 = FUN_004be695(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
                           *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),
                           *(uint *)(param_1 + 0x70) & 0xffff5fff,0);
      uVar1 = ~-(uint)(uVar1 != uVar2) & uVar1;
    }
  }
  return uVar1;
}


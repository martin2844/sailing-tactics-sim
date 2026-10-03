
undefined4 FUN_004bfa4a(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_005381ec == 0) {
    iVar1 = FUN_004c0587(FUN_0049a382);
    if (*(int *)(iVar1 + 4) == 0) {
      *(code **)(iVar1 + 0xc) = FUN_004a74f0;
      *(code **)(iVar1 + 0x10) = FUN_004a7560;
      *(code **)(iVar1 + 0x14) = FUN_004a7620;
      *(code **)(iVar1 + 0x18) = FUN_004a77a0;
      *(code **)(iVar1 + 0x1c) = FUN_004a7c40;
      *(code **)(iVar1 + 0x20) = FUN_004a7b40;
      *(code **)(iVar1 + 0x24) = FUN_004a7f20;
      *(code **)(iVar1 + 0x28) = FUN_004a7840;
      *(code **)(iVar1 + 0x2c) = FUN_004a7980;
      iVar2 = FUN_004bfff8();
      iVar2 = (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar2 + 8));
      if (iVar2 == 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(undefined4 *)(iVar1 + 0x10) = 0;
        *(undefined4 *)(iVar1 + 0x14) = 0;
        *(undefined4 *)(iVar1 + 0x18) = 0;
        *(undefined4 *)(iVar1 + 0x1c) = 0;
        *(undefined4 *)(iVar1 + 0x20) = 0;
        *(undefined4 *)(iVar1 + 0x24) = 0;
        *(undefined4 *)(iVar1 + 0x28) = 0;
        *(undefined4 *)(iVar1 + 0x2c) = 0;
      }
      *(undefined4 *)(iVar1 + 4) = 1;
    }
    if (*(int *)(iVar1 + 0x14) == 0) {
      uVar3 = 0;
    }
    else {
      iVar2 = FUN_004bfff8();
      uVar3 = (**(code **)(iVar1 + 0x14))(*(undefined4 *)(iVar2 + 8));
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


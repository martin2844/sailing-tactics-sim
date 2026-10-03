
undefined4 FUN_0047b36a(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_004ae694 == 0) {
    iVar1 = FUN_0047bea7();
    if (*(int *)(iVar1 + 4) == 0) {
      *(code **)(iVar1 + 0xc) = FUN_00462e10;
      *(code **)(iVar1 + 0x10) = FUN_00462e80;
      *(code **)(iVar1 + 0x14) = FUN_00462f40;
      *(code **)(iVar1 + 0x18) = FUN_004630c0;
      *(code **)(iVar1 + 0x1c) = FUN_00463560;
      *(code **)(iVar1 + 0x20) = FUN_00463460;
      *(code **)(iVar1 + 0x24) = FUN_00463840;
      *(code **)(iVar1 + 0x28) = FUN_00463160;
      *(code **)(iVar1 + 0x2c) = FUN_004632a0;
      iVar2 = FUN_0047b918();
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
      iVar2 = FUN_0047b918();
      uVar3 = (**(code **)(iVar1 + 0x14))(*(undefined4 *)(iVar2 + 8));
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


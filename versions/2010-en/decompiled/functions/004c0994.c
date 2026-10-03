
undefined4 __thiscall FUN_004c0994(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_004ace0f(param_2);
  if (iVar2 == 0) {
    return 0;
  }
  *(byte *)(param_2 + 0x23) = *(byte *)(param_2 + 0x23) | 4;
  if (DAT_005381ec == 0) {
    return 1;
  }
  uVar1 = *(uint *)(param_1 + 100);
  if ((uVar1 & 0x80) != 0) {
    return 1;
  }
  uVar4 = 0;
  uVar3 = uVar1 & 0xff00;
  if (uVar3 != 0x1400) {
    if (uVar3 == 0x2800) {
      uVar4 = 0x200;
      goto LAB_004c09f7;
    }
    if (uVar3 != 0x4100) {
      if (uVar3 == 0x8200) {
        uVar4 = 0x800;
      }
      goto LAB_004c09f7;
    }
  }
  uVar4 = 0xa00;
LAB_004c09f7:
  if (uVar4 != 0) {
    *(uint *)(param_1 + 100) = uVar1 & 0xfffff0ff | uVar4 | 0x80;
  }
  return 1;
}


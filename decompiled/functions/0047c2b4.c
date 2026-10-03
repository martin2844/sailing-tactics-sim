
undefined4 __thiscall FUN_0047c2b4(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0046872f(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 4;
  if (DAT_004ae694 == 0) {
    return 1;
  }
  uVar1 = *(uint *)((int)this + 100);
  if ((uVar1 & 0x80) != 0) {
    return 1;
  }
  uVar4 = 0;
  uVar3 = uVar1 & 0xff00;
  if (uVar3 != 0x1400) {
    if (uVar3 == 0x2800) {
      uVar4 = 0x200;
      goto LAB_0047c317;
    }
    if (uVar3 != 0x4100) {
      if (uVar3 == 0x8200) {
        uVar4 = 0x800;
      }
      goto LAB_0047c317;
    }
  }
  uVar4 = 0xa00;
LAB_0047c317:
  if (uVar4 != 0) {
    *(uint *)((int)this + 100) = uVar1 & 0xfffff0ff | uVar4 | 0x80;
  }
  return 1;
}


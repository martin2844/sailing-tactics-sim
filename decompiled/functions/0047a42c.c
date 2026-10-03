
undefined4 __thiscall FUN_0047a42c(void *this,int param_1,int param_2)

{
  undefined **ppuVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = 0;
  if (0 < *(int *)((int)this + 0x58)) {
    piVar3 = (int *)(*(int *)((int)this + 0x5c) + 0x10);
    do {
      FUN_0046bec5(piVar3);
      piVar3 = piVar3 + 5;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)((int)this + 0x58));
  }
  iVar5 = FUN_0047c35e(this,param_1,param_2);
  uVar2 = 0;
  if (iVar5 != 0) {
    iVar5 = 0;
    if (0 < *(int *)((int)this + 0x58)) {
      puVar4 = (undefined4 *)(*(int *)((int)this + 0x5c) + 0x10);
      do {
        uVar6 = 4;
        ppuVar1 = FUN_0046bd74();
        FUN_00457850(puVar4,ppuVar1,uVar6);
        puVar4 = puVar4 + 5;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)((int)this + 0x58));
    }
    uVar2 = 1;
  }
  return uVar2;
}


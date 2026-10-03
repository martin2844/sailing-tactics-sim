
undefined4 __thiscall FUN_004670ae(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)((int)this + 4);
  if (iVar1 != 0) {
    uVar4 = (param_1 >> 4) % *(uint *)((int)this + 8);
    puVar2 = *(undefined4 **)(iVar1 + uVar4 * 4);
    puVar5 = (undefined4 *)(iVar1 + uVar4 * 4);
    while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {
      if (puVar3[1] == param_1) {
        *puVar5 = *puVar3;
        FUN_00466fe0(this,puVar3);
        return 1;
      }
      puVar5 = puVar3;
      puVar2 = (undefined4 *)*puVar3;
    }
  }
  return 0;
}


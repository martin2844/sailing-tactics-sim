
undefined4 * __thiscall FUN_004672d0(void *this,byte *param_1,uint *param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  
  uVar2 = 0;
  bVar4 = *param_1;
  pbVar5 = param_1;
  while (bVar4 != 0) {
    uVar2 = uVar2 * 0x21 + (int)(char)bVar4;
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar4 = *pbVar1;
  }
  uVar2 = uVar2 % *(uint *)((int)this + 8);
  *param_2 = uVar2;
  if (*(int *)((int)this + 4) != 0) {
    for (puVar6 = *(undefined4 **)(*(int *)((int)this + 4) + uVar2 * 4); puVar6 != (undefined4 *)0x0
        ; puVar6 = (undefined4 *)*puVar6) {
      iVar3 = FUN_00457440((byte *)puVar6[2],param_1);
      if (iVar3 == 0) {
        return puVar6;
      }
    }
  }
  return (undefined4 *)0x0;
}


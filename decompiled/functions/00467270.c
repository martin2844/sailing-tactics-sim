
undefined4 * __fastcall FUN_00467270(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  int iVar5;
  uint uVar6;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar2 = FUN_00466bf9((undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 0x18),0x10);
    iVar5 = *(int *)(param_1 + 0x18);
    puVar3 = (undefined4 *)(iVar5 * 0x10 + -0xc + iVar2);
    if (-1 < iVar5 + -1) {
      do {
        *puVar3 = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = puVar3;
        puVar3 = puVar3 + -4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  uVar6 = 4;
  uVar1 = *puVar3;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  ppuVar4 = FUN_0046bd74();
  FUN_00457850(puVar3 + 2,ppuVar4,uVar6);
  puVar3[3] = 0;
  return puVar3;
}



undefined4 * __fastcall FUN_004ab950(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = FUN_004ab2d9(param_1 + 0x14,*(undefined4 *)(param_1 + 0x18),0x10);
    iVar4 = *(int *)(param_1 + 0x18);
    puVar2 = (undefined4 *)(iVar4 * 0x10 + -0xc + iVar1);
    if (-1 < iVar4 + -1) {
      do {
        *puVar2 = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = puVar2;
        puVar2 = puVar2 + -4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x10);
  uVar3 = *puVar2;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  *(undefined4 *)(param_1 + 0x10) = uVar3;
  uVar3 = FUN_004b0454(4);
  FUN_0049c110(puVar2 + 2,uVar3);
  puVar2[3] = 0;
  return puVar2;
}


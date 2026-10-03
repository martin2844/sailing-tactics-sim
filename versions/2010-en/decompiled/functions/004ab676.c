
void __fastcall FUN_004ab676(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar2 = FUN_004ab2d9(param_1 + 0x14,*(undefined4 *)(param_1 + 0x18),0xc);
    iVar4 = *(int *)(param_1 + 0x18);
    puVar3 = (undefined4 *)(iVar2 + -8 + iVar4 * 0xc);
    if (-1 < iVar4 + -1) {
      do {
        *puVar3 = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = puVar3;
        puVar3 = puVar3 + -3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  uVar1 = *puVar3;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  puVar3[1] = 0;
  puVar3[2] = 0;
  return;
}


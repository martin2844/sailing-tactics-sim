
void __thiscall FUN_004ab1c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = FUN_004ab2d9(param_1 + 0x14,*(undefined4 *)(param_1 + 0x18),0xc);
    iVar3 = *(int *)(param_1 + 0x18);
    puVar2 = (undefined4 *)(iVar1 + -8 + iVar3 * 0xc);
    if (-1 < iVar3 + -1) {
      do {
        *puVar2 = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = puVar2;
        puVar2 = puVar2 + -3;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = *puVar2;
  puVar2[1] = param_2;
  *puVar2 = param_3;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  puVar2[2] = 0;
  return;
}


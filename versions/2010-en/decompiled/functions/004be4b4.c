
void FUN_004be4b4(int param_1,int param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = 0;
    puVar1 = &DAT_004d072c;
    do {
      if (((*puVar1 ^ *(uint *)(param_1 + 100)) & 0xf000) == 0) {
        FUN_004bc506((&DAT_004d0728)[iVar2 * 2]);
        break;
      }
      puVar1 = puVar1 + 2;
      iVar2 = iVar2 + 1;
    } while ((int)puVar1 < 0x4d074c);
  }
  FUN_004b9b30(param_1,param_3);
  return;
}


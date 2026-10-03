
void FUN_0047b7b3(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004872dc;
  puVar2 = (undefined *)extraout_ECX[5];
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (puVar2 != (undefined *)0x0) {
    FUN_00455f09();
    FUN_0046b541(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[6];
  if (puVar2 != (undefined *)0x0) {
    FUN_00455f09();
    FUN_0046b541(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[7];
  if (puVar2 != (undefined *)0x0) {
    FUN_00455f09();
    FUN_0046b541(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[8];
  if (puVar2 != (undefined *)0x0) {
    FUN_00455f09();
    FUN_0046b541(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[9];
  if (puVar2 != (undefined *)0x0) {
    FUN_00455f09();
    FUN_0046b541(puVar2);
  }
  if (extraout_ECX[0x1d] != 0) {
    do {
      puVar2 = (undefined *)FUN_00466b7b(extraout_ECX + 0x1a);
      FUN_0046b541(puVar2);
    } while (extraout_ECX[0x1d] != 0);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00466ab1();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00466f63();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00466f63();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004865ec;
  *unaff_FS_OFFSET = uVar1;
  return;
}


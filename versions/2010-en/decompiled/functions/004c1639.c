
void FUN_004c1639(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cf69c;
  puVar1 = (undefined4 *)extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  while (puVar4 = puVar1, puVar4 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar4;
    piVar2 = (int *)puVar4[2];
    if ((piVar2[7] != 0) && (FUN_004ab27f(puVar4), piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004ab191();
  uVar3 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = uVar3;
  return;
}


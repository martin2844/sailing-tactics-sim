
void FUN_0047cf59(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004879fc;
  piVar1 = (int *)extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  while (piVar4 = piVar1, piVar4 != (int *)0x0) {
    piVar1 = (int *)*piVar4;
    piVar2 = (int *)piVar4[2];
    if ((piVar2[7] != 0) && (FUN_00466b9f(extraout_ECX + 1,piVar4), piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 4))(1);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00466ab1();
  uVar3 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00485d04;
  *unaff_FS_OFFSET = uVar3;
  return;
}


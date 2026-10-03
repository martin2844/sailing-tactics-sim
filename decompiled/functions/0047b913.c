
void thunk_FUN_0047b67a(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004872d4;
  puVar1 = (undefined4 *)extraout_ECX[0x411];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  if (extraout_ECX[0x41b] != 0) {
    iVar3 = -(uint)(*(int *)(extraout_ECX[0x41b] + 0xc) != 0);
    *(int *)(unaff_EBP + -0x14) = iVar3;
    if (iVar3 != 0) {
      do {
        FUN_004670f0((void *)extraout_ECX[0x41b],(int *)(unaff_EBP + -0x14),
                     (int *)(unaff_EBP + -0x1c),(int *)(unaff_EBP + -0x10));
        if (*(undefined4 **)(unaff_EBP + -0x10) != extraout_ECX + 0x412) {
          FUN_0046b541(*(undefined **)(unaff_EBP + -0x10));
        }
      } while (*(int *)(unaff_EBP + -0x14) != 0);
    }
    if ((int *)extraout_ECX[0x41b] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x41b] + 4))(1);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0047be89(extraout_ECX + 0x41c);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004865ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}


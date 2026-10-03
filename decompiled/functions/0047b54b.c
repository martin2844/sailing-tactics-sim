
void FUN_0047b54b(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004872cc;
  piVar1 = (int *)extraout_ECX[0x33];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x60))();
    if ((int *)extraout_ECX[0x33] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x33] + 4))(1);
    }
  }
  if ((HHOOK)extraout_ECX[0xc] != (HHOOK)0x0) {
    UnhookWindowsHookEx((HHOOK)extraout_ECX[0xc]);
  }
  if ((HHOOK)extraout_ECX[0xb] != (HHOOK)0x0) {
    UnhookWindowsHookEx((HHOOK)extraout_ECX[0xb]);
  }
  if ((undefined *)extraout_ECX[3] != (undefined *)0x0) {
    FUN_00457710((undefined *)extraout_ECX[3]);
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004865ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}


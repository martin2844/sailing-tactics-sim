
undefined4 FUN_0045fe30(void)

{
  int *piVar1;
  uint uVar2;
  
  if (DAT_004aec4c == 0) {
    PTR_DAT_004a2ff0 = *(undefined **)PTR_PTR_004a3020;
    PTR_DAT_004a2ff4 = *(undefined **)(PTR_PTR_004a3020 + 4);
    PTR_DAT_004a2ff8 = *(undefined **)(PTR_PTR_004a3020 + 8);
    PTR_PTR_004a3020 = (undefined *)&PTR_DAT_004a2ff0;
    FUN_004600b0((int)DAT_004aed50);
    FUN_00457710((undefined *)DAT_004aed50);
    DAT_004aed50 = (int *)0x0;
    return 0;
  }
  piVar1 = FUN_00458640(1,0x30);
  if (piVar1 == (int *)0x0) {
    return 1;
  }
  uVar2 = FUN_0045ff20((int)piVar1);
  if (uVar2 != 0) {
    FUN_004600b0((int)piVar1);
    FUN_00457710((undefined *)piVar1);
    return 1;
  }
  *piVar1 = *(int *)PTR_PTR_004a3020;
  piVar1[1] = *(int *)(PTR_PTR_004a3020 + 4);
  piVar1[2] = *(int *)(PTR_PTR_004a3020 + 8);
  PTR_PTR_004a3020 = (undefined *)piVar1;
  FUN_004600b0((int)DAT_004aed50);
  FUN_00457710((undefined *)DAT_004aed50);
  DAT_004aed50 = piVar1;
  return 0;
}


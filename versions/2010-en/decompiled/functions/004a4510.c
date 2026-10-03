
undefined4 FUN_004a4510(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (DAT_005387a4 == 0) {
    PTR_DAT_004f11b0 = *(undefined **)PTR_PTR_004f11e0;
    PTR_DAT_004f11b4 = *(undefined **)(PTR_PTR_004f11e0 + 4);
    PTR_DAT_004f11b8 = *(undefined **)(PTR_PTR_004f11e0 + 8);
    PTR_PTR_004f11e0 = (undefined *)&PTR_DAT_004f11b0;
    FUN_004a4790(DAT_005388a8);
    FUN_0049bfd0(DAT_005388a8);
    DAT_005388a8 = (undefined4 *)0x0;
    return 0;
  }
  puVar1 = (undefined4 *)FUN_0049cf00(1,0x30);
  if (puVar1 == (undefined4 *)0x0) {
    return 1;
  }
  iVar2 = FUN_004a4600(puVar1);
  if (iVar2 != 0) {
    FUN_004a4790(puVar1);
    FUN_0049bfd0(puVar1);
    return 1;
  }
  *puVar1 = *(undefined4 *)PTR_PTR_004f11e0;
  puVar1[1] = *(undefined4 *)(PTR_PTR_004f11e0 + 4);
  puVar1[2] = *(undefined4 *)(PTR_PTR_004f11e0 + 8);
  PTR_PTR_004f11e0 = (undefined *)puVar1;
  FUN_004a4790(DAT_005388a8);
  FUN_0049bfd0(DAT_005388a8);
  DAT_005388a8 = puVar1;
  return 0;
}



undefined4 FUN_004a3ba0(void)

{
  undefined *puVar1;
  int iVar2;
  
  if (DAT_005387ac == 0) {
    PTR_PTR_004edfec = (undefined *)&PTR_DAT_004edf40;
    FUN_004a3fd0(DAT_00538898);
    FUN_0049bfd0(DAT_00538898);
    DAT_00538898 = (undefined *)0x0;
    return 0;
  }
  puVar1 = (undefined *)FUN_0049cf00(1,0xac);
  if (puVar1 == (undefined *)0x0) {
    return 1;
  }
  iVar2 = FUN_004a3c50(puVar1);
  if (iVar2 != 0) {
    FUN_004a3fd0(puVar1);
    FUN_0049bfd0(puVar1);
    return 1;
  }
  PTR_PTR_004edfec = puVar1;
  FUN_004a3fd0(DAT_00538898);
  FUN_0049bfd0(DAT_00538898);
  DAT_00538898 = puVar1;
  return 0;
}



undefined4 FUN_0045f4c0(void)

{
  int *piVar1;
  uint uVar2;
  
  if (DAT_004aec54 == 0) {
    PTR_PTR_0049fe2c = (undefined *)&PTR_DAT_0049fd80;
    FUN_0045f8f0(DAT_004aed40);
    FUN_00457710((undefined *)DAT_004aed40);
    DAT_004aed40 = (int *)0x0;
    return 0;
  }
  piVar1 = FUN_00458640(1,0xac);
  if (piVar1 == (int *)0x0) {
    return 1;
  }
  uVar2 = FUN_0045f570((char *)piVar1);
  if (uVar2 != 0) {
    FUN_0045f8f0(piVar1);
    FUN_00457710((undefined *)piVar1);
    return 1;
  }
  PTR_PTR_0049fe2c = (undefined *)piVar1;
  FUN_0045f8f0(DAT_004aed40);
  FUN_00457710((undefined *)DAT_004aed40);
  DAT_004aed40 = piVar1;
  return 0;
}


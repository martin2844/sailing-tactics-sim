
void FUN_0042e080(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_004a9450;
  do {
    iVar1 = FUN_00415a20(100);
    *piVar2 = iVar1;
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x4a9904);
  return;
}


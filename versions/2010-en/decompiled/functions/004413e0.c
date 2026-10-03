
void FUN_004413e0(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_00512d70;
  do {
    iVar1 = FUN_0041e000(100);
    *piVar2 = iVar1;
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x513474);
  return;
}


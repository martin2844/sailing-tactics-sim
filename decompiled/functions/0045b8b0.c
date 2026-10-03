
int FUN_0045b8b0(int *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    FUN_00459f50();
    return 1;
  }
  if (DAT_004aec28 != (FARPROC)0x0) {
    bVar2 = FUN_0045df80(DAT_004aec28);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      iVar3 = (*DAT_004aec28)(param_1);
      return iVar3;
    }
  }
  return 0;
}


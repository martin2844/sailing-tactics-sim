
int __cdecl FUN_00440350(int param_1)

{
  int iVar1;
  
  FUN_0043fef0(param_1);
  iVar1 = *(int *)(&DAT_004fbf10 + param_1 * 4);
  if (iVar1 == 1) {
    DAT_005230b8 = 3;
  }
  if (iVar1 == 2) {
    DAT_005230b8 = 4;
  }
  if (iVar1 == 3) {
    DAT_005230b8 = 5;
  }
  if (iVar1 == 0) {
    DAT_005230b8 = 2;
  }
  if (((*(int *)(&DAT_004f8538 + param_1 * 4) == DAT_004da1e4) && (2 < iVar1)) &&
     (DAT_0053527c == 1)) {
    DAT_005230b8 = 5;
  }
  if (((*(int *)(&DAT_004f8538 + param_1 * 4) == DAT_004da1e4) && (DAT_00536408 == 0)) &&
     ((DAT_0053527c == 1 && (2 < iVar1)))) {
    DAT_005230b8 = 5;
  }
  return DAT_005230b8;
}


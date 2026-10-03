
undefined4 __cdecl FUN_0042d0c0(int param_1)

{
  int iVar1;
  
  FUN_0042cf70(param_1);
  iVar1 = *(int *)(&DAT_004a6ba0 + param_1 * 4);
  if (iVar1 == 1) {
    DAT_004aa7e0 = 3;
  }
  if (iVar1 == 2) {
    DAT_004aa7e0 = 4;
  }
  if (iVar1 == 3) {
    DAT_004aa7e0 = 5;
  }
  if (iVar1 == 0) {
    DAT_004aa7e0 = 2;
  }
  return DAT_004aa7e0;
}


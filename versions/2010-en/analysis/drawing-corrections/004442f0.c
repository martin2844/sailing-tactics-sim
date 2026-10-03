
void FUN_004442f0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int local_8 [2];
  
  if ((-1 < param_4) && (param_4 < 0x169)) {
    iVar1 = (&DAT_004f85c8)[param_4];
    iVar2 = (&DAT_004f1740)[param_4];
    FUN_004b4d9d(param_1,local_8,param_2,param_3);
    CDC::LineTo(param_1,iVar1 / param_5 + param_2,param_3 - iVar2 / param_5);
  }
  return;
}


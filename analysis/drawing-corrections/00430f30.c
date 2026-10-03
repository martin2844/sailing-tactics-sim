
void __cdecl FUN_00430f30(CDC *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int local_8 [2];
  
  iVar1 = (&DAT_004a54a0)[param_4];
  iVar2 = (&DAT_004a3450)[param_4];
  FUN_004706bd(param_1,local_8,param_2,param_3);
  CDC::LineTo(param_1,iVar1 / param_5 + param_2,param_3 - iVar2 / param_5);
  return;
}


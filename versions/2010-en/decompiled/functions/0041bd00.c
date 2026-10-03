
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Tact2010CString * __cdecl FUN_0041bd00(Tact2010CString *param_1,double param_2)

{
  double dVar1;
  Tact2010CString *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString local_70;
  Tact2010CString local_6c;
  Tact2010CString local_68;
  Tact2010CString local_64;
  undefined4 local_60;
  char local_5c [40];
  char local_34 [40];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c2dff;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_60 = 0;
  FUN_004b045a(&local_68);
  local_4 = 1;
  FUN_004b045a(&local_6c);
  local_4._0_1_ = 2;
  FUN_004b045a(&local_70);
  local_4._0_1_ = 3;
  local_64.data = (char *)(longlong)param_2;
  dVar1 = (param_2 - (double)(int)local_64.data) * _DAT_004cc580;
  FUN_0049b9a0(local_64.data,local_5c,10);
  FUN_004b06ed(&local_68,local_5c);
  FUN_0049b9a0((int)(longlong)dVar1,local_34,10);
  FUN_004b06ed(&local_6c,local_34);
  pTVar2 = FUN_004b07bb(&local_64,&local_68,(char *)&DAT_004dd054);
  local_4._0_1_ = 4;
  pTVar2 = FUN_004b0755((Tact2010CString *)&param_2,pTVar2,&local_6c);
  local_4._0_1_ = 5;
  FUN_004b069e(&local_70,pTVar2);
  local_4._0_1_ = 4;
  FUN_004b05a5((Tact2010CString *)&param_2);
  local_4._0_1_ = 3;
  FUN_004b05a5(&local_64);
  FUN_004b046a(param_1,&local_70);
  local_60 = 1;
  local_4._0_1_ = 2;
  FUN_004b05a5(&local_70);
  local_4._0_1_ = 1;
  FUN_004b05a5(&local_6c);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b05a5(&local_68);
  *unaff_FS_OFFSET = local_c;
  return param_1;
}


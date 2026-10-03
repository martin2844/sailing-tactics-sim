
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TactCString * __cdecl FUN_00413d90(TactCString *param_1,double param_2)

{
  double dVar1;
  TactCString *pTVar2;
  undefined4 *unaff_FS_OFFSET;
  int local_70;
  TactCString local_6c;
  TactCString local_68;
  TactCString local_64;
  undefined4 local_60;
  char local_5c [40];
  char local_34 [40];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047e0ef;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_60 = 0;
  FUN_0046bd7a(&local_68);
  local_4 = 1;
  FUN_0046bd7a(&local_6c);
  local_4._0_1_ = 2;
  FUN_0046bd7a(&local_70);
  local_4._0_1_ = 3;
  local_64.data = (char *)(longlong)param_2;
  dVar1 = (param_2 - (double)(int)local_64.data) * _DAT_00484d58;
  FUN_004570e0((uint)local_64.data,local_5c,10);
  FUN_0046c00d(&local_68,local_5c);
  FUN_004570e0((uint)(longlong)dVar1,local_34,10);
  FUN_0046c00d(&local_6c,local_34);
  pTVar2 = FUN_0046c0db(&local_64,&local_68,(char *)&DAT_0049300c);
  local_4._0_1_ = 4;
  pTVar2 = FUN_0046c075((TactCString *)&param_2,pTVar2,&local_6c);
  local_4._0_1_ = 5;
  FUN_0046bfbe(&local_70,(int *)pTVar2);
  local_4._0_1_ = 4;
  FUN_0046bec5((int *)&param_2);
  local_4._0_1_ = 3;
  FUN_0046bec5((int *)&local_64);
  FUN_0046bd8a(param_1,&local_70);
  local_60 = 1;
  local_4._0_1_ = 2;
  FUN_0046bec5(&local_70);
  local_4._0_1_ = 1;
  FUN_0046bec5((int *)&local_6c);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5((int *)&local_68);
  *unaff_FS_OFFSET = local_c;
  return param_1;
}


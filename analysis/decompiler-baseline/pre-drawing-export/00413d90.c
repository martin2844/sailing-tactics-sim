
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * __cdecl FUN_00413d90(void *param_1)

{
  double dVar1;
  int *piVar2;
  undefined4 *unaff_FS_OFFSET;
  double in_stack_00000008;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64 [2];
  char local_5c [40];
  char local_34 [40];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047e0ef;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_64[1] = 0;
  FUN_0046bd7a(&local_68);
  local_4 = 1;
  FUN_0046bd7a(&local_6c);
  local_4._0_1_ = 2;
  FUN_0046bd7a(&local_70);
  local_4._0_1_ = 3;
  local_64[0] = (uint)(longlong)in_stack_00000008;
  dVar1 = (in_stack_00000008 - (double)(int)local_64[0]) * _DAT_00484d58;
  FUN_004570e0(local_64[0],local_5c,10);
  FUN_0046c00d(&local_68,local_5c);
  FUN_004570e0((uint)(longlong)dVar1,local_34,10);
  FUN_0046c00d(&local_6c,local_34);
  FUN_0046c0db();
  local_4._0_1_ = 4;
  piVar2 = (int *)FUN_0046c075();
  local_4._0_1_ = 5;
  FUN_0046bfbe(&local_70,piVar2);
  local_4._0_1_ = 4;
  FUN_0046bec5((int *)&stack0x00000008);
  local_4._0_1_ = 3;
  FUN_0046bec5((int *)local_64);
  FUN_0046bd8a(param_1,&local_70);
  local_64[1] = 1;
  local_4._0_1_ = 2;
  FUN_0046bec5(&local_70);
  local_4._0_1_ = 1;
  FUN_0046bec5(&local_6c);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5(&local_68);
  *unaff_FS_OFFSET = local_c;
  return param_1;
}


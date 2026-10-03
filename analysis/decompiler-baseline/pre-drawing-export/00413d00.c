
void * __cdecl FUN_00413d00(void *param_1,uint param_2)

{
  undefined4 *unaff_FS_OFFSET;
  int local_3c [2];
  char local_34 [40];
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047e09f;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_3c[1] = 0;
  FUN_0046bd7a(local_3c);
  local_4 = 1;
  FUN_004570e0(param_2,local_34,10);
  FUN_0046c00d(local_3c,local_34);
  FUN_0046bd8a(param_1,local_3c);
  local_3c[1] = 1;
  local_4 = local_4 & 0xffffff00;
  FUN_0046bec5(local_3c);
  *unaff_FS_OFFSET = local_c;
  return param_1;
}


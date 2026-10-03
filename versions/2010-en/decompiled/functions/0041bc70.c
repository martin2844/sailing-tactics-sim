
Tact2010CString * __cdecl FUN_0041bc70(Tact2010CString *param_1,int param_2)

{
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString local_3c;
  undefined4 local_38;
  char local_34 [40];
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c2daf;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_38 = 0;
  FUN_004b045a(&local_3c);
  local_4 = 1;
  FUN_0049b9a0(param_2,local_34,10);
  FUN_004b06ed(&local_3c,local_34);
  FUN_004b046a(param_1,&local_3c);
  local_38 = 1;
  local_4 = local_4 & 0xffffff00;
  FUN_004b05a5(&local_3c);
  *unaff_FS_OFFSET = local_c;
  return param_1;
}


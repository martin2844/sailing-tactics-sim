
void __fastcall FUN_00401260(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  pcStack_8 = FUN_0047d0c8;
  *unaff_FS_OFFSET = &local_c;
  *param_1 = &PTR_FUN_004822e0;
  local_4 = 0;
  CStatusBar::~CStatusBar((CStatusBar *)(param_1 + 0x2f));
  local_4 = 0xffffffff;
  FUN_00476651();
  *unaff_FS_OFFSET = local_c;
  return;
}


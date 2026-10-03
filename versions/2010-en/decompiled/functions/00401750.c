
void FUN_00401750(void)

{
  undefined4 *unaff_FS_OFFSET;
  CDialog local_68 [92];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c17e8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_00401720();
  local_4 = 0;
  FUN_004abf46();
  local_4 = 0xffffffff;
  CDialog::~CDialog(local_68);
  *unaff_FS_OFFSET = local_c;
  return;
}


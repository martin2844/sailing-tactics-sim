
void __fastcall FUN_004901d0(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  CDialog local_68 [92];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c6258;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_00401000(0);
  local_4 = 0;
  FUN_004abf46();
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)(param_1 + 0x1c),(RECT *)0x0,1);
  local_4 = 0xffffffff;
  CDialog::~CDialog(local_68);
  *unaff_FS_OFFSET = local_c;
  return;
}


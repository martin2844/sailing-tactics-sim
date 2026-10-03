
void __fastcall FUN_00407df0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0047d698;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  *param_1 = &PTR_FUN_00487254;
  local_4 = 0;
  FUN_00470a84((int)param_1);
  *param_1 = &PTR_FUN_00485d04;
  *unaff_FS_OFFSET = local_c;
  return;
}


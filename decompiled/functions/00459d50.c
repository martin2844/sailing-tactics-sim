
void __cdecl FUN_00459d50(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00488d60;
  pcStack_10 = FUN_0045b408;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    FUN_004569d0(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


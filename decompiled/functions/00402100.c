
undefined4 * FUN_00402100(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d14a;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  puVar1 = (undefined4 *)FUN_0046b505(0x40);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = FUN_00402180(puVar1);
    *unaff_FS_OFFSET = local_c;
    return puVar1;
  }
  *unaff_FS_OFFSET = local_c;
  return (undefined4 *)0x0;
}


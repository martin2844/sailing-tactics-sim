
undefined4 * FUN_004c0821(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_004afbe5(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_004cf0ec;
    puVar1[1] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}



undefined4 * FUN_004bfbc1(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_004afbe5(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_004ceef4;
    puVar1[1] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


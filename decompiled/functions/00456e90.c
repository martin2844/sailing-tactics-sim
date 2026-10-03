
void FUN_00456e90(void)

{
  DAT_004aff08 = (undefined4 *)FUN_00457640(0x80);
  if (DAT_004aff08 == (undefined4 *)0x0) {
    __amsg_exit(0x18);
  }
  *DAT_004aff08 = 0;
  DAT_004aff04 = DAT_004aff08;
  return;
}


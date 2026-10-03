
void FUN_0049b080(code *UNRECOVERED_JUMPTABLE)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x0049b0ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


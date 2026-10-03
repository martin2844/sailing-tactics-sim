
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_00459fa0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  *(undefined **)(*(int *)(unaff_EBP + -0x18) + -4) = &UNK_00459fb6;
  _abort();
}


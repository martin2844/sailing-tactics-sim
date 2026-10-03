
void FUN_004b8940(void)

{
  int iVar1;
  int extraout_ECX;
  int *piVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  if (*(int *)(extraout_ECX + 0x10) == 0) {
    FUN_004b6cec(0xf104,0,0xffffffff);
  }
  else {
    piVar2 = *(int **)(*(int *)(extraout_ECX + 8) + 8);
    if (1 < *(int *)(extraout_ECX + 0x10)) {
      FUN_004abe98(0x7801,0);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      *(undefined ***)(unaff_EBP + -0x70) = &PTR_FUN_004cf70c;
      *(int *)(unaff_EBP + -0x14) = extraout_ECX + 4;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar1 = FUN_004abf46();
      if (iVar1 != 1) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined ***)(unaff_EBP + -0x70) = &PTR_FUN_004cf70c;
        CDialog::~CDialog((CDialog *)(unaff_EBP + -0x70));
        goto LAB_004b89c5;
      }
      piVar2 = *(int **)(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined ***)(unaff_EBP + -0x70) = &PTR_FUN_004cf70c;
      CDialog::~CDialog((CDialog *)(unaff_EBP + -0x70));
    }
    (**(code **)(*piVar2 + 0x88))(0,1);
  }
LAB_004b89c5:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


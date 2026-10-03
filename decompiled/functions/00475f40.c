
void FUN_00475f40(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_004708da();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = (**(code **)(iVar1 + 0xd0))();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(iVar1 + 0xe8))();
    if (iVar2 != 0) {
      (**(code **)(iVar1 + 0xe0))(unaff_EBP + -0x60);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CPaintDC::~CPaintDC((CPaintDC *)(unaff_EBP + -0x60));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


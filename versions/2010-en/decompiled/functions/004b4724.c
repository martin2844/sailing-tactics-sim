
undefined4 FUN_004b4724(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x1c) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    uVar2 = FUN_004afbd1(FUN_004b56c3);
    iVar3 = FUN_004afbe5(0x44);
    *(int *)(unaff_EBP + 8) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_004b1c11(&PTR_DAT_004ceb28,4,2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(pAVar1 + 0x1c) = uVar4;
    FUN_004afbd1(uVar2);
  }
  uVar2 = *(undefined4 *)(pAVar1 + 0x1c);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}


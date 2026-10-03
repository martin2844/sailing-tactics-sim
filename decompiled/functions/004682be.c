
undefined4 FUN_004682be(void)

{
  CWinThread *pCVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + 0x14);
  pCVar1 = AfxGetThread();
  uVar2 = (**(code **)(*(int *)pCVar1 + 0x74))(*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0x3c)
  ;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0046cfeb(*(int **)(unaff_EBP + -0x20));
  return 0x4682aa;
}



undefined4 FUN_004ac5e7(void)

{
  CWinThread *pCVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  pCVar1 = AfxGetThread();
  uVar2 = (**(code **)(*(int *)pCVar1 + 0x74))
                    (*(undefined4 *)(unaff_EBP + 0x10),*(int *)(unaff_EBP + -0x14) + 0x34);
  *(undefined4 *)(unaff_EBP + 8) = uVar2;
  FUN_004b16cb();
  return 0x4ac60e;
}



undefined4 FUN_0045622d(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x24) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    uVar2 = FUN_0046b4f1(FUN_00470fe3);
    iVar3 = FUN_0046b505(0x44);
    *(int *)(unaff_EBP + 8) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 == 0) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = FUN_0046d531();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(void **)(pAVar1 + 0x24) = pvVar4;
    FUN_0046b4f1(uVar2);
  }
  uVar2 = *(undefined4 *)(pAVar1 + 0x24);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}


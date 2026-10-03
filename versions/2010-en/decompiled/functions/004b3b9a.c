
int * FUN_004b3b9a(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  piVar2 = (int *)FUN_004afbe5(0x14);
  *(int **)(unaff_EBP + -0x10) = piVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_004b0a8b();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004b045a((Tact2010CString *)(piVar2 + 4));
    *piVar2 = (int)&PTR_FUN_004ce694;
  }
  iVar1 = *piVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar3 = (**(code **)(iVar1 + 0x28))
                    (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                     *(undefined4 *)(unaff_EBP + 0x10));
  if (iVar3 == 0) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(iVar1 + 4))(1);
    }
    piVar2 = (int *)0x0;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar2;
}



undefined4 FUN_004b62d4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  LPCSTR lpString1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  
  FUN_0049bcd8();
  **(undefined4 **)(unaff_EBP + 0xc) = 0;
  iVar3 = *extraout_ECX;
  iVar1 = (**(code **)(iVar3 + 0x5c))();
  *(int *)(unaff_EBP + -0x14) = iVar1;
  do {
    if (iVar1 == 0) {
      FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar3 = (**(code **)(iVar3 + 0x6c))(unaff_EBP + -0x10,4);
      if ((((iVar3 == 0) || (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) == 0)) ||
          (lpString1 = (LPCSTR)FUN_0049d2c0(*(undefined4 *)(unaff_EBP + 8),0x2e),
          lpString1 == (LPCSTR)0x0)) ||
         (iVar3 = lstrcmpiA(lpString1,*(LPCSTR *)(unaff_EBP + -0x10)), iVar3 != 0)) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
        uVar4 = 3;
      }
      else {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
        uVar4 = 4;
      }
LAB_004b6376:
      *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
      return uVar4;
    }
    iVar1 = (**(code **)(iVar3 + 0x60))(unaff_EBP + -0x14);
    iVar2 = FUN_004b149f(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(unaff_EBP + 8));
    if (iVar2 != 0) {
      uVar4 = 5;
      **(int **)(unaff_EBP + 0xc) = iVar1;
      goto LAB_004b6376;
    }
    iVar1 = *(int *)(unaff_EBP + -0x14);
  } while( true );
}


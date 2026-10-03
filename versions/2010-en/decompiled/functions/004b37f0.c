
void FUN_004b37f0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  iVar4 = *(int *)(unaff_EBP + 0x14);
  *(int *)(unaff_EBP + -0x10) = iVar4;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + 0x14));
  piVar1 = *(int **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    iVar2 = FUN_004b1618(&PTR_s_CUserException_004ceb10);
    if (iVar2 != 0) goto LAB_004b3943;
    iVar2 = FUN_004b1618(&PTR_s_CArchiveException_004cf8d0);
    if (iVar2 == 0) {
      iVar2 = FUN_004b1618(&PTR_s_CFileException_004cf8a8);
      if (iVar2 != 0) {
        if (*(int *)(piVar1[4] + -8) == 0) {
          FUN_004b06ed((Tact2010CString *)(piVar1 + 4),*(char **)(unaff_EBP + 8));
        }
        uVar3 = FUN_004b0956(0xff);
        iVar2 = (**(code **)(*piVar1 + 0x14))(uVar3,0x100,unaff_EBP + -0x10);
        if (((iVar2 == 0) && (iVar2 = piVar1[2], iVar2 != 1)) && (1 < iVar2)) {
          if (iVar2 < 4) {
            iVar4 = 0xf121;
          }
          else if (iVar2 == 5) {
            iVar4 = (*(int *)(unaff_EBP + 0x10) != 0) + 0xf123;
          }
          else if (iVar2 == 0xd) {
            iVar4 = 0xf122;
          }
        }
        FUN_004b09a5(0xffffffff);
      }
    }
    else {
      iVar2 = piVar1[2];
      if ((iVar2 == 3) || ((4 < iVar2 && (iVar2 < 8)))) {
        iVar4 = 0xf120;
      }
    }
  }
  if (*(int *)(*(int *)(unaff_EBP + 0x14) + -8) == 0) {
    if (DAT_005381f8 == 0) {
      lstrcpynA((LPSTR)(unaff_EBP + -0x114),*(LPCSTR *)(unaff_EBP + 8),0x104);
    }
    else {
      FUN_004b1562(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x114,0x104);
    }
    FUN_004b8baa(unaff_EBP + 0x14,iVar4,unaff_EBP + -0x114);
  }
  FUN_004b6ccb(*(undefined4 *)(unaff_EBP + 0x14),0x30,*(undefined4 *)(unaff_EBP + -0x10));
LAB_004b3943:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0x14));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


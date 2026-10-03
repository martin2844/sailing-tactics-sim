
undefined4 FUN_004b11b6(void)

{
  LPCSTR pszPath;
  DWORD_PTR DVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  pszPath = *(LPCSTR *)(unaff_EBP + 0xc);
  **(undefined1 **)(unaff_EBP + 0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DVar1 = SHGetFileInfoA(pszPath,0,(SHFILEINFOA *)(unaff_EBP + -0x174),0x160,0x800);
  if ((DVar1 != 0) && ((*(byte *)(unaff_EBP + -0x16a) & 1) != 0)) {
    iVar2 = FUN_004b0f8d(&DAT_004ce9f8);
    if (-1 < iVar2) {
      iVar2 = (**(code **)**(undefined4 **)(unaff_EBP + 0xc))();
      if (-1 < iVar2) {
        if (pszPath == (LPCSTR)0x0) {
          uVar3 = 0;
        }
        else {
          iVar2 = lstrlenA(pszPath);
          FUN_0049c450();
          uVar3 = FUN_004b0a62(&stack0xfffffe80,pszPath,iVar2 + 1);
        }
        iVar2 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x14))
                          (*(int **)(unaff_EBP + -0x14),uVar3,0);
        if (-1 < iVar2) {
          if (*(int *)(unaff_EBP + 8) == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x1c);
          }
          iVar2 = (**(code **)(**(int **)(unaff_EBP + 0xc) + 0x4c))
                            (*(int **)(unaff_EBP + 0xc),uVar3,2);
          if (-1 < iVar2) {
            (**(code **)(**(int **)(unaff_EBP + 0xc) + 0xc))
                      (*(int **)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                       *(undefined4 *)(unaff_EBP + 0x14),0,0);
            (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));
            (**(code **)(**(int **)(unaff_EBP + 0xc) + 8))(*(int **)(unaff_EBP + 0xc));
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_004b0f7f();
            uVar3 = 1;
            goto LAB_004b12e9;
          }
        }
        (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));
      }
      (**(code **)(**(int **)(unaff_EBP + 0xc) + 8))(*(int **)(unaff_EBP + 0xc));
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b0f7f();
  uVar3 = 0;
LAB_004b12e9:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}


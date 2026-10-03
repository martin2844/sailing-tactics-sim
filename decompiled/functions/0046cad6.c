
undefined4 FUN_0046cad6(void)

{
  LPCSTR pszPath;
  DWORD_PTR DVar1;
  int iVar2;
  LPWSTR pWVar3;
  undefined4 uVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  pszPath = *(LPCSTR *)(unaff_EBP + 0xc);
  **(undefined1 **)(unaff_EBP + 0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DVar1 = SHGetFileInfoA(pszPath,0,(SHFILEINFOA *)(unaff_EBP + -0x174),0x160,0x800);
  if ((DVar1 != 0) && ((*(byte *)(unaff_EBP + -0x16a) & 1) != 0)) {
    iVar2 = FUN_0046c8ad(&DAT_00486d58,0,&DAT_00486d68,unaff_EBP + 0xc);
    if (-1 < iVar2) {
      iVar2 = (**(code **)**(undefined4 **)(unaff_EBP + 0xc))();
      if (-1 < iVar2) {
        if (pszPath == (LPCSTR)0x0) {
          pWVar3 = (LPWSTR)0x0;
        }
        else {
          iVar2 = lstrlenA(pszPath);
          FUN_00457b90();
          pWVar3 = FUN_0046c382((LPWSTR)&stack0xfffffe80,pszPath,iVar2 + 1);
        }
        iVar2 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x14))
                          (*(int **)(unaff_EBP + -0x14),pWVar3,0);
        if (-1 < iVar2) {
          if (*(int *)(unaff_EBP + 8) == 0) {
            uVar4 = 0;
          }
          else {
            uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x1c);
          }
          iVar2 = (**(code **)(**(int **)(unaff_EBP + 0xc) + 0x4c))
                            (*(int **)(unaff_EBP + 0xc),uVar4,2);
          if (-1 < iVar2) {
            (**(code **)(**(int **)(unaff_EBP + 0xc) + 0xc))
                      (*(int **)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                       *(undefined4 *)(unaff_EBP + 0x14),0,0);
            (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));
            (**(code **)(**(int **)(unaff_EBP + 0xc) + 8))(*(int **)(unaff_EBP + 0xc));
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_0046c89f((undefined4 *)(unaff_EBP + -0x10));
            uVar4 = 1;
            goto LAB_0046cc09;
          }
        }
        (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));
      }
      (**(code **)(**(int **)(unaff_EBP + 0xc) + 8))(*(int **)(unaff_EBP + 0xc));
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046c89f((undefined4 *)(unaff_EBP + -0x10));
  uVar4 = 0;
LAB_0046cc09:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}


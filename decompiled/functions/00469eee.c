
undefined4 FUN_00469eee(void)

{
  HWND hWnd;
  void *this;
  void *this_00;
  HWND pHVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  this = (void *)FUN_0046805c();
  if (this != (void *)0x0) {
    hWnd = *(HWND *)(unaff_EBP + 8);
    this_00 = (void *)FUN_0046702b(this,(uint)hWnd);
    if (this_00 != (void *)0x0) {
      uVar3 = FUN_00469ec1(this_00,*(undefined4 *)(unaff_EBP + 0xc));
      goto LAB_00469f82;
    }
    pHVar1 = GetParent(hWnd);
    iVar2 = FUN_0046702b(this,(uint)pHVar1);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x34) != 0)) {
      iVar2 = FUN_0046702b((void *)(*(int *)(iVar2 + 0x34) + 0x20),(uint)hWnd);
      if (iVar2 != 0) {
        FUN_00467da9((void *)(unaff_EBP + -0x48),hWnd);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(int *)(unaff_EBP + -0x10) = iVar2;
        uVar3 = FUN_00469ec1((void *)(unaff_EBP + -0x48),*(undefined4 *)(unaff_EBP + 0xc));
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        CWnd::~CWnd((CWnd *)(unaff_EBP + -0x48));
        goto LAB_00469f82;
      }
    }
  }
  uVar3 = 0;
LAB_00469f82:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}


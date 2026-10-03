
void FUN_0046f110(void)

{
  int *this;
  int iVar1;
  UINT UVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  UVar2 = *(UINT *)(unaff_EBP + 0x14);
  *(UINT *)(unaff_EBP + -0x10) = UVar2;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + 0x14));
  this = *(int **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (this != (int *)0x0) {
    iVar1 = FUN_0046cf38(this,0x486e70);
    if (iVar1 != 0) goto LAB_0046f263;
    iVar1 = FUN_0046cf38(this,0x487c30);
    if (iVar1 == 0) {
      iVar1 = FUN_0046cf38(this,0x487c08);
      if (iVar1 != 0) {
        if (*(int *)(this[4] + -8) == 0) {
          FUN_0046c00d(this + 4,*(LPCSTR *)(unaff_EBP + 8));
        }
        iVar1 = FUN_0046c276((void *)(unaff_EBP + 0x14),0xff);
        iVar1 = (**(code **)(*this + 0x14))(iVar1,0x100,unaff_EBP + -0x10);
        if (((iVar1 == 0) && (iVar1 = this[2], iVar1 != 1)) && (1 < iVar1)) {
          if (iVar1 < 4) {
            UVar2 = 0xf121;
          }
          else if (iVar1 == 5) {
            UVar2 = (*(int *)(unaff_EBP + 0x10) != 0) + 0xf123;
          }
          else if (iVar1 == 0xd) {
            UVar2 = 0xf122;
          }
        }
        FUN_0046c2c5((void *)(unaff_EBP + 0x14),-1);
      }
    }
    else {
      iVar1 = this[2];
      if ((iVar1 == 3) || ((4 < iVar1 && (iVar1 < 8)))) {
        UVar2 = 0xf120;
      }
    }
  }
  if (*(int *)(*(int *)(unaff_EBP + 0x14) + -8) == 0) {
    if (DAT_004ae6a0 == 0) {
      lstrcpynA((LPSTR)(unaff_EBP + -0x114),*(LPCSTR *)(unaff_EBP + 8),0x104);
    }
    else {
      FUN_0046ce82(*(byte **)(unaff_EBP + 8),(LPSTR)(unaff_EBP + -0x114),0x104);
    }
    FUN_004744ca((int *)(unaff_EBP + 0x14),UVar2);
  }
  FUN_004725eb(*(undefined4 *)(unaff_EBP + 0x14),0x30,*(undefined4 *)(unaff_EBP + -0x10));
LAB_0046f263:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + 0x14));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


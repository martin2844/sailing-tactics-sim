
void FUN_004bceb6(void)

{
  RECT *lprcSrc;
  HRGN pHVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_0049b055();
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_004cfc2c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0049b055();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_004cfc2c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0049b055();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_FUN_004cfc2c;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pHVar1 = CreateRectRgnIndirect(*(RECT **)(unaff_EBP + 8));
  FUN_004b510d(pHVar1);
  CopyRect((LPRECT)(unaff_EBP + -0x44),*(RECT **)(unaff_EBP + 8));
  InflateRect((LPRECT)(unaff_EBP + -0x44),-*(int *)(unaff_EBP + 0xc),-*(int *)(unaff_EBP + 0x10));
  IntersectRect((LPRECT)(unaff_EBP + -0x44),(RECT *)(unaff_EBP + -0x44),*(RECT **)(unaff_EBP + 8));
  pHVar1 = CreateRectRgnIndirect((RECT *)(unaff_EBP + -0x44));
  FUN_004b510d(pHVar1);
  pHVar1 = CreateRectRgn(0,0,0,0);
  FUN_004b510d(pHVar1);
  CombineRgn(*(HRGN *)(unaff_EBP + -0x30),
             (HRGN)(-(uint)(unaff_EBP != 0x1c) & *(uint *)(unaff_EBP + -0x18)),
             (HRGN)(-(uint)(unaff_EBP != 0x14) & *(uint *)(unaff_EBP + -0x10)),3);
  if (*(int *)(unaff_EBP + 0x20) == 0) {
    uVar2 = FUN_004bce43();
    *(undefined4 *)(unaff_EBP + 0x20) = uVar2;
  }
  if (*(int *)(unaff_EBP + 0x24) == 0) {
    *(undefined4 *)(unaff_EBP + 0x24) = *(undefined4 *)(unaff_EBP + 0x20);
  }
  FUN_0049b055();
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_004cfc2c;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0049b055();
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_004cfc2c;
  lprcSrc = *(RECT **)(unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (lprcSrc != (RECT *)0x0) {
    pHVar1 = CreateRectRgn(0,0,0,0);
    FUN_004b510d(pHVar1);
    SetRectRgn(*(HRGN *)(unaff_EBP + -0x18),lprcSrc->left,lprcSrc->top,lprcSrc->right,
               lprcSrc->bottom);
    CopyRect((LPRECT)(unaff_EBP + -0x44),lprcSrc);
    InflateRect((LPRECT)(unaff_EBP + -0x44),-*(int *)(unaff_EBP + 0x18),-*(int *)(unaff_EBP + 0x1c))
    ;
    IntersectRect((LPRECT)(unaff_EBP + -0x44),(RECT *)(unaff_EBP + -0x44),lprcSrc);
    SetRectRgn(*(HRGN *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
               *(int *)(unaff_EBP + -0x3c),*(int *)(unaff_EBP + -0x38));
    CombineRgn(*(HRGN *)(unaff_EBP + -0x20),
               (HRGN)(-(uint)(unaff_EBP != 0x1c) & *(uint *)(unaff_EBP + -0x18)),
               (HRGN)(-(uint)(unaff_EBP != 0x14) & *(uint *)(unaff_EBP + -0x10)),3);
    if (*(int *)(*(int *)(unaff_EBP + 0x20) + 4) == *(int *)(*(int *)(unaff_EBP + 0x24) + 4)) {
      pHVar1 = CreateRectRgn(0,0,0,0);
      FUN_004b510d(pHVar1);
      CombineRgn(*(HRGN *)(unaff_EBP + -0x28),
                 (HRGN)(-(uint)(unaff_EBP != 0x24) & *(uint *)(unaff_EBP + -0x20)),
                 (HRGN)(-(uint)(unaff_EBP != 0x34) & *(uint *)(unaff_EBP + -0x30)),3);
    }
  }
  if ((*(int *)(*(int *)(unaff_EBP + 0x20) + 4) != *(int *)(*(int *)(unaff_EBP + 0x24) + 4)) &&
     (lprcSrc != (RECT *)0x0)) {
    FUN_004b4cb7(unaff_EBP + -0x24);
    (**(code **)(*extraout_ECX + 0x58))(unaff_EBP + -0x44);
    uVar2 = FUN_004b4941(*(undefined4 *)(unaff_EBP + 0x24));
    PatBlt((HDC)extraout_ECX[1],*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
           *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44),
           *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40),0x5a0049);
    FUN_004b4941(uVar2);
  }
  iVar3 = unaff_EBP + -0x2c;
  if (*(int *)(unaff_EBP + -0x28) == 0) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_004b4cb7(iVar3);
  (**(code **)(*extraout_ECX + 0x58))(unaff_EBP + -0x44);
  iVar3 = FUN_004b4941(*(undefined4 *)(unaff_EBP + 0x20));
  PatBlt((HDC)extraout_ECX[1],*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
         *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44),
         *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40),0x5a0049);
  if (iVar3 != 0) {
    FUN_004b4941(iVar3);
  }
  FUN_004b4cb7(0);
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_004ceef4;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_004b5164();
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_004ceef4;
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_004cd9a4;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_004b5164();
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_004cd9a4;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_FUN_004ceef4;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_004b5164();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_FUN_004cd9a4;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_004ceef4;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_004b5164();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_004cd9a4;
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_004ceef4;
  *(undefined4 *)(unaff_EBP + -4) = 9;
  FUN_004b5164();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


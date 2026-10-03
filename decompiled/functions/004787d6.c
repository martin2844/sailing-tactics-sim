
void FUN_004787d6(void)

{
  RECT *lprcSrc;
  HRGN pHVar1;
  undefined4 uVar2;
  int iVar3;
  int *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_00456965((undefined4 *)(unaff_EBP + -0x34));
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_00487f8c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00456965((undefined4 *)(unaff_EBP + -0x1c));
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00487f8c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00456965((undefined4 *)(unaff_EBP + -0x14));
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_FUN_00487f8c;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pHVar1 = CreateRectRgnIndirect(*(RECT **)(unaff_EBP + 8));
  FUN_00470a2d((void *)(unaff_EBP + -0x1c),(uint)pHVar1);
  CopyRect((LPRECT)(unaff_EBP + -0x44),*(RECT **)(unaff_EBP + 8));
  InflateRect((LPRECT)(unaff_EBP + -0x44),-*(int *)(unaff_EBP + 0xc),-*(int *)(unaff_EBP + 0x10));
  IntersectRect((LPRECT)(unaff_EBP + -0x44),(RECT *)(unaff_EBP + -0x44),*(RECT **)(unaff_EBP + 8));
  pHVar1 = CreateRectRgnIndirect((RECT *)(unaff_EBP + -0x44));
  FUN_00470a2d((void *)(unaff_EBP + -0x14),(uint)pHVar1);
  pHVar1 = CreateRectRgn(0,0,0,0);
  FUN_00470a2d((void *)(unaff_EBP + -0x34),(uint)pHVar1);
  CombineRgn(*(HRGN *)(unaff_EBP + -0x30),
             (HRGN)(-(uint)(unaff_EBP != 0x1c) & *(uint *)(unaff_EBP + -0x18)),
             (HRGN)(-(uint)(unaff_EBP != 0x14) & *(uint *)(unaff_EBP + -0x10)),3);
  if (*(int *)(unaff_EBP + 0x20) == 0) {
    uVar2 = FUN_00478763();
    *(undefined4 *)(unaff_EBP + 0x20) = uVar2;
  }
  if (*(int *)(unaff_EBP + 0x24) == 0) {
    *(undefined4 *)(unaff_EBP + 0x24) = *(undefined4 *)(unaff_EBP + 0x20);
  }
  FUN_00456965((undefined4 *)(unaff_EBP + -0x24));
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00487f8c;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00456965((undefined4 *)(unaff_EBP + -0x2c));
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_00487f8c;
  lprcSrc = *(RECT **)(unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (lprcSrc != (RECT *)0x0) {
    pHVar1 = CreateRectRgn(0,0,0,0);
    FUN_00470a2d((void *)(unaff_EBP + -0x24),(uint)pHVar1);
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
      FUN_00470a2d((void *)(unaff_EBP + -0x2c),(uint)pHVar1);
      CombineRgn(*(HRGN *)(unaff_EBP + -0x28),
                 (HRGN)(-(uint)(unaff_EBP != 0x24) & *(uint *)(unaff_EBP + -0x20)),
                 (HRGN)(-(uint)(unaff_EBP != 0x34) & *(uint *)(unaff_EBP + -0x30)),3);
    }
  }
  if ((*(int *)(*(int *)(unaff_EBP + 0x20) + 4) != *(int *)(*(int *)(unaff_EBP + 0x24) + 4)) &&
     (lprcSrc != (RECT *)0x0)) {
    FUN_004705d7(this,unaff_EBP + -0x24);
    (**(code **)(*this + 0x58))(unaff_EBP + -0x44);
    iVar3 = FUN_00470261(this,*(int *)(unaff_EBP + 0x24));
    PatBlt((HDC)this[1],*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
           *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44),
           *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40),0x5a0049);
    FUN_00470261(this,iVar3);
  }
  iVar3 = unaff_EBP + -0x2c;
  if (*(int *)(unaff_EBP + -0x28) == 0) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_004705d7(this,iVar3);
  (**(code **)(*this + 0x58))(unaff_EBP + -0x44);
  iVar3 = FUN_00470261(this,*(int *)(unaff_EBP + 0x20));
  PatBlt((HDC)this[1],*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
         *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44),
         *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40),0x5a0049);
  if (iVar3 != 0) {
    FUN_00470261(this,iVar3);
  }
  FUN_004705d7(this,0);
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_00487254;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_00470a84(unaff_EBP + -0x2c);
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00487254;
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_00485d04;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00470a84(unaff_EBP + -0x24);
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00485d04;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_FUN_00487254;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00470a84(unaff_EBP + -0x14);
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_FUN_00485d04;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00487254;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_00470a84(unaff_EBP + -0x1c);
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00485d04;
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_00487254;
  *(undefined4 *)(unaff_EBP + -4) = 9;
  FUN_00470a84(unaff_EBP + -0x34);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


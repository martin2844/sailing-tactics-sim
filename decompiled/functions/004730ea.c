
void __thiscall FUN_004730ea(void)

{
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_00470826();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  GetClientRect(*(HWND *)((int)this + 0x1c),(LPRECT)(unaff_EBP + -0x2c));
  GetWindowRect(*(HWND *)((int)this + 0x1c),(LPRECT)(unaff_EBP + -0x1c));
  ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(unaff_EBP + -0x1c));
  ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(unaff_EBP + -0x14));
  OffsetRect((LPRECT)(unaff_EBP + -0x2c),-*(int *)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x18));
  FUN_00470625((void *)(unaff_EBP + -0x40),(int *)(unaff_EBP + -0x2c));
  OffsetRect((LPRECT)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x18));
  FUN_00473572(this,(void *)(unaff_EBP + -0x40),(int *)(unaff_EBP + -0x1c));
  FUN_00470671((void *)(unaff_EBP + -0x40),(int *)(unaff_EBP + -0x1c));
  SendMessageA(*(HWND *)((int)this + 0x1c),0x14,*(WPARAM *)(unaff_EBP + -0x3c),0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470898();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


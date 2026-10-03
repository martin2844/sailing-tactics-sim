
/* Library Function - Single Match
    public: virtual __thiscall CStatusBar::~CStatusBar(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CStatusBar::~CStatusBar(CStatusBar *this)

{
  undefined4 *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = this_00;
  *this_00 = &PTR_FUN_004863fc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047a42c(this_00,0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004728f8();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* Library Function - Single Match
    public: virtual __thiscall CStatusBar::~CStatusBar(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CStatusBar::~CStatusBar(CStatusBar *this)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004ce09c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004beb0c(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b6fd8();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


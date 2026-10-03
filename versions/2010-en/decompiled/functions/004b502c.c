
/* Library Function - Single Match
    public: virtual __thiscall CPaintDC::~CPaintDC(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CPaintDC::~CPaintDC(CPaintDC *this)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cee44;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  EndPaint((HWND)extraout_ECX[4],(PAINTSTRUCT *)(extraout_ECX + 5));
  FUN_004b47e1();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b4812();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


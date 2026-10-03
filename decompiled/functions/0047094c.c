
/* Library Function - Single Match
    public: virtual __thiscall CPaintDC::~CPaintDC(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CPaintDC::~CPaintDC(CPaintDC *this)

{
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_FUN_004871a4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  EndPaint((HWND)extraout_ECX[4],(PAINTSTRUCT *)(extraout_ECX + 5));
  FUN_00470101(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470132();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* Library Function - Single Match
    public: virtual __thiscall CWnd::~CWnd(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CWnd::~CWnd(CWnd *this)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cd734;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((((extraout_ECX[7] != 0) && (extraout_ECX != (undefined4 *)&DAT_00537db8)) &&
      (extraout_ECX != (undefined4 *)&DAT_00537e78)) &&
     ((extraout_ECX != (undefined4 *)&DAT_00537df8 && (extraout_ECX != (undefined4 *)&DAT_00537e38))
     )) {
    FUN_004ad050();
  }
  if ((int *)extraout_ECX[0xd] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0xd] + 4))(1);
  }
  iVar1 = extraout_ECX[0xe];
  if ((iVar1 != 0) && (*(undefined4 **)(iVar1 + 0x24) == extraout_ECX)) {
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004af667();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


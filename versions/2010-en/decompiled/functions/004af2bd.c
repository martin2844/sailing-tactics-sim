
/* Library Function - Multiple Matches With Same Base Name
    int __stdcall _AfxRegisterWithIcon(struct tagWNDCLASSA *,char const *,unsigned int)
    int __stdcall _AfxRegisterWithIcon(struct tagWNDCLASSW *,wchar_t const *,unsigned int)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void AfxRegisterWithIcon(int param_1,undefined4 param_2,ushort param_3)

{
  int iVar1;
  HICON pHVar2;
  
  *(undefined4 *)(param_1 + 0x24) = param_2;
  iVar1 = FUN_004bfff8();
  pHVar2 = LoadIconA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)(uint)param_3);
  *(HICON *)(param_1 + 0x14) = pHVar2;
  if (pHVar2 == (HICON)0x0) {
    pHVar2 = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    *(HICON *)(param_1 + 0x14) = pHVar2;
  }
  FUN_004ad3d6(param_1);
  return;
}



/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall CMapPtrToPtr::RemoveAll(void)
    public: void __thiscall CMapPtrToWord::RemoveAll(void)
    public: void __thiscall CMapWordToOb::RemoveAll(void)
    public: void __thiscall CMapWordToPtr::RemoveAll(void)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __fastcall RemoveAll(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004afc21(*(int *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_004ab2f9();
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


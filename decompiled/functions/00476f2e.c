
/* Library Function - Multiple Matches With Same Base Name
    protected: char const * __thiscall CFrameWnd::GetIconWndClass(unsigned long,unsigned int)
    protected: wchar_t const * __thiscall CFrameWnd::GetIconWndClass(unsigned long,unsigned int)
   
   Library: Visual Studio 2003 Release */

LPSTR __thiscall GetIconWndClass(void *this,undefined4 param_1,ushort param_2)

{
  int iVar1;
  HICON pHVar2;
  BOOL BVar3;
  LPSTR pCVar4;
  undefined1 local_5c [32];
  undefined4 local_3c;
  LPCSTR local_34;
  tagWNDCLASSA local_2c;
  
  iVar1 = FUN_0047b918();
  pHVar2 = LoadIconA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)(uint)param_2);
  if (pHVar2 != (HICON)0x0) {
    _memset(local_5c,0,0x30);
    local_3c = param_1;
    (**(code **)(*(int *)this + 100))(local_5c);
    if (local_34 != (LPCSTR)0x0) {
      iVar1 = FUN_0047b918();
      BVar3 = GetClassInfoA(*(HINSTANCE *)(iVar1 + 8),local_34,&local_2c);
      if ((BVar3 != 0) && (local_2c.hIcon != pHVar2)) {
        pCVar4 = FUN_00468d9f(local_2c.style,local_2c.hCursor,local_2c.hbrBackground,pHVar2);
        return pCVar4;
      }
    }
  }
  return (LPSTR)0x0;
}


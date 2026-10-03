
/* Library Function - Single Match
    protected: long __thiscall CWnd::OnDisplayChange(unsigned int,long)
   
   Library: Visual Studio 1998 Release */

long __thiscall CWnd::OnDisplayChange(CWnd *this,uint param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  
  iVar1 = FUN_0047b918();
  if (*(CWnd **)(*(int *)(iVar1 + 4) + 0x1c) == this) {
    FUN_0046d70d(0x4ae638);
  }
  uVar2 = FUN_0046ad0b((int)this);
  if ((uVar2 & 0x40000000) == 0) {
    iVar1 = FUN_00467fec();
    FUN_0046996c(*(HWND *)(this + 0x1c),*(UINT *)(iVar1 + 4),*(WPARAM *)(iVar1 + 8),
                 *(LPARAM *)(iVar1 + 0xc),1,1);
  }
  lVar3 = FUN_00468021(this);
  return lVar3;
}


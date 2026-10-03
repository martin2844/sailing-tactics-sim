
/* Library Function - Single Match
    public: virtual void __thiscall CFrameWnd::OnUpdateFrameTitle(int)
   
   Library: Visual Studio 1998 Release */

void __thiscall CFrameWnd::OnUpdateFrameTitle(CFrameWnd *this,int param_1)

{
  uint uVar1;
  int iVar2;
  LPCSTR pCVar3;
  
  uVar1 = FUN_0046ad0b((int)this);
  if ((uVar1 & 0x8000) != 0) {
    if ((*(int **)(this + 0x68) != (int *)0x0) &&
       (iVar2 = (**(code **)(**(int **)(this + 0x68) + 0x70))(), iVar2 != 0)) {
      return;
    }
    iVar2 = (**(code **)(*(int *)this + 0xc4))();
    if ((param_1 == 0) || (iVar2 == 0)) {
      pCVar3 = (LPCSTR)0x0;
    }
    else {
      pCVar3 = *(LPCSTR *)(iVar2 + 0x1c);
    }
    FUN_0047807d(this,pCVar3);
  }
  return;
}


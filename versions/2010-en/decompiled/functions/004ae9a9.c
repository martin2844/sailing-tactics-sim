
/* Library Function - Single Match
    protected: long __thiscall CWnd::OnDisplayChange(unsigned int,long)
   
   Library: Visual Studio 1998 Release */

long __thiscall CWnd::OnDisplayChange(CWnd *this,uint param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  
  iVar1 = FUN_004bfff8();
  if (*(CWnd **)(*(int *)(iVar1 + 4) + 0x1c) == this) {
    FUN_004b1ded();
  }
  uVar2 = FUN_004af3eb();
  if ((uVar2 & 0x40000000) == 0) {
    iVar1 = FUN_004ac6cc();
    FUN_004ae04c(*(undefined4 *)(this + 0x1c),*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),
                 *(undefined4 *)(iVar1 + 0xc),1,1);
  }
  lVar3 = FUN_004ac701(this);
  return lVar3;
}


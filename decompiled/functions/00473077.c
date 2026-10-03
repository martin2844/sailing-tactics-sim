
/* Library Function - Single Match
    public: int __thiscall CControlBar::OnMouseActivate(class CWnd *,unsigned int,unsigned int)
   
   Library: Visual Studio 2003 Release */

int __thiscall
CControlBar::OnMouseActivate(CControlBar *this,CWnd *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = FUN_004786ef((int *)this);
  if (iVar1 == 0) {
    iVar1 = FUN_00468021(this);
  }
  else {
    CWnd::ActivateTopParent((CWnd *)this);
    iVar1 = 3;
  }
  return iVar1;
}



/* Library Function - Single Match
    public: int __thiscall CScrollView::OnMouseWheel(unsigned int,short,class CPoint)
   
   Library: Visual Studio 2003 Release */

int __thiscall CScrollView::OnMouseWheel(CScrollView *this,uint param_1,short param_2)

{
  CWnd *pCVar1;
  int extraout_EAX;
  
  if (((param_1 & 0xc) == 0) && (pCVar1 = FUN_0046fd81((CWnd *)this,1), pCVar1 == (CWnd *)0x0)) {
    FUN_004716ea((int *)this,param_1,param_2);
    return extraout_EAX;
  }
  return 0;
}


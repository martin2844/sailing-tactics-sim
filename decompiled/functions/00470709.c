
/* Library Function - Single Match
    public: int __thiscall CDC::LineTo(int,int)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

int __thiscall CDC::LineTo(CDC *this,int param_1,int param_2)

{
  HDC hdc;
  BOOL BVar1;
  
  hdc = *(HDC *)(this + 8);
  if ((hdc != (HDC)0x0) && (*(HDC *)(this + 4) != hdc)) {
    MoveToEx(hdc,param_1,param_2,(LPPOINT)0x0);
  }
  BVar1 = ::LineTo(*(HDC *)(this + 4),param_1,param_2);
  return BVar1;
}


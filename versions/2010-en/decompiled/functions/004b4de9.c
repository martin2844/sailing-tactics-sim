
/* Library Function - Single Match
    public: int __thiscall CDC::LineTo(int,int)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

int __thiscall CDC::LineTo(int *original_dc,int param_2,int param_3)

{
  HDC hdc;
  BOOL BVar1;
  
  hdc = (HDC)original_dc[2];
  if ((hdc != (HDC)0x0) && ((HDC)original_dc[1] != hdc)) {
    MoveToEx(hdc,param_2,param_3,(LPPOINT)0x0);
  }
  BVar1 = ::LineTo((HDC)original_dc[1],param_2,param_3);
  return BVar1;
}



/* Library Function - Single Match
    public: virtual void * __thiscall CWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __thiscall CWnd::_scalar_deleting_destructor_(CWnd *this,uint param_1)

{
  ~CWnd(this);
  if ((param_1 & 1) != 0) {
    FUN_004afc21(this);
  }
  return this;
}


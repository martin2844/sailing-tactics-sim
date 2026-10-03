
/* Library Function - Single Match
    public: virtual void * __thiscall CStatusBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __thiscall CStatusBar::_scalar_deleting_destructor_(CStatusBar *this,uint param_1)

{
  ~CStatusBar(this);
  if ((param_1 & 1) != 0) {
    FUN_004afc21(this);
  }
  return this;
}


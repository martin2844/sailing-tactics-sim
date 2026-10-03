
/* Library Function - Single Match
    public: virtual void * __thiscall CPaintDC::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __thiscall CPaintDC::_scalar_deleting_destructor_(CPaintDC *this,uint param_1)

{
  ~CPaintDC(this);
  if ((param_1 & 1) != 0) {
    FUN_0046b541(this);
  }
  return this;
}


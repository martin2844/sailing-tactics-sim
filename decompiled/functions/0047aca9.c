
/* Library Function - Single Match
    public: virtual void * __thiscall CWinThread::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __thiscall CWinThread::_scalar_deleting_destructor_(CWinThread *this,uint param_1)

{
  ~CWinThread(this);
  if ((param_1 & 1) != 0) {
    FUN_0046b541(this);
  }
  return this;
}


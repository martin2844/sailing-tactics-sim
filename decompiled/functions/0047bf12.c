
/* Library Function - Single Match
    public: __thiscall CProcessLocalObject::~CProcessLocalObject(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall CProcessLocalObject::~CProcessLocalObject(CProcessLocalObject *this)

{
  if (*(int *)this != 0) {
    if (*(undefined4 **)this != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)this)(1);
    }
  }
  return;
}


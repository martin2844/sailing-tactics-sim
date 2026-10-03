
/* Library Function - Single Match
    public: virtual void __thiscall CCmdTarget::OnFinalRelease(void)
   
   Library: Visual Studio 1998 Release */

void __thiscall CCmdTarget::OnFinalRelease(CCmdTarget *this)

{
  int iVar1;
  CTypeLibCache *this_00;
  
  FUN_0047c1af(0xd);
  iVar1 = *(int *)this;
  this_00 = (CTypeLibCache *)(**(code **)(iVar1 + 0x28))();
  if (this_00 != (CTypeLibCache *)0x0) {
    CTypeLibCache::Unlock(this_00);
  }
  FUN_0047c21f(0xd);
  if (this != (CCmdTarget *)0x0) {
    (**(code **)(iVar1 + 4))(1);
  }
  return;
}


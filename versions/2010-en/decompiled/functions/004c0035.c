
/* Library Function - Single Match
    public: void __thiscall CTypeLibCache::Unlock(void)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __thiscall CTypeLibCache::Unlock(CTypeLibCache *this)

{
  int *piVar1;
  LONG LVar2;
  
  LVar2 = InterlockedDecrement((LONG *)(this + 0x20));
  if (LVar2 == 0) {
    piVar1 = *(int **)(this + 0x1c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(this + 0x1c) = 0;
    }
    piVar1 = *(int **)(this + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(this + 8) = 0;
    }
  }
  return;
}


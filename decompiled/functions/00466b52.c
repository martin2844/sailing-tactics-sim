
/* Library Function - Multiple Matches With Same Base Name
    public: struct __POSITION * __thiscall CList<struct HWND__ *,struct HWND__ *>::AddTail(struct
   HWND__ *)
    public: struct __POSITION * __thiscall CList<class IControlSiteFactory *,class
   IControlSiteFactory *>::AddTail(class IControlSiteFactory *)
    public: struct __POSITION * __thiscall CObList::AddTail(class CObject *)
    public: struct __POSITION * __thiscall CPtrList::AddTail(void *)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall AddTail(void *this,undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00466ae4(this,*(undefined4 *)((int)this + 8),0);
  *(undefined4 *)(iVar1 + 8) = param_1;
  if (*(int **)((int)this + 8) == (int *)0x0) {
    *(int *)((int)this + 4) = iVar1;
  }
  else {
    **(int **)((int)this + 8) = iVar1;
  }
  *(int *)((int)this + 8) = iVar1;
  return;
}


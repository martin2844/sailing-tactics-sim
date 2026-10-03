
/* Library Function - Multiple Matches With Same Base Name
    public: struct __POSITION * __thiscall CList<struct HWND__ *,struct HWND__ *>::AddTail(struct
   HWND__ *)
    public: struct __POSITION * __thiscall CList<class IControlSiteFactory *,class
   IControlSiteFactory *>::AddTail(class IControlSiteFactory *)
    public: struct __POSITION * __thiscall CObList::AddTail(class CObject *)
    public: struct __POSITION * __thiscall CPtrList::AddTail(void *)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall AddTail(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004ab1c4(*(undefined4 *)(param_1 + 8),0);
  *(undefined4 *)(iVar1 + 8) = param_2;
  if (*(int **)(param_1 + 8) == (int *)0x0) {
    *(int *)(param_1 + 4) = iVar1;
  }
  else {
    **(int **)(param_1 + 8) = iVar1;
  }
  *(int *)(param_1 + 8) = iVar1;
  return;
}


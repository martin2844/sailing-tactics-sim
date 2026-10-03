
/* Library Function - Multiple Matches With Same Base Name
    protected: int __thiscall CToolBarCtrl::OnCreate(struct tagCREATESTRUCTA *)
    protected: int __thiscall CToolBarCtrl::OnCreate(struct tagCREATESTRUCTW *)
   
   Library: Visual Studio 2003 Release */

undefined4 __fastcall OnCreate(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00468021(param_1);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    SendMessageA((HWND)param_1[7],0x41e,0x14,0);
    uVar2 = 0;
  }
  return uVar2;
}


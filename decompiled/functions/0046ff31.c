
void __thiscall
FUN_0046ff31(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int *param_5)

{
  int iVar1;
  CWnd *pCVar2;
  CFrameWnd *this_00;
  BOOL BVar3;
  CWinThread *pCVar4;
  
  if ((int *)param_5[0x1c] != (int *)0x0) {
    (**(code **)(*(int *)param_5[0x1c] + 0x108))(param_1,param_2);
  }
  pCVar2 = FUN_004696a2((int)param_5);
  this_00 = FUN_0046cf4a(0x486140,pCVar2);
  if (this_00 != (CFrameWnd *)0x0) {
    BVar3 = IsIconic(*(HWND *)(this_00 + 0x1c));
    if (BVar3 == 0) goto LAB_0046ff82;
  }
  pCVar4 = AfxGetThread();
  this_00 = *(CFrameWnd **)(pCVar4 + 0x1c);
LAB_0046ff82:
  iVar1 = *(int *)this_00;
  (**(code **)(iVar1 + 0xd8))(0,param_5[0x22]);
  CFrameWnd::SetActiveView(this_00,*(CView **)(param_5[0x22] + 0xc),1);
  pCVar2 = FUN_004696a2((int)this);
  if (this_00 != (CFrameWnd *)pCVar2) {
    (**(code **)(*(int *)this + 0xec))(1,this,this);
  }
  (**(code **)(*param_5 + 0x60))();
  (**(code **)(iVar1 + 0xd0))(1);
  SendMessageA(*(HWND *)(this_00 + 0x1c),0x362,0xe001,0);
  UpdateWindow(*(HWND *)(this_00 + 0x1c));
  return;
}


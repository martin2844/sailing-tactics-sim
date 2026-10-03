
void __thiscall
FUN_004b4611(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  CFrameWnd *this;
  BOOL BVar3;
  CWinThread *pCVar4;
  CFrameWnd *pCVar5;
  
  if ((int *)param_6[0x1c] != (int *)0x0) {
    (**(code **)(*(int *)param_6[0x1c] + 0x108))(param_2,param_3);
  }
  uVar2 = FUN_004add82();
  this = (CFrameWnd *)FUN_004b162a(&PTR_s_CFrameWnd_004cdde0,uVar2);
  if (this != (CFrameWnd *)0x0) {
    BVar3 = IsIconic(*(HWND *)(this + 0x1c));
    if (BVar3 == 0) goto LAB_004b4662;
  }
  pCVar4 = AfxGetThread();
  this = *(CFrameWnd **)(pCVar4 + 0x1c);
LAB_004b4662:
  iVar1 = *(int *)this;
  (**(code **)(iVar1 + 0xd8))(0,param_6[0x22]);
  CFrameWnd::SetActiveView(this,*(CView **)(param_6[0x22] + 0xc),1);
  pCVar5 = (CFrameWnd *)FUN_004add82();
  if (this != pCVar5) {
    (**(code **)(*param_1 + 0xec))(1,param_1,param_1);
  }
  (**(code **)(*param_6 + 0x60))();
  (**(code **)(iVar1 + 0xd0))(1);
  SendMessageA(*(HWND *)(this + 0x1c),0x362,0xe001,0);
  UpdateWindow(*(HWND *)(this + 0x1c));
  return;
}


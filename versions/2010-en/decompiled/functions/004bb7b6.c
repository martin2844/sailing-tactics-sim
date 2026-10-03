
void __thiscall FUN_004bb7b6(CFrameWnd *param_1,int *param_2,int param_3)

{
  int iVar1;
  CView *pCVar2;
  undefined4 uVar3;
  CView *pCVar4;
  
  pCVar4 = (CView *)0x0;
  iVar1 = FUN_004bbf0e();
  if (iVar1 == 0) {
    pCVar2 = (CView *)FUN_004adfd3(*(undefined4 *)(param_1 + 0x1c),0xe900,1);
    if (pCVar2 != (CView *)0x0) {
      iVar1 = FUN_004b1618(&PTR_s_CView_004cddf8);
      if (iVar1 != 0) {
        CFrameWnd::SetActiveView(param_1,pCVar2,0);
        pCVar4 = pCVar2;
      }
    }
  }
  if (param_3 != 0) {
    FUN_004ae04c(*(undefined4 *)(param_1 + 0x1c),0x364,0,0,1,1);
    if (pCVar4 != (CView *)0x0) {
      (**(code **)(*(int *)pCVar4 + 0xf0))(0,param_1);
    }
    uVar3 = 0xffffffff;
    iVar1 = FUN_004bfff8();
    iVar1 = *(int *)(iVar1 + 4);
    if (param_1 == *(CFrameWnd **)(iVar1 + 0x1c)) {
      uVar3 = *(undefined4 *)(iVar1 + 0x74);
      *(undefined4 *)(iVar1 + 0x74) = 0xffffffff;
    }
    (**(code **)(*(int *)param_1 + 0xd4))(uVar3);
    if (pCVar4 != (CView *)0x0) {
      (**(code **)(*(int *)pCVar4 + 0xec))(1,pCVar4,pCVar4);
    }
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0xa8))();
  }
  (**(code **)(*(int *)param_1 + 0xe8))(1);
  return;
}


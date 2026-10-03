
void __thiscall FUN_004770d6(void *this,int *param_1,int param_2)

{
  int iVar1;
  CWnd *this_00;
  undefined4 uVar2;
  CWnd *pCVar3;
  
  pCVar3 = (CWnd *)0x0;
  iVar1 = FUN_0047782e((int)this);
  if (iVar1 == 0) {
    this_00 = FUN_004698f3(*(HWND *)((int)this + 0x1c),0xe900,1);
    if (this_00 != (CWnd *)0x0) {
      iVar1 = FUN_0046cf38(this_00,0x486158);
      if (iVar1 != 0) {
        CFrameWnd::SetActiveView(this,(CView *)this_00,0);
        pCVar3 = this_00;
      }
    }
  }
  if (param_2 != 0) {
    FUN_0046996c(*(HWND *)((int)this + 0x1c),0x364,0,0,1,1);
    if (pCVar3 != (CWnd *)0x0) {
      (**(code **)(*(int *)pCVar3 + 0xf0))(0,this);
    }
    uVar2 = 0xffffffff;
    iVar1 = FUN_0047b918();
    iVar1 = *(int *)(iVar1 + 4);
    if (this == *(void **)(iVar1 + 0x1c)) {
      uVar2 = *(undefined4 *)(iVar1 + 0x74);
      *(undefined4 *)(iVar1 + 0x74) = 0xffffffff;
    }
    (**(code **)(*(int *)this + 0xd4))(uVar2);
    if (pCVar3 != (CWnd *)0x0) {
      (**(code **)(*(int *)pCVar3 + 0xec))(1,pCVar3,pCVar3);
    }
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xa8))();
  }
  (**(code **)(*(int *)this + 0xe8))(1);
  return;
}


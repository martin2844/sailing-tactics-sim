
void __thiscall FUN_0047744b(void *this,int param_1,CWnd *param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  CWnd *pCVar3;
  CWnd *pCVar4;
  LRESULT LVar5;
  int *piVar6;
  int iVar7;
  
  FUN_00468021(this);
  uVar2 = FUN_0046ad0b((int)this);
  pCVar3 = this;
  if ((uVar2 & 0x40000000) == 0) {
    pCVar3 = FUN_0046980f(this);
  }
  if (param_1 != 0) {
    param_2 = this;
  }
  if ((pCVar3 == param_2) ||
     ((pCVar4 = FUN_0046980f(param_2), pCVar3 == pCVar4 &&
      (LVar5 = SendMessageA(*(HWND *)(param_2 + 0x1c),0x36d,0x40,0), LVar5 != 0)))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  *(uint *)(pCVar3 + 0x24) = *(uint *)(pCVar3 + 0x24) & 0xffffffdf;
  if (bVar1) {
    *(uint *)(pCVar3 + 0x24) = *(uint *)(pCVar3 + 0x24) | 0x20;
  }
  FUN_00476c9c(this,(-(uint)bVar1 & 0xfffffffc) + 8);
  piVar6 = (int *)FUN_0047782e((int)this);
  if (piVar6 == (int *)0x0) {
    iVar7 = (**(code **)(*(int *)this + 200))();
    piVar6 = (int *)FUN_0047782e(iVar7);
    if (piVar6 == (int *)0x0) {
      return;
    }
  }
  if ((param_1 != 0) && (param_3 == 0)) {
    (**(code **)(*piVar6 + 0xec))(1,piVar6,piVar6);
  }
  (**(code **)(*piVar6 + 0xf0))(param_1,this);
  return;
}


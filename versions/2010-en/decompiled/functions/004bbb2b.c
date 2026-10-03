
void __thiscall FUN_004bbb2b(int *param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  LRESULT LVar4;
  int *piVar5;
  
  FUN_004ac701();
  uVar2 = FUN_004af3eb();
  piVar5 = param_1;
  if ((uVar2 & 0x40000000) == 0) {
    piVar5 = (int *)FUN_004adeef();
  }
  if (param_2 != 0) {
    param_3 = param_1;
  }
  if ((piVar5 == param_3) ||
     ((piVar3 = (int *)FUN_004adeef(), piVar5 == piVar3 &&
      (LVar4 = SendMessageA((HWND)param_3[7],0x36d,0x40,0), LVar4 != 0)))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  piVar5[9] = piVar5[9] & 0xffffffdf;
  if (bVar1) {
    piVar5[9] = piVar5[9] | 0x20;
  }
  FUN_004bb37c((-(uint)bVar1 & 0xfffffffc) + 8);
  piVar5 = (int *)FUN_004bbf0e();
  if (piVar5 == (int *)0x0) {
    (**(code **)(*param_1 + 200))();
    piVar5 = (int *)FUN_004bbf0e();
    if (piVar5 == (int *)0x0) {
      return;
    }
  }
  if ((param_2 != 0) && (param_4 == 0)) {
    (**(code **)(*piVar5 + 0xec))(1,piVar5,piVar5);
  }
  (**(code **)(*piVar5 + 0xf0))(param_2,param_1);
  return;
}


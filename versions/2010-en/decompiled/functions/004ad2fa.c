
void __thiscall FUN_004ad2fa(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  HMENU pHVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (*param_3 == 1) {
    iVar1 = FUN_004c04f2(FUN_0049a32a);
    if (*(HWND *)(iVar1 + 0x50) == *(HWND *)(param_1 + 0x1c)) {
      pHVar2 = *(HMENU *)(iVar1 + 0x54);
    }
    else {
      pHVar2 = GetMenu(*(HWND *)(param_1 + 0x1c));
    }
    uVar3 = FUN_004b1ec9(pHVar2);
    piVar4 = (int *)FUN_004ad373(uVar3,param_3[2]);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x18))(param_3);
    }
  }
  else {
    iVar1 = FUN_004adfd3(*(undefined4 *)(param_1 + 0x1c),param_3[1],1);
    if ((iVar1 != 0) && (iVar1 = FUN_004ae5a1(0), iVar1 != 0)) {
      return;
    }
  }
  FUN_004ac701(param_1);
  return;
}


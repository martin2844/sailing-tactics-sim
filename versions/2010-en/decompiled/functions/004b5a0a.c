
void __thiscall FUN_004b5a0a(int *param_1,int *param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  
  param_2[1] = 0;
  *param_2 = 0;
  uVar2 = FUN_004af3eb();
  pcVar1 = *(code **)(*param_1 + 0x70);
  iVar3 = (*pcVar1)(1);
  if ((iVar3 == 0) && (*param_2 = DAT_00538190, (uVar2 & 0x800000) != 0)) {
    *param_2 = *param_2 + -1;
  }
  iVar3 = (*pcVar1)(0);
  if ((iVar3 == 0) && (param_2[1] = DAT_00538194, (uVar2 & 0x800000) != 0)) {
    param_2[1] = param_2[1] + -1;
  }
  return;
}


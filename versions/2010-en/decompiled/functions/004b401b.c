
void __fastcall FUN_004b401b(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = param_1[0x12];
  param_1[0x12] = 0;
  if (param_1[0xd] != 0) {
    pcVar2 = *(code **)(*param_1 + 0x9c);
    do {
      piVar4 = (int *)FUN_004add82();
      (*pcVar2)(piVar4);
      (**(code **)(*piVar4 + 0x60))();
    } while (param_1[0xd] != 0);
  }
  iVar3 = *param_1;
  param_1[0x12] = iVar1;
  (**(code **)(iVar3 + 0x74))();
  if ((param_1[0x12] != 0) && (param_1 != (int *)0x0)) {
    (**(code **)(iVar3 + 4))(1);
  }
  return;
}


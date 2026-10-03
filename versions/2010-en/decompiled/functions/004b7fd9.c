
void __thiscall FUN_004b7fd9(int *param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_2 == (int *)0x0) {
    if (DAT_00537ed4 != (int *)0x0) {
      if ((int *)DAT_00537ed4[1] != (int *)0x0) {
        pcVar1 = *(code **)(*param_1 + 0x14);
        piVar3 = (int *)DAT_00537ed4[1];
        do {
          piVar2 = (int *)*piVar3;
          (*pcVar1)(piVar3[2]);
          piVar3 = piVar2;
        } while (piVar2 != (int *)0x0);
      }
      if (DAT_00537ed4 != (int *)0x0) {
        (**(code **)(*DAT_00537ed4 + 4))(1);
      }
      DAT_00537ed4 = (int *)0x0;
    }
    DAT_004ed5ec = 0;
  }
  else {
    (**(code **)(*param_2 + 0x58))();
    AddTail(param_2);
  }
  return;
}


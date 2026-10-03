
void __thiscall FUN_004738f9(void *this,int *param_1)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 == (int *)0x0) {
    if (DAT_004ae37c != (int *)0x0) {
      if ((int *)DAT_004ae37c[1] != (int *)0x0) {
        pcVar1 = *(code **)(*(int *)this + 0x14);
        piVar3 = (int *)DAT_004ae37c[1];
        do {
          piVar2 = (int *)*piVar3;
          (*pcVar1)(piVar3[2]);
          piVar3 = piVar2;
        } while (piVar2 != (int *)0x0);
      }
      if (DAT_004ae37c != (int *)0x0) {
        (**(code **)(*DAT_004ae37c + 4))(1);
      }
      DAT_004ae37c = (int *)0x0;
    }
    DAT_0049f424 = 0;
  }
  else {
    (**(code **)(*param_1 + 0x58))();
    AddTail((void *)((int)this + 4),param_1);
  }
  return;
}


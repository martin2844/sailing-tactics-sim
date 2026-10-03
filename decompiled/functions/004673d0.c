
undefined4 FUN_004673d0(uint param_1,int param_2)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_2 == 0x110) {
    pvVar1 = (void *)FUN_004680f4(param_1);
    piVar2 = FUN_0046cf4a(0x485618,pvVar1);
    if (piVar2 == (int *)0x0) {
      uVar3 = 1;
    }
    else {
      uVar3 = (**(code **)(*piVar2 + 0xc4))();
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


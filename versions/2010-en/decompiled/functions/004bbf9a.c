
void FUN_004bbf9a(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)FUN_004bcdbe();
  if (param_3 == 0) {
    FUN_004af4dd(0,0,0,0,0,(-(uint)(param_2 != 0) & 0xffffffc0) + 0x80 | 0x17);
    (**(code **)(*param_1 + 0xcc))(param_2);
    if ((param_2 != 0) || (iVar2 = FUN_004bcdcf(), iVar2 == 0)) {
      (**(code **)(*piVar1 + 0xd0))(0);
    }
  }
  else {
    (**(code **)(*param_1 + 0xcc))(param_2);
    piVar1[0x2e] = piVar1[0x2e] | 0xc;
  }
  iVar2 = FUN_004bcdcf();
  if (iVar2 == 0) {
    return;
  }
  if ((int *)param_1[0x1c] == (int *)0x0) {
    uVar3 = (uint)(param_2 != 0);
  }
  else {
    uVar3 = (**(code **)(*(int *)param_1[0x1c] + 0xe8))();
  }
  if ((uVar3 == 1) && (param_2 != 0)) {
    piVar1[0x22] = -1;
    if (param_3 == 0) {
      uVar4 = 8;
LAB_004bc075:
      FUN_004af52c(uVar4);
      return;
    }
    piVar1[0x22] = 8;
  }
  else {
    if (uVar3 == 0) {
      piVar1[0x22] = -1;
      if (param_3 != 0) {
        piVar1[0x22] = 0;
        return;
      }
      uVar4 = 0;
      goto LAB_004bc075;
    }
    if (param_3 != 0) {
      return;
    }
  }
  (**(code **)(*piVar1 + 0xd0))(0);
  return;
}


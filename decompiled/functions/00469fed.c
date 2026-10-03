
uint __thiscall FUN_00469fed(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  uint uVar1;
  int *local_c;
  int local_8;
  
  if (param_1 < 0x3a) {
    if ((param_1 == 0x39) || ((0x2a < param_1 && (param_1 < 0x30)))) {
LAB_0046a0cd:
      uVar1 = FUN_00468ff7();
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x4e) {
      local_c = param_4;
      local_8 = param_3;
      uVar1 = FUN_0046afc3(this,(undefined4 *)0x0,*(uint *)(param_3 + 8) & 0xffff | 0xbc4e0000,
                           &local_c,(undefined4 *)0x0);
      return uVar1;
    }
    if (param_1 == 0x111) {
      uVar1 = FUN_0046afc3(this,(undefined4 *)0x0,(uint)param_2 >> 0x10 | 0xbd110000,
                           (undefined4 *)0x0,(undefined4 *)0x0);
      if (uVar1 == 0) {
        return 0;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = 1;
        return 1;
      }
      return 1;
    }
    if ((0x113 < param_1) && ((param_1 < 0x116 || (param_1 == 0x210)))) goto LAB_0046a0cd;
  }
  if ((0x131 < param_1) && (param_1 < 0x139)) {
    local_8 = param_1 - 0x132;
    local_c = param_2;
    uVar1 = FUN_00468ff7();
    if (*param_4 != 0) {
      return uVar1;
    }
  }
  return 0;
}


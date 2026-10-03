
undefined4 FUN_004ae6cd(uint param_1,int *param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_10 [4];
  int *local_c;
  int local_8;
  
  if (param_1 < 0x3a) {
    if ((param_1 == 0x39) || ((0x2a < param_1 && (param_1 < 0x30)))) {
LAB_004ae7ad:
      uVar1 = FUN_004ad6d7(param_1 + 0xbc00,param_2,param_3,param_4);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x4e) {
      local_c = param_4;
      local_8 = param_3;
      uVar1 = FUN_004af6a3(0,*(uint *)(param_3 + 8) & 0xffff | 0xbc4e0000,&local_c,0);
      return uVar1;
    }
    if (param_1 == 0x111) {
      iVar2 = FUN_004af6a3(0,(uint)param_2 >> 0x10 | 0xbd110000,0,0);
      if (iVar2 == 0) {
        return 0;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = 1;
        return 1;
      }
      return 1;
    }
    if ((0x113 < param_1) && ((param_1 < 0x116 || (param_1 == 0x210)))) goto LAB_004ae7ad;
  }
  if ((0x131 < param_1) && (param_1 < 0x139)) {
    local_8 = param_1 - 0x132;
    local_c = param_2;
    uVar1 = FUN_004ad6d7(0xbc19,0,local_10,param_4);
    if (*param_4 != 0) {
      return uVar1;
    }
  }
  return 0;
}


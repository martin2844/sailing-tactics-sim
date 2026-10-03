
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00488b90(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_10;
  int local_c;
  double local_8;
  
  if ((DAT_004fb5d4 == 1) || (DAT_004da218 = 0x898, DAT_004da1f8 == 0xb)) {
    DAT_004da218 = 0x19c8;
  }
  if ((((DAT_004da1f8 == 6) || (DAT_004da1f8 == 9)) || (DAT_004da1f8 == 0x68)) ||
     (DAT_004da1f8 == 100)) {
    DAT_004da218 = 0x1130;
  }
  if ((DAT_004da1f8 == 0x65) || (DAT_004da1f8 == 0x67)) {
    DAT_004da218 = 0x1004;
  }
  if (DAT_004da1f8 == 0x6a) {
    DAT_004da218 = 0xce4;
  }
  iVar1 = DAT_005362d4;
  if (param_1 != 1) {
    iVar1 = *(int *)(&DAT_00522d30 + param_4 * 4);
  }
  iVar1 = FUN_0041bc20(iVar1);
  local_10 = 1;
  local_c = 3;
  do {
    iVar2 = local_10;
    if (((DAT_004da218 < 0x1771) || (iVar2 = local_c, DAT_004da218 < 0x1771)) &&
       (4000 < DAT_004da218)) {
      iVar2 = local_10 * 2;
    }
    iVar1 = FUN_0041bc20(iVar1);
    iVar1 = FUN_0041bc20(iVar1);
    if ((iVar1 < 0) || (0x168 < iVar1)) {
      iVar1 = 0;
    }
    iVar3 = (&DAT_004f85c8)[iVar1] * iVar2 + param_2;
    iVar4 = param_3 - (&DAT_004f1740)[iVar1] * iVar2;
    if (DAT_004da1f8 < 1) {
      fVar5 = FUN_0042f330(iVar3,iVar4,param_4);
LAB_00488cf3:
      local_8 = (double)fVar5;
    }
    else {
      if (param_1 == 1) {
        fVar5 = FUN_0047d5f0(param_4,iVar3,iVar4,2,0);
        local_8 = (double)fVar5;
      }
      if (param_1 == 0) {
        fVar5 = FUN_0047d5f0(param_4,iVar3,iVar4,1,0);
        goto LAB_00488cf3;
      }
    }
    if (((param_1 == 0) && (local_8 < _DAT_004cc728)) ||
       ((param_1 == 1 && (local_8 <= _DAT_004cc650)))) {
      return iVar2 * 100;
    }
    local_c = local_c + 3;
    local_10 = local_10 + 1;
    if (0x3f < local_c) {
      return DAT_004da218;
    }
  } while( true );
}


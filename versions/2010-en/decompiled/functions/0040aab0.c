
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040aab0(int *param_1,double param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  local_30 = 0;
  local_2c = 0;
  if (DAT_004da1f8 == 0) {
    local_30 = DAT_00536410;
    local_2c = DAT_00536414;
  }
  iVar2 = (-(uint)(DAT_004da19c != 8) & 0xfffffffc) + 9;
  if (DAT_004da1f8 == 1) {
    iVar2 = 7;
  }
  if (DAT_004da1f8 == 2) {
    iVar2 = 7;
  }
  if (DAT_004da1f8 == 3) {
    iVar2 = 5;
  }
  if (DAT_004da1f8 == 4) {
    iVar2 = 3;
  }
  if (DAT_004da1f8 == 5) {
    iVar2 = 3;
    local_30 = 8000;
    local_2c = -1000;
  }
  if (DAT_004da1f8 == 6) {
    iVar2 = 7;
  }
  if (DAT_004da1f8 == 7) {
    iVar2 = 5;
  }
  if (DAT_004da1f8 == 9) {
    iVar2 = 4;
  }
  if (DAT_004da1f8 == 0xb) {
    iVar2 = 4;
    local_30 = 1000;
  }
  if (DAT_004da1f8 == 0x69) {
    iVar2 = 5;
    local_30 = -300;
  }
  if (DAT_004da1f8 == 0x68) {
    iVar2 = 10;
  }
  if (DAT_004da1f8 == 100) {
    iVar2 = 3;
  }
  if (DAT_004da1f8 == 0x65) {
    iVar2 = 8;
  }
  if (DAT_004da1f8 == 0x66) {
    iVar2 = 7;
  }
  if (DAT_004da1f8 == 0x6a) {
    iVar2 = 6;
  }
  if (DAT_004da1f8 == 999) {
    iVar2 = 5;
  }
  local_24 = -10;
  local_28 = -10;
  while( true ) {
    do {
      iVar3 = local_24 * (DAT_00525a9c / iVar2) + local_30;
      iVar5 = local_28 * (DAT_00525a9c / iVar2) + local_2c;
      if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7ec4);
      }
      if (DAT_004da1f8 == 0) {
        uVar1 = FUN_0042fca0(iVar3,iVar5,0);
      }
      else {
        uVar1 = FUN_00430260(iVar3,iVar5,0);
      }
      iVar4 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
      fVar6 = FUN_0043ec20((double)iVar3,(double)iVar5,4,0);
      if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
        _DAT_004fbb88 = 0;
        _DAT_004fbb8c = 0x40d09a00;
      }
      fVar7 = (float10)fsin(fVar6);
      fVar6 = (float10)fcos(fVar6);
      if (0 < iVar4) {
        FUN_00444270(param_1,(int)(longlong)
                                  (fVar7 * (float10)param_2 *
                                   (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
                                  (float10)param_3),
                     (int)(longlong)
                          ((float10)param_4 -
                          fVar6 * (float10)param_2 *
                          (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)),DAT_00536418,
                     (int)(0x46 / (longlong)iVar4));
      }
      local_28 = local_28 + 1;
    } while (local_28 < 0xb);
    local_24 = local_24 + 1;
    if (10 < local_24) break;
    local_28 = -10;
  }
  return;
}


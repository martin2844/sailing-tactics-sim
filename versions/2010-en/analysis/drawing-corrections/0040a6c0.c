
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040a6c0(int *param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  if (DAT_004da1f8 == 0) {
    local_2c = DAT_00536414;
    local_34 = (-(uint)(DAT_004da19c != 8) & 0xfffffffc) + 9;
    local_30 = DAT_00536410;
  }
  else {
    local_30 = 0;
    local_2c = 0;
  }
  if (DAT_004da1f8 == 1) {
    local_34 = 7;
  }
  if (DAT_004da1f8 == 2) {
    local_34 = (-(uint)(DAT_0053527c != 0) & 2) + 6;
  }
  if (DAT_004da1f8 == 3) {
    local_34 = 5;
  }
  if (DAT_004da1f8 == 4) {
    local_34 = 3;
  }
  if (DAT_004da1f8 == 5) {
    local_34 = 3;
    local_30 = 8000;
    local_2c = -1000;
  }
  if (DAT_004da1f8 == 6) {
    local_34 = 7;
  }
  if (DAT_004da1f8 == 7) {
    local_34 = 5;
  }
  if (DAT_004da1f8 == 9) {
    local_34 = 4;
  }
  if (DAT_004da1f8 == 10) {
    local_34 = 6;
  }
  if (DAT_004da1f8 == 0xb) {
    local_34 = 6;
  }
  if (DAT_004da1f8 == 0xc) {
    local_34 = 6;
  }
  if (DAT_004da1f8 == 0x67) {
    local_34 = 5;
  }
  if (DAT_004da1f8 == 0x69) {
    local_34 = 5;
  }
  if (DAT_004da1f8 == 0x68) {
    local_34 = 10;
  }
  if (DAT_004da1f8 == 100) {
    local_34 = 5;
  }
  if (DAT_004da1f8 == 0x65) {
    local_34 = 8;
  }
  if (DAT_004da1f8 == 0x66) {
    local_34 = 7;
  }
  if (DAT_004da1f8 == 0x6a) {
    local_34 = 6;
  }
  if (DAT_004da1f8 == 999) {
    local_34 = 5;
  }
  local_24 = -10;
  local_28 = -10;
  while( true ) {
    do {
      iVar2 = local_24 * (DAT_00525a9c / local_34) + local_30;
      iVar3 = local_28 * (DAT_00525a9c / local_34) + local_2c;
      if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7ec4);
      }
      if (DAT_004da1f8 == 0) {
        iVar1 = FUN_00436ba0(iVar2,iVar3,0);
      }
      else {
        iVar1 = FUN_00488d70(iVar2,iVar3,0);
      }
      if ((DAT_004f4528 == 1) && (DAT_0053516c != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_0053516c);
      }
      if ((DAT_004f4528 == -1) && (DAT_004f1cec != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f1cec);
      }
      if ((DAT_004fae5c == 1) && (DAT_00522f1c != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_00522f1c);
      }
      if ((0 < DAT_0053545c) && (DAT_00535c64 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_00535c64);
      }
      if (((DAT_004f8d74 == 1) && (DAT_004da1f8 == 0)) && (DAT_004fb994 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004fb994);
      }
      if (((DAT_004fba20 == 1) && (0 < DAT_004da1f8)) && (DAT_004fb994 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004fb994);
      }
      if (((DAT_005363e4 == 1) && (DAT_004f8d74 == 0)) && (DAT_004f7ec4 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f7ec4);
      }
      if (((DAT_005363e4 == 1) && (DAT_004f8d74 == 1)) && (DAT_004f7084 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      fVar4 = FUN_0043ec20((double)iVar2,(double)iVar3,4,0);
      if (_DAT_004cc558 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
        _DAT_004fbb88 = 0;
        _DAT_004fbb8c = 0x40da5e00;
      }
      fVar5 = (float10)fcos(fVar4);
      fVar4 = (float10)fsin(fVar4);
      FUN_00444270(param_1,(int)(longlong)
                                (fVar4 * (float10)param_2 *
                                 (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
                                (float10)param_3),
                   (int)(longlong)
                        ((float10)param_4 -
                        fVar5 * (float10)param_2 *
                        (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)),DAT_00523af4,
                   (int)(0x78 / (longlong)iVar1));
      local_28 = local_28 + 1;
    } while (local_28 < 0xb);
    local_24 = local_24 + 1;
    if (10 < local_24) break;
    local_28 = -10;
  }
  return;
}


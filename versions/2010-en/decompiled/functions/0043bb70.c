
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0043bb70(int param_1,int param_2)

{
  double dVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  double local_10;
  
  iVar3 = *(int *)(&DAT_004fecc8 + param_2 * 4);
  iVar2 = (&DAT_004fb380)[param_2];
  fVar4 = (float10)fsin((float10)iVar3 * (float10)_DAT_004cc568);
  fVar5 = (float10)fcos((float10)iVar3 * (float10)_DAT_004cc568);
  fVar4 = fVar4 * (float10)iVar2;
  dVar1 = (double)(fVar5 * (float10)iVar2 - (float10)param_1 * (float10)_DAT_004cc8b0);
  if (fVar4 < (float10)_DAT_004cc650) {
    fVar4 = (float10)_DAT_004cc650;
  }
  fVar5 = fVar4 * fVar4 + (float10)dVar1 * (float10)dVar1;
  local_10 = (double)fVar5;
  *(int *)(&DAT_00534eb8 + param_2 * 4) = (int)(longlong)SQRT(fVar5);
  if (9 < iVar2) {
    local_10 = local_10 * _DAT_004cc8d0;
  }
  if (iVar2 == 9) {
    local_10 = local_10 * _DAT_004cc400;
  }
  if (iVar2 == 8) {
    local_10 = local_10 * _DAT_004cc468;
  }
  if (iVar2 == 7) {
    local_10 = local_10 * _DAT_004cc630;
  }
  if (dVar1 == _DAT_004cc658) {
    *(undefined4 *)(&DAT_004f4cd8 + param_2 * 4) = 0x5a;
    if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
      iVar3 = *(int *)(&DAT_00535740 + param_2 * 4) + 0x5a;
    }
    else {
      iVar3 = *(int *)(&DAT_00535740 + param_2 * 4) + -0x5a;
    }
  }
  else if ((fVar4 == (float10)_DAT_004cc658) && (iVar3 < 5)) {
    *(undefined4 *)(&DAT_004f4cd8 + param_2 * 4) = 0;
    if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
      iVar3 = *(int *)(&DAT_00535740 + param_2 * 4);
    }
    else {
      iVar3 = *(int *)(&DAT_00535740 + param_2 * 4);
    }
  }
  else if ((fVar4 == (float10)_DAT_004cc658) && (-1 < iVar3)) {
    *(undefined4 *)(&DAT_004f4cd8 + param_2 * 4) = 0xb3;
    if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
      iVar3 = *(int *)(&DAT_00535740 + param_2 * 4) + 0xb3;
    }
    else {
      iVar3 = *(int *)(&DAT_00535740 + param_2 * 4) + -0xb3;
    }
  }
  else {
    if (_DAT_004cc658 < dVar1) {
      fVar5 = (float10)fpatan(fVar4 / (float10)dVar1,(float10)1);
      *(int *)(&DAT_004f4cd8 + param_2 * 4) = (int)(longlong)(fVar5 * (float10)_DAT_004cc3e8);
    }
    if (dVar1 < _DAT_004cc658) {
      fVar5 = (float10)fpatan(-((float10)dVar1 / fVar4),(float10)1);
      *(int *)(&DAT_004f4cd8 + param_2 * 4) = 0x5a - (int)(longlong)(fVar5 * (float10)_DAT_004cc910)
      ;
    }
    if (0xb3 < iVar3) {
      *(undefined4 *)(&DAT_004f4cd8 + param_2 * 4) = 0xb3;
    }
    if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
      iVar3 = *(int *)(&DAT_004f4cd8 + param_2 * 4) + *(int *)(&DAT_00535740 + param_2 * 4);
    }
    else {
      iVar3 = *(int *)(&DAT_00535740 + param_2 * 4) - *(int *)(&DAT_004f4cd8 + param_2 * 4);
    }
  }
  iVar3 = FUN_0041bc20(iVar3);
  *(int *)(&DAT_00535890 + param_2 * 4) = iVar3;
  return (float10)local_10;
}


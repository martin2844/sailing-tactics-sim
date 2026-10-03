
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043fef0(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float10 fVar7;
  int local_4;
  
  iVar2 = param_1;
  if (-1 < DAT_004f8cd0) {
    if (DAT_004f8cd0 < 0x1e) {
      *(undefined4 *)(&DAT_004fbf10 + param_1 * 4) = 1;
    }
    FUN_0043ec20((double)DAT_00536410,(double)DAT_00536414,0,param_1);
    param_1 = 1;
    bVar1 = true;
    local_4 = 0;
    do {
      iVar3 = FUN_0041bc20(DAT_004f4b40 + 0xb4);
      iVar4 = FUN_0041bc20(*(int *)((int)&DAT_004fb51c + local_4));
      _DAT_00522fe8 = DAT_004fb51c;
      _DAT_0052307c = DAT_004fb520;
      _DAT_005230a0 = DAT_004fb524;
      if (DAT_0053527c == 0) {
        if ((((iVar3 == iVar4) ||
             (uVar6 = iVar3 - iVar4 >> 0x1f, iVar5 = (iVar3 - iVar4 ^ uVar6) - uVar6, iVar5 == 0x168
             )) || (iVar5 == 0x167)) || ((iVar3 == iVar4 + -1 || (iVar3 == iVar4 + 1)))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      if ((DAT_0053527c == 1) && (param_1 == *(int *)(&DAT_004fbf10 + iVar2 * 4))) {
        if ((iVar3 == iVar4) ||
           (((uVar6 = iVar3 - iVar4 >> 0x1f, (iVar3 - iVar4 ^ uVar6) - uVar6 == 0x168 ||
             (iVar3 == iVar4 + -1)) || (iVar3 == iVar4 + 1)))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      _DAT_00522fe4 = iVar3;
      if (((param_1 == *(int *)(&DAT_004fbf10 + iVar2 * 4)) && (bVar1)) &&
         ((*(int *)(&DAT_004fb534 + local_4) + -0x3c <= (int)(longlong)_DAT_004fbb88 &&
          (DAT_0053527c == 0)))) {
        *(int *)(&DAT_004fbf10 + iVar2 * 4) = *(int *)(&DAT_004fbf10 + iVar2 * 4) + 1;
      }
      if (((param_1 == *(int *)(&DAT_004fbf10 + iVar2 * 4)) && (bVar1)) &&
         ((*(int *)(&DAT_004fb534 + local_4) + -0x1e <= (int)(longlong)_DAT_004fbb88 &&
          (DAT_0053527c == 1)))) {
        *(int *)(&DAT_004fbf10 + iVar2 * 4) = *(int *)(&DAT_004fbf10 + iVar2 * 4) + 1;
      }
      iVar3 = DAT_00536408;
      local_4 = local_4 + 4;
      param_1 = param_1 + 1;
    } while (local_4 < 9);
    if (((*(int *)(&DAT_004fbf10 + iVar2 * 4) == 4) && (DAT_00536408 == 1)) &&
       (*(int *)(&DAT_004fe2b0 + iVar2 * 4) == 1)) {
      *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 1;
    }
    iVar4 = DAT_004da194;
    if ((((*(int *)(&DAT_004fbf10 + iVar2 * 4) == 3) ||
         ((*(int *)(&DAT_004fbf10 + iVar2 * 4) == 2 && (DAT_004da194 < 0xb)))) &&
        (*(int *)(&DAT_004fe2b0 + iVar2 * 4) == 1)) && ((DAT_0053527c == 1 && (DAT_004f853c == 1))))
    {
      *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 1;
    }
    if (*(int *)(&DAT_004fbf10 + iVar2 * 4) == 4) {
      *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 0;
    }
    if (((*(int *)(&DAT_004fbf10 + iVar2 * 4) == 3) ||
        ((*(int *)(&DAT_004fbf10 + iVar2 * 4) == 2 && (iVar4 < 0xb)))) &&
       ((DAT_004da1e8 == 1 &&
        ((iVar3 == 0 &&
         (fVar7 = FUN_00439e80(iVar2,(double)DAT_005229c8,(double)DAT_00522ac4),
         fVar7 < (float10)_DAT_004cc488)))))) {
      *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 0;
    }
    if ((((DAT_004da188 < 3) &&
         ((*(int *)(&DAT_004fbf10 + iVar2 * 4) == 3 ||
          ((*(int *)(&DAT_004fbf10 + iVar2 * 4) == 2 && (DAT_004da194 < 0xb)))))) &&
        (DAT_004da1e8 == 1)) &&
       (fVar7 = FUN_00439e80(iVar2,(double)DAT_005229c8,(double)DAT_00522ac4),
       fVar7 < (float10)_DAT_004cc488)) {
      *(uint *)(&DAT_004fbf10 + iVar2 * 4) = (uint)(DAT_004da1cc < 5);
    }
    if (((DAT_0053527c == 1) && (*(int *)(&DAT_004fe2b0 + iVar2 * 4) == 1)) &&
       (fVar7 = FUN_00439e80(iVar2,(double)DAT_005229c8,(double)DAT_00522ac4),
       fVar7 < (float10)_DAT_004cc488)) {
      *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 1;
    }
    if (((DAT_005363f8 == 1) && (5 < DAT_004da1cc)) &&
       (fVar7 = FUN_00439e80(iVar2,(double)DAT_005229c8,(double)DAT_00522ac4),
       fVar7 < (float10)_DAT_004cc488)) {
      *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 0;
    }
    if (DAT_004da1f8 == 5) {
      fVar7 = FUN_00439e80(iVar2,(double)DAT_005117b0,(double)DAT_00511d30);
      if (fVar7 < (float10)_DAT_004cc490) {
        *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 2;
      }
      fVar7 = FUN_00439e80(iVar2,(double)DAT_005117bc,(double)DAT_00511d3c);
      if (fVar7 < (float10)_DAT_004cc490) {
        *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 3;
      }
      fVar7 = FUN_00439e80(iVar2,(double)DAT_005117c4,(double)DAT_00511d44);
      if (fVar7 < (float10)_DAT_004cc490) {
        *(undefined4 *)(&DAT_004fbf10 + iVar2 * 4) = 0;
      }
    }
    return;
  }
  *(undefined4 *)(&DAT_004fbf10 + param_1 * 4) = 0;
  return;
}


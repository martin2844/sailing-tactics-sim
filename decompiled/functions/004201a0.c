
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004201a0(int param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  int local_14;
  
  DAT_004abc80 = DAT_004a4f8c;
  DAT_004ab184 = param_1 * 100;
  iVar3 = ((6 < DAT_00491190) - 1 & 0xc) + 0x35;
  if (DAT_0049118c == 2) {
    iVar3 = 0x28;
  }
  if (DAT_004ac914 == 1) {
    iVar3 = iVar3 + 2;
  }
  if ((DAT_004ac900 == 1) || (DAT_004ac90c == 1)) {
    iVar3 = iVar3 + 5;
  }
  if ((DAT_0049116c < 0xd) && (2 < DAT_0049118c)) {
    iVar3 = iVar3 + -4;
  }
  if ((DAT_0049116c < 0xb) && (2 < DAT_0049118c)) {
    iVar3 = iVar3 + -4;
  }
  if ((DAT_00491194 == 8) && (DAT_004a5a4c == 0)) {
    DAT_004abc80 = 0x5a;
    DAT_004ab184 = 0xce4;
    DAT_00491160 = 1;
  }
  if (DAT_00491194 == 8) {
    if (DAT_004a5a4c == 1) {
      DAT_004ab184 = 0x898;
    }
    iVar3 = iVar3 + 10;
  }
  if (DAT_004ac954 == 1) {
    DAT_004ab184 = (DAT_004ab184 / 10) * 7;
  }
  DAT_004aa998 = (DAT_0049118c + 10) * 10;
  if (DAT_0049118c == 2) {
    DAT_004aa998 = 0x7d;
  }
  iVar4 = 0;
  DAT_004aa594 = 0;
  DAT_004aa59c = 0;
  if (DAT_00491194 == 1) {
    DAT_004aa59c = 0x15e;
  }
  if (DAT_00491194 == 2) {
    iVar4 = -0xfa;
    DAT_004aa594 = -0xfa;
  }
  if (DAT_00491194 == 3) {
    DAT_004aa59c = -0x15e;
  }
  if (DAT_00491194 == 4) {
    iVar4 = 0xfa;
    DAT_004aa594 = 0xfa;
  }
  if (DAT_004a4378 == 1) {
    iVar4 = 500;
    DAT_004aa594 = 500;
  }
  if (DAT_00491194 == 9) {
    iVar4 = 0;
    DAT_004aa59c = -400;
    DAT_004aa594 = 0;
  }
  if (DAT_00491194 == 10) {
    iVar4 = 0;
    DAT_004aa59c = 400;
    DAT_004aa594 = 0;
  }
  local_14 = DAT_004ab184;
  if (DAT_004a5a4c != 1) {
    local_14 = (int)(DAT_004ab184 * 3 + (DAT_004ab184 * 3 >> 0x1f & 3U)) >> 2;
  }
  if (DAT_00491194 == 10) {
    local_14 = DAT_004ab184 / 3;
  }
  if ((DAT_00491160 == 1) && (local_14 = DAT_004ab184, DAT_0049118c < 0xf)) {
    local_14 = 1;
  }
  if ((DAT_004ac9a8 == 1) && (DAT_004a5a4c == 0)) {
    iVar5 = -1;
  }
  else {
    iVar5 = 1;
  }
  iVar6 = iVar5 * 0x5a;
  FUN_00420b20(iVar4,DAT_004aa59c,DAT_004aa998,DAT_004abc80 + iVar6);
  DAT_004a70f8 = DAT_004a70e8;
  DAT_004a72c8 = DAT_004aa81c;
  _DAT_004a6440 = FUN_00413cb0(DAT_004abc80 + iVar6);
  _DAT_004a6458 = DAT_004aa998;
  FUN_00420b20((DAT_004aa594 + DAT_004a70f8) / 2,(DAT_004a72c8 + DAT_004aa59c) / 2,DAT_004ab184,
               DAT_004abc80);
  DAT_004aa294 = DAT_004a70e8;
  dVar1 = (double)(DAT_004a70e8 - DAT_004aa594);
  DAT_004aa388 = DAT_004aa81c;
  dVar2 = (double)(DAT_004aa59c - DAT_004aa81c);
  DAT_004a6444 = FUN_0041bb10(DAT_004a70e8 - DAT_004aa594,DAT_004aa59c - DAT_004aa81c);
  DAT_004a645c = (undefined4)(longlong)SQRT(dVar2 * dVar2 + dVar1 * dVar1);
  if (DAT_004a864c == 1) {
    fVar7 = FUN_00420b70(DAT_004aa294,DAT_004aa388,0);
  }
  else {
    fVar7 = FUN_00420c40(DAT_004aa294,DAT_004aa388,0);
  }
  if ((((fVar7 < (float10)_DAT_004850c8) && (DAT_004a5a4c == 0)) && (DAT_00491194 != 8)) &&
     (DAT_004a4958 < 2)) {
    param_1 = param_1 + -1;
    FUN_004201a0(param_1);
  }
  if ((DAT_004a5a4c == 1) || (DAT_00491194 == 9)) {
    iVar4 = DAT_004abc80 + iVar5 * -0x5a;
  }
  else {
    iVar4 = FUN_00415a20(0x3c);
    iVar4 = (iVar4 + -0x78) * iVar5 + DAT_004abc80;
  }
  if (DAT_00491194 == 10) {
    iVar4 = DAT_004abc80 + iVar5 * -0x6e;
  }
  if ((DAT_00491160 == 1) && (0xe < DAT_0049118c)) {
    iVar4 = DAT_004abc80 + iVar5 * -5;
    local_14 = DAT_004ab184;
  }
  FUN_00420b20(DAT_004aa594,DAT_004aa59c,local_14,iVar4);
  DAT_004aa38c = DAT_004a70e8;
  DAT_004aa588 = DAT_004aa81c;
  _DAT_004a6448 = FUN_00413cb0(iVar4);
  _DAT_004a6460 = local_14;
  if (DAT_004a864c == 1) {
    fVar7 = FUN_00420b70(DAT_004aa38c,DAT_004aa588,0);
  }
  else {
    fVar7 = FUN_00420c40(DAT_004aa38c,DAT_004aa588,0);
  }
  if ((float10)_DAT_004850c8 <= fVar7) {
LAB_00420664:
    if (DAT_004a5a4c != 0) goto LAB_004206bc;
    FUN_00420b20(DAT_004aa594,DAT_004aa59c,DAT_004ab184,DAT_004abc80 + iVar5 * -0xb4);
    iVar4 = DAT_004abc80 + iVar5 * -0xb4;
  }
  else {
    if (DAT_004a5a4c == 0) {
      if ((DAT_00491194 != 8) && (DAT_004a4958 < 2)) {
        param_1 = param_1 + -1;
        FUN_004201a0(param_1);
      }
      goto LAB_00420664;
    }
LAB_004206bc:
    FUN_00420b20(DAT_004aa594,DAT_004aa59c,DAT_004ab184,DAT_004abc80 + iVar5 * -200);
    iVar4 = DAT_004abc80 + iVar5 * -200;
  }
  DAT_004aa288 = DAT_004a70e8;
  DAT_004aa384 = DAT_004aa81c;
  DAT_004a644c = FUN_00413cb0(iVar4);
  DAT_004a6464 = DAT_004ab184;
  if (DAT_004a864c == 1) {
    fVar7 = FUN_00420b70(DAT_004aa288,DAT_004aa384,0);
  }
  else {
    fVar7 = FUN_00420c40(DAT_004aa288,DAT_004aa384,0);
  }
  if (((float10)_DAT_004850c8 <= fVar7) || (DAT_004a5a4c != 0)) {
LAB_00420790:
    if (DAT_00491194 != 8) {
      iVar4 = DAT_004a70f8 * 7 + DAT_004aa288;
      DAT_004a4be0 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
      iVar4 = DAT_004a72c8 * 7 + DAT_004aa384;
      DAT_004a4f84 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
      goto LAB_00420831;
    }
  }
  else if (DAT_00491194 != 8) {
    if (DAT_004a4958 < 2) {
      FUN_004201a0(param_1 + -1);
    }
    goto LAB_00420790;
  }
  DAT_004a4be0 = (DAT_004aa288 + DAT_004a70f8 * 0x14) / 0x15;
  DAT_004a4f84 = (DAT_004aa384 + DAT_004a72c8 * 0x14) / 0x15;
LAB_00420831:
  FUN_00420b20(DAT_004aa294,DAT_004aa388,iVar3,DAT_004abc80 + iVar6);
  DAT_004a8a54 = DAT_004a70e8;
  DAT_004a8a84 = DAT_004aa81c;
  FUN_00420b20(DAT_004aa294,DAT_004aa388,(iVar3 * 2) / 3,DAT_004abc80);
  _DAT_004a8a58 = DAT_004a70e8;
  _DAT_004a8a88 = DAT_004aa81c;
  FUN_00420b20(DAT_004aa294,DAT_004aa388,iVar3,DAT_004abc80 + iVar5 * -0x3c);
  _DAT_004a8a5c = DAT_004a70e8;
  _DAT_004a8a8c = DAT_004aa81c;
  FUN_00420b20(DAT_004aa38c,DAT_004aa588,iVar3,DAT_004abc80 + iVar5 * -0x37);
  _DAT_004a8a90 = DAT_004aa81c;
  _DAT_004a8a60 = DAT_004a70e8;
  FUN_00420b20(DAT_004aa38c,DAT_004aa588,iVar3,DAT_004abc80 + iVar5 * -0x87);
  _DAT_004a8a64 = DAT_004a70e8;
  _DAT_004a8a94 = DAT_004aa81c;
  FUN_00420b20(DAT_004aa288,DAT_004aa384,iVar3,DAT_004abc80 + iVar5 * -0x73);
  DAT_004a8a68 = DAT_004a70e8;
  DAT_004a8a98 = DAT_004aa81c;
  FUN_00420b20(DAT_004aa288,DAT_004aa384,iVar3,DAT_004abc80 + iVar5 * 0x87);
  _DAT_004a8a6c = DAT_004a70e8;
  _DAT_004a8a9c = DAT_004aa81c;
  if ((DAT_00491160 == 1) && (DAT_0049118c < 0xf)) {
    DAT_004aa38c = DAT_004aa288;
    DAT_004aa588 = DAT_004aa384;
    _DAT_004a8a90 = DAT_004a8a98;
    _DAT_004a8a94 = DAT_004a8a98;
    _DAT_004a8a60 = DAT_004a8a68;
    _DAT_004a8a64 = DAT_004a8a68;
    _DAT_004a6448 = DAT_004a644c;
    _DAT_004a6460 = DAT_004a6464;
  }
  _DAT_004a52f8 = (double)DAT_004aa594;
  _DAT_004a60b8 = (double)DAT_004aa59c;
  _DAT_004a5300 = (double)DAT_004a70f8;
  _DAT_004a60c0 = (double)DAT_004a72c8;
  _DAT_004a5308 = (double)DAT_004aa294;
  DAT_004a8a74 = DAT_004a8a54;
  _DAT_004a60c8 = (double)DAT_004aa388;
  _DAT_004a5310 = (double)DAT_004aa38c;
  DAT_004a8aa4 = DAT_004a8a84;
  _DAT_004a60d0 = (double)DAT_004aa588;
  _DAT_004a5318 = (double)DAT_004aa288;
  _DAT_004a60d8 = (double)DAT_004aa384;
  _DAT_004a8a70 = (DAT_004aa594 + DAT_004a70f8) / 2;
  _DAT_004a8aa0 = (DAT_004a72c8 + DAT_004aa59c) / 2;
  return;
}


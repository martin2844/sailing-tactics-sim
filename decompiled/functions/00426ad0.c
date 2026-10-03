
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00426ad0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = *(int *)(&DAT_004a5420 + param_1 * 4);
  iVar6 = (-(uint)(DAT_004ac9a8 != 1) & 2) - 1;
  if ((iVar7 == 6) || (iVar7 == 7)) {
    if (DAT_00491140 < param_1) {
      *(undefined4 *)(&DAT_004a41f0 + param_1 * 4) = DAT_004a5b80;
    }
    uVar1 = DAT_004a8a54;
    if (((iVar7 == 7) && (DAT_004ac950 == 1)) && (*(int *)(&DAT_004a72d8 + param_1 * 4) == 0)) {
      *(undefined4 *)(&DAT_004a6f48 + param_1 * 4) = DAT_004a8a84;
      bVar8 = DAT_004ac940 == 1;
      *(undefined4 *)(&DAT_004a5420 + param_1 * 4) = 0;
      *(undefined4 *)(&DAT_004a4888 + param_1 * 4) = uVar1;
      *(undefined4 *)(&DAT_004a72d8 + param_1 * 4) = 1;
      if (bVar8) {
        DAT_00491160 = 1;
        FUN_004201a0(10);
        iVar7 = iVar6 * 0x5a;
        DAT_004aa998 = 0x96;
        FUN_00420b20(DAT_004aa594,DAT_004aa59c,0x96,DAT_004abc80 + iVar7);
        DAT_004a70f8 = DAT_004a70e8;
        DAT_004a72c8 = DAT_004aa81c;
        _DAT_004a6440 = FUN_00413cb0(DAT_004abc80 + iVar7);
        uVar2 = DAT_004a8a98;
        uVar1 = DAT_004a8a68;
        _DAT_004a6458 = DAT_004aa998;
        _DAT_004a5300 = (double)DAT_004a70f8;
        _DAT_004a8a70 = (DAT_004aa594 + DAT_004a70f8) / 2;
        _DAT_004a60c0 = (double)DAT_004a72c8;
        _DAT_004a8aa0 = (DAT_004a72c8 + DAT_004aa59c) / 2;
        if (1 < DAT_0049118c) {
          iVar7 = 0;
          puVar4 = &DAT_004a6f50;
          iVar5 = DAT_0049118c + -1;
          do {
            if ((*(int *)((int)&DAT_004a5428 + iVar7) < 6) &&
               (2 < *(int *)((int)&DAT_004a5428 + iVar7))) {
              *(undefined4 *)((int)&DAT_004a5428 + iVar7) = 6;
              *(undefined4 *)((int)&DAT_004a4890 + iVar7) = uVar1;
              *puVar4 = uVar2;
            }
            iVar7 = iVar7 + 4;
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
    }
  }
  if ((2 < DAT_004911c0) && (0x82 < DAT_004aa998)) {
    DAT_004aa998 = 0x96;
    iVar6 = iVar6 * 0x5a;
    FUN_00420b20(DAT_004aa594,DAT_004aa59c,0x96,DAT_004abc80 + iVar6);
    DAT_004a70f8 = DAT_004a70e8;
    DAT_004a72c8 = DAT_004aa81c;
    _DAT_004a6440 = FUN_00413cb0(DAT_004abc80 + iVar6);
    _DAT_004a6458 = DAT_004aa998;
    _DAT_004a5300 = (double)DAT_004a70f8;
    _DAT_004a8a70 = (DAT_004a70f8 + DAT_004aa594) / 2;
    _DAT_004a60c0 = (double)DAT_004a72c8;
    _DAT_004a8aa0 = (DAT_004aa59c + DAT_004a72c8) / 2;
  }
  iVar7 = *(int *)(&DAT_004a5420 + param_1 * 4);
  if (((iVar7 == 7) && (DAT_004ac950 == 1)) && (*(int *)(&DAT_004a72d8 + param_1 * 4) == 1)) {
    *(undefined4 *)(&DAT_004a72d8 + param_1 * 4) = 2;
  }
  iVar6 = DAT_004a495c;
  if (iVar7 == 8) {
    *(undefined4 *)(&DAT_004a72d8 + param_1 * 4) = 0;
    if (iVar6 == 0) {
      DAT_004a4be8 = DAT_004a4be8 + 1;
      DAT_004ab8b4 = DAT_004a5b80;
    }
    if (0 < iVar6) {
      DAT_004a4be8 = DAT_0049118c + 1;
    }
  }
  iVar7 = iVar7 + 1;
  *(int *)(&DAT_004a5420 + param_1 * 4) = iVar7;
  uVar1 = *(undefined4 *)(&DAT_004a8a80 + iVar7 * 4);
  *(undefined4 *)(&DAT_004a4888 + param_1 * 4) = *(undefined4 *)(&DAT_004a8a50 + iVar7 * 4);
  *(undefined4 *)(&DAT_004a6f48 + param_1 * 4) = uVar1;
  uVar1 = DAT_004a8aa4;
  if (8 < iVar7) {
    *(undefined4 *)(&DAT_004a4888 + param_1 * 4) = DAT_004a8a74;
    *(undefined4 *)(&DAT_004a6f48 + param_1 * 4) = uVar1;
    if (8 < iVar7) {
      bVar8 = DAT_004a4be8 == 1;
      *(int *)(&DAT_004a7648 + param_1 * 4) = DAT_004a4be8;
      if ((bVar8) && (DAT_004ac9c0 == 0)) {
        PlaySoundA((LPCSTR)0x8c,DAT_004ac1d4,0x40005);
      }
      if (((param_1 <= DAT_00491140) && (DAT_004ac9c0 == 0)) && (1 < DAT_004a4be8)) {
        PlaySoundA((LPCSTR)0x8e,DAT_004ac1d4,0x40005);
      }
      iVar6 = DAT_004ac960;
      uVar1 = DAT_004a5b80;
      iVar7 = DAT_00491140;
      if (param_1 == 1) {
        DAT_004aa6f8 = DAT_0049116c;
        DAT_004ac858 = DAT_00491170;
      }
      if ((param_1 == 2) && (DAT_00491140 == 2)) {
        DAT_004aa6f8 = DAT_0049116c;
        DAT_004ac858 = DAT_00491170;
      }
      bVar8 = true;
      if (((0 < *(int *)(&DAT_004a7648 + param_1 * 4)) && (DAT_004ac960 < 1)) &&
         (param_1 <= DAT_00491140)) {
        *(undefined4 *)(&DAT_004a89c0 + param_1 * 4) = 0xb;
        *(undefined4 *)(&DAT_004abf18 + param_1 * 4) = uVar1;
      }
      if (((0 < DAT_004a764c) && (iVar6 == 1)) && (iVar7 == 1)) {
        DAT_004ac93c = 1;
        DAT_004ac944 = DAT_004ac944 + 1;
      }
      if (0 < DAT_0049118c) {
        piVar3 = &DAT_004a764c;
        iVar7 = DAT_0049118c;
        do {
          if (*piVar3 == 0) {
            bVar8 = false;
          }
          piVar3 = piVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (bVar8) {
        DAT_004ac93c = 1;
        DAT_004ac944 = DAT_004ac944 + 1;
      }
    }
  }
  if ((DAT_004ac940 == 1) && (DAT_004ac93c == 1)) {
    DAT_00491160 = 0;
  }
  return;
}


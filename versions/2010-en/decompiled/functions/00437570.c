
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00437570(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  LPCSTR pszSound;
  int local_4;
  
  iVar3 = param_1;
  iVar6 = *(int *)(&DAT_004f8538 + param_1 * 4);
  iVar4 = (-(uint)(DAT_0053646c != 1) & 2) - 1;
  DAT_004da214 = iVar4;
  if (((iVar6 == 6) || (iVar6 == 7)) && (DAT_004da140 < param_1)) {
    *(undefined4 *)(&DAT_004f4350 + param_1 * 4) = DAT_004f8cd0;
  }
  iVar12 = DAT_004da194;
  if (((iVar6 == 7) && (DAT_00536408 == 1)) && (*(int *)(&DAT_004fe2b0 + param_1 * 4) == 0)) {
    *(undefined4 *)(&DAT_004f8538 + param_1 * 4) = 0;
    *(undefined4 *)(&DAT_004fe2b0 + param_1 * 4) = 1;
    uVar1 = *(undefined4 *)(&DAT_00511784 + param_1 * 0x28);
    *(undefined4 *)(&DAT_004fc350 + param_1 * 4) = *(undefined4 *)(&DAT_00511d04 + param_1 * 0x28);
    bVar13 = DAT_005363f8 == 1;
    *(undefined4 *)(&DAT_004f4d78 + param_1 * 4) = uVar1;
    iVar12 = DAT_004da194;
    if ((bVar13) && (param_1 == 1)) {
      DAT_004da168 = 1;
      FUN_0042dea0(2);
      DAT_00523598 = DAT_004da194 * 3 + 0x28;
      FUN_0042f220(DAT_00536410,DAT_00536414,DAT_00523598,DAT_00535208 + DAT_004da214 * 0x5a);
      DAT_004fe2a0 = DAT_00523180;
      DAT_004fe094 = DAT_004fe080;
      _DAT_004fb518 = FUN_0041bc20(DAT_00535208 + DAT_004da214 * 0x5a);
      iVar12 = DAT_004da194;
      _DAT_004fb530 = DAT_00523598;
      if (0 < DAT_004da194) {
        iVar5 = DAT_00536410 + DAT_004fe094;
        iVar6 = DAT_004fe2a0 + DAT_00536414;
        iVar8 = 0;
        iVar4 = DAT_004da194;
        do {
          *(int *)((int)&DAT_005117c8 + iVar8) = iVar5 / 2;
          *(int *)((int)&DAT_00511d48 + iVar8) = iVar6 / 2;
          iVar8 = iVar8 + 0x28;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      uVar2 = DAT_00511d40;
      uVar1 = DAT_005117c0;
      _DAT_004fb078 = (double)DAT_004fe2a0;
      _DAT_004f83a8 = (double)DAT_004fe094;
      iVar4 = DAT_004da214;
      if (1 < iVar12) {
        param_1 = iVar12 + -1;
        puVar10 = &DAT_004fc358;
        iVar6 = 0;
        do {
          if ((*(int *)((int)&DAT_004f8540 + iVar6) < 6) &&
             (2 < *(int *)((int)&DAT_004f8540 + iVar6))) {
            *(undefined4 *)((int)&DAT_004f8540 + iVar6) = 6;
            *(undefined4 *)((int)&DAT_004f4d80 + iVar6) = uVar1;
            *puVar10 = uVar2;
          }
          iVar6 = iVar6 + 4;
          puVar10 = puVar10 + 1;
          param_1 = param_1 + -1;
          iVar4 = DAT_004da214;
        } while (param_1 != 0);
      }
    }
  }
  if ((DAT_005363f8 == 1) && (DAT_004da1cc == 5)) {
    FUN_0042dea0(3);
    iVar4 = DAT_004da214;
    iVar12 = DAT_004da194;
  }
  if (((DAT_005363f8 == 0) && (DAT_0053527c == 0)) && (*(int *)(&DAT_004f8538 + iVar3 * 4) == 2)) {
    DAT_00523598 = iVar12 * 3 + 0x28;
    FUN_0042f220(DAT_00536410,DAT_00536414,DAT_00523598,DAT_00535208 + iVar4 * 0x5a);
    DAT_004fe2a0 = DAT_00523180;
    DAT_004fe094 = DAT_004fe080;
    _DAT_004f83a8 = (double)DAT_004fe080;
    *(int *)(&DAT_005117a0 + iVar3 * 0x28) = (DAT_004fe080 + DAT_00536410) / 2;
    _DAT_004fb078 = (double)DAT_00523180;
    *(int *)(&DAT_00511d20 + iVar3 * 0x28) = (DAT_00536414 + DAT_004fe2a0) / 2;
    iVar4 = DAT_004da214;
  }
  if ((DAT_0053527c == 1) &&
     (((((DAT_00536408 == 0 || (4 < DAT_004da1cc)) || (0 < DAT_004fe63c)) ||
       (((DAT_004da188 == 7 && (0 < DAT_004fe2b4)) && (1 < DAT_004f853c)))) && (1 < DAT_004da1cc))))
  {
    DAT_005364e0 = 1;
    DAT_004da1e4 = ((DAT_004da194 < 0x10) - 1 & 2) + 4;
    if (DAT_004da194 < 3) {
      iVar6 = DAT_004f7f94 + 0x5a;
    }
    else {
      iVar6 = DAT_004f7f94 + iVar4 * 0x5a;
    }
    iVar6 = FUN_0041bc20(iVar6);
    FUN_0042f220(DAT_00536410,DAT_00536414,DAT_004da194 * 3 + 0x28,iVar6);
    DAT_004fe094 = DAT_004fe080;
    DAT_004fe2a0 = DAT_00523180;
    iVar4 = (DAT_004fe080 + DAT_00536410) / 2;
    _DAT_004f83c0 = (double)iVar4;
    iVar6 = (DAT_00536414 + DAT_00523180) / 2;
    _DAT_004fb090 = (double)iVar6;
    _DAT_004f83a8 = (double)DAT_004fe080;
    _DAT_004fb078 = (double)DAT_00523180;
    DAT_005229c8 = iVar4;
    DAT_00522ac4 = iVar6;
    if (0 < DAT_004da194) {
      param_1 = (int)&DAT_004fc354;
      iVar12 = 0;
      local_4 = DAT_004da194;
      do {
        iVar5 = DAT_004da140;
        if ((*(int *)((int)&DAT_004f853c + iVar12) == 6) && (0xf < DAT_004da194)) {
          iVar9 = iVar3 * 0x28;
          *(int *)(&DAT_00511798 + iVar9) = iVar4;
          *(int *)(&DAT_00511d18 + iVar9) = iVar6;
          iVar11 = DAT_00536414;
          iVar8 = DAT_00523180;
          if ((iVar5 < iVar3) && (0 < *(int *)(&DAT_004fe2b0 + iVar3 * 4))) {
            if (*(int *)(&DAT_00522ff0 + iVar3 * 4) == -1) {
              *(int *)(&DAT_00511798 + iVar9) = (DAT_004fe080 + iVar4) / 2;
              iVar11 = iVar8;
            }
            else {
              *(int *)(&DAT_00511798 + iVar9) = (DAT_00536410 + iVar4) / 2;
            }
            *(int *)(&DAT_00511d18 + iVar9) = (iVar11 + iVar6) / 2;
          }
          uVar1 = *(undefined4 *)(&DAT_00511d18 + iVar9);
          *(undefined4 *)((int)&DAT_004f4d7c + iVar12) = *(undefined4 *)(&DAT_00511798 + iVar9);
          *(undefined4 *)param_1 = uVar1;
        }
        if ((2 < *(int *)((int)&DAT_004f853c + iVar12)) && (DAT_004da194 < 0xb)) {
          *(int *)((int)&DAT_004f4d7c + iVar12) = iVar4;
          *(int *)(&DAT_00511790 + iVar3 * 0x28) = iVar4;
          *(int *)(&DAT_00511d10 + iVar3 * 0x28) = iVar6;
          *(int *)param_1 = iVar6;
        }
        iVar12 = iVar12 + 4;
        param_1 = param_1 + 4;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
  }
  iVar4 = DAT_004da1e4;
  iVar6 = *(int *)(&DAT_004f8538 + iVar3 * 4);
  if (((iVar6 == DAT_004da1e4 + -1) && (DAT_00536408 == 1)) &&
     (*(int *)(&DAT_004fe2b0 + iVar3 * 4) == 1)) {
    *(undefined4 *)(&DAT_004fe2b0 + iVar3 * 4) = 2;
  }
  iVar12 = DAT_004f6a58;
  if (iVar6 == iVar4) {
    *(undefined4 *)(&DAT_004fe2b0 + iVar3 * 4) = 0;
    if ((iVar12 == 0) && (DAT_004f6d64 = DAT_004f6d64 + 1, iVar3 <= DAT_004da140)) {
      DAT_00534d64 = DAT_004f8cd0;
    }
    if (0 < iVar12) {
      DAT_004f6d64 = DAT_004da194 + 1;
    }
  }
  iVar6 = iVar6 + 1;
  *(int *)(&DAT_004f8538 + iVar3 * 4) = iVar6;
  iVar12 = (iVar6 + iVar3 * 10) * 4;
  uVar1 = *(undefined4 *)(&DAT_00511780 + iVar12);
  *(undefined4 *)(&DAT_004fc350 + iVar3 * 4) = *(undefined4 *)(&DAT_00511d00 + iVar12);
  iVar12 = DAT_004da140;
  *(undefined4 *)(&DAT_004f4d78 + iVar3 * 4) = uVar1;
  if (iVar12 < iVar3) {
    *(undefined4 *)(&DAT_004f4350 + iVar3 * 4) = DAT_004f8cd0;
  }
  if (iVar4 < iVar6) {
    if (DAT_0053527c == 0) {
      uVar1 = *(undefined4 *)(&DAT_00511d24 + iVar3 * 0x28);
      *(undefined4 *)(&DAT_004f4d78 + iVar3 * 4) = *(undefined4 *)(&DAT_005117a4 + iVar3 * 0x28);
      *(undefined4 *)(&DAT_004fc350 + iVar3 * 4) = uVar1;
    }
    else {
      iVar6 = FUN_0041e000(0x3c);
      *(int *)(&DAT_004f4d78 + iVar3 * 4) = iVar6 + -0x1e + DAT_004f6d38;
      iVar6 = FUN_0041e000(0x3c);
      *(int *)(&DAT_004fc350 + iVar3 * 4) = iVar6 + -0x1e + DAT_004f7f88;
      iVar4 = DAT_004da1e4;
    }
  }
  if (iVar4 < *(int *)(&DAT_004f8538 + iVar3 * 4)) {
    bVar13 = DAT_004f6d64 == 1;
    *(int *)(&DAT_004fe638 + iVar3 * 4) = DAT_004f6d64;
    if ((bVar13) && (DAT_00536484 == 0)) {
      if (DAT_005364c8 == 0) {
        pszSound = (LPCSTR)0x8c;
      }
      else {
        pszSound = (LPCSTR)0x8e;
      }
      PlaySoundA(pszSound,DAT_005359c8,0x40005);
    }
    if (((iVar3 <= DAT_004da140) && (DAT_00536484 == 0)) && (1 < DAT_004f6d64)) {
      PlaySoundA((LPCSTR)0x8e,DAT_005359c8,0x40005);
    }
    iVar4 = DAT_00536424;
    uVar1 = DAT_004f8cd0;
    iVar6 = DAT_004da140;
    if (iVar3 == 1) {
      DAT_00522f20 = DAT_004da174;
      DAT_005362f0 = DAT_004da178;
    }
    if ((iVar3 == 2) && (DAT_004da140 == 2)) {
      DAT_00522f20 = DAT_004da174;
      DAT_005362f0 = DAT_004da178;
    }
    bVar13 = true;
    if (((0 < *(int *)(&DAT_004fe638 + iVar3 * 4)) && (DAT_00536424 < 1)) && (iVar3 <= DAT_004da140)
       ) {
      *(undefined4 *)(&DAT_005116e0 + iVar3 * 4) = 0xb;
      *(undefined4 *)(&DAT_00535620 + iVar3 * 4) = uVar1;
    }
    if (((0 < DAT_004fe63c) && (iVar4 == 1)) && (iVar6 == 1)) {
      DAT_005363f4 = 1;
      DAT_005363fc = DAT_005363fc + 1;
    }
    if (0 < DAT_004da194) {
      piVar7 = &DAT_004fe63c;
      iVar6 = DAT_004da194;
      do {
        if (*piVar7 == 0) {
          bVar13 = false;
        }
        piVar7 = piVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (bVar13) {
      DAT_005363f4 = 1;
      DAT_005363fc = DAT_005363fc + 1;
    }
  }
  if ((DAT_005363f8 == 1) && (DAT_005363f4 == 1)) {
    DAT_004da168 = 0;
  }
  return;
}


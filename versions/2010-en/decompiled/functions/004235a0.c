
void __cdecl FUN_004235a0(int *param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((((DAT_005363bc != 1) && (DAT_00535884 < param_4)) && (param_3 * DAT_005363e0 < 2)) &&
     ((DAT_0053652c != 1 || (DAT_00536458 < 1)))) {
    if (DAT_005363b8 == 1) {
      FUN_00423980(param_1,param_2,param_3);
      return;
    }
    if (param_3 < 2) {
      uVar3 = DAT_004fdfd0 / 2 >> 0x1f;
      iVar2 = (DAT_004fdfd0 / 2 ^ uVar3) - uVar3;
    }
    else {
      iVar2 = 0;
    }
    if (DAT_004fdfd0 < 1) {
      DAT_00522fc0 = (((DAT_005228fc + DAT_005228e4) / 2) * iVar2 + DAT_005228e4) / (iVar2 + 1);
      DAT_00535560 = (((DAT_005229e4 + DAT_005229fc) / 2) * iVar2 + DAT_005229e4) / (iVar2 + 1);
    }
    else {
      DAT_00522fc0 = (((DAT_0052291c + DAT_005228e4) / 2) * iVar2 + DAT_005228e4) / (iVar2 + 1);
      DAT_00535560 = (((DAT_005229e4 + DAT_00522a1c) / 2) * iVar2 + DAT_005229e4) / (iVar2 + 1);
    }
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    if (DAT_00536528 == 1) {
      FUN_004b4d9d(param_1,(int *)&param_2,(DAT_005228e0 + DAT_005228e4) / 2,
                   (DAT_005229e4 + DAT_005229e0) / 2);
      if (DAT_00522f1c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_00522f1c);
      }
    }
    else {
      FUN_004b4d9d(param_1,(int *)&param_2,DAT_005228e0,DAT_005229e0);
    }
    if (DAT_0053652c == 0) {
      CDC::LineTo(param_1,DAT_00522fc0,DAT_00535560);
    }
    if (DAT_0053652c == 1) {
      FUN_004b4d9d(param_1,(int *)&param_2,
                   (DAT_005228f8 + (DAT_00522920 + DAT_0052291c) * 2 + DAT_005228fc) / 6,
                   (DAT_005229f8 + (DAT_00522a20 + DAT_00522a1c) * 2 + DAT_005229fc) / 6);
      iVar2 = DAT_00522a1c + DAT_00535560 * 3;
      iVar1 = DAT_0052291c + DAT_00522fc0 * 3;
      CDC::LineTo(param_1,(int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2,
                  (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
      FUN_004b4d9d(param_1,(int *)&param_2,
                   (DAT_00522920 + (DAT_005228f8 + DAT_005228fc) * 2 + DAT_0052291c) / 6,
                   (DAT_00522a20 + (DAT_005229f8 + DAT_005229fc) * 2 + DAT_00522a1c) / 6);
      iVar2 = DAT_005229fc + DAT_00535560 * 3;
      iVar1 = DAT_005228fc + DAT_00522fc0 * 3;
      CDC::LineTo(param_1,(int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2,
                  (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
      (**(code **)(*param_1 + 0x2c))(param_1,7);
      iVar2 = DAT_00522a1c + DAT_00535560 * 3;
      iVar1 = DAT_0052291c + DAT_00522fc0 * 3;
      FUN_004b4d9d(param_1,(int *)&param_2,(int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2,
                   (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
      iVar2 = DAT_005229fc + DAT_00535560 * 3;
      iVar1 = DAT_005228fc + DAT_00522fc0 * 3;
      CDC::LineTo(param_1,(int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2,
                  (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
    }
    (**(code **)(*param_1 + 0x2c))(param_1,7);
  }
  return;
}


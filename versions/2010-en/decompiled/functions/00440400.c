
void __cdecl
FUN_00440400(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *local_b6c;
  int local_b68;
  int aiStack_b60 [2];
  int iStack_b58;
  uint auStack_b54 [10];
  int iStack_b2c;
  int iStack_ae4;
  int aiStack_880 [10];
  int iStack_858;
  int iStack_810;
  uint auStack_5ac [182];
  uint auStack_2d4 [181];
  
  if (DAT_0050040c == 0) {
    FUN_0043e730(0,(double)DAT_00535bc8,(double)DAT_004f3858,param_5,0);
    if ((DAT_004fed58 < param_8) && (param_6 < DAT_004fed58)) {
      local_b6c = (int *)DAT_00523660;
    }
    else {
      local_b6c = (int *)0x0;
    }
  }
  if (param_3 <= param_4) {
    puVar10 = (uint *)(&DAT_004fed58 + param_3);
    iVar12 = param_3;
    do {
      FUN_0043e730(iVar12,(double)(int)(&DAT_004fb6b8)[iVar12],(double)(int)(&DAT_004fbc38)[iVar12],
                   param_5,5);
      uVar7 = (&DAT_00523660)[iVar12];
      auStack_2d4[iVar12] = *puVar10;
      *(undefined4 *)(&DAT_004f3c10 + iVar12 * 4) = DAT_00535ff4;
      auStack_5ac[iVar12 + 1] = uVar7;
      if ((int)uVar7 < param_2) {
        auStack_5ac[iVar12 + 1] = param_2;
      }
      iVar12 = iVar12 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar12 <= param_4);
  }
  iVar12 = param_3 + 1;
  if (iVar12 <= param_4) {
    puVar10 = auStack_2d4 + iVar12;
    iVar9 = iVar12 * 2;
    do {
      if ((((((DAT_004f69b8 != 4) ||
             (((uVar7 = iVar9 - DAT_004fbac4 >> 0x1f,
               6 < (int)((iVar9 - DAT_004fbac4 ^ uVar7) - uVar7) &&
               (uVar7 = iVar9 - DAT_004fbac8 >> 0x1f,
               5 < (int)((iVar9 - DAT_004fbac8 ^ uVar7) - uVar7))) &&
              (uVar7 = iVar9 - DAT_004fbacc >> 0x1f,
              5 < (int)((iVar9 - DAT_004fbacc ^ uVar7) - uVar7))))) &&
            ((DAT_004f69b8 != 5 ||
             ((uVar7 = iVar9 - DAT_004fbac4 >> 0x1f,
              9 < (int)((iVar9 - DAT_004fbac4 ^ uVar7) - uVar7) &&
              (uVar7 = iVar9 - DAT_004fbac8 >> 0x1f,
              9 < (int)((iVar9 - DAT_004fbac8 ^ uVar7) - uVar7))))))) &&
           ((DAT_004f69b8 != 6 ||
            (((iVar9 < 0x5b || (0x10d < iVar9)) && ((3 < iVar9 && (iVar9 < 0x165)))))))) &&
          ((DAT_004f69b8 != 7 ||
           (((0x59 < iVar9 && (iVar9 < 0x10f)) && ((iVar9 < 0xba || (0xc2 < iVar9)))))))) &&
         ((uVar7 = puVar10[-1], (int)((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f)) < 31000
          && (uVar1 = *puVar10, (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) < 31000))
         )) {
        uVar2 = auStack_5ac[iVar12];
        if (((int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) < 31000) &&
           (((uVar3 = auStack_5ac[iVar12 + 1],
             (int)((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)) < 31000 &&
             (uVar8 = (int)(&DAT_004f3c0c)[iVar12] >> 0x1f,
             (int)(((&DAT_004f3c0c)[iVar12] ^ uVar8) - uVar8) < 0xa0)) &&
            (uVar8 = (int)*(uint *)(&DAT_004f3c10 + iVar12 * 4) >> 0x1f,
            (int)((*(uint *)(&DAT_004f3c10 + iVar12 * 4) ^ uVar8) - uVar8) < 0xa0)))) {
          FUN_00440b70(param_1,uVar7,uVar2,uVar1,uVar3,param_10,iVar12,param_6,param_7,param_8,
                       param_9,param_10,(int)local_b6c);
        }
      }
      iVar12 = iVar12 + 1;
      iVar9 = iVar9 + 2;
      puVar10 = puVar10 + 1;
    } while (iVar12 <= param_4);
  }
  if ((DAT_004f69b8 < 2) && (DAT_004f8b78 == 1)) {
    iVar12 = (param_9 - param_10) * (3 - DAT_005359d8);
    if (param_3 <= param_4) {
      puVar10 = auStack_5ac + param_3 + 1;
      iVar9 = param_3;
      do {
        uVar7 = *puVar10;
        uVar1 = auStack_2d4[iVar9];
        (&DAT_004f8028)[iVar9] = uVar1;
        auStack_b54[iVar9 + 1] = uVar1;
        piVar13 = &DAT_00512d74 + iVar9;
        puVar10 = puVar10 + 1;
        iVar9 = iVar9 + 1;
        iVar11 = (uVar7 - (int)((uVar7 - param_10) * *piVar13) / iVar12) + -1;
        *(int *)(&DAT_004faa5c + iVar9 * 4) = iVar11;
        aiStack_880[iVar9] = iVar11;
      } while (iVar9 <= param_4);
    }
    if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
      FUN_00484270(param_1);
    }
    else {
      if (DAT_004fe174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe174);
      }
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
    }
    pcVar4 = *(code **)(*param_1 + 0x2c);
    (*pcVar4)(param_1,7);
    if ((DAT_00536450 == 1) && ((*pcVar4)(param_1,7), DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    FUN_00433710(param_1);
    if ((DAT_005363e0 == 0) && (DAT_004da174 < 0xd)) {
      FUN_0043e730(0,(double)DAT_00535bc8,(double)DAT_004f3858,param_5,0);
      iVar9 = (iStack_810 + iStack_858) / 2;
      iVar11 = (iStack_b2c + iStack_ae4) / 2;
      if (param_3 <= param_4) {
        piVar13 = aiStack_880 + param_3 + 1;
        iVar6 = iVar12;
        do {
          if (DAT_004f7084 != (HGDIOBJ)0x0) {
            SelectObject((HDC)param_1[1],DAT_004f7084);
          }
          local_b6c = &DAT_00512d74 + param_3;
          local_b68 = 2;
          do {
            iVar5 = *local_b6c;
            if (iVar5 < 0x1a) {
              iVar12 = (int)(auStack_b54[param_3] + auStack_b54[param_3 + 1] * 3 + iVar11) / 5;
              iVar6 = (piVar13[-1] + *piVar13 * 3 + iVar9) / 5;
              if (0x19 < iVar5) goto LAB_00440990;
            }
            else {
LAB_00440990:
              if ((int)(&DAT_00512d78)[param_3] < 0x33) {
                iVar12 = (int)(auStack_b54[param_3] + iVar11 + auStack_b54[param_3 + 1]) / 3;
                iVar6 = (piVar13[-1] + iVar9 + *piVar13) / 3;
              }
            }
            if ((0x32 < iVar5) && ((int)(&DAT_00512d78)[param_3] < 0x4b)) {
              iVar12 = auStack_b54[param_3] + iVar11 * 2 + auStack_b54[param_3 + 1];
              iVar12 = (int)(iVar12 + (iVar12 >> 0x1f & 3U)) >> 2;
              iVar6 = piVar13[-1] + iVar9 * 2 + *piVar13;
              iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
            }
            if (0x4a < iVar5) {
              iVar12 = (int)(iVar11 + auStack_b54[param_3] * 3 + auStack_b54[param_3 + 1]) / 5;
              iVar6 = (iVar9 + piVar13[-1] * 3 + *piVar13) / 5;
            }
            if (iVar12 != iVar6) {
              if ((DAT_004fe2a8 / 100 + param_10 < iVar6) && (iVar6 < DAT_004fe2a8 / 0xc)) {
                FUN_004b4d9d(param_1,aiStack_b60,iVar12,iVar6);
                CDC::LineTo(param_1,iVar12,iVar6 + -1);
              }
              if (DAT_004fe2a8 / 0xc <= iVar6) {
                FUN_004b4d9d(param_1,&iStack_b58,iVar12 + -1,iVar6);
                CDC::LineTo(param_1,iVar12,iVar6 + -2);
                CDC::LineTo(param_1,iVar12 + 1,iVar6);
              }
            }
            local_b6c = local_b6c + 1;
            local_b68 = local_b68 + -1;
          } while (local_b68 != 0);
          param_3 = param_3 + 1;
          piVar13 = piVar13 + 1;
        } while (param_3 <= param_4);
      }
    }
  }
  return;
}


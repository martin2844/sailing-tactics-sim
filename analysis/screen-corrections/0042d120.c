
void __cdecl
FUN_0042d120(CDC *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,int param_8,int param_9,CDC *param_10)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  int *local_b6c;
  int local_b68;
  int aiStack_b60 [2];
  int iStack_b58;
  uint auStack_b54 [181];
  uint auStack_880 [182];
  uint auStack_5a8 [181];
  int aiStack_2d4 [181];
  
  if (DAT_004a864c == 0) {
    FUN_0042bfc0(0,(double)DAT_004ac284,(double)DAT_004a3a08,param_5,0);
    if ((DAT_004a7c48 < param_8) && (param_6 < DAT_004a7c48)) {
      local_b6c = (int *)DAT_004aaa48;
    }
    else {
      local_b6c = (int *)0x0;
    }
  }
  if (param_3 <= param_4) {
    puVar10 = (uint *)(&DAT_004a7c48 + param_3);
    iVar11 = param_3;
    do {
      FUN_0042bfc0(iVar11,(double)(int)(&DAT_004a6490)[iVar11],(double)(int)(&DAT_004a68c8)[iVar11],
                   param_5,5);
      uVar8 = (&DAT_004aaa48)[iVar11];
      auStack_5a8[iVar11] = *puVar10;
      *(undefined4 *)(&DAT_004a3c10 + iVar11 * 4) = DAT_004ac66c;
      auStack_880[iVar11 + 1] = uVar8;
      if ((int)uVar8 < (int)param_2) {
        auStack_880[iVar11 + 1] = param_2;
      }
      iVar11 = iVar11 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar11 <= param_4);
  }
  puVar12 = (undefined4 *)(param_3 + 1);
  if ((int)puVar12 <= param_4) {
    puVar10 = auStack_5a8 + (int)puVar12;
    iVar11 = (int)puVar12 * 2;
    do {
      if ((((((DAT_004a4958 != 4) ||
             (((uVar8 = iVar11 - DAT_004a67bc >> 0x1f,
               6 < (int)((iVar11 - DAT_004a67bc ^ uVar8) - uVar8) &&
               (uVar8 = iVar11 - DAT_004a67c0 >> 0x1f,
               5 < (int)((iVar11 - DAT_004a67c0 ^ uVar8) - uVar8))) &&
              (uVar8 = iVar11 - DAT_004a67c4 >> 0x1f,
              5 < (int)((iVar11 - DAT_004a67c4 ^ uVar8) - uVar8))))) &&
            ((DAT_004a4958 != 5 ||
             ((uVar8 = iVar11 - DAT_004a67bc >> 0x1f,
              9 < (int)((iVar11 - DAT_004a67bc ^ uVar8) - uVar8) &&
              (uVar8 = iVar11 - DAT_004a67c0 >> 0x1f,
              9 < (int)((iVar11 - DAT_004a67c0 ^ uVar8) - uVar8))))))) &&
           ((DAT_004a4958 != 6 ||
            (((iVar11 < 0x5b || (0x10d < iVar11)) && ((3 < iVar11 && (iVar11 < 0x165)))))))) &&
          ((DAT_004a4958 != 7 ||
           (((0x59 < iVar11 && (iVar11 < 0x10f)) && ((iVar11 < 0xba || (0xc2 < iVar11)))))))) &&
         ((uVar8 = puVar10[-1], (int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)) < 31000
          && (uVar1 = *puVar10, (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) < 31000))
         )) {
        uVar2 = auStack_880[(int)puVar12];
        if (((int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) < 31000) &&
           (((uVar3 = auStack_880[(int)puVar12 + 1],
             (int)((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)) < 31000 &&
             (uVar9 = (int)(&DAT_004a3c0c)[(int)puVar12] >> 0x1f,
             (int)(((&DAT_004a3c0c)[(int)puVar12] ^ uVar9) - uVar9) < 0xa0)) &&
            (uVar9 = (int)*(uint *)(&DAT_004a3c10 + (int)puVar12 * 4) >> 0x1f,
            (int)((*(uint *)(&DAT_004a3c10 + (int)puVar12 * 4) ^ uVar9) - uVar9) < 0xa0)))) {
          FUN_0042d8a0(param_1,uVar8,uVar2,uVar1,uVar3,param_10,puVar12,param_6,param_7,param_8,
                       param_9,(int)param_10,(int)local_b6c);
        }
      }
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      iVar11 = iVar11 + 2;
      puVar10 = puVar10 + 1;
    } while ((int)puVar12 <= param_4);
  }
  if ((DAT_004a4958 < 2) && (DAT_004a5a4c == 1)) {
    iVar11 = (param_9 - (int)param_10) * (3 - DAT_004ac1e0);
    if (param_3 <= param_4) {
      puVar10 = auStack_880 + param_3 + 1;
      iVar13 = param_3;
      do {
        uVar8 = *puVar10;
        uVar1 = auStack_5a8[iVar13];
        (&DAT_004a4f90)[iVar13] = uVar1;
        auStack_b54[iVar13 + 1] = uVar1;
        puVar10 = puVar10 + 1;
        iVar7 = (uVar8 - (int)((uVar8 - (int)param_10) * (&DAT_004a9454)[iVar13]) / iVar11) + -1;
        (&DAT_004a5bb0)[iVar13] = iVar7;
        aiStack_2d4[iVar13] = iVar7;
        iVar13 = iVar13 + 1;
      } while (iVar13 <= param_4);
    }
    if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
      (**(code **)(*(int *)param_1 + 0x2c))(param_1,8);
      if (DAT_004a621c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a621c);
      }
    }
    else {
      if (DAT_004a71bc != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a71bc);
      }
      if (DAT_004a70e4 != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
      }
    }
    pcVar4 = *(code **)(*(int *)param_1 + 0x2c);
    (*pcVar4)(param_1,7);
    if ((DAT_004ac98c == 1) && ((*pcVar4)(param_1,7), DAT_004aa7f4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004aa7f4);
    }
    FUN_004232e0((int)param_1);
    if (((DAT_004ac928 == 0) && (DAT_0049116c < 0xd)) &&
       (FUN_0042bfc0(0,(double)DAT_004ac284,(double)DAT_004a3a08,param_5,0), iVar7 = DAT_004aaa48,
       iVar13 = DAT_004a7c48, param_3 <= param_4)) {
      piVar14 = aiStack_2d4 + param_3;
      iVar6 = iVar11;
      do {
        if (DAT_004a4dec != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
        }
        local_b6c = &DAT_004a9454 + param_3;
        local_b68 = 2;
        do {
          iVar5 = *local_b6c;
          if (iVar5 < 0x1a) {
            iVar11 = (int)(auStack_b54[param_3] + auStack_b54[param_3 + 1] * 3 + iVar13) / 5;
            iVar6 = (piVar14[-1] + *piVar14 * 3 + iVar7) / 5;
            if (0x19 < iVar5) goto LAB_0042d6b3;
          }
          else {
LAB_0042d6b3:
            if ((int)(&DAT_004a9458)[param_3] < 0x33) {
              iVar11 = (int)(auStack_b54[param_3] + iVar13 + auStack_b54[param_3 + 1]) / 3;
              iVar6 = (piVar14[-1] + iVar7 + *piVar14) / 3;
            }
          }
          if ((0x32 < iVar5) && ((int)(&DAT_004a9458)[param_3] < 0x4b)) {
            iVar11 = auStack_b54[param_3] + iVar13 * 2 + auStack_b54[param_3 + 1];
            iVar11 = (int)(iVar11 + (iVar11 >> 0x1f & 3U)) >> 2;
            iVar6 = piVar14[-1] + iVar7 * 2 + *piVar14;
            iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
          }
          if (0x4a < iVar5) {
            iVar11 = (int)(iVar13 + auStack_b54[param_3] * 3 + auStack_b54[param_3 + 1]) / 5;
            iVar6 = (iVar7 + piVar14[-1] * 3 + *piVar14) / 5;
          }
          if (iVar11 != iVar6) {
            if (((int)(param_10 + DAT_004a72d0 / 100) < iVar6) && (iVar6 < DAT_004a72d0 / 0xc)) {
              FUN_004706bd(param_1,aiStack_b60,iVar11,iVar6);
              CDC::LineTo(param_1,iVar11,iVar6 + -1);
            }
            if (DAT_004a72d0 / 0xc <= iVar6) {
              FUN_004706bd(param_1,&iStack_b58,iVar11 + -1,iVar6);
              CDC::LineTo(param_1,iVar11,iVar6 + -2);
              CDC::LineTo(param_1,iVar11 + 1,iVar6);
            }
          }
          local_b6c = local_b6c + 1;
          local_b68 = local_b68 + -1;
        } while (local_b68 != 0);
        param_3 = param_3 + 1;
        piVar14 = piVar14 + 1;
      } while (param_3 <= param_4);
    }
  }
  return;
}


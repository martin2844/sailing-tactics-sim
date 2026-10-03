
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
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  int *piVar15;
  CDC *unaff_retaddr;
  int *local_b70;
  int local_b6c;
  int aiStack_b64 [2];
  int iStack_b5c;
  uint auStack_b58 [182];
  uint auStack_880 [182];
  uint auStack_5a8 [180];
  int aiStack_2d8 [182];
  
  if (DAT_004a864c == 0) {
    FUN_0042bfc0(0,(double)DAT_004ac284,(double)DAT_004a3a08,param_5,0);
    if ((DAT_004a7c48 < param_8) && (param_6 < DAT_004a7c48)) {
      local_b6c = DAT_004aaa48;
    }
    else {
      local_b6c = 0;
    }
  }
  if (param_3 <= param_4) {
    puVar11 = (uint *)(&DAT_004a7c48 + param_3);
    iVar12 = param_3;
    do {
      FUN_0042bfc0(iVar12,(double)(int)(&DAT_004a6490)[iVar12],(double)(int)(&DAT_004a68c8)[iVar12],
                   param_5,5);
      uVar9 = (&DAT_004aaa48)[iVar12];
      auStack_5a8[iVar12] = *puVar11;
      *(undefined4 *)(&DAT_004a3c10 + iVar12 * 4) = DAT_004ac66c;
      auStack_880[iVar12 + 1] = uVar9;
      if ((int)uVar9 < (int)param_2) {
        auStack_880[iVar12 + 1] = param_2;
      }
      iVar12 = iVar12 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar12 <= param_4);
  }
  puVar13 = (undefined4 *)(param_3 + 1);
  if ((int)puVar13 <= param_4) {
    puVar11 = auStack_5a8 + (int)puVar13;
    iVar12 = (int)puVar13 * 2;
    do {
      if ((((((DAT_004a4958 != 4) ||
             (((uVar9 = iVar12 - DAT_004a67bc >> 0x1f,
               6 < (int)((iVar12 - DAT_004a67bc ^ uVar9) - uVar9) &&
               (uVar9 = iVar12 - DAT_004a67c0 >> 0x1f,
               5 < (int)((iVar12 - DAT_004a67c0 ^ uVar9) - uVar9))) &&
              (uVar9 = iVar12 - DAT_004a67c4 >> 0x1f,
              5 < (int)((iVar12 - DAT_004a67c4 ^ uVar9) - uVar9))))) &&
            ((DAT_004a4958 != 5 ||
             ((uVar9 = iVar12 - DAT_004a67bc >> 0x1f,
              9 < (int)((iVar12 - DAT_004a67bc ^ uVar9) - uVar9) &&
              (uVar9 = iVar12 - DAT_004a67c0 >> 0x1f,
              9 < (int)((iVar12 - DAT_004a67c0 ^ uVar9) - uVar9))))))) &&
           ((DAT_004a4958 != 6 ||
            (((iVar12 < 0x5b || (0x10d < iVar12)) && ((3 < iVar12 && (iVar12 < 0x165)))))))) &&
          ((DAT_004a4958 != 7 ||
           (((0x59 < iVar12 && (iVar12 < 0x10f)) && ((iVar12 < 0xba || (0xc2 < iVar12)))))))) &&
         ((uVar9 = puVar11[-1], (int)((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f)) < 31000
          && (uVar1 = *puVar11, (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) < 31000))
         )) {
        uVar2 = auStack_880[(int)puVar13];
        if (((int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) < 31000) &&
           (((uVar3 = auStack_880[(int)puVar13 + 1],
             (int)((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)) < 31000 &&
             (uVar10 = (int)(&DAT_004a3c0c)[(int)puVar13] >> 0x1f,
             (int)(((&DAT_004a3c0c)[(int)puVar13] ^ uVar10) - uVar10) < 0xa0)) &&
            (uVar10 = (int)*(uint *)(&DAT_004a3c10 + (int)puVar13 * 4) >> 0x1f,
            (int)((*(uint *)(&DAT_004a3c10 + (int)puVar13 * 4) ^ uVar10) - uVar10) < 0xa0)))) {
          FUN_0042d8a0(param_1,uVar9,uVar2,uVar1,uVar3,param_10,puVar13,param_6,param_7,param_8,
                       param_9,(int)param_10,local_b6c);
        }
      }
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      iVar12 = iVar12 + 2;
      puVar11 = puVar11 + 1;
    } while ((int)puVar13 <= param_4);
  }
  if ((DAT_004a4958 < 2) && (DAT_004a5a4c == 1)) {
    iVar12 = 3 - DAT_004ac1e0;
    if (param_3 <= param_4) {
      puVar11 = auStack_880 + param_3 + 1;
      iVar14 = param_3;
      do {
        uVar9 = *puVar11;
        uVar1 = auStack_5a8[iVar14];
        (&DAT_004a4f90)[iVar14] = uVar1;
        auStack_b58[iVar14 + 2] = uVar1;
        puVar11 = puVar11 + 1;
        iVar7 = (uVar9 - (int)((uVar9 - (int)param_10) * (&DAT_004a9454)[iVar14]) /
                         ((param_9 - (int)param_10) * iVar12)) + -1;
        (&DAT_004a5bb0)[iVar14] = iVar7;
        aiStack_2d8[iVar14 + 1] = iVar7;
        iVar14 = iVar14 + 1;
      } while (iVar14 <= param_4);
    }
    if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
      (**(code **)(*(int *)param_1 + 0x2c))(8);
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
    (*pcVar4)(7);
    if ((DAT_004ac98c == 1) && ((*pcVar4)(7), DAT_004aa7f4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004aa7f4);
    }
    FUN_004232e0((int)param_1);
    if ((DAT_004ac928 == 0) && (DAT_0049116c < 0xd)) {
      FUN_0042bfc0(0,(double)DAT_004ac284,(double)DAT_004a3a08,param_4,0);
      iVar6 = DAT_004aaa48;
      iVar7 = DAT_004a7c48;
      piVar15 = aiStack_2d8 + param_3;
      iVar8 = param_3;
      iVar12 = local_b6c;
      iVar14 = local_b6c;
      do {
        if (DAT_004a4dec != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(unaff_retaddr + 4),DAT_004a4dec);
        }
        local_b70 = &DAT_004a9454 + iVar8;
        local_b6c = 2;
        do {
          iVar5 = *local_b70;
          if (iVar5 < 0x1a) {
            iVar12 = (int)(auStack_b58[iVar8] + auStack_b58[iVar8 + 1] * 3 + iVar7) / 5;
            iVar14 = (piVar15[-1] + *piVar15 * 3 + iVar6) / 5;
            if (0x19 < iVar5) goto LAB_0042d6b3;
          }
          else {
LAB_0042d6b3:
            if ((int)(&DAT_004a9458)[iVar8] < 0x33) {
              iVar12 = (int)(auStack_b58[iVar8] + iVar7 + auStack_b58[iVar8 + 1]) / 3;
              iVar14 = (piVar15[-1] + iVar6 + *piVar15) / 3;
            }
          }
          if ((0x32 < iVar5) && ((int)(&DAT_004a9458)[iVar8] < 0x4b)) {
            iVar12 = auStack_b58[iVar8] + iVar7 * 2 + auStack_b58[iVar8 + 1];
            iVar12 = (int)(iVar12 + (iVar12 >> 0x1f & 3U)) >> 2;
            iVar14 = piVar15[-1] + iVar6 * 2 + *piVar15;
            iVar14 = (int)(iVar14 + (iVar14 >> 0x1f & 3U)) >> 2;
          }
          if (0x4a < iVar5) {
            iVar12 = (int)(iVar7 + auStack_b58[iVar8] * 3 + auStack_b58[iVar8 + 1]) / 5;
            iVar14 = (iVar6 + piVar15[-1] * 3 + *piVar15) / 5;
          }
          if (iVar12 != iVar14) {
            if ((DAT_004a72d0 / 100 + param_9 < iVar14) && (iVar14 < DAT_004a72d0 / 0xc)) {
              FUN_004706bd(unaff_retaddr,aiStack_b64,iVar12,iVar14);
              CDC::LineTo(unaff_retaddr,iVar12,iVar14 + -1);
            }
            if (DAT_004a72d0 / 0xc <= iVar14) {
              FUN_004706bd(unaff_retaddr,&iStack_b5c,iVar12 + -1,iVar14);
              CDC::LineTo(unaff_retaddr,iVar12,iVar14 + -2);
              CDC::LineTo(unaff_retaddr,iVar12 + 1,iVar14);
            }
          }
          local_b70 = local_b70 + 1;
          local_b6c = local_b6c + -1;
        } while (local_b6c != 0);
        iVar8 = iVar8 + 1;
        piVar15 = piVar15 + 1;
      } while (iVar8 <= param_3);
    }
  }
  return;
}


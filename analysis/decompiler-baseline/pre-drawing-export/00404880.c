
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00404880(CDC *param_1,undefined *param_2,int param_3,int *param_4,int param_5,int *param_6)

{
  undefined *puVar1;
  CDC *this;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  code *unaff_EBX;
  int *piVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar10;
  uint left;
  HDC pHVar11;
  CDC *pCVar12;
  undefined4 uVar13;
  HGDIOBJ pvVar14;
  code *pcStack_3c;
  code *local_38;
  int aiStack_34 [2];
  HGDIOBJ pvStack_2c;
  HDC local_28;
  HGDIOBJ pvStack_24;
  HGDIOBJ local_20;
  HDC local_1c;
  HRGN local_18;
  undefined4 uStack_14;
  int iStack_10;
  code *pcStack_c;
  code *pcStack_8;
  uint uStack_4;
  
  iVar9 = param_5;
  piVar3 = param_4;
  this = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d2a0;
  pcStack_c = (code *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &pcStack_c;
  pHVar11 = *(HDC *)(param_1 + 4);
  local_1c = pHVar11;
  local_18 = CreateRectRgn((int)param_2,param_3,(int)param_4,param_5);
  local_20 = SelectObject(pHVar11,local_18);
  piVar8 = param_6;
  DAT_004a3fa0 = (int)((int)piVar3 + (int)param_2) / 2;
  iVar5 = iVar9 - param_3;
  DAT_004a4760 = iVar9 - iVar5 / 10;
  if (*(int *)(&DAT_004a4e88 + (int)param_6 * 4) == 1) {
    iVar6 = (int)((ulonglong)((longlong)iVar5 * 0x77777777) >> 0x20) - iVar5;
    DAT_004a4760 = DAT_004a4760 + ((iVar6 >> 3) - (iVar6 >> 0x1f));
  }
  if (*(int *)(&DAT_004a4e88 + (int)param_6 * 4) == 2) {
    iVar6 = (int)((ulonglong)((longlong)iVar5 * 0x6db6db6d) >> 0x20) - iVar5;
    DAT_004a4760 = DAT_004a4760 + ((iVar6 >> 2) - (iVar6 >> 0x1f));
  }
  if (*(int *)(&DAT_004a4e88 + (int)param_6 * 4) == 3) {
    iVar6 = (int)((ulonglong)((longlong)iVar5 * -0x66666667) >> 0x20);
    DAT_004a4760 = DAT_004a4760 + ((iVar6 >> 1) - (iVar6 >> 0x1f));
  }
  if ((600 < DAT_004a72d0) && (*(int *)(&DAT_004a4e88 + (int)param_6 * 4) < 3)) {
    iVar5 = (int)((ulonglong)((longlong)iVar5 * 0x6db6db6d) >> 0x20) - iVar5;
    DAT_004a4760 = DAT_004a4760 + ((iVar5 >> 2) - (iVar5 >> 0x1f));
  }
  FUN_00415ac0();
  if (DAT_00491140 == 2) {
    FUN_00415c40();
  }
  local_28 = *(HDC *)this;
  local_38 = (code *)local_28[0xb].unused;
  DAT_00491148 = (CDC *)((2 < *(int *)(&DAT_004a4e88 + (int)piVar8 * 4)) - 1 & 0x1e);
  (*local_38)(7);
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004a6dac != (HGDIOBJ)0x0) {
      pHVar11 = *(HDC *)(this + 4);
      pvVar14 = DAT_004a6dac;
LAB_00404a30:
      SelectObject(pHVar11,pvVar14);
    }
  }
  else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
    pHVar11 = *(HDC *)(this + 4);
    pvVar14 = DAT_004aa7f4;
    goto LAB_00404a30;
  }
  if (((DAT_004ac98c == 1) && (8 < DAT_004aaa1c)) && (DAT_004a7bc4 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(this + 4),DAT_004a7bc4);
  }
  iVar5 = param_3;
  Rectangle(*(HDC *)(this + 4),(int)param_1,(int)param_2,param_3,iVar9);
  left = 1;
  do {
    if (DAT_004ac98c == 0) {
      FUN_00431b30((int *)this,left,(int)piVar8,(int)param_1,(int)param_2,iVar5,iVar9);
    }
    left = left + 1;
  } while ((int)left < 6);
  if (((DAT_004ac928 == 0) && (DAT_0049116c < 0xd)) && ((DAT_004ac92c == 0 && (DAT_004ac98c == 0))))
  {
    FUN_0042fe40(this,(int)piVar8,(int)param_1,param_2,iVar5,iVar9);
  }
  FUN_0042f930(this,(int)piVar8,(int)param_1,param_2,iVar5,iVar9);
  (*pcStack_3c)(7);
  if ((DAT_004ac92c == 0) && (DAT_004a5b98 < 3)) {
    if ((DAT_004a4be4 == 0x14) || (pvVar14 = DAT_004a469c, DAT_004a4be4 == 6)) {
      if (DAT_004aa714 == (HGDIOBJ)0x0) goto LAB_00404bb3;
      pHVar11 = *(HDC *)(this + 4);
      pvVar14 = DAT_004aa714;
    }
    else {
joined_r0x00404ba6:
      if (pvVar14 == (HGDIOBJ)0x0) goto LAB_00404bb3;
      pHVar11 = *(HDC *)(this + 4);
    }
LAB_00404bad:
    SelectObject(pHVar11,pvVar14);
  }
  else {
    pvVar14 = DAT_004a70e4;
    if ((DAT_004a4be4 == 0x14) || (DAT_004a4be4 == 6)) goto joined_r0x00404ba6;
    if (DAT_004a3efc != (HGDIOBJ)0x0) {
      pHVar11 = *(HDC *)(this + 4);
      pvVar14 = DAT_004a3efc;
      goto LAB_00404bad;
    }
  }
LAB_00404bb3:
  if ((DAT_004ac98c == 1) && (DAT_004ac8f4 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(this + 4),DAT_004ac8f4);
  }
  Rectangle(*(HDC *)(this + 4),left,(int)param_1,iVar5,(int)DAT_00491148);
  if (*(int *)(&DAT_004a4e88 + (int)piVar8 * 4) < 3) {
    FUN_004060f0((int *)this);
  }
  if (DAT_004a4958 < 2) {
    if (DAT_004a864c == 1) {
      FUN_0042d120(this,(uint)DAT_00491148,2,0x24,(int)piVar8,left,param_1,iVar5,iVar9,DAT_00491148)
      ;
    }
    if (DAT_004a864c == 0) {
      iVar6 = 0x24;
      goto LAB_00404c76;
    }
  }
  else {
    iVar6 = 0xb4;
LAB_00404c76:
    FUN_0042d120(this,(uint)DAT_00491148,0,iVar6,(int)piVar8,left,param_1,iVar5,iVar9,DAT_00491148);
  }
  if (DAT_004a5a4c == 0) {
    if ((DAT_004a4958 < 3) || (aiStack_34[0] = 7, 7 < DAT_004a4958)) {
      aiStack_34[0] = 5;
    }
    uStack_4 = 1;
    if (aiStack_34[0] != 0) {
      pcStack_3c = (code *)&DAT_004aa7b4;
      local_38 = (code *)0x0;
      do {
        FUN_0042bfc0(0,(double)*(int *)(local_38 + 0x4a899c),(double)*(int *)(local_38 + 0x4ac674),
                     (int)piVar8,0);
        puVar1 = DAT_004a7c48;
        iVar9 = (int)DAT_004aaa48 - DAT_004a72d0 / 300;
        if ((((-1 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 <= DAT_004a763c)) &&
            ((int)DAT_00491148 <= iVar9)) && (iVar9 <= DAT_004a72d0 / 2)) {
          fVar10 = FUN_004060a0(iVar9,(int)piVar8);
          pvStack_2c = (HGDIOBJ)(longlong)((float10)*(int *)pcStack_3c * fVar10);
          uVar7 = (int)uStack_4 >> 0x1f;
          uVar2 = uStack_4 ^ uVar7;
          if (((iVar9 < DAT_004a72d0 / 2) && (0 < (int)puVar1)) && ((int)puVar1 < DAT_004a763c)) {
            if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
              (*unaff_EBX)(8);
              if (DAT_004a621c != (HGDIOBJ)0x0) {
                pHVar11 = *(HDC *)(this + 4);
                pvVar14 = DAT_004a621c;
LAB_00404e1e:
                SelectObject(pHVar11,pvVar14);
              }
            }
            else {
              if (DAT_004a71bc != (HGDIOBJ)0x0) {
                SelectObject(*(HDC *)(this + 4),DAT_004a71bc);
              }
              if (DAT_004a70e4 != (HGDIOBJ)0x0) {
                pHVar11 = *(HDC *)(this + 4);
                pvVar14 = DAT_004a70e4;
                goto LAB_00404e1e;
              }
            }
            if ((DAT_004ac98c == 1) && ((*unaff_EBX)(8), DAT_004aa7f4 != (HGDIOBJ)0x0)) {
              SelectObject(*(HDC *)(this + 4),DAT_004aa7f4);
            }
            _DAT_004a4cb0 = puVar1;
            iVar5 = (int)pvStack_2c * -4;
            iVar6 = ((-(uint)((uVar2 - uVar7 & 1 ^ uVar7) != uVar7) & 2) + 3) * (int)pvStack_2c;
            _DAT_004a4cb4 = (HGDIOBJ)(iVar9 - (int)pvStack_2c / 2);
            _DAT_004a4ca8 = puVar1 + iVar5;
            _DAT_004a4cac = iVar9;
            _DAT_004a4cb8 = puVar1 + iVar6;
            _DAT_004a4cbc = iVar9;
            pvStack_2c = _DAT_004a4cb4;
            Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,3);
            (*unaff_EBX)(7);
            FUN_004706bd(this,(int *)&local_1c,(int)(puVar1 + iVar5),iVar9);
            CDC::LineTo(this,(int)puVar1,(int)pvStack_2c);
            CDC::LineTo(this,(int)(puVar1 + iVar6),iVar9);
            piVar8 = param_4;
          }
        }
        uStack_4 = uStack_4 + 1;
        local_38 = local_38 + 4;
        pcStack_3c = pcStack_3c + 4;
        iVar9 = param_3;
      } while ((int)uStack_4 <= aiStack_34[0]);
    }
  }
  if (1 < DAT_004a4958) {
    DAT_004a4378 = 0;
    if (DAT_004a4958 < 6) {
      FUN_0042bfc0(0,(double)_DAT_004aa28c,(double)_DAT_004ab9d0,(int)piVar8,0);
      if ((DAT_004ac85c == 2) && (DAT_004a4958 == 5)) {
        FUN_0042e750((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      else {
        FUN_0042e550((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa654,(double)_DAT_004abc84,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa658,(double)_DAT_004abe5c,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa95c,(double)_DAT_004ac564,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        FUN_0042e970(this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa994,(double)_DAT_004ac8e0,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        if ((DAT_004a4958 == 2) || (DAT_004a4958 == 4)) {
          FUN_0042e750((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
        else {
          FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
      }
      if (DAT_004a4958 == 4) {
        FUN_0042bfc0(0,(double)_DAT_004a4418,(double)_DAT_004a63b8,(int)piVar8,0);
        if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
           ((int)DAT_004aaa48 < iVar9)) {
          DAT_004a4378 = 1;
        }
        FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
        FUN_0042bfc0(0,(double)_DAT_004a4420,(double)_DAT_004a643c,(int)piVar8,0);
        if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
           ((int)DAT_004aaa48 < iVar9)) {
          FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
        }
        DAT_004a4378 = 0;
        FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar8,0);
        if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
           ((int)DAT_004aaa48 < iVar9)) {
          FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
      }
      if (DAT_004a4958 == 5) {
        if (DAT_004ac85c == 2) {
          FUN_0042bfc0(0,(double)_DAT_004a4418,(double)_DAT_004a63b8,(int)piVar8,0);
          if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
             ((int)DAT_004aaa48 < iVar9)) {
            DAT_004a4378 = 1;
          }
          FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
          FUN_0042bfc0(0,(double)_DAT_004a4420,(double)_DAT_004a643c,(int)piVar8,0);
          if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
             ((int)DAT_004aaa48 < iVar9)) {
            FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
          }
          DAT_004a4378 = 0;
        }
        if (((DAT_004ac85c == 1) &&
            (FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar8,0),
            (int)left < (int)DAT_004a7c48)) &&
           (((int)DAT_004a7c48 < (int)param_2 && ((int)DAT_004aaa48 < iVar9)))) {
          FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
      }
    }
    if ((DAT_004a4958 == 6) || (DAT_004a4958 == 7)) {
      FUN_0042bfc0(0,(double)_DAT_004aa28c,(double)_DAT_004ab9d0,(int)piVar8,0);
      if (((int)left < (int)DAT_004a7c48) &&
         (((int)DAT_004a7c48 < (int)param_2 && ((int)DAT_004aaa48 < iVar9)))) {
        FUN_0042e550((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa95c,(double)_DAT_004ac564,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        FUN_0042e970(this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
      }
      if (DAT_004a4958 == 7) {
        DAT_004a4378 = 1;
      }
      FUN_0042bfc0(0,(double)_DAT_004aa654,(double)_DAT_004abc84,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa658,(double)_DAT_004abe5c,(int)piVar8,0);
      if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
         ((int)DAT_004aaa48 < iVar9)) {
        FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
      }
      DAT_004a4378 = 0;
    }
  }
  if (1 < DAT_004a4958) goto LAB_00405868;
  FUN_0042bfc0(0,(double)_DAT_004aa28c,(double)_DAT_004ab9d0,(int)piVar8,0);
  if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
     ((int)DAT_004aaa48 < iVar9)) {
    if (DAT_004a4378 == 0) {
      pCVar12 = DAT_00491148;
      if (DAT_004a5a4c == 0) {
        pCVar12 = DAT_004aaa48;
      }
      FUN_0042e550((int *)this,DAT_004a7c48,(int)pCVar12);
    }
    if (DAT_004a4378 == 1) {
      FUN_0042e750((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
    }
  }
  if (((DAT_004a4378 == 1) &&
      (FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar8,0),
      (int)left < (int)DAT_004a7c48)) &&
     (((int)DAT_004a7c48 < (int)param_2 && ((int)DAT_004aaa48 < iVar9)))) {
    FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
  }
  if ((DAT_004a5a4c == 0) || (DAT_00491194 == 8)) {
    FUN_0042bfc0(0,(double)_DAT_004aa654,(double)_DAT_004abc84,(int)piVar8,0);
    if (((int)left < (int)DAT_004a7c48) &&
       (((int)DAT_004a7c48 < (int)param_2 && ((int)DAT_004aaa48 < iVar9)))) {
      FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
    }
    FUN_0042bfc0(0,(double)_DAT_004aa658,(double)_DAT_004abe5c,(int)piVar8,0);
    if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
       ((int)DAT_004aaa48 < iVar9)) {
      FUN_0042eb40(this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
    }
  }
  FUN_0042bfc0(0,(double)_DAT_004a61e0,(double)_DAT_004a677c,(int)piVar8,0);
  if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
     ((int)DAT_004aaa48 < iVar9)) {
    pCVar12 = DAT_004aaa48;
    if ((DAT_004a5a4c != 0) && (pCVar12 = DAT_00491148, DAT_00491194 == 8)) {
      if ((double)DAT_004a3a08 < _DAT_004a4ae8) {
        FUN_0042e970(this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
      }
      pCVar12 = DAT_00491148;
      if (DAT_00491194 == 8) goto LAB_004056d1;
    }
    FUN_0042e970(this,(int)DAT_004a7c48,(int)pCVar12,0);
  }
LAB_004056d1:
  if (DAT_004a4378 == 1) {
    FUN_0042bfc0(0,(double)_DAT_004aaec8,(double)_DAT_004a3a30,(int)piVar8,0);
    if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
       ((int)DAT_004aaa48 < iVar9)) {
      FUN_0042e970(this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
    }
    FUN_0042bfc0(0,(double)_DAT_004aaec0,(double)_DAT_004a3c00,(int)piVar8,0);
    if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
       ((int)DAT_004aaa48 < iVar9)) {
      FUN_0042e970(this,(int)DAT_004a7c48,(int)DAT_004aaa48,3);
    }
  }
  if (DAT_004a4958 == 0) {
    FUN_0042bfc0(0,(double)_DAT_004aa818,(double)_DAT_004ac5ec,(int)piVar8,0);
    if ((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
       (((int)DAT_004aaa48 < iVar9 && (DAT_004a4378 == 0)))) {
      FUN_0042e190(this,DAT_004a7c48,DAT_004aaa48);
    }
    if (((((int)left < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < (int)param_2)) &&
        ((int)DAT_004aaa48 < iVar9)) && (DAT_004a4378 == 1)) {
      FUN_0042e190(this,DAT_004a7c48,DAT_004aaa48);
    }
  }
  if (((DAT_00491194 == 8) && (_DAT_004a4ae8 <= (double)DAT_004a3a08)) && (DAT_004a5a4c == 1)) {
    FUN_0042bfc0(0,(double)_DAT_004a61e0,(double)_DAT_004a677c,(int)piVar8,0);
    FUN_0042e970(this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
  }
LAB_00405868:
  DAT_004aa7e0 = FUN_0042d0c0((int)piVar8);
  FUN_0042c7b0(this,piVar8,left,param_1,(int)param_2,iVar9,(int)DAT_00491148);
  FUN_0042ede0(this,(int)piVar8,(int)param_2,iVar9);
  FUN_0042f0d0(this,0,(int)piVar8,left,iVar9,(int)param_2);
  FUN_0042f0d0(this,1,(int)piVar8,left,iVar9,(int)param_2);
  FUN_0042f0d0(this,-1,(int)piVar8,left,iVar9,(int)param_2);
  (*unaff_EBX)(7);
  SelectObject(local_28,pvStack_2c);
  DeleteObject(pvStack_24);
  if ((DAT_004ac8fc == 1) || (0 < *(int *)(&DAT_004a89c0 + (int)piVar8 * 4))) {
    FUN_00430f90((int *)this,left,(uint)piVar8);
  }
  iVar5 = aiStack_34[0];
  if (DAT_004ac9f0 < 1) {
    if (DAT_004ac9ac == 1) {
      (**(code **)(aiStack_34[0] + 0x38))(0);
      (**(code **)(iVar5 + 0x34))();
      if (DAT_00491198 == -10) {
        FUN_0046bf33(&param_1,s_Sail_Closehauled_004912c0);
        local_18 = (HRGN)0x0;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -9) {
        FUN_0046bf33(&param_1,s_Pinch__high_closehauled__004912a4);
        local_18 = (HRGN)0x1;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if ((-1 < DAT_00491198) && (DAT_00491198 < 0x169)) {
        FUN_00413d00(&iStack_10,DAT_004ac020);
        local_18 = (HRGN)0x2;
        FUN_0046c14f();
        local_18._0_1_ = 3;
        piVar3 = (int *)FUN_0046c0db();
        local_18._0_1_ = 4;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,*piVar3,*(undefined4 *)(*piVar3 + -8));
        local_18._0_1_ = 3;
        FUN_0046bec5((int *)&param_1);
        local_18 = (HRGN)CONCAT31(local_18._1_3_,2);
        FUN_0046bec5((int *)&stack0x00000000);
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5(&iStack_10);
      }
      if (DAT_00491198 == -1) {
        FUN_0046bf33(&param_1,s_Tack___tactical_00491280);
        local_18 = (HRGN)0x5;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -7) {
        FUN_0046bf33(&param_1,s_Tack___avoidance_0049126c);
        local_18 = (HRGN)0x6;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -2) {
        FUN_0046bf33(&param_1,s_Duck_00491264);
        local_18 = (HRGN)0x7;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -3) {
        FUN_0046bf33(&param_1,s_Give_Room_00491258);
        local_18 = (HRGN)0x8;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -4) {
        FUN_0046bf33(&param_1,s_Head_Up___avoidance_00491240);
        local_18 = (HRGN)0x9;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -5) {
        FUN_0046bf33(&param_1,s_Bear_Off_00491234);
        local_18 = (HRGN)0xa;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -6) {
        FUN_0046bf33(&param_1,s_Jibe___tactical_00491220);
        local_18 = (HRGN)0xb;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -0x10) {
        FUN_0046bf33(&param_1,s_Jibe___avoidance_0049120c);
        local_18 = (HRGN)0xc;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_00491198 == -8) {
        FUN_0046bf33(&param_1,s_Slow_down_or_head_up_004911f4);
        local_18 = (HRGN)0xd;
        (**(code **)(iVar5 + 100))
                  (DAT_004a763c / 3,iVar9 + -0xf,param_1,*(undefined4 *)(param_1 + -8));
        local_18 = (HRGN)0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (((DAT_00491198 != DAT_004a4ed8) && (DAT_00491198 < 0)) && (DAT_004ac9c0 == 0)) {
        MessageBeep(0);
      }
      uVar2 = DAT_00491198 - DAT_004a4ed8 >> 0x1f;
      if (((5 < (int)((DAT_00491198 - DAT_004a4ed8 ^ uVar2) - uVar2)) && (DAT_00491198 < 0x169)) &&
         ((-1 < DAT_00491198 && (DAT_004ac9c0 == 0)))) {
        MessageBeep(0);
      }
      (**(code **)(iVar5 + 0x38))(0);
      (**(code **)(iVar5 + 0x34))();
    }
    DAT_004a4ed8 = DAT_00491198;
    if (((DAT_004a5b80 < 1) && (DAT_00491140 == 2)) && (piVar8 == (int *)0x1)) {
      if ((DAT_004ac8fc == 1) || (param_3 = 0, 0 < DAT_004a89c4)) {
        param_3 = 0x14;
      }
      param_2 = *(undefined **)(iVar5 + 0x38);
      if (DAT_004ac92c == 0) {
        uVar13 = 0xff;
      }
      else {
        uVar13 = 0;
      }
      (*(code *)param_2)(uVar13);
      FUN_00413d00(&local_38,
                   (DAT_004a6778 ^ (int)DAT_004a6778 >> 0x1f) - ((int)DAT_004a6778 >> 0x1f));
      uStack_14 = 0xe;
      FUN_00413d00(aiStack_34,
                   (DAT_004a5e84 ^ (int)DAT_004a5e84 >> 0x1f) - ((int)DAT_004a5e84 >> 0x1f));
      uStack_14._0_1_ = 0xf;
      FUN_0046c14f();
      uStack_14._0_1_ = 0x10;
      FUN_0046c0db();
      uStack_14._0_1_ = 0x11;
      FUN_0046c075();
      uStack_14._0_1_ = 0x12;
      puVar4 = (undefined4 *)FUN_0046c0db();
      uStack_14 = CONCAT31(uStack_14._1_3_,0x13);
      (**(code **)(iVar5 + 100))(pcStack_8,param_2,*puVar4);
      pvStack_24._0_1_ = 0x12;
      FUN_0046bec5((int *)&local_1c);
      pvStack_24._0_1_ = 0x11;
      FUN_0046bec5((int *)&local_38);
      pvStack_24._0_1_ = 0x10;
      FUN_0046bec5((int *)&pcStack_3c);
      pvStack_24._0_1_ = 0xf;
      FUN_0046bec5((int *)&stack0xffffffc0);
      pvStack_24 = (HGDIOBJ)CONCAT31(pvStack_24._1_3_,0xe);
      FUN_0046bec5((int *)&stack0xffffffbc);
      pvStack_24 = (HGDIOBJ)0xffffffff;
      FUN_0046bec5((int *)&stack0xffffffb8);
      (*pcStack_c)(0);
    }
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a4dec);
    }
    uVar2 = uStack_4;
    FUN_004706bd(this,(int *)&local_20,uStack_4,left);
    CDC::LineTo(this,(int)param_1,left);
    CDC::LineTo(this,(int)param_1,iVar9);
    CDC::LineTo(this,uVar2,iVar9);
    CDC::LineTo(this,uVar2,left);
  }
  *unaff_FS_OFFSET = local_18;
  return;
}


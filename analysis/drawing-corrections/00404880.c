
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00404880(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  undefined *puVar2;
  int this;
  TactCString TVar3;
  uint uVar4;
  TactCString *pTVar5;
  TactCString *pTVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar13;
  HDC pHVar14;
  CDC *pCVar15;
  HGDIOBJ pvVar16;
  COLORREF CVar17;
  int *piStack_34;
  int iStack_30;
  TactCString local_28;
  TactCString TStack_24;
  TactCString local_20;
  TactCString local_1c;
  TactCString local_18;
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar11 = param_5;
  iVar7 = param_4;
  this = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d2a0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  pHVar14 = *(HDC *)(param_1 + 4);
  local_1c.data = (char *)pHVar14;
  local_18.data = (char *)CreateRectRgn(param_2,param_3,param_4,param_5);
  local_20.data = SelectObject(pHVar14,local_18.data);
  piVar10 = (int *)param_6;
  DAT_004a3fa0 = (iVar7 + param_2) / 2;
  iVar7 = iVar11 - param_3;
  DAT_004a4760 = iVar11 - iVar7 / 10;
  if (*(int *)(&DAT_004a4e88 + param_6 * 4) == 1) {
    iVar8 = (int)((ulonglong)((longlong)iVar7 * 0x77777777) >> 0x20) - iVar7;
    DAT_004a4760 = DAT_004a4760 + ((iVar8 >> 3) - (iVar8 >> 0x1f));
  }
  if (*(int *)(&DAT_004a4e88 + param_6 * 4) == 2) {
    iVar8 = (int)((ulonglong)((longlong)iVar7 * 0x6db6db6d) >> 0x20) - iVar7;
    DAT_004a4760 = DAT_004a4760 + ((iVar8 >> 2) - (iVar8 >> 0x1f));
  }
  if (*(int *)(&DAT_004a4e88 + param_6 * 4) == 3) {
    iVar8 = (int)((ulonglong)((longlong)iVar7 * -0x66666667) >> 0x20);
    DAT_004a4760 = DAT_004a4760 + ((iVar8 >> 1) - (iVar8 >> 0x1f));
  }
  if ((600 < DAT_004a72d0) && (*(int *)(&DAT_004a4e88 + param_6 * 4) < 3)) {
    iVar7 = (int)((ulonglong)((longlong)iVar7 * 0x6db6db6d) >> 0x20) - iVar7;
    DAT_004a4760 = DAT_004a4760 + ((iVar7 >> 2) - (iVar7 >> 0x1f));
  }
  FUN_00415ac0();
  if (DAT_00491140 == 2) {
    FUN_00415c40();
  }
  local_28.data = *(char **)this;
  pcVar1 = *(code **)(local_28.data + 0x2c);
  DAT_00491148 = (CDC *)((2 < *(int *)(&DAT_004a4e88 + (int)piVar10 * 4)) - 1 & 0x1e);
  (*pcVar1)((void *)this,7);
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004a6dac != (HGDIOBJ)0x0) {
      pHVar14 = *(HDC *)(this + 4);
      pvVar16 = DAT_004a6dac;
LAB_00404a30:
      SelectObject(pHVar14,pvVar16);
    }
  }
  else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
    pHVar14 = *(HDC *)(this + 4);
    pvVar16 = DAT_004aa7f4;
    goto LAB_00404a30;
  }
  if (((DAT_004ac98c == 1) && (8 < DAT_004aaa1c)) && (DAT_004a7bc4 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(this + 4),DAT_004a7bc4);
  }
  iVar7 = param_4;
  Rectangle(*(HDC *)(this + 4),param_2,param_3,param_4,iVar11);
  param_1 = 1;
  do {
    if (DAT_004ac98c == 0) {
      FUN_00431b30((int *)this,param_1,(int)piVar10,param_2,param_3,iVar7,iVar11);
    }
    param_1 = param_1 + 1;
  } while (param_1 < 6);
  if (((DAT_004ac928 == 0) && (DAT_0049116c < 0xd)) && ((DAT_004ac92c == 0 && (DAT_004ac98c == 0))))
  {
    FUN_0042fe40((CDC *)this,(int)piVar10,param_2,param_3,iVar7,iVar11);
  }
  FUN_0042f930((CDC *)this,(int)piVar10,param_2,param_3,iVar7,iVar11);
  (*pcVar1)((void *)this,7);
  if ((DAT_004ac92c == 0) && (DAT_004a5b98 < 3)) {
    if ((DAT_004a4be4 == 0x14) || (pvVar16 = DAT_004a469c, DAT_004a4be4 == 6)) {
      if (DAT_004aa714 == (HGDIOBJ)0x0) goto LAB_00404bb3;
      pHVar14 = *(HDC *)(this + 4);
      pvVar16 = DAT_004aa714;
    }
    else {
joined_r0x00404ba6:
      if (pvVar16 == (HGDIOBJ)0x0) goto LAB_00404bb3;
      pHVar14 = *(HDC *)(this + 4);
    }
LAB_00404bad:
    SelectObject(pHVar14,pvVar16);
  }
  else {
    pvVar16 = DAT_004a70e4;
    if ((DAT_004a4be4 == 0x14) || (DAT_004a4be4 == 6)) goto joined_r0x00404ba6;
    if (DAT_004a3efc != (HGDIOBJ)0x0) {
      pHVar14 = *(HDC *)(this + 4);
      pvVar16 = DAT_004a3efc;
      goto LAB_00404bad;
    }
  }
LAB_00404bb3:
  if ((DAT_004ac98c == 1) && (DAT_004ac8f4 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(this + 4),DAT_004ac8f4);
  }
  Rectangle(*(HDC *)(this + 4),param_2,param_3,iVar7,(int)DAT_00491148);
  if (*(int *)(&DAT_004a4e88 + (int)piVar10 * 4) < 3) {
    FUN_004060f0(this,(int)piVar10);
  }
  if (DAT_004a4958 < 2) {
    if (DAT_004a864c == 1) {
      FUN_0042d120((CDC *)this,(uint)DAT_00491148,2,0x24,(int)piVar10,param_2,param_3,iVar7,iVar11,
                   DAT_00491148);
    }
    if (DAT_004a864c == 0) {
      iVar8 = 0x24;
      goto LAB_00404c76;
    }
  }
  else {
    iVar8 = 0xb4;
LAB_00404c76:
    FUN_0042d120((CDC *)this,(uint)DAT_00491148,0,iVar8,(int)piVar10,param_2,param_3,iVar7,iVar11,
                 DAT_00491148);
  }
  if (DAT_004a5a4c == 0) {
    if ((DAT_004a4958 < 3) || (iVar7 = 7, 7 < DAT_004a4958)) {
      iVar7 = 5;
    }
    param_1 = 1;
    if (iVar7 != 0) {
      piStack_34 = &DAT_004aa7b4;
      iStack_30 = 0;
      do {
        FUN_0042bfc0(0,(double)*(int *)((int)&DAT_004a899c + iStack_30),
                     (double)*(int *)((int)&DAT_004ac674 + iStack_30),(int)piVar10,0);
        puVar2 = DAT_004a7c48;
        iVar11 = (int)DAT_004aaa48 - DAT_004a72d0 / 300;
        if ((((-1 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 <= DAT_004a763c)) &&
            ((int)DAT_00491148 <= iVar11)) && (iVar11 <= DAT_004a72d0 / 2)) {
          fVar13 = FUN_004060a0(iVar11,(int)piVar10);
          TStack_24.data = (char *)(longlong)((float10)*piStack_34 * fVar13);
          uVar9 = param_1 >> 0x1f;
          uVar4 = param_1 ^ uVar9;
          if (((iVar11 < DAT_004a72d0 / 2) && (0 < (int)puVar2)) && ((int)puVar2 < DAT_004a763c)) {
            if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
              (*pcVar1)((void *)this,8);
              if (DAT_004a621c != (HGDIOBJ)0x0) {
                pHVar14 = *(HDC *)(this + 4);
                pvVar16 = DAT_004a621c;
LAB_00404e1e:
                SelectObject(pHVar14,pvVar16);
              }
            }
            else {
              if (DAT_004a71bc != (HGDIOBJ)0x0) {
                SelectObject(*(HDC *)(this + 4),DAT_004a71bc);
              }
              if (DAT_004a70e4 != (HGDIOBJ)0x0) {
                pHVar14 = *(HDC *)(this + 4);
                pvVar16 = DAT_004a70e4;
                goto LAB_00404e1e;
              }
            }
            if ((DAT_004ac98c == 1) && ((*pcVar1)((void *)this,8), DAT_004aa7f4 != (HGDIOBJ)0x0)) {
              SelectObject(*(HDC *)(this + 4),DAT_004aa7f4);
            }
            _DAT_004a4cb0 = puVar2;
            iVar8 = (int)TStack_24.data * -4;
            iVar12 = ((-(uint)((uVar4 - uVar9 & 1 ^ uVar9) != uVar9) & 2) + 3) * (int)TStack_24.data
            ;
            _DAT_004a4cb4 = (char *)(iVar11 - (int)TStack_24.data / 2);
            _DAT_004a4ca8 = puVar2 + iVar8;
            _DAT_004a4cac = iVar11;
            _DAT_004a4cb8 = puVar2 + iVar12;
            _DAT_004a4cbc = iVar11;
            TStack_24.data = _DAT_004a4cb4;
            Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,3);
            (*pcVar1)((void *)this,7);
            FUN_004706bd((void *)this,aiStack_14,(int)(puVar2 + iVar8),iVar11);
            CDC::LineTo((CDC *)this,(int)puVar2,(int)TStack_24.data);
            CDC::LineTo((CDC *)this,(int)(puVar2 + iVar12),iVar11);
            piVar10 = (int *)param_6;
          }
        }
        param_1 = param_1 + 1;
        iStack_30 = iStack_30 + 4;
        piStack_34 = piStack_34 + 1;
        iVar11 = param_5;
      } while (param_1 <= iVar7);
    }
  }
  uVar4 = param_2;
  if (1 < DAT_004a4958) {
    DAT_004a4378 = 0;
    if (DAT_004a4958 < 6) {
      FUN_0042bfc0(0,(double)_DAT_004aa28c,(double)_DAT_004ab9d0,(int)piVar10,0);
      if ((DAT_004ac85c == 2) && (DAT_004a4958 == 5)) {
        FUN_0042e750((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      else {
        FUN_0042e550((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa654,(double)_DAT_004abc84,(int)piVar10,0);
      uVar4 = param_2;
      if (((param_2 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa658,(double)_DAT_004abe5c,(int)piVar10,0);
      if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa95c,(double)_DAT_004ac564,(int)piVar10,0);
      if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        FUN_0042e970((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa994,(double)_DAT_004ac8e0,(int)piVar10,0);
      if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        if ((DAT_004a4958 == 2) || (DAT_004a4958 == 4)) {
          FUN_0042e750((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
        else {
          FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
      }
      if (DAT_004a4958 == 4) {
        FUN_0042bfc0(0,(double)_DAT_004a4418,(double)_DAT_004a63b8,(int)piVar10,0);
        if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
           ((int)DAT_004aaa48 < iVar11)) {
          DAT_004a4378 = 1;
        }
        FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
        FUN_0042bfc0(0,(double)_DAT_004a4420,(double)_DAT_004a643c,(int)piVar10,0);
        if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
           ((int)DAT_004aaa48 < iVar11)) {
          FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
        }
        DAT_004a4378 = 0;
        FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar10,0);
        if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
           ((int)DAT_004aaa48 < iVar11)) {
          FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
      }
      if (DAT_004a4958 == 5) {
        if (DAT_004ac85c == 2) {
          FUN_0042bfc0(0,(double)_DAT_004a4418,(double)_DAT_004a63b8,(int)piVar10,0);
          if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
             ((int)DAT_004aaa48 < iVar11)) {
            DAT_004a4378 = 1;
          }
          FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
          FUN_0042bfc0(0,(double)_DAT_004a4420,(double)_DAT_004a643c,(int)piVar10,0);
          if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
             ((int)DAT_004aaa48 < iVar11)) {
            FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
          }
          DAT_004a4378 = 0;
        }
        if (((DAT_004ac85c == 1) &&
            (FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar10,0),
            (int)uVar4 < (int)DAT_004a7c48)) &&
           (((int)DAT_004a7c48 < param_4 && ((int)DAT_004aaa48 < iVar11)))) {
          FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
        }
      }
    }
    if ((DAT_004a4958 == 6) || (DAT_004a4958 == 7)) {
      FUN_0042bfc0(0,(double)_DAT_004aa28c,(double)_DAT_004ab9d0,(int)piVar10,0);
      if (((int)uVar4 < (int)DAT_004a7c48) &&
         (((int)DAT_004a7c48 < param_4 && ((int)DAT_004aaa48 < iVar11)))) {
        FUN_0042e550((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar10,0);
      if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa95c,(double)_DAT_004ac564,(int)piVar10,0);
      if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        FUN_0042e970((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
      }
      if (DAT_004a4958 == 7) {
        DAT_004a4378 = 1;
      }
      FUN_0042bfc0(0,(double)_DAT_004aa654,(double)_DAT_004abc84,(int)piVar10,0);
      if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
      }
      FUN_0042bfc0(0,(double)_DAT_004aa658,(double)_DAT_004abe5c,(int)piVar10,0);
      if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
         ((int)DAT_004aaa48 < iVar11)) {
        FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
      }
      DAT_004a4378 = 0;
    }
  }
  if (1 < DAT_004a4958) goto LAB_00405868;
  FUN_0042bfc0(0,(double)_DAT_004aa28c,(double)_DAT_004ab9d0,(int)piVar10,0);
  if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
     ((int)DAT_004aaa48 < iVar11)) {
    if (DAT_004a4378 == 0) {
      pCVar15 = DAT_00491148;
      if (DAT_004a5a4c == 0) {
        pCVar15 = DAT_004aaa48;
      }
      FUN_0042e550((int *)this,DAT_004a7c48,(int)pCVar15);
    }
    if (DAT_004a4378 == 1) {
      FUN_0042e750((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
    }
  }
  if (((DAT_004a4378 == 1) &&
      (FUN_0042bfc0(0,(double)_DAT_004a72c4,(double)_DAT_004a77e4,(int)piVar10,0),
      (int)uVar4 < (int)DAT_004a7c48)) &&
     (((int)DAT_004a7c48 < param_4 && ((int)DAT_004aaa48 < iVar11)))) {
    FUN_0042e870((int *)this,DAT_004a7c48,(int)DAT_004aaa48);
  }
  if ((DAT_004a5a4c == 0) || (DAT_00491194 == 8)) {
    FUN_0042bfc0(0,(double)_DAT_004aa654,(double)_DAT_004abc84,(int)piVar10,0);
    if (((int)uVar4 < (int)DAT_004a7c48) &&
       (((int)DAT_004a7c48 < param_4 && ((int)DAT_004aaa48 < iVar11)))) {
      FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
    }
    FUN_0042bfc0(0,(double)_DAT_004aa658,(double)_DAT_004abe5c,(int)piVar10,0);
    if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
       ((int)DAT_004aaa48 < iVar11)) {
      FUN_0042eb40((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,2);
    }
  }
  FUN_0042bfc0(0,(double)_DAT_004a61e0,(double)_DAT_004a677c,(int)piVar10,0);
  if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
     ((int)DAT_004aaa48 < iVar11)) {
    pCVar15 = DAT_004aaa48;
    if ((DAT_004a5a4c != 0) && (pCVar15 = DAT_00491148, DAT_00491194 == 8)) {
      if ((double)DAT_004a3a08 < _DAT_004a4ae8) {
        FUN_0042e970((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
      }
      pCVar15 = DAT_00491148;
      if (DAT_00491194 == 8) goto LAB_004056d1;
    }
    FUN_0042e970((CDC *)this,(int)DAT_004a7c48,(int)pCVar15,0);
  }
LAB_004056d1:
  if (DAT_004a4378 == 1) {
    FUN_0042bfc0(0,(double)_DAT_004aaec8,(double)_DAT_004a3a30,(int)piVar10,0);
    if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
       ((int)DAT_004aaa48 < iVar11)) {
      FUN_0042e970((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,1);
    }
    FUN_0042bfc0(0,(double)_DAT_004aaec0,(double)_DAT_004a3c00,(int)piVar10,0);
    if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
       ((int)DAT_004aaa48 < iVar11)) {
      FUN_0042e970((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,3);
    }
  }
  if (DAT_004a4958 == 0) {
    FUN_0042bfc0(0,(double)_DAT_004aa818,(double)_DAT_004ac5ec,(int)piVar10,0);
    if ((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
       (((int)DAT_004aaa48 < iVar11 && (DAT_004a4378 == 0)))) {
      FUN_0042e190((CDC *)this,DAT_004a7c48,DAT_004aaa48);
    }
    if (((((int)uVar4 < (int)DAT_004a7c48) && ((int)DAT_004a7c48 < param_4)) &&
        ((int)DAT_004aaa48 < iVar11)) && (DAT_004a4378 == 1)) {
      FUN_0042e190((CDC *)this,DAT_004a7c48,DAT_004aaa48);
    }
  }
  if (((DAT_00491194 == 8) && (_DAT_004a4ae8 <= (double)DAT_004a3a08)) && (DAT_004a5a4c == 1)) {
    FUN_0042bfc0(0,(double)_DAT_004a61e0,(double)_DAT_004a677c,(int)piVar10,0);
    FUN_0042e970((CDC *)this,(int)DAT_004a7c48,(int)DAT_004aaa48,0);
  }
LAB_00405868:
  DAT_004aa7e0 = FUN_0042d0c0((int)piVar10);
  FUN_0042c7b0((CDC *)this,piVar10,uVar4,param_3,param_4,iVar11,(int)DAT_00491148);
  FUN_0042ede0((CDC *)this,(int)piVar10,param_4,iVar11);
  FUN_0042f0d0((CDC *)this,0,(int)piVar10,uVar4,iVar11,param_4);
  FUN_0042f0d0((CDC *)this,1,(int)piVar10,uVar4,iVar11,param_4);
  FUN_0042f0d0((CDC *)this,-1,(int)piVar10,uVar4,iVar11,param_4);
  (*pcVar1)((void *)this,7);
  SelectObject((HDC)local_1c.data,local_20.data);
  DeleteObject(local_18.data);
  if ((DAT_004ac8fc == 1) || (0 < *(int *)(&DAT_004a89c0 + (int)piVar10 * 4))) {
    FUN_00430f90((int *)this,uVar4,(uint)piVar10);
  }
  TVar3.data = local_28.data;
  if (DAT_004ac9f0 < 1) {
    if (DAT_004ac9ac == 1) {
      (**(code **)(local_28.data + 0x38))((void *)this,0);
      (**(code **)(TVar3.data + 0x34))((void *)this,0xff00);
      if (DAT_00491198 == -10) {
        FUN_0046bf33(&param_6,s_Sail_Closehauled_004912c0);
        uStack_4 = 0;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -9) {
        FUN_0046bf33(&param_6,s_Pinch__high_closehauled__004912a4);
        uStack_4 = 1;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if ((-1 < DAT_00491198) && (DAT_00491198 < 0x169)) {
        pTVar5 = FUN_00413d00((TactCString *)&param_1,DAT_004ac020);
        uStack_4 = 2;
        pTVar5 = FUN_0046c14f((TactCString *)&param_5,s_Sail_0049129c,pTVar5);
        uStack_4._0_1_ = 3;
        pTVar5 = FUN_0046c0db((TactCString *)&param_6,pTVar5,s_deg_00491294);
        uStack_4._0_1_ = 4;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,pTVar5->data,
                   *(int *)(pTVar5->data + -8));
        uStack_4._0_1_ = 3;
        FUN_0046bec5(&param_6);
        uStack_4 = CONCAT31(uStack_4._1_3_,2);
        FUN_0046bec5(&param_5);
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_1);
      }
      if (DAT_00491198 == -1) {
        FUN_0046bf33(&param_6,s_Tack___tactical_00491280);
        uStack_4 = 5;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -7) {
        FUN_0046bf33(&param_6,s_Tack___avoidance_0049126c);
        uStack_4 = 6;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -2) {
        FUN_0046bf33(&param_6,s_Duck_00491264);
        uStack_4 = 7;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -3) {
        FUN_0046bf33(&param_6,s_Give_Room_00491258);
        uStack_4 = 8;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -4) {
        FUN_0046bf33(&param_6,s_Head_Up___avoidance_00491240);
        uStack_4 = 9;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -5) {
        FUN_0046bf33(&param_6,s_Bear_Off_00491234);
        uStack_4 = 10;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -6) {
        FUN_0046bf33(&param_6,s_Jibe___tactical_00491220);
        uStack_4 = 0xb;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -0x10) {
        FUN_0046bf33(&param_6,s_Jibe___avoidance_0049120c);
        uStack_4 = 0xc;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (DAT_00491198 == -8) {
        FUN_0046bf33(&param_6,s_Slow_down_or_head_up_004911f4);
        uStack_4 = 0xd;
        (**(code **)(TVar3.data + 100))
                  ((void *)this,DAT_004a763c / 3,iVar11 + -0xf,(LPCSTR)param_6,
                   *(int *)(param_6 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_6);
      }
      if (((DAT_00491198 != DAT_004a4ed8) && (DAT_00491198 < 0)) && (DAT_004ac9c0 == 0)) {
        MessageBeep(0);
      }
      uVar4 = DAT_00491198 - DAT_004a4ed8 >> 0x1f;
      if (((5 < (int)((DAT_00491198 - DAT_004a4ed8 ^ uVar4) - uVar4)) && (DAT_00491198 < 0x169)) &&
         ((-1 < DAT_00491198 && (DAT_004ac9c0 == 0)))) {
        MessageBeep(0);
      }
      (**(code **)(TVar3.data + 0x38))((void *)this,0);
      (**(code **)(TVar3.data + 0x34))((void *)this,0xffffff);
    }
    DAT_004a4ed8 = DAT_00491198;
    if (((DAT_004a5b80 < 1) && (DAT_00491140 == 2)) && (piVar10 == (int *)0x1)) {
      if ((DAT_004ac8fc == 1) || (param_6 = 0, 0 < DAT_004a89c4)) {
        param_6 = 0x14;
      }
      param_5 = *(int *)(TVar3.data + 0x38);
      if (DAT_004ac92c == 0) {
        CVar17 = 0xff;
      }
      else {
        CVar17 = 0;
      }
      (*(code *)param_5)((void *)this,CVar17);
      pTVar5 = FUN_00413d00(&local_28,
                            (DAT_004a6778 ^ (int)DAT_004a6778 >> 0x1f) - ((int)DAT_004a6778 >> 0x1f)
                           );
      uStack_4 = 0xe;
      pTVar6 = FUN_00413d00(&TStack_24,
                            (DAT_004a5e84 ^ (int)DAT_004a5e84 >> 0x1f) - ((int)DAT_004a5e84 >> 0x1f)
                           );
      uStack_4._0_1_ = 0xf;
      pTVar6 = FUN_0046c14f(&local_20,&DAT_004911f0,pTVar6);
      uStack_4._0_1_ = 0x10;
      pTVar6 = FUN_0046c0db(&local_1c,pTVar6,s_min_004911e8);
      uStack_4._0_1_ = 0x11;
      pTVar5 = FUN_0046c075(&local_18,pTVar6,pTVar5);
      uStack_4._0_1_ = 0x12;
      pTVar5 = FUN_0046c0db((TactCString *)&param_1,pTVar5,s_sec_004911e0);
      uStack_4._0_1_ = 0x13;
      (**(code **)(TVar3.data + 100))
                ((void *)this,param_2,param_6,pTVar5->data,*(int *)(pTVar5->data + -8));
      uStack_4._0_1_ = 0x12;
      FUN_0046bec5(&param_1);
      uStack_4._0_1_ = 0x11;
      FUN_0046bec5((int *)&local_18);
      uStack_4._0_1_ = 0x10;
      FUN_0046bec5((int *)&local_1c);
      uStack_4._0_1_ = 0xf;
      FUN_0046bec5((int *)&local_20);
      uStack_4 = CONCAT31(uStack_4._1_3_,0xe);
      FUN_0046bec5((int *)&TStack_24);
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_28);
      (*(code *)param_5)((void *)this,0);
    }
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a4dec);
    }
    iVar8 = param_3;
    iVar7 = param_2;
    FUN_004706bd((void *)this,aiStack_14,param_2,param_3);
    CDC::LineTo((CDC *)this,param_4,iVar8);
    CDC::LineTo((CDC *)this,param_4,iVar11);
    CDC::LineTo((CDC *)this,iVar7,iVar11);
    CDC::LineTo((CDC *)this,iVar7,iVar8);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


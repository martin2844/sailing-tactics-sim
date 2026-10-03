
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00468440(int *param_1,int param_2,int param_3,int param_4,int param_5,double param_6,int param_7
            ,int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  Tact2010CString TVar6;
  char *pcVar7;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar8;
  float10 fVar9;
  int iStack_40;
  Tact2010CString TStack_3c;
  Tact2010CString TStack_38;
  Tact2010CString TStack_34;
  double dStack_30;
  double dStack_28;
  double dStack_20;
  undefined4 uStack_14;
  code *pcStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  pcStack_10 = FUN_004c5960;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_005364fc == 1) {
    FUN_004b4a1f(param_1,1);
    iVar3 = (int)(longlong)((double)DAT_004da238 * param_6);
    if (DAT_004fb994 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fb994);
    }
    if (DAT_00522fcc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_00522fcc);
    }
    FUN_00433a70(param_1,iVar3,DAT_004fe624 / 2,DAT_004fe2a8 / 2);
    iVar2 = *param_1;
    (**(code **)(iVar2 + 0x38))(param_1,0xff);
    FUN_004b0613(&TStack_34,"Race Area");
    uStack_c = 0;
    (**(code **)(iVar2 + 100))
              (param_1,DAT_004fe624 / 2 - ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2),
               DAT_004fe2a8 / 2,TStack_34.data,*(int *)(TStack_34.data + -8));
    uStack_c = 0xffffffff;
    FUN_004b05a5(&TStack_34);
  }
  if ((param_10 != 1) || (param_9 != 1)) {
    fVar8 = FUN_0043ec20((double)*(int *)(&DAT_00535218 + param_7 * 4),
                         (double)*(int *)(&DAT_004f4b58 + param_7 * 4),param_10,param_11);
    fVar9 = (float10)fsin(fVar8);
    fVar8 = (float10)fcos(fVar8);
    dStack_28 = (double)param_4;
    dStack_20 = (double)param_5;
    fVar9 = fVar9 * (float10)param_6 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
            (float10)param_4;
    fVar8 = (float10)param_5 -
            fVar8 * (float10)param_6 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    dStack_30 = (double)fVar9;
    if ((float10)_DAT_004ccd78 < fVar9) {
      dStack_30 = 10000.0;
    }
    if (dStack_30 < _DAT_004ccd80) {
      dStack_30 = -10000.0;
    }
    if ((float10)_DAT_004ccd78 < fVar8) {
      fVar8 = (float10)_DAT_004ccd78;
    }
    if (fVar8 < (float10)_DAT_004ccd80) {
      fVar8 = (float10)_DAT_004ccd80;
    }
    TStack_38.data = (char *)(longlong)dStack_30;
    TStack_34.data = (char *)(longlong)fVar8;
    iStack_40 = 0x49;
    pcVar7 = (char *)(param_7 * 0x124);
    TStack_3c.data = pcVar7;
    do {
      fVar8 = FUN_0043ec20((double)*(int *)(pcVar7 + 0x4f1cf8),(double)*(int *)(pcVar7 + 0x4f8ee8),
                           param_10,param_11);
      if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
        _DAT_004fbb88 = 0;
        _DAT_004fbb8c = 0x40d86a00;
      }
      fVar9 = (float10)fsin(fVar8);
      fVar8 = (float10)fcos(fVar8);
      fVar9 = fVar9 * (float10)param_6 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
              (float10)dStack_28;
      fVar8 = (float10)dStack_20 -
              fVar8 * (float10)param_6 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
      dStack_30 = (double)fVar9;
      if ((float10)_DAT_004ccd78 < fVar9) {
        dStack_30 = 10000.0;
      }
      if (dStack_30 < _DAT_004ccd80) {
        dStack_30 = -10000.0;
      }
      if ((float10)_DAT_004ccd78 < fVar8) {
        fVar8 = (float10)_DAT_004ccd78;
      }
      if (fVar8 < (float10)_DAT_004ccd80) {
        fVar8 = (float10)_DAT_004ccd80;
      }
      iVar3 = (int)(longlong)dStack_30;
      dStack_30 = (double)CONCAT44(dStack_30._4_4_,iVar3);
      *(int *)(pcVar7 + 0x4f4e50) = iVar3;
      *(int *)(pcVar7 + 0x4fc470) = (int)(longlong)fVar8;
      if (((param_9 == 1) && (1 < param_10)) &&
         (FUN_00469690(param_1,iVar3,(int)(longlong)fVar8,0,param_7,param_8,1,param_11),
         _DAT_004cc5f0 < *(double *)(&DAT_004fb5e0 + param_7 * 8))) {
        FUN_00469690(param_1,(int)(TStack_38.data + *(int *)(pcVar7 + 0x4f4e50) * 4) / 5,
                     (int)(TStack_34.data + *(int *)(pcVar7 + 0x4fc470) * 4) / 5,0,param_7,param_8,1
                     ,param_11);
        FUN_00469690(param_1,(*(int *)(pcVar7 + 0x4f4e50) * 3 + (int)TStack_38.data * 2) / 5,
                     (*(int *)(pcVar7 + 0x4fc470) * 3 + (int)TStack_34.data * 2) / 5,0,param_7,
                     param_8,1,param_11);
        FUN_00469690(param_1,((int)TStack_38.data * 3 + *(int *)(pcVar7 + 0x4f4e50) * 2) / 5,
                     ((int)TStack_34.data * 3 + *(int *)(pcVar7 + 0x4fc470) * 2) / 5,0,param_7,
                     param_8,1,param_11);
      }
      pcVar7 = pcVar7 + 4;
      iStack_40 = iStack_40 + -1;
    } while (iStack_40 != 0);
    bVar5 = true;
    if (param_10 < 3) {
      iVar3 = *(int *)(TStack_3c.data + 0x4f4e54);
      if ((DAT_004fe624 < iVar3) && (DAT_004fe624 < *(int *)(TStack_3c.data + 0x4f4ee0))) {
        bVar5 = false;
      }
      if ((iVar3 < 0) && (*(int *)(TStack_3c.data + 0x4f4ee0) < 0)) {
        bVar5 = false;
      }
      if ((((param_10 == 1) && (iVar3 < DAT_004fe624 / 2)) &&
          (*(int *)(TStack_3c.data + 0x4f4ee0) < DAT_004fe624 / 2)) &&
         ((DAT_004da140 == 1 && (*(int *)(&DAT_004f71c0 + param_11 * 4) < 3)))) {
        bVar5 = false;
      }
      if (((param_10 == 2) && (DAT_004fe624 / 3 < iVar3)) &&
         (DAT_004fe624 / 3 < *(int *)(TStack_3c.data + 0x4f4ee0))) {
        bVar5 = false;
      }
      if ((DAT_004fe2a8 < *(int *)(TStack_3c.data + 0x4fc474)) &&
         (DAT_004fe2a8 < *(int *)(TStack_3c.data + 0x4fc500))) {
        bVar5 = false;
      }
      if (((*(int *)(TStack_3c.data + 0x4fc474) < DAT_004fe2a8 / 2) &&
          (*(int *)(TStack_3c.data + 0x4fc500) < DAT_004fe2a8 / 2)) &&
         (*(int *)(&DAT_004f71c0 + param_11 * 4) < 3)) {
        bVar5 = false;
      }
    }
    if ((param_9 == 0) && (bVar5)) {
      FUN_00469900(param_1,param_7,0,param_8,0);
    }
    if (bVar5) {
      FUN_004b4a1f(param_1,1);
      iVar3 = *param_1;
      (**(code **)(iVar3 + 0x38))(param_1,0x7fff);
      if (((DAT_004da1f8 == 999) && (param_7 == 1)) && (5 < DAT_00522f08)) {
        FUN_004b0613(&TStack_3c,"Primary Land");
        uStack_c = 1;
        iVar2 = DAT_004fc66c + DAT_004fc5dc * 3;
        iVar1 = DAT_004f504c + DAT_004f4fbc * 3;
        (**(code **)(iVar3 + 100))
                  (param_1,((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + -0x1e,
                   ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) + -0x14,TStack_3c.data,
                   *(int *)(TStack_3c.data + -8));
        uStack_c = 0xffffffff;
        FUN_004b05a5(&TStack_3c);
      }
      FUN_004b4a1f(param_1,1);
      (**(code **)(iVar3 + 0x38))(param_1,0x7fff);
      if ((DAT_004da1f8 == 0x6a) && (DAT_005233a8 == 1)) {
        if (param_7 == 1) {
          FUN_0046a760(param_1,DAT_004f5004,DAT_004fc624,1);
          FUN_004b0613(&TStack_3c,&DAT_004ec3b0);
          uStack_c = 2;
          (**(code **)(iVar3 + 100))
                    (param_1,DAT_004f5004 + 10,DAT_004fc624,TStack_3c.data,
                     *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
        if (param_7 == 6) {
          FUN_00471160(param_1);
          FUN_00433a70(param_1,4,DAT_004f55a4,DAT_004fcbc4);
          FUN_004b0613(&TStack_3c,s_Fort_Montagu_004ec3a0);
          uStack_c = 3;
          (**(code **)(iVar3 + 100))
                    (param_1,DAT_004f55a4 + 5,DAT_004fcbc4 + -0xf,TStack_3c.data,
                     *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
      }
      if (DAT_004fb5d4 == 1) {
        if ((param_7 == 4) && (DAT_005233a8 == 1)) {
          FUN_0046a760(param_1,DAT_004f52f8,DAT_004fc918,3);
          FUN_004b0613(&TStack_3c,"Fl G lighthouse");
          uStack_c = 4;
          (**(code **)(iVar3 + 100))
                    (param_1,DAT_004f52f8 + 5,DAT_004fc918 + -0xf,TStack_3c.data,
                     *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
        if (DAT_004fb5d4 == 1) {
          if ((param_7 == 7) && (DAT_005233a8 == 1)) {
            FUN_0046a760(param_1,DAT_004f5664,DAT_004fcc84,3);
            FUN_004b0613(&TStack_3c,"Fl G beacon");
            uStack_c = 5;
            (**(code **)(iVar3 + 100))
                      (param_1,DAT_004f5664 + 10,DAT_004fcc84,TStack_3c.data,
                       *(int *)(TStack_3c.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_3c);
          }
          if (DAT_004fb5d4 == 1) {
            if ((param_7 == 3) && (DAT_005233a8 == 1)) {
              FUN_00469650(param_1);
              FUN_00433a70(param_1,4,(DAT_004f52d0 + DAT_004f51c8 * 2) / 3,
                           (DAT_004fc8f0 + DAT_004fc7e8 * 2) / 3);
              FUN_004b0613(&TStack_3c,"aband lighthouse");
              uStack_c = 6;
              (**(code **)(iVar3 + 100))
                        (param_1,DAT_004f51c8 + 10,DAT_004fc7e8,TStack_3c.data,
                         *(int *)(TStack_3c.data + -8));
              uStack_c = 0xffffffff;
              FUN_004b05a5(&TStack_3c);
            }
            if (((DAT_004fb5d4 == 1) && (param_7 == 3)) && (DAT_005233a8 == 1)) {
              FUN_0046a760(param_1,(DAT_004f51c0 + DAT_004f52dc) / 2,
                           (DAT_004fc8fc + DAT_004fc7e0) / 2,2);
              FUN_004b0613(&TStack_3c,"Fl beacon");
              uStack_c = 7;
              (**(code **)(iVar3 + 100))
                        (param_1,DAT_004f51c0 + 10,DAT_004fc7e0,TStack_3c.data,
                         *(int *)(TStack_3c.data + -8));
              uStack_c = 0xffffffff;
              FUN_004b05a5(&TStack_3c);
            }
          }
        }
      }
      if ((DAT_004da1f8 == 2) && (DAT_005233a8 == 1)) {
        if (param_7 == 5) {
          FUN_0046a760(param_1,DAT_004f549c,DAT_004fcabc,1);
          FUN_004b0613(&TStack_3c,"Fl W&R lighthouse");
          pcVar4 = *(code **)(iVar3 + 100);
          uStack_c = 8;
          (*pcVar4)(param_1,DAT_004f549c + 10,DAT_004fcabc,TStack_3c.data,
                    *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
          FUN_004b0613(&TStack_3c,s_Bakers_I_004ec348);
          uStack_c = 9;
          (*pcVar4)(param_1,DAT_004f549c + 0x14,DAT_004fcabc + -0xf,TStack_3c.data,
                    *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
        if (param_7 == 3) {
          FUN_0046a760(param_1,DAT_004f52d4,DAT_004fc8f4,3);
          FUN_004b0613(&TStack_3c,"F G lighthouse");
          uStack_c = 10;
          (**(code **)(iVar3 + 100))
                    (param_1,DAT_004f52d4 + -0x1e,DAT_004fc8f4 + -0xf,TStack_3c.data,
                     *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
      }
      if ((DAT_004da1f8 == 3) && (DAT_005233a8 == 1)) {
        if (param_7 == 1) {
          FUN_0046a760(param_1,DAT_004f5010,DAT_004fc630,3);
          FUN_004b0613(&TStack_3c,"Fl G lighthouse");
          uStack_c = 0xb;
          (**(code **)(iVar3 + 100))
                    (param_1,DAT_004f5010 + 5,DAT_004fc630,TStack_3c.data,
                     *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
        if (param_7 == 8) {
          FUN_0046a760(param_1,DAT_004f5800,DAT_004fce20,1);
          FUN_004b0613(&TStack_3c,"Fl W lighthouse");
          uStack_c = 0xc;
          (**(code **)(iVar3 + 100))
                    (param_1,DAT_004f5800 + 5,DAT_004fce20,TStack_3c.data,
                     *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
        if (param_7 == 3) {
          FUN_0046a760(param_1,DAT_004f525c,DAT_004fc87c,2);
          FUN_004b0613(&TStack_3c,s_Fl_R_004ec320);
          pcVar4 = *(code **)(iVar3 + 100);
          uStack_c = 0xd;
          (*pcVar4)(param_1,DAT_004f525c + -0x1e,DAT_004fc87c + 10,TStack_3c.data,
                    *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
          FUN_004b0613(&TStack_3c,"lighthouse");
          uStack_c = 0xe;
          (*pcVar4)(param_1,DAT_004f525c + -0x1e,DAT_004fc87c + 0x19,TStack_3c.data,
                    *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
      }
      if (DAT_004da1f8 == 10) {
        if (param_7 == 3) {
          FUN_00469650(param_1);
          FUN_00433a70(param_1,4,DAT_004f5294,DAT_004fc8b4);
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_3c,"TV tower");
            uStack_c = 0xf;
            (**(code **)(iVar3 + 100))
                      (param_1,DAT_004f5294 + 5,DAT_004fc8b4,TStack_3c.data,
                       *(int *)(TStack_3c.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_3c);
          }
        }
        if ((param_7 == 4) && (FUN_0046a760(param_1,DAT_004f52e4,DAT_004fc904,1), DAT_005233a8 == 1)
           ) {
          FUN_004b0613(&TStack_3c,"Fl W lighthouse");
          uStack_c = 0x10;
          (**(code **)(iVar3 + 100))
                    (param_1,DAT_004f52e4 + 5,DAT_004fc904,TStack_3c.data,
                     *(int *)(TStack_3c.data + -8));
          uStack_c = 0xffffffff;
          FUN_004b05a5(&TStack_3c);
        }
      }
      if (DAT_004da1f8 == 0xb) {
        if (param_7 == 0xb) {
          FUN_00469670(param_1);
          FUN_00433a70(param_1,4,DAT_004f5b64,DAT_004fd184);
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_3c,"aband lighthouse");
            uStack_c = 0x11;
            (**(code **)(iVar3 + 100))
                      (param_1,DAT_004f5b64,DAT_004fd184,TStack_3c.data,
                       *(int *)(TStack_3c.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_3c);
          }
        }
        if (param_7 == 7) {
          FUN_00469650(param_1);
          FUN_00433a70(param_1,4,DAT_004f5724,DAT_004fcd44);
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_3c,"stack");
            uStack_c = 0x12;
            (**(code **)(iVar3 + 100))
                      (param_1,DAT_004f5724 + 7,DAT_004fcd44,TStack_3c.data,
                       *(int *)(TStack_3c.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_3c);
          }
        }
      }
      iVar2 = DAT_004f5470;
      TVar6.data = TStack_34.data;
      if (DAT_004da1f8 == 100) {
        if (param_7 == 5) {
          dStack_30 = (double)CONCAT44(dStack_30._4_4_,DAT_004fca90);
          FUN_0046a760(param_1,DAT_004f5470,DAT_004fca90,3);
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_3c,"Fl W lighthouse");
            uStack_c = 0x13;
            (**(code **)(iVar3 + 100))
                      (param_1,iVar2 + -0x23,dStack_30._0_4_ + 8,TStack_3c.data,
                       *(int *)(TStack_3c.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_3c);
          }
        }
        TVar6.data = TStack_34.data;
        if (param_7 == 9) {
          if (DAT_005125f4 != (HGDIOBJ)0x0) {
            SelectObject((HDC)param_1[1],DAT_005125f4);
          }
          if (DAT_00535c64 != (HGDIOBJ)0x0) {
            SelectObject((HDC)param_1[1],DAT_00535c64);
          }
          TVar6.data = TStack_34.data;
          FUN_00433a70(param_1,4,TStack_38.data,TStack_34.data);
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_34,"water tank");
            uStack_c = 0x14;
            (**(code **)(iVar3 + 100))
                      (param_1,(int)(TStack_38.data + -0x19),(int)(TVar6.data + 8),TStack_34.data,
                       *(int *)(TStack_34.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_34);
          }
        }
      }
      if (DAT_004da1f8 == 0x66) {
        if (param_7 == 5) {
          TStack_38.data = (char *)((TVar6.data + DAT_004f5494 * 0x13) / 0x14);
          iVar2 = (int)(TVar6.data + DAT_004fcab4 * 0x13) / 0x14;
          FUN_0046a760(param_1,TStack_38.data,iVar2,3);
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_34,"Fl G lighthouse");
            uStack_c = 0x15;
            (**(code **)(iVar3 + 100))
                      (param_1,(int)(TStack_38.data + -0x23),iVar2 + 0xc,TStack_34.data,
                       *(int *)(TStack_34.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_34);
            if (DAT_005233a8 == 1) {
              FUN_004b0613(&TStack_34,s_East_Chop_004ec2d4);
              uStack_c = 0x16;
              (**(code **)(iVar3 + 100))
                        (param_1,(int)(TStack_38.data + -0x23),iVar2 + 0x1b,TStack_34.data,
                         *(int *)(TStack_34.data + -8));
              uStack_c = 0xffffffff;
              FUN_004b05a5(&TStack_34);
            }
          }
        }
        iVar2 = DAT_004f59a8;
        if (param_7 == 9) {
          TStack_34.data = DAT_004fcfc8;
          FUN_0046a760(param_1,DAT_004f59a8,DAT_004fcfc8,1);
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_38,"Fl W lighthouse");
            uStack_c = 0x17;
            (**(code **)(iVar3 + 100))
                      (param_1,iVar2 + -0x23,(int)(TStack_34.data + 0xc),TStack_38.data,
                       *(int *)(TStack_38.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_38);
            if (DAT_005233a8 == 1) {
              FUN_004b0613(&TStack_38,"Cape Poge");
              uStack_c = 0x18;
              (**(code **)(iVar3 + 100))
                        (param_1,iVar2 + -0x23,(int)(TStack_34.data + 0x1b),TStack_38.data,
                         *(int *)(TStack_38.data + -8));
              uStack_c = 0xffffffff;
              FUN_004b05a5(&TStack_38);
            }
          }
        }
        iVar2 = DAT_004f5304;
        if (param_7 == 4) {
          TStack_34.data = DAT_004fc924;
          if (DAT_005233a8 == 1) {
            FUN_0046a760(param_1,DAT_004f5304,DAT_004fc924,2);
          }
          if (DAT_005233a8 == 1) {
            FUN_004b0613(&TStack_38,"Fl R lighthouse");
            uStack_c = 0x19;
            (**(code **)(iVar3 + 100))
                      (param_1,iVar2 + 9,(int)(TStack_34.data + -10),TStack_38.data,
                       *(int *)(TStack_38.data + -8));
            uStack_c = 0xffffffff;
            FUN_004b05a5(&TStack_38);
          }
        }
      }
      FUN_004b4a1f(param_1,2);
    }
  }
  *unaff_FS_OFFSET = uStack_14;
  return;
}


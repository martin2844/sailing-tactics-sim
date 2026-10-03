
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0047e040(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *original_dc;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float10 fVar12;
  HDC hdc;
  HGDIOBJ h;
  int *local_2c;
  int local_20;
  int aiStack_10 [2];
  int aiStack_8 [2];
  
  original_dc = param_1;
  if ((DAT_004f8b78 == 0) && (DAT_004da1f8 == 0)) {
    if ((DAT_004f69b8 < 3) || (iVar4 = 7, 7 < DAT_004f69b8)) {
      iVar4 = 5;
    }
    param_1 = (int *)0x1;
    if (iVar4 != 0) {
      local_2c = &DAT_00523084;
      local_20 = 0;
      do {
        FUN_0043e730(0,(double)*(int *)((int)&DAT_005116bc + local_20),
                     (double)*(int *)((int)&DAT_00535ffc + local_20),param_5,0);
        iVar3 = DAT_004fed58;
        iVar11 = DAT_00523660 - DAT_004fe2a8 / 300;
        if ((((-1 < DAT_004fed58) && (DAT_004fed58 <= DAT_004fe624)) && (DAT_004da148 <= iVar11)) &&
           (iVar11 <= DAT_004fe2a8 / 2)) {
          fVar12 = (float10)FUN_00406220(iVar11,param_5);
          iVar9 = (int)(longlong)((float10)*local_2c * fVar12 * (float10)_DAT_004cc538);
          uVar10 = (int)param_1 >> 0x1f;
          if (((iVar11 < DAT_004fe2a8 / 2) && (0 < iVar3)) && (iVar3 < DAT_004fe624)) {
            if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
              (**(code **)(*original_dc + 0x2c))(original_dc,8);
              if (DAT_005363a4 != (HGDIOBJ)0x0) {
                hdc = (HDC)original_dc[1];
                h = DAT_005363a4;
override_prt_47e1f8_6059bb06:
                SelectObject(hdc,h);
              }
            }
            else {
              if (DAT_004fe174 != (HGDIOBJ)0x0) {
                SelectObject((HDC)original_dc[1],DAT_004fe174);
              }
              if (DAT_004fe07c != (HGDIOBJ)0x0) {
                hdc = (HDC)original_dc[1];
                h = DAT_004fe07c;
                goto override_prt_47e1f8_6059bb06;
              }
            }
            if ((DAT_00536450 == 1) &&
               ((**(code **)(*original_dc + 0x2c))(original_dc,8), DAT_005230cc != (HGDIOBJ)0x0)) {
              SelectObject((HDC)original_dc[1],DAT_005230cc);
            }
            pcVar2 = *(code **)(*original_dc + 0x2c);
            (*pcVar2)(original_dc,8);
            iVar5 = iVar3 + iVar9 * -4;
            iVar6 = iVar3 + iVar9 * -2;
            _DAT_004f6e38 = iVar3;
            iVar7 = iVar11 - ((int)((iVar9 * 3 >> 0x1f & 7U) + iVar9 * 3) >> 3);
            iVar8 = iVar11 - iVar9 / 2;
            iVar9 = ((-(uint)((((uint)param_1 ^ uVar10) - uVar10 & 1 ^ uVar10) != uVar10) & 2) + 3)
                    * iVar9;
            iVar1 = iVar3 + iVar9;
            iVar9 = iVar9 / 2 + iVar3;
            _DAT_004f6e28 = iVar5;
            _DAT_004f6e2c = iVar11;
            _DAT_004f6e30 = iVar6;
            _DAT_004f6e34 = iVar7;
            _DAT_004f6e3c = iVar8;
            _DAT_004f6e40 = iVar9;
            _DAT_004f6e44 = iVar7;
            _DAT_004f6e48 = iVar1;
            _DAT_004f6e4c = iVar11;
            Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,5);
            Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,3);
            (*pcVar2)(original_dc,7);
            if ((int)param_1 % 3 == 0) {
              (*pcVar2)(original_dc,7);
              FUN_004b4d9d(original_dc,aiStack_10,iVar5,iVar11);
              iVar9 = iVar3;
              iVar7 = iVar8;
            }
            else {
              (*pcVar2)(original_dc,7);
              FUN_004b4d9d(original_dc,aiStack_8,iVar5,iVar11);
              CDC::LineTo(original_dc,iVar6,iVar7);
              CDC::LineTo(original_dc,iVar3,iVar8);
            }
            CDC::LineTo(original_dc,iVar9,iVar7);
            CDC::LineTo(original_dc,iVar1,iVar11);
          }
        }
        param_1 = (int *)((int)param_1 + 1);
        local_2c = local_2c + 1;
        local_20 = local_20 + 4;
      } while ((int)param_1 <= iVar4);
    }
  }
  if (1 < DAT_004f69b8) {
    DAT_004f4510 = 0;
    if (DAT_004f69b8 < 6) {
      FUN_0043e730(0,(double)_DAT_005229cc,(double)_DAT_00534ea0,param_5,0);
      if ((DAT_00536300 == 2) && (DAT_004f69b8 == 5)) {
        FUN_00441bc0(original_dc,DAT_004fed58,DAT_00523660);
      }
      else {
        FUN_004419a0(original_dc,DAT_004fed58,DAT_00523660);
      }
      FUN_0043e730(0,(double)_DAT_00522e5c,(double)_DAT_00535278,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,1);
      }
      FUN_0043e730(0,(double)_DAT_00522e60,(double)_DAT_00535554,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,2);
      }
      FUN_0043e730(0,(double)_DAT_0052338c,(double)_DAT_00535ecc,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        FUN_00441de0(original_dc,DAT_004fed58,DAT_00523660,0);
      }
      FUN_0043e730(0,(double)_DAT_00523594,(double)_DAT_00536398,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        if ((DAT_004f69b8 == 2) || (DAT_004f69b8 == 4)) {
          FUN_00441bc0(original_dc,DAT_004fed58,DAT_00523660);
        }
        else {
          FUN_00441ce0(original_dc,DAT_004fed58,DAT_00523660);
        }
      }
      if (DAT_004f69b8 == 4) {
        FUN_0043e730(0,(double)DAT_004f4690,(double)DAT_004fb418,param_5,0);
        if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
          DAT_004f4510 = 1;
        }
        FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,1);
        FUN_0043e730(0,(double)DAT_004f4698,(double)DAT_004fb4ac,param_5,0);
        if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
          FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,2);
        }
        DAT_004f4510 = 0;
        FUN_0043e730(0,(double)_DAT_004fe29c,(double)_DAT_004fe810,param_5,0);
        if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
          FUN_00441ce0(original_dc,DAT_004fed58,DAT_00523660);
        }
      }
      if (DAT_004f69b8 == 5) {
        if (DAT_00536300 == 2) {
          FUN_0043e730(0,(double)DAT_004f4690,(double)DAT_004fb418,param_5,0);
          if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
            DAT_004f4510 = 1;
          }
          FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,1);
          FUN_0043e730(0,(double)DAT_004f4698,(double)DAT_004fb4ac,param_5,0);
          if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
            FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,2);
          }
          DAT_004f4510 = 0;
        }
        if (((DAT_00536300 == 1) &&
            (FUN_0043e730(0,(double)_DAT_004fe29c,(double)_DAT_004fe810,param_5,0),
            param_2 < DAT_004fed58)) && ((DAT_004fed58 < param_3 && (DAT_00523660 < param_4)))) {
          FUN_00441ce0(original_dc,DAT_004fed58,DAT_00523660);
        }
      }
    }
    if ((DAT_004f69b8 == 6) || (DAT_004f69b8 == 7)) {
      FUN_0043e730(0,(double)_DAT_005229cc,(double)_DAT_00534ea0,param_5,0);
      if ((param_2 < DAT_004fed58) && ((DAT_004fed58 < param_3 && (DAT_00523660 < param_4)))) {
        FUN_004419a0(original_dc,DAT_004fed58,DAT_00523660);
      }
      FUN_0043e730(0,(double)_DAT_004fe29c,(double)_DAT_004fe810,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        FUN_00441ce0(original_dc,DAT_004fed58,DAT_00523660);
      }
      FUN_0043e730(0,(double)_DAT_0052338c,(double)_DAT_00535ecc,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        FUN_00441de0(original_dc,DAT_004fed58,DAT_00523660,0);
      }
      if (DAT_004f69b8 == 7) {
        DAT_004f4510 = 1;
      }
      FUN_0043e730(0,(double)_DAT_00522e5c,(double)_DAT_00535278,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,1);
      }
      FUN_0043e730(0,(double)_DAT_00522e60,(double)_DAT_00535554,param_5,0);
      if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
        FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,2);
      }
      DAT_004f4510 = 0;
    }
  }
  if (1 < DAT_004f69b8) {
    return;
  }
  if (DAT_004da1f8 != 0) {
    return;
  }
  FUN_0043e730(0,(double)_DAT_005229cc,(double)_DAT_00534ea0,param_5,0);
  if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
    if (DAT_004f4510 == 0) {
      iVar4 = DAT_004da148;
      if (DAT_004f8b78 == 0) {
        iVar4 = DAT_00523660;
      }
      FUN_004419a0(original_dc,DAT_004fed58,iVar4);
    }
    if (DAT_004f4510 == 1) {
      FUN_00441bc0(original_dc,DAT_004fed58,DAT_00523660);
    }
  }
  if (((DAT_004f4510 == 1) &&
      (FUN_0043e730(0,(double)_DAT_004fe29c,(double)_DAT_004fe810,param_5,0), param_2 < DAT_004fed58
      )) && ((DAT_004fed58 < param_3 && (DAT_00523660 < param_4)))) {
    FUN_00441ce0(original_dc,DAT_004fed58,DAT_00523660);
  }
  if ((DAT_004f8b78 == 0) || (DAT_004da19c == 8)) {
    FUN_0043e730(0,(double)_DAT_00522e5c,(double)_DAT_00535278,param_5,0);
    if ((param_2 < DAT_004fed58) && ((DAT_004fed58 < param_3 && (DAT_00523660 < param_4)))) {
      FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,1);
    }
    FUN_0043e730(0,(double)_DAT_00522e60,(double)_DAT_00535554,param_5,0);
    if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
      FUN_00441fb0(original_dc,DAT_004fed58,DAT_00523660,2);
    }
  }
  FUN_0043e730(0,(double)_DAT_004fb208,(double)_DAT_004fb9bc,param_5,0);
  if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
    iVar4 = DAT_00523660;
    if ((DAT_004f8b78 != 0) && (iVar4 = DAT_004da148, DAT_004da19c == 8)) {
      if ((double)DAT_004f3858 < DAT_004f6c18) {
        FUN_00441de0(original_dc,DAT_004fed58,DAT_00523660,0);
      }
      iVar4 = DAT_004da148;
      if (DAT_004da19c == 8) goto LAB_0047eb8c;
    }
    FUN_00441de0(original_dc,DAT_004fed58,iVar4,0);
  }
LAB_0047eb8c:
  if (DAT_004f4510 == 1) {
    FUN_0043e730(0,(double)_DAT_00523b10,(double)_DAT_004f3a30,param_5,0);
    if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
      FUN_00441de0(original_dc,DAT_004fed58,DAT_00523660,1);
    }
    FUN_0043e730(0,(double)_DAT_00523b08,(double)_DAT_004f3c00,param_5,0);
    if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) {
      FUN_00441de0(original_dc,DAT_004fed58,DAT_00523660,3);
    }
  }
  if (DAT_004f69b8 == 0) {
    FUN_0043e730(0,(double)_DAT_0052317c,(double)_DAT_00535f64,param_5,0);
    if (((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) &&
       ((DAT_00523660 < param_4 && (DAT_004f4510 == 0)))) {
      FUN_00441570(original_dc,DAT_004fed58,DAT_00523660,DAT_004f8b78 == 1);
    }
    if ((((param_2 < DAT_004fed58) && (DAT_004fed58 < param_3)) && (DAT_00523660 < param_4)) &&
       (DAT_004f4510 == 1)) {
      FUN_00441570(original_dc,DAT_004fed58,DAT_00523660,1);
    }
  }
  if (((DAT_004da19c == 8) && (DAT_004f6c18 <= (double)DAT_004f3858)) && (DAT_004f8b78 == 1)) {
    FUN_0043e730(0,(double)_DAT_004fb208,(double)_DAT_004fb9bc,param_5,0);
    FUN_00441de0(original_dc,DAT_004fed58,DAT_00523660,0);
  }
  return;
}


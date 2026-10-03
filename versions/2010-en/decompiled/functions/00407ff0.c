
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00407ff0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  HDC hdc;
  code *pcVar1;
  double dVar2;
  bool bVar3;
  int *original_dc;
  HRGN h;
  HGDIOBJ h_00;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc_00;
  HGDIOBJ h_01;
  int iVar8;
  int iStack_40;
  int iStack_38;
  int iStack_34;
  double dStack_14;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar8 = param_5;
  original_dc = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c1e28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  hdc = (HDC)param_1[1];
  h = CreateRectRgn(param_2,param_3,param_4,param_5);
  h_00 = SelectObject(hdc,h);
  iVar4 = param_7;
  if (0 < DAT_005363f4) {
    DAT_004da200 = 0;
    DAT_0053641c = 1;
  }
  DAT_005233a8 = (uint)(param_7 == 3);
  pcVar1 = *(code **)(*original_dc + 0x2c);
  (*pcVar1)(original_dc,7);
  if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
    if (DAT_00522fcc != (HGDIOBJ)0x0) {
      hdc_00 = (HDC)original_dc[1];
      h_01 = DAT_00522fcc;
override_prt_4080c8_6059bb06:
      SelectObject(hdc_00,h_01);
    }
  }
  else if (DAT_005230cc != (HGDIOBJ)0x0) {
    hdc_00 = (HDC)original_dc[1];
    h_01 = DAT_005230cc;
    goto override_prt_4080c8_6059bb06;
  }
  if ((((DAT_00536450 == 1) && (0 < iVar4)) && (iVar4 < 3)) && (DAT_005230cc != (HGDIOBJ)0x0)) {
    SelectObject((HDC)original_dc[1],DAT_005230cc);
  }
  if (((0 < DAT_005363f4) && (DAT_005363e4 == 0)) && (DAT_00522fcc != (HGDIOBJ)0x0)) {
    SelectObject((HDC)original_dc[1],DAT_00522fcc);
  }
  if (iVar4 == 1) {
    if (((param_6 == 1) && (0 < DAT_00522cac)) &&
       ((DAT_0050f6d4 == 2 && (DAT_004f8d6c != (HGDIOBJ)0x0)))) {
      SelectObject((HDC)original_dc[1],DAT_004f8d6c);
    }
    if ((((param_6 == 2) && (0 < DAT_00522d18)) && (DAT_0050f6d8 == 2)) &&
       (DAT_004f8d6c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)original_dc[1],DAT_004f8d6c);
    }
  }
  iVar5 = param_3;
  Rectangle((HDC)original_dc[1],param_2,param_3,param_4,iVar8);
  if (iVar4 == 1) {
    iStack_40 = (param_4 * 5 + param_2 * 4) / 9;
    param_1 = (int *)((iVar8 * 5 + iVar5 * 4) / 9);
  }
  bVar3 = iVar4 == 2;
  if (bVar3) {
    iStack_40 = (param_4 + param_2) / 2;
    param_1 = (int *)((iVar5 * 5 + iVar8 * 4) / 9);
  }
  if ((iVar4 != 2 && (!bVar3 && SBORROW4(iVar4,2)) == iVar4 + -2 < 0) || (DAT_005364fc == 1)) {
    iStack_40 = (param_2 + param_4) / 2;
    param_1 = (int *)((iVar8 + iVar5) / 2);
  }
  if (((2 < iVar4) && (DAT_0053527c == 1)) && (DAT_005364fc == 0)) {
    if (DAT_00536414 + 500 < DAT_00522ac8) {
      param_1 = (int *)((iVar8 + iVar5 * 2) / 3);
    }
    if (DAT_00522ac8 < DAT_00536414 + -500) {
      param_1 = (int *)((iVar5 + iVar8 * 2) / 3);
    }
  }
  if (iVar4 == 1) {
    dStack_14 = (_DAT_005259d0 * _DAT_004cc418) / (double)*(int *)(&DAT_0050f6d0 + param_6 * 4);
  }
  if (((iVar4 == 2) && (dStack_14 = _DAT_005259d0 * _DAT_004cc420, DAT_0053527c == 1)) &&
     (DAT_005364c8 == 0)) {
    dStack_14 = dStack_14 * _DAT_004cc428;
  }
  if (((iVar4 == 2) && (DAT_004da19c == 8)) && (DAT_004f8b78 == 0)) {
    dStack_14 = _DAT_005259d0 * _DAT_004cc430;
  }
  if (((iVar4 == 2) && (DAT_004da19c == 8)) && (DAT_004f8b78 == 1)) {
    dStack_14 = _DAT_005259d0 * _DAT_004cc438;
  }
  if ((0 < DAT_004da1f8) && (iVar4 == 2)) {
    dStack_14 = _DAT_005259d0 * _DAT_004cc440;
  }
  if ((DAT_004da1f8 == 7) || (DAT_004da1f8 == 10)) {
    if (iVar4 == 2) {
      dStack_14 = _DAT_005259d0 * _DAT_004cc420;
      goto LAB_004083ac;
    }
  }
  else {
LAB_004083ac:
    if ((iVar4 == 2) &&
       ((((DAT_004fb5d4 == 1 || (DAT_004da1f8 == 2)) || (DAT_004da1f8 == 3)) ||
        ((DAT_004da1f8 == 0xb || (DAT_004da1f8 == 9)))))) {
      dStack_14 = _DAT_005259d0 * _DAT_004cc448;
    }
  }
  if ((2 < iVar4) &&
     (dStack_14 = (_DAT_0050f6e0 * _DAT_004cc450) / (double)DAT_00525a9c, DAT_004f69b8 == 4)) {
    dStack_14 = (_DAT_0050f6e0 * _DAT_004cc458) / (double)DAT_00525a9c;
  }
  if (2 < iVar4) {
    if ((DAT_004f69b8 == 2) || (DAT_004f69b8 == 3)) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc460) / (double)DAT_00525a9c;
    }
    if (2 < iVar4) {
      if ((DAT_0053527c == 1) && (DAT_005364c8 == 0)) {
        dStack_14 = dStack_14 * _DAT_004cc468;
      }
      if (2 < iVar4) {
        if ((DAT_004da19c == 8) && (DAT_004f8b78 == 0)) {
          dStack_14 = (_DAT_0050f6e0 * _DAT_004cc470) / (double)DAT_00525a9c;
        }
        if (2 < iVar4) {
          if ((DAT_004da19c == 8) && (DAT_004f8b78 == 1)) {
            dStack_14 = (_DAT_0050f6e0 * _DAT_004cc478) / (double)DAT_00525a9c;
          }
          if (((2 < iVar4) && (DAT_004f4510 == 1)) && (DAT_0053527c == 1)) {
            dStack_14 = (_DAT_0050f6e0 * _DAT_004cc480) / (double)DAT_00525a9c;
          }
        }
      }
    }
  }
  if (DAT_004da1f8 == 1) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc478) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc488) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 2) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc490) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc498) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 3) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4a0) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4a8) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 4) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4b0) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4b8) / (double)DAT_00525a9c;
    }
  }
  if ((DAT_004da1f8 == 5) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
    dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4c0) / (double)DAT_00525a9c;
  }
  if (DAT_004da1f8 == 6) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc490) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4a8) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 7) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc478) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc488) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 9) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4c8) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4d0) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 10) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc490) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4a8) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 0xb) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4d8) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4d0) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 0xc) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc490) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4a8) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 0x67) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc480) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4e0) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 0x69) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc480) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4e0) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 0x68) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc490) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4e0) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 100) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc498) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4e8) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 0x65) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc498) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4e8) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 0x6a) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc480) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc488) / (double)DAT_00525a9c;
    }
  }
  if (DAT_004da1f8 == 999) {
    if ((DAT_0053527c == 1) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4b0) / (double)DAT_00525a9c;
    }
    if ((DAT_0053527c == 0) && (((iVar4 == 3 || (iVar4 == 4)) || (iVar4 == 5)))) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4e8) / (double)DAT_00525a9c;
    }
    if (DAT_005363b0 == 0) {
      dStack_14 = (_DAT_0050f6e0 * _DAT_004cc4f0) / (double)DAT_004da238;
    }
  }
  if (((((DAT_004da200 == 1) && (0 < DAT_004da1f8)) && (DAT_004da1f8 != 0xb)) &&
      ((DAT_004da1f8 != 5 && (DAT_004da1f8 != 6)))) && (2 < iVar4)) {
    dStack_14 = dStack_14 * _DAT_004cc4f8;
  }
  if ((iVar4 == 2) && (0 < DAT_004da1f8)) {
    dStack_14 = dStack_14 * _DAT_004cc4f8;
  }
  if (DAT_004da200 == 1) {
    if (DAT_004da1f8 == 0xb) {
      dStack_14 = dStack_14 * _DAT_004cc500;
    }
    if (DAT_004da1f8 == 5) {
      dStack_14 = dStack_14 * _DAT_004cc508;
    }
    if (DAT_004da1f8 == 6) {
      dStack_14 = dStack_14 * _DAT_004cc510;
    }
    if (DAT_004da1f8 == 0) {
      dStack_14 = dStack_14 * _DAT_004cc508;
    }
  }
  if (DAT_004da200 == 2) {
    dStack_14 = dStack_14 * _DAT_004cc518;
  }
  if (DAT_004da200 == 3) {
    dStack_14 = dStack_14 * _DAT_004cc520;
  }
  if (DAT_004da200 == 4) {
    dStack_14 = dStack_14 * _DAT_004cc528;
  }
  if (DAT_004da200 == 5) {
    dStack_14 = dStack_14 * _DAT_004cc530;
  }
  if (DAT_004da1f8 == 0) {
    if (iVar4 == 2) {
      dVar2 = _DAT_004cc548;
      if ((DAT_004da19c == 8) && (DAT_004f8b78 == 0)) {
        dVar2 = _DAT_004cc540;
      }
      dStack_14 = dStack_14 * dVar2;
    }
    else {
      dStack_14 = dStack_14 * _DAT_004cc538;
    }
  }
  if (iVar4 == 1) {
    iStack_38 = (int)(longlong)*(double *)(&DAT_004f6af8 + param_6 * 8);
    iVar8 = (int)(longlong)*(double *)(&DAT_004f6c10 + param_6 * 8);
  }
  else {
    iStack_38 = DAT_00536410;
    iVar8 = DAT_00536414;
  }
  if (DAT_00536434 == 1) {
    FUN_0040a6c0(original_dc,dStack_14,iStack_40,(int)param_1);
  }
  if (DAT_00536438 == 1) {
    FUN_0040aab0(original_dc,dStack_14,iStack_40,(int)param_1);
  }
  if (2 < iVar4) {
    if ((DAT_004f69b8 < 2) && (DAT_004da1f8 == 0)) {
      FUN_00432af0(original_dc,iStack_40,(int)param_1,dStack_14,iStack_38,iVar8,iVar4,param_6);
    }
    if (2 < iVar4) {
      if ((1 < DAT_004f69b8) && (DAT_004da1f8 == 0)) {
        FUN_004659d0(original_dc,iStack_40,(int)param_1,dStack_14,iStack_38,iVar8,iVar4,param_6);
      }
      if ((2 < iVar4) && (0 < DAT_004da1f8)) {
        iStack_34 = DAT_00511374;
        if (DAT_005364b0 == 1) {
          iStack_34 = DAT_00535e3c + DAT_00511374;
        }
        iStack_34 = iStack_34 + DAT_00522f08;
        iVar4 = DAT_00522f08;
        while (iVar4 = iVar4 + 1, iVar5 = DAT_00522f08, iVar4 <= iStack_34) {
          FUN_00468440(original_dc,iStack_38,iVar8,iStack_40,(int)param_1,dStack_14,iVar4,0,1,
                       param_7,param_6);
        }
        for (; 0 < iVar5; iVar5 = iVar5 + -1) {
          FUN_00468440(original_dc,iStack_38,iVar8,iStack_40,(int)param_1,dStack_14,iVar5,0,0,
                       param_7,param_6);
        }
        if (DAT_004da1f8 == 0xb) {
          DAT_004da220 = DAT_00535238;
        }
        if (DAT_004da1f8 == 6) {
          DAT_004da220 = DAT_00535250;
        }
        if (DAT_004da1f8 == 100) {
          DAT_004da21c = DAT_00535240;
          DAT_004da220 = DAT_0053522c;
          DAT_004da228 = DAT_004f4b74;
        }
        if (DAT_004da1f8 == 0x65) {
          DAT_004da21c = DAT_00535248;
          DAT_004da220 = DAT_00535230;
          DAT_004da224 = DAT_004f4b80;
          DAT_004da228 = DAT_004f4b74;
        }
        if (DAT_004da1f8 == 0x66) {
          DAT_004da220 = DAT_0053524c;
          DAT_004da224 = DAT_004f4b70;
        }
        if (DAT_004da1f8 == 0x67) {
          DAT_004da21c = DAT_00535234;
          DAT_004da224 = DAT_004f4b6c;
        }
        if (DAT_004da1f8 == 0x68) {
          DAT_004da220 = DAT_0053524c;
          DAT_004da224 = DAT_004f9930;
          DAT_004da228 = DAT_004f4b80;
        }
        if (DAT_004da1f8 == 0x69) {
          DAT_004da228 = DAT_004f4b6c;
        }
        if (DAT_004da1f8 == 0x6a) {
          DAT_004da220 = DAT_0053523c;
          DAT_004da224 = DAT_004f4b80;
        }
        if (DAT_004da1f8 == 999) {
          DAT_004da220 = -12000;
          DAT_004da21c = 12000;
        }
        if (((((DAT_004da21c < 30000) || (DAT_004da224 < 30000)) || (-30000 < DAT_004da220)) ||
            (-30000 < DAT_004da228)) && (DAT_004da200 < 2)) {
          iVar4 = DAT_004da21c - DAT_00536410;
          iVar5 = DAT_004da220 - DAT_00536410;
          dVar2 = (double)(int)param_1;
          iVar7 = DAT_004da224 - DAT_00536414;
          iVar6 = DAT_004da228 - DAT_00536414;
          FUN_00469650(original_dc);
          Rectangle((HDC)original_dc[1],
                    (int)(longlong)((double)iVar4 * dStack_14 + (double)iStack_40),0,DAT_004fe624,
                    DAT_004fe2a8);
          Rectangle((HDC)original_dc[1],0,0,
                    (int)(longlong)((double)iVar5 * dStack_14 + (double)iStack_40),DAT_004fe2a8);
          Rectangle((HDC)original_dc[1],0,(int)(longlong)((double)iVar7 * dStack_14 + dVar2),
                    DAT_004fe624,DAT_004fe2a8);
          Rectangle((HDC)original_dc[1],0,(int)(longlong)((double)iVar6 * dStack_14 + dVar2),
                    DAT_004fe624,0);
        }
      }
    }
  }
  iVar4 = param_7;
  if (((param_7 == 3) && (0 < DAT_004da1f8)) && (DAT_005364fc == 0)) {
    FUN_0046a890(original_dc,iStack_40,(int)param_1,dStack_14);
  }
  iVar5 = param_6;
  if ((iVar4 < 3) && (0 < DAT_004da1f8)) {
    FUN_00489980(original_dc,iStack_40,(int)param_1,dStack_14,param_6,param_7);
  }
  DAT_005230b8 = FUN_00440350(iVar5);
  if (DAT_005364fc == 0) {
    FUN_00431ab0(original_dc,iStack_40,(int)param_1,dStack_14,iStack_38,iVar8,param_7,iVar5,param_2,
                 param_3,param_4,param_5);
  }
  if (param_7 < 3) {
    if ((DAT_004f69b8 < 2) && (DAT_004da1f8 == 0)) {
      FUN_00432af0(original_dc,iStack_40,(int)param_1,dStack_14,iStack_38,iVar8,param_7,iVar5);
    }
    if (param_7 < 3) {
      if ((1 < DAT_004f69b8) && (DAT_004da1f8 == 0)) {
        FUN_004659d0(original_dc,iStack_40,(int)param_1,dStack_14,iStack_38,iVar8,param_7,iVar5);
      }
      if ((param_7 < 3) && (0 < DAT_004da1f8)) {
        iVar4 = DAT_00511374;
        if (DAT_005364b0 == 1) {
          iVar4 = DAT_00511374 + DAT_00535e3c;
        }
        iVar4 = iVar4 + DAT_00522f08;
        iVar5 = DAT_00522f08;
        while (iVar5 = iVar5 + 1, iVar6 = DAT_00522f08, iVar5 <= iVar4) {
          FUN_00468440(original_dc,iStack_38,iVar8,iStack_40,(int)param_1,dStack_14,iVar5,1,1,
                       param_7,param_6);
        }
        for (; 0 < iVar6; iVar6 = iVar6 + -1) {
          FUN_00468440(original_dc,iStack_38,iVar8,iStack_40,(int)param_1,dStack_14,iVar6,1,0,
                       param_7,param_6);
        }
      }
    }
  }
  iVar8 = param_2;
  if (DAT_00536434 == 1) {
    FUN_0040b920(original_dc,param_2,param_3,param_4,param_5);
  }
  if (DAT_00536438 == 1) {
    FUN_0040ad30(original_dc,iVar8,param_3,param_4,param_5);
  }
  if ((DAT_005233a8 == 1) && (DAT_005364fc == 0)) {
    FUN_0040b130(original_dc,iVar8,param_3,param_4,param_5);
  }
  if (DAT_005363f4 < 1) {
    (*pcVar1)(original_dc,7);
    if (((param_7 == 3) || (param_7 == 4)) || (param_7 == 5)) {
      FUN_0047cea0(original_dc,dStack_14,iStack_40,(int)param_1);
    }
    iVar4 = param_3;
    if (param_7 == 1) {
      param_5 = DAT_004fe2a8 / 0x1c;
      (**(code **)(*original_dc + 0x34))(original_dc,0x7f7f7f);
      param_4 = *(undefined4 *)(*original_dc + 0x38);
      if (DAT_005363e4 == 0) {
        iVar5 = 0xffff00;
      }
      else {
        iVar5 = 0xffffff;
      }
      (*(code *)param_4)(original_dc,iVar5);
      if (param_6 == 1) {
        param_3 = (int)(longlong)((double)DAT_004fe624 * _DAT_004cc420) + iVar8;
        iVar5 = param_5 + iVar4;
        FUN_00463f50(original_dc,iVar8,iVar4,param_3,iVar5,1,-1);
        FUN_004b0613((Tact2010CString *)&param_1,s_down_004da91c);
        uStack_4 = 5;
        param_2 = *(undefined4 *)(*original_dc + 100);
        (*(code *)param_2)(original_dc,iVar8 + 3,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        FUN_00463f50(original_dc,iVar8 + 1,iVar4,param_3,iVar5,0,-1);
        iVar5 = iVar5 + 2;
        if (((iVar8 < DAT_004fe75c) && (DAT_004fe75c < param_3)) &&
           ((DAT_005233a4 < iVar5 && (iVar4 = iVar5 - param_5, iVar4 < DAT_005233a4)))) {
          DAT_0050f6d4 = DAT_0050f6d4 / 2;
          if (DAT_0050f6d4 < 2) {
            DAT_0050f6d4 = 2;
          }
          DAT_005233a4 = 0;
          (*(code *)param_4)(original_dc,0);
          FUN_004b0613((Tact2010CString *)&param_1,s_down_004da91c);
          uStack_4 = 6;
          (*(code *)param_2)(original_dc,iVar8 + 3,iVar4 + -2,(char *)param_1,param_1[-2]);
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_1);
        }
        iVar4 = param_5 + iVar5;
        FUN_00463f50(original_dc,iVar8,iVar5,param_3,iVar4,1,-1);
        if (DAT_005363e4 == 0) {
          iVar6 = 0xffff00;
        }
        else {
          iVar6 = 0xffffff;
        }
        (*(code *)param_4)(original_dc,iVar6);
        FUN_004b0613((Tact2010CString *)&param_1,&DAT_004da918);
        uStack_4 = 7;
        (*(code *)param_2)(original_dc,iVar8 + 5,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        FUN_00463f50(original_dc,iVar8,iVar5,param_3,iVar4,0,-1);
        if (((iVar8 < DAT_004fe75c) && (DAT_004fe75c < param_3)) &&
           ((DAT_005233a4 < iVar4 && (iVar5 = iVar4 - param_5, iVar5 < DAT_005233a4)))) {
          DAT_0050f6d4 = DAT_0050f6d4 * 2;
          if (DAT_004fe770 < DAT_0050f6d4) {
            DAT_0050f6d4 = DAT_004fe770;
          }
          DAT_005233a4 = 0;
          (*(code *)param_4)(original_dc,0);
          FUN_004b0613((Tact2010CString *)&param_3,&DAT_004da918);
          uStack_4 = 8;
          (*(code *)param_2)(original_dc,iVar8 + 5,iVar5,(char *)param_3,*(int *)(param_3 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_3);
        }
      }
      if (param_6 == 2) {
        param_6 = param_5 + iVar4;
        iVar5 = (int)(longlong)((double)DAT_004fe624 * _DAT_004cc550) + iVar8;
        FUN_00463f50(original_dc,iVar8,iVar4,iVar5,param_6,1,1);
        if (DAT_005363e4 == 0) {
          iVar6 = 0xffff00;
        }
        else {
          iVar6 = 0xffffff;
        }
        (*(code *)param_4)(original_dc,iVar6);
        FUN_004b0613((Tact2010CString *)&param_3,"down Z");
        uStack_4 = 9;
        param_2 = *(undefined4 *)(*original_dc + 100);
        (*(code *)param_2)(original_dc,iVar8 + 3,iVar4,(char *)param_3,*(int *)(param_3 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_3);
        FUN_00463f50(original_dc,iVar8,iVar4,iVar5,param_6,0,1);
        iVar4 = param_6;
        param_6 = param_5 + param_6;
        FUN_00463f50(original_dc,iVar8,iVar4,iVar5,param_6,1,1);
        if (DAT_005363e4 == 0) {
          iVar6 = 0xffff00;
        }
        else {
          iVar6 = 0xffffff;
        }
        (*(code *)param_4)(original_dc,iVar6);
        FUN_004b0613((Tact2010CString *)&param_4,&DAT_004da908);
        uStack_4 = 10;
        (*(code *)param_2)(original_dc,iVar8 + 3,iVar4,(char *)param_4,*(int *)(param_4 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_4);
        FUN_00463f50(original_dc,iVar8,iVar4,iVar5,param_6,0,1);
      }
    }
    if ((2 < param_7) && (DAT_005363f4 == 0)) {
      FUN_004b4a1f(original_dc,1);
      if (DAT_004fe624 < 0x3e9) {
        iVar8 = DAT_004fe624 / 0xc;
      }
      else {
        iVar8 = DAT_004fe624 / 0xe;
      }
      iVar8 = iVar8 + (DAT_004fe624 >> 0x1f);
      iVar8 = iVar8 - (iVar8 >> 0x1f);
      param_4 = iVar8;
      if (param_7 == 3) {
        iVar4 = iVar8 + 5;
        iVar5 = (int)(DAT_004fe2a8 + (DAT_004fe2a8 >> 0x1f & 0xfU)) >> 4;
        if (DAT_005364fc == 1) {
          iVar5 = 2;
        }
        iVar6 = iVar5 + 0x14;
        param_6 = iVar6;
        FUN_00463f50(original_dc,5,iVar5,iVar4,iVar6,1,-1);
        if (DAT_004da200 == 0) {
          if (DAT_005363e4 == 0) {
            iVar6 = 0xff0000;
          }
          else {
            iVar6 = 0xffffff;
          }
          iVar7 = *original_dc;
          (**(code **)(iVar7 + 0x38))(original_dc,iVar6);
          FUN_004b0613((Tact2010CString *)&param_2,s_zoom_out_004da8fc);
          uStack_4 = 0xb;
          (**(code **)(iVar7 + 100))(original_dc,9,iVar5,(char *)param_2,*(int *)(param_2 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_2);
          iVar6 = param_6;
        }
        if (DAT_004da200 == 1) {
          if (DAT_005363e4 == 0) {
            iVar6 = 0x7f;
          }
          else {
            iVar6 = 0xffffff;
          }
          iVar7 = *original_dc;
          (**(code **)(iVar7 + 0x38))(original_dc,iVar6);
          FUN_004b0613((Tact2010CString *)&param_2,s_zoom_in_004da8f4);
          uStack_4 = 0xc;
          (**(code **)(iVar7 + 100))(original_dc,9,iVar5,(char *)param_2,*(int *)(param_2 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_2);
          iVar6 = param_6;
        }
        if ((((5 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) && (iVar5 < DAT_005233a4)) &&
           ((DAT_005233a4 < iVar6 && (DAT_005364fc == 0)))) {
          DAT_004da200 = DAT_004da200 + 1;
          DAT_005233a4 = 0;
          DAT_004fe75c = 0;
          if (1 < DAT_004da200) {
            DAT_004da200 = 0;
          }
        }
        if (DAT_005364fc == 1) {
          if (((5 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) && (DAT_005233a4 < iVar6)) {
            DAT_004da200 = DAT_004da200 + 1;
            DAT_005233a4 = 0;
            DAT_004fe75c = 0;
            if (1 < DAT_004da200) {
              DAT_004da200 = 0;
            }
          }
          iVar4 = iVar8 + 0x19;
          param_4 = iVar4 + param_4 * 2;
          FUN_00463f50(original_dc,iVar4,iVar5,param_4,param_6,1,-1);
          iVar6 = *original_dc;
          (**(code **)(iVar6 + 0x38))(original_dc,0x7fff);
          FUN_004b0613((Tact2010CString *)&param_7,"Race area creation completed");
          uStack_4 = 0xd;
          (**(code **)(iVar6 + 100))
                    (original_dc,iVar8 + 0x1d,iVar5,(char *)param_7,*(int *)(param_7 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_7);
          if (((iVar4 < DAT_004fe75c) && (DAT_004fe75c < param_4)) && (DAT_005233a4 < param_6)) {
            DAT_005364fc = 0;
            DAT_005233a4 = 0;
            DAT_004fe75c = 0;
            SelectObject(hdc,h_00);
            DeleteObject(h);
            FUN_00413bc0(original_dc);
          }
          if (DAT_004fe624 < 1000) {
            iVar8 = (DAT_004fe2a8 << 2) / 5 + -0xf;
          }
          else {
            iVar8 = (DAT_004fe2a8 * 4) / 5 + 10;
          }
          FUN_004b4a1f(original_dc,1);
          FUN_0048cf50(original_dc,iVar8);
          FUN_004b4a1f(original_dc,2);
          SelectObject(hdc,h_00);
          DeleteObject(h);
          *unaff_FS_OFFSET = uStack_c;
          return;
        }
        (**(code **)(*original_dc + 0x38))(original_dc,0xffff00);
        if (0 < DAT_005359d0) {
          if (DAT_004fe624 < 0x3e9) {
            iVar4 = DAT_004fe624 / 9;
          }
          else {
            iVar4 = DAT_004fe624 / 0xb;
          }
          iVar6 = iVar8 + 0xf;
          iVar4 = iVar4 + iVar6;
          FUN_00463f50(original_dc,iVar6,iVar5,iVar4,param_6,1,-1);
          FUN_004b0613((Tact2010CString *)&param_4,s_current_chart_004da8d0);
          uStack_4 = 0xe;
          (**(code **)(*original_dc + 100))
                    (original_dc,iVar8 + 0x13,iVar5,(char *)param_4,*(int *)(param_4 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_4);
          if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) &&
             ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_6)))) {
            DAT_00536438 = DAT_00536438 + 1;
            if (1 < DAT_00536438) {
              DAT_00536438 = 0;
            }
            DAT_005233a8 = 0;
            DAT_005363f0 = 0;
            DAT_00536434 = 0;
            DAT_00536404 = 0;
            DAT_005233a4 = 0;
            DAT_004da200 = 0;
          }
        }
        if (DAT_004fe624 < 0x3e9) {
          iVar8 = DAT_004fe624 / 10;
        }
        else {
          iVar8 = DAT_004fe624 / 0xc;
        }
        iVar6 = iVar4 + 10;
        iVar8 = iVar8 + iVar6;
        FUN_00463f50(original_dc,iVar6,iVar5,iVar8,param_6,1,-1);
        FUN_004b0613((Tact2010CString *)&param_4,s_wind_chart_004da8c4);
        uStack_4 = 0xf;
        param_2 = *(undefined4 *)(*original_dc + 100);
        (*(code *)param_2)(original_dc,iVar4 + 0xe,iVar5,(char *)param_4,*(int *)(param_4 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_4);
        if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar8)) &&
           ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_6)))) {
          DAT_00536434 = DAT_00536434 + 1;
          if (1 < DAT_00536434) {
            DAT_00536434 = 0;
          }
          DAT_005233a8 = 0;
          DAT_005363f0 = 0;
          DAT_00536438 = 0;
          DAT_00536404 = 0;
          DAT_005233a4 = 0;
          DAT_004da200 = 0;
        }
        if (DAT_004fe624 < 0x3e9) {
          iVar4 = DAT_004fe624 / 0xd;
        }
        else {
          iVar4 = (int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 0xfU)) >> 4;
        }
        iVar6 = iVar8 + 10;
        iVar4 = iVar4 + iVar6;
        FUN_00463f50(original_dc,iVar6,iVar5,iVar4,param_6,1,-1);
        FUN_004b0613((Tact2010CString *)&param_4,s_weather_004da8bc);
        uStack_4 = 0x10;
        (*(code *)param_2)(original_dc,iVar8 + 0xe,iVar5,(char *)param_4,*(int *)(param_4 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_4);
        if ((((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) && (iVar5 < DAT_005233a4)) &&
           (DAT_005233a4 < param_6)) {
          DAT_005363f0 = 1;
          DAT_005363b4 = 0;
          DAT_00536404 = 0;
          DAT_005233a8 = 0;
          DAT_00536444 = 0;
          DAT_004fafa0 = 1;
          DAT_00536438 = 0;
          DAT_00536434 = 0;
          DAT_005233a4 = 0;
          FUN_004298f0(original_dc);
        }
        if (DAT_005363f0 == 0) {
          if (DAT_004fe624 < 0x3e9) {
            iVar8 = DAT_004fe624 / 9;
          }
          else {
            iVar8 = DAT_004fe624 / 0xb;
          }
          iVar6 = iVar4 + 10;
          FUN_00463f50(original_dc,iVar6,iVar5,iVar8 + iVar6,param_6,1,-1);
          FUN_004b0613((Tact2010CString *)&param_4,s_sailing_view_004da8ac);
          uStack_4 = 0x11;
          (*(code *)param_2)(original_dc,iVar4 + 0xe,iVar5,(char *)param_4,*(int *)(param_4 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_4);
          if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar8 + iVar6)) &&
             ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_6)))) {
            DAT_00536434 = 0;
            DAT_005233a8 = 0;
            DAT_005363f0 = 0;
            DAT_00536438 = 0;
            DAT_00536404 = 0;
            DAT_005233a4 = 0;
          }
        }
      }
      if ((param_7 == 4) || (param_7 == 5)) {
        if (DAT_004fe624 < 0x3e9) {
          iVar8 = DAT_004fe624 / 0xc;
        }
        else {
          iVar8 = DAT_004fe624 / 0xe;
        }
        FUN_00463f50(original_dc,5,0x15,iVar8 + 5,0x29,1,-1);
        iVar4 = *original_dc;
        (**(code **)(iVar4 + 0x38))(original_dc,0xffff00);
        if (DAT_004da200 == 0) {
          FUN_004b0613((Tact2010CString *)&param_7,s_zoom_out_004da8fc);
          uStack_4 = 0x12;
          (**(code **)(iVar4 + 100))(original_dc,9,0x15,(char *)param_7,*(int *)(param_7 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_7);
        }
        if (DAT_004da200 == 1) {
          FUN_004b0613((Tact2010CString *)&param_7,s_zoom_in_004da8f4);
          uStack_4 = 0x13;
          (**(code **)(iVar4 + 100))(original_dc,9,0x15,(char *)param_7,*(int *)(param_7 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_7);
        }
        if ((((5 < DAT_004fe75c) && (DAT_004fe75c < iVar8 + 5)) && (0x15 < DAT_005233a4)) &&
           (DAT_005233a4 < 0x29)) {
          DAT_005233a4 = 0;
          DAT_004da200 = DAT_004da200 + 1;
          if (1 < DAT_004da200) {
            DAT_004da200 = 0;
          }
        }
        if (DAT_004fe624 < 0x3e9) {
          iVar8 = DAT_004fe624 / 9;
        }
        else {
          iVar8 = DAT_004fe624 / 0xb;
        }
        iVar5 = iVar8 + 5;
        iVar6 = iVar8 + iVar5;
        FUN_00463f50(original_dc,iVar5,0x15,iVar6,0x29,1,-1);
        (**(code **)(iVar4 + 0x38))(original_dc,0xffff00);
        FUN_004b0613((Tact2010CString *)&param_7,s_race_course_004da8a0);
        pcVar1 = *(code **)(iVar4 + 100);
        uStack_4 = 0x14;
        (*pcVar1)(original_dc,iVar8 + 9,0x15,(char *)param_7,*(int *)(param_7 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_7);
        if (((iVar5 < DAT_004fe75c) && (DAT_004fe75c < iVar6)) &&
           ((0x15 < DAT_005233a4 && (DAT_005233a4 < 0x29)))) {
          DAT_005233a8 = 1;
          DAT_00536434 = 0;
          DAT_005363f0 = 0;
          DAT_00536438 = 0;
          DAT_00536404 = 0;
          DAT_005233a4 = 0;
        }
        iVar8 = iVar6;
        if (DAT_00536438 == 1) {
          if (DAT_004fe624 < 0x3e9) {
            iVar8 = DAT_004fe624 / 10;
          }
          else {
            iVar8 = DAT_004fe624 / 0xc;
          }
          iVar4 = iVar6 + 10;
          iVar8 = iVar8 + iVar4;
          FUN_00463f50(original_dc,iVar4,0x15,iVar8,0x29,1,-1);
          FUN_004b0613((Tact2010CString *)&param_7,s_wind_chart_004da8c4);
          uStack_4 = 0x15;
          (*pcVar1)(original_dc,iVar6 + 0xe,0x15,(char *)param_7,*(int *)(param_7 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_7);
          if (((iVar4 < DAT_004fe75c) && (DAT_004fe75c < iVar8)) &&
             ((0x15 < DAT_005233a4 && (DAT_005233a4 < 0x29)))) {
            DAT_00536434 = DAT_00536434 + 1;
            if (1 < DAT_00536434) {
              DAT_00536434 = 0;
            }
            DAT_005233a8 = 0;
            DAT_005363f0 = 0;
            DAT_00536438 = 0;
            DAT_00536404 = 0;
            DAT_005233a4 = 0;
          }
        }
        iVar4 = iVar8;
        if ((DAT_00536434 == 1) && (0 < DAT_005359d0)) {
          if (DAT_004fe624 < 0x3e9) {
            iVar4 = DAT_004fe624 / 9;
          }
          else {
            iVar4 = DAT_004fe624 / 0xb;
          }
          iVar5 = iVar8 + 10;
          iVar4 = iVar4 + iVar5;
          FUN_00463f50(original_dc,iVar5,0x15,iVar4,0x29,1,-1);
          FUN_004b0613((Tact2010CString *)&param_7,s_current_chart_004da8d0);
          uStack_4 = 0x16;
          (*pcVar1)(original_dc,iVar8 + 0xe,0x15,(char *)param_7,*(int *)(param_7 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_7);
          if ((((iVar5 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) && (0x15 < DAT_005233a4)) &&
             (DAT_005233a4 < 0x29)) {
            DAT_00536438 = DAT_00536438 + 1;
            if (1 < DAT_00536438) {
              DAT_00536438 = 0;
            }
            DAT_005233a8 = 0;
            DAT_005363f0 = 0;
            DAT_00536434 = 0;
            DAT_00536404 = 0;
            DAT_005233a4 = 0;
          }
        }
        if (DAT_004fe624 < 0x3e9) {
          iVar8 = DAT_004fe624 / 9;
        }
        else {
          iVar8 = DAT_004fe624 / 0xb;
        }
        iVar5 = iVar4 + 10;
        iVar8 = iVar8 + iVar5;
        FUN_00463f50(original_dc,iVar5,0x15,iVar8,0x29,1,-1);
        FUN_004b0613((Tact2010CString *)&param_7,s_sailing_view_004da8ac);
        uStack_4 = 0x17;
        (*pcVar1)(original_dc,iVar4 + 0xe,0x15,(char *)param_7,*(int *)(param_7 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_7);
        if (((iVar5 < DAT_004fe75c) && (DAT_004fe75c < iVar8)) &&
           ((0x15 < DAT_005233a4 && (DAT_005233a4 < 0x29)))) {
          DAT_00536434 = 0;
          DAT_005233a8 = 0;
          DAT_005363f0 = 0;
          DAT_00536438 = 0;
          DAT_00536404 = 0;
          DAT_005233a4 = 0;
        }
        if (DAT_00536438 == 1) {
          if (DAT_004fe624 < 0x3e9) {
            iVar4 = DAT_004fe624 / 7;
          }
          else {
            iVar4 = (int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3;
          }
          iVar5 = iVar8 + 10;
          FUN_00463f50(original_dc,iVar5,0x15,iVar4 + iVar5,0x29,1,-1);
          FUN_004b0613((Tact2010CString *)&param_7,s_advance_time_1_hr_004da88c);
          uStack_4 = 0x18;
          (*pcVar1)(original_dc,iVar8 + 0xe,0x15,(char *)param_7,*(int *)(param_7 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_7);
          if (((iVar5 < DAT_004fe75c) && (DAT_004fe75c < iVar4 + iVar5)) &&
             ((0x15 < DAT_005233a4 && (DAT_005233a4 < 0x29)))) {
            DAT_005233a4 = 0;
            DAT_00536404 = DAT_00536404 + 1;
          }
        }
      }
    }
  }
  else {
    FUN_004b4a1f(original_dc,1);
    if (DAT_004fe624 < 0x3e9) {
      iVar8 = (int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3;
    }
    else {
      iVar8 = DAT_004fe624 / 10;
    }
    iVar5 = DAT_004fe2a8 - DAT_004fe2a8 / 6;
    FUN_00463f50(original_dc,5,iVar5,iVar8 + 5,iVar5 + 0x14,1,-1);
    iVar4 = *original_dc;
    param_4 = *(undefined4 *)(iVar4 + 0x38);
    if (DAT_005363e4 == 0) {
      iVar6 = 0xff0000;
    }
    else {
      iVar6 = 0xffffff;
    }
    (*(code *)param_4)(original_dc,iVar6);
    FUN_004b0613((Tact2010CString *)&param_7,s_Return_to_results_004da980);
    pcVar1 = *(code **)(iVar4 + 100);
    uStack_4 = 0;
    (*pcVar1)(original_dc,9,iVar5,(char *)param_7,*(int *)(param_7 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_7);
    if ((((5 < DAT_004fe75c) && (DAT_004fe75c < iVar8 + 5)) && (iVar5 + -0x3c < DAT_005233a4)) &&
       (DAT_005233a4 < iVar5 + 0x14)) {
      DAT_005233a8 = DAT_005233a8 + 1;
      if (1 < (int)DAT_005233a8) {
        DAT_005233a8 = 0;
      }
      DAT_00536404 = 0;
      DAT_00536434 = 0;
      DAT_00536438 = 0;
      DAT_005363f0 = 0;
      DAT_005233a4 = 0;
      DAT_004fe75c = 0;
    }
    if (DAT_005363e4 == 0) {
      iVar8 = 0xff;
    }
    else {
      iVar8 = 0xffffff;
    }
    (*(code *)param_4)(original_dc,iVar8);
    FUN_0041f3e0(original_dc,1);
    if (DAT_004f8dbc < 2) {
      FUN_004b0613((Tact2010CString *)&param_7,s_Boat_1_first_tack____________004da94c);
      uStack_4 = 2;
      (*pcVar1)(original_dc,DAT_004fe624 / 3,iVar5,(char *)param_7,*(int *)(param_7 + -8));
    }
    else {
      FUN_004b0613((Tact2010CString *)&param_7,s_Boat_1_tack_______004da96c);
      uStack_4 = 1;
      (*pcVar1)(original_dc,DAT_004fe624 / 3,iVar5,(char *)param_7,*(int *)(param_7 + -8));
    }
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_7);
    if (DAT_004da140 == 1) {
      if (1 < DAT_004f8dbc) {
        FUN_0041f3e0(original_dc,DAT_004f8dbc);
        FUN_004b0613((Tact2010CString *)&param_7,s_Winner_tack________004da938);
        uStack_4 = 3;
        (*pcVar1)(original_dc,DAT_004fe624 / 2,iVar5,(char *)param_7,*(int *)(param_7 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_7);
        FUN_004b4a1f(original_dc,2);
        goto LAB_0040a610;
      }
    }
    else {
      FUN_0041f3e0(original_dc,2);
      FUN_004b0613((Tact2010CString *)&param_7,s_Player_2_tack_______004da924);
      uStack_4 = 4;
      (*pcVar1)(original_dc,DAT_004fe624 / 2,iVar5,(char *)param_7,*(int *)(param_7 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_7);
    }
    FUN_004b4a1f(original_dc,2);
  }
LAB_0040a610:
  SelectObject(hdc,h_00);
  DeleteObject(h);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


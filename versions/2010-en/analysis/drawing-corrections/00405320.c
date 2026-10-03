
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00405320(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  Tact2010CString *pTVar1;
  Tact2010CString *pTVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar7;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  Tact2010CString TStack_48;
  int local_44;
  Tact2010CString local_40;
  Tact2010CString TStack_3c;
  Tact2010CString TStack_38;
  Tact2010CString TStack_34;
  Tact2010CString TStack_30;
  Tact2010CString TStack_2c;
  Tact2010CString TStack_28;
  Tact2010CString local_24;
  Tact2010CString local_20;
  Tact2010CString local_1c [2];
  undefined4 uStack_14;
  code *pcStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  pcStack_10 = FUN_004c1950;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  pHVar8 = (HDC)param_1[1];
  local_20.data = (char *)pHVar8;
  local_1c[0].data = (char *)CreateRectRgn(param_2,param_3,param_4,param_5);
  local_24.data = SelectObject(pHVar8,local_1c[0].data);
  DAT_004f40a8 = (param_4 + param_2) / 2;
  iVar3 = param_5 - param_3;
  DAT_004f4b48 = param_5 - iVar3 / 10;
  if (*(int *)(&DAT_004f71c0 + param_6 * 4) == 1) {
    iVar4 = (int)((ulonglong)((longlong)iVar3 * 0x77777777) >> 0x20) - iVar3;
    DAT_004f4b48 = DAT_004f4b48 + ((iVar4 >> 3) - (iVar4 >> 0x1f));
  }
  if (*(int *)(&DAT_004f71c0 + param_6 * 4) == 2) {
    iVar4 = (int)((ulonglong)((longlong)iVar3 * 0x6db6db6d) >> 0x20) - iVar3;
    DAT_004f4b48 = DAT_004f4b48 + ((iVar4 >> 2) - (iVar4 >> 0x1f));
  }
  if (*(int *)(&DAT_004f71c0 + param_6 * 4) == 3) {
    iVar4 = (int)((ulonglong)((longlong)iVar3 * -0x66666667) >> 0x20);
    DAT_004f4b48 = DAT_004f4b48 + ((iVar4 >> 1) - (iVar4 >> 0x1f));
  }
  if ((600 < DAT_004fe2a8) && (*(int *)(&DAT_004f71c0 + param_6 * 4) < 3)) {
    iVar3 = (int)((ulonglong)((longlong)iVar3 * 0x6db6db6d) >> 0x20) - iVar3;
    DAT_004f4b48 = DAT_004f4b48 + ((iVar3 >> 2) - (iVar3 >> 0x1f));
  }
  FUN_0041e0a0();
  if (DAT_004da140 == 2) {
    FUN_0041e220();
  }
  local_44 = *param_1;
  local_40.data = *(char **)(local_44 + 0x2c);
  DAT_004da148 = (2 < *(int *)(&DAT_004f71c0 + param_6 * 4)) - 1 & 0x1e;
  (*(code *)local_40.data)(param_1,7);
  if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
    if (((DAT_004da1f8 == 0x6a) || (DAT_004da1f8 == 0x69)) ||
       ((DAT_004da1f8 == 999 && (DAT_00536524 == 1)))) {
      if (DAT_004f7ed4 != (HGDIOBJ)0x0) {
        pHVar8 = (HDC)param_1[1];
        pvVar9 = DAT_004f7ed4;
        goto override_prt_405507_6059bb06;
      }
    }
    else if (DAT_004fc15c != (HGDIOBJ)0x0) {
      pHVar8 = (HDC)param_1[1];
      pvVar9 = DAT_004fc15c;
override_prt_405507_6059bb06:
      SelectObject(pHVar8,pvVar9);
    }
  }
  else if (DAT_004fecc4 != (HGDIOBJ)0x0) {
    pHVar8 = (HDC)param_1[1];
    pvVar9 = DAT_004fecc4;
    goto override_prt_405507_6059bb06;
  }
  if (((DAT_00536450 == 1) && (8 < DAT_0052362c)) && (DAT_005363ac != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_005363ac);
  }
  Rectangle((HDC)param_1[1],param_2,param_3,param_4,param_5);
  iVar3 = 1;
  do {
    if (DAT_00536450 == 0) {
      FUN_00445370(param_1,iVar3,param_6,param_2,param_3,param_4,param_5);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  DAT_004da1f4 = 0x18d;
  if (DAT_004da140 == 1) {
    iVar3 = 0;
    do {
      FUN_00466330(param_1,(double)CONCAT44(*(undefined4 *)((int)&DAT_004f7220 + iVar3 * 8 + 4),
                                            *(undefined4 *)(&DAT_004f7220 + iVar3)),
                   (double)CONCAT44(*(undefined4 *)((int)&DAT_004ff038 + iVar3 * 8 + 4),
                                    *(undefined4 *)(&DAT_004ff038 + iVar3)),iVar3,1);
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_004da1f4);
  }
  if (DAT_004da140 == 2) {
    iVar3 = DAT_004da1f4;
    if ((param_6 == 1) && (uVar6 = 0, -1 < DAT_004da1f4)) {
      do {
        uVar5 = (int)uVar6 >> 0x1f;
        if (((uVar6 ^ uVar5) - uVar5 & 1 ^ uVar5) == uVar5) {
          FUN_00466330(param_1,(double)CONCAT44(*(undefined4 *)((int)&DAT_004f7220 + uVar6 * 8 + 4),
                                                *(undefined4 *)(&DAT_004f7220 + uVar6)),
                       (double)CONCAT44(*(undefined4 *)((int)&DAT_004ff038 + uVar6 * 8 + 4),
                                        *(undefined4 *)(&DAT_004ff038 + uVar6)),uVar6,1);
          iVar3 = DAT_004da1f4;
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 <= iVar3);
    }
    if (((DAT_004da140 == 2) && (param_6 == 2)) && (uVar6 = 0, -1 < iVar3)) {
      do {
        uVar5 = (int)uVar6 >> 0x1f;
        if (((uVar6 ^ uVar5) - uVar5 & 1 ^ uVar5) != uVar5) {
          FUN_00466330(param_1,(double)CONCAT44(*(undefined4 *)((int)&DAT_004f7220 + uVar6 * 8 + 4),
                                                *(undefined4 *)(&DAT_004f7220 + uVar6)),
                       (double)CONCAT44(*(undefined4 *)((int)&DAT_004ff038 + uVar6 * 8 + 4),
                                        *(undefined4 *)(&DAT_004ff038 + uVar6)),uVar6,2);
          iVar3 = DAT_004da1f4;
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 <= iVar3);
    }
  }
  if ((param_6 == 1) && (DAT_00522cac == 1)) {
    FUN_00442fd0(param_1,1,param_2,param_3,param_4,param_5,1);
  }
  if ((param_6 == 2) && (DAT_00522d18 == 1)) {
    FUN_00442fd0(param_1,2,param_2,param_3,param_4,param_5,1);
  }
  (*(code *)local_40.data)(param_1,7);
  if ((DAT_005363e4 == 0) && (DAT_004f8d78 < 3)) {
    if ((DAT_004f6d60 == 0x14) || (pvVar9 = DAT_004f4a5c, DAT_004f6d60 == 6)) {
      if (DAT_00522fcc == (HGDIOBJ)0x0) goto LAB_00405789;
      pHVar8 = (HDC)param_1[1];
      pvVar9 = DAT_00522fcc;
    }
    else {
joined_r0x0040577c:
      if (pvVar9 == (HGDIOBJ)0x0) goto LAB_00405789;
      pHVar8 = (HDC)param_1[1];
    }
override_prt_405783_6059bb06:
    SelectObject(pHVar8,pvVar9);
  }
  else {
    pvVar9 = DAT_004fe07c;
    if ((DAT_004f6d60 == 0x14) || (DAT_004f6d60 == 6)) goto joined_r0x0040577c;
    if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      pHVar8 = (HDC)param_1[1];
      pvVar9 = DAT_004f3f5c;
      goto override_prt_405783_6059bb06;
    }
  }
LAB_00405789:
  if ((DAT_00536450 == 1) && (DAT_005363ac != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_005363ac);
  }
  Rectangle((HDC)param_1[1],param_2,param_3,param_4,DAT_004da148);
  if (*(int *)(&DAT_004f71c0 + param_6 * 4) < 3) {
    FUN_00406270(param_1,param_6);
  }
  if (DAT_004da1f8 != 0) goto LAB_0040587c;
  if (DAT_004f69b8 < 2) {
    if (DAT_0050040c == 1) {
      FUN_00440400(param_1,DAT_004da148,2,0x24,param_6,param_2,param_3,param_4,param_5,DAT_004da148)
      ;
    }
    if (DAT_0050040c == 0) {
      iVar3 = 0x24;
      goto LAB_0040585d;
    }
  }
  else {
    iVar3 = 0xb4;
LAB_0040585d:
    FUN_00440400(param_1,DAT_004da148,0,iVar3,param_6,param_2,param_3,param_4,param_5,DAT_004da148);
  }
  FUN_0047e040(param_1,param_2,param_4,param_5,param_6);
LAB_0040587c:
  if (0 < DAT_004da1f8) {
    if (DAT_004da1f8 == 10) {
      FUN_00488870(param_1,param_6);
    }
    if (DAT_004da1f8 == 9) {
      FUN_00488590(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x65) {
      FUN_00486250(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x6a) {
      FUN_004886a0(param_1,param_6);
    }
    if (DAT_004da1f8 == 100) {
      FUN_00485a50(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x65) {
      FUN_00485820(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x66) {
      FUN_00485d00(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x6a) {
      FUN_00485dd0(param_1,param_6);
    }
    if (DAT_004da1f8 == 1) {
      FUN_004840c0(param_1,param_6);
    }
    if (DAT_004da1f8 == 2) {
      FUN_00484d30(param_1,param_6);
    }
    if (DAT_004da1f8 == 3) {
      FUN_004851b0(param_1,param_6);
    }
    if (DAT_004da1f8 == 6) {
      FUN_00487290(param_1,param_6);
    }
    if (DAT_004da1f8 == 7) {
      FUN_00487f80(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x67) {
      FUN_004854d0(param_1,param_6);
    }
    iVar3 = DAT_004fe764;
    if (DAT_004fb5d4 == 0) {
      for (; 0 < iVar3; iVar3 = iVar3 + -1) {
        FUN_0047ed40(param_1,iVar3,param_6);
      }
    }
    else if (DAT_004da1f8 == 4) {
      FUN_0047ed40(param_1,7,param_6);
      FUN_0047ed40(param_1,6,param_6);
      FUN_0047ed40(param_1,3,param_6);
      FUN_0047ed40(param_1,4,param_6);
      FUN_0047ed40(param_1,2,param_6);
      FUN_0047ed40(param_1,1,param_6);
      FUN_0047ed40(param_1,5,param_6);
    }
    else {
      FUN_00481150(param_1,param_6);
    }
    if (DAT_004da1f8 == 1) {
      FUN_00484320(param_1,param_6);
    }
    if (DAT_004da1f8 == 2) {
      FUN_00484e40(param_1,param_6);
    }
    if (DAT_004da1f8 == 3) {
      FUN_00485330(param_1,param_6);
    }
    if (DAT_004fb5d4 == 1) {
      FUN_00486dd0(param_1,param_6);
    }
    if (DAT_004da1f8 == 6) {
      FUN_00487460(param_1,param_6);
    }
    if (DAT_004da1f8 == 7) {
      FUN_00487b50(param_1,param_6);
    }
    if (DAT_004da1f8 == 9) {
      FUN_00488550(param_1,param_6);
    }
    if (DAT_004da1f8 == 0xb) {
      FUN_004889e0(param_1,param_6);
    }
    if (DAT_004da1f8 == 0xc) {
      FUN_00488b20(param_1,param_6);
    }
    if (DAT_004da1f8 == 100) {
      FUN_00486400(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x65) {
      FUN_004862c0(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x66) {
      FUN_00488790(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x67) {
      FUN_00485400(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x69) {
      FUN_00485f10(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x68) {
      FUN_00486060(param_1,param_6);
    }
    if (DAT_004da1f8 == 0x6a) {
      FUN_00488710(param_1,param_6);
    }
  }
  DAT_005230b8 = FUN_00440350(param_6);
  FUN_0043efd0(param_1,param_6,param_2,param_3,param_4,param_5,DAT_004da148);
  FUN_00442270(param_1,param_6,param_4,param_5);
  FUN_00442560(param_1,0,param_6,param_2,param_5,param_4);
  FUN_00442560(param_1,1,param_6,param_2,param_5,param_4);
  FUN_00442560(param_1,-1,param_6,param_2,param_5,param_4);
  (*(code *)local_40.data)(param_1,7);
  if (((DAT_004da140 == 2) && (param_6 == 1)) && (DAT_004f8cd0 < 1)) {
    if (DAT_005363e4 == 0) {
      (**(code **)(local_44 + 0x38))(param_1,0xffff);
    }
    FUN_004b4a1f(param_1,2);
    TStack_28.data = *(char **)(local_44 + 0x34);
    (*(code *)TStack_28.data)(param_1,0);
    uVar6 = (int)DAT_004fb9b8 >> 0x1f;
    if (DAT_005364c8 == 1) {
      pTVar1 = FUN_0041bc70(&TStack_48,
                            (int)(((DAT_004fb9b8 ^ uVar6) - uVar6) +
                                 ((DAT_004fad34 ^ (int)DAT_004fad34 >> 0x1f) -
                                 ((int)DAT_004fad34 >> 0x1f)) * 0x3c) / 5);
      iStack_c = 0;
      pTVar1 = FUN_004b082f(&local_40,&DAT_004da2bc,pTVar1);
      iStack_c._0_1_ = 1;
      pTVar1 = FUN_004b07bb(&TStack_3c,pTVar1,s_sec_004da2b4);
      iStack_c._0_1_ = 2;
      (**(code **)(local_44 + 100))
                (param_1,DAT_004fe624 / 2 + 1,0x14,pTVar1->data,*(int *)(pTVar1->data + -8));
      iStack_c._0_1_ = 1;
      FUN_004b05a5(&TStack_3c);
      iStack_c = (uint)iStack_c._1_3_ << 8;
      FUN_004b05a5(&local_40);
      pTVar1 = &TStack_48;
    }
    else {
      TStack_3c.data = (char *)FUN_0041bc70(&TStack_2c,(DAT_004fb9b8 ^ uVar6) - uVar6);
      iStack_c = 3;
      pTVar1 = FUN_0041bc70(&TStack_30,
                            (DAT_004fad34 ^ (int)DAT_004fad34 >> 0x1f) - ((int)DAT_004fad34 >> 0x1f)
                           );
      iStack_c._0_1_ = 4;
      pTVar1 = FUN_004b082f(&TStack_34,&DAT_004da2bc,pTVar1);
      iStack_c._0_1_ = 5;
      pTVar1 = FUN_004b07bb(&TStack_38,pTVar1,s_min_004da2ac);
      iStack_c._0_1_ = 6;
      pTVar1 = FUN_004b0755(&TStack_48,pTVar1,(Tact2010CString *)TStack_3c.data);
      iStack_c._0_1_ = 7;
      pTVar1 = FUN_004b07bb(&local_40,pTVar1,s_sec_004da2b4);
      iStack_c._0_1_ = 8;
      (**(code **)(local_44 + 100))
                (param_1,DAT_004fe624 / 2 + 1,0x14,pTVar1->data,*(int *)(pTVar1->data + -8));
      iStack_c._0_1_ = 7;
      FUN_004b05a5(&local_40);
      iStack_c._0_1_ = 6;
      FUN_004b05a5(&TStack_48);
      iStack_c._0_1_ = 5;
      FUN_004b05a5(&TStack_38);
      iStack_c._0_1_ = 4;
      FUN_004b05a5(&TStack_34);
      iStack_c = CONCAT31(iStack_c._1_3_,3);
      FUN_004b05a5(&TStack_30);
      pTVar1 = &TStack_2c;
    }
    iStack_c = 0xffffffff;
    FUN_004b05a5(pTVar1);
    FUN_004b4a1f(param_1,1);
    (*(code *)TStack_28.data)(param_1,0xffffff);
  }
  SelectObject((HDC)local_20.data,local_24.data);
  DeleteObject(local_1c[0].data);
  if ((DAT_005363b4 == 1) || (0 < *(int *)(&DAT_005116e0 + param_6 * 4))) {
    FUN_00444350(param_1,param_2,param_6);
  }
  if (DAT_005364b0 == 1) {
    FUN_0048b7e0(param_1);
  }
  if (DAT_004f7084 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  FUN_004b4d9d(param_1,(int *)local_1c,param_2,param_3);
  CDC::LineTo(param_1,param_4,param_3);
  CDC::LineTo(param_1,param_4,param_5);
  CDC::LineTo(param_1,param_2,param_5);
  CDC::LineTo(param_1,param_2,param_3);
  local_40.data = (char *)0x2;
  if (1 < DAT_004da194) {
    iVar3 = 0;
    TStack_48.data = (char *)0x0;
    do {
                    /* WARNING: Load size is inaccurate */
      TStack_3c.data = TStack_48.data[0x5230f8];
      uVar6 = DAT_004fe75c - (int)TStack_3c.data >> 0x1f;
                    /* WARNING: Load size is inaccurate */
      if ((((int)((DAT_004fe75c - (int)TStack_3c.data ^ uVar6) - uVar6) < DAT_004fe624 / 0x3c) &&
          (local_1c[0].data = TStack_48.data[0x522c28],
          uVar6 = DAT_005233a4 - (int)local_1c[0].data >> 0x1f,
          (int)((DAT_005233a4 - (int)local_1c[0].data ^ uVar6) - uVar6) < DAT_004fe624 / 0x3c)) &&
         ((DAT_005233a4 != 0 &&
          (((0 < (int)TStack_3c.data && ((int)TStack_3c.data < DAT_004fe624)) &&
           ((int)local_1c[0].data < DAT_00535564)))))) {
        DAT_004fe630 = DAT_004f8cd0;
        DAT_004da278 = local_40.data;
        DAT_005233a4 = 0;
        if ((-5 < (int)TStack_48.data) && ((int)local_40.data <= DAT_004da194)) {
          fVar7 = FUN_0043ec20(*(double *)((int)&DAT_004f6b08 + iVar3),
                               *(double *)((int)&DAT_004f6c20 + iVar3),0,param_6);
          DAT_004f4e04 = FUN_0041bc20((int)(longlong)(fVar7 * (float10)_DAT_004cc3e8));
          DAT_00536540 = DAT_004fe75c;
        }
      }
      TStack_48.data = TStack_48.data + 4;
      local_40.data = local_40.data + 1;
      iVar3 = iVar3 + 8;
    } while ((int)local_40.data <= DAT_004da194);
  }
  if (((DAT_004f8cd0 < DAT_004fe630 + 5 + DAT_004da174 * 2) && (DAT_004fe630 <= DAT_004f8cd0)) &&
     (DAT_005233a4 == 0)) {
    iVar3 = DAT_004fe624 / 5;
    if ((iVar3 <= DAT_00536540) || (0 < DAT_004f8cd0)) {
      iVar3 = DAT_00536540 + -0xf;
    }
    if ((0 < (int)DAT_004da278) && ((int)DAT_004da278 <= DAT_004da194)) {
      FUN_0041f3e0(param_1,(int)DAT_004da278);
      pTVar1 = FUN_0041bc70(&TStack_2c,DAT_004f4e04);
      iStack_c = 9;
      pTVar2 = FUN_004b082f(&TStack_28,&DAT_004da2bc,
                            (Tact2010CString *)(&DAT_004fec30 + (int)DAT_004da278 * 4));
      iStack_c._0_1_ = 10;
      pTVar2 = FUN_004b07bb(&local_24,pTVar2,&DAT_004da2a8);
      iStack_c._0_1_ = 0xb;
      pTVar1 = FUN_004b0755(&local_20,pTVar2,pTVar1);
      iStack_c._0_1_ = 0xc;
      pTVar1 = FUN_004b07bb(local_1c,pTVar1,s_deg_004da2a0);
      iStack_c._0_1_ = 0xd;
      (**(code **)(local_44 + 100))(param_1,iVar3,2,pTVar1->data,*(int *)(pTVar1->data + -8));
      iStack_c._0_1_ = 0xc;
      FUN_004b05a5(local_1c);
      iStack_c._0_1_ = 0xb;
      FUN_004b05a5(&local_20);
      iStack_c._0_1_ = 10;
      FUN_004b05a5(&local_24);
      iStack_c = CONCAT31(iStack_c._1_3_,9);
      FUN_004b05a5(&TStack_28);
      iStack_c = 0xffffffff;
      FUN_004b05a5(&TStack_2c);
      *unaff_FS_OFFSET = uStack_14;
      return;
    }
  }
  else {
    DAT_004da278 = (char *)0xffffffff;
  }
  *unaff_FS_OFFSET = uStack_14;
  return;
}


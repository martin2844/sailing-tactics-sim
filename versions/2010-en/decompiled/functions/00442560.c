
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00442560(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *original_dc;
  int iVar1;
  int iVar2;
  int iVar3;
  Tact2010CString *pTVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  float10 fVar8;
  Tact2010CString local_4c;
  Tact2010CString local_48;
  Tact2010CString local_44;
  Tact2010CString local_40;
  Tact2010CString TStack_3c;
  Tact2010CString TStack_38;
  Tact2010CString aTStack_34 [3];
  int local_28 [4];
  int local_18 [4];
  code *pcStack_8;
  uint local_4;
  
  original_dc = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c31e0;
  local_18[3] = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_18 + 3;
  FUN_004b045a(&local_48);
  local_4 = 0;
  FUN_004b045a(&local_4c);
  iVar1 = param_2;
  local_4 = CONCAT31(local_4._1_3_,1);
  if ((((DAT_005359d0 == 0) && (param_2 == -1)) ||
      ((param_2 == -1 && ((0 < DAT_004f69b8 && (DAT_004f69b8 < 4)))))) ||
     ((param_2 == -1 && ((DAT_004da158 == 0 && (DAT_004f69b8 != 4)))))) {
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5(&local_4c);
    goto LAB_00442fad;
  }
  FUN_004b4a1f(param_1,1);
  iVar2 = param_5;
  iVar3 = param_3;
  if ((DAT_00536444 < 1) ||
     ((DAT_00536444 == 2 || (local_44.data = (char *)0x1, DAT_00536444 == 300)))) {
    local_44.data = (char *)0x0;
  }
  iVar6 = param_4 + 0x1e + iVar1 * 0x46;
  if (*(int *)(&DAT_004f71c0 + param_3 * 4) == 3) {
    param_5 = 0x1f;
  }
  else {
    param_5 = param_5 + -10;
  }
  if ((iVar1 == -1) && (DAT_004da140 == 1)) {
    iVar6 = 0xd2;
  }
  if (local_44.data != (char *)0x0) {
    param_5 = iVar2 + 0x1f;
  }
  iVar2 = param_3;
  if (iVar1 == 1) {
    iVar6 = param_6 - ((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3);
    DAT_005230b8 = FUN_00440350(param_3);
    fVar8 = FUN_0043ec20((double)CONCAT44(*(undefined4 *)(&DAT_004f839c + DAT_005230b8 * 8),
                                          *(undefined4 *)(&DAT_004f8398 + DAT_005230b8 * 8)),
                         (double)CONCAT44(*(undefined4 *)(&DAT_004fb06c + DAT_005230b8 * 8),
                                          *(undefined4 *)(&DAT_004fb068 + DAT_005230b8 * 8)),-1,
                         iVar3);
    iVar2 = 0xba - (int)(longlong)(fVar8 * (float10)_DAT_004cc3e8);
  }
  if (iVar1 == 0) {
    iVar6 = param_4 + 0x1b;
    iVar2 = DAT_004f4b44;
    if (DAT_00536498 == 0) {
      iVar5 = DAT_004f4ce0;
      if (iVar3 == 1) {
        iVar5 = DAT_004f4cdc * DAT_00522ff4;
      }
      else {
LAB_00442731:
        iVar5 = iVar5 * DAT_00522ff8;
        iVar2 = DAT_004f4bb8;
      }
    }
    else {
      iVar5 = DAT_004fecd0;
      if (iVar3 != 1) goto LAB_00442731;
      iVar5 = DAT_004feccc * DAT_00522ff4;
    }
    iVar2 = -(iVar5 + iVar2);
    if (0 < (int)local_44.data) {
      iVar6 = DAT_004fe624 + -0x28;
      iVar2 = DAT_005362d4;
    }
  }
  if (iVar1 == -1) {
    local_40.data = *(char **)(&DAT_00535a08 + iVar3 * 4);
    iVar6 = ((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3) + param_4;
    if (iVar3 == 1) {
      iVar1 = (DAT_00535744 - DAT_00522d34) - DAT_004f4b44;
    }
    else {
      iVar1 = (DAT_00535748 - DAT_00522d38) - DAT_004f4bb8;
    }
    iVar2 = FUN_0041bc20(iVar1);
  }
  iVar1 = FUN_0041bc20(iVar2);
  iVar1 = FUN_0041bc20(iVar1);
  iVar3 = FUN_0041bc20(iVar1);
  if (param_2 == 0) {
    iVar2 = FUN_0041e3a0(iVar1);
    *(int *)(&DAT_00511368 + param_3 * 4) = iVar2;
  }
  iVar2 = param_5;
  if ((-1 < iVar1) && (iVar1 < 0x169)) {
    local_18[0] = iVar6 - ((&DAT_004f85c8)[iVar1] * 0x1a) / 100;
    local_28[0] = param_5 - ((&DAT_004f1740)[iVar1] * 0x1a) / 300;
    iVar1 = FUN_0041bc20(iVar3 + 0x28);
    iVar1 = FUN_0041bc20(iVar1);
    local_18[1] = iVar6 - ((&DAT_004f85c8)[iVar1] * 0xd) / 100;
    local_28[1] = iVar2 - ((&DAT_004f1740)[iVar1] * 0xd) / 300;
    iVar1 = FUN_0041bc20(iVar3 + -0x28);
    iVar1 = FUN_0041bc20(iVar1);
    local_18[2] = iVar6 - ((&DAT_004f85c8)[iVar1] * 0xd) / 100;
    local_28[2] = iVar2 - ((&DAT_004f1740)[iVar1] * 0xd) / 300;
    if (DAT_005363e4 == 0) {
      if (DAT_004fb244 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fb244);
      }
    }
    else {
      (**(code **)(*param_1 + 0x2c))(param_1,4);
    }
    if (DAT_005363e4 == 0) {
      if (param_2 == 1) {
        if (((DAT_005230b8 == 3) || (DAT_005230b8 == 5)) && (DAT_004fb6ac != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004fb6ac);
        }
        if ((DAT_005230b8 == 4) && (DAT_00525a94 != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_00525a94);
        }
        if ((DAT_005230b8 == 2) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004fe07c);
        }
      }
      if (((DAT_005363e4 == 0) && (param_2 == -1)) && (DAT_00522fcc != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_00522fcc);
      }
    }
    iVar1 = *param_1;
    (**(code **)(iVar1 + 0x2c))(param_1,7);
    Ellipse((HDC)param_1[1],iVar6 + -0x1a,param_5 + -8,iVar6 + 0x1a,param_5 + 8);
    if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7ec4);
    }
    iVar3 = 0;
    do {
      FUN_004b4d9d(param_1,(int *)aTStack_34,iVar6,param_5);
      CDC::LineTo(param_1,*(int *)((int)local_18 + iVar3),*(int *)((int)local_28 + iVar3));
      iVar3 = iVar3 + 4;
    } while (iVar3 < 9);
    param_1 = (int *)(param_5 + -0x1a);
    if (900 < DAT_004fe624) {
      param_1 = (int *)(param_5 + -0x1b);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar1 + 0x34))(original_dc,0x7f7f00);
      (**(code **)(iVar1 + 0x38))(original_dc,0xffff);
    }
    if (DAT_00536450 == 1) {
      (**(code **)(iVar1 + 0x34))(original_dc,0x7f7f7f);
    }
    iVar3 = param_3;
    if (param_2 == 0) {
      bVar7 = false;
      if (local_44.data == (char *)0x0) {
        if (((param_3 == 1) && (0 < DAT_00522cac)) && (DAT_005363e4 == 0)) {
          (**(code **)(iVar1 + 0x38))(original_dc,0x7fff);
        }
        if (((iVar3 == 2) && (0 < DAT_00522d18)) && (DAT_005363e4 == 0)) {
          (**(code **)(iVar1 + 0x38))(original_dc,0x7fff);
        }
        if (DAT_00536498 == 0) {
          pTVar4 = FUN_0041bc70((Tact2010CString *)&param_6,*(int *)(&DAT_00534eb8 + iVar3 * 4));
          local_4._0_1_ = 2;
          FUN_004b069e(&local_48,pTVar4);
          local_4._0_1_ = 1;
          FUN_004b05a5((Tact2010CString *)&param_6);
          pTVar4 = FUN_004b082f((Tact2010CString *)&param_6,s_a_wind_004dd760,&local_48);
          local_4._0_1_ = 3;
          (**(code **)(iVar1 + 100))
                    (original_dc,iVar6 + -0x18,(int)param_1,pTVar4->data,*(int *)(pTVar4->data + -8)
                    );
        }
        else {
          pTVar4 = FUN_0041bc70((Tact2010CString *)&param_6,(&DAT_004fb380)[iVar3]);
          local_4._0_1_ = 4;
          FUN_004b069e(&local_48,pTVar4);
          local_4._0_1_ = 1;
          FUN_004b05a5((Tact2010CString *)&param_6);
          pTVar4 = FUN_004b082f((Tact2010CString *)&param_6,s_t_wind_004dd758,&local_48);
          local_4._0_1_ = 5;
          (**(code **)(iVar1 + 100))
                    (original_dc,iVar6 + -0x18,(int)param_1,pTVar4->data,*(int *)(pTVar4->data + -8)
                    );
        }
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_004b05a5((Tact2010CString *)&param_6);
        if (DAT_005363e4 == 0) {
          (**(code **)(iVar1 + 0x38))(original_dc,0xffff);
        }
        goto LAB_00442c1c;
      }
    }
    else {
LAB_00442c1c:
      bVar7 = local_44.data == (char *)0x0;
    }
    if (!bVar7 && -1 < (int)local_44.data) {
      FUN_004b0613((Tact2010CString *)&param_6,&DAT_004dd750);
      local_4._0_1_ = 6;
      (**(code **)(iVar1 + 100))
                (original_dc,iVar6 + -0xc,(int)param_1,(char *)param_6,*(int *)(param_6 + -8));
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_004b05a5((Tact2010CString *)&param_6);
    }
    iVar3 = param_2;
    if (param_2 == 1) {
      FUN_004b0613((Tact2010CString *)&param_6,&DAT_004dd748);
      local_4._0_1_ = 7;
      (**(code **)(iVar1 + 100))
                (original_dc,iVar6 + -0xf,(int)param_1,(char *)param_6,*(int *)(param_6 + -8));
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_004b05a5((Tact2010CString *)&param_6);
    }
    if (iVar3 == -1) {
      if ((DAT_004f69b8 != 4) && (DAT_00536510 == 0)) {
        FUN_004b06ed(&local_4c,s_tide_004dd740);
      }
      if (((DAT_004f69b8 == 4) || (DAT_00536510 == 1)) && (700 < DAT_004fe624)) {
        FUN_004b06ed(&local_4c,"current ");
      }
      if (((DAT_004f69b8 == 4) || (DAT_00536510 == 1)) && (DAT_004fe624 < 0x2bd)) {
        FUN_004b06ed(&local_4c,s_curr_004dd72c);
      }
      iVar3 = ((uint)local_40.data ^ (int)local_40.data >> 0x1f) - ((int)local_40.data >> 0x1f);
      param_6 = (int)FUN_0041bc70(aTStack_34,iVar3 % 10);
      local_4._0_1_ = 8;
      pTVar4 = FUN_0041bc70(&TStack_38,iVar3 / 10);
      local_4._0_1_ = 9;
      pTVar4 = FUN_004b0755(&TStack_3c,&local_4c,pTVar4);
      local_4._0_1_ = 10;
      pTVar4 = FUN_004b07bb(&local_44,pTVar4,(char *)&DAT_004dd054);
      local_4._0_1_ = 0xb;
      pTVar4 = FUN_004b0755(&local_40,pTVar4,(Tact2010CString *)param_6);
      local_4._0_1_ = 0xc;
      (**(code **)(iVar1 + 100))
                (original_dc,iVar6 + -0x19,(int)param_1,pTVar4->data,*(int *)(pTVar4->data + -8));
      local_4._0_1_ = 0xb;
      FUN_004b05a5(&local_40);
      local_4._0_1_ = 10;
      FUN_004b05a5(&local_44);
      local_4._0_1_ = 9;
      FUN_004b05a5(&TStack_3c);
      local_4._0_1_ = 8;
      FUN_004b05a5(&TStack_38);
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_004b05a5(aTStack_34);
    }
    if ((param_2 == 0) && (DAT_00536444 == 0)) {
      iVar3 = param_5 + -0xd;
      iVar2 = DAT_004fe624 / 5 + param_4;
      if (*(int *)(&DAT_00535e40 + param_3 * 4) < 2) {
        FUN_004b0613((Tact2010CString *)&param_2,s_smooth_004dd724);
        local_4._0_1_ = 0xd;
        (**(code **)(iVar1 + 100))(original_dc,iVar2,iVar3,(char *)param_2,*(int *)(param_2 + -8));
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      if (*(int *)(&DAT_00535e40 + param_3 * 4) == 2) {
        FUN_004b0613((Tact2010CString *)&param_2,"choppy");
        local_4._0_1_ = 0xe;
        (**(code **)(iVar1 + 100))(original_dc,iVar2,iVar3,(char *)param_2,*(int *)(param_2 + -8));
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      if (*(int *)(&DAT_00535e40 + param_3 * 4) == 3) {
        FUN_004b0613((Tact2010CString *)&param_2,s_rough_004dd714);
        local_4._0_1_ = 0xf;
        (**(code **)(iVar1 + 100))(original_dc,iVar2,iVar3,(char *)param_2,*(int *)(param_2 + -8));
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      if (*(int *)(&DAT_00535e40 + param_3 * 4) == 4) {
        FUN_004b0613((Tact2010CString *)&param_2,s_very_rough_004dd708);
        local_4._0_1_ = 0x10;
        (**(code **)(iVar1 + 100))(original_dc,iVar2,iVar3,(char *)param_2,*(int *)(param_2 + -8));
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      if (4 < *(int *)(&DAT_00535e40 + param_3 * 4)) {
        FUN_004b0613((Tact2010CString *)&param_3,"extremely rough");
        local_4._0_1_ = 0x11;
        (**(code **)(iVar1 + 100))(original_dc,iVar2,iVar3,(char *)param_3,*(int *)(param_3 + -8));
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_004b05a5((Tact2010CString *)&param_3);
      }
    }
    FUN_004b4a1f(original_dc,2);
    (**(code **)(iVar1 + 0x34))(original_dc,0xffffff);
    (**(code **)(iVar1 + 0x38))(original_dc,0);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_004b05a5(&local_4c);
LAB_00442fad:
  local_4 = 0xffffffff;
  FUN_004b05a5(&local_48);
  *unaff_FS_OFFSET = local_18[3];
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00412d30(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  HDC hdc;
  code *pcVar2;
  code *pcVar3;
  float10 fVar4;
  int iVar5;
  Tact2010CString *pTVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar9;
  uint uStack_30;
  Tact2010CString local_2c;
  Tact2010CString TStack_28;
  Tact2010CString local_24;
  Tact2010CString TStack_20;
  Tact2010CString local_1c;
  HGDIOBJ local_18;
  HDC local_14;
  HRGN local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c2780;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  hdc = (HDC)param_1[1];
  local_14 = hdc;
  local_10 = CreateRectRgn(param_2,param_3,param_4,param_5);
  local_18 = SelectObject(hdc,local_10);
  FUN_004b045a(&local_2c);
  iVar5 = DAT_004fe2a8 / 0x1f;
  local_4 = 0;
  DAT_005230b8 = FUN_00440350(param_6);
  fVar9 = FUN_0043ec20((double)CONCAT44(*(undefined4 *)(&DAT_004f839c + DAT_005230b8 * 8),
                                        *(undefined4 *)(&DAT_004f8398 + DAT_005230b8 * 8)),
                       (double)CONCAT44(*(undefined4 *)(&DAT_004fb06c + DAT_005230b8 * 8),
                                        *(undefined4 *)(&DAT_004fb068 + DAT_005230b8 * 8)),0,param_6
                      );
  if (((DAT_0053527c == 0) && (*(int *)(&DAT_004f8538 + param_6 * 4) == DAT_004da1e4)) &&
     (*(int *)(&DAT_004fbf10 + param_6 * 4) == 0)) {
    local_24.data = (char *)((DAT_004fe094 + DAT_00536410) / 2);
    fVar9 = FUN_0043ec20((double)(int)local_24.data,(double)((DAT_004fe2a0 + DAT_00536414) / 2),0,
                         param_6);
  }
  if (((DAT_0053527c == 1) && (*(int *)(&DAT_004f8538 + param_6 * 4) == DAT_004da1e4)) &&
     ((1 < *(int *)(&DAT_004fbf10 + param_6 * 4) && (DAT_004da194 < 0xf)))) {
    local_24.data = (char *)((DAT_004fe094 + DAT_00536410) / 2);
    fVar9 = FUN_0043ec20((double)(int)local_24.data,(double)((DAT_00536414 + DAT_004fe2a0) / 2),0,
                         param_6);
  }
  fVar4 = (float10)_DAT_004cc3e8;
  *(int *)(&DAT_00522ef8 + param_6 * 4) = (int)(longlong)(_DAT_004fbb88 * _DAT_004cc598);
  DAT_00535ff4 = FUN_0041e3a0((int)(longlong)(fVar9 * fVar4) - *(int *)(&DAT_00535740 + param_6 * 4)
                             );
  local_1c.data = (char *)(longlong)_DAT_004fbb88;
  iVar8 = *param_1;
  pcVar2 = *(code **)(iVar8 + 0x2c);
  (*pcVar2)(param_1,7);
  (*pcVar2)(param_1,0);
  Rectangle((HDC)param_1[1],param_2,param_3,param_4,param_5);
  (**(code **)(iVar8 + 0x34))(param_1,0xffffff);
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar8 + 0x38))(param_1,0xff);
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar8 + 0x38))(param_1,0x7f0000);
    }
  }
  if (DAT_005364c8 == 1) {
    pTVar6 = FUN_0041bd00(&local_24,*(double *)(&DAT_004fe180 + param_6 * 8) * _DAT_004cc5b0);
    local_4._0_1_ = 1;
    FUN_004b069e(&local_2c,pTVar6);
  }
  else {
    pTVar6 = FUN_0041bd00(&local_24,*(double *)(&DAT_004fe180 + param_6 * 8) * _DAT_004cc5b8);
    local_4._0_1_ = 2;
    FUN_004b069e(&local_2c,pTVar6);
  }
  local_4._0_1_ = 0;
  FUN_004b05a5(&local_24);
  pTVar6 = FUN_004b082f(&local_24,s_speed__004db24c,&local_2c);
  local_4._0_1_ = 3;
  iVar1 = param_2 + 1;
  pcVar2 = *(code **)(iVar8 + 100);
  (*pcVar2)(param_1,iVar1,param_3 + 1,pTVar6->data,*(int *)(pTVar6->data + -8));
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b05a5(&local_24);
  iVar7 = param_3 + 1 + iVar5;
  if (*(double *)(&DAT_004ffcb8 + param_6 * 8) <= (double)DAT_004da1fc - _DAT_004cc5c8) {
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar8 + 0x38))(param_1,0xff);
    }
    pTVar6 = FUN_0041bc70(&TStack_28,(int)(longlong)*(double *)(&DAT_004ffcb8 + param_6 * 8));
    local_4._0_1_ = 7;
    pTVar6 = FUN_004b082f(&local_24,s_depth__004db278,pTVar6);
    local_4._0_1_ = 8;
    (*pcVar2)(param_1,iVar1,iVar7,pTVar6->data,*(int *)(pTVar6->data + -8));
    local_4._0_1_ = 7;
    FUN_004b05a5(&local_24);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5(&TStack_28);
    if (((*(double *)(&DAT_004ffcb8 + param_6 * 8) < (double)DAT_004da1fc - _DAT_004cc5c8) &&
        (_DAT_004cc5a8 < *(double *)(&DAT_004f4888 + param_6 * 8))) && (DAT_00536484 == 0)) {
      MessageBeep(0);
    }
  }
  else {
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar8 + 0x38))(param_1,0xff0000);
    }
    if (*(int *)(&DAT_004fe778 + param_6 * 4) == 1) {
      FUN_004b0613(&TStack_28,s_sail__flat_004db20c);
      local_4._0_1_ = 4;
      (*pcVar2)(param_1,iVar1,iVar7,TStack_28.data,*(int *)(TStack_28.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&TStack_28);
    }
    if (*(int *)(&DAT_004fe778 + param_6 * 4) == 2) {
      FUN_004b0613(&TStack_28,s_sail__medium_004db1fc);
      local_4._0_1_ = 5;
      (*pcVar2)(param_1,iVar1,iVar7,TStack_28.data,*(int *)(TStack_28.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&TStack_28);
    }
    if (*(int *)(&DAT_004fe778 + param_6 * 4) == 3) {
      FUN_004b0613(&TStack_28,s_sail__baggy_004db1f0);
      local_4._0_1_ = 6;
      (*pcVar2)(param_1,iVar1,iVar7,TStack_28.data,*(int *)(TStack_28.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&TStack_28);
    }
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar8 + 0x38))(param_1,0x7f0000);
  }
  pTVar6 = FUN_0041bc70(&local_24,*(int *)(&DAT_00512278 + param_6 * 4));
  local_4._0_1_ = 9;
  FUN_004b069e(&local_2c,pTVar6);
  local_4._0_1_ = 0;
  FUN_004b05a5(&local_24);
  pTVar6 = FUN_004b082f(&TStack_28,s_luffing__004db6a0,&local_2c);
  local_4._0_1_ = 10;
  pTVar6 = FUN_004b07bb(&local_24,pTVar6,&DAT_004db218);
  local_4._0_1_ = 0xb;
  (*pcVar2)(param_1,iVar1,iVar7 + iVar5,pTVar6->data,*(int *)(pTVar6->data + -8));
  local_4._0_1_ = 10;
  FUN_004b05a5(&local_24);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b05a5(&TStack_28);
  iVar7 = iVar7 + iVar5 + iVar5;
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar8 + 0x38))(param_1,0x7f00);
  }
  if (*(int *)(&DAT_004fe8a8 + param_6 * 4) == 0) {
    FUN_004b0613(&TStack_28,s_air_clear_004db694);
    local_4._0_1_ = 0xc;
    (*pcVar2)(param_1,iVar1,iVar7,TStack_28.data,*(int *)(TStack_28.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5(&TStack_28);
  }
  else if (DAT_005363e4 == 0) {
    (**(code **)(iVar8 + 0x38))(param_1,0xff);
  }
  if ((*(int *)(&DAT_004fe8a8 + param_6 * 4) == 2) || (*(int *)(&DAT_004fe8a8 + param_6 * 4) == 0xc)
     ) {
    FUN_004b0613(&TStack_28,s_blanketed_004db234);
    local_4._0_1_ = 0xd;
    (*pcVar2)(param_1,iVar1,iVar7,TStack_28.data,*(int *)(TStack_28.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5(&TStack_28);
  }
  if (*(int *)(&DAT_004fe8a8 + param_6 * 4) == 3) {
    FUN_004b0613(&TStack_28,s_backwinded_004db228);
    local_4._0_1_ = 0xe;
    (*pcVar2)(param_1,iVar1,iVar7,TStack_28.data,*(int *)(TStack_28.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5(&TStack_28);
  }
  iVar7 = iVar7 + iVar5;
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar8 + 0x38))(param_1,0x7f0000);
  }
  uStack_30 = FUN_0041bc20((&DAT_00522b90)[param_6] - DAT_004f7f94);
  if (0xb4 < (int)uStack_30) {
    uStack_30 = uStack_30 - 0x168;
  }
  TStack_28.data = (char *)((uStack_30 ^ (int)uStack_30 >> 0x1f) - ((int)uStack_30 >> 0x1f));
  DAT_00536428 = (uint)(0x28 < (int)TStack_28.data);
  if ((DAT_0053643c == 0) && (DAT_00536428 == 0)) {
    if (0 < (int)(uStack_30 * *(int *)(&DAT_00522ff0 + param_6 * 4))) {
      pTVar6 = FUN_0041bc70(&TStack_20,(int)TStack_28.data);
      local_4._0_1_ = 0xf;
      pTVar6 = FUN_004b082f(&local_24,s_lifted_004db1e8,pTVar6);
      local_4._0_1_ = 0x10;
      (*pcVar2)(param_1,iVar1,iVar7,pTVar6->data,*(int *)(pTVar6->data + -8));
      local_4._0_1_ = 0xf;
      FUN_004b05a5(&local_24);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&TStack_20);
    }
    if (uStack_30 == 0) {
      FUN_004b0613(&local_24,s_wind_ave_004db688);
      local_4._0_1_ = 0x11;
      (*pcVar2)(param_1,iVar1,iVar7,local_24.data,*(int *)(local_24.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
    if ((int)(uStack_30 * *(int *)(&DAT_00522ff0 + param_6 * 4)) < 0) {
      if (DAT_0053643c == 0) {
        pTVar6 = FUN_0041bc70(&local_24,(int)TStack_28.data);
        local_4._0_1_ = 0x12;
        pTVar6 = FUN_004b082f(&TStack_20,s_headed_004db1d0,pTVar6);
        local_4._0_1_ = 0x13;
        (*pcVar2)(param_1,iVar1,iVar7,pTVar6->data,*(int *)(pTVar6->data + -8));
        local_4._0_1_ = 0x12;
        FUN_004b05a5(&TStack_20);
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_004b05a5(&local_24);
      }
      if ((((DAT_004feccc < 0x37) &&
           (0x2d < (int)((DAT_00535ff4 ^ (int)DAT_00535ff4 >> 0x1f) - ((int)DAT_00535ff4 >> 0x1f))))
          && (10 < (int)TStack_28.data)) && ((300 < (int)local_1c.data && (param_6 == 1)))) {
        DAT_004fb234 = 1;
      }
    }
  }
  pcVar3 = *(code **)(iVar8 + 0x38);
  iVar8 = iVar7 + 2 + iVar5;
  (*pcVar3)(param_1,0xff0000);
  if ((*(int *)(&DAT_00511620 + param_6 * 4) == 1) && (*(int *)(&DAT_005359e0 + param_6 * 4) == 0))
  {
    FUN_004b0613(&local_24,s_closehauled_004db67c);
    local_4._0_1_ = 0x14;
    (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5(&local_24);
  }
  if (*(int *)(&DAT_00511620 + param_6 * 4) == 1) {
    if (*(int *)(&DAT_005359e0 + param_6 * 4) == 5) {
      FUN_004b0613(&local_24,s_footing_004db674);
      local_4._0_1_ = 0x15;
      (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
    if ((*(int *)(&DAT_00511620 + param_6 * 4) == 1) &&
       (*(int *)(&DAT_005359e0 + param_6 * 4) == -5)) {
      FUN_004b0613(&local_24,s_pinching_004db668);
      local_4._0_1_ = 0x16;
      (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
  }
  if (*(int *)(&DAT_004f6a68 + param_6 * 4) == 1) {
    if (*(int *)(&DAT_004f3f60 + param_6 * 4) == 0) {
      FUN_004b0613(&local_24,s_running_004db660);
      local_4._0_1_ = 0x17;
      (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
    if (*(int *)(&DAT_004f6a68 + param_6 * 4) == 1) {
      if (*(int *)(&DAT_004f3f60 + param_6 * 4) == -7) {
        FUN_004b0613(&local_24,s_run__high_004db654);
        local_4._0_1_ = 0x18;
        (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_004b05a5(&local_24);
      }
      if ((*(int *)(&DAT_004f6a68 + param_6 * 4) == 1) &&
         (*(int *)(&DAT_004f3f60 + param_6 * 4) == 7)) {
        FUN_004b0613(&local_24,s_run__low_004db648);
        local_4._0_1_ = 0x19;
        (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_004b05a5(&local_24);
      }
    }
  }
  iVar8 = iVar8 + iVar5;
  if (DAT_004f8cd0 < 1) goto LAB_00413a4c;
  if (DAT_005363e4 == 0) {
    if ((DAT_005230b8 == 3) || (DAT_005230b8 == 5)) {
      iVar7 = 0x7f;
    }
    else {
      iVar7 = 0x7f7f;
    }
    (*pcVar3)(param_1,iVar7);
    if (DAT_005230b8 == 2) {
      (*pcVar3)(param_1,0x7f7f);
    }
    if ((DAT_005230b8 == 5) && (DAT_004f452c == 1)) {
      (*pcVar3)(param_1,0x7fff);
    }
  }
  if (DAT_004fe624 < 0x385) {
    if (0 < (int)DAT_00535ff4) {
      pTVar6 = FUN_0041bc70(&local_24,DAT_00535ff4);
      local_4._0_1_ = 0x21;
      pTVar6 = FUN_004b082f(&TStack_20,s_mrk__004db61c,pTVar6);
      local_4._0_1_ = 0x22;
      pTVar6 = FUN_004b07bb(&local_1c,pTVar6,s_to_S_004db638);
      local_4._0_1_ = 0x23;
      (*pcVar2)(param_1,iVar1,iVar8,pTVar6->data,*(int *)(pTVar6->data + -8));
      local_4._0_1_ = 0x22;
      FUN_004b05a5(&local_1c);
      local_4._0_1_ = 0x21;
      FUN_004b05a5(&TStack_20);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
    if ((int)DAT_00535ff4 < 0) {
      pTVar6 = FUN_0041bc70(&local_24,
                            (DAT_00535ff4 ^ (int)DAT_00535ff4 >> 0x1f) - ((int)DAT_00535ff4 >> 0x1f)
                           );
      local_4._0_1_ = 0x24;
      pTVar6 = FUN_004b082f(&TStack_20,s_mrk__004db61c,pTVar6);
      local_4._0_1_ = 0x25;
      pTVar6 = FUN_004b07bb(&local_1c,pTVar6,s_to_P_004db630);
      local_4._0_1_ = 0x26;
      (*pcVar2)(param_1,iVar1,iVar8,pTVar6->data,*(int *)(pTVar6->data + -8));
      local_4._0_1_ = 0x25;
      FUN_004b05a5(&local_1c);
      local_4._0_1_ = 0x24;
      FUN_004b05a5(&TStack_20);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
    if (DAT_00535ff4 == 0) {
      FUN_004b0613(&local_24,s_mrk__ahead_004db610);
      local_4._0_1_ = 0x27;
      (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
      goto LAB_00413a43;
    }
  }
  else {
    if (0 < (int)DAT_00535ff4) {
      pTVar6 = FUN_0041bc70(&local_24,DAT_00535ff4);
      local_4._0_1_ = 0x1a;
      pTVar6 = FUN_004b082f(&TStack_20,s_mark__004db640,pTVar6);
      local_4._0_1_ = 0x1b;
      pTVar6 = FUN_004b07bb(&local_1c,pTVar6,s_to_S_004db638);
      local_4._0_1_ = 0x1c;
      (*pcVar2)(param_1,iVar1,iVar8,pTVar6->data,*(int *)(pTVar6->data + -8));
      local_4._0_1_ = 0x1b;
      FUN_004b05a5(&local_1c);
      local_4._0_1_ = 0x1a;
      FUN_004b05a5(&TStack_20);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
    if ((int)DAT_00535ff4 < 0) {
      pTVar6 = FUN_0041bc70(&local_24,
                            (DAT_00535ff4 ^ (int)DAT_00535ff4 >> 0x1f) - ((int)DAT_00535ff4 >> 0x1f)
                           );
      local_4._0_1_ = 0x1d;
      pTVar6 = FUN_004b082f(&TStack_20,s_mark__004db640,pTVar6);
      local_4._0_1_ = 0x1e;
      pTVar6 = FUN_004b07bb(&local_1c,pTVar6,s_to_P_004db630);
      local_4._0_1_ = 0x1f;
      (*pcVar2)(param_1,iVar1,iVar8,pTVar6->data,*(int *)(pTVar6->data + -8));
      local_4._0_1_ = 0x1e;
      FUN_004b05a5(&local_1c);
      local_4._0_1_ = 0x1d;
      FUN_004b05a5(&TStack_20);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
    if (DAT_00535ff4 == 0) {
      FUN_004b0613(&local_24,s_mark__ahead_004db624);
      local_4._0_1_ = 0x20;
      (*pcVar2)(param_1,iVar1,iVar8,local_24.data,*(int *)(local_24.data + -8));
LAB_00413a43:
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_004b05a5(&local_24);
    }
  }
  iVar8 = iVar8 + iVar5;
LAB_00413a4c:
  (*pcVar3)(param_1,0);
  if ((DAT_005363e4 == 0) && (DAT_004da174 == 1)) {
    (*pcVar3)(param_1,0xff);
  }
  if (DAT_004fe624 < 0x385) {
    pTVar6 = FUN_0041bc70(&TStack_20,DAT_004da174);
    local_4._0_1_ = 0x2a;
    pTVar6 = FUN_004b082f(&local_1c,s_sim_spd__004db5f8,pTVar6);
    local_4._0_1_ = 0x2b;
    (*pcVar2)(param_1,iVar1,iVar8,pTVar6->data,*(int *)(pTVar6->data + -8));
    local_4._0_1_ = 0x2a;
    FUN_004b05a5(&local_1c);
  }
  else {
    pTVar6 = FUN_0041bc70(&TStack_20,DAT_004da174);
    local_4._0_1_ = 0x28;
    pTVar6 = FUN_004b082f(&local_1c,s_sim_speed__004db604,pTVar6);
    local_4._0_1_ = 0x29;
    (*pcVar2)(param_1,iVar1,iVar8,pTVar6->data,*(int *)(pTVar6->data + -8));
    local_4._0_1_ = 0x28;
    FUN_004b05a5(&local_1c);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b05a5(&TStack_20);
  if (param_6 == 1) {
    FUN_0040bbc0(param_1,param_2,param_3,param_4,param_5,1,iVar5);
  }
  else {
    FUN_0040e6e0(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  (*pcVar3)(param_1,0);
  SelectObject(local_14,local_18);
  DeleteObject(local_10);
  local_4 = 0xffffffff;
  FUN_004b05a5(&local_2c);
  *unaff_FS_OFFSET = uStack_c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040f240(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  code *pcVar2;
  Tact2010CString *pTVar3;
  Tact2010CString *pTVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  Tact2010CString TVar9;
  Tact2010CString TVar10;
  int iVar11;
  int iVar12;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar13;
  HDC hdc;
  HGDIOBJ h;
  Tact2010CString TStack_64;
  int local_60;
  char *local_5c;
  Tact2010CString TStack_58;
  Tact2010CString TStack_54;
  code *pcStack_50;
  Tact2010CString local_4c;
  Tact2010CString local_48;
  Tact2010CString TStack_44;
  Tact2010CString local_40;
  code *local_3c;
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
  int local_c;
  
  local_c = 0xffffffff;
  pcStack_10 = FUN_004c2540;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_40.data = (char *)param_1[1];
  local_1c[0].data = (char *)CreateRectRgn(param_2,param_3,param_4,param_5);
  local_20.data = SelectObject(local_40.data,local_1c[0].data);
  FUN_004b045a(&local_4c);
  local_c._0_1_ = 0;
  local_c._1_3_ = 0;
  DAT_00536520 = DAT_00536520 + -1;
  if (DAT_00536520 < 0) {
    DAT_00536520 = 0;
  }
  FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,&DAT_005365a4);
  DAT_0053649c = 0;
  DAT_004fe088 = (char *)((param_4 + param_2) / 2);
  DAT_0052318c = (param_3 + param_5 * 4) / 5;
  local_60 = DAT_004fe2a8 / 0x23;
  if ((DAT_004da1a8 == 1) && (*(int *)(&DAT_004f71c0 + param_6 * 4) < 3)) {
    iVar11 = param_4 + param_2 * 3;
    local_48.data = (char *)((int)(iVar11 + (iVar11 >> 0x1f & 3U)) >> 2);
    pcVar8 = local_48.data + 10;
  }
  else {
    local_48.data = (char *)((param_4 + param_2 * 4) / 5);
    pcVar8 = local_48.data + 5;
  }
  local_5c = (char *)*param_1;
  local_3c = *(code **)((int)local_5c + 0x2c);
  local_24.data = DAT_004fe088;
  (*local_3c)(param_1,7);
  if (DAT_004f7084 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  (*local_3c)(param_1,0);
  Rectangle((HDC)param_1[1],param_2,param_3,param_4,param_5);
  FUN_0040bbc0(param_1,param_2,param_3,param_4,param_5,param_6,local_60);
  FUN_004118b0(param_1,param_2,param_3,param_4,(int)local_48.data,param_6,local_60);
  iVar11 = param_3 + 1;
  pcStack_50 = *(code **)((int)local_5c + 0x34);
  (*pcStack_50)(param_1,0xffffff);
  if (DAT_005363e4 == 0) {
    iVar12 = 0xff;
    pcVar2 = *(code **)((int)local_5c + 0x38);
  }
  else {
    iVar12 = 0;
    pcVar2 = *(code **)((int)local_5c + 0x38);
  }
  (*pcVar2)(param_1,iVar12);
  if (DAT_004f8cd0 < 1) {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(param_1,0xffff);
    }
    FUN_004b4a1f(param_1,2);
    (*pcStack_50)(param_1,0);
    uVar7 = (int)DAT_004fb9b8 >> 0x1f;
    if (DAT_005364c8 == 1) {
      pTVar3 = FUN_0041bc70(&TStack_54,
                            (int)(((DAT_004fb9b8 ^ uVar7) - uVar7) +
                                 ((DAT_004fad34 ^ (int)DAT_004fad34 >> 0x1f) -
                                 ((int)DAT_004fad34 >> 0x1f)) * 0x3c) / 5);
      local_c._0_1_ = 1;
      pTVar3 = FUN_004b082f(&local_48,&DAT_004da2bc,pTVar3);
      local_c._0_1_ = 2;
      pTVar3 = FUN_004b07bb(&TStack_44,pTVar3,s_sec_004da2b4);
      local_c._0_1_ = 3;
      (**(code **)((int)local_5c + 100))
                (param_1,(int)pcVar8,iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_c._0_1_ = 2;
      FUN_004b05a5(&TStack_44);
      local_c._0_1_ = 1;
      FUN_004b05a5(&local_48);
      pTVar3 = &TStack_54;
    }
    else {
      TStack_44.data = (char *)FUN_0041bc70(&TStack_34,(DAT_004fb9b8 ^ uVar7) - uVar7);
      local_c._0_1_ = 4;
      pTVar3 = FUN_0041bc70(&TStack_38,
                            (DAT_004fad34 ^ (int)DAT_004fad34 >> 0x1f) - ((int)DAT_004fad34 >> 0x1f)
                           );
      local_c._0_1_ = 5;
      pTVar3 = FUN_004b082f(&TStack_64,&DAT_004da2bc,pTVar3);
      local_c._0_1_ = 6;
      pTVar3 = FUN_004b07bb(&TStack_58,pTVar3,s_min_004da2ac);
      local_c._0_1_ = 7;
      pTVar3 = FUN_004b0755(&TStack_54,pTVar3,(Tact2010CString *)TStack_44.data);
      local_c._0_1_ = 8;
      pTVar3 = FUN_004b07bb(&local_48,pTVar3,s_sec_004da2b4);
      local_c._0_1_ = 9;
      (**(code **)((int)local_5c + 100))
                (param_1,(int)pcVar8,iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_c._0_1_ = 8;
      FUN_004b05a5(&local_48);
      local_c._0_1_ = 7;
      FUN_004b05a5(&TStack_54);
      local_c._0_1_ = 6;
      FUN_004b05a5(&TStack_58);
      local_c._0_1_ = 5;
      FUN_004b05a5(&TStack_64);
      local_c._0_1_ = 4;
      FUN_004b05a5(&TStack_38);
      pTVar3 = &TStack_34;
    }
    local_c._0_1_ = 0;
    FUN_004b05a5(pTVar3);
    iVar11 = iVar11 + local_60 * 2;
    FUN_004b4a1f(param_1,1);
    (*pcStack_50)(param_1,0xffffff);
    if (0 < DAT_004f8cd0) goto LAB_0040f647;
  }
  else {
LAB_0040f647:
    DAT_005230b8 = FUN_00440350(param_6);
    fVar13 = FUN_0043ec20((double)CONCAT44(*(undefined4 *)(&DAT_004f839c + DAT_005230b8 * 8),
                                           *(undefined4 *)(&DAT_004f8398 + DAT_005230b8 * 8)),
                          (double)CONCAT44(*(undefined4 *)(&DAT_004fb06c + DAT_005230b8 * 8),
                                           *(undefined4 *)(&DAT_004fb068 + DAT_005230b8 * 8)),0,
                          param_6);
    if (((DAT_0053527c == 0) && (*(int *)(&DAT_004f8538 + param_6 * 4) == DAT_004da1e4)) &&
       (*(int *)(&DAT_004fbf10 + param_6 * 4) == 0)) {
      TStack_34.data = (char *)((DAT_004fe094 + DAT_00536410) / 2);
      fVar13 = FUN_0043ec20((double)(int)TStack_34.data,(double)((DAT_004fe2a0 + DAT_00536414) / 2),
                            0,param_6);
    }
    if (((DAT_0053527c == 1) && (*(int *)(&DAT_004f8538 + param_6 * 4) == DAT_004da1e4)) &&
       ((1 < *(int *)(&DAT_004fbf10 + param_6 * 4) && (DAT_004da194 < 0xf)))) {
      TStack_34.data = (char *)((DAT_00536410 + DAT_004fe094) / 2);
      fVar13 = FUN_0043ec20((double)(int)TStack_34.data,(double)((DAT_004fe2a0 + DAT_00536414) / 2),
                            0,param_6);
    }
    _DAT_00522efc = (undefined4)(longlong)(_DAT_004fbb88 * _DAT_004cc598);
    DAT_00535ff4 = FUN_0041e3a0((int)(longlong)(fVar13 * (float10)_DAT_004cc3e8) -
                                *(int *)(&DAT_00535740 + param_6 * 4));
    local_48.data = (char *)(longlong)_DAT_004fbb88;
    if (DAT_005363e4 == 0) {
      if ((DAT_005230b8 == 3) || (DAT_005230b8 == 5)) {
        iVar12 = 0xff00ff;
      }
      else {
        iVar12 = 0x7f7f;
      }
      (*pcVar2)(param_1,iVar12);
      if (DAT_005230b8 == 2) {
        (*pcVar2)(param_1,0x7f7f7f);
      }
      if ((DAT_005230b8 == 5) && (DAT_004f452c == 1)) {
        (*pcVar2)(param_1,0x7fff);
      }
    }
    FUN_004b0613(&TStack_54,s_mark__004db2ac);
    local_c._0_1_ = 10;
    TStack_64.data = *(char **)((int)local_5c + 100);
    (*(code *)TStack_64.data)
              (param_1,(int)pcVar8,iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
    local_c._0_1_ = 0;
    FUN_004b05a5(&TStack_54);
    iVar11 = iVar11 + local_60;
    DAT_004fb998 = DAT_00535ff4;
    if (0 < (int)DAT_00535ff4) {
      pTVar3 = FUN_0041bc70(&TStack_38,DAT_00535ff4);
      local_c._0_1_ = 0xb;
      pTVar3 = FUN_004b07bb(&TStack_34,pTVar3,s_deg_to_Star_004db29c);
      local_c._0_1_ = 0xc;
      (*(code *)TStack_64.data)
                (param_1,(int)(pcVar8 + 10),iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_c._0_1_ = 0xb;
      FUN_004b05a5(&TStack_34);
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_38);
    }
    if ((int)DAT_00535ff4 < 0) {
      pTVar3 = FUN_0041bc70(&TStack_38,
                            (DAT_00535ff4 ^ (int)DAT_00535ff4 >> 0x1f) - ((int)DAT_00535ff4 >> 0x1f)
                           );
      local_c._0_1_ = 0xd;
      pTVar3 = FUN_004b07bb(&TStack_34,pTVar3,s_deg_to_Port_004db28c);
      local_c._0_1_ = 0xe;
      (*(code *)TStack_64.data)
                (param_1,(int)(pcVar8 + 10),iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_c._0_1_ = 0xd;
      FUN_004b05a5(&TStack_34);
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_38);
    }
    if (DAT_00535ff4 == 0) {
      FUN_004b0613(&TStack_54,s_ahead_004daef0);
      local_c._0_1_ = 0xf;
      (*(code *)TStack_64.data)
                (param_1,(int)(pcVar8 + 10),iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_54);
    }
    if (((DAT_004da1a8 == 1) && (DAT_004da140 == 1)) && (DAT_005364c8 == 0)) {
      fVar13 = FUN_00481350((int)(longlong)DAT_004f6b00,(int)(longlong)DAT_004f6c18,
                            (int)(longlong)*(double *)(&DAT_004f8398 + DAT_005230b8 * 8),
                            (int)(longlong)*(double *)(&DAT_004fb068 + DAT_005230b8 * 8));
      if (fVar13 < (float10)_DAT_004cc5a0) {
        pTVar3 = FUN_0041bc70(&TStack_38,(int)(longlong)(fVar13 * (float10)_DAT_004cc5a8));
        local_c._0_1_ = 0x12;
        pTVar3 = FUN_004b07bb(&TStack_34,pTVar3,&DAT_004db280);
        local_c._0_1_ = 0x13;
        (*(code *)TStack_64.data)
                  (param_1,(int)(pcVar8 + DAT_004fe624 / 7),iVar11,pTVar3->data,
                   *(int *)(pTVar3->data + -8));
        local_c._0_1_ = 0x12;
        FUN_004b05a5(&TStack_34);
      }
      else {
        pTVar3 = FUN_0041bd00(&TStack_38,(double)(fVar13 * (float10)_DAT_004cc3f0));
        local_c._0_1_ = 0x10;
        pTVar3 = FUN_004b07bb(&TStack_34,pTVar3,&DAT_004db288);
        local_c._0_1_ = 0x11;
        (*(code *)TStack_64.data)
                  (param_1,(int)(pcVar8 + DAT_004fe624 / 7),iVar11,pTVar3->data,
                   *(int *)(pTVar3->data + -8));
        local_c._0_1_ = 0x10;
        FUN_004b05a5(&TStack_34);
      }
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_38);
    }
    iVar11 = iVar11 + local_60;
  }
  if ((((DAT_004da1a8 == 1) && (DAT_004da140 == 1)) &&
      (((DAT_004da190 == 7 && (DAT_005364c8 == 0)) || ((DAT_004da190 == 8 || (DAT_00513478 == 1)))))
      ) || ((DAT_004da1f8 == 999 && (DAT_004da248 == 2)))) {
    if (DAT_005363e4 == 0) {
      TStack_34.data = (char *)(DAT_004da1fc + 5);
      if ((double)(int)TStack_34.data <= *(double *)(&DAT_004ffcb8 + param_6 * 8)) {
        iVar12 = 0xff7f00;
      }
      else {
        iVar12 = 0xff;
      }
      (*pcVar2)(param_1,iVar12);
    }
    if (DAT_004da1a8 == 1) {
      pTVar3 = FUN_0041bc70(&TStack_38,(int)(longlong)*(double *)(&DAT_004ffcb8 + param_6 * 8));
      local_c._0_1_ = 0x14;
      pTVar3 = FUN_004b082f(&TStack_34,s_depth__004db278,pTVar3);
      local_c._0_1_ = 0x15;
      (**(code **)((int)local_5c + 100))
                (param_1,(int)(pcVar8 + DAT_004fe624 / 7),iVar11 + local_60,pTVar3->data,
                 *(int *)(pTVar3->data + -8));
      local_c._0_1_ = 0x14;
      FUN_004b05a5(&TStack_34);
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_38);
    }
  }
  if ((DAT_005350dc == 0) &&
     ((((DAT_004da190 == 7 && (DAT_005364c8 == 0)) || (DAT_004da190 == 8)) && (DAT_004da1a8 == 1))))
  {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(param_1,0xff0000);
    }
    if (DAT_004f7ee4 == 1) {
      FUN_004b0613(&TStack_54,s__1_Genoa_004db26c);
      local_c._0_1_ = 0x16;
      (**(code **)((int)local_5c + 100))
                (param_1,(int)(pcVar8 + DAT_004fe624 / 7),iVar11 + local_60 * 3,TStack_54.data,
                 *(int *)(TStack_54.data + -8));
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_54);
    }
    if (DAT_004f7ee4 == 2) {
      FUN_004b0613(&TStack_54,s__2_Genoa_004db260);
      local_c._0_1_ = 0x17;
      (**(code **)((int)local_5c + 100))
                (param_1,(int)(pcVar8 + DAT_004fe624 / 7),iVar11 + local_60 * 3,TStack_54.data,
                 *(int *)(TStack_54.data + -8));
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_54);
    }
    if (DAT_004f7ee4 == 3) {
      FUN_004b0613(&TStack_54,s__3_Blade_004db254);
      local_c._0_1_ = 0x18;
      (**(code **)((int)local_5c + 100))
                (param_1,(int)(pcVar8 + DAT_004fe624 / 7),iVar11 + local_60 * 3,TStack_54.data,
                 *(int *)(TStack_54.data + -8));
      local_c._0_1_ = 0;
      FUN_004b05a5(&TStack_54);
    }
  }
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0x7f0000);
  }
  if (DAT_005364c8 == 1) {
    pTVar3 = FUN_0041bd00(&TStack_34,*(double *)(&DAT_004fe180 + param_6 * 8) * _DAT_004cc5b0);
    local_c._0_1_ = 0x19;
    FUN_004b069e(&local_4c,pTVar3);
  }
  else {
    pTVar3 = FUN_0041bd00(&TStack_34,*(double *)(&DAT_004fe180 + param_6 * 8) * _DAT_004cc5b8);
    local_c._0_1_ = 0x1a;
    FUN_004b069e(&local_4c,pTVar3);
  }
  local_c._0_1_ = 0;
  FUN_004b05a5(&TStack_34);
  pTVar3 = FUN_004b082f(&TStack_34,s_speed__004db24c,&local_4c);
  local_c._0_1_ = 0x1b;
  TStack_64.data = *(char **)((int)local_5c + 100);
  (*(code *)TStack_64.data)(param_1,(int)pcVar8,iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
  local_c = (uint)local_c._1_3_ << 8;
  FUN_004b05a5(&TStack_34);
  local_5c = (char *)(local_60 * 5);
  iVar11 = iVar11 + ((int)((int)local_5c + ((int)local_5c >> 0x1f & 3U)) >> 2);
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0x7f00);
  }
  if (*(int *)(&DAT_004fe8a8 + param_6 * 4) == 0) {
    FUN_004b0613(&TStack_54,s_clear_air_004db240);
    local_c._0_1_ = 0x1c;
    (*(code *)TStack_64.data)
              (param_1,(int)pcVar8,iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_54);
  }
  else if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0xff);
  }
  if ((*(int *)(&DAT_004fe8a8 + param_6 * 4) == 2) || (*(int *)(&DAT_004fe8a8 + param_6 * 4) == 0xc)
     ) {
    FUN_004b0613(&TStack_54,s_blanketed_004db234);
    local_c._0_1_ = 0x1d;
    (*(code *)TStack_64.data)
              (param_1,(int)pcVar8,iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_54);
  }
  if (*(int *)(&DAT_004fe8a8 + param_6 * 4) == 3) {
    FUN_004b0613(&TStack_54,s_backwinded_004db228);
    local_c._0_1_ = 0x1e;
    (*(code *)TStack_64.data)
              (param_1,(int)pcVar8,iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_54);
  }
  iVar11 = iVar11 + local_60;
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0x7f0000);
  }
  pTVar3 = FUN_0041bc70(&TStack_34,*(int *)(&DAT_00512278 + param_6 * 4));
  local_c._0_1_ = 0x1f;
  FUN_004b069e(&local_4c,pTVar3);
  local_c._0_1_ = 0;
  FUN_004b05a5(&TStack_34);
  pTVar3 = FUN_004b082f(&TStack_38,s_luffing__004db21c,&local_4c);
  local_c._0_1_ = 0x20;
  pTVar3 = FUN_004b07bb(&TStack_34,pTVar3,&DAT_004db218);
  local_c._0_1_ = 0x21;
  (*(code *)TStack_64.data)(param_1,(int)pcVar8,iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
  local_c._0_1_ = 0x20;
  FUN_004b05a5(&TStack_34);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_004b05a5(&TStack_38);
  iVar11 = iVar11 + local_60;
  if (((double)DAT_004da1fc - _DAT_004cc5c0 < *(double *)(&DAT_004ffcb8 + param_6 * 8)) ||
     (((DAT_004da140 == 1 && (DAT_004da190 == 7)) && (DAT_005364c8 == 0)))) {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(param_1,0xff0000);
    }
    if (*(int *)(&DAT_004fe778 + param_6 * 4) == 1) {
      FUN_004b0613(&TStack_54,s_sail__flat_004db20c);
      local_c._0_1_ = 0x22;
      (*(code *)TStack_64.data)
                (param_1,(int)pcVar8,iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_54);
    }
    if (*(int *)(&DAT_004fe778 + param_6 * 4) == 2) {
      FUN_004b0613(&TStack_54,s_sail__medium_004db1fc);
      local_c._0_1_ = 0x23;
      (*(code *)TStack_64.data)
                (param_1,(int)pcVar8,iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_54);
    }
    if (*(int *)(&DAT_004fe778 + param_6 * 4) == 3) {
      FUN_004b0613(&TStack_54,s_sail__baggy_004db1f0);
      local_c._0_1_ = 0x24;
      (*(code *)TStack_64.data)
                (param_1,(int)pcVar8,iVar11,TStack_54.data,*(int *)(TStack_54.data + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_54);
    }
  }
  else {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(param_1,0xff);
    }
    pTVar3 = FUN_0041bc70(&TStack_38,(int)(longlong)*(double *)(&DAT_004ffcb8 + param_6 * 8));
    local_c._0_1_ = 0x25;
    pTVar3 = FUN_004b082f(&TStack_34,s_depth__004db278,pTVar3);
    local_c._0_1_ = 0x26;
    (*(code *)TStack_64.data)(param_1,(int)pcVar8,iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x25;
    FUN_004b05a5(&TStack_34);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_38);
    if (((*(double *)(&DAT_004ffcb8 + param_6 * 8) < (double)DAT_004da1fc - _DAT_004cc5c8) &&
        (DAT_00536520 == 0)) && (DAT_00536484 == 0)) {
      DAT_00536520 = 300;
      FUN_00489960();
    }
  }
  if (((*(double *)(&DAT_004ffcb8 + param_6 * 8) < (double)DAT_004da1fc - _DAT_004cc5c8) &&
      (DAT_00536520 == 0)) && (DAT_00536484 == 0)) {
    DAT_00536520 = 300;
    FUN_00489960();
  }
  iVar11 = iVar11 + local_60;
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0x7f);
  }
  TStack_58.data = (char *)FUN_0041bc20((&DAT_00522b90)[param_6] - DAT_004f7f94);
  if (0xb4 < (int)TStack_58.data) {
    TStack_58.data = TStack_58.data + -0x168;
  }
  TStack_54.data =
       (char *)(((uint)TStack_58.data ^ (int)TStack_58.data >> 0x1f) - ((int)TStack_58.data >> 0x1f)
               );
  DAT_00536428 = (uint)(0x46 < (int)TStack_54.data);
  if ((DAT_0053643c == 0) && (DAT_00536428 == 0)) {
    if (0 < (int)TStack_58.data * *(int *)(&DAT_00522ff0 + param_6 * 4)) {
      pTVar3 = FUN_0041bc70(&TStack_38,(int)TStack_54.data);
      local_c._0_1_ = 0x27;
      pTVar3 = FUN_004b082f(&TStack_34,s_lifted_004db1e8,pTVar3);
      local_c._0_1_ = 0x28;
      (*(code *)TStack_64.data)(param_1,(int)pcVar8,iVar11,pTVar3->data,*(int *)(pTVar3->data + -8))
      ;
      local_c._0_1_ = 0x27;
      FUN_004b05a5(&TStack_34);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_38);
    }
    if (TStack_58.data == (char *)0x0) {
      FUN_004b0613(&TStack_44,s_wind_average_004db1d8);
      local_c._0_1_ = 0x29;
      (*(code *)TStack_64.data)
                (param_1,(int)pcVar8,iVar11,TStack_44.data,
                 (int)((Tact2010CString *)(TStack_44.data + -8))->data);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_44);
    }
    if ((int)TStack_58.data * *(int *)(&DAT_00522ff0 + param_6 * 4) < 0) {
      if (DAT_0053643c == 0) {
        pTVar3 = FUN_0041bc70(&TStack_38,(int)TStack_54.data);
        local_c._0_1_ = 0x2a;
        pTVar3 = FUN_004b082f(&TStack_34,s_headed_004db1d0,pTVar3);
        local_c._0_1_ = 0x2b;
        (*(code *)TStack_64.data)
                  (param_1,(int)pcVar8,iVar11,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_c._0_1_ = 0x2a;
        FUN_004b05a5(&TStack_34);
        local_c = (uint)local_c._1_3_ << 8;
        FUN_004b05a5(&TStack_38);
      }
      if ((((DAT_004feccc < 0x37) &&
           (0x2d < (int)((DAT_00535ff4 ^ (int)DAT_00535ff4 >> 0x1f) - ((int)DAT_00535ff4 >> 0x1f))))
          && (10 < (int)TStack_54.data)) &&
         (((300 < (int)local_48.data && (param_6 == 1)) && (0 < DAT_004f8cd0)))) {
        DAT_004fb234 = 1;
      }
    }
    if (DAT_00536428 == 1) {
      if (DAT_005363e4 == 0) {
        (*pcVar2)(param_1,0x7f0000);
      }
      FUN_004b0613(&TStack_44,s_major_wind_change_004db1bc);
      local_c._0_1_ = 0x2c;
      (*(code *)TStack_64.data)
                (param_1,(int)pcVar8,iVar11,TStack_44.data,
                 (int)((Tact2010CString *)(TStack_44.data + -8))->data);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_44);
    }
    iVar11 = iVar11 + local_60;
  }
  if ((DAT_004da1a8 == 0) || (*(int *)(&DAT_004f71c0 + param_6 * 4) == 3)) {
    if (DAT_004fe624 < 0x385) {
      TStack_54.data = (char *)(param_2 + 1);
    }
    else {
      TStack_54.data = (char *)(param_2 + 10);
    }
  }
  else {
    TStack_54.data = (char *)(param_2 + 0x14);
  }
  if (DAT_00536428 == 1) {
    FUN_004b0613(&TStack_44,s_major_wind_change_004db1bc);
    local_c._0_1_ = 0x2d;
    (*(code *)TStack_64.data)
              (param_1,(int)pcVar8,iVar11,TStack_44.data,
               (int)((Tact2010CString *)(TStack_44.data + -8))->data);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_44);
  }
  if (((DAT_004da190 == 7) || (DAT_004da190 == 8)) && (DAT_005364c8 == 0)) {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(param_1,0x7f00);
    }
    pTVar3 = FUN_0041bc70(&TStack_28,(&DAT_00522b90)[param_6]);
    local_c._0_1_ = 0x2e;
    pTVar4 = FUN_0041bc70(&TStack_2c,(&DAT_004fb380)[param_6]);
    local_c._0_1_ = 0x2f;
    pTVar4 = FUN_004b082f(&TStack_30,s_true_wind__004db1b0,pTVar4);
    local_c._0_1_ = 0x30;
    pTVar4 = FUN_004b07bb(&TStack_44,pTVar4,&DAT_004db1a8);
    local_c._0_1_ = 0x31;
    pTVar3 = FUN_004b0755(&TStack_38,pTVar4,pTVar3);
    local_c._0_1_ = 0x32;
    pTVar3 = FUN_004b07bb(&TStack_34,pTVar3,&DAT_004daa64);
    local_c._0_1_ = 0x33;
    iVar11 = (int)((ulonglong)((longlong)DAT_004fe2a8 * -0x51eb851f) >> 0x20);
    (*(code *)TStack_64.data)
              (param_1,(int)TStack_54.data,
               ((iVar11 >> 4) - (iVar11 >> 0x1f)) + local_60 * -4 + DAT_0052318c,pTVar3->data,
               *(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x32;
    FUN_004b05a5(&TStack_34);
    local_c._0_1_ = 0x31;
    FUN_004b05a5(&TStack_38);
    local_c._0_1_ = 0x30;
    FUN_004b05a5(&TStack_44);
    local_c._0_1_ = 0x2f;
    FUN_004b05a5(&TStack_30);
    local_c._0_1_ = 0x2e;
    FUN_004b05a5(&TStack_2c);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_28);
  }
  uVar7 = (int)DAT_00535ff4 >> 0x1f;
  if ((param_6 == 1) && (0 < DAT_004f8cd0)) {
    if (DAT_004feccc < 0x37) {
      if (-1 < (int)TStack_58.data * DAT_00522ff4) {
        DAT_004f6d2c = DAT_004f6d2c + 1;
      }
      if (DAT_004feccc < 0x37) {
        DAT_00534e94 = DAT_00534e94 + 1;
      }
    }
    DAT_00534ea4 = DAT_00534ea4 + 1;
    if (0 < DAT_004fe8ac) {
      DAT_004fb220 = 1;
      DAT_004fe768 = DAT_004fe768 + 1;
    }
    if (((DAT_004feccc < 0x37) && (0x4b < (int)((DAT_00535ff4 ^ uVar7) - uVar7))) &&
       (DAT_00525a9c / 3 < (int)local_48.data)) {
      DAT_004fb234 = 2;
    }
    if ((((DAT_004feccc < 0x37) && (0x5a < (int)((DAT_00535ff4 ^ uVar7) - uVar7))) &&
        (0 < DAT_004f853c)) && (10 < DAT_004f8cd0)) {
      DAT_004fb234 = 3;
    }
  }
  if (((param_6 == 1) && (0 < (int)TStack_58.data * DAT_00522ff4)) &&
     ((0 < DAT_004f8cd0 && (iVar11 = 0xaa - DAT_004fae64, iVar11 <= DAT_004feccc)))) {
    if ((300 < (int)local_48.data) && (DAT_004fae64 < (int)((DAT_00535ff4 ^ uVar7) - uVar7))) {
      DAT_004fb234 = 0xffffffff;
    }
    if (iVar11 <= DAT_004feccc) {
      if ((700 < (int)local_48.data) &&
         ((DAT_004fae64 * 9) / 5 < (int)((DAT_00535ff4 ^ uVar7) - uVar7))) {
        DAT_004fb234 = 0xfffffffe;
      }
      if (((iVar11 <= DAT_004feccc) && (700 < (int)local_48.data)) &&
         (DAT_004fae64 * 2 < (int)((DAT_00535ff4 ^ uVar7) - uVar7))) {
        DAT_004fb234 = 0xfffffffd;
      }
    }
  }
  (*pcVar2)(param_1,0x7f7f7f);
  TVar10.data = TStack_54.data;
  if (DAT_004fe624 < 900) {
    TVar10.data = (char *)(param_2 + 1);
  }
  TVar9.data = TStack_64.data;
  if (DAT_004da1b0 == 1) {
    if (DAT_0053649c == 0) {
      FUN_004b0613(&TStack_44,s_Button_explanations_show_here__004db188);
      TVar9.data = TStack_64.data;
      local_c._0_1_ = 0x34;
      (*(code *)TStack_64.data)
                (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - local_60,
                 TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_44);
    }
    else {
      FUN_004640e0(param_1,local_60,param_2);
      TVar9.data = TStack_64.data;
    }
  }
  if (DAT_005363e4 == 0) {
    iVar11 = 0x7f0000;
  }
  else {
    iVar11 = 0;
  }
  (*pcVar2)(param_1,iVar11);
  TVar10.data = TStack_54.data;
  if (((*(int *)(&DAT_00511620 + param_6 * 4) == 0) &&
      (*(int *)(&DAT_004fecc8 + param_6 * 4) < 0x50)) && (DAT_005364c8 == 1)) {
    pTVar3 = FUN_0041bc70(&TStack_2c,*(int *)(&DAT_004fecc8 + param_6 * 4));
    local_c._0_1_ = 0x35;
    pTVar3 = FUN_004b082f(&TStack_28,s_pointing__004db17c,pTVar3);
    TVar10.data = TStack_54.data;
    local_c._0_1_ = 0x36;
    (*(code *)TVar9.data)
              (param_1,(int)TStack_54.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_5c,
               pTVar3->data,*(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x35;
    FUN_004b05a5(&TStack_28);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_2c);
  }
  if (*(int *)(&DAT_00511620 + param_6 * 4) == 1) {
    if (*(int *)(&DAT_005359e0 + param_6 * 4) == 0) {
      FUN_004b0613(&TStack_44,s_normal_closehauled_course_004db160);
      local_c._0_1_ = 0x37;
      (*(code *)TVar9.data)
                (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_5c,
                 TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_44);
    }
    if (*(int *)(&DAT_00511620 + param_6 * 4) == 1) {
      if (*(int *)(&DAT_005359e0 + param_6 * 4) == 5) {
        if (DAT_005363e4 == 0) {
          (*pcVar2)(param_1,0x7f);
        }
        FUN_004b0613(&TStack_44,s_closehauled___footing_004db148);
        local_c._0_1_ = 0x38;
        (*(code *)TVar9.data)
                  (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_5c,
                   TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
        local_c = (uint)local_c._1_3_ << 8;
        FUN_004b05a5(&TStack_44);
      }
      if ((*(int *)(&DAT_00511620 + param_6 * 4) == 1) &&
         (*(int *)(&DAT_005359e0 + param_6 * 4) == -5)) {
        if (DAT_005363e4 == 0) {
          (*pcVar2)(param_1,0x7f);
        }
        FUN_004b0613(&TStack_44,s_closehauled___pinching_004db130);
        local_c._0_1_ = 0x39;
        (*(code *)TVar9.data)
                  (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_5c,
                   TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
        local_c = (uint)local_c._1_3_ << 8;
        FUN_004b05a5(&TStack_44);
      }
    }
  }
  if (*(int *)(&DAT_004f6a68 + param_6 * 4) == 1) {
    if (*(int *)(&DAT_004f3f60 + param_6 * 4) == 0) {
      FUN_004b0613(&TStack_44,s_run___good_angle_004db11c);
      local_c._0_1_ = 0x3a;
      (*(code *)TVar9.data)
                (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_5c,
                 TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_004b05a5(&TStack_44);
    }
    if (*(int *)(&DAT_004f6a68 + param_6 * 4) == 1) {
      if (*(int *)(&DAT_004f3f60 + param_6 * 4) == -7) {
        if (DAT_005363e4 == 0) {
          (*pcVar2)(param_1,0x7f);
        }
        FUN_004b0613(&TStack_44,s_running_7_deg_high_004db108);
        local_c._0_1_ = 0x3b;
        (*(code *)TVar9.data)
                  (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_5c,
                   TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
        local_c = (uint)local_c._1_3_ << 8;
        FUN_004b05a5(&TStack_44);
      }
      if ((*(int *)(&DAT_004f6a68 + param_6 * 4) == 1) &&
         (*(int *)(&DAT_004f3f60 + param_6 * 4) == 7)) {
        if (DAT_005363e4 == 0) {
          (*pcVar2)(param_1,0x7f);
        }
        FUN_004b0613(&TStack_44,s_running_7_deg_low_004db0f4);
        local_c._0_1_ = 0x3c;
        (*(code *)TVar9.data)
                  (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_5c,
                   TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
        local_c = (uint)local_c._1_3_ << 8;
        FUN_004b05a5(&TStack_44);
      }
    }
  }
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0x7f0000);
  }
  if (DAT_005363b4 == 0) {
    if ((DAT_004da174 == 1) && (DAT_005363e4 == 0)) {
      (*pcVar2)(param_1,0xff);
    }
    pTVar3 = FUN_0041bc70(&TStack_2c,DAT_004da174);
    local_c._0_1_ = 0x3d;
    pTVar3 = FUN_004b082f(&TStack_28,s_simulator_speed__004db0e0,pTVar3);
    local_c._0_1_ = 0x3e;
    local_48.data = (char *)(local_60 * 3);
    (*(code *)TVar9.data)
              (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) + local_60 * -3,
               pTVar3->data,*(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x3d;
    FUN_004b05a5(&TStack_28);
    pTVar3 = &TStack_2c;
  }
  else {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(param_1,0xff);
    }
    FUN_004b0613(&TStack_44,s_movement_suspended_004db0cc);
    local_c._0_1_ = 0x3f;
    local_48.data = (char *)(local_60 * 3);
    (*(code *)TVar9.data)
              (param_1,(int)TVar10.data,(DAT_0052318c - DAT_004fe2a8 / 0x32) + local_60 * -3,
               TStack_44.data,(int)((Tact2010CString *)(TStack_44.data + -8))->data);
    pTVar3 = &TStack_44;
  }
  local_c = (uint)local_c._1_3_ << 8;
  FUN_004b05a5(pTVar3);
  local_5c = local_24.data + 0xf;
  if (DAT_004fe624 < 0x3e9) {
    iVar11 = DAT_004fe624 / 0x11;
  }
  else {
    iVar11 = DAT_004fe624 / 0x14;
  }
  TStack_58.data = local_5c + iVar11;
  iVar11 = (DAT_0052318c - DAT_004fe2a8 / 0x32) - (int)local_48.data;
  local_48.data = (char *)(iVar11 + local_60);
  FUN_00463f50(param_1,(int)local_5c,iVar11,(int)TStack_58.data,(int)local_48.data,1,-1);
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0xff00);
  }
  FUN_004b0613(&TStack_44,s_faster_004db0c4);
  local_c._0_1_ = 0x40;
  (*(code *)TVar9.data)
            (param_1,(int)(local_5c + 6),iVar11,TStack_44.data,
             (int)((Tact2010CString *)(TStack_44.data + -8))->data);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_004b05a5(&TStack_44);
  if (((((int)local_5c < DAT_005364a0) && (DAT_005364a0 < (int)TStack_58.data)) &&
      (DAT_005364a4 < (int)local_48.data)) && (iVar11 < DAT_005364a4)) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Simulator_runs_1_unit_faster_per_004db09c);
    DAT_0053649c = 1;
    FUN_004640e0(param_1,local_60,param_2);
  }
  if ((((int)local_5c < DAT_004fe75c) && (DAT_004fe75c < (int)TStack_58.data)) &&
     ((DAT_005233a4 < (int)local_48.data && (iVar11 < DAT_005233a4)))) {
    DAT_004da174 = DAT_004da174 + 1;
    if (0xf < DAT_004da174) {
      DAT_004da174 = 0xf;
    }
    FUN_00464940();
    DAT_005233a4 = 0;
  }
  local_5c = TStack_58.data + 10;
  if (DAT_004fe624 < 0x3e9) {
    iVar12 = DAT_004fe624 / 0xf;
  }
  else {
    iVar12 = DAT_004fe624 / 0x12;
  }
  TStack_58.data = local_5c + iVar12;
  FUN_00463f50(param_1,(int)local_5c,iVar11,(int)TStack_58.data,(int)local_48.data,1,-1);
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0x7f);
  }
  FUN_004b0613(&TStack_44,s_slower_004db094);
  local_c._0_1_ = 0x41;
  (*(code *)TVar9.data)
            (param_1,(int)(local_5c + 6),iVar11,TStack_44.data,
             (int)((Tact2010CString *)(TStack_44.data + -8))->data);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_004b05a5(&TStack_44);
  if ((((int)local_5c < DAT_005364a0) && (DAT_005364a0 < (int)TStack_58.data)) &&
     ((DAT_005364a4 < (int)local_48.data && (iVar11 < DAT_005364a4)))) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Simulator_runs_1_unit_slower_per_004db06c);
    DAT_0053649c = 1;
    FUN_004640e0(param_1,local_60,param_2);
  }
  if (((((int)local_5c < DAT_004fe75c) && (DAT_004fe75c < (int)TStack_58.data)) &&
      (DAT_005233a4 < (int)local_48.data)) && (iVar11 < DAT_005233a4)) {
    DAT_004da174 = DAT_004da174 + -1;
    if (DAT_004da174 < 1) {
      DAT_004da174 = 1;
    }
    FUN_00464940();
    DAT_005233a4 = 0;
  }
  if (DAT_005363e4 == 0) {
    (*pcVar2)(param_1,0x7f7f00);
  }
  if ((0 < DAT_004f8cd0) && (9 < (int)DAT_004fad34)) {
    pTVar3 = FUN_0041bc70(&TStack_34,DAT_004fad34);
    local_c._0_1_ = 0x42;
    pTVar4 = FUN_0041bc70(&TStack_30,DAT_004f6d60);
    local_c._0_1_ = 0x43;
    pTVar4 = FUN_004b082f(&TStack_2c,s_time__004db064,pTVar4);
    local_c._0_1_ = 0x44;
    pTVar4 = FUN_004b07bb(&TStack_28,pTVar4,&DAT_004db060);
    local_c._0_1_ = 0x45;
    pTVar3 = FUN_004b0755(&local_24,pTVar4,pTVar3);
    local_c._0_1_ = 0x46;
    iVar11 = (int)((ulonglong)((longlong)DAT_004fe2a8 * -0x51eb851f) >> 0x20);
    (*(code *)TVar9.data)
              (param_1,(param_2 + param_4 * 2) / 3 + -3,
               ((iVar11 >> 4) - (iVar11 >> 0x1f)) + local_60 * -4 + DAT_0052318c,pTVar3->data,
               *(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x45;
    FUN_004b05a5(&local_24);
    local_c._0_1_ = 0x44;
    FUN_004b05a5(&TStack_28);
    local_c._0_1_ = 0x43;
    FUN_004b05a5(&TStack_2c);
    local_c._0_1_ = 0x42;
    FUN_004b05a5(&TStack_30);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_34);
  }
  if ((0 < DAT_004f8cd0) && ((int)DAT_004fad34 < 10)) {
    local_24.data = (char *)FUN_0041bc70(&TStack_38,DAT_004fad34);
    local_c._0_1_ = 0x47;
    pTVar3 = FUN_0041bc70(&TStack_34,DAT_004f6d60);
    local_c._0_1_ = 0x48;
    pTVar3 = FUN_004b082f(&TStack_30,s_time__004db064,pTVar3);
    local_c._0_1_ = 0x49;
    pTVar3 = FUN_004b07bb(&TStack_2c,pTVar3,&DAT_004db05c);
    local_c._0_1_ = 0x4a;
    pTVar3 = FUN_004b0755(&TStack_28,pTVar3,(Tact2010CString *)local_24.data);
    local_c._0_1_ = 0x4b;
    local_24.data = (char *)(local_60 * 4);
    iVar11 = (int)((ulonglong)((longlong)DAT_004fe2a8 * -0x51eb851f) >> 0x20);
    (*(code *)TVar9.data)
              (param_1,(param_2 + param_4 * 2) / 3 + -3,
               ((iVar11 >> 4) - (iVar11 >> 0x1f)) + local_60 * -4 + DAT_0052318c,pTVar3->data,
               *(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x4a;
    FUN_004b05a5(&TStack_28);
    local_c._0_1_ = 0x49;
    FUN_004b05a5(&TStack_2c);
    local_c._0_1_ = 0x48;
    FUN_004b05a5(&TStack_30);
    local_c._0_1_ = 0x47;
    FUN_004b05a5(&TStack_34);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&TStack_38);
  }
  (*pcVar2)(param_1,0);
  SelectObject((HDC)local_40.data,local_20.data);
  DeleteObject(local_1c[0].data);
  TVar10.data = (char *)(DAT_004fe2a8 / 0x32);
  TStack_54.data = TVar10.data;
  if (((DAT_004f8ee4 - DAT_004f3ff0 / 0xf <= DAT_0052318c - (int)TVar10.data) ||
      (DAT_004f7f78 <= DAT_005230e0 + -0x14)) || (DAT_00525a68 + 0x14 <= DAT_004f7f78)) {
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    TStack_44.data = TStack_54.data * 10;
    Rectangle((HDC)param_1[1],param_2,DAT_0052318c - (int)TStack_54.data,param_4,
              (int)(TStack_44.data + DAT_0052318c));
    (*pcStack_50)(param_1,0x7f7f7f);
    if (DAT_004fe624 < 0x385) {
      local_48.data = (char *)(param_2 - param_4);
      iVar6 = param_2 - ((int)((int)&((HRGN)local_48.data)->unused +
                              ((int)local_48.data >> 0x1f & 3U)) >> 2);
      iVar11 = iVar6 + 0xc;
      iVar5 = param_2 - (int)local_48.data / 3;
      iVar12 = iVar5 + 0xc;
    }
    else if (DAT_004f82fc < 0x15) {
      local_48.data = (char *)(param_2 - param_4);
      iVar6 = param_2 - ((int)((int)&((HRGN)local_48.data)->unused +
                              ((int)local_48.data >> 0x1f & 3U)) >> 2);
      iVar11 = iVar6 + 0x1e;
      iVar5 = param_2 - (int)local_48.data / 3;
      iVar12 = iVar5 + 0x1e;
    }
    else {
      local_48.data = (char *)(param_2 - param_4);
      iVar6 = param_2 - ((int)((int)&((HRGN)local_48.data)->unused +
                              ((int)local_48.data >> 0x1f & 3U)) >> 2);
      iVar11 = iVar6 + 0x10;
      iVar5 = param_2 - (int)local_48.data / 3;
      iVar12 = iVar5 + 0x10;
    }
    if (DAT_004fe624 < 700) {
      iVar11 = iVar6 + -1;
      iVar12 = iVar5 + -1;
    }
    local_1c[0].data = (char *)((DAT_004fe624 < 0x4b1) - 1 & 0x15);
    if ((DAT_004da1a8 == 0) || (*(int *)(&DAT_004f71c0 + param_6 * 4) == 3)) {
      FUN_004b0613(&local_40,s_Steering_Zone_004db04c);
      local_c._0_1_ = 0x4c;
      (*(code *)TStack_64.data)
                (param_1,iVar11,(DAT_0052318c - (int)TStack_54.data) + 2,local_40.data,
                 ((HDC)(local_40.data + -8))->unused);
    }
    else {
      FUN_004b0613(&local_40,s_Steering_Zone_004db04c);
      local_c._0_1_ = 0x4d;
      (*(code *)TStack_64.data)
                (param_1,(int)(local_1c[0].data + iVar12),(DAT_0052318c - (int)TStack_54.data) + 2,
                 local_40.data,((HDC)(local_40.data + -8))->unused);
    }
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&local_40);
    (*pcStack_50)(param_1,0xffffff);
    TVar10.data = TStack_54.data;
    goto LAB_00411526;
  }
  if (DAT_005363e4 == 0) {
    if (DAT_004f4a5c != (HGDIOBJ)0x0) {
      hdc = (HDC)param_1[1];
      h = DAT_004f4a5c;
override_prt_41132f_6059bb06:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_005230cc != (HGDIOBJ)0x0) {
    hdc = (HDC)param_1[1];
    h = DAT_005230cc;
    goto override_prt_41132f_6059bb06;
  }
  TStack_44.data = (char *)((int)TVar10.data * 10);
  Rectangle((HDC)param_1[1],param_2,DAT_0052318c - (int)TVar10.data,param_4,
            (int)(TStack_44.data + DAT_0052318c));
LAB_00411526:
  (*local_3c)(param_1,7);
  FUN_004b4d9d(param_1,(int *)local_1c,(int)DAT_004fe088,DAT_0052318c - (int)TVar10.data);
  CDC::LineTo(param_1,(int)DAT_004fe088,(int)(TStack_44.data + DAT_0052318c));
  if (((0 < DAT_00536488) && (DAT_004da1a8 == 1)) && (DAT_004da140 == 1)) {
    local_3c = (code *)0xbb8;
    local_48.data = (char *)0x2;
    TVar10.data = local_1c[0].data;
    if (1 < DAT_004da194) {
      iVar11 = 0;
      do {
        FUN_0043ec20(*(double *)((int)&DAT_004f6b08 + iVar11),
                     *(double *)((int)&DAT_004f6c20 + iVar11),1,1);
        if ((int)(code *)(longlong)_DAT_004fbb88 < (int)local_3c) {
          TVar10.data = local_48.data;
          local_3c = (code *)(longlong)_DAT_004fbb88;
        }
        local_48.data = local_48.data + 1;
        iVar11 = iVar11 + 8;
      } while ((int)local_48.data <= DAT_004da194);
    }
    pcVar1 = pcStack_50;
    if ((DAT_004da194 < (int)TVar10.data) || ((int)TVar10.data <= DAT_004da140)) {
      TVar10.data = (char *)0x3;
    }
    (*pcStack_50)(param_1,0x7f7f7f);
    (*pcVar1)(param_1,0xffffff);
    FUN_0041f3e0(param_1,(int)TVar10.data);
    FUN_004b4a1f(param_1,2);
    if (DAT_005364c8 == 1) {
      pTVar3 = FUN_0041bd00(&local_20,
                            *(double *)(&DAT_004fe180 + (int)TVar10.data * 8) * _DAT_004cc5b0);
      local_c._0_1_ = 0x4e;
      pTVar3 = FUN_004b082f(local_1c,s_nearest__004db040,pTVar3);
      local_c._0_1_ = 0x4f;
      iVar11 = param_2 - param_4;
      iVar12 = local_60 / 2 - (int)TStack_54.data;
      (*(code *)TStack_64.data)
                (param_1,param_2 - iVar11 / 5,DAT_0052318c + iVar12,pTVar3->data,
                 *(int *)(pTVar3->data + -8));
      local_c._0_1_ = 0x4e;
      FUN_004b05a5(local_1c);
    }
    else {
      pTVar3 = FUN_0041bd00(&local_20,
                            *(double *)(&DAT_004fe180 + (int)TVar10.data * 8) * _DAT_004cc5b8);
      local_c._0_1_ = 0x50;
      pTVar3 = FUN_004b082f(local_1c,s_nearest__004db040,pTVar3);
      local_c._0_1_ = 0x51;
      iVar12 = local_60 / 2 - (int)TStack_54.data;
      iVar11 = param_2 - param_4;
      (*(code *)TStack_64.data)
                (param_1,param_2 - iVar11 / 5,DAT_0052318c + iVar12,pTVar3->data,
                 *(int *)(pTVar3->data + -8));
      local_c._0_1_ = 0x50;
      FUN_004b05a5(local_1c);
    }
    local_c._0_1_ = 0;
    FUN_004b05a5(&local_20);
    (*pcVar2)(param_1,0x7f0000);
    local_1c[0].data =
         (char *)((DAT_004fe178 ^ (int)DAT_004fe178 >> 0x1f) - ((int)DAT_004fe178 >> 0x1f));
    pTVar3 = FUN_0041bd00(&local_20,(double)(int)local_1c[0].data * _DAT_004cc3f0);
    local_c._0_1_ = 0x52;
    pTVar3 = FUN_004b082f(local_1c,&DAT_004db038,pTVar3);
    local_c._0_1_ = 0x53;
    (*(code *)TStack_64.data)
              (param_1,param_2 + 1,DAT_0052318c + iVar12,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x52;
    FUN_004b05a5(local_1c);
    local_c._0_1_ = 0;
    FUN_004b05a5(&local_20);
    pTVar3 = FUN_0041bc70(&local_20,DAT_004fc2c4);
    local_c._0_1_ = 0x54;
    pTVar3 = FUN_004b082f(local_1c,s_Tip__004db030,pTVar3);
    local_c._0_1_ = 0x55;
    (*(code *)TStack_64.data)
              (param_1,param_2 - iVar11 / 2,DAT_0052318c + iVar12,pTVar3->data,
               *(int *)(pTVar3->data + -8));
    local_c._0_1_ = 0x54;
    FUN_004b05a5(local_1c);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_004b05a5(&local_20);
    FUN_004b4a1f(param_1,1);
  }
  (*pcStack_50)(param_1,0xffffff);
  local_c = 0xffffffff;
  FUN_004b05a5(&local_4c);
  *unaff_FS_OFFSET = uStack_14;
  return;
}


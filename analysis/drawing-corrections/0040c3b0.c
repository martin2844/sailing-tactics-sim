
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040c3b0(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  COLORREF CVar1;
  TactCString *pTVar2;
  TactCString *pTVar3;
  uint uVar4;
  int iVar5;
  LPCSTR pCVar6;
  TactCString TVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar9;
  HDC hdc;
  HGDIOBJ h;
  TactCString TStack_60;
  code *pcStack_5c;
  int local_58;
  TactCString TStack_54;
  LPCSTR local_50;
  TactCString local_4c;
  TactCString TStack_48;
  code *local_44;
  TactCString TStack_40;
  HDC local_3c;
  code *local_38;
  TactCString TStack_34;
  TactCString TStack_30;
  TactCString TStack_2c;
  TactCString TStack_28;
  TactCString TStack_24;
  LPCSTR local_20 [2];
  TactCString local_18;
  undefined4 uStack_14;
  code *pcStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  pcStack_10 = FUN_0047dc18;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_3c = *(HDC *)(param_1 + 4);
  local_18.data = (char *)CreateRectRgn(param_2,param_3,param_4,param_5);
  local_20[0] = SelectObject(local_3c,local_18.data);
  FUN_0046bd7a(&local_4c);
  local_c._0_1_ = 0;
  local_c._1_3_ = 0;
  FUN_0046c00d(&DAT_004a7048,&DAT_004aca50);
  DAT_004ac9dc = 0;
  DAT_004a70ec = (param_4 + param_2) / 2;
  DAT_004aa824 = (param_3 + param_5 * 4) / 5;
  local_58 = DAT_004a72d0 / 0x1e;
  if ((DAT_004ac9c8 == 1) && (*(int *)(&DAT_004a4e88 + param_6 * 4) < 3)) {
    iVar8 = param_4 + param_2 * 3;
    local_44 = (code *)((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2);
    pCVar6 = (LPCSTR)((int)local_44 + 10);
  }
  else {
    local_44 = (code *)((param_4 + param_2 * 4) / 5);
    pCVar6 = (LPCSTR)((int)local_44 + 5);
  }
  local_50 = *(LPCSTR *)param_1;
  local_38 = *(code **)(local_50 + 0x2c);
  (*local_38)(param_1,7);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  (*local_38)(param_1,0);
  Rectangle(*(HDC *)(param_1 + 4),param_2,param_3,param_4,param_5);
  FUN_00409760((int)param_1,param_2,param_3,param_4,param_5,param_6,local_58);
  FUN_0040db30((int)param_1,param_2,param_3,param_4,(int)local_44,param_6,local_58);
  iVar8 = param_3 + 1;
  local_44 = *(code **)(local_50 + 0x34);
  (*local_44)(param_1,0xffffff);
  if (DAT_004ac92c == 0) {
    CVar1 = 0xff;
    pcStack_5c = *(code **)(local_50 + 0x38);
  }
  else {
    CVar1 = 0;
    pcStack_5c = *(code **)(local_50 + 0x38);
  }
  (*pcStack_5c)(param_1,CVar1);
  if (DAT_004a5b80 < 1) {
    TStack_40.data =
         (char *)FUN_00413d00(&TStack_30,
                              (DAT_004a6778 ^ (int)DAT_004a6778 >> 0x1f) -
                              ((int)DAT_004a6778 >> 0x1f));
    local_c._0_1_ = 1;
    pTVar2 = FUN_00413d00(&TStack_34,
                          (DAT_004a5e84 ^ (int)DAT_004a5e84 >> 0x1f) - ((int)DAT_004a5e84 >> 0x1f));
    local_c._0_1_ = 2;
    pTVar2 = FUN_0046c0db(&TStack_60,pTVar2,s_min_00491eb8);
    local_c._0_1_ = 3;
    pTVar2 = FUN_0046c075(&TStack_54,pTVar2,(TactCString *)TStack_40.data);
    local_c._0_1_ = 4;
    pTVar2 = FUN_0046c0db(&TStack_48,pTVar2,&DAT_00491eb0);
    local_c._0_1_ = 5;
    (**(code **)(local_50 + 100))
              (param_1,(int)pCVar6,iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_c._0_1_ = 4;
    FUN_0046bec5((int *)&TStack_48);
    local_c._0_1_ = 3;
    FUN_0046bec5((int *)&TStack_54);
    local_c._0_1_ = 2;
    FUN_0046bec5((int *)&TStack_60);
    local_c._0_1_ = 1;
    FUN_0046bec5((int *)&TStack_34);
    local_c._0_1_ = 0;
    FUN_0046bec5((int *)&TStack_30);
    iVar8 = iVar8 + local_58 * 2;
    if (0 < DAT_004a5b80) goto LAB_0040c690;
  }
  else {
LAB_0040c690:
    DAT_004aa7e0 = FUN_0042d0c0(param_6);
    fVar9 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + DAT_004aa7e0 * 8),
                                          *(undefined4 *)(&DAT_004a52f0 + DAT_004aa7e0 * 8)),
                         (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + DAT_004aa7e0 * 8),
                                          *(undefined4 *)(&DAT_004a60b0 + DAT_004aa7e0 * 8)),0,
                         param_6);
    _DAT_004aa6e4 = (undefined4)(longlong)(_DAT_004a6828 * _DAT_00484d70);
    DAT_004ac66c = FUN_00415dc0((int)(longlong)(fVar9 * (float10)_DAT_00484d78) -
                                *(int *)(&DAT_004ac018 + param_6 * 4));
    TStack_48.data = (char *)(longlong)_DAT_004a6828;
    if (DAT_004ac92c == 0) {
      if ((DAT_004aa7e0 == 3) || (DAT_004aa7e0 == 5)) {
        CVar1 = 0x7f;
      }
      else {
        CVar1 = 0x7f7f;
      }
      (*pcStack_5c)(param_1,CVar1);
      if (DAT_004aa7e0 == 2) {
        (*pcStack_5c)(param_1,0x7f7f7f);
      }
    }
    FUN_0046bf33(&TStack_54,s_mark__00491ea8);
    local_c._0_1_ = 6;
    TStack_60.data = *(char **)(local_50 + 100);
    (*(code *)TStack_60.data)
              (param_1,(int)pCVar6,iVar8,TStack_54.data,*(int *)(TStack_54.data + -8));
    local_c._0_1_ = 0;
    FUN_0046bec5((int *)&TStack_54);
    iVar8 = iVar8 + local_58;
    DAT_004a6770 = DAT_004ac66c;
    if (0 < (int)DAT_004ac66c) {
      pTVar2 = FUN_00413d00(&TStack_34,DAT_004ac66c);
      local_c._0_1_ = 7;
      pTVar2 = FUN_0046c0db(&TStack_30,pTVar2,s_deg_to_Star_00491e98);
      local_c._0_1_ = 8;
      (*(code *)TStack_60.data)
                (param_1,(int)(pCVar6 + 10),iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_c._0_1_ = 7;
      FUN_0046bec5((int *)&TStack_30);
      local_c._0_1_ = 0;
      FUN_0046bec5((int *)&TStack_34);
    }
    if ((int)DAT_004ac66c < 0) {
      pTVar2 = FUN_00413d00(&TStack_34,
                            (DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f)
                           );
      local_c._0_1_ = 9;
      pTVar2 = FUN_0046c0db(&TStack_30,pTVar2,s_deg_to_Port_00491e88);
      local_c._0_1_ = 10;
      (*(code *)TStack_60.data)
                (param_1,(int)(pCVar6 + 10),iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_c._0_1_ = 9;
      FUN_0046bec5((int *)&TStack_30);
      local_c._0_1_ = 0;
      FUN_0046bec5((int *)&TStack_34);
    }
    if (DAT_004ac66c == 0) {
      FUN_0046bf33(&TStack_54,s_ahead_00491c18);
      local_c._0_1_ = 0xb;
      (*(code *)TStack_60.data)
                (param_1,(int)(pCVar6 + 10),iVar8,TStack_54.data,*(int *)(TStack_54.data + -8));
      local_c._0_1_ = 0;
      FUN_0046bec5((int *)&TStack_54);
    }
    iVar8 = iVar8 + local_58;
  }
  if (DAT_004ac92c == 0) {
    (*pcStack_5c)(param_1,0x7f0000);
  }
  pTVar2 = FUN_00413d90(&TStack_30,*(double *)(&DAT_004a71c8 + param_6 * 8) * _DAT_00484d48);
  local_c._0_1_ = 0xc;
  FUN_0046bfbe(&local_4c,(int *)pTVar2);
  local_c._0_1_ = 0;
  FUN_0046bec5((int *)&TStack_30);
  pTVar2 = FUN_0046c14f(&TStack_30,s_speed__00491e80,&local_4c);
  local_c._0_1_ = 0xd;
  TStack_60.data = *(char **)(local_50 + 100);
  (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
  local_c = (uint)local_c._1_3_ << 8;
  FUN_0046bec5((int *)&TStack_30);
  iVar8 = iVar8 + local_58;
  if (DAT_004ac92c == 0) {
    (*pcStack_5c)(param_1,0x7f00);
  }
  if (*(int *)(&DAT_004a7868 + param_6 * 4) == 0) {
    FUN_0046bf33(&local_50,s_clear_air_00491e74);
    local_c._0_1_ = 0xe;
    (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,local_50,*(int *)(local_50 + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&local_50);
  }
  else if (DAT_004ac92c == 0) {
    (*pcStack_5c)(param_1,0xff);
  }
  if ((*(int *)(&DAT_004a7868 + param_6 * 4) == 2) || (*(int *)(&DAT_004a7868 + param_6 * 4) == 0xc)
     ) {
    FUN_0046bf33(&local_50,s_blanketed_00491e68);
    local_c._0_1_ = 0xf;
    (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,local_50,*(int *)(local_50 + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&local_50);
  }
  if (*(int *)(&DAT_004a7868 + param_6 * 4) == 3) {
    FUN_0046bf33(&local_50,s_backwinded_00491e5c);
    local_c._0_1_ = 0x10;
    (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,local_50,*(int *)(local_50 + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&local_50);
  }
  iVar8 = iVar8 + local_58;
  if (DAT_004ac92c == 0) {
    (*pcStack_5c)(param_1,0x7f0000);
  }
  pTVar2 = FUN_00413d00(&TStack_30,*(int *)(&DAT_004a8aa8 + param_6 * 4));
  local_c._0_1_ = 0x11;
  FUN_0046bfbe(&local_4c,(int *)pTVar2);
  local_c._0_1_ = 0;
  FUN_0046bec5((int *)&TStack_30);
  pTVar2 = FUN_0046c14f(&TStack_34,s_luffing__00491e50,&local_4c);
  local_c._0_1_ = 0x12;
  pTVar2 = FUN_0046c0db(&TStack_30,pTVar2,&DAT_00491e4c);
  local_c._0_1_ = 0x13;
  (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
  local_c._0_1_ = 0x12;
  FUN_0046bec5((int *)&TStack_30);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_0046bec5((int *)&TStack_34);
  iVar8 = iVar8 + local_58;
  if (*(double *)(&DAT_004a7f28 + param_6 * 8) <= _DAT_00484d80) {
    if (DAT_004ac92c == 0) {
      (*pcStack_5c)(param_1,0xff);
    }
    pTVar2 = FUN_00413d00(&TStack_34,(int)(longlong)*(double *)(&DAT_004a7f28 + param_6 * 8));
    local_c._0_1_ = 0x17;
    pTVar2 = FUN_0046c14f(&TStack_30,s_depth__00491e1c,pTVar2);
    local_c._0_1_ = 0x18;
    (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_c._0_1_ = 0x17;
    FUN_0046bec5((int *)&TStack_30);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_34);
    if (((*(double *)(&DAT_004a7f28 + param_6 * 8) < _DAT_00484d80) &&
        (_DAT_00484d80 < *(double *)(&DAT_004a4510 + param_6 * 8))) && (DAT_004ac9c0 == 0)) {
      MessageBeep(0);
    }
  }
  else {
    if (DAT_004ac92c == 0) {
      (*pcStack_5c)(param_1,0xff0000);
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 1) {
      FUN_0046bf33(&local_50,s_sail__flat_00491e40);
      local_c._0_1_ = 0x14;
      (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,local_50,*(int *)(local_50 + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&local_50);
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 2) {
      FUN_0046bf33(&local_50,s_sail__medium_00491e30);
      local_c._0_1_ = 0x15;
      (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,local_50,*(int *)(local_50 + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&local_50);
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 3) {
      FUN_0046bf33(&local_50,s_sail__baggy_00491e24);
      local_c._0_1_ = 0x16;
      (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,local_50,*(int *)(local_50 + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&local_50);
    }
  }
  iVar8 = iVar8 + local_58;
  if (DAT_004ac92c == 0) {
    (*pcStack_5c)(param_1,0x7f);
  }
  TStack_54.data = (char *)FUN_00413cb0(*(int *)(&DAT_004aa5b0 + param_6 * 4) - DAT_004a4f8c);
  if (0xb4 < (int)TStack_54.data) {
    TStack_54.data = TStack_54.data + -0x168;
  }
  local_50 = (LPCSTR)(((uint)TStack_54.data ^ (int)TStack_54.data >> 0x1f) -
                     ((int)TStack_54.data >> 0x1f));
  DAT_004ac964 = (uint)(0x46 < (int)local_50);
  if ((DAT_004ac978 == 0) && (DAT_004ac964 == 0)) {
    if (0 < (int)TStack_54.data * *(int *)(&DAT_004aa730 + param_6 * 4)) {
      pTVar2 = FUN_00413d00(&TStack_34,(int)local_50);
      local_c._0_1_ = 0x19;
      pTVar2 = FUN_0046c14f(&TStack_30,s_lifted_00491e14,pTVar2);
      local_c._0_1_ = 0x1a;
      (*(code *)TStack_60.data)(param_1,(int)pCVar6,iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_c._0_1_ = 0x19;
      FUN_0046bec5((int *)&TStack_30);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_34);
    }
    if (TStack_54.data == (char *)0x0) {
      FUN_0046bf33(&TStack_40,s_wind_average_00491e04);
      local_c._0_1_ = 0x1b;
      (*(code *)TStack_60.data)
                (param_1,(int)pCVar6,iVar8,TStack_40.data,
                 (int)((TactCString *)(TStack_40.data + -8))->data);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_40);
    }
    if ((int)TStack_54.data * *(int *)(&DAT_004aa730 + param_6 * 4) < 0) {
      if (DAT_004ac978 == 0) {
        pTVar2 = FUN_00413d00(&TStack_34,(int)local_50);
        local_c._0_1_ = 0x1c;
        pTVar2 = FUN_0046c14f(&TStack_30,s_headed_00491dfc,pTVar2);
        local_c._0_1_ = 0x1d;
        (*(code *)TStack_60.data)
                  (param_1,(int)pCVar6,iVar8,pTVar2->data,*(int *)(pTVar2->data + -8));
        local_c._0_1_ = 0x1c;
        FUN_0046bec5((int *)&TStack_30);
        local_c = (uint)local_c._1_3_ << 8;
        FUN_0046bec5((int *)&TStack_34);
      }
      if (((DAT_004a7bcc < 0x37) &&
          (0x2d < (int)((DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f))))
         && ((10 < (int)local_50 &&
             (((300 < (int)TStack_48.data && (param_6 == 1)) && (0 < DAT_004a5b80)))))) {
        DAT_004a620c = 1;
      }
    }
    if (DAT_004ac964 == 1) {
      if (DAT_004ac92c == 0) {
        (*pcStack_5c)();
      }
      FUN_0046bf33(&TStack_40,s_major_wind_change_00491de8);
      local_c._0_1_ = 0x1e;
      (*(code *)TStack_60.data)(pCVar6,iVar8,TStack_40.data);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_40);
    }
    iVar8 = iVar8 + local_58;
  }
  if ((DAT_004ac9c8 == 0) || (local_50 = pCVar6, *(int *)(&DAT_004a4e88 + param_6 * 4) == 3)) {
    local_50 = (LPCSTR)(param_2 + 10);
  }
  if (DAT_004ac964 == 1) {
    FUN_0046bf33(&TStack_40,s_major_wind_change_00491de8);
    local_c._0_1_ = 0x1f;
    (*(code *)TStack_60.data)
              (param_1,(int)pCVar6,iVar8,TStack_40.data,
               (int)((TactCString *)(TStack_40.data + -8))->data);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_40);
  }
  if ((DAT_00491188 == 7) || (DAT_00491188 == 8)) {
    if (DAT_004ac92c == 0) {
      (*pcStack_5c)(param_1,0x7f00);
    }
    pTVar2 = FUN_00413d00(&TStack_24,*(int *)(&DAT_004aa5b0 + param_6 * 4));
    local_c._0_1_ = 0x20;
    pTVar3 = FUN_00413d00(&TStack_28,*(int *)(&DAT_004a6338 + param_6 * 4));
    local_c._0_1_ = 0x21;
    pTVar3 = FUN_0046c14f(&TStack_2c,s_true_wind__00491ddc,pTVar3);
    local_c._0_1_ = 0x22;
    pTVar3 = FUN_0046c0db(&TStack_40,pTVar3,&DAT_00491dd4);
    local_c._0_1_ = 0x23;
    pTVar2 = FUN_0046c075(&TStack_34,pTVar3,pTVar2);
    local_c._0_1_ = 0x24;
    pTVar2 = FUN_0046c0db(&TStack_30,pTVar2,&DAT_0049198c);
    local_c._0_1_ = 0x25;
    iVar8 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
    (*(code *)TStack_60.data)
              (param_1,(int)local_50,((iVar8 >> 4) - (iVar8 >> 0x1f)) + local_58 * -4 + DAT_004aa824
               ,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_c._0_1_ = 0x24;
    FUN_0046bec5((int *)&TStack_30);
    local_c._0_1_ = 0x23;
    FUN_0046bec5((int *)&TStack_34);
    local_c._0_1_ = 0x22;
    FUN_0046bec5((int *)&TStack_40);
    local_c._0_1_ = 0x21;
    FUN_0046bec5((int *)&TStack_2c);
    local_c._0_1_ = 0x20;
    FUN_0046bec5((int *)&TStack_28);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_24);
  }
  uVar4 = (int)DAT_004ac66c >> 0x1f;
  if ((param_6 == 1) && (0 < DAT_004a5b80)) {
    if (DAT_004a7bcc < 0x37) {
      if (-1 < (int)TStack_54.data * DAT_004aa734) {
        DAT_004a4bd8 = DAT_004a4bd8 + 1;
      }
      if (DAT_004a7bcc < 0x37) {
        DAT_004ab9c4 = DAT_004ab9c4 + 1;
      }
    }
    DAT_004ab9d4 = DAT_004ab9d4 + 1;
    if (0 < DAT_004a786c) {
      DAT_004a61f8 = 1;
      DAT_004a7754 = DAT_004a7754 + 1;
    }
    if (((DAT_004a7bcc < 0x37) && (0x4b < (int)((DAT_004ac66c ^ uVar4) - uVar4))) &&
       (700 < (int)TStack_48.data)) {
      DAT_004a620c = 2;
    }
    if (((DAT_004a7bcc < 0x37) && (0x5a < (int)((DAT_004ac66c ^ uVar4) - uVar4))) &&
       ((0 < DAT_004a5424 && (10 < DAT_004a5b80)))) {
      DAT_004a620c = 3;
    }
  }
  if (((param_6 == 1) && (0 < (int)TStack_54.data * DAT_004aa734)) &&
     ((0 < DAT_004a5b80 && (iVar8 = 0xaa - DAT_004a5f14, iVar8 <= DAT_004a7bcc)))) {
    if ((300 < (int)TStack_48.data) && (DAT_004a5f14 < (int)((DAT_004ac66c ^ uVar4) - uVar4))) {
      DAT_004a620c = 0xffffffff;
    }
    if (iVar8 <= DAT_004a7bcc) {
      if ((700 < (int)TStack_48.data) &&
         ((DAT_004a5f14 * 9) / 5 < (int)((DAT_004ac66c ^ uVar4) - uVar4))) {
        DAT_004a620c = 0xfffffffe;
      }
      if (((iVar8 <= DAT_004a7bcc) && (700 < (int)TStack_48.data)) &&
         (DAT_004a5f14 * 2 < (int)((DAT_004ac66c ^ uVar4) - uVar4))) {
        DAT_004a620c = 0xfffffffd;
      }
    }
  }
  (*pcStack_5c)(param_1,0x7f7f7f);
  iVar8 = local_58;
  if (DAT_004a763c < 700) {
    TStack_40.data = (char *)(param_2 + 1);
  }
  else {
    TStack_40.data = local_50;
  }
  if (DAT_004911a4 == 1) {
    if (DAT_004ac9dc == 0) {
      FUN_0046bf33(&TStack_48,s_Button_explanations_show_here__00491db4);
      iVar8 = local_58;
      local_c._0_1_ = 0x26;
      (*(code *)TStack_60.data)
                (param_1,(int)TStack_40.data,(DAT_004aa824 - DAT_004a72d0 / 0x32) - local_58,
                 TStack_48.data,*(int *)(TStack_48.data + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_48);
    }
    else {
      FUN_0044db20((int)param_1,local_58,param_2,(int)local_50);
    }
  }
  if (DAT_004ac92c == 0) {
    CVar1 = 0x7f;
  }
  else {
    CVar1 = 0;
  }
  (*pcStack_5c)(param_1,CVar1);
  if (*(int *)(&DAT_004a8910 + param_6 * 4) == 1) {
    if (*(int *)(&DAT_004ac1e8 + param_6 * 4) == 0) {
      FUN_0046bf33(&TStack_40,s_normal_closehauled_course_00491d98);
      TStack_24.data = (char *)(iVar8 * 3);
      local_c._0_1_ = 0x27;
      iVar5 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
      (*(code *)TStack_60.data)
                (param_1,(int)local_50,((iVar5 >> 4) - (iVar5 >> 0x1f)) + iVar8 * -3 + DAT_004aa824,
                 TStack_40.data,*(int *)(TStack_40.data + -8));
      local_c = (uint)local_c._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_40);
    }
    if (*(int *)(&DAT_004a8910 + param_6 * 4) == 1) {
      if (*(int *)(&DAT_004ac1e8 + param_6 * 4) == 5) {
        FUN_0046bf33(&TStack_40,s_closehauled___footing_00491d80);
        TStack_24.data = (char *)(iVar8 * 3);
        local_c._0_1_ = 0x28;
        iVar5 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
        (*(code *)TStack_60.data)
                  (param_1,(int)local_50,
                   ((iVar5 >> 4) - (iVar5 >> 0x1f)) + iVar8 * -3 + DAT_004aa824,TStack_40.data,
                   *(int *)(TStack_40.data + -8));
        local_c = (uint)local_c._1_3_ << 8;
        FUN_0046bec5((int *)&TStack_40);
      }
      if ((*(int *)(&DAT_004a8910 + param_6 * 4) == 1) &&
         (*(int *)(&DAT_004ac1e8 + param_6 * 4) == -5)) {
        FUN_0046bf33(&TStack_40,s_closehauled___pinching_00491d68);
        TStack_24.data = (char *)(iVar8 * 3);
        local_c._0_1_ = 0x29;
        iVar5 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
        (*(code *)TStack_60.data)
                  (param_1,(int)local_50,
                   ((iVar5 >> 4) - (iVar5 >> 0x1f)) + iVar8 * -3 + DAT_004aa824,TStack_40.data,
                   *(int *)(TStack_40.data + -8));
        local_c = (uint)local_c._1_3_ << 8;
        FUN_0046bec5((int *)&TStack_40);
      }
    }
  }
  if (*(int *)(&DAT_004a4968 + param_6 * 4) == 1) {
    FUN_0046bf33(&TStack_40,s_run___good_angle_00491d54);
    TStack_24.data = (char *)(iVar8 * 3);
    local_c._0_1_ = 0x2a;
    iVar5 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
    (*(code *)TStack_60.data)
              (param_1,(int)local_50,((iVar5 >> 4) - (iVar5 >> 0x1f)) + iVar8 * -3 + DAT_004aa824,
               TStack_40.data,*(int *)(TStack_40.data + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_40);
  }
  if (DAT_004ac92c == 0) {
    (*pcStack_5c)(param_1,0x7f0000);
  }
  if (DAT_004ac8fc == 0) {
    if ((DAT_0049116c == 1) && (DAT_004ac92c == 0)) {
      (*pcStack_5c)(param_1,0xff);
    }
    pTVar2 = FUN_00413d00(&TStack_28,DAT_0049116c);
    local_c._0_1_ = 0x2b;
    pTVar2 = FUN_0046c14f(&TStack_24,s_simulator_speed__00491d40,pTVar2);
    local_c._0_1_ = 0x2c;
    (*(code *)TStack_60.data)
              (param_1,param_2 + 10,(DAT_004aa824 - DAT_004a72d0 / 0x32) + iVar8 * -2,pTVar2->data,
               *(int *)(pTVar2->data + -8));
    local_c._0_1_ = 0x2b;
    FUN_0046bec5((int *)&TStack_24);
    pTVar2 = &TStack_28;
  }
  else {
    if (DAT_004ac92c == 0) {
      (*pcStack_5c)(param_1,0xff);
    }
    FUN_0046bf33(&TStack_40,s_movement_suspended_00491d2c);
    local_c._0_1_ = 0x2d;
    (*(code *)TStack_60.data)
              (param_1,param_2 + 10,(DAT_004aa824 - DAT_004a72d0 / 0x32) + iVar8 * -2,TStack_40.data
               ,*(int *)(TStack_40.data + -8));
    pTVar2 = &TStack_40;
  }
  local_c = (uint)local_c._1_3_ << 8;
  FUN_0046bec5((int *)pTVar2);
  if (DAT_004ac92c == 0) {
    (*pcStack_5c)(param_1,0x7f7f00);
  }
  if (0 < DAT_004a5b80) {
    TStack_24.data = (char *)FUN_00413d00(&TStack_40,DAT_004a5e84);
    local_c._0_1_ = 0x2e;
    pTVar2 = FUN_00413d00(&TStack_34,DAT_004a4be4);
    local_c._0_1_ = 0x2f;
    pTVar2 = FUN_0046c14f(&TStack_30,s_time__00491d24,pTVar2);
    local_c._0_1_ = 0x30;
    pTVar2 = FUN_0046c0db(&TStack_2c,pTVar2,&DAT_00491d20);
    local_c._0_1_ = 0x31;
    pTVar2 = FUN_0046c075(&TStack_28,pTVar2,(TactCString *)TStack_24.data);
    local_c._0_1_ = 0x32;
    (*(code *)TStack_60.data)
              (param_1,(param_2 + param_4 * 2) / 3 + -3,
               (DAT_004aa824 - DAT_004a72d0 / 0x32) + iVar8 * -2,pTVar2->data,
               *(int *)(pTVar2->data + -8));
    local_c._0_1_ = 0x31;
    FUN_0046bec5((int *)&TStack_28);
    local_c._0_1_ = 0x30;
    FUN_0046bec5((int *)&TStack_2c);
    local_c._0_1_ = 0x2f;
    FUN_0046bec5((int *)&TStack_30);
    local_c._0_1_ = 0x2e;
    FUN_0046bec5((int *)&TStack_34);
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_40);
  }
  (*pcStack_5c)(param_1,0);
  SelectObject(local_3c,local_20[0]);
  DeleteObject(local_18.data);
  TVar7.data = (char *)(DAT_004a72d0 / 0x32);
  local_18.data = TVar7.data;
  if (((DAT_004a5ba0 - DAT_004a3f04 / 0xf <= DAT_004aa824 - (int)TVar7.data) ||
      (DAT_004a4f80 <= DAT_004aa808 + -0x14)) || (DAT_004ab150 + 0x14 <= DAT_004a4f80)) {
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
    }
    TStack_40.data = (char *)((int)TVar7.data * 10);
    Rectangle(*(HDC *)(param_1 + 4),param_2,DAT_004aa824 - (int)TVar7.data,param_4,
              (int)(TStack_40.data + DAT_004aa824));
    (*local_44)(param_1,0x7f7f7f);
    if (DAT_004a763c < 0x385) {
      iVar8 = param_2 - param_4;
      iVar5 = param_2 - ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2);
      local_50 = (LPCSTR)(iVar5 + 0xc);
      iVar8 = param_2 - iVar8 / 3;
      TStack_48.data = (char *)(iVar8 + 0xc);
    }
    else if (DAT_004a5264 < 0x15) {
      iVar8 = param_2 - param_4;
      iVar5 = param_2 - ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2);
      local_50 = (LPCSTR)(iVar5 + 0x1e);
      iVar8 = param_2 - iVar8 / 3;
      TStack_48.data = (char *)(iVar8 + 0x1e);
    }
    else {
      iVar8 = param_2 - param_4;
      iVar5 = param_2 - ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2);
      local_50 = (LPCSTR)(iVar5 + 0x10);
      iVar8 = param_2 - iVar8 / 3;
      TStack_48.data = (char *)(iVar8 + 0x10);
    }
    if (DAT_004a763c < 700) {
      local_50 = (LPCSTR)(iVar5 + -1);
      TStack_48.data = (char *)(iVar8 + -1);
    }
    if ((DAT_004ac9c8 == 0) || (*(int *)(&DAT_004a4e88 + param_6 * 4) == 3)) {
      FUN_0046bf33(&local_3c,s_Steering_Zone_00491d10);
      local_c._0_1_ = 0x33;
      (*(code *)TStack_60.data)
                (param_1,(int)local_50,(DAT_004aa824 - (int)TVar7.data) + 2,(LPCSTR)local_3c,
                 local_3c[-2].unused);
    }
    else {
      FUN_0046bf33(&local_3c,s_Steering_Zone_00491d10);
      local_c._0_1_ = 0x34;
      (*(code *)TStack_60.data)
                (param_1,(int)TStack_48.data,(DAT_004aa824 - (int)TVar7.data) + 2,(LPCSTR)local_3c,
                 local_3c[-2].unused);
    }
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&local_3c);
    (*local_44)(param_1,0xffffff);
    goto LAB_0040d995;
  }
  if (DAT_004ac92c == 0) {
    if (DAT_004a469c != (HGDIOBJ)0x0) {
      hdc = *(HDC *)(param_1 + 4);
      h = DAT_004a469c;
LAB_0040d7a5:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004aa7f4;
    goto LAB_0040d7a5;
  }
  TStack_40.data = (char *)((int)TVar7.data * 10);
  Rectangle(*(HDC *)(param_1 + 4),param_2,DAT_004aa824 - (int)TVar7.data,param_4,
            (int)(TStack_40.data + DAT_004aa824));
LAB_0040d995:
  (*local_38)(param_1,7);
  FUN_004706bd(param_1,(int *)local_20,DAT_004a70ec,DAT_004aa824 - (int)TVar7.data);
  CDC::LineTo(param_1,DAT_004a70ec,(int)(TStack_40.data + DAT_004aa824));
  if (0 < DAT_004ac9c4) {
    local_38 = (code *)0xbb8;
    TStack_48.data = (LPCSTR)0x2;
    if (1 < DAT_0049118c) {
      iVar8 = 0;
      do {
        FUN_0042c400(*(double *)((int)&DAT_004a49f8 + iVar8),*(double *)((int)&DAT_004a4af0 + iVar8)
                     ,1,1);
        if ((int)(code *)(longlong)_DAT_004a6828 < (int)local_38) {
          local_20[0] = TStack_48.data;
          local_38 = (code *)(longlong)_DAT_004a6828;
        }
        TStack_48.data = TStack_48.data + 1;
        iVar8 = iVar8 + 8;
        TVar7.data = local_18.data;
      } while ((int)TStack_48.data <= DAT_0049118c);
    }
    pTVar2 = FUN_00413d90(&local_18,
                          *(double *)(&DAT_004a71c8 + (int)local_20[0] * 8) * _DAT_00484d48);
    local_c._0_1_ = 0x35;
    FUN_0046bfbe(&local_4c,(int *)pTVar2);
    local_c._0_1_ = 0;
    FUN_0046bec5((int *)&local_18);
    (*local_44)(param_1,0x7f7f7f);
    pTVar2 = FUN_0046c14f(&local_18,s_nearest__00491d04,&local_4c);
    local_c._0_1_ = 0x36;
    (*(code *)TStack_60.data)
              (param_1,param_2 - ((int)((param_2 - param_4) + (param_2 - param_4 >> 0x1f & 3U)) >> 2
                                 ),(local_58 - (int)TVar7.data) + 2 + DAT_004aa824,pTVar2->data,
               *(int *)(pTVar2->data + -8));
    local_c = (uint)local_c._1_3_ << 8;
    FUN_0046bec5((int *)&local_18);
  }
  (*local_44)(param_1,0xffffff);
  local_c = 0xffffffff;
  FUN_0046bec5((int *)&local_4c);
  *unaff_FS_OFFSET = uStack_14;
  return;
}


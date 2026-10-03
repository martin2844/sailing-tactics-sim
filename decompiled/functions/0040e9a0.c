
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040e9a0(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  HDC hdc;
  int iVar2;
  code *pcVar3;
  float10 fVar4;
  int iVar5;
  COLORREF CVar6;
  TactCString *pTVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar9;
  TactCString local_30;
  code *pcStack_2c;
  TactCString TStack_28;
  TactCString TStack_24;
  TactCString TStack_20;
  TactCString local_1c;
  HGDIOBJ local_18;
  HDC local_14;
  HRGN local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047ddc8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  hdc = *(HDC *)(param_1 + 4);
  local_14 = hdc;
  local_10 = CreateRectRgn(param_2,param_3,param_4,param_5);
  local_18 = SelectObject(hdc,local_10);
  FUN_0046bd7a(&local_30);
  iVar5 = DAT_004a72d0 / 0x1f;
  local_4 = 0;
  DAT_004aa7e0 = FUN_0042d0c0(param_6);
  fVar9 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + DAT_004aa7e0 * 8),
                                        *(undefined4 *)(&DAT_004a52f0 + DAT_004aa7e0 * 8)),
                       (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + DAT_004aa7e0 * 8),
                                        *(undefined4 *)(&DAT_004a60b0 + DAT_004aa7e0 * 8)),0,param_6
                      );
  fVar4 = (float10)_DAT_00484d78;
  *(int *)(&DAT_004aa6e0 + param_6 * 4) = (int)(longlong)(_DAT_004a6828 * _DAT_00484d70);
  DAT_004ac66c = FUN_00415dc0((int)(longlong)(fVar9 * fVar4) - *(int *)(&DAT_004ac018 + param_6 * 4)
                             );
  local_1c.data = (char *)(longlong)_DAT_004a6828;
  iVar2 = *(int *)param_1;
  pcVar3 = *(code **)(iVar2 + 0x2c);
  (*pcVar3)(param_1,7);
  (*pcVar3)(param_1,0);
  Rectangle(*(HDC *)(param_1 + 4),param_2,param_3,param_4,param_5);
  (**(code **)(iVar2 + 0x34))(param_1,0xffffff);
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar2 + 0x38))(param_1,0xff);
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar2 + 0x38))(param_1,0x7f0000);
    }
  }
  pTVar7 = FUN_00413d90(&TStack_24,*(double *)(&DAT_004a71c8 + param_6 * 8) * _DAT_00484d48);
  local_4._0_1_ = 1;
  FUN_0046bfbe(&local_30,(int *)pTVar7);
  local_4._0_1_ = 0;
  FUN_0046bec5((int *)&TStack_24);
  FUN_0046bf33(&TStack_28,s_speed__00491e80);
  pcVar3 = *(code **)(iVar2 + 100);
  local_4._0_1_ = 2;
  iVar1 = param_2 + 1;
  (*pcVar3)(param_1,iVar1,param_3 + 1,TStack_28.data,*(int *)(TStack_28.data + -8));
  local_4._0_1_ = 0;
  FUN_0046bec5((int *)&TStack_28);
  iVar8 = param_3 + 1 + iVar5;
  pTVar7 = FUN_0046c14f(&TStack_24,&DAT_004911f0,&local_30);
  local_4._0_1_ = 3;
  (*pcVar3)(param_1,iVar1,iVar8,pTVar7->data,*(int *)(pTVar7->data + -8));
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5((int *)&TStack_24);
  iVar8 = iVar8 + iVar5;
  if (*(double *)(&DAT_004a7f28 + param_6 * 8) <= _DAT_00484d80) {
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar2 + 0x38))(param_1,0xff);
    }
    pTVar7 = FUN_00413d00(&TStack_28,(int)(longlong)*(double *)(&DAT_004a7f28 + param_6 * 8));
    local_4._0_1_ = 8;
    pTVar7 = FUN_0046c14f(&TStack_24,s_depth__00491e1c,pTVar7);
    local_4._0_1_ = 9;
    (*pcVar3)(param_1,iVar1,iVar8,pTVar7->data,*(int *)(pTVar7->data + -8));
    local_4._0_1_ = 8;
    FUN_0046bec5((int *)&TStack_24);
    local_4._0_1_ = 0;
    FUN_0046bec5((int *)&TStack_28);
    if (((*(double *)(&DAT_004a7f28 + param_6 * 8) < _DAT_00484d80) &&
        (_DAT_00484d80 < *(double *)(&DAT_004a4510 + param_6 * 8))) && (DAT_004ac9c0 == 0)) {
      MessageBeep(0);
    }
  }
  else {
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar2 + 0x38))(param_1,0xff0000);
    }
    FUN_0046bf33(&TStack_28,s_sail__0049219c);
    local_4._0_1_ = 4;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
    local_4._0_1_ = 0;
    FUN_0046bec5((int *)&TStack_28);
    iVar8 = iVar8 + iVar5;
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 1) {
      FUN_0046bf33(&TStack_28,s_flat_00492194);
      local_4._0_1_ = 5;
      (*pcVar3)(param_1,iVar1,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
      local_4._0_1_ = 0;
      FUN_0046bec5((int *)&TStack_28);
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 2) {
      FUN_0046bf33(&TStack_28,s_medium_0049218c);
      local_4._0_1_ = 6;
      (*pcVar3)(param_1,iVar1,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
      local_4._0_1_ = 0;
      FUN_0046bec5((int *)&TStack_28);
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 3) {
      FUN_0046bf33(&TStack_28,s_baggy_00492184);
      local_4._0_1_ = 7;
      (*pcVar3)(param_1,iVar1,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
      local_4._0_1_ = 0;
      FUN_0046bec5((int *)&TStack_28);
    }
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar2 + 0x38))(param_1,0x7f0000);
  }
  pTVar7 = FUN_00413d00(&TStack_24,*(int *)(&DAT_004a8aa8 + param_6 * 4));
  local_4._0_1_ = 10;
  FUN_0046bfbe(&local_30,(int *)pTVar7);
  local_4._0_1_ = 0;
  FUN_0046bec5((int *)&TStack_24);
  FUN_0046bf33(&TStack_28,s_luffing__00492178);
  local_4._0_1_ = 0xb;
  (*pcVar3)(param_1,iVar1,iVar8 + iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
  local_4._0_1_ = 0;
  FUN_0046bec5((int *)&TStack_28);
  iVar8 = iVar8 + iVar5 + iVar5;
  pTVar7 = FUN_0046c14f(&TStack_28,&DAT_004911f0,&local_30);
  local_4._0_1_ = 0xc;
  pTVar7 = FUN_0046c0db(&TStack_24,pTVar7,&DAT_00491e4c);
  local_4._0_1_ = 0xd;
  (*pcVar3)(param_1,iVar1,iVar8,pTVar7->data,*(int *)(pTVar7->data + -8));
  local_4._0_1_ = 0xc;
  FUN_0046bec5((int *)&TStack_24);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5((int *)&TStack_28);
  iVar8 = iVar8 + iVar5;
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar2 + 0x38))(param_1,0x7f00);
  }
  if (*(int *)(&DAT_004a7868 + param_6 * 4) == 0) {
    FUN_0046bf33(&TStack_28,s_air_ok_00492170);
    local_4._0_1_ = 0xe;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_28);
  }
  else if (DAT_004ac92c == 0) {
    (**(code **)(iVar2 + 0x38))(param_1,0xff);
  }
  if ((*(int *)(&DAT_004a7868 + param_6 * 4) == 2) || (*(int *)(&DAT_004a7868 + param_6 * 4) == 0xc)
     ) {
    FUN_0046bf33(&TStack_28,s_blankt_00492168);
    local_4._0_1_ = 0xf;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_28);
  }
  if (*(int *)(&DAT_004a7868 + param_6 * 4) == 3) {
    FUN_0046bf33(&TStack_28,s_bckwnd_00492160);
    local_4._0_1_ = 0x10;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_28);
  }
  iVar8 = iVar8 + iVar5;
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar2 + 0x38))(param_1,0x7f0000);
  }
  pcStack_2c = (code *)FUN_00413cb0(*(int *)(&DAT_004aa5b0 + param_6 * 4) - DAT_004a4f8c);
  if (0xb4 < (int)pcStack_2c) {
    pcStack_2c = (code *)((int)pcStack_2c - 0x168);
  }
  TStack_28.data =
       (char *)(((uint)pcStack_2c ^ (int)pcStack_2c >> 0x1f) - ((int)pcStack_2c >> 0x1f));
  DAT_004ac964 = (uint)(0x28 < (int)TStack_28.data);
  if ((DAT_004ac978 == 0) && (DAT_004ac964 == 0)) {
    if (0 < (int)pcStack_2c * *(int *)(&DAT_004aa730 + param_6 * 4)) {
      pTVar7 = FUN_00413d00(&TStack_20,(int)TStack_28.data);
      local_4._0_1_ = 0x11;
      pTVar7 = FUN_0046c14f(&TStack_24,s_lift_00492158,pTVar7);
      local_4._0_1_ = 0x12;
      (*pcVar3)(param_1,iVar1,iVar8,pTVar7->data,*(int *)(pTVar7->data + -8));
      local_4._0_1_ = 0x11;
      FUN_0046bec5((int *)&TStack_24);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_20);
    }
    if (pcStack_2c == (code *)0x0) {
      FUN_0046bf33(&TStack_24,s_wnd_av_00492150);
      local_4._0_1_ = 0x13;
      (*pcVar3)(param_1,iVar1,iVar8,TStack_24.data,*(int *)(TStack_24.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_24);
    }
    if ((int)pcStack_2c * *(int *)(&DAT_004aa730 + param_6 * 4) < 0) {
      if (DAT_004ac978 == 0) {
        pTVar7 = FUN_00413d00(&TStack_24,(int)TStack_28.data);
        local_4._0_1_ = 0x14;
        pTVar7 = FUN_0046c14f(&TStack_20,s_head_00492148,pTVar7);
        local_4._0_1_ = 0x15;
        (*pcVar3)(param_1,iVar1,iVar8,pTVar7->data,*(int *)(pTVar7->data + -8));
        local_4._0_1_ = 0x14;
        FUN_0046bec5((int *)&TStack_20);
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_0046bec5((int *)&TStack_24);
      }
      if ((((DAT_004a7bcc < 0x37) &&
           (0x2d < (int)((DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f))))
          && (10 < (int)TStack_28.data)) && ((300 < (int)local_1c.data && (param_6 == 1)))) {
        DAT_004a620c = 1;
      }
    }
  }
  iVar8 = iVar8 + 2 + iVar5;
  pcStack_2c = *(code **)(iVar2 + 0x38);
  (*pcStack_2c)(param_1,0xff0000);
  if ((*(int *)(&DAT_004a8910 + param_6 * 4) == 1) && (*(int *)(&DAT_004ac1e8 + param_6 * 4) == 0))
  {
    FUN_0046bf33(&TStack_24,s_closehauled_0049213c);
    local_4._0_1_ = 0x16;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_24.data,*(int *)(TStack_24.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_24);
  }
  if ((*(int *)(&DAT_004a8910 + param_6 * 4) == 1) && (*(int *)(&DAT_004ac1e8 + param_6 * 4) == 5))
  {
    FUN_0046bf33(&TStack_24,s_footing_00492134);
    local_4._0_1_ = 0x17;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_24.data,*(int *)(TStack_24.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_24);
  }
  if ((*(int *)(&DAT_004a8910 + param_6 * 4) == 1) && (*(int *)(&DAT_004ac1e8 + param_6 * 4) == -5))
  {
    FUN_0046bf33(&TStack_24,s_pinching_00492128);
    local_4._0_1_ = 0x18;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_24.data,*(int *)(TStack_24.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_24);
  }
  if (*(int *)(&DAT_004a4968 + param_6 * 4) == 1) {
    FUN_0046bf33(&TStack_24,s_running_00492120);
    local_4._0_1_ = 0x19;
    (*pcVar3)(param_1,iVar1,iVar8,TStack_24.data,*(int *)(TStack_24.data + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&TStack_24);
  }
  iVar8 = iVar8 + iVar5;
  if (0 < DAT_004a5b80) {
    if (DAT_004ac92c == 0) {
      if ((DAT_004aa7e0 == 3) || (DAT_004aa7e0 == 5)) {
        CVar6 = 0x7f;
      }
      else {
        CVar6 = 0x7f7f;
      }
      (*pcStack_2c)(param_1,CVar6);
      if (DAT_004aa7e0 == 2) {
        (*pcStack_2c)(param_1,0x7f7f);
      }
    }
    if (0 < (int)DAT_004ac66c) {
      pTVar7 = FUN_00413d00(&TStack_24,DAT_004ac66c);
      local_4._0_1_ = 0x1a;
      pTVar7 = FUN_0046c14f(&TStack_20,s_mark__00492118,pTVar7);
      local_4._0_1_ = 0x1b;
      pTVar7 = FUN_0046c0db(&local_1c,pTVar7,s_to_S_00492110);
      local_4._0_1_ = 0x1c;
      (*pcVar3)(param_1,iVar1,iVar8,pTVar7->data,*(int *)(pTVar7->data + -8));
      local_4._0_1_ = 0x1b;
      FUN_0046bec5((int *)&local_1c);
      local_4._0_1_ = 0x1a;
      FUN_0046bec5((int *)&TStack_20);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_24);
    }
    if ((int)DAT_004ac66c < 0) {
      pTVar7 = FUN_00413d00(&TStack_24,
                            (DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f)
                           );
      local_4._0_1_ = 0x1d;
      pTVar7 = FUN_0046c14f(&TStack_20,s_mark__00492118,pTVar7);
      local_4._0_1_ = 0x1e;
      pTVar7 = FUN_0046c0db(&local_1c,pTVar7,s_to_P_00492108);
      local_4._0_1_ = 0x1f;
      (*pcVar3)(param_1,iVar1,iVar8,pTVar7->data,*(int *)(pTVar7->data + -8));
      local_4._0_1_ = 0x1e;
      FUN_0046bec5((int *)&local_1c);
      local_4._0_1_ = 0x1d;
      FUN_0046bec5((int *)&TStack_20);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_24);
    }
    if (DAT_004ac66c == 0) {
      FUN_0046bf33(&TStack_24,s_mark__ahead_004920fc);
      local_4._0_1_ = 0x20;
      (*pcVar3)(param_1,iVar1,iVar8,TStack_24.data,*(int *)(TStack_24.data + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&TStack_24);
    }
  }
  if (param_6 == 1) {
    FUN_00409760((int)param_1,param_2,param_3,param_4,param_5,1,iVar5);
  }
  else {
    FUN_0040b990((int)param_1,param_2,param_3,param_4,param_5,param_6,iVar5);
  }
  (*pcStack_2c)(param_1,0);
  SelectObject(local_14,local_18);
  DeleteObject(local_10);
  local_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_30);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


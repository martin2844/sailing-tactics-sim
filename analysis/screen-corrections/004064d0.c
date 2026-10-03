
void __cdecl FUN_004064d0(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  TactCString *pTVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uStack_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d3d0;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = param_2 + param_4;
  FUN_0046bf33(&param_2,s___Motivation_Factors_for_Jibing___0049147c);
  local_4 = 0;
  iVar3 = param_3 + 5;
  pcVar1 = *(code **)(*param_1 + 100);
  (*pcVar1)(param_1,iVar3,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
  local_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  iVar4 = iVar4 + param_4 / 2;
  if (DAT_004a67d4 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67d4);
    local_4 = 1;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Jibe_for_clear_air__00491464,pTVar2);
    local_4._0_1_ = 2;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67d8 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67d8);
    local_4 = 3;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Don_t_jibe_into_bad_air__00491448,pTVar2);
    local_4._0_1_ = 4;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,3);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67dc != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67dc);
    local_4 = 5;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Jibe_for_more_wind__00491430,pTVar2);
    local_4._0_1_ = 6;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,5);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67e0 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67e0);
    local_4 = 7;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Go_for_more_wind__0049141c,pTVar2);
    local_4._0_1_ = 8;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,7);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67e4 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67e4);
    local_4 = 9;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Jibe_for_headed_tack__00491404,pTVar2);
    local_4._0_1_ = 10;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,9);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67e8 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67e8);
    local_4 = 0xb;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Stay_on_headed_tack__004913ec,pTVar2);
    local_4._0_1_ = 0xc;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0xb);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67ec != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67ec);
    local_4 = 0xd;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Persistant_shift_expected__004913d0,pTVar2);
    local_4._0_1_ = 0xe;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0xd);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67f0 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67f0);
    local_4 = 0xf;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Persistant_shift_expected__004913d0,pTVar2);
    local_4._0_1_ = 0x10;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0xf);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67f4 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67f4);
    local_4 = 0x11;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Avoid_Jibe__Near_layline__004913b4,pTVar2);
    local_4._0_1_ = 0x12;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x11);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67f8 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67f8);
    local_4 = 0x13;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Approaching_layline__0049139c,pTVar2);
    local_4._0_1_ = 0x14;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x13);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a67fc != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a67fc);
    local_4 = 0x15;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Favor_rhumbline_when_ahead__0049137c,pTVar2);
    local_4._0_1_ = 0x16;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x15);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a6800 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a6800);
    local_4 = 0x17;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Try_for_inside_position__00491360,pTVar2);
    local_4._0_1_ = 0x18;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x17);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004a6804 == 1) {
    iVar4 = iVar4 + param_4;
    FUN_0046bf33(&param_2,s_Sail_high__Don_t_jibe__00491348);
    local_4 = 0x19;
    (*pcVar1)(param_1,iVar3,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_2);
  }
  if (0 < DAT_004a6808) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a6808);
    local_4 = 0x1a;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Blanket__Don_t_jibe_00491334,pTVar2);
    local_4._0_1_ = 0x1b;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x1a);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (0 < DAT_004a680c) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a680c);
    local_4 = 0x1c;
    pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Blanket__Jibe_00491324,pTVar2);
    local_4._0_1_ = 0x1d;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x1c);
    FUN_0046bec5(&param_2);
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_3);
  }
  if (DAT_004ac9ac == 1) {
    if (DAT_004a6810 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a6810);
      local_4 = 0x1e;
      pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Jibe_for_more_better_tide__00491308,pTVar2);
      local_4._0_1_ = 0x1f;
      (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1e);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a6814 != 0) {
      pTVar2 = FUN_00413d00((TactCString *)&param_3,DAT_004a6814);
      local_4 = 0x20;
      pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_Go_for_better_tide__004912f0,pTVar2);
      local_4._0_1_ = 0x21;
      (*pcVar1)(param_1,iVar3,param_4 + iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x20);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
  }
  pTVar2 = FUN_00413d00((TactCString *)&param_2,DAT_004a681c);
  local_4 = 0x22;
  pTVar2 = FUN_0046c14f((TactCString *)&param_4,s_Total_motivation_points__004912d4,pTVar2);
  local_4._0_1_ = 0x23;
  (*pcVar1)(param_1,iVar3,(DAT_004a72d0 * 6) / 7,pTVar2->data,*(int *)(pTVar2->data + -8));
  local_4 = CONCAT31(local_4._1_3_,0x22);
  FUN_0046bec5(&param_4);
  local_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  puVar5 = &DAT_004a67d0;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


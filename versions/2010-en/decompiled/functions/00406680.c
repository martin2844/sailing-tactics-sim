
void __cdecl FUN_00406680(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  Tact2010CString *pTVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uStack_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c1a80;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = param_2 + param_4;
  FUN_004b0613((Tact2010CString *)&param_2,s___Motivation_Factors_for_Jibing___004da468);
  local_4 = 0;
  iVar3 = param_3 + 5;
  pcVar1 = *(code **)(*param_1 + 100);
  (*pcVar1)(param_1,iVar3,iVar4,(char *)param_2,*(int *)(param_2 + -8));
  local_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
  iVar4 = iVar4 + param_4 / 2;
  if (DAT_004fbadc != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbadc);
    local_4 = 1;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Jibe_for_clear_air__004da450,pTVar2);
    local_4._0_1_ = 2;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbae0 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbae0);
    local_4 = 3;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Don_t_jibe_into_bad_air__004da434,pTVar2);
    local_4._0_1_ = 4;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,3);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbae4 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbae4);
    local_4 = 5;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Jibe_for_more_wind__004da41c,pTVar2);
    local_4._0_1_ = 6;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,5);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbae8 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbae8);
    local_4 = 7;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Go_for_more_wind__004da408,pTVar2);
    local_4._0_1_ = 8;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,7);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbaec != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbaec);
    local_4 = 9;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Jibe_for_headed_tack__004da3f0,pTVar2);
    local_4._0_1_ = 10;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,9);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbaf0 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbaf0);
    local_4 = 0xb;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Stay_on_headed_tack__004da3d8,pTVar2);
    local_4._0_1_ = 0xc;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0xb);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbaf4 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbaf4);
    local_4 = 0xd;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Persistant_shift_expected__004da3bc,pTVar2);
    local_4._0_1_ = 0xe;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0xd);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbaf8 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbaf8);
    local_4 = 0xf;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Persistant_shift_expected__004da3bc,pTVar2);
    local_4._0_1_ = 0x10;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0xf);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbafc != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbafc);
    local_4 = 0x11;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Avoid_Jibe__Near_layline__004da3a0,pTVar2);
    local_4._0_1_ = 0x12;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x11);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbb00 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbb00);
    local_4 = 0x13;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Approaching_layline__004da388,pTVar2);
    local_4._0_1_ = 0x14;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x13);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbb04 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbb04);
    local_4 = 0x15;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Favor_rhumbline_when_ahead__004da368,pTVar2)
    ;
    local_4._0_1_ = 0x16;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x15);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbb08 != 0) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbb08);
    local_4 = 0x17;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Try_for_inside_position__004da34c,pTVar2);
    local_4._0_1_ = 0x18;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x17);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_004fbb0c == 1) {
    iVar4 = iVar4 + param_4;
    FUN_004b0613((Tact2010CString *)&param_2,s_Sail_high__Don_t_jibe__004da334);
    local_4 = 0x19;
    (*pcVar1)(param_1,iVar3,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if (0 < DAT_004fbb10) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbb10);
    local_4 = 0x1a;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Blanket__Don_t_jibe_004da320,pTVar2);
    local_4._0_1_ = 0x1b;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x1a);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (0 < DAT_004fbb14) {
    iVar4 = iVar4 + param_4;
    pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbb14);
    local_4 = 0x1c;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Blanket__Jibe_004da310,pTVar2);
    local_4._0_1_ = 0x1d;
    (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x1c);
    FUN_004b05a5((Tact2010CString *)&param_2);
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  if (DAT_00536470 == 1) {
    if (DAT_004fbb18 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbb18);
      local_4 = 0x1e;
      pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Jibe_for_more_better_tide__004da2f4,pTVar2
                           );
      local_4._0_1_ = 0x1f;
      (*pcVar1)(param_1,iVar3,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1e);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004fbb1c != 0) {
      pTVar2 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004fbb1c);
      local_4 = 0x20;
      pTVar2 = FUN_004b082f((Tact2010CString *)&param_2,s_Go_for_better_tide__004da2dc,pTVar2);
      local_4._0_1_ = 0x21;
      (*pcVar1)(param_1,iVar3,param_4 + iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x20);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
  }
  pTVar2 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_004fbb24);
  local_4 = 0x22;
  pTVar2 = FUN_004b082f((Tact2010CString *)&param_4,s_Total_motivation_points__004da2c0,pTVar2);
  local_4._0_1_ = 0x23;
  (*pcVar1)(param_1,iVar3,(DAT_004fe2a8 * 6) / 7,pTVar2->data,*(int *)(pTVar2->data + -8));
  local_4 = CONCAT31(local_4._1_3_,0x22);
  FUN_004b05a5((Tact2010CString *)&param_4);
  local_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
  puVar5 = &DAT_004fbad8;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


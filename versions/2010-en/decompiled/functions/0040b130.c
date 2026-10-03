
void __cdecl FUN_0040b130(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  Tact2010CString *pTVar3;
  code *pcVar4;
  undefined4 *unaff_FS_OFFSET;
  int iVar5;
  int iStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c1fb0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_004b4a1f(param_1,1);
  iVar2 = *original_dc;
  pcVar1 = *(code **)(iVar2 + 0x2c);
  (*pcVar1)(original_dc,4);
  (*pcVar1)(original_dc,6);
  Rectangle((HDC)original_dc[1],param_2,param_3,param_4,param_3 + 0x28);
  pcVar1 = *(code **)(iVar2 + 0x34);
  (*pcVar1)(original_dc,0);
  param_1 = *(int **)(iVar2 + 0x38);
  if (DAT_005363e4 == 0) {
    iVar5 = 0xff;
  }
  else {
    iVar5 = 0xffffff;
  }
  (*(code *)param_1)(original_dc,iVar5);
  if (0 < DAT_005363f4) {
    FUN_004b0613((Tact2010CString *)&param_3,s_Race_tracks__black_in_bad_air__d_004dac04);
    pcVar1 = *(code **)(iVar2 + 100);
    uStack_4 = 0;
    (*pcVar1)(original_dc,1,1,(char *)param_3,*(int *)(param_3 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
    (*(code *)param_1)(original_dc,0x7f);
    FUN_004b0613((Tact2010CString *)&param_1,s_Note__The_committee_boat_moved_a_004dabbc);
    uStack_4 = 1;
    (*pcVar1)(original_dc,1,0x10,(char *)param_1,param_1[-2]);
    goto LAB_0040b907;
  }
  if (DAT_0053646c == 1) {
    FUN_004b0613((Tact2010CString *)&param_3,s___Race_Course___Marks_to_Starboa_004dab94);
    pcVar4 = *(code **)(iVar2 + 100);
    uStack_4 = 2;
    (*pcVar4)(original_dc,1,1,(char *)param_3,*(int *)(param_3 + -8));
  }
  else {
    FUN_004b0613((Tact2010CString *)&param_3,s___RACE_COURSE___marks_to_PORT_004dab70);
    pcVar4 = *(code **)(iVar2 + 100);
    uStack_4 = 3;
    (*pcVar4)(original_dc,1,1,(char *)param_3,*(int *)(param_3 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_3);
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0xffff);
  }
  if (DAT_004da1e8 == 1) {
    DAT_004f452c = 1;
    if (DAT_004da188 == 1) {
      DAT_004f452c = (uint)(0x14 < DAT_004f8cd0);
    }
    if (DAT_004da188 == 2) {
      DAT_004f452c = 1;
    }
    if (DAT_004da188 == 5) {
      DAT_004f452c = (uint)(4 < DAT_004da1cc);
    }
    if (((DAT_004da188 == 6) || (DAT_004da188 == 3)) || (DAT_004da188 == 4)) {
      DAT_004f452c = 0;
    }
    if (DAT_004da188 == 7) {
      if (((DAT_004f853c < 2) || (7 < DAT_004f853c)) && ((DAT_004fe2b4 == 0 && (DAT_00536408 == 1)))
         ) {
        DAT_004f452c = 0;
      }
      if ((1 < DAT_004f853c) && (0 < DAT_004fe2b4)) {
        DAT_004f452c = 0;
      }
    }
    (*(code *)param_1)(original_dc,0x7fff);
    if (DAT_004da188 == 1) {
      FUN_004b0613((Tact2010CString *)&param_3,s_On_the_run__pass_thru_the_gate_a_004dab38);
      uStack_4 = 4;
      (*pcVar4)(original_dc,DAT_004fe624 / 3,1,(char *)param_3,*(int *)(param_3 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004da188 == 2) {
      FUN_004b0613((Tact2010CString *)&param_3,s_On_the_runs__pass_thru_the_gate_a_004dab00);
      uStack_4 = 5;
      (*pcVar4)(original_dc,DAT_004fe624 / 3,1,(char *)param_3,*(int *)(param_3 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_0053527c == 1) {
      FUN_004b0613((Tact2010CString *)&param_3,s_On_the_first_run__pass_thru_the_g_004daac4);
      uStack_4 = 6;
      (*pcVar4)(original_dc,DAT_004fe624 / 3,1,(char *)param_3,*(int *)(param_3 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_005363f8 == 1) {
      FUN_004b0613((Tact2010CString *)&param_3,s_On_the_run_after_the_second_beat_004daa78);
      uStack_4 = 7;
      (*pcVar4)(original_dc,DAT_004fe624 / 3,1,(char *)param_3,*(int *)(param_3 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    (*(code *)param_1)(original_dc,0xffff);
  }
  else {
    DAT_004f452c = 0;
  }
  iStack_1c = DAT_00535208;
  if (DAT_004da1f8 == 5) {
    iStack_1c = FUN_00427ee0(DAT_005229d4 - DAT_00536410,DAT_00536414 - DAT_00522ac8);
  }
  iVar2 = FUN_00427ee0(DAT_00522acc - DAT_005229d4,DAT_00522ac8 - DAT_00522ae0);
  if ((DAT_004da168 == 0) || (iVar5 = DAT_00535208, 0xe < DAT_004da194)) {
    iVar5 = FUN_00427ee0(DAT_005229c8 - DAT_00522acc,DAT_00522ae0 - DAT_00522ac4);
  }
  pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,iStack_1c);
  uStack_4 = 8;
  pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_1st_leg__004daa6c,pTVar3);
  uStack_4._0_1_ = 9;
  pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,&DAT_004daa64);
  uStack_4._0_1_ = 10;
  (*pcVar4)(original_dc,1,DAT_004fe2a8 / 0x1e,pTVar3->data,*(int *)(pTVar3->data + -8));
  uStack_4._0_1_ = 9;
  FUN_004b05a5((Tact2010CString *)&param_3);
  uStack_4 = CONCAT31(uStack_4._1_3_,8);
  FUN_004b05a5((Tact2010CString *)&param_4);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
  pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,iVar2);
  uStack_4 = 0xb;
  pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_2nd_leg__004daa58,pTVar3);
  uStack_4._0_1_ = 0xc;
  pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,&DAT_004daa64);
  uStack_4._0_1_ = 0xd;
  (*pcVar4)(original_dc,0xa0,DAT_004fe2a8 / 0x1e,pTVar3->data,*(int *)(pTVar3->data + -8));
  uStack_4._0_1_ = 0xc;
  FUN_004b05a5((Tact2010CString *)&param_3);
  uStack_4 = CONCAT31(uStack_4._1_3_,0xb);
  FUN_004b05a5((Tact2010CString *)&param_4);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
  pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,iVar5);
  uStack_4 = 0xe;
  pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_3rd_leg__004daa4c,pTVar3);
  uStack_4._0_1_ = 0xf;
  pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,&DAT_004daa64);
  uStack_4._0_1_ = 0x10;
  (*pcVar4)(original_dc,0x140,DAT_004fe2a8 / 0x1e,pTVar3->data,*(int *)(pTVar3->data + -8));
  uStack_4._0_1_ = 0xf;
  FUN_004b05a5((Tact2010CString *)&param_3);
  uStack_4 = CONCAT31(uStack_4._1_3_,0xe);
  FUN_004b05a5((Tact2010CString *)&param_4);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
  if (DAT_004da1f8 == 5) {
LAB_0040b7e0:
    iVar2 = FUN_00427ee0(DAT_00536410 - DAT_005229c8,DAT_00522ac4 - DAT_00536414);
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,iVar2);
    uStack_4 = 0x14;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_4th_leg__004daa40,pTVar3);
    uStack_4._0_1_ = 0x15;
    pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,&DAT_004daa64);
    uStack_4._0_1_ = 0x16;
    (*pcVar4)(original_dc,0x1e0,DAT_004fe2a8 / 0x1e,pTVar3->data,*(int *)(pTVar3->data + -8));
    uStack_4._0_1_ = 0x15;
    FUN_004b05a5((Tact2010CString *)&param_3);
    uStack_4 = CONCAT31(uStack_4._1_3_,0x14);
    FUN_004b05a5((Tact2010CString *)&param_4);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  else {
    if ((DAT_004da168 == 0) || (0xe < DAT_004da194)) {
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_00535208);
      uStack_4 = 0x11;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_4th_leg__004daa40,pTVar3);
      uStack_4._0_1_ = 0x12;
      pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,&DAT_004daa64);
      uStack_4._0_1_ = 0x13;
      (*pcVar4)(original_dc,0x1e0,DAT_004fe2a8 / 0x1e,pTVar3->data,*(int *)(pTVar3->data + -8));
      uStack_4._0_1_ = 0x12;
      FUN_004b05a5((Tact2010CString *)&param_3);
      uStack_4 = CONCAT31(uStack_4._1_3_,0x11);
      FUN_004b05a5((Tact2010CString *)&param_4);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004da1f8 == 5) goto LAB_0040b7e0;
  }
  FUN_004b4a1f(original_dc,2);
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f);
    (*pcVar1)(original_dc,0xffffff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Movement_suspended__Click_mouse_o_004da994);
  uStack_4 = 0x17;
  (*pcVar4)(original_dc,1,(DAT_004fe2a8 - DAT_004fe2a8 / 10) + -5,(char *)param_1,param_1[-2]);
LAB_0040b907:
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


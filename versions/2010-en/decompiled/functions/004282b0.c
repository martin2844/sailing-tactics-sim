
void __cdecl FUN_004282b0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  Tact2010CString *pTVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString local_e0;
  Tact2010CString TStack_dc;
  int local_d8;
  int local_d4;
  Tact2010CString local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  Tact2010CString TStack_c0;
  int local_bc;
  Tact2010CString TStack_b8;
  char *pcStack_b4;
  char *pcStack_b0;
  Tact2010CString TStack_ac;
  Tact2010CString TStack_a8;
  Tact2010CString TStack_a4;
  Tact2010CString TStack_a0;
  Tact2010CString TStack_9c;
  int aiStack_98 [35];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2eec;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_cc = 0xf;
  local_d4 = 0;
  iVar6 = ((699 < DAT_004fe624) - 1 & 0xfffffff1) + 0x32;
  if (900 < DAT_004fe624) {
    local_cc = 0x14;
    iVar6 = 0x41;
  }
  local_d0.data = (char *)(DAT_004fe624 / 10 + -10);
  local_c4 = (DAT_004fe624 * 2) / 10 + -10;
  local_bc = (DAT_004fe624 * 3) / 10 + -10;
  local_d8 = (DAT_004fe624 << 2) / 10 + -10;
  local_c8 = iVar6;
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613(&local_e0,s____Previous_race_results_in_this_004dd0bc);
  uStack_4 = 0;
  pcVar1 = *(code **)(*param_1 + 100);
  (*pcVar1)(param_1,10,1,local_e0.data,*(int *)(local_e0.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_e0);
  if (DAT_00536424 == 0) {
    if (0 < DAT_004da194) {
      piVar4 = &DAT_004fbf34;
      iVar2 = 0;
      iVar5 = DAT_004da194;
      do {
        if (DAT_005363fc == 1) {
          iVar7 = *piVar4;
        }
        else {
          iVar7 = piVar4[1] + *piVar4;
        }
        *(int *)((int)aiStack_98 + iVar2 + 4) = iVar7;
        *(int *)((int)&DAT_004fc164 + iVar2) = iVar7;
        piVar4 = piVar4 + 4;
        iVar2 = iVar2 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    FUN_0043f9f0(1);
    FUN_004b0613(&local_e0,s_Place_004dd0b4);
    iVar5 = iVar6 - local_cc;
    uStack_4 = 1;
    (*pcVar1)(param_1,5,iVar5,local_e0.data,*(int *)(local_e0.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_e0);
    FUN_004b0613(&local_e0,s_Race_1_004dd0ac);
    uStack_4 = 2;
    (*pcVar1)(param_1,(int)(local_d0.data + DAT_004fe624 / 0x1e),iVar5,local_e0.data,
              *(int *)(local_e0.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_e0);
    if (DAT_005363fc == 2) {
      FUN_004b0613(&local_e0,s_Race_2_004dd0a4);
      uStack_4 = 3;
      (*pcVar1)(param_1,DAT_004fe624 / 0x32 + local_c4,iVar5,local_e0.data,
                *(int *)(local_e0.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_e0);
    }
    FUN_004b0613(&local_e0,s_Total_points_004dd094);
    uStack_4 = 4;
    (*pcVar1)(param_1,local_d8 - DAT_004fe624 / 0x32,iVar5,local_e0.data,
              *(int *)(local_e0.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_e0);
    local_e0.data = (char *)(DAT_004fe624 / 2 + -10);
    if (0xf < DAT_004da194) {
      FUN_004b0613(&TStack_dc,s_Place_004dd0b4);
      uStack_4 = 5;
      (*pcVar1)(param_1,(int)(local_e0.data + 5),iVar5,TStack_dc.data,*(int *)(TStack_dc.data + -8))
      ;
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_dc);
      FUN_004b0613(&TStack_dc,s_Race_1_004dd0ac);
      uStack_4 = 6;
      (*pcVar1)(param_1,(int)(local_e0.data + DAT_004fe624 / 0x1e + local_d0.data),iVar5,
                TStack_dc.data,*(int *)(TStack_dc.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_dc);
      if (DAT_005363fc == 2) {
        FUN_004b0613(&TStack_dc,s_Race_2_004dd0a4);
        uStack_4 = 7;
        (*pcVar1)(param_1,(int)(local_e0.data + local_c4 + DAT_004fe624 / 0x32),iVar5,TStack_dc.data
                  ,*(int *)(TStack_dc.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_dc);
      }
      FUN_004b0613(&TStack_dc,s_Total_points_004dd094);
      uStack_4 = 8;
      (*pcVar1)(param_1,(int)(local_e0.data + (local_d8 - DAT_004fe624 / 0x32)),iVar5,TStack_dc.data
                ,*(int *)(TStack_dc.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_dc);
    }
    TStack_dc.data = (char *)(DAT_004fe624 / 0x12);
    local_e0.data = (char *)0x1;
    if (0 < DAT_004da194) {
      pcStack_b4 = TStack_dc.data + local_d0.data;
      pcStack_b0 = TStack_dc.data + local_d8;
      do {
        iVar5 = *(int *)(&DAT_004f4778 + (int)local_e0.data * 4);
        FUN_0041f3e0(param_1,iVar5);
        local_d8 = iVar5 * 4;
        *(char **)(&DAT_005357f8 + local_d8) = local_e0.data;
        if ((local_e0.data == (char *)0x1) && (DAT_004da140 < iVar5)) {
          DAT_004f7f90 = iVar5;
        }
        if ((DAT_005357fc == 1) && (local_e0.data == (char *)0x2)) {
          DAT_004f7f90 = iVar5;
        }
        if (DAT_004da140 == 2) {
          if ((DAT_00535800 == 1) && (local_e0.data == (char *)0x2)) {
            DAT_004f7f90 = iVar5;
          }
          if ((DAT_005357fc + DAT_00535800 == 3) && (local_e0.data == (char *)0x3)) {
            DAT_004f7f90 = iVar5;
          }
        }
        pTVar3 = FUN_0041bc70(&TStack_c0,(int)local_e0.data);
        uStack_4 = 9;
        pTVar3 = FUN_004b07bb(&TStack_a0,pTVar3,&DAT_004dd090);
        uStack_4._0_1_ = 10;
        pTVar3 = FUN_004b0755(&TStack_9c,pTVar3,(Tact2010CString *)(&DAT_004fec30 + local_d8));
        uStack_4._0_1_ = 0xb;
        pTVar3 = FUN_004b07bb(&local_d0,pTVar3,&DAT_004db060);
        uStack_4._0_1_ = 0xc;
        (*pcVar1)(param_1,local_d4 + 5,iVar6,pTVar3->data,*(int *)(pTVar3->data + -8));
        uStack_4._0_1_ = 0xb;
        FUN_004b05a5(&local_d0);
        uStack_4._0_1_ = 10;
        FUN_004b05a5(&TStack_9c);
        uStack_4 = CONCAT31(uStack_4._1_3_,9);
        FUN_004b05a5(&TStack_a0);
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_c0);
        iVar5 = iVar5 * 0x10;
        pTVar3 = FUN_0041bc70(&TStack_a4,*(int *)(&DAT_004fbf24 + iVar5) / 100);
        uStack_4 = 0xd;
        (*pcVar1)(param_1,(int)(pcStack_b4 + local_d4),iVar6,pTVar3->data,
                  *(int *)(pTVar3->data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_a4);
        if ((0 < *(int *)(&DAT_004fbf28 + iVar5)) && (1 < DAT_005363fc)) {
          pTVar3 = FUN_0041bc70(&TStack_ac,*(int *)(&DAT_004fbf28 + iVar5) / 100);
          uStack_4 = 0xe;
          (*pcVar1)(param_1,(int)(TStack_dc.data + local_d4 + local_c4),iVar6,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_ac);
        }
        if (0 < *(int *)(&DAT_004fbf2c + iVar5)) {
          pTVar3 = FUN_0041bc70(&TStack_b8,*(int *)(&DAT_004fbf2c + iVar5) / 100);
          uStack_4 = 0xf;
          (*pcVar1)(param_1,(int)(TStack_dc.data + local_d4 + local_bc),iVar6,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_b8);
        }
        pTVar3 = FUN_0041bc70(&TStack_a8,*(int *)((int)aiStack_98 + local_d8) / 100);
        uStack_4 = 0x10;
        (*pcVar1)(param_1,(int)(pcStack_b0 + local_d4),iVar6,pTVar3->data,
                  *(int *)(pTVar3->data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_a8);
        iVar6 = iVar6 + local_cc;
        if (local_e0.data == (char *)0xf) {
          local_d4 = DAT_004fe624 / 2 + -10;
          iVar6 = local_c8;
        }
        local_e0.data = local_e0.data + 1;
      } while ((int)local_e0.data <= DAT_004da194);
    }
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0xff);
  }
  local_c8 = local_cc * 8;
  iVar6 = (DAT_004fe2a8 * 6) / 7 + local_cc * -8 + 10;
  if (DAT_004f8cd0 < 1) {
    if (DAT_005363b0 == 0) {
      FUN_004b0613(&TStack_dc,s_Click_mouse_to_continue__004dd074);
      uStack_4 = 0x12;
      (*pcVar1)(param_1,10,iVar6,TStack_dc.data,*(int *)(TStack_dc.data + -8));
    }
    else {
      FUN_004b0613(&TStack_dc,s_Press_spacebar_to_continue__004dd058);
      uStack_4 = 0x13;
      (*pcVar1)(param_1,10,iVar6,TStack_dc.data,*(int *)(TStack_dc.data + -8));
    }
  }
  else {
    FUN_004b0613(&TStack_dc,s_Movement_suspended__Click_mouse_o_004da994);
    uStack_4 = 0x11;
    (*pcVar1)(param_1,10,iVar6,TStack_dc.data,*(int *)(TStack_dc.data + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_dc);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


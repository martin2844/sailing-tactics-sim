
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004545d0(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  double dVar4;
  int *original_dc;
  int iVar5;
  Tact2010CString TVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_30;
  int local_2c [2];
  int local_24;
  Tact2010CString aTStack_20 [2];
  Tact2010CString aTStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4820;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar4;
  if (DAT_004fe624 < 700) {
    iVar7 = 0x10;
    local_30 = 0x16;
    local_2c[0] = 5;
    local_24 = 10;
  }
  else {
    iVar7 = 0x14;
    local_30 = 0x1b;
    local_2c[0] = 0x14;
    local_24 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___HEADERS_WHILE_BEATING___004e708c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_2c[0],2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = local_30 + 2;
  if (DAT_004fb9b4 == 0) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_A_header_is_a_windshift_that_for_004e7030);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_2c[0],iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boats_A_and_B_are_initially_even_004e6bbc);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_2c[0],iVar5 + local_30,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_30 + local_30;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6ff4);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_2c[0],iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 1) {
    FUN_004b0613(aTStack_20,s_Boat_A_has_gained_30___of_the_se_004e6f90);
    param_1 = (int *)(local_24 + local_2c[0]);
    uStack_4 = 4;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    FUN_004b0613(aTStack_20,s_boat_lengths__If_the_boats_had_b_004e6f2c);
    uStack_4 = 5;
    (*pcVar1)(original_dc,(int)param_1,iVar5 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    iVar5 = iVar5 + iVar7 + iVar7;
    FUN_004b0613(aTStack_20,s_gained_30___of_a_mile___If_the_s_004e6ecc);
    uStack_4 = 6;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    iVar5 = iVar5 + local_30;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(aTStack_20,s_Problem__If_the_wind_shifts_back_004e6e74);
    uStack_4 = 7;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    iVar5 = iVar5 + iVar7;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(aTStack_20,s_To_consolidate_the_gain__A_tacks_004e6e50);
    uStack_4 = 8;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    iVar5 = iVar5 + local_30;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(aTStack_20,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 9;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
  }
  if (DAT_004fb9b4 == 2) {
    FUN_004b0613(aTStack_20,s_If_Boat_A_can_get_between_the_ma_004e6dd8);
    param_1 = (int *)(local_24 + local_2c[0]);
    uStack_4 = 10;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    FUN_004b0613(aTStack_20,s_will_not_be_lost_by_a_wind_shift_004e6db4);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,(int)param_1,iVar5 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    iVar5 = iVar5 + iVar7 + local_30;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(aTStack_20,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
  }
  if (DAT_004fb9b4 == 3) {
    FUN_004b0613(aTStack_20,s_Boat_A_is_now_between_the_mark_a_004e6d64);
    param_1 = (int *)(local_24 + local_2c[0]);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    FUN_004b0613(aTStack_20,s_In_order_to_stay_in_this_safe_po_004e6d20);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,(int)param_1,iVar5 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    iVar5 = iVar5 + iVar7 + local_30;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(aTStack_20,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
  }
  if (DAT_004fb9b4 == 4) {
    FUN_004b0613(aTStack_20,s_Boat_A_s_position_between_Boat_B_004e6cd0);
    param_1 = (int *)(local_24 + local_2c[0]);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,(int)param_1,iVar5,aTStack_20[0].data,*(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    FUN_004b0613(aTStack_20,s_Boat_A_s_lead_will_not_be_lost_b_004e6ca0);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,(int)param_1,iVar5 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    FUN_004b0613(aTStack_20,s_In_order_to_keep_this_position__B_004e6c50);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,(int)param_1,iVar5 + iVar7 + local_30,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
  }
  FUN_00463df0(original_dc,local_2c[0],iVar7);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00454c60;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00454c60;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00454c60:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 4;
  FUN_00463c90(original_dc,iVar7);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  TVar6.data = (char *)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
  local_24 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc5e0);
  aTStack_18[0].data = TVar6.data;
  FUN_0043faa0(original_dc,TVar6.data,local_24,4,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004dd748);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,(int)(TVar6.data + DAT_004fe624 / 100),local_24,(char *)param_1,param_1[-2])
  ;
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_004fb9b4 == 0) {
    DAT_005362d4 = DAT_004fb9b4;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_20,(int)TVar6.data,local_24);
    local_2c[0] = (int)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,local_2c[0],(int)param_1);
    FUN_004b0613(aTStack_20,"LayLine");
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,local_2c[0],(int)param_1 + iVar7 * -2,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    FUN_004b4d9d(original_dc,(int *)aTStack_20,(int)TVar6.data,local_24);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,iVar5,(int)param_1);
    iVar3 = DAT_004fe624 / 0xe;
    FUN_004b0613(aTStack_20,"LayLine");
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7 * -2,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    aTStack_20[0].data = *(char **)(*original_dc + 0x38);
    (*(code *)aTStack_20[0].data)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    FUN_004b4d9d(original_dc,local_2c,0,iVar5);
    CDC::LineTo(original_dc,DAT_004fe624,iVar5);
    (*(code *)aTStack_20[0].data)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)aTStack_20[0].data)(original_dc,0);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc508);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 10;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar5,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_20,"Boat B");
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc518);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 0xe;
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar5,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_20,"Boat A");
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    TVar6.data = aTStack_18[0].data;
  }
  if ((DAT_004fb9b4 == 1) || (DAT_004fb9b4 == 2)) {
    DAT_005362d4 = 0x14;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_20,(int)TVar6.data,local_24);
    local_2c[0] = (int)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,local_2c[0],(int)param_1);
    FUN_004b0613(aTStack_20,"LayLine");
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,local_2c[0],(int)param_1 + iVar7 * -2,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    FUN_004b4d9d(original_dc,(int *)aTStack_20,(int)TVar6.data,local_24);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,iVar5,(int)param_1);
    iVar3 = DAT_004fe624 / 0xe;
    FUN_004b0613(aTStack_20,"LayLine");
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7 * -2,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    pcVar2 = *(code **)(*original_dc + 0x38);
    (*pcVar2)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_20,(int)(longlong)(_DAT_005230e8 * _DAT_004cc508),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccc28));
    CDC::LineTo(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc518),
                (int)(longlong)(_DAT_005230b0 * _DAT_004cc600));
    (*pcVar2)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,(int)(longlong)(_DAT_005230b0 * _DAT_004cc738),
              (char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc508);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 10;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x127;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar5,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_20,"Boat B");
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc518);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 0xe;
    if (DAT_004fb9b4 == 1) {
      DAT_00522ff8 = DAT_004fb9b4;
      _DAT_004fc2c8 = 0xf;
      _DAT_004fe820 = 2;
      DAT_004fdff0 = 0x3c;
      DAT_004fb388 = 0xf;
      DAT_00535748 = 0x127;
      DAT_004fecd0 = 0x2d;
    }
    if (DAT_004fb9b4 == 2) {
      DAT_00522ff8 = -1;
      _DAT_004fc2c8 = 0xf;
      _DAT_004fe820 = DAT_004fb9b4;
      DAT_004fdff0 = 0x3c;
      DAT_004fb388 = 0xf;
      DAT_00535748 = 0x19;
      DAT_004fecd0 = 0x2d;
    }
    FUN_00417aa0(original_dc,iVar5,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_20,"Boat A");
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7,aTStack_20[0].data,
              *(int *)(aTStack_20[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_20);
    TVar6.data = aTStack_18[0].data;
  }
  if ((DAT_004fb9b4 == 3) || (DAT_004fb9b4 == 4)) {
    DAT_005362d4 = 0x14;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)TVar6.data,local_24);
    local_2c[0] = (int)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,local_2c[0],(int)param_1);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,local_2c[0],(int)param_1 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)TVar6.data,local_24);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,iVar5,(int)param_1);
    iVar3 = DAT_004fe624 / 0xe;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (**(code **)(*original_dc + 0x38))(original_dc,0);
    local_2c[0] = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc668);
    iVar3 = DAT_004fe624 / 0xe;
    if (DAT_004fb9b4 == 3) {
      DAT_00522ff8 = -1;
      _DAT_004fc2c8 = 0xf;
      _DAT_004fe820 = 2;
      DAT_004fdff0 = 0x3c;
      DAT_004fb388 = 0xf;
      DAT_00535748 = 0x19;
      DAT_004fecd0 = 0x2d;
    }
    if (DAT_004fb9b4 == 4) {
      DAT_00522ff8 = 1;
      _DAT_004fc2c8 = 0xf;
      _DAT_004fe820 = 2;
      DAT_004fdff0 = 0x3c;
      DAT_004fb388 = 0xf;
      DAT_00535748 = 0x127;
      DAT_004fecd0 = 0x2d;
    }
    FUN_00417aa0(original_dc,local_2c[0],iVar5,2,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat A");
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,iVar3 + local_2c[0],iVar5 - iVar7,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar3 = DAT_004fe624 / 10;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x127;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar5,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x21;
    (*pcVar1)(original_dc,iVar5 - iVar3,(int)param_1 + iVar7,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_004f71c4 = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


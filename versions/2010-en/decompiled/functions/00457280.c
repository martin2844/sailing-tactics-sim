
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00457280(int *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  int *original_dc;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_2c;
  int local_28 [2];
  int iStack_20;
  Tact2010CString TStack_1c;
  Tact2010CString aTStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4ac8;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar3;
  if (DAT_004fe624 < 700) {
    iVar4 = 0x10;
    local_2c = 0x16;
    local_28[0] = 5;
  }
  else {
    iVar4 = 0x14;
    local_2c = 0x1b;
    local_28[0] = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___STRATEGY_for_BEATING_IN_AN_OSC_004e79dc);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_28[0],2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  param_1 = (int *)(local_2c + 2);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  if (DAT_004fb9b4 == 0) {
    FUN_004b0613(&TStack_1c,s_An_oscillating_wind_is_one_which_004e7980);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_1c,s_of_the_race__In_an_oscillating_w_004e7924);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(&TStack_1c,s_by_tacking_at_the_right_times__004e7904);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_1c,s_Boat_A_and_Boat_B_are_even__The_w_004e78c0);
    uStack_4 = 4;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(&TStack_1c,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 5;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
  }
  if (DAT_004fb9b4 == 1) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_1c,s_The_wind_swings_20_degrees_to_th_004e787c);
    uStack_4 = 6;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(&TStack_1c,s_Both_boats_are_headed_20_degrees_004e784c);
    uStack_4 = 7;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(&TStack_1c,s_Boat_A_and_Boat_B_are_almost_eve_004e7808);
    uStack_4 = 8;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(&TStack_1c,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 9;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
  }
  if (DAT_004fb9b4 == 2) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_1c,s_They_sail_some_distance__004e77ec);
    uStack_4 = 10;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(&TStack_1c,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
  }
  if (DAT_004fb9b4 == 3) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_1c,s_The_wind_swings_20_degrees_to_th_004e77a4);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(&TStack_1c,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
  }
  if (DAT_004fb9b4 == 4) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_1c,s_By_tacking_when_headed_relative_t_004e774c);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(&TStack_1c,s_Boat_A_will_finish_the_leg_saili_004e76fc);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(&TStack_1c,s_even_though_the_wind_shifts_were_004e76ac);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613(&TStack_1c,s_When_the_wind_is_near_the_averag_004e7658);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(&TStack_1c,s_from_the_nearest_layline_since_a_004e7608);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    param_1 = (int *)((int)param_1 + local_2c);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_1c,s_Boats_which_lose_significant_dis_004e75b8);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,local_28[0],(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    FUN_004b0613(&TStack_1c,s_will_not_gain_by_tacking_on_very_004e7588);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,local_28[0],iVar4 + (int)param_1,TStack_1c.data,
              *(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
  }
  FUN_00463df0(original_dc,local_28[0],iVar4);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00457a23;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00457a23;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00457a23:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 4;
  FUN_00463c90(original_dc,iVar4);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  iStack_20 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
  TStack_1c.data = (char *)(longlong)(_DAT_005230b0 * _DAT_004cc5e0);
  FUN_0043faa0(original_dc,iStack_20,TStack_1c.data,4,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004dd748);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,DAT_004fe624 / 100 + iStack_20,(int)TStack_1c.data,(char *)param_1,
            param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_004fb9b4 == 0) {
    DAT_005362d4 = 0;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    local_28[0] = DAT_004fe624 / 0x32;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,(int)param_1 - local_28[0],iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    local_28[0] = DAT_004fe624 / 0xf;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,(int)param_1 - local_28[0],iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    aTStack_18[0].data = *(char **)(*original_dc + 0x38);
    (*(code *)aTStack_18[0].data)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    FUN_004b4d9d(original_dc,local_28,0,iVar2);
    CDC::LineTo(original_dc,DAT_004fe624,iVar2);
    (*(code *)aTStack_18[0].data)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,DAT_004fe624 / 5,iVar2,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)aTStack_18[0].data)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0] = DAT_004fe624 / 0x14;
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 1;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,local_28[0] + (int)param_1,iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0] = DAT_004fe624 / 0xe;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,(int)param_1 - local_28[0],iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (DAT_004fb9b4 == 1) {
    DAT_005362d4 = 0x1e;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    local_28[0] = DAT_004fe624 / 0xe;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,(int)param_1 - local_28[0],iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (**(code **)(*original_dc + 0x38))(original_dc,0);
    DAT_005127a0 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    DAT_004f721c = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0] = DAT_004fe624 / 0x14;
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 0xffffffff;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x19;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,DAT_005127a0,DAT_004f721c,1,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat A");
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,DAT_005127a0 + local_28[0],DAT_004f721c + iVar4,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    DAT_004fe620 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    DAT_004fb24c = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0] = DAT_004fe624 / 0xe;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x127;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,DAT_004fe620,DAT_004fb24c,2,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat B");
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,DAT_004fe620 - local_28[0],DAT_004fb24c + iVar4,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 2) {
    DAT_005362d4 = 0x1e;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    local_28[0] = DAT_004fe624 / 0xe;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,(int)param_1 - local_28[0],iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (**(code **)(*original_dc + 0x38))(original_dc,0);
    DAT_00535604 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    DAT_005354c0 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    local_28[0] = DAT_004fe624 / 0x14;
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 0xffffffff;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x19;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,DAT_00535604,DAT_005354c0,1,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat A");
    uStack_4 = 0x21;
    (*pcVar1)(original_dc,DAT_00535604 + local_28[0],DAT_005354c0 + iVar4,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    DAT_004f4148 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc660);
    DAT_005354b8 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    local_28[0] = DAT_004fe624 / 0xe;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x127;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,DAT_004f4148,DAT_005354b8,2,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat B");
    uStack_4 = 0x22;
    (*pcVar1)(original_dc,DAT_004f4148 - local_28[0],DAT_005354b8 + iVar4,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 3) {
    DAT_005362d4 = 0xffffffec;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x23;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_20,(int)TStack_1c.data);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    local_28[0] = DAT_004fe624 / 0xe;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x24;
    (*pcVar1)(original_dc,(int)param_1 - local_28[0],iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (**(code **)(*original_dc + 0x38))(original_dc,0);
    DAT_00523394 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    DAT_0052365c = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    local_28[0] = DAT_004fe624 / 0x14;
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 1;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x14f;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,DAT_00523394,DAT_0052365c,1,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat A");
    uStack_4 = 0x25;
    (*pcVar1)(original_dc,DAT_00523394 + local_28[0],DAT_0052365c + iVar4,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    DAT_005357d0 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc660);
    DAT_004fb9ec = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    local_28[0] = DAT_004fe624 / 0xe;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x41;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,DAT_005357d0,DAT_004fb9ec,2,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat B");
    uStack_4 = 0x26;
    (*pcVar1)(original_dc,DAT_005357d0 - local_28[0],DAT_004fb9ec + iVar4,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 4) {
    DAT_005362d4 = 0xffffffec;
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc668);
    local_28[0] = DAT_004fe624 / 0x14;
    if ((DAT_005363e4 == 0) && (DAT_005362ec != (HGDIOBJ)0x0)) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)param_1,iVar2);
    CDC::LineTo(original_dc,DAT_00523394,DAT_0052365c);
    CDC::LineTo(original_dc,DAT_00535604,DAT_005354c0);
    CDC::LineTo(original_dc,DAT_005127a0,DAT_004f721c);
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 1;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x14f;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x27;
    (*pcVar1)(original_dc,local_28[0] + (int)param_1,iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    local_28[0] = DAT_004fe624 / 0xe;
    if ((DAT_005363e4 == 0) && (DAT_004f3c0c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)param_1,iVar2);
    CDC::LineTo(original_dc,DAT_005357d0,DAT_004fb9ec);
    CDC::LineTo(original_dc,DAT_004f4148,DAT_005354b8);
    CDC::LineTo(original_dc,DAT_004fe620,DAT_004fb24c);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x41;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x28;
    (*pcVar1)(original_dc,(int)param_1 - local_28[0],iVar2 + iVar4,aTStack_18[0].data,
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


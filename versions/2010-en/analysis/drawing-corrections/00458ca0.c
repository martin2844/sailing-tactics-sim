
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00458ca0(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  int *original_dc;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_28;
  int local_24;
  Tact2010CString aTStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar6 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4c00;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar6;
  if (DAT_004fe624 < 700) {
    iVar7 = 0x10;
    local_24 = 0x16;
    local_28 = 5;
  }
  else {
    iVar7 = 0x14;
    local_24 = 0x1b;
    local_28 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___STRATEGY_for_BEATING_with_ONE_S_004e7f38);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_28,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar8 = local_24 + 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  if (DAT_004fb9b4 == 0) {
    FUN_004b0613((Tact2010CString *)&param_1,s_One_side_could_be_favored_becaus_004e7eec);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_less_adverse_tide_on_one_side__o_004e7e98);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_28,iVar8 + iVar7,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + iVar7 + iVar7;
    FUN_004b0613((Tact2010CString *)&param_1,s_shift_is_one_that_does_not_shift_004e7e40);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + local_24;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_The_boats_are_even__Boat_A_expec_004e7de8);
    uStack_4 = 4;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + local_24;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 5;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_After_they_sail_some_distance__t_004e7da0);
    uStack_4 = 6;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + iVar7;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 7;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 2) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_A_has_made_a_significant_ga_004e7d70);
    uStack_4 = 8;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_If_the_wind_goes_farther_right__B_004e7d10);
    uStack_4 = 9;
    (*pcVar1)(original_dc,local_28,iVar8 + local_24,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + local_24 + iVar7;
    FUN_004b0613((Tact2010CString *)&param_1,s_However__that_would_be_risky__If_004e7cb4);
    uStack_4 = 10;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + iVar7;
    FUN_004b0613((Tact2010CString *)&param_1,s_and_lose_much_distance__Also__if_004e7c58);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + iVar7;
    FUN_004b0613((Tact2010CString *)&param_1,s_be_hopelessly_behind__004e7c40);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + local_24;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 3) {
    FUN_004b0613((Tact2010CString *)&param_1,s_The_wind_goes_another_10_degrees_004e7be0);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_When_one_side_is_favored__the_be_004e7b7c);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,local_28,iVar8 + local_24,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + local_24 + iVar7;
    FUN_004b0613((Tact2010CString *)&param_1,s_However__one_must_be_careful_not_004e7b18);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + iVar7;
    FUN_004b0613((Tact2010CString *)&param_1,s_oscillating__one_probably_should_004e7ab4);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar8 = iVar8 + local_24;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_If_somewhat_in_doubt_that_one_si_004e7a54);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,local_28,iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_Instead__try_to_stay_on_the_favo_004e7a10);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,local_28,iVar7 + iVar8,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  FUN_00463df0(original_dc,local_28,iVar7);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00459318;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00459318;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00459318:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 3;
  FUN_00463c90(original_dc,iVar7);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  iVar8 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
  iVar3 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc5e0);
  FUN_0043faa0(original_dc,iVar8,iVar3,4,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004dd748);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,DAT_004fe624 / 100 + iVar8,iVar3,(char *)param_1,param_1[-2]);
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
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar8,iVar3);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,iVar4,iVar5);
    param_1 = (int *)(DAT_004fe624 / 0x32);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar8,iVar3);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,iVar4,iVar5);
    param_1 = (int *)(DAT_004fe624 / 10);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    pcVar2 = *(code **)(*original_dc + 0x38);
    (*pcVar2)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,0,iVar4);
    CDC::LineTo(original_dc,DAT_004fe624,iVar4);
    (*pcVar2)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,DAT_004fe624 / 5,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    param_1 = (int *)(DAT_004fe624 / 0x14);
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 0xffffffff;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x2d;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar4,iVar5,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,(int)param_1 + iVar4,iVar5 + iVar7,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    param_1 = (int *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,iVar5,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + iVar7,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if ((DAT_004fb9b4 == 1) || (DAT_004fb9b4 == 2)) {
    DAT_005362d4 = -10;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar8,iVar3);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    CDC::LineTo(original_dc,iVar4,iVar5);
    param_1 = (int *)(DAT_004fe624 / 0x32);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar8,iVar3);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    CDC::LineTo(original_dc,iVar4,iVar5);
    param_1 = (int *)(DAT_004fe624 / 10);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    pcVar2 = *(code **)(*original_dc + 0x38);
    (*pcVar2)(original_dc,0);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    param_1 = (int *)(DAT_004fe624 / 0x14);
    if (DAT_004fb9b4 == 1) {
      DAT_00522ff4 = 0xffffffff;
      DAT_00535744 = 0x23;
    }
    else {
      DAT_00522ff4 = 1;
      DAT_00535744 = 0x145;
    }
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar4,iVar5,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,(int)param_1 + iVar4,iVar5 + iVar7,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar4,iVar5);
    CDC::LineTo(original_dc,DAT_004fe624 / 5,iVar5 - DAT_004fe2a8 / 10);
    (*pcVar2)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,iVar5 - DAT_004fe2a8 / 0x14,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    param_1 = (int *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x145;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,iVar5,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + iVar7,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (DAT_004fb9b4 == 3) {
    DAT_005362d4 = -0x14;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar8,iVar3);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc958);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,iVar4,iVar5);
    param_1 = (int *)(DAT_004fe624 / 0x32);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar8,iVar3);
    iVar8 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc598);
    iVar3 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,iVar8,iVar3);
    param_1 = (int *)(DAT_004fe624 / 10);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,iVar8 - (int)param_1,iVar3 + iVar7 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    pcVar2 = *(code **)(*original_dc + 0x38);
    (*pcVar2)(original_dc,0);
    iVar8 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    iVar3 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    DAT_00522ff4 = 1;
    param_1 = (int *)(DAT_004fe624 / 0x14);
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x14f;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar8,iVar3,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x21;
    (*pcVar1)(original_dc,(int)param_1 + iVar8,iVar3 + iVar7,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar8,iVar3);
    CDC::LineTo(original_dc,DAT_004fe624 / 5,iVar3 - DAT_004fe2a8 / 5);
    (*pcVar2)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x22;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,iVar3 - DAT_004fe2a8 / 10,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0);
    iVar8 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar3 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    param_1 = (int *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x14f;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar8,iVar3,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x23;
    (*pcVar1)(original_dc,iVar8 - (int)param_1,iVar3 + iVar7,aTStack_18[0].data,
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


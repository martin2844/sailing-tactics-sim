
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00453230(int *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  int *original_dc;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_28;
  Tact2010CString TStack_24;
  int local_20;
  int local_1c;
  Tact2010CString aTStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4700;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar3;
  if (DAT_004fe624 < 700) {
    iVar4 = 0x10;
    local_20 = 0x16;
    local_28 = 5;
    local_1c = 10;
  }
  else {
    iVar4 = 0x14;
    local_20 = 0x1b;
    local_28 = 0x14;
    local_1c = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___LIFTS_WHILE_BEATING___004e6c34);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_28,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  param_1 = (int *)(local_20 + 2);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  param_1 = (int *)((int)param_1 + iVar4);
  if (DAT_004fb9b4 == 0) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_24,s_A_lift_is_a_windshift_that_lets_a_004e6be0);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_28,(int)param_1,TStack_24.data,*(int *)(TStack_24.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_24);
    param_1 = (int *)((int)param_1 + local_20);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_24,s_Boats_A_and_B_are_initially_even_004e6bbc);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_28,(int)param_1,TStack_24.data,*(int *)(TStack_24.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_24);
    param_1 = (int *)((int)param_1 + local_20);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(&TStack_24,s_Click_the_Advance_Position_Butto_004e6b84);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_28,(int)param_1,TStack_24.data,*(int *)(TStack_24.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_24);
  }
  if (DAT_004fb9b4 == 1) {
    FUN_004b0613(aTStack_18,s_Boat_A_has_just_gained_a_lot__004e6b64);
    TStack_24.data = (char *)(local_28 + local_1c);
    uStack_4 = 4;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + local_20);
    FUN_004b0613(aTStack_18,s_Notice_that_the_laylines_and_the_004e6b1c);
    uStack_4 = 5;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + local_20);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(aTStack_18,s_Click_the_Advance_Position_Butto_004e6adc);
    uStack_4 = 6;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (DAT_004fb9b4 == 2) {
    FUN_004b0613(aTStack_18,s_Boat_A_has_gained_30___of_the_se_004e6a84);
    TStack_24.data = (char *)(local_28 + local_1c);
    uStack_4 = 7;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(aTStack_18,s_about_two_boat_lengths__If_the_b_004e6a30);
    uStack_4 = 8;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(aTStack_18,s_occurred__Boat_A_would_have_gain_004e69fc);
    uStack_4 = 9;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + local_20);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613(aTStack_18,s_If_the_shift_was_only_10_degrees_004e69b4);
    uStack_4 = 10;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + local_20);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613(aTStack_18,s_Click_the_Advance_Position_Butto_004e697c);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (DAT_004fb9b4 == 3) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613(aTStack_18,s_Using_the_compass_to_detect_a_wi_004e6950);
    TStack_24.data = (char *)(local_28 + local_1c);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(aTStack_18,s_If_a_closehauled_boat_is_being_s_004e68f4);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(aTStack_18,s_true_wind_changes_20_degrees_pro_004e6898);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)((int)param_1 + iVar4);
    FUN_004b0613(aTStack_18,
                 "crew compares compass headings before and after a shift, he can tell the helmsperson how much the wind shifted."
                );
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,(int)TStack_24.data,(int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b0613(aTStack_18,s__004e6820);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,(int)TStack_24.data,iVar4 + (int)param_1,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  FUN_00463df0(original_dc,local_28,iVar4);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00453883;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00453883;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00453883:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 3;
  FUN_00463c90(original_dc,iVar4);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  local_20 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
  local_1c = (int)(longlong)(_DAT_005230b0 * _DAT_004cc5e0);
  FUN_0043faa0(original_dc,local_20,local_1c,4,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004dd748);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,DAT_004fe624 / 100 + local_20,local_1c,(char *)param_1,param_1[-2]);
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
    FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20,local_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc618);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    TStack_24.data = (char *)(DAT_004fe624 / 0x32);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20,local_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    TStack_24.data = (char *)(DAT_004fe624 / 0x19);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = *(int **)(*original_dc + 0x38);
    (*(code *)param_1)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,0,iVar2);
    CDC::LineTo(original_dc,DAT_004fe624,iVar2);
    (*(code *)param_1)(original_dc,0x7f00);
    FUN_004b0613(aTStack_18,"Equal Position Line");
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,iVar2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (*(code *)param_1)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    TStack_24.data = (char *)(DAT_004fe624 / 10);
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 1;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc5f0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    TStack_24.data = (char *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (DAT_004fb9b4 == 1) {
    DAT_005362d4 = 0xffffffec;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20,local_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc618);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    TStack_24.data = (char *)(DAT_004fe624 / 0x32);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20,local_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    TStack_24.data = (char *)(DAT_004fe624 / 0x19);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = *(int **)(*original_dc + 0x38);
    (*(code *)param_1)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)(longlong)(_DAT_005230e8 * _DAT_004cc600),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600));
    CDC::LineTo(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0),
                (int)(longlong)(_DAT_005230b0 * _DAT_004cc820));
    (*(code *)param_1)(original_dc,0x7f00);
    FUN_004b0613(aTStack_18,"Equal Position Line");
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,(int)(longlong)(_DAT_005230b0 * _DAT_004cc738),
              aTStack_18[0].data,*(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (*(code *)param_1)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    TStack_24.data = (char *)(DAT_004fe624 / 10);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x14f;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc5f0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    TStack_24.data = (char *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x14f;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (1 < DAT_004fb9b4) {
    DAT_005362d4 = 0xffffffec;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20,local_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc618);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    TStack_24.data = (char *)(DAT_004fe624 / 0x32);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20,local_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    TStack_24.data = (char *)(DAT_004fe624 / 0x19);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (**(code **)(*original_dc + 0x38))(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc668);
    TStack_24.data = (char *)(DAT_004fe624 / 10);
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 1;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x14f;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    TStack_24.data = (char *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x41;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_24.data,iVar2 + iVar4,aTStack_18[0].data,
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


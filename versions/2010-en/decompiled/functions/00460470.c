
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00460470(int *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  double dVar4;
  int *original_dc;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_20;
  int local_1c;
  int local_18;
  Tact2010CString TStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  DAT_0053658c = DAT_005350e4;
  DAT_00536588 = DAT_005350e0;
  DAT_00536584 = DAT_005350dc;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c5368;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_00536598 = DAT_005350f0;
  DAT_004faf7c = (int)(longlong)dVar4;
  if (DAT_004fe624 < 700) {
    local_18 = 0x10;
    local_1c = 0x16;
    local_20 = 5;
  }
  else {
    local_1c = 0x1b;
    local_18 = 0x14;
    local_20 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___MARK_ROUNDING___004eab80);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_20,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = local_18 + 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  if (DAT_004fb9b4 == 0) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Rounding_a_mark_with_other_boats_004eab28);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_race_since_the_outside_boat_must_004eaaf0);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_20,iVar5 + local_18,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18 + local_1c;
    FUN_004b0613((Tact2010CString *)&param_1,s_Roundings_are_especially_importa_004eaa98);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_the_outside_boats_usually_start_t_004eaa5c);
    uStack_4 = 4;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_1c;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boats_A__B__C__and_D_are_approac_004eaa14);
    uStack_4 = 5;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_Boats_B_and_C_will_have_to_give_r_004ea9bc);
    uStack_4 = 6;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_inside_overlap_on_both_B_and_C__B_004ea95c);
    uStack_4 = 7;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_As_they_go_around__Boat_A_sails_t_004ea910);
    uStack_4 = 8;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_D_intentionally_slows_down_a_004ea8bc);
    uStack_4 = 9;
    (*pcVar1)(original_dc,local_20,iVar5 + local_1c,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_1c + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_the_outside_boat__Boat_D_will_no_004ea868);
    uStack_4 = 10;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_avoid_a_sharp__speed_killing_tur_004ea818);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    iVar5 = iVar5 + local_1c;
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_A_would_like_a_gradual_turn_004ea7c4);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_a_leeward__right_of_way__boat__U_004ea770);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_rounding_but_not_enough_for_a_ta_004ea730);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 2) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_A_has_the_lead__clear_air__a_004ea6f8);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_B_and_boat_C_have_bad_air_a_004ea6b0);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,local_20,iVar5 + local_18,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18 + local_1c;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_D_is_in_bad_air_but_can_tac_004ea658);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_004b0613((Tact2010CString *)&param_1,s_pack_rather_than_outside_it_when_004ea60c);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_1c;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_If_the_next_were_a_run_or_broad_r_004ea5b4);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,local_20,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_It_almost_never_pays_to_round_in_004ea55c);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,local_20,iVar5 + local_18,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  FUN_00463df0(original_dc,local_20,local_18);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00460b15;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00460b15;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00460b15:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 2;
  FUN_00463c90(original_dc,local_18);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 3;
  DAT_004fbb94 = 0;
  if (DAT_004fb9b4 == 0) {
    if ((2 < DAT_004da190) && (DAT_004da190 != 9)) {
      DAT_005350dc = 1;
      DAT_005350e0 = 1;
      DAT_005350e4 = 1;
      DAT_005350f0 = 1;
    }
    FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),3,1);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004ccc80);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    iVar3 = DAT_004fe624 / 0xf;
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 5;
    _DAT_004fe81c = 0x1e;
    DAT_004fdfec = 0x14;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x82;
    DAT_004feccc = 0x78;
    FUN_00417aa0(original_dc,param_1,iVar5,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004ccc88);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    iVar3 = DAT_004fe624 / 0xf;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 5;
    _DAT_004fe820 = 0x1e;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x82;
    DAT_004fecd0 = 0x78;
    FUN_00417aa0(original_dc,param_1,iVar5,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    iVar3 = DAT_004fe624 / 0xf;
    _DAT_004fe824 = 0x1e;
    _DAT_004fdff4 = 0x1e;
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fc2cc = 5;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x82;
    _DAT_004fecd4 = 0x78;
    FUN_00417aa0(original_dc,param_1,iVar5,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc6d8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar3 = DAT_004fe624 / 0x19;
    _DAT_00523008 = 0xffffffff;
    _DAT_004fc2d8 = 5;
    _DAT_004fe830 = 0x28;
    _DAT_004fe000 = 0x1e;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x82;
    _DAT_004fece0 = 0x78;
    FUN_00417aa0(original_dc,param_1,iVar5,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar5 + 4 + local_18,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 1) {
    if ((2 < DAT_004da190) && (DAT_004da190 != 9)) {
      DAT_005350dc = 0;
      DAT_005350e0 = 0;
      DAT_005350e4 = 0;
      DAT_005350f0 = 0;
    }
    FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc668),3,1);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    iVar3 = DAT_004fe624 / 0xf;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x14;
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 5;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x78;
    DAT_004feccc = 0x5a;
    FUN_00417aa0(original_dc,param_1,iVar5,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar3 = DAT_004fe624 / 0xf;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 5;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x5a;
    DAT_004fecd0 = 100;
    FUN_00417aa0(original_dc,param_1,iVar5,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    iVar3 = DAT_004fe624 / 0xf;
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fc2cc = 5;
    _DAT_004fe824 = 0x14;
    _DAT_004fdff4 = 0x1e;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 100;
    _DAT_004fecd4 = 0x6e;
    FUN_00417aa0(original_dc,param_1,iVar5,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc660);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    iVar3 = DAT_004fe624 / 0x19;
    _DAT_00535758 = 0x6e;
    _DAT_004fece0 = 0x6e;
    _DAT_00523008 = 0xffffffff;
    _DAT_004fc2d8 = 5;
    _DAT_004fe830 = 0x28;
    _DAT_004fe000 = 0x1e;
    _DAT_004fb398 = 0xf;
    FUN_00417aa0(original_dc,param_1,iVar5,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar5 + 4 + local_18,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 2) {
    FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc770),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),3,1);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    iVar3 = DAT_004fe624 / 0x14;
    DAT_00535744 = 0x2d;
    DAT_004feccc = 0x2d;
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    FUN_00417aa0(original_dc,param_1,iVar5,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,&DAT_004ea558);
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5 - local_18,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar3 = DAT_004fe624 / 0x14;
    DAT_00522ff8 = 0xffffffff;
    DAT_00535748 = 0x30;
    DAT_004fecd0 = 0x30;
    _DAT_004fc2c8 = 10;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x32;
    DAT_004fb388 = 0xf;
    FUN_00417aa0(original_dc,param_1,iVar5,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,&DAT_004ea554);
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5 - local_18,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc508);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    iVar3 = DAT_004fe624 / 0xf;
    _DAT_0053574c = 0x33;
    _DAT_004fecd4 = 0x33;
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fc2cc = 10;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x28;
    _DAT_004fb38c = 0xf;
    FUN_00417aa0(original_dc,param_1,iVar5,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    piVar2 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar3 = DAT_004fe624 / 0x19;
    _DAT_004fc2d8 = 0xf;
    _DAT_004fb398 = 0xf;
    _DAT_00523008 = 0xffffffff;
    _DAT_004fe830 = 2;
    _DAT_004fe000 = 0x3c;
    _DAT_00535758 = 0x2d;
    _DAT_004fece0 = 0x2d;
    param_1 = piVar2;
    FUN_00417aa0(original_dc,piVar2,iVar5,6,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat D");
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,(int)piVar2 - iVar3,iVar5 + 4 + local_18,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_005350dc = DAT_00536584;
  DAT_005350e0 = DAT_00536588;
  DAT_005350f0 = DAT_00536598;
  DAT_005350e4 = DAT_0053658c;
  DAT_00536458 = 0;
  DAT_004f71c4 = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00451e60(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *original_dc;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar3 = DAT_004da194;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c4548;
  *unaff_FS_OFFSET = &uStack_c;
  if (0 < iVar3) {
    puVar4 = &DAT_005350dc;
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  DAT_004faf7c = (int)(longlong)(_DAT_005230b0 * _DAT_004cc770);
  if (DAT_004fe624 < 700) {
    local_14 = 0x10;
    local_10 = 0x16;
    iVar3 = 5;
  }
  else {
    iVar3 = 0x14;
    local_10 = 0x1b;
    local_14 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___TACTICS___STRATEGY_TUTORIAL_IN_004e6494);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar3,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Unless_some_boat_has_a_big_speed_004e643c);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar3,local_10 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = local_10 + 2 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_variations__and_opponent_actions_004e63e0);
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar3,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_is_to_play_the_odds_to_maximize_t_004e6380);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar3,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_tack__jibe__or_alter_course_or_b_004e633c);
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar3,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  iVar5 = iVar5 + local_10;
  FUN_004b0613((Tact2010CString *)&param_1,s_This_tutorial_covers_decision_ma_004e62dc);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar3,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_A_bibliography_screen_is_availab_004e6284);
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar3,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Move_through_this_tutorial_with_t_004e6220);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar3,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_There_is_a_control_button_to_adv_004e61bc);
  uStack_4 = 8;
  (*pcVar1)(original_dc,iVar3,local_14 + iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_00463df0(original_dc,iVar3,local_14);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_004521a3;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_004521a3;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_004521a3:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 2;
  FUN_00463c90(original_dc,local_14);
  uVar2 = DAT_004f71c4;
  DAT_00536458 = 2;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5e0),
               (int)(longlong)(_DAT_005230b0 * _DAT_004cc7d0),4,1);
  if (DAT_004fb9b4 == 0) {
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x2d;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),2,1,DAT_004fe2a8,0);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc600),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0),3,1,DAT_004fe2a8,0);
  }
  if (DAT_004fb9b4 == 1) {
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5e0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc508),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x2d;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc660),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc508),2,1,DAT_004fe2a8,0);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc738),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),3,1,DAT_004fe2a8,0);
  }
  if (DAT_004fb9b4 == 2) {
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x2d;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc770),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc660),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),2,1,DAT_004fe2a8,0);
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x2d;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc668),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc508),3,1,DAT_004fe2a8,0);
  }
  DAT_00536458 = 0;
  DAT_004f71c4 = uVar2;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


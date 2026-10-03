
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044e240(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *original_dc;
  int *piVar3;
  int x1;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_20;
  int local_1c;
  Tact2010CString local_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4180;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
    iVar4 = 0x10;
    local_20 = 0x16;
    local_1c = 0x10;
    local_18.data = &DAT_00000005;
  }
  else {
    local_20 = 0x1b;
    local_1c = 0x14;
    local_18.data = (char *)0x14;
    iVar4 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Rounding_a_racing_mark_when_the_b_004e4cb0);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,0x14,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "An outside boat must give an overlapped boat mark-room only when they are on the same tack."
              );
  uStack_4 = 1;
  (*pcVar1)(original_dc,0x14,local_20 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = local_20 + 2 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_Otherwise__starboard_tack_has_ri_004e4c1c);
  uStack_4 = 2;
  (*pcVar1)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  iVar5 = iVar5 + local_20;
  FUN_004b0613((Tact2010CString *)&param_1,s_The_rules_for_I_and_S_are_as_on_t_004e4bb8);
  uStack_4 = 3;
  (*pcVar1)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_P__closehauled_on_port_tack__mus_004e4b7c);
  uStack_4 = 4;
  (*pcVar1)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff00ff);
  }
  iVar5 = iVar5 + local_20;
  FUN_004b0613((Tact2010CString *)&param_1,s_If_P_tacks_while_approaching_the_004e4b0c);
  uStack_4 = 5;
  (*pcVar1)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_If_P_completes_a_tack_inside_the_004e4aa0);
  uStack_4 = 6;
  (*pcVar1)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_P_has_fouled__Rule_18_3___P_also_004e4a30);
  uStack_4 = 7;
  (*pcVar1)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___This_rule_applies_if_either_bo_004e49ec);
  uStack_4 = 8;
  (*pcVar1)(original_dc,0x14,iVar5 + local_20,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_00463df0(original_dc,(int)local_18.data,iVar4);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0044e584;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0044e584;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0044e584:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 3;
  DAT_004fbb94 = 0;
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,iVar4);
  if (DAT_004fb9b4 == 0) {
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004ccbe8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccbf0);
    DAT_00522ff4 = 1;
    param_1 = (int *)(DAT_004fe624 / 0x14);
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar4,iVar5,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&local_18,s_Boat_S__004e49e4);
    uStack_4 = 9;
    (*pcVar1)(original_dc,(int)param_1 + iVar4,iVar5 + 4,local_18.data,*(int *)(local_18.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_18);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    local_18.data = (char *)(longlong)(_DAT_005230b0 * _DAT_004cc620);
    iVar5 = DAT_004fe624 + (DAT_004fe624 >> 0x1f & 0xfU);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,local_18.data,2,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_I__Inside_Overlap_004e4460);
    uStack_4 = 10;
    (*pcVar1)(original_dc,iVar4 - (iVar5 >> 4),(int)(local_18.data + local_1c + 4),(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004ccbf8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc00);
    param_1 = (int *)(DAT_004fe624 / 0xf);
    _DAT_004fc2cc = 0xf;
    _DAT_004fb38c = 0xf;
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_0053574c = 0x2d;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,iVar5,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&local_18,s_Boat_P__Port_Tack_004e3d08);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,iVar4 - (int)param_1,iVar5 + 4 + local_1c,local_18.data,
              *(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_18);
    iVar6 = ((((DAT_005228f4 - DAT_005228e0) * 3) / 2) * 5) / 2;
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc668);
    (**(code **)(*original_dc + 0x2c))(original_dc,7);
    iStack_14 = iVar6 / 2;
    iVar5 = iVar4 - iStack_14;
    x1 = (int)param_1 - iVar6;
    Arc((HDC)original_dc[1],x1,iVar5,(int)param_1 + iVar6,iStack_14 + iVar4,x1,iVar5,x1,iVar5);
    FUN_0043faa0(original_dc,param_1,iVar4,3,1);
    FUN_004b0613(&local_18,s_Mark__Leave_to_Port_004e4444);
    piVar3 = param_1;
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,(int)param_1 - iVar6 / 0xe,(iVar4 - iVar6 / 0xd) - local_1c,local_18.data,
              *(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_18);
    FUN_004b0613((Tact2010CString *)&param_1,s_3_Length_Zone_004e4434);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,(int)piVar3 + iStack_14,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  else {
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x140;
    DAT_004feccc = 0x28;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004ccc10),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccc08),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccbe0),2,1,DAT_004fe2a8,0);
    FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc778),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc668),3,1);
    _DAT_0053574c = 0x5a;
    _DAT_004fecd4 = 0x5a;
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 0x14;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004ccc18),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccbd0),3,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_005350dc = 0;
  DAT_004f71c4 = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044d690(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *original_dc;
  char *y2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString TVar7;
  HDC hdc;
  HGDIOBJ h;
  int local_20;
  Tact2010CString TStack_1c;
  Tact2010CString local_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4100;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
    uVar3 = 0xf;
    local_20 = 0x14;
    local_18[0].data = &DAT_00000005;
  }
  else {
    uVar3 = 0x11;
    local_20 = 0x18;
    local_18[0].data = (char *)0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "Rounding a mark while not closehauled (Rule 18): An outside boat must give mark-room to an inside overlapped boat."
              );
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,5,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  param_1 = (int *)(uVar3 + 2);
  FUN_004b0613(&TStack_1c,
               "There are exceptions. Mark-room is the space a boat needs to sail towards and at the mark"
              );
  uStack_4 = 1;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,
               "on her proper course. The mark-room rules do not apply to a starting mark when boats approach it to start,"
              );
  uStack_4 = 2;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,s_or_when_a_boat_must_tack_to_roun_004e486c);
  uStack_4 = 3;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  param_1 = (int *)((int)param_1 + local_20);
  FUN_004b0613(&TStack_1c,s_O_must_give_I_mark_room_because_t_004e4808);
  uStack_4 = 4;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,
               "O must give I mark-room even if O is on starboard tack and I is on port tack.");
  uStack_4 = 5;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + local_20);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff00ff);
  }
  FUN_004b0613(&TStack_1c,s_O_need_not_give_A_mark_room__whe_004e4758);
  uStack_4 = 6;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,s_not_overlapped__Even_if_A_overla_004e46f0);
  uStack_4 = 7;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + local_20);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_1c,"");
  uStack_4 = 8;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,
               "Moored boats, right-of-way boats and shoals are obstructions. An outside boat must give an overlapped inside boat"
              );
  uStack_4 = 9;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,s_give_room_to_pass_the_obstructio_004e45b4);
  uStack_4 = 10;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,s_choose_which_side_of_the_obstruc_004e454c);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + uVar3);
  FUN_004b0613(&TStack_1c,s_However__Rule_19_applies_at_a_co_004e44e0);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  param_1 = (int *)((int)param_1 + local_20);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_1c,s___Match_racing_and_team_racing__2_004e448c);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,5,(int)param_1,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_1c);
  FUN_00463df0(original_dc,(int)local_18[0].data,uVar3);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0044db63;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0044db63;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0044db63:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 3;
  DAT_004fbb94 = 0;
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,uVar3);
  if (DAT_004fb9b4 == 0) {
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc8a8);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccbe0);
    TStack_1c.data = (char *)(DAT_004fe624 / 0xe);
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x5a;
    DAT_004feccc = 0x5a;
    DAT_00522ff4 = 0xffffffff;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    FUN_00417aa0(original_dc,param_1,iVar4,1,1,DAT_004fe2a8,0);
    FUN_004b0613(local_18,s_Boat_A__No_Overlap_004e4478);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,(int)param_1 - (int)TStack_1c.data,iVar4 + uVar3,local_18[0].data,
              *(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc660);
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fe824 = 0x14;
    TStack_1c.data = (char *)(DAT_004fe624 / 0xe);
    _DAT_004fdff4 = 0x3c;
    _DAT_004fc2cc = 0xf;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x5a;
    _DAT_004fecd4 = 0x5a;
    FUN_00417aa0(original_dc,param_1,(int)(longlong)(_DAT_005230b0 * _DAT_004ccbe0),3,1,DAT_004fe2a8
                 ,0);
    FUN_004b0613(local_18,s_Boat_I__Inside_Overlap_004e4460);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,(int)param_1 - ((int)TStack_1c.data * 3) / 2,
              (uVar3 * 3) / 2 + DAT_004faf7c,local_18[0].data,*(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc7e0);
    TStack_1c.data = (char *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x5a;
    DAT_004fecd0 = 0x5a;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    FUN_00417aa0(original_dc,param_1,iVar4,2,1,DAT_004fe2a8,0);
    FUN_004b0613(local_18,s_Boat_O__004e4458);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,(int)(TStack_1c.data + (int)param_1),uVar3 / 2 + iVar4,local_18[0].data,
              *(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
    (**(code **)(*original_dc + 0x2c))(original_dc,7);
    FUN_004b4d9d(original_dc,(int *)local_18,DAT_005228e0,
                 DAT_005229e0 - ((int)(DAT_004fe2a8 + (DAT_004fe2a8 >> 0x1f & 3U)) >> 2));
    CDC::LineTo(original_dc,DAT_005228e0,DAT_004fe2a8 / 0xf + DAT_005229e0);
    FUN_004b0613((Tact2010CString *)&param_1,s_Overlap_Line_004e4064);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,DAT_005228e0,DAT_004fe2a8 / 0xf + DAT_005229e0,(char *)param_1,param_1[-2]
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = DAT_005228f4 - DAT_005228e0;
    iVar5 = iVar4 * 2;
    param_1 = (int *)((iVar4 * 8) / 5 + DAT_005228f4);
    TStack_1c.data = (char *)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    local_18[0].data = (char *)((int)param_1 + iVar4 * -2);
    iVar4 = (int)TStack_1c.data - iVar5 / 2;
    y2 = TStack_1c.data + iVar5 / 2;
    Arc((HDC)original_dc[1],(int)local_18[0].data,iVar4,(int)param_1 + iVar5,(int)y2,
        (int)local_18[0].data,iVar4,(int)local_18[0].data,iVar4);
    FUN_004b0613(local_18,s_Mark__Leave_to_Port_004e4444);
    piVar6 = param_1;
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,(int)param_1,(int)(TStack_1c.data + iVar5 / 0xe),local_18[0].data,
              *(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
    FUN_004b0613((Tact2010CString *)&param_1,s_3_Length_Zone_004e4434);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,(int)piVar6,(int)(y2 + 2),(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    TVar7.data = TStack_1c.data;
  }
  else {
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 10;
    _DAT_004fe81c = 0x28;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x82;
    DAT_004feccc = 0x82;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc500),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),1,1,DAT_004fe2a8,0);
    _DAT_00522ffc = 0xffffffff;
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 0x14;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x5f;
    _DAT_004fecd4 = 0x5f;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc508),3,1,DAT_004fe2a8,0);
    iVar4 = DAT_005228f4 - DAT_005228e0;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 0x1e;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x6e;
    DAT_004fecd0 = 0x6e;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),2,1,DAT_004fe2a8,0);
    TVar7.data = (char *)(longlong)(_DAT_005230b0 * _DAT_004ccbe8);
    piVar6 = (int *)((iVar4 * 2) / 3 + DAT_005228f4);
  }
  FUN_0043faa0(original_dc,piVar6,TVar7.data,4,1);
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_005350dc = 0;
  DAT_004f71c4 = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


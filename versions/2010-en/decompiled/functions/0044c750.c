
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044c750(int *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  int *original_dc;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_20;
  int local_1c;
  Tact2010CString local_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4008;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar3;
  if (DAT_004fe624 < 700) {
    local_20 = 0x10;
    local_1c = 0x16;
    local_18[0].data = &DAT_00000005;
  }
  else {
    local_1c = 0x1b;
    local_20 = 0x14;
    local_18[0].data = (char *)0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Same_tack__overlapped__Windward_b_004e42f8);
  iVar4 = *original_dc;
  uStack_4 = 0;
  pcVar1 = *(code **)(iVar4 + 100);
  (*pcVar1)(original_dc,0x14,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar4 + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_L_and_W_overlap_because_W_s_bow_i_004e42a4);
  uStack_4 = 1;
  (*pcVar1)(original_dc,0xe,local_1c + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = local_1c + 2 + local_20;
  FUN_004b0613((Tact2010CString *)&param_1,s_L_may_alter_course_toward_the_wi_004e4248);
  uStack_4 = 2;
  (*pcVar1)(original_dc,0xe,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_W2_and_L2_overlap__W2_must_keep_c_004e41ec);
  uStack_4 = 3;
  (*pcVar1)(original_dc,0xe,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_20;
  FUN_004b0613((Tact2010CString *)&param_1,s_above_her_proper_course_while_wi_004e4190);
  uStack_4 = 4;
  (*pcVar1)(original_dc,0xe,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "Proper course is the course a boat would sail to finish as soon as possible without the other boats covered by this rule."
              );
  uStack_4 = 5;
  (*pcVar1)(original_dc,0xe,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_20;
  FUN_004b0613((Tact2010CString *)&param_1,s_When_choosing_a_proper_course__a_004e40dc);
  uStack_4 = 6;
  (*pcVar1)(original_dc,0xe,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s__004e4098);
  uStack_4 = 7;
  (*pcVar1)(original_dc,0xe,local_20 + iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_00463df0(original_dc,(int)local_18[0].data,local_20);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0044ca34;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0044ca34;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0044ca34:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,local_20);
  if (DAT_004fb9b4 == 0) {
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004ccbc8);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar2 = DAT_004fe624 / 0xe;
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x5a;
    DAT_004feccc = 0x5a;
    DAT_00522ff4 = 0xffffffff;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    FUN_00417aa0(original_dc,iVar4,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(local_18,s_Boat_W__Windward_004e4084);
    uStack_4 = 8;
    (*pcVar1)(original_dc,iVar4 + iVar2 * -2 + -3,(int)param_1 + local_20,local_18[0].data,
              *(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc518);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004ccbd0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fe820 = 0x14;
    iVar2 = DAT_004fe624 / 0xe;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x5a;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,iVar4,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(local_18,s_Boat_L__Leeward_004e4074);
    uStack_4 = 9;
    (*pcVar1)(original_dc,iVar4 - iVar2,(int)param_1 + local_20,local_18[0].data,
              *(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
    (**(code **)(*original_dc + 0x2c))(original_dc,7);
    FUN_004b4d9d(original_dc,(int *)local_18,DAT_005228e0,DAT_005229e0 - DAT_004fe2a8 / 3);
    CDC::LineTo(original_dc,DAT_005228e0,DAT_005229e0);
    FUN_004b0613((Tact2010CString *)&param_1,s_Overlap_Line_004e4064);
    uStack_4 = 10;
    (*pcVar1)(original_dc,DAT_005228e0,DAT_005229e0 - DAT_004fe2a8 / 3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc738);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar2 = DAT_004fe624 / 0xe;
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x5a;
    DAT_004feccc = 0x5a;
    DAT_00522ff4 = 0xffffffff;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    FUN_00417aa0(original_dc,iVar4,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(local_18,s_Boat_W2__Windward_004e4050);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,iVar2 + iVar4,(int)param_1 + local_20,local_18[0].data,
              *(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004ccbd0);
    iVar2 = DAT_004fe624 / 0xe;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x5a;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,iVar4,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(local_18,s_Boat_L2__Leeward_004e403c);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,iVar4 - iVar2,(int)param_1 + local_20,local_18[0].data,
              *(int *)(local_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_18);
  }
  if (DAT_004fb9b4 == 1) {
    _DAT_004fe81c = 2;
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 0xf;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x23;
    DAT_004feccc = 0x23;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004ccbd8),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 5;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x2d;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc8c0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccbd0),2,1,DAT_004fe2a8,0);
    DAT_00535744 = 0x5a;
    DAT_004feccc = 0x5a;
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc6c0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x5a;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc600),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccbd0),2,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_004f71c4 = uStack_10;
  DAT_00536458 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044c0f0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  int *original_dc;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_18;
  Tact2010CString local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c3f88;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar3;
  if (DAT_004fe624 < 700) {
    iVar4 = 0x10;
    local_18 = 0x16;
    local_14.data = &DAT_00000005;
  }
  else {
    iVar4 = 0x14;
    local_18 = 0x1b;
    local_14.data = (char *)0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Opposite_tacks__Port_tack_must_k_004e4004);
  iVar5 = *original_dc;
  uStack_4 = 0;
  pcVar1 = *(code **)(iVar5 + 100);
  (*pcVar1)(original_dc,0x14,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar5 + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Boat_P_must_bear_off_and_pass_as_004e3fb4);
  uStack_4 = 1;
  (*pcVar1)(original_dc,0xe,local_18 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = local_18 + 2 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_Exception__Rounding_a_downwind_m_004e3f8c);
  uStack_4 = 2;
  (*pcVar1)(original_dc,0xe,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_If_boat_P_tacks__she_must_keep_c_004e3f2c);
  uStack_4 = 3;
  (*pcVar1)(original_dc,0xe,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_on_a_closehauled_course__Rule_13_004e3ecc);
  uStack_4 = 4;
  (*pcVar1)(original_dc,0xe,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_acquires_right_of_way_must_initi_004e3e6c);
  uStack_4 = 5;
  (*pcVar1)(original_dc,0xe,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_If_a_right_of_way_boat_alters_co_004e3e00);
  uStack_4 = 6;
  (*pcVar1)(original_dc,0xe,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_004b0613((Tact2010CString *)&param_1,s_keep_clear__Rule_16_1___After_th_004e3d94);
  uStack_4 = 7;
  (*pcVar1)(original_dc,0xe,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_not_alter_course_so_that_P_would_004e3d34);
  uStack_4 = 8;
  (*pcVar1)(original_dc,0xe,iVar4 + iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_00463df0(original_dc,(int)local_14.data,iVar4);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0044c3fc;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0044c3fc;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0044c3fc:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,iVar4);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  if (DAT_004fb9b4 == 0) {
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar2 = DAT_004fe624 / 10;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar5,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&local_14,s_Boat_S__Starboard_Tack_004e3d1c);
    uStack_4 = 9;
    (*pcVar1)(original_dc,iVar5 - iVar2,(int)param_1 + iVar4,local_14.data,
              *(int *)(local_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_14);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fe820 = 2;
    iVar2 = DAT_004fe624 / 0xe;
    DAT_004fdff0 = 0x3c;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x2d;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar5,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&local_14,s_Boat_P__Port_Tack_004e3d08);
    uStack_4 = 10;
    (*pcVar1)(original_dc,iVar5 - iVar2,(int)param_1 + iVar4,local_14.data,
              *(int *)(local_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_14);
  }
  else {
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc668),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x78;
    DAT_004fecd0 = 0x78;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc770),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),2,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_004f71c4 = uStack_10;
  DAT_00536458 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


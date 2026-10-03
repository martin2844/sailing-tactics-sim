
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044eb90(int *param_1)

{
  double dVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC pHVar6;
  HGDIOBJ pvVar7;
  int local_20;
  int local_1c;
  int local_18 [2];
  code *pcStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar1 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c41e8;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar1;
  if (DAT_004fe624 < 700) {
    iVar3 = 0x10;
    local_20 = 0x16;
    local_1c = 0x10;
    local_18[0] = 5;
  }
  else {
    local_20 = 0x1b;
    local_1c = 0x14;
    local_18[0] = 0x14;
    iVar3 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Room_to_tack_at_obstructions__Ru_004e4fac);
  uStack_4 = 0;
  pcVar4 = *(code **)(*original_dc + 100);
  pcStack_10 = pcVar4;
  (*pcVar4)(original_dc,0x14,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_When_a_closehauled_boat_must_alt_004e4f4c);
  uStack_4 = 1;
  (*pcVar4)(original_dc,0x14,local_20 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = local_20 + 2 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_hitting_another_boat_on_the_same_004e4f04);
  uStack_4 = 2;
  (*pcVar4)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f7f);
  }
  iVar5 = iVar5 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_However__she_shall_not_hail_unle_004e4e98);
  uStack_4 = 3;
  (*pcVar4)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_20;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "After L hails Room to Tack, W must tack immediately or immediately reply You Tack. In that case,"
              );
  uStack_4 = 4;
  (*pcVar4)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,
               "W must keep clear of L. L must tack as soon as W replies or");
  uStack_4 = 5;
  (*pcVar4)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_W_tacks__L_must_give_W_time_to_r_004e4da8);
  uStack_4 = 6;
  (*pcVar4)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_20;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "Exception: If the obstruction is a mark W is about to round, such as a committee boat or its anchor line,"
              );
  uStack_4 = 7;
  (*pcVar4)(original_dc,0x14,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_L_is_not_entitled_to_hail_for_ro_004e4d0c);
  uStack_4 = 8;
  (*pcVar4)(original_dc,0x14,iVar3 + iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_00463df0(original_dc,local_18[0],iVar3);
  pcVar4 = SelectObject_exref;
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004fc15c);
    }
  }
  else if (DAT_005230cc != (HGDIOBJ)0x0) {
    SelectObject((HDC)original_dc[1],DAT_005230cc);
    pcVar4 = SelectObject_exref;
  }
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  if (DAT_005363e4 == 0) {
    if (DAT_004f4a5c != (HGDIOBJ)0x0) {
      pHVar6 = (HDC)original_dc[1];
      pvVar7 = DAT_004f4a5c;
override_prt_44ef45_6059bb06:
      (*pcVar4)(pHVar6,pvVar7);
    }
  }
  else if (DAT_004f3f5c != (HGDIOBJ)0x0) {
    pHVar6 = (HDC)original_dc[1];
    pvVar7 = DAT_004f3f5c;
    goto override_prt_44ef45_6059bb06;
  }
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8 / 10 + DAT_004faf7c);
  iVar3 = DAT_004fe2a8 - DAT_004faf7c;
  if (DAT_004fe07c != (HGDIOBJ)0x0) {
    (*pcVar4)((HDC)original_dc[1],DAT_004fe07c);
  }
  _DAT_004f6e28 = 0;
  _DAT_004f6e50 = 0;
  _DAT_004f6e2c = (int *)(DAT_004fe2a8 / 10 + DAT_004faf7c);
  _DAT_004f6e30 = DAT_004fe624 / 9;
  _DAT_004f6e38 = (int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3;
  iVar5 = (iVar3 * 2) / 5;
  _DAT_004f6e3c = DAT_004faf7c + iVar5;
  iVar2 = (iVar3 * 3) / 5;
  _DAT_004f6e44 = DAT_004faf7c + iVar2;
  _DAT_004f6e48 = DAT_004fe624 / 10;
  iVar3 = (iVar3 * 4) / 5;
  _DAT_004f6e4c = DAT_004faf7c + iVar3;
  _DAT_004f6e54 = DAT_004fe2a8 + 200;
  _DAT_004f6e34 = _DAT_004f6e2c;
  _DAT_004f6e40 = _DAT_004f6e30;
  Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,6);
  if (DAT_005363e4 == 0) {
    if (DAT_004fb244 == (HGDIOBJ)0x0) goto LAB_0044f0f0;
    pHVar6 = (HDC)original_dc[1];
    pvVar7 = DAT_004fb244;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0044f0f0;
    pHVar6 = (HDC)original_dc[1];
    pvVar7 = DAT_005230cc;
  }
  SelectObject(pHVar6,pvVar7);
LAB_0044f0f0:
  _DAT_004f6e28 = 0;
  _DAT_004f6e2c = (int *)(DAT_004fe2a8 / 10 + DAT_004faf7c);
  _DAT_004f6e50 = 0xfffffff6;
  local_18[0] = DAT_004fe624 / 9;
  _DAT_004f6e30 = local_18[0] + -2;
  _DAT_004f6e38 = ((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3) + -4;
  _DAT_004f6e40 = local_18[0] + -6;
  _DAT_004f6e3c = DAT_004faf7c + iVar5;
  _DAT_004f6e44 = DAT_004faf7c + iVar2;
  _DAT_004f6e4c = DAT_004faf7c + iVar3;
  _DAT_004f6e48 = DAT_004fe624 / 10 + -8;
  _DAT_004f6e54 = DAT_004fe2a8 + 200;
  _DAT_004f6e34 = _DAT_004f6e2c;
  param_1 = _DAT_004f6e2c;
  Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,6);
  (**(code **)(*original_dc + 0x2c))(original_dc,6);
  FUN_004b4d9d(original_dc,local_18,DAT_004fe624 / 9,DAT_004fe2a8 / 10 + DAT_004faf7c);
  CDC::LineTo(original_dc,(int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U)) >> 3,
              DAT_004faf7c + iVar5);
  CDC::LineTo(original_dc,DAT_004fe624 / 9,DAT_004faf7c + iVar2);
  CDC::LineTo(original_dc,DAT_004fe624 / 10,DAT_004faf7c + iVar3);
  CDC::LineTo(original_dc,0,DAT_004fe2a8 + 200);
  DAT_00536458 = 2;
  local_18[0] = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,local_1c);
  if (DAT_004fb9b4 == 0) {
    iVar3 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar2 = DAT_004fe624 / 0xf;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar3,iVar5,1,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_W_004e4d04);
    uStack_4 = 9;
    (*pcStack_10)(original_dc,iVar2 + iVar3,iVar5 + 4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar3 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar2 = DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar3,iVar5,2,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_L_Hail___ROOM_TO_TACK__004e4ce8);
    uStack_4 = 10;
    (*pcStack_10)(original_dc,iVar3 - (iVar2 >> 3),iVar5 + 4 + local_1c,(char *)param_1,param_1[-2])
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  else {
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x32;
    DAT_004feccc = 0x32;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc8c0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x19;
    DAT_004fecd0 = 0x19;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc518),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),2,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_005350dc = 0;
  DAT_004f71c4 = local_18[0];
  *unaff_FS_OFFSET = uStack_c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045cff0(int *param_1)

{
  int iVar1;
  double dVar2;
  int *original_dc;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_30;
  int local_2c;
  Tact2010CString local_20;
  Tact2010CString TStack_1c;
  code *pcStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc778;
  pcStack_8 = FUN_004c5060;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
    local_30 = 0x10;
    local_2c = 0x16;
    iVar7 = 5;
  }
  else {
    iVar7 = 0x14;
    local_2c = 0x1b;
    local_30 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613(&local_20,s___WIND_INTERFERENCE_FROM_OTHER_B_004e9d84);
  uStack_4 = 0;
  param_1 = *(int **)(*original_dc + 100);
  (*(code *)param_1)(original_dc,iVar7,2,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&local_20,s_Downwind_of_a_sail_is_reduced_an_004e9d20);
  uStack_4 = 1;
  (*(code *)param_1)(original_dc,iVar7,local_2c + 2,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  iVar8 = local_2c + 2 + local_30;
  FUN_004b0613(&local_20,s_speed__Boats_B_and_D_are_blanket_004e9cc0);
  uStack_4 = 2;
  (*(code *)param_1)(original_dc,iVar7,iVar8,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  iVar8 = iVar8 + local_30;
  FUN_004b0613(&local_20,s_from_a_windward_boat__Blanket_zo_004e9c60);
  uStack_4 = 3;
  (*(code *)param_1)(original_dc,iVar7,iVar8,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  iVar8 = iVar8 + local_2c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613(&local_20,s_Blanket_zones_align_with_the_app_004e9c14);
  uStack_4 = 4;
  (*(code *)param_1)(original_dc,iVar7,iVar8,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  iVar8 = iVar8 + local_30;
  FUN_004b0613(&local_20,s_If_your_masthead_fly_points_at_a_004e9bd0);
  uStack_4 = 5;
  (*(code *)param_1)(original_dc,iVar7,iVar8,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  iVar8 = iVar8 + local_2c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&local_20,s_When_a_boat_is_beating__a_zone_o_004e9b70);
  uStack_4 = 6;
  (*(code *)param_1)(original_dc,iVar7,iVar8,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  iVar8 = iVar8 + local_30;
  FUN_004b0613(&local_20,s_this_zone__such_as_Boat_E__has_t_004e9b14);
  uStack_4 = 7;
  (*(code *)param_1)(original_dc,iVar7,iVar8,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  iVar8 = iVar8 + local_30;
  FUN_004b0613(&local_20,s_boat_will_eventually_fall_into_t_004e9ac8);
  uStack_4 = 8;
  (*(code *)param_1)(original_dc,iVar7,iVar8,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613(&local_20,s_A_blanketed_or_backwinded_boat_i_004e9a68);
  uStack_4 = 9;
  (*(code *)param_1)(original_dc,iVar7,iVar8 + local_2c,local_20.data,*(int *)(local_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_20);
  FUN_00463df0(original_dc,iVar7,local_30);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0045d381;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0045d381;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0045d381:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,local_30);
  uStack_10 = DAT_004f71c4;
  DAT_00536458 = 2;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  if (DAT_004fb9b4 == 0) {
    DAT_00523590 = DAT_004da190;
    DAT_005362d4 = 0;
    DAT_00522dc8 = DAT_005363b8;
    DAT_00511384 = DAT_005363c0;
    _DAT_004f4a50 = DAT_005363bc;
    DAT_004da190 = 6;
    DAT_005363b8 = 0;
    DAT_005363c0 = 0;
    DAT_005363bc = 0;
    DAT_005350dc = 1;
    DAT_005350e0 = 1;
    iVar7 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0);
    iVar8 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc28);
    iVar4 = DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U);
    _DAT_004f6e50 = (int)(longlong)(_DAT_005230e8 * _DAT_004ccc38);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc640);
    _DAT_004f6e34 = iVar5 + iVar8 + iVar5 * 2;
    _DAT_004f6e28 = iVar7 - _DAT_004f6e50;
    _DAT_004f6e38 = (char *)(((_DAT_004f6e50 * 3) / 2 + iVar7) - _DAT_004f6e50 / 2);
    _DAT_004f6e3c = (char *)(iVar8 + iVar5 * 4);
    TStack_1c.data = (char *)(_DAT_004f6e50 * 2);
    _DAT_004f6e40 = (char *)((_DAT_004f6e50 * 6) / 2 + iVar7 + _DAT_004f6e50 / 2);
    _DAT_004f6e48 = _DAT_004f6e50 * 3 + iVar7;
    _DAT_004f6e50 = _DAT_004f6e50 + iVar7;
    pcStack_18 = *(code **)(*original_dc + 0x2c);
    _DAT_004f6e2c = iVar8;
    _DAT_004f6e30 = iVar7;
    _DAT_004f6e44 = _DAT_004f6e3c;
    _DAT_004f6e4c = _DAT_004f6e34;
    _DAT_004f6e54 = iVar8;
    local_20.data = _DAT_004f6e3c;
    (*pcStack_18)(original_dc,4);
    Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,6);
    FUN_004b0613(&local_20,"Blanket Zone");
    piVar3 = param_1;
    uStack_4 = 10;
    (*(code *)param_1)(original_dc,(int)(TStack_1c.data + iVar7),iVar5 + iVar8,local_20.data,
                       *(int *)(local_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_20);
    _DAT_004fe81c = 0x3c;
    DAT_004fdfec = 0x3c;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0xdc;
    DAT_004feccc = 0xb4;
    FUN_00417aa0(original_dc,iVar7,iVar8,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_1c,"Boat A");
    uStack_4 = 0xb;
    (*(code *)piVar3)(original_dc,iVar7 - (iVar4 >> 3),iVar8 - local_30,TStack_1c.data,
                      *(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    iVar7 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc518);
    iVar8 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc40);
    iVar5 = DAT_004fe624 + (DAT_004fe624 >> 0x1f & 7U);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0;
    _DAT_004fe820 = 0x3c;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0xdc;
    DAT_004fecd0 = 0xb4;
    FUN_00417aa0(original_dc,iVar7,iVar8,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_1c,"Boat B");
    uStack_4 = 0xc;
    (*(code *)param_1)(original_dc,iVar7 - (iVar5 >> 3),iVar8 - local_30,TStack_1c.data,
                       *(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    iVar7 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    iVar8 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    iVar1 = DAT_004fe624 / 9;
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc528);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc530);
    _DAT_004f6e2c = iVar8 - iVar4 / 2;
    _DAT_004f6e30 = (((int)(iVar5 * 5 + (iVar5 * 5 >> 0x1f & 3U)) >> 2) - iVar5) + iVar7;
    iVar6 = iVar8 + iVar4 * 2 + iVar4;
    TStack_1c.data = (char *)(iVar5 / 2);
    local_20.data = (char *)((iVar5 * 5) / 2);
    _DAT_004f6e38 = local_20.data + (iVar7 - (int)TStack_1c.data);
    _DAT_004f6e3c = (char *)(iVar8 + iVar4 * 4);
    _DAT_004f6e40 = local_20.data + iVar7 + (int)TStack_1c.data;
    _DAT_004f6e4c = iVar8 + iVar4 * 2;
    _DAT_004f6e44 = (char *)((iVar4 * 7) / 2 + iVar8);
    _DAT_004f6e48 = (iVar5 * 10) / 3 + iVar5 + iVar7;
    _DAT_004f6e50 = iVar5 + iVar7;
    _DAT_004f6e28 = iVar7;
    _DAT_004f6e34 = iVar6;
    _DAT_004f6e54 = _DAT_004f6e2c;
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004fe07c);
    }
    Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,6);
    FUN_004b0613(&TStack_1c,s_Backwind_Zone_004e9a48);
    uStack_4 = 0xd;
    (*(code *)param_1)(original_dc,iVar5 + iVar7 + iVar5 * 2,iVar6,TStack_1c.data,
                       *(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    _DAT_004f6e50 = (int)(longlong)(_DAT_005230e8 * _DAT_004ccc38);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc638);
    _DAT_004f6e34 = iVar5 + iVar8 + iVar5 * 2;
    _DAT_004f6e28 = iVar7 - _DAT_004f6e50;
    iStack_14 = _DAT_004f6e50 * 3;
    _DAT_004f6e38 = (char *)((iStack_14 / 2 + iVar7) - _DAT_004f6e50 / 2);
    _DAT_004f6e3c = (char *)(iVar8 + iVar5 * 4);
    _DAT_004f6e48 = _DAT_004f6e50 * 3 + iVar7;
    _DAT_004f6e40 = (char *)((_DAT_004f6e50 * 6) / 2 + iVar7 + _DAT_004f6e50 / 2);
    _DAT_004f6e50 = _DAT_004f6e50 + iVar7;
    _DAT_004f6e2c = iVar8;
    _DAT_004f6e30 = iVar7;
    _DAT_004f6e44 = _DAT_004f6e3c;
    _DAT_004f6e4c = _DAT_004f6e34;
    _DAT_004f6e54 = iVar8;
    local_20.data = _DAT_004f6e3c;
    (*pcStack_18)(original_dc,4);
    Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,6);
    FUN_004b0613(&TStack_1c,"Blanket Zone");
    piVar3 = param_1;
    uStack_4 = 0xe;
    (*(code *)param_1)(original_dc,iVar7 - iStack_14,iVar5 + iVar8,TStack_1c.data,
                       *(int *)(TStack_1c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_1c);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0x19;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,iVar7,iVar8,3,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat C");
    uStack_4 = 0xf;
    (*(code *)piVar3)(original_dc,iVar7 - iVar1,iVar8 - local_30,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar7 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc738);
    iVar8 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    _DAT_00523000 = 1;
    iVar5 = DAT_004fe624 / 9;
    _DAT_004fc2d0 = 10;
    _DAT_004fe828 = 2;
    _DAT_004fdff8 = 0x3c;
    _DAT_004fb390 = 0xf;
    _DAT_00535750 = 0x13b;
    _DAT_004fecd8 = 0x2d;
    FUN_00417aa0(original_dc,iVar7,iVar8,4,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat D");
    uStack_4 = 0x10;
    (*(code *)piVar3)(original_dc,iVar7 - iVar5,iVar8 - local_30,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar7 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    iVar8 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    _DAT_00523004 = 1;
    iVar5 = DAT_004fe624 / 0x14;
    _DAT_004fc2d4 = 0xf;
    _DAT_004fe82c = 2;
    _DAT_004fdffc = 0x3c;
    _DAT_004fb394 = 0xf;
    _DAT_00535754 = 0x131;
    _DAT_004fecdc = 0x37;
    FUN_00417aa0(original_dc,iVar7,iVar8,5,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,"Boat E");
    uStack_4 = 0x11;
    (*(code *)piVar3)(original_dc,iVar5 + iVar7,iVar8 + local_30 * -2,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 1) {
    DAT_00522dc8 = DAT_005363b8;
    DAT_00523590 = DAT_004da190;
    DAT_00511384 = DAT_005363c0;
    _DAT_004f4a50 = DAT_005363bc;
    DAT_004da190 = 6;
    DAT_005363b8 = 0;
    DAT_005363c0 = 0;
    DAT_005363bc = 0;
    DAT_005350dc = 1;
    DAT_005350e0 = 1;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0;
    _DAT_004fe81c = 0x3c;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0xdc;
    DAT_004feccc = 0xb4;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc570),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccbd0),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0;
    _DAT_004fe820 = 0x3c;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0xdc;
    DAT_004fecd0 = 0xb4;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc518),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),2,1,DAT_004fe2a8,0);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0x19;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccc10),3,1,DAT_004fe2a8,0);
    _DAT_00523000 = 1;
    _DAT_004fc2d0 = 10;
    _DAT_004fe828 = 2;
    _DAT_004fdff8 = 0x3c;
    _DAT_004fb390 = 0xf;
    _DAT_00535750 = 0x13b;
    _DAT_004fecd8 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc508),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0),4,1,DAT_004fe2a8,0);
    _DAT_00523004 = 1;
    _DAT_004fc2d4 = 0xf;
    _DAT_004fe82c = 2;
    _DAT_004fdffc = 0x3c;
    _DAT_004fb394 = 0xf;
    _DAT_00535754 = 0x13b;
    _DAT_004fecdc = 0x37;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc6c0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc508),5,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_004f71c4 = uStack_10;
  DAT_005363b8 = DAT_00522dc8;
  DAT_00536458 = 0;
  DAT_005350dc = 0;
  DAT_005350e0 = 0;
  DAT_004da190 = DAT_00523590;
  DAT_005363c0 = DAT_00511384;
  DAT_005363bc = DAT_00523590;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


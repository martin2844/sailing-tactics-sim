
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00437950(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  int iVar3;
  CDC *this;
  undefined1 *puVar4;
  int y1;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *unaff_FS_OFFSET;
  int iVar9;
  HDC hdc;
  HGDIOBJ h;
  int iStack_b8;
  int iStack_b4;
  undefined1 *puStack_ac;
  int iStack_a8;
  int iStack_a4;
  undefined4 uVar10;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  undefined1 *puStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_6c;
  int iStack_68;
  char *pcStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int aiStack_3c [2];
  CDC *pCStack_34;
  int local_1c [4];
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047ef30;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar6 = 0x10;
    local_1c[0] = 0x16;
    local_1c[1] = 5;
  }
  else {
    iVar6 = 0x14;
    local_1c[0] = 0x1b;
    local_1c[1] = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_34 = (CDC *)0x4379cc;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_34 = (CDC *)0x4379da;
  FUN_0046bf33(&param_1,s_Passing_a_racing_mark_or_an_obst_00497dc8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  pCStack_34 = param_1;
  aiStack_3c[1] = 2;
  aiStack_3c[0] = 5;
  (*pcVar1)();
  local_1c[2] = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  iStack_44 = 0x437a1a;
  FUN_0046bf33(&iStack_c,s_An_outside_boat_must_give_an_ove_00497d70);
  local_1c[2] = 1;
  iStack_44 = iStack_c;
  iStack_4c = 5;
  iStack_48 = iVar6 + 2;
  (*pcVar1)();
  FUN_0046bec5(local_1c);
  if (DAT_004ac92c == 0) {
    iStack_54 = 0x437a58;
    (**(code **)(*(int *)this + 0x38))();
  }
  iVar5 = iVar6 + 2 + aiStack_3c[0];
  iStack_54 = 0x437a6c;
  FUN_0046bf33(local_1c,s_O_must_give_room_to_I_because_th_00497d14);
  iStack_54 = local_1c[0];
  iStack_5c = 5;
  uStack_60 = 0x437a84;
  iStack_58 = iVar5;
  (*pcVar1)();
  pCStack_34 = (CDC *)0xffffffff;
  uStack_60 = 0x437a95;
  FUN_0046bec5((int *)&stack0xffffffd4);
  iVar5 = iVar5 + iVar6;
  if (DAT_004ac92c == 0) {
    uStack_60 = 0xff0000;
    pcStack_64 = (char *)0x437aac;
    (**(code **)(*(int *)this + 0x38))();
  }
  uStack_60 = 0x44;
  pcStack_64 = s_Even_if_O_was_on_starboard_tack_a_00497ccc;
  iStack_6c = 5;
  iStack_68 = iVar5;
  (*pcVar1)();
  iVar5 = iVar5 + iStack_5c;
  if (DAT_004ac92c == 0) {
    iStack_74 = 0x437ad5;
    (**(code **)(*(int *)this + 0x38))();
  }
  iStack_74 = 0x437ae3;
  FUN_0046bf33(aiStack_3c,s_O_does_not_have_to_give_room_to_A_00497c6c);
  iStack_44 = 3;
  iStack_74 = aiStack_3c[0];
  iStack_7c = 5;
  iStack_78 = iVar5;
  (*pcVar1)();
  iStack_54 = 0xffffffff;
  FUN_0046bec5(&iStack_4c);
  iVar5 = iVar5 + iVar6;
  iStack_84 = 0x437b1c;
  FUN_0046bf33(&iStack_4c,s_from_the_mark__If_A_gets_the_ove_00497c08);
  iStack_54 = 4;
  iStack_84 = iStack_4c;
  puStack_8c = &DAT_00000005;
  iStack_88 = iVar5;
  (*pcVar1)();
  pcStack_64 = (char *)0xffffffff;
  FUN_0046bec5(&iStack_5c);
  iVar5 = iVar5 + iStack_7c;
  if (DAT_004ac92c == 0) {
    iStack_94 = 0x437b60;
    (**(code **)(*(int *)this + 0x38))();
  }
  iStack_94 = 0x437b6e;
  FUN_0046bf33(&iStack_5c,s_An_obstruction_is_an_object_larg_00497ba4);
  pcStack_64 = (char *)0x5;
  iStack_94 = iStack_5c;
  iStack_9c = 5;
  iStack_98 = iVar5;
  (*pcVar1)();
  iStack_74 = 0xffffffff;
  FUN_0046bec5(&iStack_6c);
  iVar5 = iVar5 + iVar6;
  iStack_a4 = 0x437ba7;
  FUN_0046bf33(&iStack_6c,s_Moored_boats_or_right_of_way_boa_00497b40);
  iStack_74 = 6;
  iStack_a4 = iStack_6c;
  puStack_ac = &DAT_00000005;
  iStack_a8 = iVar5;
  (*pcVar1)();
  iStack_84 = 0xffffffff;
  FUN_0046bec5(&iStack_7c);
  iStack_b4 = 0x437be0;
  FUN_0046bf33(&iStack_7c,s_shoal__a_2_length_rule_does_not_a_00497adc);
  iStack_84 = 7;
  iStack_b4 = iStack_7c;
  iStack_b8 = iVar5 + iVar6;
  (*pcVar1)();
  iStack_94 = 0xffffffff;
  FUN_0046bec5((int *)&puStack_8c);
  FUN_0044d830((int *)this,iStack_a8,iVar6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00437c5c;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00437c5c;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00437c5c:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  uVar10 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)this);
  if (DAT_004a6774 == 0) {
    puStack_8c = (undefined1 *)(longlong)(_DAT_004aa7d8 * _DAT_00485300);
    puStack_ac = (undefined1 *)(DAT_004a763c / 0xe);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485058),puStack_8c,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_a8,s_Boat_A__No_Overlap_00497ac8);
    puVar4 = puStack_8c + iVar6;
    iStack_94 = 8;
    (*pcVar1)();
    iStack_a4 = 0xffffffff;
    FUN_0046bec5(&iStack_b8);
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a77f4 = 0x14;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a6344 = 0xf;
    _DAT_004a706c = 0x3c;
    _DAT_004ac024 = 0x5a;
    _DAT_004a7bd4 = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484d90),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300),3,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_9c,s_Boat_I__Inside_Overlap_00497ab0);
    iStack_a4 = 9;
    (*pcVar1)();
    iStack_b4 = 0xffffffff;
    FUN_0046bec5((int *)&puStack_ac);
    puStack_ac = (undefined1 *)(longlong)(_DAT_004aa7d8 * _DAT_00485088);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485070),puStack_ac,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff38,s_Boat_O__00497aa8);
    iStack_b4 = 10;
    iVar9 = *(int *)(puVar4 + -8);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff28);
    (**(code **)(*(int *)this + 0x2c))();
    FUN_004706bd(this,(int *)&stack0xffffff24,DAT_004aa1a0,
                 DAT_004aa2a0 - ((int)(DAT_004a72d0 + (DAT_004a72d0 >> 0x1f & 3U)) >> 2));
    CDC::LineTo(this,DAT_004aa1a0,DAT_004a72d0 / 0xf + DAT_004aa2a0);
    FUN_0046bf33(&stack0xffffff40,s_Overlap_Line_004975e4);
    iVar3 = DAT_004aa1a0;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff30);
    iVar7 = DAT_004aa1b4 - DAT_004aa1a0;
    iVar8 = iVar7 * 2;
    iVar5 = (iVar7 * 8) / 5 + DAT_004aa1b4;
    iVar6 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar7 = iVar5 + iVar7 * -2;
    y1 = iVar6 - iVar8 / 2;
    Arc(*(HDC *)(this + 4),iVar7,y1,iVar8 + iVar5,iVar8 / 2 + iVar6,iVar7,y1,iVar7,y1);
    FUN_0046bf33(&stack0xffffff14,s_Mark__Leave_to_Port_00497a94);
    (*pcVar1)(iVar5,iVar8 / 0xe + iVar6,iVar7,*(undefined4 *)(iVar7 + -8));
    FUN_0046bec5((int *)&stack0xffffff04);
    FUN_0046bf33(&stack0xffffff20,s_2_Length_Zone_00497a84);
    (*pcVar1)(iVar5,iVar3 + 2,iVar9,*(undefined4 *)(iVar9 + -8));
    iStack_94 = 0xffffffff;
    FUN_0046bec5((int *)&puStack_8c);
  }
  else {
    DAT_004aa734 = 0xffffffff;
    DAT_004ac01c = 0x82;
    DAT_004a7bcc = 0x82;
    DAT_004a6ecc = 10;
    _DAT_004a77ec = 0x28;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485308),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),1,1,DAT_004a72d0,0);
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 0x14;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x5f;
    _DAT_004a7bd4 = 0x5f;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),3,1,DAT_004a72d0,0);
    iVar5 = DAT_004aa1b4 - DAT_004aa1a0;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 0x1e;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x6e;
    DAT_004a7bd0 = 0x6e;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),2,1,DAT_004a72d0,0);
    iVar6 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00485310);
    iVar5 = (iVar5 * 2) / 3 + DAT_004aa1b4;
  }
  FUN_0042cd40((int *)this,iVar5,iVar6,4,1);
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = uVar10;
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  *unaff_FS_OFFSET = iStack_9c;
  return;
}


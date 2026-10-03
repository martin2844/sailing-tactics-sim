
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00437950(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *this;
  CDC *y2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  CDC *pCVar7;
  HDC hdc;
  HGDIOBJ h;
  int local_1c;
  LPCSTR local_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047ef30;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    uVar4 = 0x10;
    local_1c = 0x16;
    local_18[0] = &DAT_00000005;
  }
  else {
    uVar4 = 0x14;
    local_1c = 0x1b;
    local_18[0] = (LPCSTR)0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f);
  }
  FUN_0046bf33(&param_1,s_Passing_a_racing_mark_or_an_obst_00497dc8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,5,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_An_outside_boat_must_give_an_ove_00497d70);
  uStack_4 = 1;
  (*pcVar1)(this,5,uVar4 + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  iVar3 = uVar4 + 2 + local_1c;
  FUN_0046bf33(&param_1,s_O_must_give_room_to_I_because_th_00497d14);
  uStack_4 = 2;
  (*pcVar1)(this,5,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + uVar4;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  (*pcVar1)(this,5,iVar3,s_Even_if_O_was_on_starboard_tack_a_00497ccc,0x44);
  iVar3 = iVar3 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff00ff);
  }
  FUN_0046bf33(&param_1,s_O_does_not_have_to_give_room_to_A_00497c6c);
  uStack_4 = 3;
  (*pcVar1)(this,5,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + uVar4;
  FUN_0046bf33(&param_1,s_from_the_mark__If_A_gets_the_ove_00497c08);
  uStack_4 = 4;
  (*pcVar1)(this,5,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_An_obstruction_is_an_object_larg_00497ba4);
  uStack_4 = 5;
  (*pcVar1)(this,5,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + uVar4;
  FUN_0046bf33(&param_1,s_Moored_boats_or_right_of_way_boa_00497b40);
  uStack_4 = 6;
  (*pcVar1)(this,5,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_shoal__a_2_length_rule_does_not_a_00497adc);
  uStack_4 = 7;
  (*pcVar1)(this,5,iVar3 + uVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,(int)local_18[0],uVar4);
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
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,uVar4);
  if (DAT_004a6774 == 0) {
    iVar3 = (int)(longlong)(_DAT_004aa810 * _DAT_00485058);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00485300);
    iVar5 = DAT_004a763c / 0xe;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    FUN_00411000(this,iVar3,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(local_18,s_Boat_A__No_Overlap_00497ac8);
    uStack_4 = 8;
    (*pcVar1)(this,iVar3 - iVar5,(int)(param_1 + uVar4),local_18[0],*(int *)(local_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_18);
    iVar3 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    _DAT_004aa73c = 0xffffffff;
    iVar5 = DAT_004a763c / 0xe;
    _DAT_004a77f4 = 0x14;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a6344 = 0xf;
    _DAT_004a706c = 0x3c;
    _DAT_004ac024 = 0x5a;
    _DAT_004a7bd4 = 0x5a;
    FUN_00411000(this,iVar3,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300),3,1,DAT_004a72d0,
                 0);
    FUN_0046bf33(&param_1,s_Boat_I__Inside_Overlap_00497ab0);
    uStack_4 = 9;
    (*pcVar1)(this,iVar3 - (iVar5 * 3) / 2,(uVar4 * 3) / 2 + DAT_004a600c,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar3 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00485088);
    iVar5 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,iVar3,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(local_18,s_Boat_O__00497aa8);
    uStack_4 = 10;
    (*pcVar1)(this,iVar5 + iVar3,(int)(param_1 + uVar4 / 2),local_18[0],*(int *)(local_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_18);
    (**(code **)(*(int *)this + 0x2c))(this,7);
    FUN_004706bd(this,(int *)local_18,DAT_004aa1a0,
                 DAT_004aa2a0 - ((int)(DAT_004a72d0 + (DAT_004a72d0 >> 0x1f & 3U)) >> 2));
    CDC::LineTo(this,DAT_004aa1a0,DAT_004a72d0 / 0xf + DAT_004aa2a0);
    FUN_0046bf33(&param_1,s_Overlap_Line_004975e4);
    uStack_4 = 0xb;
    (*pcVar1)(this,DAT_004aa1a0,DAT_004a72d0 / 0xf + DAT_004aa2a0,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = DAT_004aa1b4 - DAT_004aa1a0;
    iVar6 = iVar5 * 2;
    iVar3 = (iVar5 * 8) / 5 + DAT_004aa1b4;
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    local_18[0] = (LPCSTR)(iVar3 + iVar5 * -2);
    iVar5 = (int)param_1 - iVar6 / 2;
    y2 = param_1 + iVar6 / 2;
    Arc(*(HDC *)(this + 4),(int)local_18[0],iVar5,iVar6 + iVar3,(int)y2,(int)local_18[0],iVar5,
        (int)local_18[0],iVar5);
    FUN_0046bf33(local_18,s_Mark__Leave_to_Port_00497a94);
    pCVar7 = param_1;
    uStack_4 = 0xc;
    (*pcVar1)(this,iVar3,(int)(param_1 + iVar6 / 0xe),local_18[0],*(int *)(local_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_18);
    FUN_0046bf33(&param_1,s_2_Length_Zone_00497a84);
    uStack_4 = 0xd;
    (*pcVar1)(this,iVar3,(int)(y2 + 2),(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
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
    iVar3 = DAT_004aa1b4 - DAT_004aa1a0;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 0x1e;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x6e;
    DAT_004a7bd0 = 0x6e;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),2,1,DAT_004a72d0,0);
    pCVar7 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00485310);
    iVar3 = (iVar3 * 2) / 3 + DAT_004aa1b4;
  }
  FUN_0042cd40((int *)this,iVar3,(int)pCVar7,4,1);
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


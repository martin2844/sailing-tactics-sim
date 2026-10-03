
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00438330(CDC *param_1)

{
  code *pcVar1;
  undefined *puVar2;
  double dVar3;
  CDC *this;
  CDC *pCVar4;
  int x1;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_20;
  int local_1c;
  LPCSTR local_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047efa8;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    iVar5 = 0x10;
    local_1c = 0x16;
    local_20 = 0x10;
    local_18 = &DAT_00000005;
  }
  else {
    local_1c = 0x1b;
    local_20 = 0x14;
    local_18 = (LPCSTR)0x14;
    iVar5 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f);
  }
  FUN_0046bf33(&param_1,s_Rounding_a_racing_mark_when_the_b_0049804c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,0x14,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_An_outside_boat_must_give_an_ove_00497ff4);
  uStack_4 = 1;
  (*pcVar1)(this,0x14,local_1c + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = local_1c + 2 + iVar5;
  FUN_0046bf33(&param_1,s_Otherwise__starboard_tack_has_ri_00497fbc);
  uStack_4 = 2;
  (*pcVar1)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  iVar6 = iVar6 + local_1c;
  FUN_0046bf33(&param_1,s_Rules_governing_I_and_S_are_the_s_00497f5c);
  uStack_4 = 3;
  (*pcVar1)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = iVar6 + iVar5;
  FUN_0046bf33(&param_1,s_P__closehauled_on_port_tack__mus_00497f20);
  uStack_4 = 4;
  (*pcVar1)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff00ff);
  }
  iVar6 = iVar6 + local_1c;
  FUN_0046bf33(&param_1,s_If_boat_P_tacks_under_I_within_t_00497ec4);
  uStack_4 = 5;
  (*pcVar1)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = iVar6 + iVar5;
  FUN_0046bf33(&param_1,s_I_or_S_have_to_head_up_to_avoid_c_00497e68);
  uStack_4 = 6;
  (*pcVar1)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_can_t_pass_and_clear_the_mark_be_00497e20);
  uStack_4 = 7;
  (*pcVar1)(this,0x14,iVar5 + iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,(int)local_18,iVar5);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00438623;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00438623;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00438623:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,iVar5);
  if (DAT_004a6774 == 0) {
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00485310);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485318);
    DAT_004aa734 = 1;
    param_1 = (CDC *)(DAT_004a763c / 0x14);
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar5,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_18,s_Boat_S__00497e18);
    uStack_4 = 8;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)(puVar2 + 4),local_18,*(int *)(local_18 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    local_18 = (LPCSTR)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    iVar6 = DAT_004a763c + (DAT_004a763c >> 0x1f & 0xfU);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar5,local_18,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_I__Inside_Overlap_00497ab0);
    uStack_4 = 9;
    (*pcVar1)(this,iVar5 - (iVar6 >> 4),(int)(local_18 + local_20 + 4),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00485320);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485328);
    param_1 = (CDC *)(DAT_004a763c / 0xf);
    _DAT_004a6ed4 = 0xf;
    _DAT_004a6344 = 0xf;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004ac024 = 0x2d;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(this,iVar5,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_18,s_Boat_P__Port_Tack_004972a0);
    uStack_4 = 10;
    (*pcVar1)(this,iVar5 - (int)param_1,(int)(puVar2 + local_20 + 4),local_18,
              *(int *)(local_18 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar7 = ((((DAT_004aa1b4 - DAT_004aa1a0) * 3) / 2) * 5) / 2;
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    (**(code **)(*(int *)this + 0x2c))(this,7);
    iStack_14 = iVar7 / 2;
    iVar6 = iVar5 - iStack_14;
    x1 = (int)param_1 - iVar7;
    Arc(*(HDC *)(this + 4),x1,iVar6,(int)(param_1 + iVar7),iStack_14 + iVar5,x1,iVar6,x1,iVar6);
    FUN_0042cd40((int *)this,(int)param_1,iVar5,3,1);
    FUN_0046bf33(&local_18,s_Mark__Leave_to_Port_00497a94);
    pCVar4 = param_1;
    uStack_4 = 0xb;
    (*pcVar1)(this,(int)param_1 - iVar7 / 0xe,(iVar5 - iVar7 / 0xd) - local_20,local_18,
              *(int *)(local_18 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    FUN_0046bf33(&param_1,s_2_Length_Zone_00497a84);
    uStack_4 = 0xc;
    (*pcVar1)(this,(int)(pCVar4 + iStack_14),iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  else {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x140;
    DAT_004a7bcc = 0x28;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485338),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485330),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300),2,1,DAT_004a72d0,0);
    FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f18),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0),3,1);
    _DAT_004ac024 = 0x5a;
    _DAT_004a7bd4 = 0x5a;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 0x14;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485340),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),3,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


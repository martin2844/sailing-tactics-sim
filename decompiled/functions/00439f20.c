
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00439f20(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  CDC *this;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_18;
  LPCSTR local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f0e0;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    iVar4 = 0x10;
    local_18 = 0x16;
    local_14 = &DAT_00000005;
  }
  else {
    iVar4 = 0x14;
    local_18 = 0x1b;
    local_14 = (LPCSTR)0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f);
  }
  FUN_0046bf33(&param_1,s_No_room_at_a_starting_mark____Ru_00498750);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,5,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_A_windward_boat_is_not_entitled_t_004986f8);
  uStack_4 = 1;
  (*pcVar1)(this,5,local_18 + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = local_18 + 2 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Windward_Boat_W_must_promptly_ke_004986ac);
  uStack_4 = 2;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_0046bf33(&param_1,s_Leeward_Boat_L_may_alter_course_p_00498658);
  uStack_4 = 3;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_After_the_starting_signal__a_lee_00498604);
  uStack_4 = 4;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_0046bf33(&param_1,s_may_not_sail_above_her_proper_co_004985d0);
  uStack_4 = 5;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_At_the_other_end_of_the_line__an_0049857c);
  uStack_4 = 6;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_of_way_as_a_leeward_boat__A_leew_00498528);
  uStack_4 = 7;
  (*pcVar1)(this,5,iVar4 + iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,(int)local_14,iVar4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043a20e;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043a20e;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043a20e:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,iVar4);
  FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
               (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
  FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),0,1,DAT_004a72d0,0);
  if (DAT_004a6774 == 0) {
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar2 = DAT_004a763c / 0xe;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar5,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_14,s_Boat_L_0049832c);
    uStack_4 = 8;
    (*pcVar1)(this,iVar5 - iVar2,(int)(param_1 + iVar4 + 1),local_14,*(int *)(local_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_14);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485310);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00485088);
    iVar5 = DAT_004a763c + (DAT_004a763c >> 0x1f & 0xfU);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 10;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x122;
    DAT_004a7bd0 = 0x41;
    FUN_00411000(this,iVar4,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_14,s_Boat_W_0049809c);
    uStack_4 = 9;
    (*pcVar1)(this,(iVar5 >> 4) + iVar4,(int)param_1,local_14,*(int *)(local_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_14);
  }
  else {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485350),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 1;
    _DAT_004a77f0 = 10;
    DAT_004a7068 = 0x14;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x14;
    DAT_004a7bd0 = 0x14;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484db8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485318),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = uStack_10;
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


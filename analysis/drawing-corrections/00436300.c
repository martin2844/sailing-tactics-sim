
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00436300(CDC *param_1)

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
  pcStack_8 = FUN_0047edc8;
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
  FUN_0046bf33(&param_1,s_Opposite_tacks__Port_tack_must_k_00497584);
  iVar5 = *(int *)this;
  uStack_4 = 0;
  pcVar1 = *(code **)(iVar5 + 100);
  (*pcVar1)(this,0x14,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar5 + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Boat_P_must_bear_off_and_pass_as_00497534);
  uStack_4 = 1;
  (*pcVar1)(this,0xe,local_18 + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = local_18 + 2 + iVar4;
  FUN_0046bf33(&param_1,s_Exception__Rounding_a_downwind_m_0049750c);
  uStack_4 = 2;
  (*pcVar1)(this,0xe,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + local_18;
  FUN_0046bf33(&param_1,s_If_boat_P_tacks__she_must_keep_c_004974ac);
  uStack_4 = 3;
  (*pcVar1)(this,0xe,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_0046bf33(&param_1,s_on_a_closehauled_course__Rule_13_0049744c);
  uStack_4 = 4;
  (*pcVar1)(this,0xe,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_0046bf33(&param_1,s_acquires_right_of_way_must_initi_004973ec);
  uStack_4 = 5;
  (*pcVar1)(this,0xe,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_If_a_right_of_way_boat_alters_co_0049738c);
  uStack_4 = 6;
  (*pcVar1)(this,0xe,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar4;
  FUN_0046bf33(&param_1,s_to_promptly_keep_clear__Rule_16__0049732c);
  uStack_4 = 7;
  (*pcVar1)(this,0xe,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_not_alter_course_so_that_P_would_004972cc);
  uStack_4 = 8;
  (*pcVar1)(this,0xe,iVar4 + iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,(int)local_14,iVar4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043660c;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043660c;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043660c:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,iVar4);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  if (DAT_004a6774 == 0) {
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar2 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar5,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_14,s_Boat_S__Starboard_Tack_004972b4);
    uStack_4 = 9;
    (*pcVar1)(this,iVar5 - iVar2,(int)(param_1 + iVar4),local_14,*(int *)(local_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_14);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    iVar2 = DAT_004a763c / 0xe;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar5,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_14,s_Boat_P__Port_Tack_004972a0);
    uStack_4 = 10;
    (*pcVar1)(this,iVar5 - iVar2,(int)(param_1 + iVar4),local_14,*(int *)(local_14 + -8));
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
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x78;
    DAT_004a7bd0 = 0x78;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f10),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = uStack_10;
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


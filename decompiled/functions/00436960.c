
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00436960(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  CDC *this;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_20;
  int local_1c;
  LPCSTR local_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047ee48;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    local_20 = 0x10;
    local_1c = 0x16;
    local_18[0] = &DAT_00000005;
  }
  else {
    local_1c = 0x1b;
    local_20 = 0x14;
    local_18[0] = (LPCSTR)0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f);
  }
  FUN_0046bf33(&param_1,s_Same_tack__overlapped__Windward_b_00497878);
  iVar4 = *(int *)this;
  uStack_4 = 0;
  pcVar1 = *(code **)(iVar4 + 100);
  (*pcVar1)(this,0x14,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar4 + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_L_and_W_overlap_because_W_s_bow_i_00497824);
  uStack_4 = 1;
  (*pcVar1)(this,0xe,local_1c + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = local_1c + 2 + local_20;
  FUN_0046bf33(&param_1,s_L_may_alter_course_toward_the_wi_004977c8);
  uStack_4 = 2;
  (*pcVar1)(this,0xe,iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_W2_and_L2_overlap__W2_must_keep_c_0049776c);
  uStack_4 = 3;
  (*pcVar1)(this,0xe,iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_20;
  FUN_0046bf33(&param_1,s_closer_to_the_wind_than_her_prop_00497710);
  uStack_4 = 4;
  (*pcVar1)(this,0xe,iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s__Proper_course__is_the_course_a_b_004976b0);
  uStack_4 = 5;
  (*pcVar1)(this,0xe,iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_20;
  FUN_0046bf33(&param_1,s_of_other_boats_referred_to_in_th_0049765c);
  uStack_4 = 6;
  (*pcVar1)(this,0xe,iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_referred_to_in_the_applicable_ru_00497618);
  uStack_4 = 7;
  (*pcVar1)(this,0xe,local_20 + iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,(int)local_18[0],local_20);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00436c44;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00436c44;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00436c44:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,local_20);
  if (DAT_004a6774 == 0) {
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar2 = DAT_004a763c / 0xe;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    FUN_00411000(this,iVar4,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(local_18,s_Boat_W__Windward_00497604);
    uStack_4 = 8;
    (*pcVar1)(this,iVar4 + iVar2 * -2 + -3,(int)(param_1 + local_20),local_18[0],
              *(int *)(local_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_18);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 0x14;
    iVar2 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,iVar4,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(local_18,s_Boat_L__Leeward_004975f4);
    uStack_4 = 9;
    (*pcVar1)(this,iVar4 - iVar2,(int)(param_1 + local_20),local_18[0],*(int *)(local_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_18);
    (**(code **)(*(int *)this + 0x2c))(this,7);
    FUN_004706bd(this,(int *)local_18,DAT_004aa1a0,DAT_004aa2a0 - DAT_004a72d0 / 3);
    CDC::LineTo(this,DAT_004aa1a0,DAT_004aa2a0);
    FUN_0046bf33(&param_1,s_Overlap_Line_004975e4);
    uStack_4 = 10;
    (*pcVar1)(this,DAT_004aa1a0,DAT_004aa2a0 - DAT_004a72d0 / 3,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar2 = DAT_004a763c / 0xe;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    FUN_00411000(this,iVar4,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(local_18,s_Boat_W2__Windward_004975d0);
    uStack_4 = 0xb;
    (*pcVar1)(this,iVar2 + iVar4,(int)(param_1 + local_20),local_18[0],*(int *)(local_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_18);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0);
    iVar2 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,iVar4,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(local_18,s_Boat_L2__Leeward_004975bc);
    uStack_4 = 0xc;
    (*pcVar1)(this,iVar4 - iVar2,(int)(param_1 + local_20),local_18[0],*(int *)(local_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_18);
  }
  if (DAT_004a6774 == 1) {
    _DAT_004a77ec = 2;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x23;
    DAT_004a7bcc = 0x23;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852f8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 5;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485070),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),2,1,DAT_004a72d0,0);
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484e50),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = uStack_10;
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


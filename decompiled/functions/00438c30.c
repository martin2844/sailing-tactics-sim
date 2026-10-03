
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00438c30(CDC *param_1)

{
  undefined *puVar1;
  int iVar2;
  double dVar3;
  CDC *this;
  int iVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC pHVar7;
  HGDIOBJ pvVar8;
  int local_20;
  int local_1c;
  int local_18 [2];
  code *pcStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f010;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    iVar4 = 0x10;
    local_20 = 0x16;
    local_1c = 0x10;
    local_18[0] = 5;
  }
  else {
    local_20 = 0x1b;
    local_1c = 0x14;
    local_18[0] = 0x14;
    iVar4 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f);
  }
  FUN_0046bf33(&param_1,s_Room_to_tack_at_obstructions___R_004982f4);
  uStack_4 = 0;
  pcVar5 = *(code **)(*(int *)this + 100);
  pcStack_10 = pcVar5;
  (*pcVar5)(this,0x14,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_When_a_closehauled_boat_must_alt_00498294);
  uStack_4 = 1;
  (*pcVar5)(this,0x14,local_20 + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = local_20 + 2 + iVar4;
  FUN_0046bf33(&param_1,s_hitting_another_boat_on_the_same_0049824c);
  uStack_4 = 2;
  (*pcVar5)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  iVar6 = iVar6 + local_20;
  FUN_0046bf33(&param_1,s_After_L_hails__room_to_tack___W_m_004981f0);
  uStack_4 = 3;
  (*pcVar5)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = iVar6 + iVar4;
  FUN_0046bf33(&param_1,s__you_tack__in_which_case_W_must_k_004981bc);
  uStack_4 = 4;
  (*pcVar5)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = iVar6 + iVar4;
  FUN_0046bf33(&param_1,s_L_must_tack_as_soon_as_possible_a_0049815c);
  uStack_4 = 5;
  (*pcVar5)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = iVar6 + local_20;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Exceptions__If_the_obstruction_i_004980f8);
  uStack_4 = 6;
  (*pcVar5)(this,0x14,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_or_a_racing_mark_that_W_can_fetc_004980a4);
  uStack_4 = 7;
  (*pcVar5)(this,0x14,iVar4 + iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,local_18[0],iVar4);
  pcVar5 = SelectObject_exref;
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a6dac);
    }
  }
  else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(this + 4),DAT_004aa7f4);
    pcVar5 = SelectObject_exref;
  }
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  if (DAT_004ac92c == 0) {
    if (DAT_004a469c != (HGDIOBJ)0x0) {
      pHVar7 = *(HDC *)(this + 4);
      pvVar8 = DAT_004a469c;
override_prt_438f82_6059bb06:
      (*pcVar5)(pHVar7,pvVar8);
    }
  }
  else if (DAT_004a3efc != (HGDIOBJ)0x0) {
    pHVar7 = *(HDC *)(this + 4);
    pvVar8 = DAT_004a3efc;
    goto override_prt_438f82_6059bb06;
  }
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0 / 10 + DAT_004a600c);
  iVar4 = DAT_004a72d0 - DAT_004a600c;
  if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    (*pcVar5)(*(HDC *)(this + 4),DAT_004a70e4);
  }
  _DAT_004a4ca8 = 0;
  _DAT_004a4cd0 = 0;
  _DAT_004a4cac = (CDC *)(DAT_004a72d0 / 10 + DAT_004a600c);
  _DAT_004a4cb0 = DAT_004a763c / 9;
  _DAT_004a4cb8 = (int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 7U)) >> 3;
  iVar6 = (iVar4 * 2) / 5;
  _DAT_004a4cbc = DAT_004a600c + iVar6;
  iVar2 = (iVar4 * 3) / 5;
  _DAT_004a4cc4 = DAT_004a600c + iVar2;
  _DAT_004a4cc8 = DAT_004a763c / 10;
  iVar4 = (iVar4 * 4) / 5;
  _DAT_004a4ccc = DAT_004a600c + iVar4;
  _DAT_004a4cd4 = DAT_004a72d0 + 200;
  _DAT_004a4cb4 = _DAT_004a4cac;
  _DAT_004a4cc0 = _DAT_004a4cb0;
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a621c == (HGDIOBJ)0x0) goto LAB_0043912d;
    pHVar7 = *(HDC *)(this + 4);
    pvVar8 = DAT_004a621c;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043912d;
    pHVar7 = *(HDC *)(this + 4);
    pvVar8 = DAT_004aa7f4;
  }
  SelectObject(pHVar7,pvVar8);
LAB_0043912d:
  _DAT_004a4ca8 = 0;
  _DAT_004a4cac = (CDC *)(DAT_004a72d0 / 10 + DAT_004a600c);
  _DAT_004a4cd0 = 0xfffffff6;
  local_18[0] = DAT_004a763c / 9;
  _DAT_004a4cb0 = local_18[0] + -2;
  _DAT_004a4cb8 = ((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 7U)) >> 3) + -4;
  _DAT_004a4cc0 = local_18[0] + -6;
  _DAT_004a4cbc = DAT_004a600c + iVar6;
  _DAT_004a4cc4 = DAT_004a600c + iVar2;
  _DAT_004a4ccc = DAT_004a600c + iVar4;
  _DAT_004a4cc8 = DAT_004a763c / 10 + -8;
  _DAT_004a4cd4 = DAT_004a72d0 + 200;
  _DAT_004a4cb4 = _DAT_004a4cac;
  param_1 = _DAT_004a4cac;
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,6);
  (**(code **)(*(int *)this + 0x2c))(this,6);
  FUN_004706bd(this,local_18,DAT_004a763c / 9,DAT_004a72d0 / 10 + DAT_004a600c);
  CDC::LineTo(this,(int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 7U)) >> 3,DAT_004a600c + iVar6);
  CDC::LineTo(this,DAT_004a763c / 9,DAT_004a600c + iVar2);
  CDC::LineTo(this,DAT_004a763c / 10,DAT_004a600c + iVar4);
  CDC::LineTo(this,0,DAT_004a72d0 + 200);
  DAT_004ac994 = 2;
  local_18[0] = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,local_1c);
  if (DAT_004a6774 == 0) {
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar1 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar6 = DAT_004a763c / 0xf;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar4,puVar1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_W_0049809c);
    uStack_4 = 8;
    (*pcStack_10)(this,iVar6 + iVar4,(int)(puVar1 + 4),(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar1 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar6 = DAT_004a763c + (DAT_004a763c >> 0x1f & 7U);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar4,puVar1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_L_Hail___ROOM_TO_TACK__00498080);
    uStack_4 = 9;
    (*pcStack_10)(this,iVar4 - (iVar6 >> 3),(int)(puVar1 + local_1c + 4),(LPCSTR)param_1,
                  *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  else {
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x32;
    DAT_004a7bcc = 0x32;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485070),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x19;
    DAT_004a7bd0 = 0x19;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852e8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = local_18[0];
  *unaff_FS_OFFSET = uStack_c;
  return;
}



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
  int unaff_EDI;
  int iVar6;
  int *unaff_FS_OFFSET;
  undefined4 uVar7;
  HDC hdc;
  HGDIOBJ h;
  int iVar8;
  code *pcVar9;
  int iStack_9c;
  int iStack_98;
  code *pcVar10;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int aiStack_6c [2];
  int iStack_5c;
  int iStack_58;
  int iStack_4c;
  int iStack_48;
  int iStack_3c;
  CDC *pCStack_38;
  int local_1c [3];
  code *pcStack_10;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f010;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    iVar4 = 0x10;
    local_1c[0] = 0x10;
    local_1c[1] = 5;
  }
  else {
    local_1c[0] = 0x14;
    local_1c[1] = 0x14;
    iVar4 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_38 = (CDC *)0x438cb6;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_38 = (CDC *)0x438cc4;
  FUN_0046bf33(&param_1,s_Room_to_tack_at_obstructions___R_004982f4);
  uStack_4 = 0;
  pcVar5 = *(code **)(*(int *)this + 100);
  pCStack_38 = param_1;
  iStack_3c = 2;
  pcStack_10 = pcVar5;
  (*pcVar5)();
  local_1c[2] = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  iStack_48 = 0x438d0c;
  FUN_0046bf33(&iStack_c,s_When_a_closehauled_boat_must_alt_00498294);
  local_1c[2] = 1;
  iStack_48 = iStack_c;
  iStack_4c = unaff_EDI + 2;
  (*pcVar5)();
  FUN_0046bec5(local_1c);
  iVar6 = unaff_EDI + 2 + iVar4;
  iStack_58 = 0x438d45;
  FUN_0046bf33(local_1c,s_hitting_another_boat_on_the_same_0049824c);
  iStack_58 = local_1c[0];
  iStack_5c = iVar6;
  (*pcVar5)();
  FUN_0046bec5((int *)&stack0xffffffd4);
  if (DAT_004ac92c == 0) {
    aiStack_6c[1] = 0x438d83;
    (**(code **)(*(int *)this + 0x38))();
  }
  iVar6 = iVar6 + 0x14;
  aiStack_6c[1] = 0x438d97;
  FUN_0046bf33(&stack0xffffffd4,s_After_L_hails__room_to_tack___W_m_004981f0);
  aiStack_6c[0] = iVar6;
  (*pcVar5)();
  FUN_0046bec5(&iStack_3c);
  iVar6 = iVar6 + iVar4;
  iStack_78 = 0x438dd0;
  FUN_0046bf33(&iStack_3c,s__you_tack__in_which_case_W_must_k_004981bc);
  iStack_78 = iStack_3c;
  iStack_80 = 0x14;
  iStack_7c = iVar6;
  (*pcVar5)();
  FUN_0046bec5(&iStack_4c);
  iVar6 = iVar6 + iVar4;
  iStack_88 = 0x438e09;
  FUN_0046bf33(&iStack_4c,s_L_must_tack_as_soon_as_possible_a_0049815c);
  iStack_88 = iStack_4c;
  iStack_90 = 0x14;
  iStack_8c = iVar6;
  (*pcVar5)();
  FUN_0046bec5(&iStack_5c);
  iVar6 = iVar6 + iStack_80;
  if (DAT_004ac92c == 0) {
    iStack_98 = 0x438e4d;
    (**(code **)(*(int *)this + 0x38))();
  }
  iStack_98 = 0x438e5b;
  FUN_0046bf33(&iStack_5c,s_Exceptions__If_the_obstruction_i_004980f8);
  pcVar10 = *(code **)(iStack_5c + -8);
  iStack_98 = iStack_5c;
  iStack_9c = iVar6;
  (*pcVar5)(0x14);
  FUN_0046bec5(aiStack_6c);
  FUN_0046bf33(aiStack_6c,s_or_a_racing_mark_that_W_can_fetc_004980a4);
  pcVar9 = *(code **)(aiStack_6c[0] + -8);
  iVar8 = 0x14;
  (*pcVar5)(0x14,iVar4 + iVar6,aiStack_6c[0]);
  FUN_0046bec5(&iStack_7c);
  FUN_0044d830((int *)this,iStack_98,iVar4);
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
    if (DAT_004a469c != 0) {
      uVar7 = *(undefined4 *)(this + 4);
      iVar4 = DAT_004a469c;
LAB_00438f82:
      (*pcVar5)(uVar7,iVar4);
    }
  }
  else if (DAT_004a3efc != 0) {
    uVar7 = *(undefined4 *)(this + 4);
    iVar4 = DAT_004a3efc;
    goto LAB_00438f82;
  }
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0 / 10 + DAT_004a600c);
  iVar4 = DAT_004a72d0 - DAT_004a600c;
  if (DAT_004a70e4 != 0) {
    (*pcVar5)(*(undefined4 *)(this + 4),DAT_004a70e4);
  }
  _DAT_004a4ca8 = 0;
  _DAT_004a4cd0 = 0;
  _DAT_004a4cac = DAT_004a72d0 / 10 + DAT_004a600c;
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
    hdc = *(HDC *)(this + 4);
    h = DAT_004a621c;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043912d;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043912d:
  _DAT_004a4ca8 = 0;
  _DAT_004a4cac = DAT_004a72d0 / 10 + DAT_004a600c;
  _DAT_004a4cd0 = 0xfffffff6;
  iStack_98 = DAT_004a763c / 9;
  _DAT_004a4cb0 = iStack_98 + -2;
  _DAT_004a4cb8 = ((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 7U)) >> 3) + -4;
  _DAT_004a4cc0 = iStack_98 + -6;
  _DAT_004a4cbc = DAT_004a600c + iVar6;
  _DAT_004a4cc4 = DAT_004a600c + iVar2;
  _DAT_004a4ccc = DAT_004a600c + iVar4;
  _DAT_004a4cc8 = DAT_004a763c / 10 + -8;
  _DAT_004a4cd4 = DAT_004a72d0 + 200;
  _DAT_004a4cb4 = _DAT_004a4cac;
  iStack_7c = _DAT_004a4cac;
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,6);
  (**(code **)(*(int *)this + 0x2c))(6);
  FUN_004706bd(this,&iStack_9c,DAT_004a763c / 9,DAT_004a72d0 / 10 + DAT_004a600c);
  CDC::LineTo(this,(int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 7U)) >> 3,DAT_004a600c + iVar6);
  CDC::LineTo(this,DAT_004a763c / 9,DAT_004a600c + iVar2);
  CDC::LineTo(this,DAT_004a763c / 10,DAT_004a600c + iVar4);
  CDC::LineTo(this,0,DAT_004a72d0 + 200);
  DAT_004ac994 = 2;
  iStack_9c = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)this);
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
    FUN_0046bf33(&iStack_80,s_Boat_W_0049809c);
    iStack_88 = 8;
    (*pcVar10)(iVar6 + iVar4,puVar1 + 4,iStack_80,*(undefined4 *)(iStack_80 + -8));
    iStack_98 = 0xffffffff;
    FUN_0046bec5(&iStack_90);
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
    FUN_0046bf33(&iStack_90,s_Boat_L_Hail___ROOM_TO_TACK__00498080);
    iStack_98 = 9;
    (*pcVar9)(iVar4 - (iVar6 >> 3),puVar1 + iVar8 + 4,iStack_90,*(undefined4 *)(iStack_90 + -8));
    iStack_88 = -1;
    FUN_0046bec5(&iStack_80);
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
  DAT_004a4e8c = iStack_9c;
  *unaff_FS_OFFSET = iStack_90;
  return;
}


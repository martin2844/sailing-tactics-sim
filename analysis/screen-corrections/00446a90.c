
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00446a90(CDC *param_1)

{
  undefined *puVar1;
  int iVar2;
  double dVar3;
  CDC *this;
  CDC *pCVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_30;
  int local_2c;
  LPCSTR local_20;
  LPCSTR pCStack_1c;
  code *pcStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f18;
  pcStack_8 = FUN_0047fe20;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    local_30 = 0x10;
    local_2c = 0x16;
    iVar7 = 5;
  }
  else {
    iVar7 = 0x14;
    local_2c = 0x1b;
    local_30 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&local_20,s___WIND_INTERFERENCE_FROM_OTHER_B_0049cd8c);
  uStack_4 = 0;
  param_1 = *(CDC **)(*(int *)this + 100);
  (*(code *)param_1)(this,iVar7,2,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&local_20,s_Downwind_of_a_sail_is_reduced_an_0049cd28);
  uStack_4 = 1;
  (*(code *)param_1)(this,iVar7,local_2c + 2,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  iVar8 = local_2c + 2 + local_30;
  FUN_0046bf33(&local_20,s_speed__Boats_B_and_D_are_blanket_0049ccc8);
  uStack_4 = 2;
  (*(code *)param_1)(this,iVar7,iVar8,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  iVar8 = iVar8 + local_30;
  FUN_0046bf33(&local_20,s_from_a_windward_boat__Blanket_zo_0049cc68);
  uStack_4 = 3;
  (*(code *)param_1)(this,iVar7,iVar8,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  iVar8 = iVar8 + local_2c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&local_20,s_Blanket_zones_align_with_the_app_0049cc1c);
  uStack_4 = 4;
  (*(code *)param_1)(this,iVar7,iVar8,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  iVar8 = iVar8 + local_30;
  FUN_0046bf33(&local_20,s_If_your_masthead_fly_points_at_a_0049cbd8);
  uStack_4 = 5;
  (*(code *)param_1)(this,iVar7,iVar8,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  iVar8 = iVar8 + local_2c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&local_20,s_When_a_boat_is_beating__a_zone_o_0049cb78);
  uStack_4 = 6;
  (*(code *)param_1)(this,iVar7,iVar8,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  iVar8 = iVar8 + local_30;
  FUN_0046bf33(&local_20,s_this_zone__such_as_Boat_E__has_t_0049cb1c);
  uStack_4 = 7;
  (*(code *)param_1)(this,iVar7,iVar8,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  iVar8 = iVar8 + local_30;
  FUN_0046bf33(&local_20,s_boat_will_eventually_fall_into_t_0049cad0);
  uStack_4 = 8;
  (*(code *)param_1)(this,iVar7,iVar8,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&local_20,s_A_blanketed_or_backwinded_boat_i_0049ca70);
  uStack_4 = 9;
  (*(code *)param_1)(this,iVar7,iVar8 + local_2c,local_20,*(int *)(local_20 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_20);
  FUN_0044d830((int)this,iVar7,local_30);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00446e21;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00446e21;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00446e21:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,local_30);
  uStack_10 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  if (DAT_004a6774 == 0) {
    DAT_004aa990 = DAT_00491188;
    DAT_004ac840 = 0;
    DAT_004aa650 = DAT_004ac900;
    DAT_004a8684 = DAT_004ac908;
    _DAT_004a4694 = DAT_004ac904;
    DAT_00491188 = 6;
    DAT_004ac900 = 0;
    DAT_004ac908 = 0;
    DAT_004ac904 = 0;
    DAT_004abb74 = 1;
    DAT_004abb78 = 1;
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar1 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485368);
    iVar5 = DAT_004a763c + (DAT_004a763c >> 0x1f & 7U);
    _DAT_004a4cd0 = (int)(longlong)(_DAT_004aa810 * _DAT_00485378);
    iVar8 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00485380);
    _DAT_004a4cb4 = puVar1 + iVar8 * 3;
    _DAT_004a4ca8 = iVar7 - _DAT_004a4cd0;
    _DAT_004a4cb8 = (LPCSTR)(((_DAT_004a4cd0 * 3) / 2 + iVar7) - _DAT_004a4cd0 / 2);
    _DAT_004a4cbc = puVar1 + iVar8 * 4;
    pCStack_1c = (LPCSTR)(_DAT_004a4cd0 * 2);
    _DAT_004a4cc0 = (LPCSTR)((_DAT_004a4cd0 * 6) / 2 + iVar7 + _DAT_004a4cd0 / 2);
    _DAT_004a4cc8 = _DAT_004a4cd0 * 3 + iVar7;
    _DAT_004a4cd0 = _DAT_004a4cd0 + iVar7;
    pcStack_18 = *(code **)(*(int *)this + 0x2c);
    _DAT_004a4cac = puVar1;
    _DAT_004a4cb0 = iVar7;
    _DAT_004a4cc4 = _DAT_004a4cbc;
    _DAT_004a4ccc = _DAT_004a4cb4;
    _DAT_004a4cd4 = puVar1;
    local_20 = _DAT_004a4cbc;
    (*pcStack_18)(this,4);
    Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,6);
    FUN_0046bf33(&local_20,s_Blanket_Zone_0049ca60);
    pCVar4 = param_1;
    uStack_4 = 10;
    (*(code *)param_1)(this,(int)(pCStack_1c + iVar7),(int)(puVar1 + iVar8),local_20,
                       *(int *)(local_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_20);
    _DAT_004a77ec = 0x3c;
    DAT_004a7064 = 0x3c;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0xdc;
    DAT_004a7bcc = 0xb4;
    FUN_00411000(this,iVar7,puVar1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_1c,s_Boat_A_004994e4);
    uStack_4 = 0xb;
    (*(code *)pCVar4)(this,iVar7 - (iVar5 >> 3),(int)puVar1 - local_30,pCStack_1c,
                      *(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    puVar1 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485388);
    iVar8 = DAT_004a763c + (DAT_004a763c >> 0x1f & 7U);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0;
    _DAT_004a77f0 = 0x3c;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0xdc;
    DAT_004a7bd0 = 0xb4;
    FUN_00411000(this,iVar7,puVar1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_1c,s_Boat_B_004994ec);
    uStack_4 = 0xc;
    (*(code *)param_1)(this,iVar7 - (iVar8 >> 3),(int)puVar1 - local_30,pCStack_1c,
                       *(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar1 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar2 = DAT_004a763c / 9;
    iVar8 = (int)(longlong)(_DAT_004aa810 * _DAT_00484df8);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00485390);
    _DAT_004a4cac = (undefined *)((int)puVar1 - iVar5 / 2);
    _DAT_004a4cb0 = (((int)(iVar8 * 5 + (iVar8 * 5 >> 0x1f & 3U)) >> 2) - iVar8) + iVar7;
    puVar6 = puVar1 + iVar5 * 3;
    pCStack_1c = (LPCSTR)(iVar8 / 2);
    local_20 = (LPCSTR)((iVar8 * 5) / 2);
    _DAT_004a4cb8 = local_20 + (iVar7 - (int)pCStack_1c);
    _DAT_004a4cbc = puVar1 + iVar5 * 4;
    _DAT_004a4cc0 = pCStack_1c + (int)(local_20 + iVar7);
    _DAT_004a4ccc = puVar1 + iVar5 * 2;
    _DAT_004a4cc4 = puVar1 + (iVar5 * 7) / 2;
    _DAT_004a4cc8 = (iVar8 * 10) / 3 + iVar8 + iVar7;
    _DAT_004a4cd0 = iVar8 + iVar7;
    _DAT_004a4ca8 = iVar7;
    _DAT_004a4cb4 = puVar6;
    _DAT_004a4cd4 = _DAT_004a4cac;
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a70e4);
    }
    Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,6);
    FUN_0046bf33(&pCStack_1c,s_Backwind_Zone_0049ca50);
    uStack_4 = 0xd;
    (*(code *)param_1)(this,iVar8 + iVar7 + iVar8 * 2,(int)puVar6,pCStack_1c,
                       *(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    _DAT_004a4cd0 = (int)(longlong)(_DAT_004aa810 * _DAT_00485378);
    iVar8 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e00);
    _DAT_004a4cb4 = puVar1 + iVar8 * 3;
    _DAT_004a4ca8 = iVar7 - _DAT_004a4cd0;
    iStack_14 = _DAT_004a4cd0 * 3;
    _DAT_004a4cb8 = (LPCSTR)((iStack_14 / 2 + iVar7) - _DAT_004a4cd0 / 2);
    _DAT_004a4cbc = puVar1 + iVar8 * 4;
    _DAT_004a4cc8 = _DAT_004a4cd0 * 3 + iVar7;
    _DAT_004a4cc0 = (LPCSTR)((_DAT_004a4cd0 * 6) / 2 + iVar7 + _DAT_004a4cd0 / 2);
    _DAT_004a4cd0 = _DAT_004a4cd0 + iVar7;
    _DAT_004a4cac = puVar1;
    _DAT_004a4cb0 = iVar7;
    _DAT_004a4cc4 = _DAT_004a4cbc;
    _DAT_004a4ccc = _DAT_004a4cb4;
    _DAT_004a4cd4 = puVar1;
    local_20 = _DAT_004a4cbc;
    (*pcStack_18)(this,4);
    Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,6);
    FUN_0046bf33(&pCStack_1c,s_Blanket_Zone_0049ca60);
    pCVar4 = param_1;
    uStack_4 = 0xe;
    (*(code *)param_1)(this,iVar7 - iStack_14,(int)(puVar1 + iVar8),pCStack_1c,
                       *(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0x19;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(this,iVar7,puVar1,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_C_0049ca48);
    uStack_4 = 0xf;
    (*(code *)pCVar4)(this,iVar7 - iVar2,(int)puVar1 - local_30,(LPCSTR)param_1,
                      *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    puVar1 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    _DAT_004aa740 = 1;
    iVar8 = DAT_004a763c / 9;
    _DAT_004a6ed8 = 10;
    _DAT_004a77f8 = 2;
    _DAT_004a7070 = 0x3c;
    _DAT_004a6348 = 0xf;
    _DAT_004ac028 = 0x13b;
    _DAT_004a7bd8 = 0x2d;
    FUN_00411000(this,iVar7,puVar1,4,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_D_0049ca40);
    uStack_4 = 0x10;
    (*(code *)pCVar4)(this,iVar7 - iVar8,(int)puVar1 - local_30,(LPCSTR)param_1,
                      *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar1 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    _DAT_004aa744 = 1;
    iVar8 = DAT_004a763c / 0x14;
    _DAT_004a6edc = 0xf;
    _DAT_004a77fc = 2;
    _DAT_004a7074 = 0x3c;
    _DAT_004a634c = 0xf;
    _DAT_004ac02c = 0x131;
    _DAT_004a7bdc = 0x37;
    FUN_00411000(this,iVar7,puVar1,5,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_E_0049ca38);
    uStack_4 = 0x11;
    (*(code *)pCVar4)(this,iVar8 + iVar7,(int)(puVar1 + local_30 * -2),(LPCSTR)param_1,
                      *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 1) {
    DAT_004aa650 = DAT_004ac900;
    DAT_004aa990 = DAT_00491188;
    DAT_004a8684 = DAT_004ac908;
    _DAT_004a4694 = DAT_004ac904;
    DAT_00491188 = 6;
    DAT_004ac900 = 0;
    DAT_004ac908 = 0;
    DAT_004ac904 = 0;
    DAT_004abb74 = 1;
    DAT_004abb78 = 1;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0;
    _DAT_004a77ec = 0x3c;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0xdc;
    DAT_004a7bcc = 0xb4;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484d48),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0;
    _DAT_004a77f0 = 0x3c;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0xdc;
    DAT_004a7bd0 = 0xb4;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852e8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),2,1,DAT_004a72d0,0);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0x19;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485338),3,1,DAT_004a72d0,0);
    _DAT_004aa740 = 1;
    _DAT_004a6ed8 = 10;
    _DAT_004a77f8 = 2;
    _DAT_004a7070 = 0x3c;
    _DAT_004a6348 = 0xf;
    _DAT_004ac028 = 0x13b;
    _DAT_004a7bd8 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484de8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50),4,1,DAT_004a72d0,0);
    _DAT_004aa744 = 1;
    _DAT_004a6edc = 0xf;
    _DAT_004a77fc = 2;
    _DAT_004a7074 = 0x3c;
    _DAT_004a634c = 0xf;
    _DAT_004ac02c = 0x13b;
    _DAT_004a7bdc = 0x37;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484e50),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),5,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = uStack_10;
  DAT_004ac900 = DAT_004aa650;
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004abb78 = 0;
  DAT_00491188 = DAT_004aa990;
  DAT_004ac908 = DAT_004a8684;
  DAT_004ac904 = DAT_004aa990;
  *unaff_FS_OFFSET = uStack_c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040f4a0(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  CDC *this;
  DWORD DVar4;
  TactCString *pTVar5;
  DWORD DVar6;
  uint uVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  bool bVar9;
  HDC hdc;
  COLORREF CVar10;
  HGDIOBJ h;
  LPCSTR pCStack_1c;
  TactCString TStack_18;
  LPCSTR pCStack_14;
  DWORD local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047deb0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_10 = GetTickCount();
  this = param_1;
  _DAT_004aa810 = (double)DAT_004a763c;
  _DAT_004aa7d8 = (double)DAT_004a72d0;
  iVar2 = DAT_004a763c / 10;
  iVar8 = *(int *)param_1;
  pcVar1 = *(code **)(iVar8 + 0x2c);
  uVar7 = (699 < DAT_004a763c) - 1 & 0xfffffff6;
  (*pcVar1)(param_1,7);
  (*pcVar1)(this,0);
  Rectangle(*(HDC *)(this + 4),0,0,DAT_004a763c,DAT_004a72d0);
  if ((0 < DAT_00491164) && (DAT_004ac9cc == 0)) {
    FUN_00410090(this);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  param_1 = *(CDC **)(iVar8 + 0x38);
  if (DAT_004ac92c == 0) {
    CVar10 = 0xff;
  }
  else {
    CVar10 = 0;
  }
  (*(code *)param_1)(this,CVar10);
  FUN_0046bf33(&pCStack_1c,s_Select_Options__Then_select_Star_00492438);
  pcVar1 = *(code **)(iVar8 + 100);
  uStack_4 = 0;
  (*pcVar1)(this,5,1,pCStack_1c,*(int *)(pCStack_1c + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_1c);
  if (DAT_004ac9ac == 0) {
    iVar8 = uVar7 + 0x3c;
  }
  else {
    iVar8 = uVar7 + 0x28;
  }
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)(this,0x7f0000);
  }
  DAT_004a5264 = (LPCSTR)GetSystemMetrics(0xf);
  TStack_18.data = DAT_004a5264;
  FUN_0046bf33(&pCStack_14,s_SAILING_TACTICS_SIMULATOR_2002_00492418);
  uStack_4 = 1;
  (*pcVar1)(this,iVar2,iVar8,pCStack_14,*(int *)(pCStack_14 + -8));
  if ((DAT_004a763c < 0x385) && (699 < DAT_004a763c)) {
    if ((int)TStack_18.data < 0x15) {
      pCStack_1c = (LPCSTR)(iVar2 + 0xe6);
    }
    else {
      pCStack_1c = (LPCSTR)(iVar2 + 0x122);
    }
  }
  if ((900 < DAT_004a763c) && (pCStack_1c = (LPCSTR)(iVar2 + 0x122), (int)TStack_18.data < 0x15)) {
    pCStack_1c = (LPCSTR)(iVar2 + 0xe6);
  }
  if (DAT_004a763c < 700) {
    pCStack_1c = (LPCSTR)(iVar2 + 0xe6);
  }
  FUN_0046bf33(&TStack_18,&DAT_00492414);
  uStack_4._0_1_ = 2;
  (*pcVar1)(this,(int)(pCStack_1c + 2),iVar8 - DAT_004a72d0 / 100,TStack_18.data,
            *(int *)(TStack_18.data + -8));
  uStack_4._0_1_ = 1;
  FUN_0046bec5((int *)&TStack_18);
  (*(code *)param_1)(this,0);
  if (DAT_004ac9ac == 1) {
    FUN_0046bf33(&TStack_18,s_Modified_for_TEKNOWLEDGE__You_co_004923c0);
    uStack_4._0_1_ = 3;
    (*pcVar1)(this,10,iVar8 + 0x14,TStack_18.data,*(int *)(TStack_18.data + -8));
    uStack_4._0_1_ = 1;
    FUN_0046bec5((int *)&TStack_18);
    if (DAT_004ac9ac == 1) {
      FUN_0046bf33(&TStack_18,s_Messages__green_background__are_G_00492364);
      uStack_4._0_1_ = 4;
      (*pcVar1)(this,10,iVar8 + 0x28,TStack_18.data,*(int *)(TStack_18.data + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&TStack_18);
    }
  }
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)(this,0x7f0000);
  }
  if (DAT_00491164 == 0) {
    FUN_0046bf33(&TStack_18,s_Release_2_00492358);
    uStack_4._0_1_ = 5;
    (*pcVar1)(this,iVar2,iVar8 + 0x14,TStack_18.data,*(int *)(TStack_18.data + -8));
  }
  else {
    FUN_0046bf33(&TStack_18,s_Demo_Version_00492348);
    uStack_4._0_1_ = 6;
    (*pcVar1)(this,iVar2,iVar8 + 0x14,TStack_18.data,*(int *)(TStack_18.data + -8));
  }
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_0046bec5((int *)&TStack_18);
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)(this,0xff0000);
  }
  FUN_0046bf33(&TStack_18,s_Copyright_C__1998_2001_by_C__Den_0049231c);
  uStack_4._0_1_ = 7;
  (*pcVar1)(this,(DAT_004a763c * 6) / 0xb,iVar8,TStack_18.data,*(int *)(TStack_18.data + -8));
  uStack_4._0_1_ = 1;
  FUN_0046bec5((int *)&TStack_18);
  (*(code *)param_1)(this,0);
  if (DAT_00491140 == 2) {
    if (DAT_004ac948 == -7) {
      FUN_0046bf33(&param_1,s_Boat_1_much_faster_00492308);
      uStack_4._0_1_ = 8;
      (*pcVar1)(this,0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac948 == -4) {
      FUN_0046bf33(&param_1,s_Boat_1_significantly_faster_004922ec);
      uStack_4._0_1_ = 9;
      (*pcVar1)(this,0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac948 == -2) {
      FUN_0046bf33(&param_1,s_Boat_1_slightly_faster_004922d4);
      uStack_4._0_1_ = 10;
      (*pcVar1)(this,0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac948 == 0) {
      FUN_0046bf33(&param_1,s_Boats_equal_speed_potential_004922b8);
      uStack_4._0_1_ = 0xb;
      (*pcVar1)(this,0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac948 == 7) {
      FUN_0046bf33(&param_1,s_Boat_2_much_faster_004922a4);
      uStack_4._0_1_ = 0xc;
      (*pcVar1)(this,0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac948 == 4) {
      FUN_0046bf33(&param_1,s_Boat_2_significantly_faster_00492288);
      uStack_4._0_1_ = 0xd;
      (*pcVar1)(this,0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac948 == 2) {
      FUN_0046bf33(&param_1,s_Boat_2_slightly_faster_00492270);
      uStack_4._0_1_ = 0xe;
      (*pcVar1)(this,0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
  }
  if (((5 < DAT_00491188) && (DAT_00491188 < 9)) && (DAT_004ac908 == 0)) {
    iVar8 = (DAT_004a72d0 * 4) / 5;
    pTVar5 = FUN_00413d00(&TStack_18,DAT_004a5ba4);
    uStack_4._0_1_ = 0xf;
    pTVar5 = FUN_0046c14f((TactCString *)&param_1,s_Length__00492264,pTVar5);
    uStack_4._0_1_ = 0x10;
    (*pcVar1)(this,10,iVar8,pTVar5->data,*(int *)(pTVar5->data + -8));
    uStack_4._0_1_ = 0xf;
    FUN_0046bec5((int *)&param_1);
    uStack_4._0_1_ = 1;
    FUN_0046bec5((int *)&TStack_18);
    if (DAT_004a4eec == 0xb) {
      FUN_0046bf33(&param_1,s_Heavy_displacement_00492250);
      uStack_4._0_1_ = 0x11;
      (*pcVar1)(this,(int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar8,(LPCSTR)param_1,
                *(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004a4eec == 10) {
      FUN_0046bf33(&param_1,s_Moderate_displacement_00492238);
      uStack_4._0_1_ = 0x12;
      (*pcVar1)(this,(int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar8,(LPCSTR)param_1,
                *(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004a4eec == 9) {
      FUN_0046bf33(&param_1,s_Light_displacement_00492224);
      uStack_4._0_1_ = 0x13;
      (*pcVar1)(this,(int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar8,(LPCSTR)param_1,
                *(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004a4eec < 9) {
      FUN_0046bf33(&param_1,s_Ultra_light_displacement_00492208);
      uStack_4._0_1_ = 0x14;
      (*pcVar1)(this,(int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar8,(LPCSTR)param_1,
                *(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004a5b90 < 10) {
      FUN_0046bf33(&param_1,s_Less_than_average_sail_004921f0);
      uStack_4._0_1_ = 0x15;
      (*pcVar1)(this,((int)(DAT_004a763c * 2 + (DAT_004a763c * 2 >> 0x1f & 3U)) >> 2) + 10,iVar8,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    bVar9 = false;
    if (DAT_004a5b90 == 10) {
      FUN_0046bf33(&param_1,s_Average_sail_area_004921dc);
      uStack_4._0_1_ = 0x16;
      (*pcVar1)(this,((int)(DAT_004a763c * 2 + (DAT_004a763c * 2 >> 0x1f & 3U)) >> 2) + 10,iVar8,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
      bVar9 = DAT_004a5b90 == 10;
    }
    if (!bVar9 && 9 < DAT_004a5b90) {
      FUN_0046bf33(&param_1,s_More_than_average_sail_004921c4);
      uStack_4._0_1_ = 0x17;
      (*pcVar1)(this,((int)(DAT_004a763c * 2 + (DAT_004a763c * 2 >> 0x1f & 3U)) >> 2) + 10,iVar8,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4._0_1_ = 1;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_00491150 < 100) {
      FUN_0046bf33(&param_1,s_Fractional_rig_004921b4);
      uStack_4._0_1_ = 0x18;
      (*pcVar1)(this,((int)(DAT_004a763c * 3 + (DAT_004a763c * 3 >> 0x1f & 3U)) >> 2) + 10,iVar8,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
    }
    else {
      FUN_0046bf33(&param_1,s_Masthead_rig_004921a4);
      uStack_4._0_1_ = 0x19;
      (*pcVar1)(this,((int)(DAT_004a763c * 3 + (DAT_004a763c * 3 >> 0x1f & 3U)) >> 2) + 10,iVar8,
                (LPCSTR)param_1,*(int *)(param_1 + -8));
    }
    uStack_4._0_1_ = 1;
    FUN_0046bec5((int *)&param_1);
  }
  dVar3 = _DAT_004a8670 * _DAT_00484d88;
  iVar8 = DAT_004a72d0 * 3;
  iVar2 = DAT_004a763c * 9;
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0040fe0b;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0040fe0b;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0040fe0b:
  RoundRect(*(HDC *)(this + 4),DAT_004a763c / 10,DAT_004a72d0 / 5,iVar2 / 10,
            ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) - (int)(longlong)dVar3,0x50,0x50);
  DAT_004ac994 = 1;
  TStack_18.data = DAT_004a4e8c;
  DAT_004a4e8c = (char *)0x2;
  _DAT_004a6834 = 0;
  FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484d98),
               (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d90),4,1);
  _DAT_004a77ec = 2;
  DAT_004aa734 = 1;
  DAT_004a6ecc = 0xf;
  DAT_004a7064 = 0x3c;
  DAT_004a633c = 0xf;
  DAT_004ac01c = 0x13b;
  DAT_004a7bcc = 0x2d;
  DAT_004abb74 = 0;
  DAT_004abf1c = 0xfffffc18;
  FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da8),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0),1,1,DAT_004a72d0,0);
  DAT_004aa738 = 0xffffffff;
  _DAT_004a6ed0 = 0xf;
  _DAT_004a77f0 = 2;
  DAT_004a7068 = 0x3c;
  DAT_004a6340 = 0xf;
  DAT_004ac020 = 0x2d;
  DAT_004a7bd0 = 0x2d;
  DAT_004abb78 = 0;
  DAT_004abf20 = 0xfffffc18;
  FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0),2,1,DAT_004a72d0,0);
  if (2 < DAT_0049118c) {
    _DAT_004a77f4 = 2;
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    DAT_004abb7c = 0;
    _DAT_004abf24 = 0xfffffc18;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),3,1,DAT_004a72d0,0);
  }
  DAT_004ac994 = 0;
  DAT_004a4e8c = TStack_18.data;
  DVar6 = GetTickCount();
  DVar4 = local_10;
  uVar7 = DVar6 - local_10;
  while (uVar7 < 0x50) {
    DVar6 = GetTickCount();
    uVar7 = DVar6 - DVar4;
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_14);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


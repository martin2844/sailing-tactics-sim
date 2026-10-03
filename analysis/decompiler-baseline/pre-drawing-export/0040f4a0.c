
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040f4a0(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  int *piVar3;
  DWORD DVar4;
  uint uVar5;
  int unaff_EBP;
  int iVar6;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  bool bVar7;
  HDC hdc;
  HGDIOBJ h;
  int iStack_8c;
  int iStack_88;
  int iStack_7c;
  int iStack_78;
  int iVar8;
  int iStack_70;
  code *pcStack_6c;
  int iStack_68;
  int iStack_64;
  int iVar9;
  int iStack_58;
  int iStack_54;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  code *pcVar13;
  code *pcStack_38;
  int iStack_34;
  code *pcStack_18;
  int iStack_14;
  int iStack_c;
  code *pcStack_8;
  code *pcStack_4;
  
  pcStack_4 = (code *)0xffffffff;
  pcStack_8 = FUN_0047deb0;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iStack_34 = 0x40f4c2;
  GetTickCount();
  _DAT_004aa810 = (double)DAT_004a763c;
  _DAT_004aa7d8 = (double)DAT_004a72d0;
  iVar6 = *(int *)param_1;
  pcVar12 = *(code **)(iVar6 + 0x2c);
  iStack_34 = 7;
  uVar5 = (699 < DAT_004a763c) - 1 & 0xfffffff6;
  pcStack_38 = (code *)0x40f51c;
  (*pcVar12)();
  pcStack_38 = (code *)0x0;
  (*pcVar12)();
  Rectangle(*(HDC *)(param_1 + 4),0,0,DAT_004a763c,DAT_004a72d0);
  if ((0 < DAT_00491164) && (DAT_004ac9cc == 0)) {
    FUN_00410090(param_1);
    *unaff_FS_OFFSET = iStack_14;
    return;
  }
  pcStack_4 = *(code **)(iVar6 + 0x38);
  if (DAT_004ac92c == 0) {
    pcVar12 = (code *)0xff;
  }
  else {
    pcVar12 = (code *)0x0;
  }
  (*pcStack_4)();
  FUN_0046bf33(&stack0xffffffd8,s_Select_Options__Then_select_Star_00492438);
  pcVar1 = *(code **)(iVar6 + 100);
  pcVar11 = (code *)0x1;
  pcVar10 = (code *)&DAT_00000005;
  (*pcVar1)();
  FUN_0046bec5((int *)&pcStack_38);
  if (DAT_004ac9ac == 0) {
    iVar6 = uVar5 + 0x3c;
  }
  else {
    iVar6 = uVar5 + 0x28;
  }
  if (DAT_004ac92c == 0) {
    iStack_54 = 0x40f5ec;
    (*pcStack_18)();
  }
  iStack_54 = 0x40f5f4;
  DAT_004a5264 = GetSystemMetrics(0xf);
  iStack_54 = 0x40f60b;
  iStack_34 = DAT_004a5264;
  FUN_0046bf33(&stack0xffffffd0,s_SAILING_TACTICS_SIMULATOR_2002_00492418);
  iStack_58 = iVar6;
  iStack_54 = unaff_EDI;
  pcVar13 = pcVar12;
  (*pcVar1)();
  if ((DAT_004a763c < 0x385) && (699 < DAT_004a763c)) {
    if (unaff_EBP < 0x15) {
      pcVar11 = pcVar10 + 0xe6;
    }
    else {
      pcVar11 = pcVar10 + 0x122;
    }
  }
  if ((900 < DAT_004a763c) && (pcVar11 = pcVar10 + 0x122, unaff_EBP < 0x15)) {
    pcVar11 = pcVar10 + 0xe6;
  }
  if (DAT_004a763c < 700) {
    pcVar11 = pcVar10 + 0xe6;
  }
  iStack_64 = 0x40f69b;
  FUN_0046bf33(&stack0xffffffbc,&DAT_00492414);
  iStack_64 = unaff_EBP;
  iVar9 = *(int *)(iStack_64 + -8);
  iStack_68 = iVar6 - DAT_004a72d0 / 100;
  pcStack_6c = pcVar11 + 2;
  iStack_70 = 0x40f6d1;
  (*pcVar1)();
  iStack_70 = 0x40f6de;
  FUN_0046bec5(&iStack_54);
  iStack_70 = 0;
  (*pcStack_38)();
  if (DAT_004ac9ac == 1) {
    iStack_78 = 0x40f6fc;
    FUN_0046bf33(&iStack_58,s_Modified_for_TEKNOWLEDGE__You_co_004923c0);
    iStack_7c = iVar6 + 0x14;
    iStack_78 = iStack_58;
    (*pcVar1)();
    FUN_0046bec5(&iStack_58);
    if (DAT_004ac9ac == 1) {
      iStack_78 = 0x40f737;
      FUN_0046bf33(&iStack_58,s_Messages__green_background__are_G_00492364);
      iStack_7c = iVar6 + 0x28;
      iStack_78 = iStack_58;
      (*pcVar1)();
      FUN_0046bec5(&iStack_58);
    }
  }
  if (DAT_004ac92c == 0) {
    iStack_78 = 0x40f770;
    (*pcVar13)();
  }
  if (DAT_00491164 == 0) {
    iStack_78 = 0x40f787;
    FUN_0046bf33(&iStack_58,s_Release_2_00492358);
    iStack_7c = iVar6 + 0x14;
    iVar8 = *(int *)(iStack_58 + -8);
    iStack_78 = iStack_58;
    (*pcVar1)();
  }
  else {
    iStack_78 = 0x40f7ba;
    FUN_0046bf33(&iStack_58,s_Demo_Version_00492348);
    iStack_7c = iVar6 + 0x14;
    iVar8 = *(int *)(iStack_58 + -8);
    iStack_78 = iStack_58;
    (*pcVar1)();
  }
  iStack_54 = CONCAT31(iStack_54._1_3_,1);
  FUN_0046bec5(&iStack_68);
  if (DAT_004ac92c == 0) {
    iStack_88 = 0x40f7f6;
    (*pcVar10)();
  }
  iStack_88 = 0x40f804;
  FUN_0046bf33(&iStack_68,s_Copyright_C__1998_2001_by_C__Den_0049231c);
  iStack_54 = CONCAT31(iStack_54._1_3_,7);
  iStack_88 = iStack_68;
  iStack_8c = iVar6;
  (*pcVar1)((DAT_004a763c * 6) / 0xb);
  iStack_64 = CONCAT31(iStack_64._1_3_,1);
  FUN_0046bec5(&iStack_78);
  (*pcVar12)(0);
  if (DAT_00491140 == 2) {
    if (DAT_004ac948 == -7) {
      FUN_0046bf33(&stack0xffffffa0,s_Boat_1_much_faster_00492308);
      iStack_68._0_1_ = 8;
      (*pcVar1)(0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,iVar9,
                *(undefined4 *)(iVar9 + -8));
      iStack_68 = CONCAT31(iStack_68._1_3_,1);
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if (DAT_004ac948 == -4) {
      FUN_0046bf33(&stack0xffffffa0,s_Boat_1_significantly_faster_004922ec);
      iStack_68._0_1_ = 9;
      (*pcVar1)(0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,iVar9,
                *(undefined4 *)(iVar9 + -8));
      iStack_68 = CONCAT31(iStack_68._1_3_,1);
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if (DAT_004ac948 == -2) {
      FUN_0046bf33(&stack0xffffffa0,s_Boat_1_slightly_faster_004922d4);
      iStack_68._0_1_ = 10;
      (*pcVar1)(0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,iVar9,
                *(undefined4 *)(iVar9 + -8));
      iStack_68 = CONCAT31(iStack_68._1_3_,1);
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if (DAT_004ac948 == 0) {
      FUN_0046bf33(&stack0xffffffa0,s_Boats_equal_speed_potential_004922b8);
      iStack_68._0_1_ = 0xb;
      (*pcVar1)(0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,iVar9,
                *(undefined4 *)(iVar9 + -8));
      iStack_68 = CONCAT31(iStack_68._1_3_,1);
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if (DAT_004ac948 == 7) {
      FUN_0046bf33(&stack0xffffffa0,s_Boat_2_much_faster_004922a4);
      iStack_68._0_1_ = 0xc;
      (*pcVar1)(0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,iVar9,
                *(undefined4 *)(iVar9 + -8));
      iStack_68 = CONCAT31(iStack_68._1_3_,1);
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if (DAT_004ac948 == 4) {
      FUN_0046bf33(&stack0xffffffa0,s_Boat_2_significantly_faster_00492288);
      iStack_68._0_1_ = 0xd;
      (*pcVar1)(0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,iVar9,
                *(undefined4 *)(iVar9 + -8));
      iStack_68 = CONCAT31(iStack_68._1_3_,1);
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if (DAT_004ac948 == 2) {
      FUN_0046bf33(&stack0xffffffa0,s_Boat_2_slightly_faster_00492270);
      iStack_68._0_1_ = 0xe;
      (*pcVar1)(0x14,(int)(DAT_004a72d0 * 3 + (DAT_004a72d0 * 3 >> 0x1f & 3U)) >> 2,iVar9,
                *(undefined4 *)(iVar9 + -8));
      iStack_68 = CONCAT31(iStack_68._1_3_,1);
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
  }
  if (((5 < DAT_00491188) && (DAT_00491188 < 9)) && (DAT_004ac908 == 0)) {
    iVar6 = (DAT_004a72d0 * 4) / 5;
    FUN_00413d00(&iStack_7c,DAT_004a5ba4);
    iStack_68._0_1_ = 0xf;
    piVar3 = (int *)FUN_0046c14f();
    iStack_68 = CONCAT31(iStack_68._1_3_,0x10);
    (*pcVar1)(10,iVar6,*piVar3,*(undefined4 *)(*piVar3 + -8));
    iStack_78._0_1_ = 0xf;
    FUN_0046bec5(&iStack_70);
    iStack_78._0_1_ = 1;
    FUN_0046bec5(&iStack_8c);
    if (DAT_004a4eec == 0xb) {
      FUN_0046bf33(&iStack_70,s_Heavy_displacement_00492250);
      iStack_78._0_1_ = 0x11;
      (*pcVar1)((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar6,iStack_70,
                *(undefined4 *)(iStack_70 + -8));
      iStack_78._0_1_ = 1;
      FUN_0046bec5(&iStack_70);
    }
    if (DAT_004a4eec == 10) {
      FUN_0046bf33(&iStack_70,s_Moderate_displacement_00492238);
      iStack_78._0_1_ = 0x12;
      (*pcVar1)((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar6,iStack_70,
                *(undefined4 *)(iStack_70 + -8));
      iStack_78._0_1_ = 1;
      FUN_0046bec5(&iStack_70);
    }
    if (DAT_004a4eec == 9) {
      FUN_0046bf33(&iStack_70,s_Light_displacement_00492224);
      iStack_78._0_1_ = 0x13;
      (*pcVar1)((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar6,iStack_70,
                *(undefined4 *)(iStack_70 + -8));
      iStack_78._0_1_ = 1;
      FUN_0046bec5(&iStack_70);
    }
    if (DAT_004a4eec < 9) {
      FUN_0046bf33(&iStack_70,s_Ultra_light_displacement_00492208);
      iStack_78._0_1_ = 0x14;
      (*pcVar1)((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar6,iStack_70,
                *(undefined4 *)(iStack_70 + -8));
      iStack_78._0_1_ = 1;
      FUN_0046bec5(&iStack_70);
    }
    if (DAT_004a5b90 < 10) {
      FUN_0046bf33(&iStack_70,s_Less_than_average_sail_004921f0);
      iStack_78._0_1_ = 0x15;
      (*pcVar1)(((int)(DAT_004a763c * 2 + (DAT_004a763c * 2 >> 0x1f & 3U)) >> 2) + 10,iVar6,
                iStack_70,*(undefined4 *)(iStack_70 + -8));
      iStack_78._0_1_ = 1;
      FUN_0046bec5(&iStack_70);
    }
    bVar7 = false;
    if (DAT_004a5b90 == 10) {
      FUN_0046bf33(&iStack_70,s_Average_sail_area_004921dc);
      iStack_78._0_1_ = 0x16;
      (*pcVar1)(((int)(DAT_004a763c * 2 + (DAT_004a763c * 2 >> 0x1f & 3U)) >> 2) + 10,iVar6,
                iStack_70,*(undefined4 *)(iStack_70 + -8));
      iStack_78._0_1_ = 1;
      FUN_0046bec5(&iStack_70);
      bVar7 = DAT_004a5b90 == 10;
    }
    if (!bVar7 && 9 < DAT_004a5b90) {
      FUN_0046bf33(&iStack_70,s_More_than_average_sail_004921c4);
      iStack_78._0_1_ = 0x17;
      (*pcVar1)(((int)(DAT_004a763c * 2 + (DAT_004a763c * 2 >> 0x1f & 3U)) >> 2) + 10,iVar6,
                iStack_70,*(undefined4 *)(iStack_70 + -8));
      iStack_78._0_1_ = 1;
      FUN_0046bec5(&iStack_70);
    }
    if (DAT_00491150 < 100) {
      FUN_0046bf33(&iStack_70,s_Fractional_rig_004921b4);
      iStack_78 = CONCAT31(iStack_78._1_3_,0x18);
      (*pcVar1)(((int)(DAT_004a763c * 3 + (DAT_004a763c * 3 >> 0x1f & 3U)) >> 2) + 10,iVar6,
                iStack_70,*(undefined4 *)(iStack_70 + -8));
    }
    else {
      FUN_0046bf33(&iStack_70,s_Masthead_rig_004921a4);
      iStack_78 = CONCAT31(iStack_78._1_3_,0x19);
      (*pcVar1)(((int)(DAT_004a763c * 3 + (DAT_004a763c * 3 >> 0x1f & 3U)) >> 2) + 10,iVar6,
                iStack_70,*(undefined4 *)(iStack_70 + -8));
    }
    iStack_68 = CONCAT31(iStack_68._1_3_,1);
    FUN_0046bec5((int *)&stack0xffffffa0);
  }
  dVar2 = _DAT_004a8670 * _DAT_00484d88;
  iVar6 = DAT_004a72d0 * 3;
  iVar9 = DAT_004a763c * 9;
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0040fe0b;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0040fe0b;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0040fe0b:
  RoundRect(*(HDC *)(param_1 + 4),DAT_004a763c / 10,DAT_004a72d0 / 5,iVar9 / 10,
            ((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2) - (int)(longlong)dVar2,0x50,0x50);
  DAT_004ac994 = 1;
  iStack_7c = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  FUN_0042cd40((int *)param_1,(int)(longlong)(_DAT_004aa810 * _DAT_00484d98),
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
  FUN_00411000(param_1,(int)(longlong)(_DAT_004aa810 * _DAT_00484da8),
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
  FUN_00411000(param_1,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
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
    FUN_00411000(param_1,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),3,1,DAT_004a72d0,0);
  }
  DAT_004ac994 = 0;
  DAT_004a4e8c = iStack_7c;
  DVar4 = GetTickCount();
  uVar5 = DVar4 - iVar8;
  while (uVar5 < 0x50) {
    DVar4 = GetTickCount();
    uVar5 = DVar4 - iVar8;
  }
  iStack_68 = -1;
  FUN_0046bec5(&iStack_78);
  *unaff_FS_OFFSET = iStack_70;
  return;
}


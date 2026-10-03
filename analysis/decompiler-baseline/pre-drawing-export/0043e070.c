
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043e070(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *this;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  int unaff_EBX;
  code *pcVar6;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  int unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  int iVar9;
  int iVar10;
  code *pcStack_80;
  undefined *puVar11;
  HDC hdc;
  HGDIOBJ h;
  code *pcStack_50;
  int iStack_4c;
  CDC *pCStack_48;
  int iVar12;
  int local_30;
  code *local_2c;
  int iStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  int aiStack_1c [2];
  undefined4 uStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f5e0;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar8 = 0x10;
    local_30 = 0x16;
    local_2c = (code *)&DAT_00000005;
    local_24 = 10;
  }
  else {
    iVar8 = 0x14;
    local_30 = 0x1b;
    local_2c = (code *)0x14;
    local_24 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_48 = (CDC *)0x43e0fb;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_48 = (CDC *)0x43e109;
  FUN_0046bf33(&param_1,s___HEADERS_WHILE_BEATING___0049a094);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  iVar12 = *(int *)(param_1 + -8);
  pCStack_48 = param_1;
  iStack_4c = 2;
  pcStack_50 = local_2c;
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  pcVar6 = (code *)(unaff_EDI + 2);
  if (DAT_004a6774 == 0) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_c,s_A_header_is_a_windshift_that_for_0049a038);
    uStack_14 = 1;
    iVar10 = unaff_ESI;
    pcVar4 = pcVar6;
    (*pcVar1)();
    local_24 = 0xffffffff;
    FUN_0046bec5(aiStack_1c);
    pcVar6 = pcVar6 + (int)pcStack_50;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(aiStack_1c,s_Boats_A_and_B_are_initially_even_00499bc4);
    local_24 = 2;
    (*pcVar1)();
    FUN_0046bec5((int *)&local_2c);
    pcVar6 = pcVar6 + iVar10;
    pcStack_80 = pcVar4;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
      pcStack_80 = pcVar4;
    }
    FUN_0046bf33(&local_2c,s_Click_the_Advance_Position_Butto_00499ffc);
    unaff_EBX = 3;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(&local_30,s_Boat_A_has_gained_30___of_the_se_00499f98);
    iStack_c = unaff_EBX + unaff_ESI;
    uStack_14 = 4;
    pcVar4 = pcVar6;
    (*pcVar1)();
    local_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
    FUN_0046bf33(&stack0xffffffc0,s_boat_lengths__If_the_boats_had_b_00499f34);
    local_24 = 5;
    iVar7 = aiStack_1c[0];
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_50);
    FUN_0046bf33(&pcStack_50,s_gained_30___of_a_mile___If_the_s_00499ed4);
    unaff_EBX = 6;
    pcStack_80 = local_2c;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffa0);
    iVar10 = iVar7 + iVar8 * 3;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffa0,s_Problem__If_the_wind_shifts_back_00499e7c);
    iVar12 = 7;
    iVar5 = unaff_ESI;
    (*pcVar1)(unaff_ESI);
    FUN_0046bec5((int *)&stack0xffffff90);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0x7f0000);
    }
    FUN_0046bf33(&stack0xffffff90,s_To_consolidate_the_gain__A_tacks_00499e58);
    (*pcVar1)(iStack_4c,pcVar6 + iVar10,iVar7,*(undefined4 *)(iVar7 + -8));
    FUN_0046bec5((int *)&pcStack_80);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0x7f0000);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0xff);
    }
    FUN_0046bf33(&pcStack_80,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)(pcVar4,pcVar6 + iVar10 + iVar5,pcStack_80,*(undefined4 *)(pcStack_80 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_30);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(&local_30,s_If_Boat_A_can_get_between_the_ma_00499de0);
    iStack_c = unaff_EBX + unaff_ESI;
    uStack_14 = 10;
    (*pcVar1)();
    local_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
    FUN_0046bf33(&stack0xffffffc0,s_will_not_be_lost_by_a_wind_shift_00499dbc);
    local_24 = 0xb;
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_50);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&pcStack_50,s_Click_the_Advance_Position_Butto_00499e34);
    unaff_EBX = 0xc;
    pcStack_80 = local_2c;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_30);
  }
  if (DAT_004a6774 == 3) {
    FUN_0046bf33(&local_30,s_Boat_A_is_now_between_the_mark_a_00499d6c);
    iStack_c = unaff_EBX + unaff_ESI;
    uStack_14 = 0xd;
    (*pcVar1)();
    local_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
    FUN_0046bf33(&stack0xffffffc0,s_In_order_to_stay_in_this_safe_po_00499d28);
    local_24 = 0xe;
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_50);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&pcStack_50,s_Click_the_Advance_Position_Butto_00499e34);
    unaff_EBX = 0xf;
    pcStack_80 = local_2c;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_30);
  }
  if (DAT_004a6774 == 4) {
    FUN_0046bf33(&local_30,s_Boat_A_s_position_between_Boat_B_00499cd8);
    iStack_c = unaff_EBX + unaff_ESI;
    uStack_14 = 0x10;
    (*pcVar1)();
    local_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
    FUN_0046bf33(&stack0xffffffc0,s_Boat_A_s_lead_will_not_be_lost_b_00499ca8);
    local_24 = 0x11;
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_50);
    FUN_0046bf33(&pcStack_50,s_In_order_to_keep_this_position__B_00499c58);
    pcStack_80 = local_2c;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_30);
  }
  FUN_0044d830((int *)this,unaff_ESI,iVar8);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043e700;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043e700;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043e700:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 4;
  FUN_0044d6d0((int *)this);
  DAT_004ac994 = 2;
  uStack_20 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  iStack_28 = iVar7;
  FUN_0042cd40((int *)this,iVar7,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98),4,1);
  FUN_0046bf33(&iStack_c,&DAT_00493460);
  uStack_14 = 0x13;
  iVar10 = *(int *)(iStack_c + -8);
  (*pcVar1)();
  local_24 = 0xffffffff;
  FUN_0046bec5(aiStack_1c);
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = DAT_004a6774;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc0,iVar7,iVar12);
    iStack_4c = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,iStack_4c,aiStack_1c[0]);
    FUN_0046bf33(&stack0xffffffc0,s_LayLine_00499508);
    local_24 = 0x14;
    pcVar6 = *(code **)(unaff_EDI + -8);
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_50);
    pcStack_80 = (code *)0x43e8c8;
    FUN_004706bd(this,(int *)&pcStack_50,iVar7,iVar10);
    iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    local_2c = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,iVar12,(int)local_2c);
    iVar7 = DAT_004a763c / 0xe;
    FUN_0046bf33(&pcStack_50,s_LayLine_00499508);
    pcVar3 = local_2c + iVar8 * -2;
    pcStack_80 = (code *)(iVar12 - iVar7);
    pcVar4 = pcStack_50;
    (*pcVar1)();
    iVar12 = -1;
    FUN_0046bec5((int *)&stack0xffffffa0);
    (**(code **)(*(int *)this + 0x38))();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar7 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)&stack0xffffff90,0,iVar7);
    CDC::LineTo(this,DAT_004a763c,iVar7);
    (*pcVar6)();
    FUN_0046bf33(&stack0xffffffbc,s_Equal_Position_Line_004994f4);
    iStack_4c = 0x16;
    (*pcVar1)((DAT_004a763c * 2) / 5,iVar7,iVar12);
    FUN_0046bec5((int *)&stack0xffffffac);
    (*pcVar4)(0);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    puVar11 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar5 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar7,puVar11,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff84,s_Boat_B_004994ec);
    (*pcVar1)(iVar7 - iVar5,puVar11 + iVar8,pcVar3,*(undefined4 *)(pcVar3 + -8));
    FUN_0046bec5((int *)&stack0xffffff74);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    puVar11 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar9 = DAT_004a763c / 0xe;
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar7,puVar11,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff74,s_Boat_A_004994e4);
    (*pcVar1)(iVar7 - iVar9,puVar11 + iVar8,iVar5,*(undefined4 *)(iVar5 + -8));
    local_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
    iVar7 = unaff_EBP;
  }
  if ((DAT_004a6774 == 1) || (DAT_004a6774 == 2)) {
    DAT_004ac840 = 0x14;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc0,iVar7,iVar12);
    iStack_4c = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,iStack_4c,aiStack_1c[0]);
    FUN_0046bf33(&stack0xffffffc0,s_LayLine_00499508);
    local_24 = 0x19;
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_50);
    pcStack_80 = (code *)0x43ecd3;
    FUN_004706bd(this,(int *)&pcStack_50,iVar7,iVar10);
    iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    local_2c = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,iVar12,(int)local_2c);
    iVar7 = DAT_004a763c / 0xe;
    FUN_0046bf33(&pcStack_50,s_LayLine_00499508);
    pcVar4 = local_2c + iVar8 * -2;
    pcStack_80 = (code *)(iVar12 - iVar7);
    (*pcVar1)();
    iVar12 = -1;
    FUN_0046bec5((int *)&stack0xffffffa0);
    pcVar6 = *(code **)(*(int *)this + 0x38);
    (*pcVar6)();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)&stack0xffffff9c,(int)(longlong)(_DAT_004aa810 * _DAT_00484de8),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00485368));
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852e8),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    (*pcVar6)();
    FUN_0046bf33(&stack0xffffffbc,s_Equal_Position_Line_004994f4);
    iStack_4c = 0x1b;
    (*pcVar1)((DAT_004a763c * 2) / 5,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),iVar12);
    FUN_0046bec5((int *)&stack0xffffffac);
    (*pcVar6)(0);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    puVar11 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar5 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar7,puVar11,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff84,s_Boat_B_004994ec);
    (*pcVar1)(iVar7 - iVar5,puVar11 + iVar8,pcVar4,*(undefined4 *)(pcVar4 + -8));
    FUN_0046bec5((int *)&stack0xffffff74);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    puVar11 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar9 = DAT_004a763c / 0xe;
    if (DAT_004a6774 == 1) {
      DAT_004aa738 = DAT_004a6774;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = 2;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x127;
      DAT_004a7bd0 = 0x2d;
    }
    if (DAT_004a6774 == 2) {
      DAT_004aa738 = -1;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = DAT_004a6774;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x19;
      DAT_004a7bd0 = 0x2d;
    }
    FUN_00411000(this,iVar7,puVar11,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff74,s_Boat_A_004994e4);
    (*pcVar1)(iVar7 - iVar9,puVar11 + iVar8,iVar5,*(undefined4 *)(iVar5 + -8));
    local_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
    iVar7 = unaff_EBP;
  }
  if ((DAT_004a6774 == 3) || (DAT_004a6774 == 4)) {
    DAT_004ac840 = 0x14;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar7,iVar12);
    iStack_4c = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,iStack_4c,aiStack_1c[0]);
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    local_24 = 0x1e;
    iVar5 = aiStack_1c[0] + iVar8 * -2;
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_48);
    pcStack_80 = (code *)0x43f15e;
    FUN_004706bd(this,(int *)&pCStack_48,iVar7,iVar10);
    iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    local_2c = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,iVar12,(int)local_2c);
    iVar10 = DAT_004a763c / 0xe;
    FUN_0046bf33(&pCStack_48,s_LayLine_00499508);
    pcStack_80 = (code *)(iVar12 - iVar10);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar11 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    iVar10 = DAT_004a763c / 0xe;
    if (DAT_004a6774 == 3) {
      DAT_004aa738 = -1;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = 2;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x19;
      DAT_004a7bd0 = 0x2d;
    }
    if (DAT_004a6774 == 4) {
      DAT_004aa738 = 1;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = 2;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x127;
      DAT_004a7bd0 = 0x2d;
    }
    FUN_00411000(this,iVar12,puVar11,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffc0,s_Boat_A_004994e4);
    pCStack_48 = (CDC *)0x20;
    (*pcVar1)(iVar10 + iVar12,(int)puVar11 - iVar8);
    FUN_0046bec5((int *)&pcStack_50);
    iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    pcStack_50 = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar10 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar12,pcStack_50,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff94,s_Boat_B_004994ec);
    (*pcVar1)(iVar12 - iVar10,pcStack_50 + iVar8,iVar5,*(undefined4 *)(iVar5 + -8));
    local_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = local_30;
  *unaff_FS_OFFSET = (int)local_2c;
  return;
}


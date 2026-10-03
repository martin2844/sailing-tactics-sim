
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043f460(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *this;
  CDC *pCVar3;
  undefined *puVar4;
  int unaff_EBX;
  CDC *pCVar5;
  int unaff_EBP;
  int iVar6;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  code *pcVar7;
  int iVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  undefined *puVar14;
  HDC hdc;
  HGDIOBJ h;
  code *pcStack_48;
  int iStack_44;
  CDC *pCStack_40;
  int iVar15;
  code *local_28;
  undefined *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 auStack_10 [4];
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f730;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  iVar6 = 0x14;
  if (DAT_004a763c < 700) {
    iVar6 = 0x10;
    local_28 = (code *)&DAT_00000005;
  }
  else {
    local_28 = (code *)0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_40 = (CDC *)0x43f4df;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_40 = (CDC *)0x43f4ed;
  FUN_0046bf33(&param_1,s___DEATH_BY_LAYLINE___0049a578);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  iVar15 = *(int *)(param_1 + -8);
  pCStack_40 = param_1;
  iStack_44 = 2;
  pcStack_48 = local_28;
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  pCVar5 = (CDC *)(unaff_EBP + 2);
  if ((DAT_004a6774 == 0) || (DAT_004a6774 == 3)) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_c,s_With_any_windshift__a_boat_on_a_l_0049a51c);
    uStack_14 = 1;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_1c);
    pCVar3 = pCStack_40;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&puStack_1c,s_Boats_A_and_B_are_initially_even_0049a4e8);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    FUN_0046bf33(&stack0xffffffd4,s_However__boat_A_is_actually_clos_0049a4b8);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
    pCVar5 = pCVar3 + (int)(pCVar5 + unaff_EBP + iVar6);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    if (DAT_004a6774 == 0) {
      FUN_0046bf33(&iStack_c,s_Click_the_Advance_Position_Butto_0049a480);
      uStack_14 = 4;
      (*pcVar1)();
      uStack_14 = 0xffffffff;
      FUN_0046bec5(&iStack_c);
    }
    if (DAT_004a6774 == 3) {
      (**(code **)(*(int *)this + 0x38))();
      FUN_0046bf33(auStack_10,s_Click_the_Advance_Position_Butto_0049a444);
      uStack_18 = 5;
      (*pcVar1)();
      uStack_14 = 0xffffffff;
      FUN_0046bec5(&iStack_c);
    }
  }
  if ((DAT_004a6774 == 1) || (DAT_004a6774 == 2)) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_c,s_With_this_lift__Boat_A_can_sail_d_0049a40c);
    uStack_14 = 6;
    iVar9 = iStack_c;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_1c);
    FUN_0046bf33(&puStack_1c,s_Since_boat_A_is_actually_closer_t_0049a3c4);
    pcVar7 = pcStack_48;
    puVar12 = puStack_1c;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffd4,s_Boat_B_is_now_overstanding_and_h_0049a384);
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffc4);
    pCVar5 = pCVar5 + iVar9 + iVar6 + (int)puVar12;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_Click_the_Advance_Position_Butto_00499e34);
    iStack_44 = 9;
    (*pcVar1)(pcVar7);
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if ((DAT_004a6774 == 4) || (DAT_004a6774 == 5)) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_c,s_With_this_header__Boat_A_can_tac_0049a350);
    uStack_14 = 10;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_1c);
    pCVar5 = pCVar5 + (int)pCStack_40;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&puStack_1c,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 6) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_c,s_Boat_A_can_tack_back__consolidat_0049a308);
    uStack_14 = 0xc;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_1c);
    pCVar5 = pCVar5 + (int)pCStack_40;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&puStack_1c,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 7) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_c,s_Boat_A_can_now_stay_ahead_with_a_0049a2d8);
    uStack_14 = 0xe;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_1c);
    pCVar5 = pCVar5 + (int)pCStack_40;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&puStack_1c,s_Click_the_Advance_Position_Butto_0049a2a4);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 8) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_c,s_Despite_the_wind_shift_disadvant_0049a248);
    uStack_14 = 0x10;
    iVar9 = *(int *)(iStack_c + -8);
    iVar8 = unaff_EDI;
    iVar11 = iStack_c;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_1c);
    FUN_0046bf33(&puStack_1c,s_where_it_pays_to_sail_to_or_even_0049a1f8);
    iVar13 = *(int *)(puStack_1c + -8);
    pcVar7 = pcStack_48;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffd4,s_1__If_you_are_fairly_near_the_ma_0049a1a0);
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffc4);
    FUN_0046bf33(&stack0xffffffc4,s_worthwile_to_gamble_that_there_w_0049a168);
    iStack_44 = 0x13;
    (*pcVar1)(pcVar7);
    FUN_0046bec5((int *)&stack0xffffffb4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0x7f0000);
    }
    FUN_0046bf33(&stack0xffffffb4,s_2__In_light_air__the_wind_could_b_0049a110);
    (*pcVar1)(iVar8,pCVar5 + unaff_EBX + iVar11 + iVar6 * 2,iVar9,*(undefined4 *)(iVar9 + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    FUN_0046bf33(&stack0xffffffa4,s_or_beyond_the_layline__However__i_0049a0b8);
    (*pcVar1)(pcVar7,pCVar5 + unaff_EBX + iVar11 + iVar6 * 2 + iVar6,iVar13,
              *(undefined4 *)(iVar13 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  FUN_0044d830((int *)this,unaff_EDI,iVar6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043fc37;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043fc37;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043fc37:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 8;
  FUN_0044d6d0((int *)this);
  DAT_004ac994 = 2;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  puVar12 = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  dVar2 = _DAT_00485370;
  if ((DAT_004a6774 != 2) && (DAT_004a6774 != 8)) {
    dVar2 = _DAT_00484d98;
  }
  iVar13 = (int)(longlong)(_DAT_004aa7d8 * dVar2);
  FUN_0042cd40((int *)this,(int)puVar12,iVar13,4,1);
  FUN_0046bf33(&iStack_c,&DAT_00493460);
  uStack_14 = 0x16;
  iVar9 = *(int *)(iStack_c + -8);
  iVar8 = iStack_c;
  (*pcVar1)();
  FUN_0046bec5((int *)&puStack_1c);
  if ((DAT_004a6774 == 0) || (DAT_004a6774 == 3)) {
    DAT_004ac840 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar15,(int)pCStack_40);
    puStack_1c = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00484d48);
    CDC::LineTo(this,(int)puStack_1c,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    FUN_0046bf33(&pcStack_48,s_LayLine_00499508);
    pcVar7 = *(code **)(pcStack_48 + -8);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffa8);
    FUN_004706bd(this,(int *)&pcStack_48,iVar9,iVar8);
    puVar12 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484fe0),(int)puVar12);
    FUN_0046bf33(&pcStack_48,s_LayLine_00499508);
    puVar4 = puVar12 + iVar6 * -4;
    pcVar10 = pcStack_48;
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar9 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)&stack0xffffff94,0,iVar9);
    CDC::LineTo(this,DAT_004a763c,iVar9);
    (*pcVar7)();
    FUN_0046bf33(&iStack_44,s_Equal_Position_Line_004994f4);
    (*pcVar1)((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar9,iStack_44);
    FUN_0046bec5((int *)&stack0xffffffac);
    (*pcVar10)(0);
    iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    puVar14 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar8 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar9,puVar14,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff8c,s_Boat_B_004994ec);
    (*pcVar1)(iVar9 - iVar8,puVar14 + iVar6,puVar4,*(undefined4 *)(puVar4 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
    dVar2 = _DAT_00484da0;
    if (DAT_004a6774 == 0) {
      dVar2 = _DAT_00484ec8;
    }
    iVar9 = (int)(longlong)(_DAT_004aa810 * dVar2);
    puVar4 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar11 = DAT_004a763c / 0xe;
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar9,puVar4,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_A_004994e4);
    (*pcVar1)(iVar9 - iVar11,puVar4 + iVar6,iVar8,*(undefined4 *)(iVar8 + -8));
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  if (DAT_004a6774 == 1) {
    DAT_004ac840 = 0xffffffec;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    pCVar5 = pCStack_40;
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar15,(int)pCStack_40);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485060),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar15,(int)pCVar5);
    puStack_1c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484ec8),(int)puStack_1c);
    pcStack_48 = (code *)(DAT_004a763c / 10);
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_48);
    iVar11 = 0;
    (**(code **)(*(int *)this + 0x38))();
    iVar13 = (int)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    puVar4 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 0xc;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x145;
    DAT_004a7bcc = 0x41;
    FUN_00411000(this,iVar13,puVar4,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffb4,s_Boat_B__0049a0b0);
    (*pcVar1)();
    pcStack_48 = (code *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa4);
    FUN_0046bf33(&pCStack_40,s_Overstanding_004994cc);
    pcStack_48 = (code *)0x1e;
    (*pcVar1)(iVar11,puVar4 + iVar6);
    FUN_0046bec5((int *)&stack0xffffffb0);
    iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    puVar4 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa738 = 1;
    iVar8 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar9,puVar4,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff94,s_Boat_A_004994e4);
    (*pcVar1)(iVar9 - iVar8,puVar4 + iVar6,iVar11,*(undefined4 *)(iVar11 + -8));
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  if ((DAT_004a6774 == 2) || (DAT_004a6774 == 8)) {
    DAT_004ac840 = 0xffffffec;
    puStack_1c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    pcStack_48 = (code *)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 0xc;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x14a;
    DAT_004a7bcc = 0x41;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484ec8),puStack_1c,1,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 2) {
      FUN_0046bf33(&stack0xffffffc8,s_Boat_B_004994ec);
      (*pcVar1)();
      FUN_0046bec5((int *)&stack0xffffffc8);
    }
    puStack_1c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    pcStack_48 = (code *)(DAT_004a763c / 0xe);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),puStack_1c,2,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 2) {
      FUN_0046bf33(&stack0xffffffc8,s_Boat_A_004994e4);
      (*pcVar1)();
      FUN_0046bec5((int *)&stack0xffffffc8);
    }
  }
  if ((DAT_004a6774 == 4) || (DAT_004a6774 == 5)) {
    DAT_004ac840 = 0x1e;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    pCVar5 = pCStack_40;
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar15,(int)pCStack_40);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484d48),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484fe0));
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar15,(int)pCVar5);
    puStack_1c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484fe0),(int)puStack_1c);
    pcStack_48 = (code *)(DAT_004a763c / 6);
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    puVar4 = puStack_1c + iVar6 * -5;
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_48);
    pcVar7 = *(code **)(*(int *)this + 0x38);
    (*pcVar7)();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)&stack0xffffffb4,(int)(longlong)(_DAT_004aa810 * _DAT_00484fe0),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0));
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    (*pcVar7)();
    FUN_0046bf33(&stack0xffffffcc,s_Equal_Position_Line_004994f4);
    (*pcVar1)();
    FUN_0046bec5(&iStack_44);
    (*pcVar7)();
    iVar15 = (int)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    pcStack_48 = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar9 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar15,pcStack_48,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff9c,s_Boat_B_004994ec);
    (*pcVar1)(iVar15 - iVar9,pcStack_48 + iVar6,puVar4,*(undefined4 *)(puVar4 + -8));
    FUN_0046bec5((int *)&stack0xffffff8c);
    iVar15 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    puVar4 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar8 = DAT_004a763c / 0xe;
    if (DAT_004a6774 == 4) {
      DAT_004aa738 = 1;
      DAT_004ac020 = 0x127;
    }
    else {
      DAT_004aa738 = 0xffffffff;
      DAT_004ac020 = 0x19;
    }
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar15,puVar4,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff8c,s_Boat_A_004994e4);
    (*pcVar1)(iVar15 - iVar8,puVar4 + iVar6,iVar9,*(undefined4 *)(iVar9 + -8));
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  if ((DAT_004a6774 == 6) || (DAT_004a6774 == 7)) {
    DAT_004ac840 = 0x1e;
    puStack_1c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    pcStack_48 = (code *)(DAT_004a763c / 0xe);
    if (DAT_004a6774 == 7) {
      DAT_004aa738 = 1;
      DAT_004ac020 = 0x127;
    }
    else {
      DAT_004aa738 = 0xffffffff;
      DAT_004ac020 = 0x19;
    }
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484ec8),puStack_1c,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffc8,s_Boat_A_004994e4);
    (*pcVar1)();
    FUN_0046bec5((int *)&pcStack_48);
    puVar12 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),puVar12,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pcStack_48,s_Boat_B_004994ec);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = iVar13;
  *unaff_FS_OFFSET = (int)puVar12;
  return;
}


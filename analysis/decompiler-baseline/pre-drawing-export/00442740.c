
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00442740(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *this;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined *puVar9;
  undefined *puVar10;
  int iVar11;
  code *pcVar12;
  code *pcVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  HDC hdc;
  HGDIOBJ h;
  int iStack_48;
  int iStack_44;
  CDC *pCStack_40;
  int local_28;
  int aiStack_1c [2];
  undefined4 uStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f9c0;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar4 = 0x10;
    local_28 = 5;
  }
  else {
    iVar4 = 0x14;
    local_28 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_40 = (CDC *)0x4427bf;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_40 = (CDC *)0x4427cd;
  FUN_0046bf33(&param_1,s___STRATEGY_for_BEATING_with_ONE_S_0049af40);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  iVar11 = *(int *)(param_1 + -8);
  pCStack_40 = param_1;
  iStack_44 = 2;
  iStack_48 = local_28;
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  iVar6 = unaff_ESI + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&iStack_c,s_One_side_could_be_favored_becaus_0049aef4);
    uStack_14 = 1;
    iVar8 = *(int *)(iStack_c + -8);
    iVar7 = unaff_EDI;
    (*pcVar1)();
    FUN_0046bec5(aiStack_1c);
    FUN_0046bf33(aiStack_1c,s_less_adverse_tide_on_one_side__o_0049aea0);
    iVar14 = iStack_48;
    iVar16 = iVar6 + iVar4;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    iVar5 = iVar6 + iVar4 + iVar4;
    FUN_0046bf33(&stack0xffffffd4,s_shift_is_one_that_does_not_shift_0049ae48);
    iVar6 = iVar5;
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffc4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_The_boats_are_even__Boat_A_expec_0049adf0);
    iStack_44 = 4;
    (*pcVar1)(iVar14);
    FUN_0046bec5((int *)&stack0xffffffb4);
    iVar6 = iVar5 + iVar16 + iVar6;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0xff);
    }
    FUN_0046bf33(&stack0xffffffb4,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)(iVar7,iVar6,iVar8,*(undefined4 *)(iVar8 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(&iStack_c,s_After_they_sail_some_distance__t_0049ada8);
    uStack_14 = 6;
    (*pcVar1)();
    FUN_0046bec5(aiStack_1c);
    iVar6 = iVar6 + iVar4;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(aiStack_1c,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(&iStack_c,s_Boat_A_has_made_a_significant_ga_0049ad78);
    uStack_14 = 8;
    iVar8 = *(int *)(iStack_c + -8);
    iVar14 = unaff_EDI;
    (*pcVar1)();
    FUN_0046bec5(aiStack_1c);
    iVar6 = iVar6 + iStack_44;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(aiStack_1c,s_If_the_wind_goes_farther_right__B_0049ad18);
    iVar16 = *(int *)(aiStack_1c[0] + -8);
    iVar5 = iStack_48;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    iVar6 = iVar6 + iVar4 * 2;
    FUN_0046bf33(&stack0xffffffd4,s_However__that_would_be_risky__If_0049acbc);
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffc4);
    FUN_0046bf33(&stack0xffffffc4,s_and_lose_much_distance__Also__if_0049ac60);
    iStack_44 = 0xb;
    iVar7 = iVar6;
    (*pcVar1)(iVar5);
    FUN_0046bec5((int *)&stack0xffffffb4);
    iVar6 = iVar6 + iVar4;
    FUN_0046bf33(&stack0xffffffb4,s_be_hopelessly_behind__0049ac48);
    (*pcVar1)(iVar14,iVar6,iVar8,*(undefined4 *)(iVar8 + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    iVar6 = iVar6 + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0xff);
    }
    FUN_0046bf33(&stack0xffffffa4,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)(iVar5,iVar6,iVar16,*(undefined4 *)(iVar16 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 3) {
    FUN_0046bf33(&iStack_c,s_The_wind_goes_another_10_degrees_0049abe8);
    uStack_14 = 0xe;
    iVar8 = *(int *)(iStack_c + -8);
    iVar14 = unaff_EDI;
    (*pcVar1)();
    FUN_0046bec5(aiStack_1c);
    iVar6 = iVar6 + iStack_44;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(aiStack_1c,s_When_one_side_is_favored__the_be_0049ab84);
    iVar16 = *(int *)(aiStack_1c[0] + -8);
    iVar5 = iStack_48;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    iVar6 = iVar6 + iVar4;
    FUN_0046bf33(&stack0xffffffd4,s_However__one_must_be_careful_not_0049ab20);
    iVar7 = iVar6;
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffc4);
    FUN_0046bf33(&stack0xffffffc4,s_oscillating__one_probably_should_0049aabc);
    iStack_44 = 0x11;
    (*pcVar1)(iVar5);
    FUN_0046bec5((int *)&stack0xffffffb4);
    iVar7 = iVar6 + iVar4 + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0);
    }
    FUN_0046bf33(&stack0xffffffb4,s_If_somewhat_in_doubt_that_one_si_0049aa5c);
    (*pcVar1)(iVar14,iVar7,iVar8,*(undefined4 *)(iVar8 + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    FUN_0046bf33(&stack0xffffffa4,s_Instead__try_to_stay_on_the_favo_0049aa18);
    (*pcVar1)(iVar5,iVar4 + iVar7,iVar16,*(undefined4 *)(iVar16 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  FUN_0044d830((int *)this,unaff_EDI,iVar4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00442db8;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00442db8;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00442db8:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 3;
  FUN_0044d6d0((int *)this);
  DAT_004ac994 = 2;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iVar8 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  iVar14 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,iVar8,iVar14,4,1);
  FUN_0046bf33(&iStack_c,&DAT_00493460);
  uStack_14 = 0x14;
  iVar6 = *(int *)(iStack_c + -8);
  iVar7 = iVar14;
  iVar5 = iStack_c;
  (*pcVar1)();
  FUN_0046bec5(aiStack_1c);
  iVar16 = iVar8;
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = DAT_004a6774;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar8,(int)pCStack_40);
    iStack_44 = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iStack_48 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,iStack_44,iStack_48);
    aiStack_1c[0] = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar8,iVar5);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485360),iVar3);
    iVar16 = DAT_004a763c / 10;
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    pcVar13 = *(code **)(iStack_48 + -8);
    iVar3 = iVar3 + iVar4 * -2;
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    iVar8 = iVar11;
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
      iVar8 = iVar11;
    }
    iVar11 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)&stack0xffffffa4,0,iVar11);
    CDC::LineTo(this,DAT_004a763c,iVar11);
    pcVar12 = (code *)0x7f00;
    (*pcVar13)();
    FUN_0046bf33(&iStack_44,s_Equal_Position_Line_004994f4);
    iVar6 = 0x17;
    (*pcVar1)(DAT_004a763c / 5,iVar11,iStack_44);
    FUN_0046bec5((int *)&stack0xffffffac);
    (*pcVar12)(0);
    iVar11 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar15 = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x2d;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar11,puVar10,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff8c,s_Boat_A_004994e4);
    (*pcVar1)(iVar15 + iVar11,puVar10 + iVar4,iVar3,*(undefined4 *)(iVar3 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
    iVar11 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar9 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar3 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar11,puVar9,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_B_004994ec);
    (*pcVar1)(iVar11 - iVar3,puVar9 + iVar4,puVar10,*(undefined4 *)(puVar10 + -8));
    FUN_0046bec5((int *)&stack0xffffffc8);
    iVar11 = iVar8;
  }
  if ((DAT_004a6774 == 1) || (DAT_004a6774 == 2)) {
    DAT_004ac840 = -10;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar8,(int)pCStack_40);
    iStack_44 = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iStack_48 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    CDC::LineTo(this,iStack_44,iStack_48);
    aiStack_1c[0] = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    iVar3 = *(int *)(unaff_EDI + -8);
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar8,iVar5);
    iVar15 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    CDC::LineTo(this,iVar15,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    iVar16 = DAT_004a763c / 10;
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    pcVar13 = (code *)0x0;
    (**(code **)(*(int *)this + 0x38))();
    iVar8 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    pCStack_40 = (CDC *)(DAT_004a763c / 0x14);
    if (DAT_004a6774 == 1) {
      DAT_004aa734 = 0xffffffff;
      DAT_004ac01c = 0x23;
    }
    else {
      DAT_004aa734 = 1;
      DAT_004ac01c = 0x145;
    }
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar8,puVar10,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffa4,s_Boat_A_004994e4);
    iStack_48 = 0x1c;
    (*pcVar1)(pCStack_40 + iVar8,puVar10 + iVar4);
    FUN_0046bec5((int *)&stack0xffffff94);
    iVar8 = iVar11;
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
      iVar8 = iVar11;
    }
    FUN_004706bd(this,(int *)&stack0xffffff94,iVar15 - iVar16,(int)puVar10);
    CDC::LineTo(this,DAT_004a763c / 5,(int)puVar10 - DAT_004a72d0 / 10);
    pcVar12 = (code *)0x7f00;
    (*pcVar13)();
    FUN_0046bf33(&stack0xffffffac,s_Equal_Position_Line_004994f4);
    (*pcVar1)((DAT_004a763c * 2) / 5,(int)puVar10 - DAT_004a72d0 / 0x14,iVar7,
              *(undefined4 *)(iVar7 + -8));
    FUN_0046bec5((int *)&stack0xffffff9c);
    (*pcVar12)(0);
    iVar11 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    iVar15 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x145;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar11,puVar10,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_B_004994ec);
    (*pcVar1)(iVar11 - iVar15,puVar10 + iVar4,iVar3,*(undefined4 *)(iVar3 + -8));
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  if (DAT_004a6774 == 3) {
    DAT_004ac840 = -0x14;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar8,(int)pCStack_40);
    iStack_48 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485358),iStack_48);
    aiStack_1c[0] = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    iVar11 = *(int *)(unaff_EDI + -8);
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar6,iVar5);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    CDC::LineTo(this,iVar6,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50));
    iVar16 = DAT_004a763c / 10;
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    pcVar13 = (code *)0x0;
    (**(code **)(*(int *)this + 0x38))();
    iVar8 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    DAT_004aa734 = 1;
    pCStack_40 = (CDC *)(DAT_004a763c / 0x14);
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar8,puVar10,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffa4,s_Boat_A_004994e4);
    iStack_48 = 0x21;
    (*pcVar1)(pCStack_40 + iVar8,puVar10 + iVar4);
    FUN_0046bec5((int *)&stack0xffffff94);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)&stack0xffffff94,iVar6 - iVar16,(int)puVar10);
    CDC::LineTo(this,DAT_004a763c / 5,(int)puVar10 - DAT_004a72d0 / 5);
    pcVar12 = (code *)0x7f00;
    (*pcVar13)();
    FUN_0046bf33(&stack0xffffffac,s_Equal_Position_Line_004994f4);
    (*pcVar1)((DAT_004a763c * 2) / 5,(int)puVar10 - DAT_004a72d0 / 10,iVar7,
              *(undefined4 *)(iVar7 + -8));
    FUN_0046bec5((int *)&stack0xffffff9c);
    (*pcVar12)(0);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar8 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar6,puVar10,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_B_004994ec);
    (*pcVar1)(iVar6 - iVar8,puVar10 + iVar4,iVar11,*(undefined4 *)(iVar11 + -8));
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = iVar14;
  *unaff_FS_OFFSET = iVar16;
  return;
}


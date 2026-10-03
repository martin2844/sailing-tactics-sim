
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00440d20(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *this;
  undefined *puVar3;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  code *pcVar13;
  code *pcVar14;
  HDC hdc;
  HGDIOBJ h;
  undefined *puStack_4c;
  int iStack_48;
  CDC *pCStack_44;
  int local_2c;
  undefined1 *local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined *apuStack_1c [2];
  undefined4 uStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f888;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar4 = 0x10;
    local_2c = 0x16;
    local_28 = &DAT_00000005;
  }
  else {
    iVar4 = 0x14;
    local_2c = 0x1b;
    local_28 = (undefined1 *)0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_44 = (CDC *)0x440d9f;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_44 = (CDC *)0x440dad;
  FUN_0046bf33(&param_1,s___STRATEGY_for_BEATING_IN_AN_OSC_0049a9e4);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  iVar11 = *(int *)(param_1 + -8);
  pCStack_44 = param_1;
  iStack_48 = 2;
  puStack_4c = local_28;
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  iStack_c = unaff_EDI + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&local_2c,s_An_oscillating_wind_is_one_which_0049a988);
    uStack_14 = 1;
    iVar9 = iStack_c;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    apuStack_1c[0] = apuStack_1c[0] + (int)puStack_4c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_of_the_race__In_an_oscillating_w_0049a92c);
    uStack_24 = 2;
    iVar10 = iStack_48;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_4c);
    local_2c = local_2c + iVar4;
    FUN_0046bf33(&puStack_4c,s_by_tacking_at_the_right_times__0049a90c);
    iVar12 = local_2c;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa4);
    unaff_EDI = unaff_EDI + iVar10;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffa4,s_Boat_A_and_Boat_B_are_even__The_w_0049a8c8);
    pCStack_44 = (CDC *)0x4;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff94);
    puStack_4c = puStack_4c + iVar9;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0xff);
    }
    FUN_0046bf33(&stack0xffffff94,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)(iVar12,puStack_4c,iVar10,*(undefined4 *)(iVar10 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_2c);
  }
  if (DAT_004a6774 == 1) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&local_2c,s_The_wind_swings_20_degrees_to_th_0049a884);
    uStack_14 = 6;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    apuStack_1c[0] = apuStack_1c[0] + iVar4;
    FUN_0046bf33(&stack0xffffffc4,s_Both_boats_are_headed_20_degrees_0049a854);
    uStack_24 = 7;
    iVar9 = iStack_48;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_4c);
    local_2c = local_2c + iVar4;
    FUN_0046bf33(&puStack_4c,s_Boat_A_and_Boat_B_are_almost_eve_0049a810);
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa4);
    unaff_EDI = unaff_EDI + iVar9;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffa4,s_Click_the_Advance_Position_Butto_00499e34);
    pCStack_44 = (CDC *)0x9;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_2c);
  }
  if (DAT_004a6774 == 2) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&local_2c,s_They_sail_some_distance__0049a7f4);
    uStack_14 = 10;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    apuStack_1c[0] = apuStack_1c[0] + (int)puStack_4c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_24 = 0xb;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_2c);
  }
  if (DAT_004a6774 == 3) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&local_2c,s_The_wind_swings_20_degrees_to_th_0049a7ac);
    uStack_14 = 0xc;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    apuStack_1c[0] = apuStack_1c[0] + (int)puStack_4c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_24 = 0xd;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_2c);
  }
  if (DAT_004a6774 == 4) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&local_2c,s_By_tacking_when_headed_relative_t_0049a754);
    uStack_14 = 0xe;
    iVar10 = unaff_ESI;
    iVar7 = iStack_c;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    apuStack_1c[0] = apuStack_1c[0] + iVar4;
    FUN_0046bf33(&stack0xffffffc4,s_Boat_A_will_finish_the_leg_saili_0049a704);
    uStack_24 = 0xf;
    iVar12 = iStack_48;
    puVar6 = apuStack_1c[0];
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_4c);
    local_2c = local_2c + iVar4;
    FUN_0046bf33(&puStack_4c,s_even_though_the_wind_shifts_were_0049a6b4);
    iVar9 = local_2c;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa4);
    unaff_EDI = unaff_EDI + iVar12;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffa4,s_When_the_wind_is_near_the_averag_0049a660);
    pCStack_44 = (CDC *)0x11;
    iVar8 = unaff_EDI;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff94);
    puStack_4c = puStack_4c + iVar4;
    FUN_0046bf33(&stack0xffffff94,s_from_the_nearest_layline_since_a_0049a610);
    puVar5 = puStack_4c;
    (*pcVar1)(iVar9,puStack_4c,iVar12,*(undefined4 *)(iVar12 + -8));
    FUN_0046bec5((int *)&stack0xffffff84);
    puVar3 = puVar6 + iVar10;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0xff0000);
    }
    FUN_0046bf33(&stack0xffffff84,s_Boats_which_lose_significant_dis_0049a5c0);
    (*pcVar1)(iVar8,puVar3,iVar7,*(undefined4 *)(iVar7 + -8));
    FUN_0046bec5((int *)&stack0xffffff74);
    FUN_0046bf33(&stack0xffffff74,s_will_not_gain_by_tacking_on_very_0049a590);
    (*pcVar1)(puVar5,iVar4 + iVar12,puVar6,*(undefined4 *)(puVar6 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&local_2c);
  }
  FUN_0044d830((int *)this,unaff_ESI,iVar4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_004414c3;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_004414c3;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_004414c3:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 4;
  FUN_0044d6d0((int *)this);
  DAT_004ac994 = 2;
  uStack_20 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  local_2c = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,iVar12,local_2c,4,1);
  FUN_0046bf33(&iStack_c,&DAT_00493460);
  uStack_14 = 0x15;
  iVar9 = *(int *)(iStack_c + -8);
  (*pcVar1)();
  uStack_24 = 0xffffffff;
  FUN_0046bec5((int *)apuStack_1c);
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar11,unaff_EDI);
    apuStack_1c[0] = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)apuStack_1c[0],(int)puStack_4c);
    iStack_48 = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    uStack_24 = 0x16;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar9,(int)puStack_4c);
    local_2c = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    pcVar14 = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,local_2c,(int)pcVar14);
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    iVar10 = iStack_48;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    pcVar13 = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)&stack0xffffff94,0,(int)pcVar13);
    CDC::LineTo(this,DAT_004a763c,(int)pcVar13);
    (*pcVar14)();
    FUN_0046bf33(&pCStack_44,s_Equal_Position_Line_004994f4);
    puStack_4c = (undefined1 *)0x18;
    (*pcVar1)(DAT_004a763c / 5,iVar10);
    FUN_0046bec5((int *)&stack0xffffffac);
    (*pcVar13)(0);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar8 = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar7,puVar6,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff8c,s_Boat_A_004994e4);
    (*pcVar1)(iVar8 + iVar7,puVar6 + iVar4,iVar10,*(undefined4 *)(iVar10 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
    iVar10 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar7 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar10,puVar6,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_B_004994ec);
    (*pcVar1)(iVar10 - iVar7,puVar6 + iVar4,iVar8,*(undefined4 *)(iVar8 + -8));
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  if (DAT_004a6774 == 1) {
    DAT_004ac840 = 0x1e;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar11,unaff_EDI);
    apuStack_1c[0] = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)apuStack_1c[0],(int)puStack_4c);
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    uStack_24 = 0x1b;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar9,(int)puStack_4c);
    local_2c = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    CDC::LineTo(this,local_2c,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8));
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    DAT_004a8e88 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    DAT_004a4eb8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar10 = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x19;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,DAT_004a8e88,DAT_004a4eb8,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffc0,s_Boat_A_004994e4);
    iStack_48 = 0x1d;
    (*pcVar1)(DAT_004a8e88 + iVar10);
    FUN_0046bec5((int *)&stack0xffffffb0);
    DAT_004a7638 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    DAT_004a6224 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar10 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x127;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,DAT_004a7638,DAT_004a6224,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffb0,s_Boat_B_004994ec);
    (*pcVar1)(DAT_004a7638 - iVar10,DAT_004a6224 + iVar4,iVar9,*(undefined4 *)(iVar9 + -8));
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)apuStack_1c);
  }
  if (DAT_004a6774 == 2) {
    DAT_004ac840 = 0x1e;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar11,unaff_EDI);
    apuStack_1c[0] = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)apuStack_1c[0],(int)puStack_4c);
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    uStack_24 = 0x1f;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar9,(int)puStack_4c);
    local_2c = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    CDC::LineTo(this,local_2c,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8));
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    DAT_004abefc = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    DAT_004abdd8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar10 = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x19;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,DAT_004abefc,DAT_004abdd8,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffc0,s_Boat_A_004994e4);
    iStack_48 = 0x21;
    (*pcVar1)(DAT_004abefc + iVar10);
    FUN_0046bec5((int *)&stack0xffffffb0);
    DAT_004a4030 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    DAT_004abdd0 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    iVar10 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x127;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,DAT_004a4030,DAT_004abdd0,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffb0,s_Boat_B_004994ec);
    (*pcVar1)(DAT_004a4030 - iVar10,DAT_004abdd0 + iVar4,iVar9,*(undefined4 *)(iVar9 + -8));
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)apuStack_1c);
  }
  if (DAT_004a6774 == 3) {
    DAT_004ac840 = 0xffffffec;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,iVar11,unaff_EDI);
    apuStack_1c[0] = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)apuStack_1c[0],(int)puStack_4c);
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    uStack_24 = 0x23;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar9,(int)puStack_4c);
    local_2c = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    CDC::LineTo(this,local_2c,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50));
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    DAT_004aa968 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    DAT_004aaa40 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar11 = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,DAT_004aa968,DAT_004aaa40,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffc0,s_Boat_A_004994e4);
    iStack_48 = 0x25;
    (*pcVar1)(DAT_004aa968 + iVar11);
    FUN_0046bec5((int *)&stack0xffffffb0);
    DAT_004ac098 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    DAT_004a679c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    iVar11 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x41;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,DAT_004ac098,DAT_004a679c,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffb0,s_Boat_B_004994ec);
    (*pcVar1)(DAT_004ac098 - iVar11,DAT_004a679c + iVar4,iVar9,*(undefined4 *)(iVar9 + -8));
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)apuStack_1c);
  }
  if (DAT_004a6774 == 4) {
    DAT_004ac840 = 0xffffffec;
    apuStack_1c[0] = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    iStack_48 = DAT_004a763c / 0x14;
    if ((DAT_004ac92c == 0) && (DAT_004ac854 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,(int)apuStack_1c[0],(int)puStack_4c);
    CDC::LineTo(this,DAT_004aa968,(int)DAT_004aaa40);
    CDC::LineTo(this,DAT_004abefc,(int)DAT_004abdd8);
    CDC::LineTo(this,DAT_004a8e88,(int)DAT_004a4eb8);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)apuStack_1c[0],puStack_4c,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffc8,s_Boat_A_004994e4);
    uStack_24 = 0x27;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    local_2c = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    if ((DAT_004ac92c == 0) && (DAT_004a3c0c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,&iStack_48,local_2c,(int)puVar6);
    CDC::LineTo(this,DAT_004ac098,(int)DAT_004a679c);
    CDC::LineTo(this,DAT_004a4030,(int)DAT_004abdd0);
    CDC::LineTo(this,DAT_004a7638,(int)DAT_004a6224);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x41;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,local_2c,puVar6,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_48,s_Boat_B_004994ec);
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = iVar12;
  *unaff_FS_OFFSET = local_2c;
  return;
}


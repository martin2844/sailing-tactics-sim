
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043ccd0(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *this;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int unaff_EBX;
  int iVar7;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined *puVar8;
  int iVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  CDC *pCVar14;
  code *pcVar15;
  HDC hdc;
  HGDIOBJ h;
  int iStack_48;
  int iStack_44;
  CDC *pCStack_40;
  int local_28 [3];
  CDC *local_1c [2];
  undefined4 uStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f4c0;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar7 = 0x10;
    local_28[2] = 0x16;
    local_28[0] = 5;
    local_1c[0] = (CDC *)0xa;
  }
  else {
    iVar7 = 0x14;
    local_28[2] = 0x1b;
    local_28[0] = 0x14;
    local_1c[0] = (CDC *)0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_40 = (CDC *)0x43cd5b;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_40 = (CDC *)0x43cd69;
  FUN_0046bf33(&param_1,s___LIFTS_WHILE_BEATING___00499c3c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  pcVar6 = *(code **)(param_1 + -8);
  pCStack_40 = param_1;
  iStack_44 = 2;
  iStack_48 = local_28[0];
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  iStack_c = unaff_EBP + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  iStack_c = iStack_c + iVar7;
  if (DAT_004a6774 == 0) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffcc,s_A_lift_is_a_windshift_that_lets_a_00499be8);
    uStack_14 = 1;
    (*pcVar1)();
    local_28[1] = 0xffffffff;
    FUN_0046bec5(&iStack_44);
    local_1c[0] = local_1c[0] + (int)pCStack_40;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_44,s_Boats_A_and_B_are_initially_even_00499bc4);
    local_28[1] = 2;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    unaff_EBX = unaff_EBX + unaff_ESI;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffac,s_Click_the_Advance_Position_Butto_00499b8c);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffcc);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(local_28,s_Boat_A_has_just_gained_a_lot__00499b6c);
    uStack_14 = 4;
    iVar4 = local_28[0];
    (*pcVar1)();
    local_28[1] = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
    local_1c[0] = local_1c[0] + (int)pCStack_40;
    FUN_0046bf33(&stack0xffffffc8,s_Notice_that_the_laylines_and_the_00499b24);
    local_28[1] = 5;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    unaff_EBX = unaff_EBX + iVar4;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&iStack_48,s_Click_the_Advance_Position_Butto_00499ae4);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(local_28);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(local_28,s_Boat_A_has_gained_30___of_the_se_00499a8c);
    uStack_14 = 7;
    iVar4 = *(int *)(local_28[0] + -8);
    (*pcVar1)();
    local_28[1] = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
    local_1c[0] = local_1c[0] + iVar7;
    FUN_0046bf33(&stack0xffffffc8,s_about_two_boat_lengths__If_the_b_00499a38);
    local_28[1] = 8;
    iVar13 = iStack_44;
    pCVar14 = local_1c[0];
    iVar3 = unaff_EDI;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    unaff_EBX = unaff_EBX + iVar7;
    FUN_0046bf33(&iStack_48,s_occurred__Boat_A_would_have_gain_00499a04);
    iVar12 = unaff_EBX;
    iVar5 = iStack_48;
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    pcVar6 = pcVar6 + iVar3;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffa8,s_If_the_shift_was_only_10_degrees_004999bc);
    iStack_44 = 10;
    (*pcVar1)(pCVar14);
    FUN_0046bec5((int *)&stack0xffffff98);
    iVar4 = iVar4 + iVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0xff);
    }
    FUN_0046bf33(&stack0xffffff98,s_Click_the_Advance_Position_Butto_00499984);
    (*pcVar1)(iVar12,iVar4,iVar13,*(undefined4 *)(iVar13 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(local_28);
  }
  if (DAT_004a6774 == 3) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(local_28,s_Using_the_compass_to_detect_a_wi_00499958);
    uStack_14 = 0xc;
    iVar4 = *(int *)(local_28[0] + -8);
    (*pcVar1)();
    local_28[1] = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
    local_1c[0] = local_1c[0] + iVar7;
    FUN_0046bf33(&stack0xffffffc8,s_If_a_closehauled_boat_is_being_s_004998fc);
    local_28[1] = 0xd;
    iVar12 = iStack_44;
    pCVar14 = local_1c[0];
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    iVar5 = unaff_EBX + iVar7;
    FUN_0046bf33(&iStack_48,s_true_wind_changes_20_degrees_pro_004998a0);
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    pcVar6 = pcVar6 + iVar7;
    FUN_0046bf33(&stack0xffffffa8,s_crew_compares_the_compass_course_00499844);
    iStack_44 = 0xf;
    (*pcVar1)(pCVar14);
    FUN_0046bec5((int *)&stack0xffffff98);
    FUN_0046bf33(&stack0xffffff98,s_much_the_wind_has_shifted__00499828);
    (*pcVar1)(iVar5,iVar7 + iVar4,iVar12,*(undefined4 *)(iVar12 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(local_28);
  }
  FUN_0044d830((int *)this,unaff_EDI,iVar7);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043d323;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043d323;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043d323:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 3;
  FUN_0044d6d0((int *)this);
  DAT_004ac994 = 2;
  local_28[2] = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,iVar12,iVar5,4,1);
  FUN_0046bf33(&iStack_c,&DAT_00493460);
  uStack_14 = 0x11;
  iVar4 = *(int *)(iStack_c + -8);
  iVar13 = iStack_c;
  (*pcVar1)();
  local_28[1] = 0xffffffff;
  FUN_0046bec5((int *)local_1c);
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,(int)pCStack_40,(int)pcVar6);
    local_1c[0] = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iStack_48 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)local_1c[0],iStack_48);
    iStack_44 = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    local_28[1] = 0x12;
    iVar11 = unaff_EDI;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar13,iVar4);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,iVar5,iVar3);
    pcVar15 = (code *)(DAT_004a763c / 0x19);
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    iVar3 = iVar3 + iVar7 * -2;
    iVar9 = iStack_48;
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    pcVar6 = *(code **)(*(int *)this + 0x38);
    (*pcVar6)();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar4 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)&stack0xffffffa4,0,iVar4);
    CDC::LineTo(this,DAT_004a763c,iVar4);
    (*(code *)pCStack_40)();
    FUN_0046bf33(&stack0xffffffa0,s_Equal_Position_Line_004994f4);
    iVar4 = 0x14;
    (*pcVar1)((DAT_004a763c * 2) / 5,iVar9,iVar11);
    FUN_0046bec5((int *)&stack0xffffff90);
    (*pcVar15)(0);
    iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar11 = DAT_004a763c / 10;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar9,puVar10,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff8c,s_Boat_A_004994e4);
    (*pcVar1)(iVar9 - iVar11,puVar10 + iVar7,iVar3,*(undefined4 *)(iVar3 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
    iVar3 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar9 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar3,puVar8,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_B_004994ec);
    (*pcVar1)(iVar3 - iVar9,puVar8 + iVar7,puVar10,*(undefined4 *)(puVar10 + -8));
    local_28[1] = 0xffffffff;
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
    FUN_004706bd(this,(int *)&stack0xffffffc8,(int)pCStack_40,(int)pcVar6);
    local_1c[0] = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iStack_48 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)local_1c[0],iStack_48);
    iStack_44 = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    local_28[1] = 0x17;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar13,iVar4);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,iVar5,iVar3);
    pcVar15 = (code *)(DAT_004a763c / 0x19);
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    iVar3 = iVar3 + iVar7 * -2;
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    pcVar6 = *(code **)(*(int *)this + 0x38);
    (*pcVar6)();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)&stack0xffffffa4,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8));
    (*(code *)pCStack_40)();
    FUN_0046bf33(&stack0xffffffa0,s_Equal_Position_Line_004994f4);
    iVar4 = 0x19;
    (*pcVar1)((DAT_004a763c * 2) / 5,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),unaff_EDI);
    FUN_0046bec5((int *)&stack0xffffff90);
    (*pcVar15)(0);
    iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar11 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar9,puVar10,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff8c,s_Boat_A_004994e4);
    (*pcVar1)(iVar9 - iVar11,puVar10 + iVar7,iVar3,*(undefined4 *)(iVar3 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
    iVar3 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar9 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar3,puVar8,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_B_004994ec);
    (*pcVar1)(iVar3 - iVar9,puVar8 + iVar7,puVar10,*(undefined4 *)(puVar10 + -8));
    local_28[1] = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  if (1 < DAT_004a6774) {
    DAT_004ac840 = 0xffffffec;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,(int)pCStack_40,(int)pcVar6);
    local_1c[0] = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iStack_48 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)local_1c[0],iStack_48);
    iStack_44 = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    local_28[1] = 0x1c;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar13,iVar4);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    CDC::LineTo(this,iVar5,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50));
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    (*pcVar1)();
    iStack_44 = -1;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    pCStack_40 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    iVar4 = DAT_004a763c / 10;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)pCStack_40,puVar10,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffa4,s_Boat_A_004994e4);
    iStack_48 = 0x1e;
    (*pcVar1)((int)pCStack_40 - iVar4,puVar10 + iVar7);
    FUN_0046bec5((int *)&stack0xffffff94);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar13 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x41;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar4,puVar8,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff94,s_Boat_B_004994ec);
    (*pcVar1)(iVar4 - iVar13,puVar8 + iVar7,puVar10,*(undefined4 *)(puVar10 + -8));
    local_28[1] = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = iVar12;
  *unaff_FS_OFFSET = iVar5;
  return;
}


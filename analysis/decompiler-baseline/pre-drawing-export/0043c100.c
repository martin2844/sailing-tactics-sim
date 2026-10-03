
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043c100(CDC *param_1)

{
  code *pcVar1;
  undefined *puVar2;
  double dVar3;
  CDC *this;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  int unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined *puVar6;
  int iVar7;
  undefined *puVar8;
  code *pcVar9;
  undefined *puStack_ec;
  int iStack_e8;
  int iVar10;
  code *pcVar11;
  HDC hdc;
  int iVar12;
  HGDIOBJ h;
  code *pcStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_b8;
  int iStack_b4;
  int iStack_b0;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iVar13;
  int iStack_68;
  int iStack_64;
  undefined4 uStack_60;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_48;
  int iStack_44;
  CDC *pCStack_40;
  int local_24;
  int aiStack_1c [2];
  undefined4 uStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f3a8;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  DAT_004ac840 = 0;
  if (DAT_004a763c < 700) {
    iVar4 = 0x10;
    local_24 = 5;
  }
  else {
    iVar4 = 0x14;
    local_24 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_40 = (CDC *)0x43c193;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_40 = (CDC *)0x43c1a1;
  FUN_0046bf33(&param_1,s___BASIC_CONCEPTS___CONSEQUENCES_O_004997e8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  iVar7 = *(int *)(param_1 + -8);
  pCStack_40 = param_1;
  iStack_44 = 2;
  iStack_48 = local_24;
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    iStack_50 = 0x43c1e8;
    (**(code **)(*(int *)this + 0x38))();
  }
  iStack_50 = 0x43c1f6;
  FUN_0046bf33(&iStack_c,s_Laylines__A_closehauled_boat_on_a_00499784);
  uStack_14 = 1;
  iVar10 = *(int *)(iStack_c + -8);
  iStack_50 = iStack_c;
  iStack_58 = unaff_ESI;
  iStack_54 = unaff_EBP + 2;
  (*pcVar1)();
  FUN_0046bec5(aiStack_1c);
  iVar5 = unaff_EBP + 2 + iVar4;
  uStack_60 = 0x43c232;
  FUN_0046bf33(&stack0xffffffc8,s_laylines_are_beating__A_boat_out_00499720);
  iStack_68 = iStack_48 + iStack_44;
  iVar12 = *(int *)(unaff_EDI + -8);
  iStack_64 = iVar5;
  aiStack_1c[0] = iStack_68;
  (*pcVar1)();
  FUN_0046bec5(&iStack_48);
  if (DAT_004ac92c == 0) {
    iStack_70 = 0x43c27d;
    (**(code **)(*(int *)this + 0x38))();
  }
  iVar5 = iVar5 + iStack_50;
  iStack_70 = 0x43c291;
  FUN_0046bf33(&iStack_48,s_Equal_position_Line__This_is_a_l_004996c4);
  iVar13 = *(int *)(iStack_48 + -8);
  iStack_70 = iStack_48;
  iStack_78 = iStack_54;
  iStack_74 = iVar5;
  (*pcVar1)();
  iStack_44 = 0xffffffff;
  FUN_0046bec5(&iStack_58);
  iVar5 = iVar5 + iVar4;
  iStack_80 = 0x43c2cd;
  iStack_88 = iVar7;
  FUN_0046bf33(&iStack_58,s_line_are_equally_upwind__Provide_00499668);
  iStack_44 = 4;
  pcVar11 = *(code **)(iStack_58 + -8);
  iStack_80 = iStack_58;
  iStack_84 = iVar5;
  (*pcVar1)();
  iStack_54 = 0xffffffff;
  FUN_0046bec5(&iStack_68);
  iVar5 = iVar5 + iVar4;
  iStack_90 = 0x43c309;
  iStack_98 = iVar10;
  FUN_0046bf33(&iStack_68,s_If_boat_A_tacks__they_will_conve_00499620);
  iStack_54 = 5;
  iStack_90 = iStack_68;
  iStack_94 = iVar5;
  (*pcVar1)();
  iStack_64 = 0xffffffff;
  FUN_0046bec5(&iStack_78);
  iStack_a8 = iVar12;
  if (DAT_004ac92c == 0) {
    iStack_a0 = 0x43c347;
    (**(code **)(*(int *)this + 0x38))();
    iStack_a8 = iVar12;
  }
  iVar5 = iVar5 + iVar4;
  iStack_a0 = 0x43c357;
  FUN_0046bf33(&iStack_78,s_If_the_wind_shifts__the_equal_po_004995c8);
  iStack_64 = 6;
  iStack_a0 = iStack_78;
  iStack_a4 = iVar5;
  (*pcVar1)();
  iStack_74 = 0xffffffff;
  FUN_0046bec5(&iStack_88);
  iVar5 = iVar5 + iVar4;
  iStack_b0 = 0x43c393;
  iStack_b8 = iVar13;
  FUN_0046bf33(&iStack_88,s_The_boats_are_no_longer_even__Th_00499568);
  iStack_74 = 7;
  iStack_b0 = iStack_88;
  iStack_b4 = iVar5;
  (*pcVar1)();
  iStack_84 = 0xffffffff;
  FUN_0046bec5(&iStack_98);
  iStack_c0 = 0x43c3cd;
  pcStack_c8 = pcVar11;
  FUN_0046bf33(&iStack_98,s_distance_between_the_boats__Doub_00499510);
  iStack_c4 = iVar4 + iVar5;
  iStack_84 = 8;
  iStack_c0 = iStack_98;
  (*pcVar1)();
  iStack_94 = 0xffffffff;
  FUN_0046bec5(&iStack_a8);
  FUN_0044d830((int *)this,iStack_b4,iVar4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043c450;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043c450;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043c450:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 2;
  FUN_0044d6d0((int *)this);
  DAT_004ac994 = 2;
  iStack_a0 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iStack_b0 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  iVar7 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484f18);
  if (DAT_004ac854 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(this + 4),DAT_004ac854);
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  FUN_004706bd(this,&iStack_a8,iStack_b0,iVar7);
  iStack_b4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
  iStack_b8 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
  CDC::LineTo(this,iStack_b4,iStack_b8);
  FUN_0046bf33(&iStack_a8,s_LayLine_00499508);
  iStack_94 = 9;
  iVar5 = iStack_b8 + iVar4 * -2;
  iVar12 = iStack_a8;
  (*pcVar1)();
  iStack_a4 = 0xffffffff;
  FUN_0046bec5(&iStack_b8);
  iStack_e8 = 0x43c5be;
  FUN_004706bd(this,&iStack_b8,iStack_c0,iVar7);
  iStack_c4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d70);
  pcStack_c8 = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
  CDC::LineTo(this,iStack_c4,(int)pcStack_c8);
  iVar10 = DAT_004a763c / 0x18;
  FUN_0046bf33(&iStack_b8,s_LayLine_00499508);
  iStack_a4 = 10;
  pcVar11 = *(code **)(iStack_b8 + -8);
  iStack_e8 = iStack_c4 - iVar10;
  puStack_ec = (undefined *)0x43c648;
  (*pcVar1)();
  iStack_b4 = 0xffffffff;
  puStack_ec = (undefined *)0x43c659;
  FUN_0046bec5((int *)&pcStack_c8);
  puStack_ec = (undefined *)0x0;
  pcStack_c8 = *(code **)(*(int *)this + 0x38);
  (*pcStack_c8)();
  FUN_0042cd40((int *)this,iVar5,iVar7,4,1);
  FUN_0046bf33(&iStack_b0,&DAT_00493460);
  iStack_b8 = 0xb;
  pcVar9 = *(code **)(iStack_b0 + -8);
  (*pcVar1)();
  pcStack_c8 = (code *)0xffffffff;
  FUN_0046bec5(&iStack_c0);
  if (DAT_004a6774 < 2) {
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar7 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)&stack0xffffff1c,0,iVar7);
    CDC::LineTo(this,DAT_004a763c,iVar7);
    (*pcVar11)();
    FUN_0046bf33(&iStack_c4,s_Equal_Position_Line_004994f4);
    (*pcVar1)((DAT_004a763c * 2) / 5);
    FUN_0046bec5((int *)&stack0xffffff2c);
    (*pcVar9)(0);
  }
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = 0;
    puStack_ec = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iStack_c0 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),puStack_ec,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff24,s_Boat_B_004994ec);
    pcStack_c8 = (code *)0xd;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_ec);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    iVar12 = DAT_004a763c / 0xe;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar7,puVar8,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&puStack_ec,s_Boat_A_004994e4);
    puVar6 = puStack_ec;
    (*pcVar1)(iVar7 - iVar12,puVar8 + iVar4,puStack_ec,*(undefined4 *)(puStack_ec + -8));
    iStack_e8 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffff04);
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484e50);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    _DAT_004aa73c = 1;
    iVar10 = DAT_004a763c / 100;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 10;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x145;
    _DAT_004a7bd4 = 0x37;
    FUN_00411000(this,iVar7,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff04,s_Boat_C__004994dc);
    iStack_e8 = 0xf;
    (*pcVar1)(iVar7 + iVar10,puVar2 + iVar4 * -2,puVar8,*(undefined4 *)(puVar8 + -8));
    FUN_0046bec5((int *)&stack0xfffffef4);
    FUN_0046bf33(&stack0xffffff10,s_Overstanding_004994cc);
    (*pcVar1)(puVar6,(int)puVar2 - iVar4,pcVar9,*(undefined4 *)(pcVar9 + -8));
    pcStack_c8 = (code *)0xffffffff;
    FUN_0046bec5(&iStack_c0);
  }
  if (DAT_004a6774 == 1) {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),2,1,DAT_004a72d0,0);
  }
  if (DAT_004a6774 == 2) {
    _DAT_004a77ec = 2;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f18),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = iVar5;
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = iVar12;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043c100(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  double dVar6;
  CDC *this;
  uint uVar7;
  CDC *pCVar8;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_28;
  int local_24;
  CDC *local_20 [2];
  code *apcStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar6 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f3a8;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar6;
  DAT_004ac840 = 0;
  if (DAT_004a763c < 700) {
    uVar7 = 0x10;
    local_20[0] = (CDC *)0x16;
    local_24 = 5;
    local_28 = 10;
  }
  else {
    uVar7 = 0x14;
    local_20[0] = (CDC *)0x1b;
    local_24 = 0x14;
    local_28 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___BASIC_CONCEPTS___CONSEQUENCES_O_004997e8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_24,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar8 = local_20[0] + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&param_1,s_Laylines__A_closehauled_boat_on_a_00499784);
  uStack_4 = 1;
  (*pcVar1)(this,local_24,(int)pCVar8,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar8 = pCVar8 + uVar7;
  FUN_0046bf33(apcStack_18,s_laylines_are_beating__A_boat_out_00499720);
  param_1 = (CDC *)(local_28 + local_24);
  uStack_4 = 2;
  (*pcVar1)(this,(int)param_1,(int)pCVar8,(LPCSTR)apcStack_18[0],*(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f00);
  }
  pCVar8 = pCVar8 + (int)local_20[0];
  FUN_0046bf33(apcStack_18,s_Equal_position_Line__This_is_a_l_004996c4);
  uStack_4 = 3;
  (*pcVar1)(this,local_24,(int)pCVar8,(LPCSTR)apcStack_18[0],*(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  pCVar8 = pCVar8 + uVar7;
  FUN_0046bf33(apcStack_18,s_line_are_equally_upwind__Provide_00499668);
  uStack_4 = 4;
  (*pcVar1)(this,(int)param_1,(int)pCVar8,(LPCSTR)apcStack_18[0],*(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  pCVar8 = pCVar8 + uVar7;
  FUN_0046bf33(apcStack_18,s_If_boat_A_tacks__they_will_conve_00499620);
  uStack_4 = 5;
  (*pcVar1)(this,(int)param_1,(int)pCVar8,(LPCSTR)apcStack_18[0],*(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0);
  }
  pCVar8 = pCVar8 + uVar7;
  FUN_0046bf33(apcStack_18,s_If_the_wind_shifts__the_equal_po_004995c8);
  uStack_4 = 6;
  (*pcVar1)(this,(int)param_1,(int)pCVar8,(LPCSTR)apcStack_18[0],*(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  FUN_0046bf33(apcStack_18,s_The_boats_are_no_longer_even__Th_00499568);
  uStack_4 = 7;
  (*pcVar1)(this,(int)param_1,(int)(pCVar8 + uVar7),(LPCSTR)apcStack_18[0],
            *(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  FUN_0046bf33(apcStack_18,s_distance_between_the_boats__Doub_00499510);
  uStack_4 = 8;
  (*pcVar1)(this,(int)param_1,(int)(pCVar8 + uVar7 + uVar7),(LPCSTR)apcStack_18[0],
            *(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  FUN_0044d830((int)this,local_24,uVar7);
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
  FUN_0044d6d0((int)this,uVar7);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  local_20[0] = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484f18);
  if (DAT_004ac854 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(this + 4),DAT_004ac854);
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f);
  }
  FUN_004706bd(this,(int *)apcStack_18,(int)local_20[0],iVar2);
  iVar3 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
  iVar4 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
  CDC::LineTo(this,iVar3,iVar4);
  param_1 = (CDC *)(DAT_004a763c / 0x32);
  FUN_0046bf33(apcStack_18,s_LayLine_00499508);
  uStack_4 = 9;
  (*pcVar1)(this,iVar3 - (int)param_1,iVar4 + uVar7 * -2,(LPCSTR)apcStack_18[0],
            *(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  FUN_004706bd(this,(int *)apcStack_18,(int)local_20[0],iVar2);
  iVar3 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d70);
  iVar4 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
  CDC::LineTo(this,iVar3,iVar4);
  param_1 = (CDC *)(DAT_004a763c / 0x18);
  FUN_0046bf33(apcStack_18,s_LayLine_00499508);
  uStack_4 = 10;
  (*pcVar1)(this,iVar3 - (int)param_1,iVar4 + uVar7 * -2,(LPCSTR)apcStack_18[0],
            *(int *)(apcStack_18[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apcStack_18);
  apcStack_18[0] = *(code **)(*(int *)this + 0x38);
  (*apcStack_18[0])(this,0);
  FUN_0042cd40((int *)this,(int)local_20[0],iVar2,4,1);
  FUN_0046bf33(&param_1,&DAT_00493460);
  uStack_4 = 0xb;
  (*pcVar1)(this,(int)(local_20[0] + DAT_004a763c / 100),iVar2 - uVar7 / 2,(LPCSTR)param_1,
            *(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004a6774 < 2) {
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)local_20,0,iVar2);
    CDC::LineTo(this,DAT_004a763c,iVar2);
    (*apcStack_18[0])(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0xc;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,iVar2,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*apcStack_18[0])(this,0);
  }
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = 0;
    iVar2 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar5 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    param_1 = (CDC *)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar2,puVar5,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_B_004994ec);
    uStack_4 = 0xd;
    (*pcVar1)(this,iVar2 - (int)param_1,(int)(puVar5 + uVar7),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    iVar2 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar5 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    param_1 = (CDC *)(DAT_004a763c / 0xe);
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar2,puVar5,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
    uStack_4 = 0xe;
    (*pcVar1)(this,iVar2 - (int)param_1,(int)(puVar5 + uVar7),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    iVar2 = (int)(longlong)(_DAT_004aa810 * _DAT_00484e50);
    puVar5 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    _DAT_004aa73c = 1;
    param_1 = (CDC *)(DAT_004a763c / 100);
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 10;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x145;
    _DAT_004a7bd4 = 0x37;
    FUN_00411000(this,iVar2,puVar5,3,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_C__004994dc);
    local_20[0] = param_1 + iVar2;
    uStack_4 = 0xf;
    (*pcVar1)(this,(int)local_20[0],(int)(puVar5 + uVar7 * -2),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    FUN_0046bf33(&param_1,s_Overstanding_004994cc);
    uStack_4 = 0x10;
    (*pcVar1)(this,(int)local_20[0],(int)puVar5 - uVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
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
  DAT_004a4e8c = uStack_10;
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


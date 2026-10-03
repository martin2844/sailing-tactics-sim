
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00435b50(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *pCVar3;
  int iVar4;
  int unaff_EBP;
  int unaff_ESI;
  int iVar5;
  int *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iVar6;
  undefined4 uVar7;
  CDC *pCVar8;
  int iVar9;
  int iStack_7c;
  int iStack_6c;
  CDC *pCStack_5c;
  int iStack_4c;
  int iStack_3c;
  CDC *pCStack_2c;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar3 = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047ed60;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar4 = 5;
  }
  else {
    iVar4 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_2c = (CDC *)0x435bcf;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_2c = (CDC *)0x435bdd;
  FUN_0046bf33(&param_1,s___RACING_RULES_TUTORIAL_INTRODUC_00497278);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)pCVar3 + 100);
  pCStack_2c = param_1;
  (*pcVar1)();
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    iStack_3c = 0x435c27;
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  iStack_3c = 0x435c35;
  FUN_0046bf33(&iStack_c,s_This_tutorial_covers_essentially_0049721c);
  iStack_3c = iStack_c;
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffe4);
  iStack_4c = 0x435c71;
  FUN_0046bf33(&stack0xffffffe4,s_non_right_of_way_rules__you_will_004971c0);
  iStack_4c = unaff_EBP;
  (*pcVar1)();
  FUN_0046bec5((int *)&pCStack_2c);
  if (DAT_004ac92c == 0) {
    pCStack_5c = (CDC *)0x435cb4;
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  pCStack_5c = (CDC *)0x435cc2;
  FUN_0046bf33(&pCStack_2c,s_Move_through_this_tutorial_with_t_0049715c);
  pCStack_5c = pCStack_2c;
  (*pcVar1)();
  FUN_0046bec5(&iStack_3c);
  iVar5 = (unaff_ESI + 2) * 4 + iVar4 * 3;
  iStack_6c = 0x435cfe;
  FUN_0046bf33(&iStack_3c,s_Tutorial_pages_have_a_control_bu_004970f4);
  iStack_6c = iStack_3c;
  (*pcVar1)();
  FUN_0046bec5(&iStack_4c);
  if (DAT_004ac92c == 0) {
    iStack_7c = 0x435d3b;
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  iStack_7c = 0x435d4f;
  FUN_0046bf33(&iStack_4c,s_This_tutorial_is_based_on_the_20_004970a0);
  iStack_7c = iStack_4c;
  iVar9 = iVar4;
  (*pcVar1)(iVar4,iVar5);
  FUN_0046bec5((int *)&pCStack_5c);
  iVar5 = iVar5 + iVar4;
  FUN_0046bf33(&pCStack_5c,s_United_States_Sailing_Associatio_00497050);
  iVar6 = iVar4;
  pCVar8 = pCStack_5c;
  (*pcVar1)(iVar4,iVar5,pCStack_5c,*(undefined4 *)(pCStack_5c + -8));
  FUN_0046bec5(&iStack_6c);
  FUN_0046bf33(&iStack_6c,s_Portsmouth__RI_02871_00497038);
  (*pcVar1)(iVar4,iVar9 + iVar5,iStack_6c,*(undefined4 *)(iStack_6c + -8));
  FUN_0046bec5(&iStack_7c);
  FUN_0044d830((int *)pCVar3,iVar4,iVar6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00435e43;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00435e43;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00435e43:
  Rectangle(*(HDC *)(pCVar3 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 2;
  FUN_0044d6d0((int *)pCVar3);
  uVar7 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  FUN_0042cd40((int *)pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484d98),
               (int)(longlong)(_DAT_004aa7d8 * _DAT_00484f78),4,1);
  if (DAT_004a6774 == 0) {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484da8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),2,1,DAT_004a72d0,0);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50),3,1,DAT_004a72d0,0);
  }
  if (DAT_004a6774 == 1) {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484d98),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484d90),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),2,1,DAT_004a72d0,0);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484ec8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),3,1,DAT_004a72d0,0);
  }
  if (DAT_004a6774 == 2) {
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x2d;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484f10),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484d90),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,DAT_004a72d0,0);
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x2d;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),3,1,DAT_004a72d0,0);
  }
  DAT_004a4e8c = uVar7;
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = (int)pCVar8;
  return;
}


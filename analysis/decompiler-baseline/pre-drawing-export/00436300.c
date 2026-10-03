
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00436300(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *pCVar3;
  int unaff_EBX;
  int iVar4;
  int unaff_EDI;
  int iVar5;
  int *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iVar6;
  int iStack_b4;
  int iStack_b0;
  int iStack_a4;
  int iStack_a0;
  undefined *puVar7;
  int iVar8;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar3 = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047edc8;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar4 = 0x10;
  }
  else {
    iVar4 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  FUN_0046bf33(&param_1,s_Opposite_tacks__Port_tack_must_k_00497584);
  iVar8 = *(int *)pCVar3;
  uStack_4 = 0;
  pcVar1 = *(code **)(iVar8 + 100);
  (*pcVar1)();
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar8 + 0x38))();
  }
  FUN_0046bf33(&iStack_c,s_Boat_P_must_bear_off_and_pass_as_00497534);
  iVar8 = *(int *)(iStack_c + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffe4);
  FUN_0046bf33(&stack0xffffffe4,s_Exception__Rounding_a_downwind_m_0049750c);
  iVar6 = *(int *)(unaff_EBX + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffd4);
  FUN_0046bf33(&stack0xffffffd4,s_If_boat_P_tacks__she_must_keep_c_004974ac);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffc4);
  FUN_0046bf33(&stack0xffffffc4,s_on_a_closehauled_course__Rule_13_0049744c);
  iVar8 = *(int *)(iVar8 + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffb4);
  FUN_0046bf33(&stack0xffffffb4,s_acquires_right_of_way_must_initi_004973ec);
  iVar6 = *(int *)(iVar6 + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffa4);
  iVar5 = unaff_EDI + iVar4 * 4 + 0x1e;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  FUN_0046bf33(&stack0xffffffa4,s_If_a_right_of_way_boat_alters_co_0049738c);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffff94);
  iStack_a0 = 0x436554;
  FUN_0046bf33(&stack0xffffff94,s_to_promptly_keep_clear__Rule_16__0049732c);
  iStack_a0 = iVar8;
  puVar7 = *(undefined **)(iStack_a0 + -8);
  iStack_a4 = iVar5;
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffff84);
  iStack_b0 = 0x43658b;
  FUN_0046bf33(&stack0xffffff84,s_not_alter_course_so_that_P_would_004972cc);
  iStack_b0 = iVar6;
  iStack_b4 = iVar4 + iVar5;
  (*pcVar1)(0xe);
  FUN_0046bec5((int *)&stack0xffffff74);
  FUN_0044d830((int *)pCVar3,iStack_a4,iVar4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043660c;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043660c;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043660c:
  Rectangle(*(HDC *)(pCVar3 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)pCVar3);
  DAT_004ac994 = 2;
  iStack_a0 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  if (DAT_004a6774 == 0) {
    iVar8 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar7 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar6 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar3,iVar8,puVar7,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_a4,s_Boat_S__Starboard_Tack_004972b4);
    (*pcVar1)(iVar8 - iVar6,puVar7 + iVar4,iStack_a4,*(undefined4 *)(iStack_a4 + -8));
    iStack_a4 = -1;
    FUN_0046bec5(&iStack_b4);
    iVar8 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar7 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    iVar6 = DAT_004a763c / 0xe;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar3,iVar8,puVar7,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_b4,s_Boat_P__Port_Tack_004972a0);
    iStack_a4 = 10;
    (*pcVar1)(iVar8 - iVar6,puVar7 + iVar4,iStack_b4,*(undefined4 *)(iStack_b4 + -8));
    FUN_0046bec5(&iStack_a4);
  }
  else {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x78;
    DAT_004a7bd0 = 0x78;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484f10),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(pCVar3,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = iStack_a0;
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = (int)puVar7;
  return;
}


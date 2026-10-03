
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00439f20(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *pCVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  int iVar6;
  int *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iStack_a4;
  int iStack_a0;
  int iStack_94;
  int iStack_90;
  undefined *puVar7;
  int iVar8;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar3 = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f0e0;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar5 = 0x10;
  }
  else {
    iVar5 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  FUN_0046bf33(&param_1,s_No_room_at_a_starting_mark____Ru_00498750);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)pCVar3 + 100);
  iVar4 = *(int *)(param_1 + -8);
  (*pcVar1)();
  FUN_0046bec5(&iStack_c);
  FUN_0046bf33(&iStack_c,s_A_windward_boat_is_not_entitled_t_004986f8);
  iVar8 = *(int *)(iStack_c + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffe4);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  FUN_0046bf33(&stack0xffffffe4,s_Windward_Boat_W_must_promptly_ke_004986ac);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffd4);
  FUN_0046bf33(&stack0xffffffd4,s_Leeward_Boat_L_may_alter_course_p_00498658);
  iVar4 = *(int *)(iVar4 + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffc4);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  FUN_0046bf33(&stack0xffffffc4,s_After_the_starting_signal__a_lee_00498604);
  iVar8 = *(int *)(iVar8 + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffb4);
  FUN_0046bf33(&stack0xffffffb4,s_may_not_sail_above_her_proper_co_004985d0);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffa4);
  iVar6 = unaff_EDI + iVar5 * 2 + 0x11;
  if (DAT_004ac92c == 0) {
    iStack_90 = 0x43a148;
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  iStack_90 = 0x43a156;
  FUN_0046bf33(&stack0xffffffa4,s_At_the_other_end_of_the_line__an_0049857c);
  iStack_90 = iVar4;
  puVar7 = *(undefined **)(iStack_90 + -8);
  iStack_94 = iVar6;
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffff94);
  iStack_a0 = 0x43a18d;
  FUN_0046bf33(&stack0xffffff94,s_of_way_as_a_leeward_boat__A_leew_00498528);
  iStack_a0 = iVar8;
  iStack_a4 = iVar5 + iVar6;
  (*pcVar1)(5);
  FUN_0046bec5((int *)&stack0xffffff84);
  FUN_0044d830((int *)pCVar3,iStack_94,iVar5);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043a20e;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043a20e;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043a20e:
  Rectangle(*(HDC *)(pCVar3 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_004ac994 = 2;
  iStack_90 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)pCVar3);
  FUN_0042cd40((int *)pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
               (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
  FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),0,1,DAT_004a72d0,0);
  if (DAT_004a6774 == 0) {
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    puVar7 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar8 = DAT_004a763c / 0xe;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar3,iVar4,puVar7,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_94,s_Boat_L_0049832c);
    (*pcVar1)(iVar4 - iVar8,puVar7 + iVar5 + 1,iStack_94,*(undefined4 *)(iStack_94 + -8));
    iStack_94 = -1;
    FUN_0046bec5(&iStack_a4);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00485310);
    puVar7 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485088);
    iVar4 = DAT_004a763c + (DAT_004a763c >> 0x1f & 0xfU);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 10;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x122;
    DAT_004a7bd0 = 0x41;
    FUN_00411000(pCVar3,iVar5,puVar7,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_a4,s_Boat_W_0049809c);
    iStack_94 = 9;
    (*pcVar1)((iVar4 >> 4) + iVar5,puVar7,iStack_a4,*(undefined4 *)(iStack_a4 + -8));
    FUN_0046bec5(&iStack_94);
  }
  else {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00485350),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 1;
    _DAT_004a77f0 = 10;
    DAT_004a7068 = 0x14;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x14;
    DAT_004a7bd0 = 0x14;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484db8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485318),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(pCVar3,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = iStack_90;
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  *unaff_FS_OFFSET = (int)puVar7;
  return;
}


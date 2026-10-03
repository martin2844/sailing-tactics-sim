
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00438330(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  undefined4 uVar4;
  CDC *pCVar5;
  undefined *puVar6;
  int y1;
  int x1;
  int iVar7;
  int unaff_ESI;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  int *unaff_FS_OFFSET;
  int iVar11;
  HDC hdc;
  HGDIOBJ h;
  undefined *puStack_a8;
  undefined *puStack_9c;
  int iStack_98;
  undefined *puStack_8c;
  int iStack_88;
  undefined *puStack_7c;
  int iStack_78;
  undefined *puStack_6c;
  undefined4 uStack_68;
  int iStack_5c;
  int iStack_58;
  int iStack_4c;
  int iStack_48;
  int iStack_3c;
  CDC *pCStack_38;
  int local_1c [4];
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar5 = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047efa8;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    iVar7 = 0x10;
    local_1c[0] = 0x16;
    local_1c[1] = 5;
  }
  else {
    local_1c[0] = 0x1b;
    local_1c[1] = 0x14;
    iVar7 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_38 = (CDC *)0x4383b6;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_38 = (CDC *)0x4383c4;
  FUN_0046bf33(&param_1,s_Rounding_a_racing_mark_when_the_b_0049804c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)pCVar5 + 100);
  pCStack_38 = param_1;
  iStack_3c = 2;
  (*pcVar1)();
  local_1c[2] = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    iStack_48 = 0x43840f;
    (**(code **)(*(int *)pCVar5 + 0x38))();
  }
  iStack_48 = 0x43841d;
  FUN_0046bf33(&iStack_c,s_An_outside_boat_must_give_an_ove_00497ff4);
  local_1c[2] = 1;
  iStack_48 = iStack_c;
  iStack_4c = unaff_ESI + 2;
  (*pcVar1)();
  FUN_0046bec5(local_1c);
  iVar8 = unaff_ESI + 2 + iVar7;
  iStack_58 = 0x438456;
  FUN_0046bf33(local_1c,s_Otherwise__starboard_tack_has_ri_00497fbc);
  iStack_58 = local_1c[0];
  iStack_5c = iVar8;
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffd4);
  if (DAT_004ac92c == 0) {
    uStack_68 = 0x438494;
    (**(code **)(*(int *)pCVar5 + 0x38))();
  }
  puVar9 = (undefined *)(iVar8 + iStack_4c);
  uStack_68 = 0x4384a8;
  FUN_0046bf33(&stack0xffffffd4,s_Rules_governing_I_and_S_are_the_s_00497f5c);
  puStack_6c = puVar9;
  (*pcVar1)();
  FUN_0046bec5(&iStack_3c);
  puVar9 = puVar9 + iVar7;
  iStack_78 = 0x4384e1;
  FUN_0046bf33(&iStack_3c,s_P__closehauled_on_port_tack__mus_00497f20);
  iStack_78 = iStack_3c;
  puStack_7c = puVar9;
  (*pcVar1)();
  FUN_0046bec5(&iStack_4c);
  if (DAT_004ac92c == 0) {
    iStack_88 = 0x43851f;
    (**(code **)(*(int *)pCVar5 + 0x38))();
  }
  puVar9 = puVar9 + (int)puStack_6c;
  iStack_88 = 0x438533;
  FUN_0046bf33(&iStack_4c,s_If_boat_P_tacks_under_I_within_t_00497ec4);
  iStack_88 = iStack_4c;
  puStack_8c = puVar9;
  (*pcVar1)();
  FUN_0046bec5(&iStack_5c);
  iStack_98 = 0x43856c;
  FUN_0046bf33(&iStack_5c,s_I_or_S_have_to_head_up_to_avoid_c_00497e68);
  iStack_98 = iStack_5c;
  puStack_9c = puVar9 + iVar7;
  (*pcVar1)();
  FUN_0046bec5((int *)&puStack_6c);
  puStack_a8 = (undefined *)0x4385a3;
  FUN_0046bf33(&puStack_6c,s_can_t_pass_and_clear_the_mark_be_00497e20);
  puStack_a8 = puStack_6c;
  (*pcVar1)();
  FUN_0046bec5((int *)&puStack_7c);
  FUN_0044d830((int *)pCVar5,iStack_98,iVar7);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00438623;
    hdc = *(HDC *)(pCVar5 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00438623;
    hdc = *(HDC *)(pCVar5 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00438623:
  Rectangle(*(HDC *)(pCVar5 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  uVar4 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)pCVar5);
  if (DAT_004a6774 == 0) {
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00485310);
    DAT_004aa734 = 1;
    puStack_7c = (undefined *)(DAT_004a763c / 0x14);
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar5,iVar7,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485318),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&iStack_98,s_Boat_S__00497e18);
    puVar6 = puStack_7c + iVar7;
    iVar11 = iStack_98;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_a8);
    puStack_a8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar5,(int)(longlong)(_DAT_004aa810 * _DAT_00484db8),puStack_a8,2,1,DAT_004a72d0,0
                );
    FUN_0046bf33(&puStack_8c,s_Boat_I__Inside_Overlap_00497ab0);
    puVar9 = puStack_a8 + 0x18;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_9c);
    iVar8 = (int)(longlong)(_DAT_004aa810 * _DAT_00485320);
    puStack_9c = (undefined *)(DAT_004a763c / 0xf);
    _DAT_004a6ed4 = 0xf;
    _DAT_004a6344 = 0xf;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004ac024 = 0x2d;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar5,iVar8,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485328),3,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff48,s_Boat_P__Port_Tack_004972a0);
    iVar7 = *(int *)(iVar11 + -8);
    iVar8 = iVar8 - (int)puStack_9c;
    (*pcVar1)(iVar8);
    FUN_0046bec5((int *)&stack0xffffff38);
    iVar10 = ((((DAT_004aa1b4 - DAT_004aa1a0) * 3) / 2) * 5) / 2;
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    (**(code **)(*(int *)pCVar5 + 0x2c))(7);
    y1 = iVar2 - iVar10 / 2;
    x1 = 0x14 - iVar10;
    Arc(*(HDC *)(pCVar5 + 4),x1,y1,iVar10 + 0x14,iVar10 / 2 + iVar2,x1,y1,x1,y1);
    FUN_0042cd40((int *)pCVar5,0x14,iVar2,3,1);
    FUN_0046bf33(&stack0xffffff34,s_Mark__Leave_to_Port_00497a94);
    (*pcVar1)(0x14 - iVar10 / 0xe,(iVar2 - iVar10 / 0xd) - iVar7,puVar9,*(undefined4 *)(puVar9 + -8)
             );
    FUN_0046bec5((int *)&stack0xffffff24);
    FUN_0046bf33(&stack0xffffff40,s_2_Length_Zone_00497a84);
    (*pcVar1)(iVar11 + 0x14,iVar8,puVar6,*(undefined4 *)(puVar6 + -8));
    FUN_0046bec5((int *)&puStack_7c);
  }
  else {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x140;
    DAT_004a7bcc = 0x28;
    FUN_00411000(pCVar5,(int)(longlong)(_DAT_004aa810 * _DAT_00485338),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485330),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar5,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300),2,1,DAT_004a72d0,0);
    FUN_0042cd40((int *)pCVar5,(int)(longlong)(_DAT_004aa810 * _DAT_00484f18),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0),3,1);
    _DAT_004ac024 = 0x5a;
    _DAT_004a7bd4 = 0x5a;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 0x14;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    FUN_00411000(pCVar5,(int)(longlong)(_DAT_004aa810 * _DAT_00485340),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),3,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(pCVar5,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = uVar4;
  *unaff_FS_OFFSET = (int)puStack_8c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00439600(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *pCVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int iVar6;
  int *unaff_FS_OFFSET;
  int iVar7;
  HDC hdc;
  int iVar8;
  HGDIOBJ h;
  undefined *puStack_90;
  undefined4 uStack_84;
  int iStack_80;
  int iVar9;
  undefined *puVar10;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar3 = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f078;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar6 = 0x10;
  }
  else {
    iVar6 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  FUN_0046bf33(&param_1,s_Same_tack__starting__A_windward_b_004984e8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)pCVar3 + 100);
  iVar7 = *(int *)(param_1 + -8);
  (*pcVar1)();
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  FUN_0046bf33(&iStack_c,s_L_and_L2_may_turn_toward_the_win_00498488);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffe4);
  FUN_0046bf33(&stack0xffffffe4,s_give_the_windward_boats_room_and_0049842c);
  iVar5 = *(int *)(unaff_EBX + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffd4);
  FUN_0046bf33(&stack0xffffffd4,s_keep_clear__00498420);
  puVar10 = *(undefined **)(iVar7 + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffc4);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  FUN_0046bf33(&stack0xffffffc4,s_Before_the_starting_signal_there_004983c4);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffb4);
  iStack_80 = 0x4397ea;
  FUN_0046bf33(&stack0xffffffb4,s_to_wind__After_the_starting_sign_00498368);
  iStack_80 = iVar5;
  iVar7 = *(int *)(iStack_80 + -8);
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffa4);
  puStack_90 = (undefined *)0x439821;
  FUN_0046bf33(&stack0xffffffa4,s_established_the_overlap_from_ast_00498334);
  puStack_90 = puVar10;
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffff94);
  FUN_0044d830((int *)pCVar3,iStack_80,iVar6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_004398a2;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_004398a2;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_004398a2:
  Rectangle(*(HDC *)(pCVar3 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_004ac994 = 2;
  uStack_84 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)pCVar3);
  FUN_0042cd40((int *)pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
               (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
  FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484d70),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),0,1,DAT_004a72d0,0);
  if (DAT_004a6774 == 0) {
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    iVar5 = DAT_004a763c / 0x14;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 9;
    _DAT_004a77ec = 0x28;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x10e;
    DAT_004a7bcc = 0x5a;
    FUN_00411000(pCVar3,iVar6,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&iStack_80,s_Boat_W_0049809c);
    iVar5 = iVar5 + iVar6;
    iVar8 = iStack_80;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_90);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    puStack_90 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    iVar4 = DAT_004a763c + (DAT_004a763c >> 0x1f & 0xfU);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 9;
    _DAT_004a77f0 = 0x28;
    DAT_004a7068 = 0x14;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(pCVar3,iVar6,puStack_90,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff84,s_Boat_L_0049832c);
    uStack_84 = 8;
    iVar9 = iVar7;
    (*pcVar1)(iVar6 - (iVar4 >> 4),puStack_90 + 9);
    FUN_0046bec5((int *)&stack0xffffff74);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar4 = DAT_004a763c / 7;
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x32;
    _DAT_004a706c = 0x14;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x10e;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar3,iVar6,puVar10,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff60,s_Boat_W2_00498324);
    (*pcVar1)(iVar6 - iVar4,puVar10 + (-4 - iVar5),iVar8,*(undefined4 *)(iVar8 + -8));
    FUN_0046bec5((int *)&stack0xffffff50);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    _DAT_004aa748 = 1;
    iVar5 = DAT_004a763c / 0x19;
    _DAT_004a6ee0 = 0xf;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x10e;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(pCVar3,iVar6,puVar10,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff50,s_Boat_L2_0049831c);
    (*pcVar1)(iVar5 + iVar6,puVar10 + DAT_004a72d0 / 0x46,iVar7,*(undefined4 *)(iVar7 + -8));
    FUN_0046bec5(&iStack_80);
    iVar7 = iVar9;
  }
  else {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x32;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x145;
    DAT_004a7bcc = 0x23;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_004852e8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x32;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,DAT_004a72d0,0);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x14;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x145;
    _DAT_004a7bd4 = 0x23;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484ec8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),3,1,DAT_004a72d0,0);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xf;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00485348),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),6,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(pCVar3,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = uStack_84;
  *unaff_FS_OFFSET = iVar7;
  return;
}


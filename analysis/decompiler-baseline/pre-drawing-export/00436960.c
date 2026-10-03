
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00436960(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  undefined4 uVar3;
  CDC *this;
  undefined *puVar4;
  int iVar5;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  HDC hdc;
  HGDIOBJ h;
  undefined *puStack_b0;
  undefined *puStack_ac;
  int iStack_a8;
  int iStack_a0;
  undefined *puStack_9c;
  int iStack_98;
  undefined *puStack_8c;
  undefined *puStack_7c;
  int iStack_78;
  int aiStack_6c [2];
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
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047ee48;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    local_1c[0] = 0x16;
    local_1c[1] = 5;
  }
  else {
    local_1c[0] = 0x1b;
    local_1c[1] = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_38 = (CDC *)0x4369e3;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_38 = (CDC *)0x4369f1;
  FUN_0046bf33(&param_1,s_Same_tack__overlapped__Windward_b_00497878);
  iVar5 = *(int *)this;
  uStack_4 = 0;
  pcVar1 = *(code **)(iVar5 + 100);
  pCStack_38 = param_1;
  iStack_3c = 2;
  (*pcVar1)();
  local_1c[2] = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    iStack_48 = 0x436a32;
    (**(code **)(iVar5 + 0x38))();
  }
  iStack_48 = 0x436a47;
  FUN_0046bf33(&iStack_c,s_L_and_W_overlap_because_W_s_bow_i_00497824);
  local_1c[2] = 1;
  iStack_48 = iStack_c;
  iStack_4c = unaff_ESI + 2;
  (*pcVar1)();
  FUN_0046bec5(local_1c);
  iStack_58 = 0x436a80;
  FUN_0046bf33(local_1c,s_L_may_alter_course_toward_the_wi_004977c8);
  iStack_58 = local_1c[0];
  iStack_5c = unaff_ESI + 0x16;
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffd4);
  iVar5 = unaff_ESI + 0x16 + iStack_4c;
  if (DAT_004ac92c == 0) {
    aiStack_6c[1] = 0x436ac0;
    (**(code **)(*(int *)this + 0x38))();
  }
  aiStack_6c[1] = 0x436ace;
  FUN_0046bf33(&stack0xffffffd4,s_W2_and_L2_overlap__W2_must_keep_c_0049776c);
  aiStack_6c[0] = iVar5;
  (*pcVar1)();
  FUN_0046bec5(&iStack_3c);
  puStack_8c = (undefined *)(iVar5 + 0xe);
  iStack_78 = 0x436b07;
  FUN_0046bf33(&iStack_3c,s_closer_to_the_wind_than_her_prop_00497710);
  iStack_78 = iStack_3c;
  puStack_7c = puStack_8c;
  (*pcVar1)();
  FUN_0046bec5(&iStack_4c);
  puStack_8c = puStack_8c + aiStack_6c[0];
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  FUN_0046bf33(&iStack_4c,s__Proper_course__is_the_course_a_b_004976b0);
  (*pcVar1)();
  FUN_0046bec5(&iStack_5c);
  iStack_98 = 0x436b8e;
  FUN_0046bf33(&iStack_5c,s_of_other_boats_referred_to_in_th_0049765c);
  iStack_98 = iStack_5c;
  iStack_a0 = 0xe;
  puStack_9c = puStack_8c + 0xe;
  (*pcVar1)();
  FUN_0046bec5(aiStack_6c);
  iStack_a8 = 0x436bc1;
  FUN_0046bf33(aiStack_6c,s_referred_to_in_the_applicable_ru_00497618);
  puStack_ac = puStack_8c + 0x1c;
  iStack_a8 = aiStack_6c[0];
  puStack_b0 = (undefined *)0xe;
  (*pcVar1)();
  FUN_0046bec5((int *)&puStack_7c);
  FUN_0044d830((int *)this,iStack_98,iStack_a0);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00436c44;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00436c44;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00436c44:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  uVar3 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)this);
  if (DAT_004a6774 == 0) {
    puStack_7c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    puStack_9c = (undefined *)(DAT_004a763c / 0xe);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852e0),puStack_7c,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_98,s_Boat_W__Windward_00497604);
    (*pcVar1)();
    FUN_0046bec5(&iStack_a8);
    puStack_8c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 0x14;
    puStack_ac = (undefined *)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852e8),puStack_8c,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_a8,s_Boat_L__Leeward_004975f4);
    puVar4 = puStack_8c + (int)puStack_b0;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff48);
    iVar9 = 7;
    (**(code **)(*(int *)this + 0x2c))();
    FUN_004706bd(this,(int *)&stack0xffffff44,DAT_004aa1a0,DAT_004aa2a0 - DAT_004a72d0 / 3);
    CDC::LineTo(this,DAT_004aa1a0,DAT_004aa2a0);
    FUN_0046bf33(&iStack_a0,s_Overlap_Line_004975e4);
    iStack_a8 = 10;
    iVar6 = DAT_004aa1a0;
    iVar8 = iStack_a0;
    (*pcVar1)(DAT_004aa1a0,DAT_004aa2a0 - DAT_004a72d0 / 3);
    FUN_0046bec5((int *)&puStack_b0);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    puStack_b0 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar7 = DAT_004a763c / 0xe;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    FUN_00411000(this,iVar5,puStack_b0,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff34,s_Boat_W2__Windward_004975d0);
    (*pcVar1)(iVar7 + iVar5,puStack_b0 + iVar9,puVar4,*(undefined4 *)(puVar4 + -8));
    FUN_0046bec5((int *)&stack0xffffff24);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar4 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0);
    iVar7 = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,iVar5,puVar4,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff24,s_Boat_L2__Leeward_004975bc);
    (*pcVar1)(iVar5 - iVar7,puVar4 + iVar6,iVar8,*(undefined4 *)(iVar8 + -8));
    FUN_0046bec5(&iStack_98);
  }
  if (DAT_004a6774 == 1) {
    _DAT_004a77ec = 2;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x23;
    DAT_004a7bcc = 0x23;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852f8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 5;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x2d;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485070),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),2,1,DAT_004a72d0,0);
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484e50),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),2,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = uVar3;
  *unaff_FS_OFFSET = (int)puStack_8c;
  return;
}


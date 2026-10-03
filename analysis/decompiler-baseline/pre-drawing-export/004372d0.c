
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004372d0(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  CDC *this;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iStack_88;
  int iStack_84;
  int iStack_78;
  int iStack_74;
  undefined4 uVar7;
  undefined *puStack_6c;
  undefined *puStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int aiStack_3c [2];
  CDC *pCStack_34;
  int local_1c [4];
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047eea8;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar4;
  if (DAT_004a763c < 700) {
    iVar6 = 0x10;
    local_1c[0] = 0x16;
    local_1c[1] = 5;
  }
  else {
    iVar6 = 0x14;
    local_1c[0] = 0x1b;
    local_1c[1] = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_34 = (CDC *)0x43734c;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_34 = (CDC *)0x43735a;
  FUN_0046bf33(&param_1,s_Same_tack__not_overlapped__Boat_c_00497a3c);
  iVar5 = *(int *)this;
  uStack_4 = 0;
  pcVar1 = *(code **)(iVar5 + 100);
  pCStack_34 = param_1;
  aiStack_3c[1] = 2;
  aiStack_3c[0] = 0x14;
  (*pcVar1)();
  local_1c[2] = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    iStack_44 = 0x43739c;
    (**(code **)(iVar5 + 0x38))();
  }
  iStack_44 = 0x4373b1;
  FUN_0046bf33(&iStack_c,s_No_overlap_because_A_s_bow_is_be_004979e0);
  local_1c[2] = 1;
  iStack_44 = iStack_c;
  iStack_4c = 0xe;
  iStack_48 = unaff_EDI + 2;
  (*pcVar1)();
  FUN_0046bec5(local_1c);
  iVar5 = unaff_EDI + 2 + iVar6;
  iStack_54 = 0x4373ea;
  FUN_0046bf33(local_1c,s_Boat_A_is_clear_astern_and_must_k_004979b4);
  iStack_54 = local_1c[0];
  puStack_5c = (undefined *)0xe;
  iStack_58 = iVar5;
  (*pcVar1)();
  pCStack_34 = (CDC *)0xffffffff;
  FUN_0046bec5((int *)&stack0xffffffd4);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  iVar5 = iVar5 + iStack_4c;
  FUN_0046bf33(&stack0xffffffd4,s_If_the_boats_are_not_beating__00497994);
  pCStack_34 = (CDC *)0x3;
  puStack_6c = (undefined *)0xe;
  (*pcVar1)();
  iStack_44 = 0xffffffff;
  FUN_0046bec5(aiStack_3c);
  iVar5 = iVar5 + iVar6;
  iStack_74 = 0x437475;
  FUN_0046bf33(aiStack_3c,s_When_A_is_clear_astern_or_overla_00497938);
  iStack_44 = 4;
  iStack_74 = aiStack_3c[0];
  iStack_78 = iVar5;
  (*pcVar1)();
  iStack_54 = 0xffffffff;
  FUN_0046bec5(&iStack_4c);
  iStack_84 = 0x4374ac;
  FUN_0046bf33(&iStack_4c,s_below_her_proper_course_if_A_is_s_004978e4);
  iStack_88 = iVar6 + iVar5;
  iStack_54 = 5;
  iVar5 = *(int *)(iStack_4c + -8);
  iStack_84 = iStack_4c;
  (*pcVar1)();
  FUN_0046bec5((int *)&puStack_5c);
  FUN_0044d830((int *)this,iStack_78,iVar6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043752d;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043752d;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043752d:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  uVar7 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int *)this);
  if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
    DAT_004abb74 = 1;
  }
  if (DAT_004a6774 == 0) {
    puStack_5c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x5a;
    DAT_004a7bcc = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485058),puStack_5c,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_78,s_Boat_A__Clear_Astern_004978cc);
    (*pcVar1)();
    iStack_74 = 0xffffffff;
    FUN_0046bec5(&iStack_88);
    iVar2 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puStack_6c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 0x14;
    iVar3 = DAT_004a763c / 0xe;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,iVar2,puStack_6c,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_88,s_Boat_B__Clear_Ahead_004978b8);
    iStack_74 = 7;
    (*pcVar1)(iVar3 + iVar2,puStack_6c + iVar6,iStack_88,*(undefined4 *)(iStack_88 + -8));
    iStack_84 = -1;
    FUN_0046bec5((int *)&stack0xffffff68);
    (**(code **)(*(int *)this + 0x2c))(7);
    FUN_004706bd(this,(int *)&stack0xffffff64,DAT_004aa1a0,
                 DAT_004aa2a0 - ((int)(DAT_004a72d0 + (DAT_004a72d0 >> 0x1f & 3U)) >> 2));
    CDC::LineTo(this,DAT_004aa1a0,DAT_004a72d0 / 10 + DAT_004aa2a0);
    FUN_0046bf33(&stack0xffffff80,s_Overlap_Line_004975e4);
    iStack_88 = 8;
    (*pcVar1)(DAT_004aa1a0,DAT_004a72d0 / 10 + DAT_004aa2a0,iVar5,*(undefined4 *)(iVar5 + -8));
    FUN_0046bec5((int *)&puStack_5c);
  }
  else {
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,DAT_004a72d0,0);
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x6e;
    DAT_004a7bcc = 0x6e;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485088),1,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = uVar7;
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  *unaff_FS_OFFSET = (int)puStack_6c;
  return;
}


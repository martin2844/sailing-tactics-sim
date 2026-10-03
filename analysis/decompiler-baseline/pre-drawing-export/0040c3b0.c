
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040c3b0(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  HGDIOBJ unaff_EBX;
  code *pcVar9;
  code *pcVar10;
  int iVar11;
  code *pcVar12;
  code *unaff_EDI;
  HDC pHVar13;
  code *pcVar14;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar15;
  HGDIOBJ h;
  code *pcVar16;
  code *pcStack_9c;
  void **ppvStack_98;
  code *pcVar17;
  code *pcVar18;
  HDC hdc;
  undefined8 uVar19;
  code *pcVar20;
  int iVar21;
  int iStack_60;
  int iStack_5c;
  int local_58;
  undefined1 auStack_54 [4];
  void *local_50;
  code *local_4c [2];
  int local_44;
  undefined1 auStack_40 [4];
  HDC local_3c;
  code *local_38;
  undefined1 uStack_2c;
  HGDIOBJ local_20;
  undefined1 uStack_1c;
  HRGN local_18;
  undefined4 uStack_14;
  code *pcStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  pcStack_10 = FUN_0047dc18;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_3c = *(HDC *)(param_1 + 4);
  local_18 = CreateRectRgn(param_2,param_3,param_4,param_5);
  local_20 = SelectObject(local_3c,local_18);
  FUN_0046bd7a(local_4c);
  local_c = 0;
  FUN_0046c00d(&DAT_004a7048,&DAT_004aca50);
  DAT_004ac9dc = 0;
  DAT_004a70ec = (param_4 + param_2) / 2;
  DAT_004aa824 = (param_3 + param_5 * 4) / 5;
  local_58 = DAT_004a72d0 / 0x1e;
  if ((DAT_004ac9c8 == 1) && (*(int *)(&DAT_004a4e88 + param_6 * 4) < 3)) {
    iVar21 = param_4 + param_2 * 3;
    local_44 = (int)(iVar21 + (iVar21 >> 0x1f & 3U)) >> 2;
    pcVar9 = (code *)(local_44 + 10);
  }
  else {
    local_44 = (param_4 + param_2 * 4) / 5;
    pcVar9 = (code *)(local_44 + 5);
  }
  local_50 = *(void **)param_1;
  local_38 = *(code **)((int)local_50 + 0x2c);
  (*local_38)();
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  (*(code *)local_3c)();
  Rectangle(*(HDC *)(param_1 + 4),param_2,param_3,param_4,param_5);
  FUN_00409760(param_1,param_2,param_3,param_4,param_5,param_6,iStack_60);
  FUN_0040db30(param_1,param_2,param_3,param_4,local_4c[0],param_6);
  pHVar13 = (HDC)(param_3 + 1);
  local_4c[0] = *(code **)(local_58 + 0x34);
  iVar21 = 0xffffff;
  (*local_4c[0])();
  if (DAT_004ac92c == 0) {
    pcVar20 = (code *)0xff;
    pcVar1 = *(code **)(iStack_5c + 0x38);
  }
  else {
    pcVar20 = (code *)0x0;
    pcVar1 = *(code **)(iStack_5c + 0x38);
  }
  (*pcVar1)();
  if (DAT_004a5b80 < 1) {
    local_50 = FUN_00413d00(auStack_40,
                            (DAT_004a6778 ^ (int)DAT_004a6778 >> 0x1f) - ((int)DAT_004a6778 >> 0x1f)
                           );
    uStack_1c = 1;
    FUN_00413d00(&local_44,(DAT_004a5e84 ^ (int)DAT_004a5e84 >> 0x1f) - ((int)DAT_004a5e84 >> 0x1f))
    ;
    uStack_1c = 2;
    FUN_0046c0db();
    uStack_1c = 3;
    FUN_0046c075();
    uStack_1c = 4;
    FUN_0046c0db();
    uStack_1c = 5;
    (**(code **)(iStack_60 + 100))();
    uStack_1c = 4;
    FUN_0046bec5(&local_58);
    uStack_1c = 3;
    FUN_0046bec5((int *)&stack0xffffff9c);
    uStack_1c = 2;
    FUN_0046bec5((int *)&stack0xffffff90);
    uStack_1c = 1;
    FUN_0046bec5(&local_44);
    uStack_1c = 0;
    FUN_0046bec5((int *)auStack_40);
    pHVar13 = (HDC)((int)&pHVar13->unused + (int)pcVar1 * 2);
    if (0 < DAT_004a5b80) goto LAB_0040c690;
  }
  else {
LAB_0040c690:
    DAT_004aa7e0 = FUN_0042d0c0(param_6);
    ppvStack_98 = (void **)0x40c6cc;
    fVar15 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + DAT_004aa7e0 * 8),
                                           *(undefined4 *)(&DAT_004a52f0 + DAT_004aa7e0 * 8)),
                          (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + DAT_004aa7e0 * 8),
                                           *(undefined4 *)(&DAT_004a60b0 + DAT_004aa7e0 * 8)),0,
                          param_6);
    _DAT_004aa6e4 = (undefined4)(longlong)(_DAT_004a6828 * _DAT_00484d70);
    DAT_004ac66c = FUN_00415dc0((int)(longlong)(fVar15 * (float10)_DAT_00484d78) -
                                *(int *)(&DAT_004ac018 + param_6 * 4));
    local_58 = (int)(longlong)_DAT_004a6828;
    if ((DAT_004ac92c == 0) && ((*unaff_EDI)(), DAT_004aa7e0 == 2)) {
      (*unaff_EDI)();
    }
    FUN_0046bf33(&stack0xffffff9c,s_mark__00491ea8);
    uStack_1c = 6;
    pcVar16 = *(code **)(iStack_60 + 100);
    (*pcVar16)();
    uStack_1c = 0;
    FUN_0046bec5((int *)&stack0xffffff9c);
    pHVar13 = (HDC)((int)&pHVar13->unused + (int)pcVar1 * 2);
    DAT_004a6770 = DAT_004ac66c;
    if (0 < (int)DAT_004ac66c) {
      FUN_00413d00(&local_44,DAT_004ac66c);
      uStack_1c = 7;
      FUN_0046c0db();
      uStack_1c = 8;
      (*pcVar16)();
      uStack_1c = 7;
      FUN_0046bec5((int *)auStack_40);
      uStack_1c = 0;
      FUN_0046bec5(&local_44);
    }
    if ((int)DAT_004ac66c < 0) {
      FUN_00413d00(&local_44,
                   (DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f));
      uStack_1c = 9;
      FUN_0046c0db();
      uStack_1c = 10;
      (*pcVar16)();
      uStack_1c = 9;
      FUN_0046bec5((int *)auStack_40);
      uStack_1c = 0;
      FUN_0046bec5(&local_44);
    }
    if (DAT_004ac66c == 0) {
      FUN_0046bf33(&stack0xffffff9c,s_ahead_00491c18);
      uStack_1c = 0xb;
      (*pcVar16)();
      uStack_1c = 0;
      FUN_0046bec5((int *)&stack0xffffff9c);
    }
  }
  if (DAT_004ac92c == 0) {
    (*unaff_EDI)();
  }
  piVar2 = FUN_00413d90(auStack_40);
  uStack_1c = 0xc;
  FUN_0046bfbe(&iStack_5c,piVar2);
  uStack_1c = 0;
  FUN_0046bec5((int *)auStack_40);
  piVar2 = (int *)FUN_0046c14f();
  uStack_1c = 0xd;
  pcVar16 = *(code **)(iStack_60 + 100);
  pcVar12 = *(code **)(*piVar2 + -8);
  pcVar10 = pcVar9;
  hdc = pHVar13;
  (*pcVar16)();
  uStack_2c = 0;
  FUN_0046bec5((int *)&local_50);
  iVar8 = (int)&pHVar13->unused + iVar21;
  if (DAT_004ac92c == 0) {
    (*pcVar20)();
  }
  if (*(int *)(&DAT_004a7868 + param_6 * 4) == 0) {
    FUN_0046bf33(&stack0xffffff90,s_clear_air_00491e74);
    uStack_2c = 0xe;
    pcStack_9c = pcVar9;
    ppvStack_98 = (void **)iVar8;
    (*pcVar12)();
    uStack_2c = 0;
    FUN_0046bec5((int *)&stack0xffffff90);
  }
  else if (DAT_004ac92c == 0) {
    (*pcVar20)();
  }
  if ((*(int *)(&DAT_004a7868 + param_6 * 4) == 2) || (*(int *)(&DAT_004a7868 + param_6 * 4) == 0xc)
     ) {
    FUN_0046bf33(&stack0xffffff90,s_blanketed_00491e68);
    uStack_2c = 0xf;
    pcStack_9c = pcVar9;
    ppvStack_98 = (void **)iVar8;
    (*pcVar12)();
    uStack_2c = 0;
    FUN_0046bec5((int *)&stack0xffffff90);
  }
  if (*(int *)(&DAT_004a7868 + param_6 * 4) == 3) {
    FUN_0046bf33(&stack0xffffff90,s_backwinded_00491e5c);
    uStack_2c = 0x10;
    pcStack_9c = pcVar9;
    ppvStack_98 = (void **)iVar8;
    (*pcVar12)();
    uStack_2c = 0;
    FUN_0046bec5((int *)&stack0xffffff90);
  }
  pcVar14 = (code *)(iVar8 + iVar21);
  if (DAT_004ac92c == 0) {
    (*pcVar20)();
  }
  ppvStack_98 = (void **)0x40ca54;
  piVar2 = FUN_00413d00(&local_50,*(uint *)(&DAT_004a8aa8 + param_6 * 4));
  uStack_2c = 0x11;
  FUN_0046bfbe(&stack0xffffff94,piVar2);
  uStack_2c = 0;
  FUN_0046bec5((int *)&local_50);
  ppvStack_98 = (void **)auStack_54;
  pcStack_9c = (code *)0x40ca88;
  FUN_0046c14f();
  ppvStack_98 = &local_50;
  uStack_2c = 0x12;
  pcStack_9c = (code *)0x40ca9d;
  piVar2 = (int *)FUN_0046c0db();
  pcVar17 = (code *)*piVar2;
  uStack_2c = 0x13;
  pcVar18 = *(code **)(pcVar17 + -8);
  pcStack_9c = pcVar9;
  ppvStack_98 = (void **)pcVar14;
  (*pcVar12)();
  local_3c._0_1_ = 0x12;
  FUN_0046bec5(&iStack_60);
  local_3c = (HDC)((uint)local_3c._1_3_ << 8);
  FUN_0046bec5((int *)&stack0xffffff9c);
  pcVar14 = pcVar14 + (int)hdc;
  if (*(double *)(&DAT_004a7f28 + param_6 * 8) <= _DAT_00484d80) {
    if (DAT_004ac92c == 0) {
      (*pcVar10)();
    }
    FUN_00413d00(&stack0xffffff9c,(uint)(longlong)*(double *)(&DAT_004a7f28 + param_6 * 8));
    local_3c._0_1_ = 0x17;
    puVar4 = (undefined4 *)FUN_0046c14f();
    local_3c._0_1_ = 0x18;
    (*pcVar18)(pcVar9,pcVar14,*puVar4);
    local_3c._0_1_ = 0x17;
    FUN_0046bec5(&iStack_60);
    local_3c = (HDC)((uint)local_3c._1_3_ << 8);
    FUN_0046bec5((int *)&stack0xffffff9c);
    if (((*(double *)(&DAT_004a7f28 + param_6 * 8) < _DAT_00484d80) &&
        (_DAT_00484d80 < *(double *)(&DAT_004a4510 + param_6 * 8))) && (DAT_004ac9c0 == 0)) {
      MessageBeep(0);
    }
  }
  else {
    if (DAT_004ac92c == 0) {
      (*pcVar10)();
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 1) {
      FUN_0046bf33(&stack0xffffff80,s_sail__flat_00491e40);
      local_3c._0_1_ = 0x14;
      (*pcVar18)(pcVar9,pcVar14,pcVar12);
      local_3c = (HDC)((uint)local_3c._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff80);
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 2) {
      FUN_0046bf33(&stack0xffffff80,s_sail__medium_00491e30);
      local_3c._0_1_ = 0x15;
      (*pcVar18)(pcVar9,pcVar14,pcVar12);
      local_3c = (HDC)((uint)local_3c._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff80);
    }
    if (*(int *)(&DAT_004a7768 + param_6 * 4) == 3) {
      FUN_0046bf33(&stack0xffffff80,s_sail__baggy_00491e24);
      local_3c._0_1_ = 0x16;
      (*pcVar18)(pcVar9,pcVar14,pcVar12);
      local_3c = (HDC)((uint)local_3c._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff80);
    }
  }
  pcVar14 = pcVar14 + (int)hdc;
  if (DAT_004ac92c == 0) {
    (*pcVar10)();
  }
  uVar3 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + param_6 * 4) - DAT_004a4f8c);
  if (0xb4 < (int)uVar3) {
    uVar3 = uVar3 - 0x168;
  }
  uVar6 = (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
  DAT_004ac964 = (uint)(0x46 < (int)uVar6);
  if ((DAT_004ac978 == 0) && (DAT_004ac964 == 0)) {
    if (0 < (int)(uVar3 * *(int *)(&DAT_004aa730 + param_6 * 4))) {
      FUN_00413d00(&stack0xffffff9c,uVar6);
      local_3c._0_1_ = 0x19;
      puVar4 = (undefined4 *)FUN_0046c14f();
      local_3c._0_1_ = 0x1a;
      (*pcVar18)(pcVar9,pcVar14,*puVar4);
      local_3c._0_1_ = 0x19;
      FUN_0046bec5(&iStack_60);
      local_3c = (HDC)((uint)local_3c._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff9c);
    }
    if (uVar3 == 0) {
      FUN_0046bf33(&stack0xffffff90,s_wind_average_00491e04);
      local_3c._0_1_ = 0x1b;
      (*pcVar18)(pcVar9,pcVar14,pcVar16);
      local_3c = (HDC)((uint)local_3c._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff90);
    }
    if ((int)(uVar3 * *(int *)(&DAT_004aa730 + param_6 * 4)) < 0) {
      if (DAT_004ac978 == 0) {
        FUN_00413d00(&stack0xffffff9c,uVar6);
        local_3c._0_1_ = 0x1c;
        puVar4 = (undefined4 *)FUN_0046c14f();
        local_3c._0_1_ = 0x1d;
        (*pcVar18)(pcVar9,pcVar14,*puVar4);
        local_3c._0_1_ = 0x1c;
        FUN_0046bec5(&iStack_60);
        local_3c = (HDC)((uint)local_3c._1_3_ << 8);
        FUN_0046bec5((int *)&stack0xffffff9c);
      }
      if (((DAT_004a7bcc < 0x37) &&
          (0x2d < (int)((DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f))))
         && ((10 < (int)uVar6 && (((300 < iVar21 && (param_6 == 1)) && (0 < DAT_004a5b80)))))) {
        DAT_004a620c = 1;
      }
    }
    if (DAT_004ac964 == 1) {
      if (DAT_004ac92c == 0) {
        (*pcVar10)();
      }
      FUN_0046bf33(&stack0xffffff90,s_major_wind_change_00491de8);
      local_3c._0_1_ = 0x1e;
      (*pcVar18)(pcVar9,pcVar14,pcVar16);
      local_3c = (HDC)((uint)local_3c._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff90);
    }
    pcVar14 = pcVar14 + (int)hdc;
  }
  if ((DAT_004ac9c8 == 0) || (pcVar12 = pcVar9, *(int *)(&DAT_004a4e88 + param_6 * 4) == 3)) {
    pcVar12 = (code *)(param_2 + 10);
  }
  uVar19 = CONCAT44(pcVar12,uVar3);
  if (DAT_004ac964 == 1) {
    FUN_0046bf33(&stack0xffffff90,s_major_wind_change_00491de8);
    local_3c._0_1_ = 0x1f;
    (*pcVar18)(pcVar9,pcVar14,pcVar16);
    local_3c = (HDC)((uint)local_3c._1_3_ << 8);
    FUN_0046bec5((int *)&stack0xffffff90);
  }
  if ((DAT_00491188 == 7) || (DAT_00491188 == 8)) {
    if (DAT_004ac92c == 0) {
      (*pcVar10)();
    }
    FUN_00413d00(auStack_54,*(uint *)(&DAT_004aa5b0 + param_6 * 4));
    local_3c._0_1_ = 0x20;
    FUN_00413d00(&local_58,*(uint *)(&DAT_004a6338 + param_6 * 4));
    local_3c._0_1_ = 0x21;
    FUN_0046c14f();
    local_3c._0_1_ = 0x22;
    FUN_0046c0db();
    local_3c._0_1_ = 0x23;
    FUN_0046c075();
    local_3c._0_1_ = 0x24;
    puVar4 = (undefined4 *)FUN_0046c0db();
    local_3c._0_1_ = 0x25;
    iVar8 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
    (*pcVar18)((int)((ulonglong)uVar19 >> 0x20),
               ((iVar8 >> 4) - (iVar8 >> 0x1f)) + (int)hdc * -4 + DAT_004aa824,*puVar4);
    local_3c._0_1_ = 0x24;
    FUN_0046bec5(&iStack_60);
    local_3c._0_1_ = 0x23;
    FUN_0046bec5((int *)&stack0xffffff9c);
    local_3c._0_1_ = 0x22;
    FUN_0046bec5((int *)&stack0xffffff90);
    local_3c._0_1_ = 0x21;
    FUN_0046bec5(&iStack_5c);
    local_3c._0_1_ = 0x20;
    FUN_0046bec5(&local_58);
    local_3c = (HDC)((uint)local_3c._1_3_ << 8);
    FUN_0046bec5((int *)auStack_54);
  }
  pcVar9 = (code *)uVar19;
  uVar3 = (int)DAT_004ac66c >> 0x1f;
  if ((param_6 == 1) && (0 < DAT_004a5b80)) {
    if (DAT_004a7bcc < 0x37) {
      if (-1 < (int)pcVar9 * DAT_004aa734) {
        DAT_004a4bd8 = DAT_004a4bd8 + 1;
      }
      if (DAT_004a7bcc < 0x37) {
        DAT_004ab9c4 = DAT_004ab9c4 + 1;
      }
    }
    DAT_004ab9d4 = DAT_004ab9d4 + 1;
    if (0 < DAT_004a786c) {
      DAT_004a61f8 = 1;
      DAT_004a7754 = DAT_004a7754 + 1;
    }
    if (((DAT_004a7bcc < 0x37) && (0x4b < (int)((DAT_004ac66c ^ uVar3) - uVar3))) && (700 < iVar21))
    {
      DAT_004a620c = 2;
    }
    if (((DAT_004a7bcc < 0x37) && (0x5a < (int)((DAT_004ac66c ^ uVar3) - uVar3))) &&
       ((0 < DAT_004a5424 && (10 < DAT_004a5b80)))) {
      DAT_004a620c = 3;
    }
  }
  if (((param_6 == 1) && (0 < (int)pcVar9 * DAT_004aa734)) &&
     ((0 < DAT_004a5b80 && (iVar8 = 0xaa - DAT_004a5f14, iVar8 <= DAT_004a7bcc)))) {
    if ((300 < iVar21) && (DAT_004a5f14 < (int)((DAT_004ac66c ^ uVar3) - uVar3))) {
      DAT_004a620c = 0xffffffff;
    }
    if (iVar8 <= DAT_004a7bcc) {
      if ((700 < iVar21) && ((DAT_004a5f14 * 9) / 5 < (int)((DAT_004ac66c ^ uVar3) - uVar3))) {
        DAT_004a620c = 0xfffffffe;
      }
      if (((iVar8 <= DAT_004a7bcc) && (700 < iVar21)) &&
         (DAT_004a5f14 * 2 < (int)((DAT_004ac66c ^ uVar3) - uVar3))) {
        DAT_004a620c = 0xfffffffd;
      }
    }
  }
  (*pcVar10)();
  pcVar16 = pcVar9;
  if (DAT_004a763c < 700) {
    pcVar16 = (code *)(param_2 + 1);
  }
  if (DAT_004911a4 == 1) {
    if (DAT_004ac9dc == 0) {
      FUN_0046bf33(&stack0xffffff84,s_Button_explanations_show_here__00491db4);
      auStack_40[0] = 0x26;
      (*pcVar17)(pcVar16,(DAT_004aa824 - DAT_004a72d0 / 0x32) - (int)pcVar10,pcVar20,
                 *(undefined4 *)(pcVar20 + -8));
      auStack_40[0] = 0;
      FUN_0046bec5((int *)&stack0xffffff84);
    }
    else {
      FUN_0044db20((int *)param_1,(int)pcVar10,param_2);
    }
  }
  if (DAT_004ac92c == 0) {
    pcVar20 = (code *)0x7f;
  }
  else {
    pcVar20 = (code *)0x0;
  }
  (*pcVar18)();
  if (*(int *)(&DAT_004a8910 + param_6 * 4) == 1) {
    if (*(int *)(&DAT_004ac1e8 + param_6 * 4) == 0) {
      FUN_0046bf33(&stack0xffffff88,s_normal_closehauled_course_00491d98);
      iStack_5c = (int)pcVar10 * 3;
      local_44._0_1_ = 0x27;
      iVar8 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
      (*(code *)ppvStack_98)
                (hdc,((iVar8 >> 4) - (iVar8 >> 0x1f)) + (int)pcVar10 * -3 + DAT_004aa824,iVar21,
                 *(undefined4 *)(iVar21 + -8));
      local_44 = (uint)local_44._1_3_ << 8;
      FUN_0046bec5((int *)&stack0xffffff88);
    }
    if (*(int *)(&DAT_004a8910 + param_6 * 4) == 1) {
      if (*(int *)(&DAT_004ac1e8 + param_6 * 4) == 5) {
        FUN_0046bf33(&stack0xffffff88,s_closehauled___footing_00491d80);
        iStack_5c = (int)pcVar10 * 3;
        local_44._0_1_ = 0x28;
        iVar8 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
        (*(code *)ppvStack_98)
                  (hdc,((iVar8 >> 4) - (iVar8 >> 0x1f)) + (int)pcVar10 * -3 + DAT_004aa824,iVar21,
                   *(undefined4 *)(iVar21 + -8));
        local_44 = (uint)local_44._1_3_ << 8;
        FUN_0046bec5((int *)&stack0xffffff88);
      }
      if ((*(int *)(&DAT_004a8910 + param_6 * 4) == 1) &&
         (*(int *)(&DAT_004ac1e8 + param_6 * 4) == -5)) {
        FUN_0046bf33(&stack0xffffff88,s_closehauled___pinching_00491d68);
        iStack_5c = (int)pcVar10 * 3;
        local_44._0_1_ = 0x29;
        iVar8 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
        (*(code *)ppvStack_98)
                  (hdc,((iVar8 >> 4) - (iVar8 >> 0x1f)) + (int)pcVar10 * -3 + DAT_004aa824,iVar21,
                   *(undefined4 *)(iVar21 + -8));
        local_44 = (uint)local_44._1_3_ << 8;
        FUN_0046bec5((int *)&stack0xffffff88);
      }
    }
  }
  if (*(int *)(&DAT_004a4968 + param_6 * 4) == 1) {
    FUN_0046bf33(&stack0xffffff88,s_run___good_angle_00491d54);
    iStack_5c = (int)pcVar10 * 3;
    local_44._0_1_ = 0x2a;
    iVar8 = (int)((ulonglong)((longlong)DAT_004a72d0 * -0x51eb851f) >> 0x20);
    (*(code *)ppvStack_98)
              (hdc,((iVar8 >> 4) - (iVar8 >> 0x1f)) + (int)pcVar10 * -3 + DAT_004aa824,iVar21,
               *(undefined4 *)(iVar21 + -8));
    local_44 = (uint)local_44._1_3_ << 8;
    FUN_0046bec5((int *)&stack0xffffff88);
  }
  if (DAT_004ac92c == 0) {
    (*pcVar17)(0x7f0000);
  }
  if (DAT_004ac8fc == 0) {
    if ((DAT_0049116c == 1) && (DAT_004ac92c == 0)) {
      (*pcVar17)(0xff);
    }
    FUN_00413d00(&iStack_60,DAT_0049116c);
    local_44._0_1_ = 0x2b;
    piVar2 = (int *)FUN_0046c14f();
    iVar21 = *piVar2;
    local_44 = CONCAT31(local_44._1_3_,0x2c);
    pcVar12 = *(code **)(iVar21 + -8);
    pcVar16 = (code *)(param_2 + 10);
    pcVar14 = (code *)((DAT_004aa824 - DAT_004a72d0 / 0x32) + (int)pcVar10 * -2);
    (*(code *)ppvStack_98)(pcVar16,pcVar14,iVar21);
    auStack_54[0] = 0x2b;
    FUN_0046bec5((int *)&stack0xffffff94);
    piVar2 = (int *)&stack0xffffff90;
  }
  else {
    if (DAT_004ac92c == 0) {
      (*pcVar17)(0xff);
    }
    FUN_0046bf33(&stack0xffffff88,s_movement_suspended_00491d2c);
    local_44 = CONCAT31(local_44._1_3_,0x2d);
    pcVar12 = *(code **)(iVar21 + -8);
    pcVar16 = (code *)(param_2 + 10);
    pcVar14 = (code *)((DAT_004aa824 - DAT_004a72d0 / 0x32) + (int)pcVar10 * -2);
    (*(code *)ppvStack_98)(pcVar16,pcVar14,iVar21);
    piVar2 = (int *)&stack0xffffff78;
  }
  auStack_54[0] = 0;
  FUN_0046bec5(piVar2);
  if (DAT_004ac92c == 0) {
    (*pcVar20)(0x7f7f00);
  }
  if (0 < DAT_004a5b80) {
    unaff_EDI = FUN_00413d00(&stack0xffffff78,DAT_004a5e84);
    auStack_54[0] = 0x2e;
    FUN_00413d00(&stack0xffffff84,DAT_004a4be4);
    auStack_54[0] = 0x2f;
    FUN_0046c14f();
    auStack_54[0] = 0x30;
    FUN_0046c0db();
    auStack_54[0] = 0x31;
    piVar2 = (int *)FUN_0046c075();
    auStack_54[0] = 0x32;
    (*pcVar12)((param_2 + param_4 * 2) / 3 + -3,
               (DAT_004aa824 - DAT_004a72d0 / 0x32) + (int)pcVar10 * -2,*piVar2,
               *(undefined4 *)(*piVar2 + -8));
    auStack_54[0] = 0x31;
    FUN_0046bec5((int *)&stack0xffffff90);
    auStack_54[0] = 0x30;
    FUN_0046bec5((int *)&stack0xffffff8c);
    auStack_54[0] = 0x2f;
    FUN_0046bec5((int *)&stack0xffffff88);
    auStack_54[0] = 0x2e;
    FUN_0046bec5((int *)&stack0xffffff84);
    auStack_54[0] = 0;
    FUN_0046bec5((int *)&stack0xffffff78);
  }
  (*pcVar20)(0);
  SelectObject(hdc,unaff_EDI);
  DeleteObject(unaff_EBX);
  pcVar12 = (code *)(DAT_004a72d0 / 0x32);
  if (((DAT_004a5ba0 - DAT_004a3f04 / 0xf <= DAT_004aa824 - (int)pcVar12) ||
      (DAT_004a4f80 <= DAT_004aa808 + -0x14)) || (DAT_004ab150 + 0x14 <= DAT_004a4f80)) {
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
    }
    iVar8 = (int)pcVar12 * 10;
    Rectangle(*(HDC *)(param_1 + 4),param_2,DAT_004aa824 - (int)pcVar12,param_4,iVar8 + DAT_004aa824
             );
    (*pcVar18)(0x7f7f7f);
    if (DAT_004a763c < 0x385) {
      iVar5 = param_2 - param_4;
      iVar7 = param_2 - ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2);
      iVar11 = iVar7 + 0xc;
      iVar5 = param_2 - iVar5 / 3;
      ppvStack_98 = (void **)(iVar5 + 0xc);
    }
    else if (DAT_004a5264 < 0x15) {
      iVar5 = param_2 - param_4;
      iVar7 = param_2 - ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2);
      iVar11 = iVar7 + 0x1e;
      iVar5 = param_2 - iVar5 / 3;
      ppvStack_98 = (void **)(iVar5 + 0x1e);
    }
    else {
      iVar5 = param_2 - param_4;
      iVar7 = param_2 - ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2);
      iVar11 = iVar7 + 0x10;
      iVar5 = param_2 - iVar5 / 3;
      ppvStack_98 = (void **)(iVar5 + 0x10);
    }
    if (DAT_004a763c < 700) {
      iVar11 = iVar7 + -1;
      ppvStack_98 = (void **)(iVar5 + -1);
    }
    if ((DAT_004ac9c8 == 0) || (*(int *)(&DAT_004a4e88 + param_6 * 4) == 3)) {
      FUN_0046bf33(&stack0xffffff74,s_Steering_Zone_00491d10);
      iStack_5c = CONCAT31(iStack_5c._1_3_,0x33);
      (*pcVar14)(iVar11,(DAT_004aa824 - (int)pcVar12) + 2,iVar8);
    }
    else {
      FUN_0046bf33(&stack0xffffff74,s_Steering_Zone_00491d10);
      iStack_5c = CONCAT31(iStack_5c._1_3_,0x34);
      (*pcVar14)(ppvStack_98,(DAT_004aa824 - (int)pcVar12) + 2,iVar8);
    }
    FUN_0046bec5((int *)&pcStack_9c);
    (*pcVar20)(0xffffff);
    goto LAB_0040d995;
  }
  if (DAT_004ac92c == 0) {
    if (DAT_004a469c != (HGDIOBJ)0x0) {
      pHVar13 = *(HDC *)(param_1 + 4);
      h = DAT_004a469c;
LAB_0040d7a5:
      SelectObject(pHVar13,h);
    }
  }
  else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
    pHVar13 = *(HDC *)(param_1 + 4);
    h = DAT_004aa7f4;
    goto LAB_0040d7a5;
  }
  Rectangle(*(HDC *)(param_1 + 4),param_2,DAT_004aa824 - (int)pcVar12,param_4,
            DAT_004aa824 + (int)pcVar12 * 10);
LAB_0040d995:
  (*pcVar9)(7);
  FUN_004706bd(param_1,(int *)&stack0xffffff90,DAT_004a70ec,DAT_004aa824 - (int)pcVar12);
  CDC::LineTo(param_1,DAT_004a70ec,(int)(pcVar18 + DAT_004aa824));
  if (0 < DAT_004ac9c4) {
    iVar8 = 3000;
    ppvStack_98 = (void **)0x2;
    if (1 < DAT_0049118c) {
      iVar11 = 0;
      do {
        FUN_0042c400(*(double *)((int)&DAT_004a49f8 + iVar11),
                     *(double *)((int)&DAT_004a4af0 + iVar11),1,1);
        if ((int)(longlong)_DAT_004a6828 < iVar8) {
          iVar8 = (int)(longlong)_DAT_004a6828;
        }
        ppvStack_98 = (void **)((int)ppvStack_98 + 1);
        iVar11 = iVar11 + 8;
        pcVar12 = pcVar1;
      } while ((int)ppvStack_98 <= DAT_0049118c);
    }
    piVar2 = FUN_00413d90(&stack0xffffff98);
    iStack_5c._0_1_ = 0x35;
    FUN_0046bfbe(&pcStack_9c,piVar2);
    iStack_5c._0_1_ = 0;
    FUN_0046bec5((int *)&stack0xffffff98);
    (*pcVar17)();
    piVar2 = (int *)FUN_0046c14f();
    iStack_60 = CONCAT31(iStack_60._1_3_,0x36);
    (*pcVar16)(param_2 - ((int)((param_2 - param_4) + (param_2 - param_4 >> 0x1f & 3U)) >> 2),
               (iVar21 - (int)pcVar12) + 2 + DAT_004aa824,*piVar2,*(undefined4 *)(*piVar2 + -8));
    iStack_5c = (uint)iStack_5c._1_3_ << 8;
    FUN_0046bec5((int *)&stack0xffffff98);
  }
  (*pcVar17)();
  iStack_60 = -1;
  FUN_0046bec5((int *)&stack0xffffff60);
  *unaff_FS_OFFSET = pcVar1;
  return;
}


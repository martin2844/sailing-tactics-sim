
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040e9a0(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  code *pcVar2;
  float10 fVar3;
  int *piVar4;
  uint uVar5;
  int unaff_EBX;
  int unaff_EDI;
  int iVar6;
  undefined1 *puVar7;
  code *pcVar8;
  int *unaff_FS_OFFSET;
  float10 fVar9;
  int unaff_retaddr;
  undefined4 uVar10;
  undefined1 **ppuStack_94;
  int iStack_90;
  code *pcStack_8c;
  int iStack_80;
  undefined1 *puStack_7c;
  HDC pHVar11;
  HGDIOBJ ho;
  undefined1 *puStack_6c;
  undefined *puStack_68;
  undefined1 *puStack_64;
  int iVar12;
  int iVar13;
  int iVar14;
  HDC pHVar15;
  uint uVar16;
  undefined3 uVar18;
  int iVar17;
  undefined4 uVar19;
  int iVar20;
  int local_34;
  int local_30 [2];
  int iStack_28;
  int iStack_24;
  undefined1 uStack_20;
  undefined4 local_1c;
  HGDIOBJ local_18;
  HDC local_14;
  HRGN local_10;
  int iStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047ddc8;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  pHVar11 = *(HDC *)(param_1 + 4);
  local_14 = pHVar11;
  local_10 = CreateRectRgn(param_2,param_3,param_4,param_5);
  local_18 = SelectObject(pHVar11,local_10);
  FUN_0046bd7a(local_30);
  iVar6 = DAT_004a72d0 / 0x1f;
  local_4 = 0;
  DAT_004aa7e0 = FUN_0042d0c0(param_6);
  fVar9 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + DAT_004aa7e0 * 8),
                                        *(undefined4 *)(&DAT_004a52f0 + DAT_004aa7e0 * 8)),
                       (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + DAT_004aa7e0 * 8),
                                        *(undefined4 *)(&DAT_004a60b0 + DAT_004aa7e0 * 8)),0,param_6
                      );
  fVar3 = (float10)_DAT_00484d78;
  *(int *)(&DAT_004aa6e0 + param_6 * 4) = (int)(longlong)(_DAT_004a6828 * _DAT_00484d70);
  DAT_004ac66c = FUN_00415dc0((int)(longlong)(fVar9 * fVar3) - *(int *)(&DAT_004ac018 + param_6 * 4)
                             );
  local_1c = (undefined4)(longlong)_DAT_004a6828;
  iVar1 = *(int *)param_1;
  iVar20 = 7;
  pcVar2 = *(code **)(iVar1 + 0x2c);
  local_34 = iVar1;
  (*pcVar2)();
  uVar19 = 0;
  (*pcVar2)();
  puStack_64 = (undefined1 *)0x40ead6;
  Rectangle(*(HDC *)(param_1 + 4),unaff_retaddr,iVar6,param_2,param_3);
  uVar16 = 0xffffff;
  iVar6 = iVar6 + 1;
  (**(code **)(iVar1 + 0x34))();
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar1 + 0x38))();
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar1 + 0x38))();
    }
  }
  piVar4 = FUN_00413d90(local_30);
  local_10._0_1_ = 1;
  FUN_0046bfbe(&stack0xffffffc4,piVar4);
  local_10._0_1_ = 0;
  FUN_0046bec5(local_30);
  FUN_0046bf33(&local_34,s_speed__00491e80);
  iVar17 = local_4;
  pcVar2 = *(code **)(iVar1 + 100);
  local_10 = (HRGN)CONCAT31(local_10._1_3_,2);
  iVar1 = local_4 + 1;
  pHVar11 = *(HDC *)(local_34 + -8);
  puStack_64 = (undefined1 *)0x40eb70;
  iVar12 = iVar1;
  iVar13 = iVar6;
  iVar14 = local_34;
  (*pcVar2)();
  uStack_20 = 0;
  puStack_64 = (undefined1 *)0x40eb7e;
  FUN_0046bec5((int *)&stack0xffffffbc);
  puStack_64 = &stack0xffffffb4;
  puStack_6c = &stack0xffffffc0;
  puStack_68 = &DAT_004911f0;
  puVar7 = (undefined1 *)(iVar6 + (int)local_18);
  piVar4 = (int *)FUN_0046c14f();
  puStack_68 = (undefined *)*piVar4;
  uStack_20 = 3;
  puStack_64 = *(undefined1 **)((int)puStack_68 + -8);
  puStack_6c = puVar7;
  (*pcVar2)();
  local_30[0]._0_1_ = 0;
  FUN_0046bec5((int *)&stack0xffffffb0);
  puVar7 = puVar7 + iStack_28;
  if (*(double *)(&DAT_004a7f28 + (int)local_14 * 8) <= _DAT_00484d80) {
    pHVar15 = pHVar11;
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar12 + 0x38))();
      pHVar15 = pHVar11;
    }
    puStack_7c = (undefined1 *)0x40ed17;
    FUN_00413d00(&stack0xffffffac,(uint)(longlong)*(double *)(&DAT_004a7f28 + (int)local_14 * 8));
    puStack_7c = &stack0xffffffb0;
    local_30[0]._0_1_ = 8;
    iStack_80 = 0x40ed2f;
    piVar4 = (int *)FUN_0046c14f();
    pHVar11 = (HDC)*piVar4;
    local_30[0]._0_1_ = 9;
    ho = (HGDIOBJ)pHVar11[-2].unused;
    iStack_80 = iVar1;
    puStack_7c = puVar7;
    (*pcVar2)();
    FUN_0046bec5((int *)&stack0xffffffa0);
    FUN_0046bec5((int *)&puStack_64);
    if (((*(double *)(&DAT_004a7f28 + iStack_24 * 8) < _DAT_00484d80) &&
        (_DAT_00484d80 < *(double *)(&DAT_004a4510 + iStack_24 * 8))) && (DAT_004ac9c0 == 0)) {
      MessageBeep(0);
    }
  }
  else {
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar12 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffac,s_sail__0049219c);
    local_30[0]._0_1_ = 4;
    ho = (HGDIOBJ)pHVar11[-2].unused;
    iStack_80 = iVar1;
    puStack_7c = puVar7;
    pHVar15 = pHVar11;
    (*pcVar2)();
    FUN_0046bec5((int *)&puStack_64);
    puVar7 = puVar7 + unaff_EBX;
    if (*(int *)(&DAT_004a7768 + iStack_24 * 4) == 1) {
      FUN_0046bf33(&puStack_64,s_flat_00492194);
      ppuStack_94 = (undefined1 **)0x40ec57;
      iStack_90 = iVar1;
      pcStack_8c = (code *)puVar7;
      (*pcVar2)();
      FUN_0046bec5((int *)&puStack_64);
    }
    if (*(int *)(&DAT_004a7768 + iStack_24 * 4) == 2) {
      FUN_0046bf33(&puStack_64,s_medium_0049218c);
      ppuStack_94 = (undefined1 **)0x40ec95;
      iStack_90 = iVar1;
      pcStack_8c = (code *)puVar7;
      (*pcVar2)();
      FUN_0046bec5((int *)&puStack_64);
    }
    if (*(int *)(&DAT_004a7768 + iStack_24 * 4) == 3) {
      FUN_0046bf33(&puStack_64,s_baggy_00492184);
      ppuStack_94 = (undefined1 **)0x40ecd7;
      iStack_90 = iVar1;
      pcStack_8c = (code *)puVar7;
      (*pcVar2)();
      FUN_0046bec5((int *)&puStack_64);
    }
  }
  pcVar8 = (code *)(puVar7 + unaff_EBX);
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar17 + 0x39))();
  }
  pcStack_8c = (code *)0x40edcf;
  piVar4 = FUN_00413d00(&stack0xffffffa0,*(uint *)(&DAT_004a8aa8 + iStack_24 * 4));
  FUN_0046bfbe(&puStack_6c,piVar4);
  FUN_0046bec5((int *)&stack0xffffffa0);
  FUN_0046bf33(&puStack_64,s_luffing__00492178);
  iVar6 = *(int *)(puStack_64 + -8);
  ppuStack_94 = (undefined1 **)0x40ee11;
  iStack_90 = iVar1;
  pcStack_8c = pcVar8;
  (*pcVar2)();
  uVar16 = uVar16 & 0xffffff00;
  ppuStack_94 = (undefined1 **)0x40ee1f;
  FUN_0046bec5((int *)&stack0xffffff8c);
  ppuStack_94 = &puStack_7c;
  pcVar8 = pcVar8 + iVar20;
  FUN_0046c14f();
  ppuStack_94 = (undefined1 **)&DAT_00491e4c;
  uVar18 = (undefined3)(uVar16 >> 8);
  piVar4 = (int *)FUN_0046c0db();
  iVar17 = CONCAT31(uVar18,0xd);
  ppuStack_94 = *(undefined1 ***)(*piVar4 + -8);
  (*pcVar2)(iVar1,pcVar8,*piVar4);
  FUN_0046bec5(&iStack_80);
  FUN_0046bec5((int *)&stack0xffffff7c);
  pcVar8 = pcVar8 + iVar14;
  if (DAT_004ac92c == 0) {
    (**(code **)(iStack_90 + 0x38))(0x7f00);
  }
  if (*(int *)(&DAT_004a7868 + unaff_EDI * 4) == 0) {
    FUN_0046bf33(&stack0xffffff7c,s_air_ok_00492170);
    (*pcVar2)(iVar1,pcVar8,iVar6,*(undefined4 *)(iVar6 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
  }
  else if (DAT_004ac92c == 0) {
    (**(code **)(iStack_90 + 0x38))(0xff);
  }
  if ((*(int *)(&DAT_004a7868 + unaff_EDI * 4) == 2) ||
     (*(int *)(&DAT_004a7868 + unaff_EDI * 4) == 0xc)) {
    FUN_0046bf33(&stack0xffffff7c,s_blankt_00492168);
    (*pcVar2)(iVar1,pcVar8,iVar6,*(undefined4 *)(iVar6 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
  }
  if (*(int *)(&DAT_004a7868 + unaff_EDI * 4) == 3) {
    FUN_0046bf33(&stack0xffffff7c,s_bckwnd_00492160);
    (*pcVar2)(iVar1,pcVar8,iVar6,*(undefined4 *)(iVar6 + -8));
    FUN_0046bec5((int *)&stack0xffffff7c);
  }
  pcVar8 = pcVar8 + iVar14;
  if (DAT_004ac92c == 0) {
    (**(code **)(iStack_90 + 0x38))(0x7f0000);
  }
  uVar16 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + unaff_EDI * 4) - DAT_004a4f8c);
  if (0xb4 < (int)uVar16) {
    uVar16 = uVar16 - 0x168;
  }
  uVar5 = (uVar16 ^ (int)uVar16 >> 0x1f) - ((int)uVar16 >> 0x1f);
  DAT_004ac964 = (uint)(0x28 < (int)uVar5);
  if ((DAT_004ac978 == 0) && (DAT_004ac964 == 0)) {
    if (0 < (int)(uVar16 * *(int *)(&DAT_004aa730 + unaff_EDI * 4))) {
      FUN_00413d00(&puStack_7c,uVar5);
      piVar4 = (int *)FUN_0046c14f();
      (*pcVar2)(iVar1,pcVar8,*piVar4,*(undefined4 *)(*piVar4 + -8));
      FUN_0046bec5(&iStack_80);
      FUN_0046bec5((int *)&puStack_7c);
    }
    if (uVar16 == 0) {
      FUN_0046bf33(&iStack_80,s_wnd_av_00492150);
      (*pcVar2)(iVar1,pcVar8,iStack_80,*(undefined4 *)(iStack_80 + -8));
      FUN_0046bec5(&iStack_80);
    }
    if ((int)(uVar16 * *(int *)(&DAT_004aa730 + unaff_EDI * 4)) < 0) {
      if (DAT_004ac978 == 0) {
        FUN_00413d00(&iStack_80,uVar5);
        piVar4 = (int *)FUN_0046c14f();
        (*pcVar2)(iVar1,pcVar8,*piVar4,*(undefined4 *)(*piVar4 + -8));
        FUN_0046bec5((int *)&puStack_7c);
        FUN_0046bec5(&iStack_80);
      }
      if ((((DAT_004a7bcc < 0x37) &&
           (0x2d < (int)((DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f))))
          && (10 < (int)uVar5)) && ((300 < (int)pHVar11 && (unaff_EDI == 1)))) {
        DAT_004a620c = 1;
      }
    }
  }
  pcVar8 = pcVar8 + iVar14 + 2;
  (**(code **)(iStack_90 + 0x38))(0xff0000);
  if ((*(int *)(&DAT_004a8910 + iVar20 * 4) == 1) && (*(int *)(&DAT_004ac1e8 + iVar20 * 4) == 0)) {
    FUN_0046bf33(&stack0xffffff7c,s_closehauled_0049213c);
    puStack_64._0_1_ = 0x16;
    (*pcVar2)(iVar1,pcVar8,uVar5,*(undefined4 *)(uVar5 - 8));
    puStack_64 = (undefined1 *)((uint)puStack_64._1_3_ << 8);
    FUN_0046bec5((int *)&stack0xffffff7c);
  }
  if ((*(int *)(&DAT_004a8910 + iVar20 * 4) == 1) && (*(int *)(&DAT_004ac1e8 + iVar20 * 4) == 5)) {
    FUN_0046bf33(&stack0xffffff7c,s_footing_00492134);
    puStack_64._0_1_ = 0x17;
    (*pcVar2)(iVar1,pcVar8,uVar5,*(undefined4 *)(uVar5 - 8));
    puStack_64 = (undefined1 *)((uint)puStack_64._1_3_ << 8);
    FUN_0046bec5((int *)&stack0xffffff7c);
  }
  if ((*(int *)(&DAT_004a8910 + iVar20 * 4) == 1) && (*(int *)(&DAT_004ac1e8 + iVar20 * 4) == -5)) {
    FUN_0046bf33(&stack0xffffff7c,s_pinching_00492128);
    puStack_64._0_1_ = 0x18;
    (*pcVar2)(iVar1,pcVar8,uVar5,*(undefined4 *)(uVar5 - 8));
    puStack_64 = (undefined1 *)((uint)puStack_64._1_3_ << 8);
    FUN_0046bec5((int *)&stack0xffffff7c);
  }
  if (*(int *)(&DAT_004a4968 + iVar20 * 4) == 1) {
    FUN_0046bf33(&stack0xffffff7c,s_running_00492120);
    puStack_64._0_1_ = 0x19;
    (*pcVar2)(iVar1,pcVar8,uVar5,*(undefined4 *)(uVar5 - 8));
    puStack_64 = (undefined1 *)((uint)puStack_64._1_3_ << 8);
    FUN_0046bec5((int *)&stack0xffffff7c);
  }
  pcVar8 = pcVar8 + iVar13;
  if (0 < DAT_004a5b80) {
    if (DAT_004ac92c == 0) {
      if ((DAT_004aa7e0 == 3) || (DAT_004aa7e0 == 5)) {
        uVar10 = 0x7f;
      }
      else {
        uVar10 = 0x7f7f;
      }
      (*pcStack_8c)(uVar10);
      if (DAT_004aa7e0 == 2) {
        (*pcStack_8c)(0x7f7f);
      }
    }
    if (0 < (int)DAT_004ac66c) {
      FUN_00413d00(&stack0xffffff7c,DAT_004ac66c);
      puStack_64._0_1_ = 0x1a;
      FUN_0046c14f();
      puStack_64._0_1_ = 0x1b;
      piVar4 = (int *)FUN_0046c0db();
      puStack_64._0_1_ = 0x1c;
      (*pcVar2)(iVar1,pcVar8,*piVar4,*(undefined4 *)(*piVar4 + -8));
      puStack_64._0_1_ = 0x1b;
      FUN_0046bec5((int *)&puStack_7c);
      puStack_64._0_1_ = 0x1a;
      FUN_0046bec5(&iStack_80);
      puStack_64 = (undefined1 *)((uint)puStack_64._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff7c);
    }
    if ((int)DAT_004ac66c < 0) {
      FUN_00413d00(&stack0xffffff7c,
                   (DAT_004ac66c ^ (int)DAT_004ac66c >> 0x1f) - ((int)DAT_004ac66c >> 0x1f));
      puStack_64._0_1_ = 0x1d;
      FUN_0046c14f();
      puStack_64._0_1_ = 0x1e;
      piVar4 = (int *)FUN_0046c0db();
      puStack_64._0_1_ = 0x1f;
      (*pcVar2)(iVar1,pcVar8,*piVar4,*(undefined4 *)(*piVar4 + -8));
      puStack_64._0_1_ = 0x1e;
      FUN_0046bec5((int *)&puStack_7c);
      puStack_64._0_1_ = 0x1d;
      FUN_0046bec5(&iStack_80);
      puStack_64 = (undefined1 *)((uint)puStack_64._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff7c);
    }
    if (DAT_004ac66c == 0) {
      FUN_0046bf33(&stack0xffffff7c,s_mark__ahead_004920fc);
      puStack_64._0_1_ = 0x20;
      (*pcVar2)(iVar1,pcVar8,uVar5,*(undefined4 *)(uVar5 - 8));
      puStack_64 = (undefined1 *)((uint)puStack_64._1_3_ << 8);
      FUN_0046bec5((int *)&stack0xffffff7c);
    }
  }
  if (iVar20 == 1) {
    FUN_00409760(param_1,iVar14,(int)pHVar15,iVar17,uVar19,1,iVar13);
  }
  else {
    FUN_0040b990(param_1,iVar14,(int)pHVar15,iVar17);
  }
  (*pcStack_8c)(0);
  SelectObject(pHVar11,puStack_7c);
  DeleteObject(ho);
  puStack_68 = (undefined *)0xffffffff;
  FUN_0046bec5((int *)&ppuStack_94);
  *unaff_FS_OFFSET = iVar1;
  return;
}


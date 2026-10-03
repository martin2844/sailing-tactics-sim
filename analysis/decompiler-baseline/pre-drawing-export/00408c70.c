
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00408c70(int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar9;
  int unaff_retaddr;
  int iStack_64;
  int iStack_44;
  code *pcVar10;
  int iStack_28;
  undefined1 local_14 [8];
  code *pcStack_c;
  code *pcStack_8;
  code *local_4;
  
  local_4 = (code *)0xffffffff;
  pcStack_8 = FUN_0047d788;
  pcStack_c = (code *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &pcStack_c;
  iStack_28 = 0x408c95;
  FUN_0046bd7a((undefined4 *)local_14);
  iStack_28 = 4;
  iVar1 = *param_1;
  local_4 = (code *)0x0;
  pcVar8 = *(code **)(iVar1 + 0x2c);
  (*pcVar8)();
  (*pcVar8)();
  iStack_44 = 0x408ccd;
  Rectangle((HDC)param_1[1],unaff_retaddr,(int)param_1,param_2,(int)(param_1 + 5));
  (**(code **)(iVar1 + 0x34))();
  if (DAT_004ac92c == 0) {
    pcVar8 = *(code **)(iVar1 + 0x38);
    pcStack_8 = pcVar8;
    (*pcVar8)();
  }
  else {
    pcStack_8 = *(code **)(iVar1 + 0x38);
    (*pcStack_8)();
    pcVar8 = pcStack_c;
  }
  FUN_0046bf33(&local_4,s___TIDE_CHART___00491958);
  pcVar2 = *(code **)(iVar1 + 100);
  local_14[0] = 1;
  iStack_44 = 1;
  pcVar10 = local_4;
  (*pcVar2)();
  FUN_0046bec5((int *)local_14);
  if (DAT_004ac92c == 0) {
    (*pcVar8)();
  }
  if ((int)DAT_004ac94c < 1) {
    FUN_0046bf33(local_14,s_Time_is_now__00491924);
    (*pcVar2)();
    piVar5 = (int *)&stack0xffffffdc;
  }
  else if ((int)DAT_004ac94c < 2) {
    FUN_00413d00(&stack0xffffffe8,DAT_004ac94c);
    FUN_0046c14f();
    FUN_0046c0db();
    (*pcVar2)();
    FUN_0046bec5((int *)&stack0xffffffdc);
    FUN_0046bec5((int *)&stack0xffffffe0);
    piVar5 = &iStack_28;
  }
  else {
    FUN_00413d00(&stack0xffffffe8,DAT_004ac94c);
    FUN_0046c14f();
    FUN_0046c0db();
    (*pcVar2)();
    FUN_0046bec5((int *)&stack0xffffffdc);
    FUN_0046bec5((int *)&stack0xffffffe0);
    piVar5 = &iStack_28;
  }
  FUN_0046bec5(piVar5);
  if (DAT_004ac92c == 0) {
    (*pcVar8)();
  }
  fVar9 = (float10)fsin((float10)(int)(((DAT_004ac94c - DAT_004a8020) + DAT_004a4be4) * 0x1e) *
                        (float10)_DAT_00484d40);
  uVar4 = (uint)(longlong)(fVar9 * (float10)DAT_004ac1dc);
  uVar7 = (int)uVar4 >> 0x1f;
  iStack_64 = 0x408eec;
  piVar5 = FUN_00413d90(&stack0xffffffdc);
  FUN_0046bfbe(&iStack_44,piVar5);
  FUN_0046bec5((int *)&stack0xffffffdc);
  if ((int)((uVar4 ^ uVar7) - uVar7) < 0xb) {
    iStack_64 = 0x408f7c;
    FUN_0046c14f();
    iStack_64 = 0x408f91;
    puVar6 = (undefined4 *)FUN_0046c0db();
    uVar3 = *puVar6;
    iStack_64 = 0x172;
    (*pcVar2)();
    iStack_44._0_1_ = 0xc;
    FUN_0046bec5((int *)&stack0xffffffcc);
  }
  else {
    iStack_64 = 0x408f24;
    FUN_0046c14f();
    iStack_64 = 0x408f39;
    puVar6 = (undefined4 *)FUN_0046c0db();
    uVar3 = *puVar6;
    iStack_64 = 0x172;
    (*pcVar2)();
    iStack_44._0_1_ = 10;
    FUN_0046bec5((int *)&stack0xffffffcc);
  }
  iStack_44 = (uint)iStack_44._1_3_ << 8;
  FUN_0046bec5((int *)&stack0xffffffd0);
  if (DAT_004ac92c == 0) {
    (*pcVar10)(0x7f);
    (*(code *)0x96)(0xffffff);
  }
  FUN_0046bf33(&stack0xffffffc4,s_Movement_suspended__Click_mouse_o_004918bc);
  iStack_44 = CONCAT31(iStack_44._1_3_,0xe);
  (*pcVar2)(1,DAT_004a72d0 / 0x1b,pcVar10,*(undefined4 *)(pcVar10 + -8));
  FUN_0046bec5((int *)&stack0xffffffb4);
  FUN_0046bec5(&iStack_64);
  *unaff_FS_OFFSET = uVar3;
  return;
}


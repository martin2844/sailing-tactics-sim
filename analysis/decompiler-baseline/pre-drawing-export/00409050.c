
void __cdecl FUN_00409050(int *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  code *pcVar3;
  int *unaff_FS_OFFSET;
  int unaff_retaddr;
  code *pcVar4;
  int iVar5;
  int *piStack_5c;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined3 uVar10;
  code *pcVar9;
  int iStack_38;
  int iStack_20;
  int iStack_1c;
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d818;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iStack_38 = 0x40907d;
  FUN_0047033f(param_1,1);
  iVar6 = *param_1;
  pcVar3 = *(code **)(iVar6 + 0x2c);
  iStack_38 = 0x409088;
  (*pcVar3)();
  iStack_38 = 6;
  (*pcVar3)();
  Rectangle((HDC)param_1[1],unaff_retaddr,(int)param_1,param_2,(int)(param_1 + 10));
  (**(code **)(iVar6 + 0x34))();
  (**(code **)(iVar6 + 0x38))();
  if (DAT_004ac9a8 == 1) {
    FUN_0046bf33(&iStack_c,s___RACE_COURSE___marks_to_starboa_004919c4);
    pcVar3 = *(code **)(iVar6 + 100);
    uStack_14 = 0;
    uVar7 = *(uint *)(iStack_c + -8);
    iVar6 = 1;
    (*pcVar3)();
  }
  else {
    FUN_0046bf33(&iStack_c,s___RACE_COURSE___marks_to_port_004919a0);
    pcVar3 = *(code **)(iVar6 + 100);
    uStack_14 = 1;
    uVar7 = *(uint *)(iStack_c + -8);
    iVar6 = 1;
    (*pcVar3)();
  }
  FUN_0046bec5(&iStack_1c);
  uVar1 = DAT_004abc80;
  piStack_5c = (int *)0x409171;
  FUN_0041bb10(DAT_004aa38c - DAT_004aa294,DAT_004aa388 - DAT_004aa588);
  if ((DAT_00491160 == 0) || (0xe < DAT_0049118c)) {
    piStack_5c = (int *)0x4091b8;
    FUN_0041bb10(DAT_004aa288 - DAT_004aa38c,DAT_004aa588 - DAT_004aa384);
  }
  piStack_5c = (int *)0x4091ca;
  FUN_00413d00(auStack_18,uVar1);
  piStack_5c = &iStack_10;
  FUN_0046c14f();
  piStack_5c = &iStack_1c;
  FUN_0046c0db();
  piStack_5c = (int *)(DAT_004a72d0 / 0x1e);
  (*pcVar3)(1);
  FUN_0046bec5((int *)&stack0xffffffd4);
  FUN_0046bec5(&iStack_20);
  FUN_0046bec5((int *)&stack0xffffffd8);
  FUN_00413d00(&stack0xffffffd8,uVar7);
  FUN_0046c14f();
  piVar2 = (int *)FUN_0046c0db();
  iVar5 = DAT_004a72d0 / 0x1e;
  (*pcVar3)(0xa0,iVar5,*piVar2,*(undefined4 *)(*piVar2 + -8));
  FUN_0046bec5((int *)&stack0xffffffc4);
  FUN_0046bec5((int *)&stack0xffffffd0);
  FUN_0046bec5(&iStack_38);
  FUN_00413d00(&iStack_38,1);
  uVar8 = 0;
  FUN_0046c14f();
  uVar10 = (undefined3)((uint)uVar8 >> 8);
  piVar2 = (int *)FUN_0046c0db();
  pcVar9 = (code *)CONCAT31(uVar10,10);
  pcVar4 = *(code **)(*piVar2 + -8);
  (*pcVar3)(0x140,DAT_004a72d0 / 0x1e,*piVar2);
  FUN_0046bec5((int *)&stack0xffffffb4);
  FUN_0046bec5((int *)&stack0xffffffc0);
  FUN_0046bec5((int *)&stack0xffffffb8);
  if ((DAT_00491160 == 0) || (0xe < DAT_0049118c)) {
    FUN_00413d00(&stack0xffffffb8,DAT_004abc80);
    FUN_0046c14f();
    piVar2 = (int *)FUN_0046c0db();
    (*pcVar3)(0x1e0,DAT_004a72d0 / 0x1e,*piVar2,*(undefined4 *)(*piVar2 + -8));
    FUN_0046bec5((int *)&stack0xffffffb4);
    FUN_0046bec5((int *)&stack0xffffffc0);
    FUN_0046bec5((int *)&stack0xffffffb8);
  }
  FUN_0047033f(param_1,2);
  if (DAT_004ac92c == 0) {
    (*pcVar9)(0x7f);
    (*pcVar4)(0xffffff);
  }
  FUN_0046bf33(&stack0xffffffb4,s_Movement_suspended__Click_mouse_o_004918bc);
  (*pcVar3)(1,(DAT_004a72d0 * 2) / 0x1b,iVar6,*(undefined4 *)(iVar6 + -8));
  FUN_0046bec5((int *)&piStack_5c);
  *unaff_FS_OFFSET = iVar5;
  return;
}


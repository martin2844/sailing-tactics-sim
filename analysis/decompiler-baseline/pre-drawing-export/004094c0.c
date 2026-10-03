
void __cdecl FUN_004094c0(int *param_1,int param_2)

{
  code *pcVar1;
  code *pcVar2;
  int *unaff_FS_OFFSET;
  int unaff_retaddr;
  int in_stack_ffffff60;
  int aiStack_90 [4];
  int in_stack_ffffff80;
  code *pcStack_7c;
  int iStack_70;
  int iStack_5c;
  int iStack_48;
  int iVar3;
  int iStack_20;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d870;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iStack_20 = 4;
  iVar3 = *param_1;
  pcVar1 = *(code **)(iVar3 + 0x2c);
  (*pcVar1)();
  (*pcVar1)();
  Rectangle((HDC)param_1[1],unaff_retaddr,(int)param_1,param_2,(int)(param_1 + 5));
  (**(code **)(iVar3 + 0x34))();
  pcVar1 = *(code **)(iVar3 + 0x38);
  (*pcVar1)();
  FUN_0046bf33(&iStack_c,s___WIND_CHART___00491a44);
  pcVar2 = *(code **)(iVar3 + 100);
  iVar3 = iStack_c;
  (*pcVar2)();
  FUN_0046bec5((int *)&stack0xffffffe4);
  if (DAT_004ac92c == 0) {
    (*pcVar1)();
    iStack_48 = 0x409582;
    FUN_0046bf33(&iStack_20,s_Mixing_00491a3c);
    iStack_48 = iStack_20;
    (*pcVar2)();
    FUN_0046bec5((int *)&stack0xffffffd0);
    (*pcVar1)();
    iStack_5c = 0x4095c2;
    FUN_0046bf33(&stack0xffffffcc,s_Convergence_00491a30);
    iStack_5c = iVar3;
    (*pcVar2)();
    FUN_0046bec5((int *)&stack0xffffffbc);
    (*pcVar1)();
    iStack_70 = 0x409602;
    FUN_0046bf33(&iStack_48,s_Divergence_00491a24);
    iStack_70 = iStack_48;
    (*pcVar2)();
    FUN_0046bec5((int *)&stack0xffffffa8);
    pcStack_7c = (code *)0xff;
    (*pcVar1)();
    aiStack_90[3] = 0x409642;
    FUN_0046bf33(&iStack_5c,&DAT_00491a1c);
    in_stack_ffffff80 = *(int *)(iStack_5c + -8);
    aiStack_90[3] = iStack_5c;
    aiStack_90[2] = 1;
    aiStack_90[1] = 500;
    aiStack_90[0] = 0x40965e;
    (*pcVar2)();
    aiStack_90[0] = 0x40966b;
    FUN_0046bec5((int *)&stack0xffffff94);
    aiStack_90[0] = 0xffff00;
    (*pcVar1)();
    FUN_0046bf33(&iStack_70,s_Channeled_00491a10);
    in_stack_ffffff60 = 0x226;
    (*pcVar2)(0x226,1,iStack_70,*(undefined4 *)(iStack_70 + -8));
  }
  else {
    FUN_0046bf33(&stack0xffffffe4,s_Transient_puff_vectors_are_black_004919ec);
    iStack_48 = 1;
    (*pcVar2)();
  }
  aiStack_90[2] = 0xffffffff;
  FUN_0046bec5((int *)&stack0xffffff80);
  if (DAT_004ac92c == 0) {
    (*pcVar1)(0x7f);
    (*pcStack_7c)(0xffffff);
  }
  FUN_0046bf33(&stack0xffffff80,s_Movement_suspended__Click_mouse_o_004918bc);
  aiStack_90[2] = 7;
  (*pcVar2)(1,DAT_004a72d0 / 0x1b,in_stack_ffffff80,*(undefined4 *)(in_stack_ffffff80 + -8));
  FUN_0046bec5(aiStack_90);
  *unaff_FS_OFFSET = in_stack_ffffff60;
  return;
}


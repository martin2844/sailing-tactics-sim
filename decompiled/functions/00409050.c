
void __cdecl FUN_00409050(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  int this;
  int iVar3;
  TactCString *pTVar4;
  code *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  COLORREF CVar6;
  int iStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d818;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_0047033f((void *)param_1,1);
  iVar1 = *(int *)this;
  pcVar2 = *(code **)(iVar1 + 0x2c);
  (*pcVar2)((void *)this,4);
  (*pcVar2)((void *)this,6);
  Rectangle(*(HDC *)(this + 4),param_2,param_3,param_4,param_3 + 0x28);
  pcVar2 = *(code **)(iVar1 + 0x34);
  (*pcVar2)((void *)this,0);
  param_3 = *(undefined4 *)(iVar1 + 0x38);
  if (DAT_004ac92c == 0) {
    CVar6 = 0xffff;
  }
  else {
    CVar6 = 0xffffff;
  }
  (*(code *)param_3)((void *)this,CVar6);
  if (DAT_004ac9a8 == 1) {
    FUN_0046bf33(&param_1,s___RACE_COURSE___marks_to_starboa_004919c4);
    pcVar5 = *(code **)(iVar1 + 100);
    uStack_4 = 0;
    (*pcVar5)((void *)this,1,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  else {
    FUN_0046bf33(&param_1,s___RACE_COURSE___marks_to_port_004919a0);
    pcVar5 = *(code **)(iVar1 + 100);
    uStack_4 = 1;
    (*pcVar5)((void *)this,1,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  iVar1 = DAT_004abc80;
  iVar3 = FUN_0041bb10(DAT_004aa38c - DAT_004aa294,DAT_004aa388 - DAT_004aa588);
  if ((DAT_00491160 == 0) || (0xe < DAT_0049118c)) {
    iStack_10 = FUN_0041bb10(DAT_004aa288 - DAT_004aa38c,DAT_004aa588 - DAT_004aa384);
  }
  else {
    iStack_10 = DAT_004abc80;
  }
  pTVar4 = FUN_00413d00((TactCString *)&param_2,iVar1);
  uStack_4 = 2;
  pTVar4 = FUN_0046c14f((TactCString *)&param_4,s_1st_leg__00491994,pTVar4);
  uStack_4._0_1_ = 3;
  pTVar4 = FUN_0046c0db((TactCString *)&param_1,pTVar4,&DAT_0049198c);
  uStack_4._0_1_ = 4;
  (*pcVar5)((void *)this,1,DAT_004a72d0 / 0x1e,pTVar4->data,*(int *)(pTVar4->data + -8));
  uStack_4._0_1_ = 3;
  FUN_0046bec5(&param_1);
  uStack_4 = CONCAT31(uStack_4._1_3_,2);
  FUN_0046bec5(&param_4);
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  pTVar4 = FUN_00413d00((TactCString *)&param_2,iVar3);
  uStack_4 = 5;
  pTVar4 = FUN_0046c14f((TactCString *)&param_4,s_2nd_leg__00491980,pTVar4);
  uStack_4._0_1_ = 6;
  pTVar4 = FUN_0046c0db((TactCString *)&param_1,pTVar4,&DAT_0049198c);
  uStack_4._0_1_ = 7;
  (*pcVar5)((void *)this,0xa0,DAT_004a72d0 / 0x1e,pTVar4->data,*(int *)(pTVar4->data + -8));
  uStack_4._0_1_ = 6;
  FUN_0046bec5(&param_1);
  uStack_4 = CONCAT31(uStack_4._1_3_,5);
  FUN_0046bec5(&param_4);
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  pTVar4 = FUN_00413d00((TactCString *)&param_2,iStack_10);
  uStack_4 = 8;
  pTVar4 = FUN_0046c14f((TactCString *)&param_4,s_3rd_leg__00491974,pTVar4);
  uStack_4._0_1_ = 9;
  pTVar4 = FUN_0046c0db((TactCString *)&param_1,pTVar4,&DAT_0049198c);
  uStack_4._0_1_ = 10;
  (*pcVar5)((void *)this,0x140,DAT_004a72d0 / 0x1e,pTVar4->data,*(int *)(pTVar4->data + -8));
  uStack_4._0_1_ = 9;
  FUN_0046bec5(&param_1);
  uStack_4 = CONCAT31(uStack_4._1_3_,8);
  FUN_0046bec5(&param_4);
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  if ((DAT_00491160 == 0) || (0xe < DAT_0049118c)) {
    pTVar4 = FUN_00413d00((TactCString *)&param_2,DAT_004abc80);
    uStack_4 = 0xb;
    pTVar4 = FUN_0046c14f((TactCString *)&param_4,s_4th_leg__00491968,pTVar4);
    uStack_4._0_1_ = 0xc;
    pTVar4 = FUN_0046c0db((TactCString *)&param_1,pTVar4,&DAT_0049198c);
    uStack_4._0_1_ = 0xd;
    (*pcVar5)((void *)this,0x1e0,DAT_004a72d0 / 0x1e,pTVar4->data,*(int *)(pTVar4->data + -8));
    uStack_4._0_1_ = 0xc;
    FUN_0046bec5(&param_1);
    uStack_4 = CONCAT31(uStack_4._1_3_,0xb);
    FUN_0046bec5(&param_4);
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_2);
  }
  FUN_0047033f((void *)this,2);
  if (DAT_004ac92c == 0) {
    (*(code *)param_3)((void *)this,0x7f);
    (*pcVar2)((void *)this,0xffffff);
  }
  FUN_0046bf33(&param_1,s_Movement_suspended__Click_mouse_o_004918bc);
  uStack_4 = 0xe;
  (*pcVar5)((void *)this,1,(DAT_004a72d0 * 2) / 0x1b,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}



/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00408c70(int param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  uint uVar2;
  int this;
  TactCString *pTVar3;
  int *piVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar8;
  TactCString local_14;
  code *pcStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d788;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_0046bd7a(&local_14);
  this = param_1;
  iVar7 = *(int *)param_1;
  local_4 = 0;
  pcVar6 = *(code **)(iVar7 + 0x2c);
  (*pcVar6)((void *)param_1,4);
  (*pcVar6)((void *)this,6);
  Rectangle(*(HDC *)(this + 4),param_2,param_3,param_4,param_3 + 0x14);
  pcStack_10 = *(code **)(iVar7 + 0x34);
  (*pcStack_10)((void *)this,0);
  if (DAT_004ac92c == 0) {
    pcVar6 = *(code **)(iVar7 + 0x38);
    param_1 = (int)pcVar6;
    (*pcVar6)((void *)this,0xffff);
  }
  else {
    param_1 = *(undefined4 *)(iVar7 + 0x38);
    (*(code *)param_1)((void *)this,0xffffff);
    pcVar6 = (code *)param_1;
  }
  FUN_0046bf33(&param_3,s___TIDE_CHART___00491958);
  pcVar1 = *(code **)(iVar7 + 100);
  local_4._0_1_ = 1;
  (*pcVar1)((void *)this,1,1,(LPCSTR)param_3,*(int *)(param_3 + -8));
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5(&param_3);
  if (DAT_004ac92c == 0) {
    (*pcVar6)((void *)this,0xff00ff);
  }
  if (DAT_004ac94c < 1) {
    FUN_0046bf33(&param_3,s_Time_is_now__00491924);
    local_4._0_1_ = 8;
    (*pcVar1)((void *)this,0x96,1,(LPCSTR)param_3,*(int *)(param_3 + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    piVar4 = &param_3;
  }
  else if (DAT_004ac94c < 2) {
    pTVar3 = FUN_00413d00((TactCString *)&param_2,DAT_004ac94c);
    local_4._0_1_ = 5;
    pTVar3 = FUN_0046c14f((TactCString *)&param_4,s_Time_is__present___00491944,pTVar3);
    local_4._0_1_ = 6;
    pTVar3 = FUN_0046c0db((TactCString *)&param_3,pTVar3,s_hour__00491934);
    local_4._0_1_ = 7;
    (*pcVar1)((void *)this,0x96,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 6;
    FUN_0046bec5(&param_3);
    local_4._0_1_ = 5;
    FUN_0046bec5(&param_4);
    local_4 = (uint)local_4._1_3_ << 8;
    piVar4 = &param_2;
  }
  else {
    pTVar3 = FUN_00413d00((TactCString *)&param_2,DAT_004ac94c);
    local_4._0_1_ = 2;
    pTVar3 = FUN_0046c14f((TactCString *)&param_4,s_Time_is__present___00491944,pTVar3);
    local_4._0_1_ = 3;
    pTVar3 = FUN_0046c0db((TactCString *)&param_3,pTVar3,s_hours__0049193c);
    local_4._0_1_ = 4;
    (*pcVar1)((void *)this,0x96,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 3;
    FUN_0046bec5(&param_3);
    local_4._0_1_ = 2;
    FUN_0046bec5(&param_4);
    local_4 = (uint)local_4._1_3_ << 8;
    piVar4 = &param_2;
  }
  FUN_0046bec5(piVar4);
  if (DAT_004ac92c == 0) {
    (*pcVar6)((void *)this,0xffff);
  }
  fVar8 = (float10)fsin((float10)(((DAT_004ac94c - DAT_004a8020) + DAT_004a4be4) * 0x1e) *
                        (float10)_DAT_00484d40);
  uVar2 = (uint)(longlong)(fVar8 * (float10)DAT_004ac1dc);
  uVar5 = (int)uVar2 >> 0x1f;
  iVar7 = (uVar2 ^ uVar5) - uVar5;
  param_3 = iVar7;
  pTVar3 = FUN_00413d90((TactCString *)&param_3,(double)iVar7 * _DAT_00484d48);
  local_4._0_1_ = 9;
  FUN_0046bfbe(&local_14,(int *)pTVar3);
  local_4._0_1_ = 0;
  FUN_0046bec5(&param_3);
  if (iVar7 < 0xb) {
    pTVar3 = FUN_0046c14f((TactCString *)&param_4,s_Deep_water_current_is__0049190c,&local_14);
    local_4._0_1_ = 0xc;
    pTVar3 = FUN_0046c0db((TactCString *)&param_3,pTVar3,s_knot__004918fc);
    local_4._0_1_ = 0xd;
    (*pcVar1)((void *)this,0x172,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 0xc;
    FUN_0046bec5(&param_3);
  }
  else {
    pTVar3 = FUN_0046c14f((TactCString *)&param_4,s_Deep_water_current_is__0049190c,&local_14);
    local_4._0_1_ = 10;
    pTVar3 = FUN_0046c0db((TactCString *)&param_3,pTVar3,s_knots__00491904);
    local_4._0_1_ = 0xb;
    (*pcVar1)((void *)this,0x172,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 10;
    FUN_0046bec5(&param_3);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5(&param_4);
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)((void *)this,0x7f);
    (*pcStack_10)((void *)this,0xffffff);
  }
  FUN_0046bf33(&param_1,s_Movement_suspended__Click_mouse_o_004918bc);
  local_4._0_1_ = 0xe;
  (*pcVar1)((void *)this,1,DAT_004a72d0 / 0x1b,(LPCSTR)param_1,*(int *)(param_1 + -8));
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5(&param_1);
  local_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_14);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


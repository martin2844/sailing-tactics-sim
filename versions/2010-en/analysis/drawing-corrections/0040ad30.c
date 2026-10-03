
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040ad30(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  uint uVar2;
  int *original_dc;
  Tact2010CString *pTVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar7;
  Tact2010CString local_14;
  code *pcStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c1ed8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_004b045a(&local_14);
  original_dc = param_1;
  iVar6 = *param_1;
  local_4 = 0;
  pcVar5 = *(code **)(iVar6 + 0x2c);
  (*pcVar5)(param_1,4);
  (*pcVar5)(original_dc,6);
  Rectangle((HDC)original_dc[1],param_2,param_3,param_4,param_3 + 0x14);
  pcStack_10 = *(code **)(iVar6 + 0x34);
  (*pcStack_10)(original_dc,0);
  if (DAT_005363e4 == 0) {
    pcVar5 = *(code **)(iVar6 + 0x38);
    param_1 = (int *)pcVar5;
    (*pcVar5)(original_dc,0xffff);
  }
  else {
    param_1 = *(int **)(iVar6 + 0x38);
    (*(code *)param_1)(original_dc,0xffffff);
    pcVar5 = (code *)param_1;
  }
  FUN_004b0613((Tact2010CString *)&param_3,s___TIDE_CHART___004daa30);
  pcVar1 = *(code **)(iVar6 + 100);
  local_4._0_1_ = 1;
  (*pcVar1)(original_dc,1,1,(char *)param_3,*(int *)(param_3 + -8));
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b05a5((Tact2010CString *)&param_3);
  if (DAT_005363e4 == 0) {
    (*pcVar5)(original_dc,0xff00ff);
  }
  if (DAT_00536404 < 1) {
    FUN_004b0613((Tact2010CString *)&param_3,s_Time_is_now__004da9fc);
    local_4._0_1_ = 8;
    (*pcVar1)(original_dc,0x96,1,(char *)param_3,*(int *)(param_3 + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    pTVar3 = (Tact2010CString *)&param_3;
  }
  else if (DAT_00536404 < 2) {
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_00536404);
    local_4._0_1_ = 5;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_Time_is__present___004daa1c,pTVar3);
    local_4._0_1_ = 6;
    pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,s_hour__004daa0c);
    local_4._0_1_ = 7;
    (*pcVar1)(original_dc,0x96,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 6;
    FUN_004b05a5((Tact2010CString *)&param_3);
    local_4._0_1_ = 5;
    FUN_004b05a5((Tact2010CString *)&param_4);
    local_4 = (uint)local_4._1_3_ << 8;
    pTVar3 = (Tact2010CString *)&param_2;
  }
  else {
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_00536404);
    local_4._0_1_ = 2;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_Time_is__present___004daa1c,pTVar3);
    local_4._0_1_ = 3;
    pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,s_hours__004daa14);
    local_4._0_1_ = 4;
    (*pcVar1)(original_dc,0x96,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 3;
    FUN_004b05a5((Tact2010CString *)&param_3);
    local_4._0_1_ = 2;
    FUN_004b05a5((Tact2010CString *)&param_4);
    local_4 = (uint)local_4._1_3_ << 8;
    pTVar3 = (Tact2010CString *)&param_2;
  }
  FUN_004b05a5(pTVar3);
  if (DAT_005363e4 == 0) {
    (*pcVar5)(original_dc,0xffff);
  }
  fVar7 = (float10)fsin((float10)(((DAT_00536404 + DAT_004f6d60) - DAT_004ffdd0) * 0x1e) *
                        (float10)_DAT_004cc568);
  uVar2 = (uint)(longlong)(fVar7 * (float10)DAT_005359d0);
  uVar4 = (int)uVar2 >> 0x1f;
  iVar6 = (uVar2 ^ uVar4) - uVar4;
  param_3 = iVar6;
  if (DAT_004da1f8 == 0) {
    pTVar3 = FUN_0041bd00((Tact2010CString *)&param_3,(double)iVar6 * _DAT_004cc570);
    local_4._0_1_ = 9;
    FUN_004b069e(&local_14,pTVar3);
    local_4._0_1_ = 0;
    FUN_004b05a5((Tact2010CString *)&param_3);
    if (iVar6 < 0xb) {
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_Deep_water_current_is__004da9e4,&local_14)
      ;
      local_4._0_1_ = 0xc;
      pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,s_knot__004da9d4);
      local_4._0_1_ = 0xd;
      (*pcVar1)(original_dc,0x172,1,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4._0_1_ = 0xc;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    else {
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_Deep_water_current_is__004da9e4,&local_14)
      ;
      local_4._0_1_ = 10;
      pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,s_knots__004da9dc);
      local_4._0_1_ = 0xb;
      (*pcVar1)(original_dc,0x172,1,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4._0_1_ = 10;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5((Tact2010CString *)&param_4);
    if (DAT_005363e4 == 0) {
      (*(code *)param_1)(original_dc,0x7f);
      (*pcStack_10)(original_dc,0xffffff);
    }
  }
  (*(code *)param_1)(original_dc,0xff);
  FUN_004b0613((Tact2010CString *)&param_1,s_Movement_suspended__Click_mouse_o_004da994);
  local_4._0_1_ = 0xe;
  (*pcVar1)(original_dc,1,(DAT_004fe2a8 - DAT_004fe2a8 / 10) + -5,(char *)param_1,param_1[-2]);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b05a5((Tact2010CString *)&param_1);
  local_4 = 0xffffffff;
  FUN_004b05a5(&local_14);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


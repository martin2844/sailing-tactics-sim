
void __cdecl FUN_00430f90(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int *this;
  uint uVar2;
  TactCString *pTVar3;
  TactCString *pTVar4;
  undefined4 *unaff_FS_OFFSET;
  COLORREF CVar5;
  TactCString TStack_18;
  TactCString TStack_14;
  TactCString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar1 = DAT_004ac92c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e630;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar1 == 0) {
    iVar1 = *param_1;
    if (DAT_004ac8fc == 1) {
      CVar5 = 0xffffff;
    }
    else {
      CVar5 = 0;
    }
    (**(code **)(iVar1 + 0x34))(param_1,CVar5);
    (**(code **)(iVar1 + 0x38))(this,0xff);
  }
  uVar2 = param_3;
  iVar1 = param_2;
  if (*(int *)(&DAT_004a89c0 + param_3 * 4) == 1) {
    FUN_0046bf33(&param_1,s_PENALTY__HIT_MARK___Rule_31___004936c4);
    uStack_4 = 0;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 2) {
    FUN_0046bf33(&param_1,s_PENALTY__OVER_EARLY___Rule_29_1___0049369c);
    uStack_4 = 1;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 3) {
    FUN_0046bf33(&param_1,s_PENALTY__FAILURE_TO_GIVE_ROOM___R_00493668);
    uStack_4 = 2;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 4) {
    FUN_0046bf33(&param_1,s_PENALTY__PORT_TACK___Rule_10___00493644);
    uStack_4 = 3;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 5) {
    FUN_0046bf33(&param_1,s_PENALTY__WINDWARD_BOAT___Rule_11_0049361c);
    uStack_4 = 4;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 6) {
    FUN_0046bf33(&param_1,s_PENALTY__OVERTAKING_BOAT___Rule_1_004935f4);
    uStack_4 = 5;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 7) {
    FUN_0046bf33(&param_1,s_PENALTY__TACKED_TOO_CLOSE___Rule_004935c8);
    uStack_4 = 6;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 10) {
    FUN_0046bf33(&param_1,s_AGROUND_004935bc);
    uStack_4 = 7;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (*(int *)(&DAT_004a89c0 + uVar2 * 4) == 0xb) {
    pTVar3 = FUN_00413d00(&TStack_10,*(int *)(&DAT_004a7648 + uVar2 * 4));
    uStack_4 = 8;
    pTVar4 = FUN_00413d00(&TStack_14,uVar2);
    uStack_4._0_1_ = 9;
    pTVar4 = FUN_0046c14f(&TStack_18,s_Boat_0049317c,pTVar4);
    uStack_4._0_1_ = 10;
    pTVar4 = FUN_0046c0db((TactCString *)&param_2,pTVar4,s_finished_004935b0);
    uStack_4._0_1_ = 0xb;
    pTVar3 = FUN_0046c075((TactCString *)&param_3,pTVar4,pTVar3);
    uStack_4._0_1_ = 0xc;
    pTVar3 = FUN_0046c0db((TactCString *)&param_1,pTVar3,s___Please_wait_for_last_boat__00493590);
    uStack_4._0_1_ = 0xd;
    (**(code **)(*this + 100))(this,iVar1,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    uStack_4._0_1_ = 0xc;
    FUN_0046bec5((int *)&param_1);
    uStack_4._0_1_ = 0xb;
    FUN_0046bec5((int *)&param_3);
    uStack_4._0_1_ = 10;
    FUN_0046bec5(&param_2);
    uStack_4._0_1_ = 9;
    FUN_0046bec5((int *)&TStack_18);
    uStack_4 = CONCAT31(uStack_4._1_3_,8);
    FUN_0046bec5((int *)&TStack_14);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&TStack_10);
  }
  if ((DAT_004ac8fc == 1) && (uVar2 == DAT_00491140)) {
    FUN_0046bf33(&param_1,s_Movement_suspended__Click_mouse_t_00493564);
    uStack_4 = 0xe;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if ((DAT_004ac968 == 1) && (uVar2 == DAT_00491140)) {
    FUN_0046bf33(&param_1,s_Movement_suspended__Click_mouse_t_00493564);
    uStack_4 = 0xf;
    (**(code **)(*this + 100))(this,iVar1,1,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  iVar1 = *this;
  (**(code **)(iVar1 + 0x34))(this,0xffffff);
  (**(code **)(iVar1 + 0x38))(this,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}



void __cdecl FUN_00444350(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *original_dc;
  Tact2010CString *pTVar2;
  Tact2010CString *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  Tact2010CString TStack_18;
  Tact2010CString TStack_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar1 = DAT_005363e4;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c3390;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar1 == 0) {
    iVar1 = *param_1;
    if (DAT_005363b4 == 1) {
      iVar4 = 0xffffff;
    }
    else {
      iVar4 = 0;
    }
    (**(code **)(iVar1 + 0x34))(param_1,iVar4);
    (**(code **)(iVar1 + 0x38))(original_dc,0xff);
  }
  iVar4 = param_3;
  iVar1 = param_2;
  if (*(int *)(&DAT_005116e0 + param_3 * 4) == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PENALTY__HIT_MARK___Rule_31___004dd9c8);
    uStack_4 = 0;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 2) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PENALTY__RECALL__Rule_28_1__004dd9a0);
    uStack_4 = 1;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 3) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PENALTY__FAILURE_TO_GIVE_ROOM___R_004dd96c);
    uStack_4 = 2;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 4) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PENALTY__PORT_TACK___Rule_10___004dd948);
    uStack_4 = 3;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 5) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PENALTY__WINDWARD_BOAT___Rule_11_004dd920);
    uStack_4 = 4;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 6) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PENALTY__OVERTAKING_BOAT___Rule_1_004dd8f8);
    uStack_4 = 5;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 7) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PENALTY__TACKED_TOO_CLOSE___Rule_004dd8cc);
    uStack_4 = 6;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 10) {
    FUN_004b0613((Tact2010CString *)&param_1,s_AGROUND_004dd8c0);
    uStack_4 = 7;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (*(int *)(&DAT_005116e0 + iVar4 * 4) == 0xb) {
    pTVar2 = FUN_0041bc70(&TStack_10,*(int *)(&DAT_004fe638 + iVar4 * 4));
    uStack_4 = 8;
    pTVar3 = FUN_0041bc70(&TStack_14,iVar4);
    uStack_4._0_1_ = 9;
    pTVar3 = FUN_004b082f(&TStack_18,s_Boat_004dd23c,pTVar3);
    uStack_4._0_1_ = 10;
    pTVar3 = FUN_004b07bb((Tact2010CString *)&param_2,pTVar3,s_finished_004dd8b4);
    uStack_4._0_1_ = 0xb;
    pTVar2 = FUN_004b0755((Tact2010CString *)&param_3,pTVar3,pTVar2);
    uStack_4._0_1_ = 0xc;
    pTVar2 = FUN_004b07bb((Tact2010CString *)&param_1,pTVar2,s___Please_wait_for_last_boat__004dd894
                         );
    uStack_4._0_1_ = 0xd;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,pTVar2->data,*(int *)(pTVar2->data + -8));
    uStack_4._0_1_ = 0xc;
    FUN_004b05a5((Tact2010CString *)&param_1);
    uStack_4._0_1_ = 0xb;
    FUN_004b05a5((Tact2010CString *)&param_3);
    uStack_4._0_1_ = 10;
    FUN_004b05a5((Tact2010CString *)&param_2);
    uStack_4._0_1_ = 9;
    FUN_004b05a5(&TStack_18);
    uStack_4 = CONCAT31(uStack_4._1_3_,8);
    FUN_004b05a5(&TStack_14);
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_005363b4 == 1) && (iVar4 == DAT_004da140)) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Movement_suspended__Click_mouse_t_004dd868);
    uStack_4 = 0xe;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if ((DAT_0053642c == 1) && (iVar4 == DAT_004da140)) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Movement_suspended__Click_mouse_t_004dd868);
    uStack_4 = 0xf;
    (**(code **)(*original_dc + 100))(original_dc,iVar1,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  iVar1 = *original_dc;
  (**(code **)(iVar1 + 0x34))(original_dc,0xffffff);
  (**(code **)(iVar1 + 0x38))(original_dc,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


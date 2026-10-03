
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

void __cdecl FUN_0047cea0(int *param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  int *original_dc;
  Tact2010CString *pTVar3;
  uint uVar4;
  Tact2010CString TVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar7;
  Tact2010CString local_2c;
  Tact2010CString TStack_28;
  Tact2010CString TStack_24;
  Tact2010CString TStack_20;
  Tact2010CString local_1c;
  Tact2010CString TStack_18;
  tagPOINT local_14;
  undefined4 uStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c5f68;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  GetCursorPos(&local_14);
  original_dc = param_1;
  DAT_004f7f78 = local_14.x;
  local_2c.data = (char *)(local_14.x - param_3);
  DAT_004f8ee4 = local_14.y;
  TVar5.data = (char *)((int)(longlong)((double)(int)local_2c.data / param_2) + DAT_00536410);
  param_4 = (int)(longlong)((double)((local_14.y - DAT_004f3ff0 / 0xe) - param_4) / param_2) +
            DAT_00536414;
  iVar1 = *param_1;
  local_1c.data = TVar5.data;
  (**(code **)(iVar1 + 0x38))(param_1,0x7fff);
  (**(code **)(iVar1 + 0x34))(original_dc,0);
  if (DAT_005364b0 == 1) {
    param_1 = (int *)FUN_0041bc70(&TStack_20,DAT_00536410);
    iStack_4 = 0;
    pTVar3 = FUN_0041bc70(&TStack_24,(int)TVar5.data);
    iStack_4._0_1_ = 1;
    pTVar3 = FUN_004b082f(&TStack_28,s_xWorldMouse_004ecad0,pTVar3);
    iStack_4._0_1_ = 2;
    pTVar3 = FUN_004b07bb(&local_2c,pTVar3,s_xs_004ecac8);
    iStack_4._0_1_ = 3;
    pTVar3 = FUN_004b0755((Tact2010CString *)&param_2,pTVar3,(Tact2010CString *)param_1);
    pcVar2 = *(code **)(iVar1 + 100);
    iStack_4._0_1_ = 4;
    (*pcVar2)(original_dc,0x2ee,0x96,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4._0_1_ = 3;
    FUN_004b05a5((Tact2010CString *)&param_2);
    iStack_4._0_1_ = 2;
    FUN_004b05a5(&local_2c);
    iStack_4._0_1_ = 1;
    FUN_004b05a5(&TStack_28);
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    FUN_004b05a5(&TStack_24);
    iStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
    param_1 = (int *)FUN_0041bc70(&local_2c,DAT_00536414);
    iStack_4 = 5;
    pTVar3 = FUN_0041bc70(&TStack_28,param_4);
    iStack_4._0_1_ = 6;
    pTVar3 = FUN_004b082f(&TStack_24,s_yWorldMouse_004ecab8,pTVar3);
    iStack_4._0_1_ = 7;
    pTVar3 = FUN_004b07bb(&TStack_20,pTVar3,s_ys_004ecab0);
    iStack_4._0_1_ = 8;
    pTVar3 = FUN_004b0755((Tact2010CString *)&param_2,pTVar3,(Tact2010CString *)param_1);
    iStack_4._0_1_ = 9;
    (*pcVar2)(original_dc,0x2ee,0xaa,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4._0_1_ = 8;
    FUN_004b05a5((Tact2010CString *)&param_2);
    iStack_4._0_1_ = 7;
    FUN_004b05a5(&TStack_20);
    iStack_4._0_1_ = 6;
    FUN_004b05a5(&TStack_24);
    iStack_4 = CONCAT31(iStack_4._1_3_,5);
    FUN_004b05a5(&TStack_28);
    iStack_4 = 0xffffffff;
    FUN_004b05a5(&local_2c);
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_004da200);
    iStack_4 = 10;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_1,s_widechart_004ecaa4,pTVar3);
    iStack_4._0_1_ = 0xb;
    (*pcVar2)(original_dc,0x2ee,0xbe,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4 = CONCAT31(iStack_4._1_3_,10);
    FUN_004b05a5((Tact2010CString *)&param_1);
    iStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_00522fd0);
    iStack_4 = 0xc;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_1,s_100000fspacing_004eca94,pTVar3);
    iStack_4._0_1_ = 0xd;
    (*pcVar2)(original_dc,0x2ee,0xd2,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4 = CONCAT31(iStack_4._1_3_,0xc);
    FUN_004b05a5((Tact2010CString *)&param_1);
    iStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_005364fc);
    iStack_4 = 0xe;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_1,s_creating_004eca88,pTVar3);
    iStack_4._0_1_ = 0xf;
    (*pcVar2)(original_dc,0x2ee,0xe6,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4 = CONCAT31(iStack_4._1_3_,0xe);
    FUN_004b05a5((Tact2010CString *)&param_1);
    iStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_1,param_3);
    iStack_4 = 0x10;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_3,s_xmid_004eca80,pTVar3);
    iStack_4._0_1_ = 0x11;
    (*pcVar2)(original_dc,0x2ee,0xfa,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4 = CONCAT31(iStack_4._1_3_,0x10);
    FUN_004b05a5((Tact2010CString *)&param_3);
    iStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    TVar5.data = local_1c.data;
  }
  if (DAT_005233a8 == 1) {
    fVar7 = FUN_0042f330((int)TVar5.data,param_4,0);
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,(int)(longlong)fVar7);
    iStack_4 = 0x12;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_1," depth at pointer: ",pTVar3);
    iStack_4._0_1_ = 0x13;
    pTVar3 = FUN_004b07bb((Tact2010CString *)&param_3,pTVar3,s__004eca64);
    iStack_4._0_1_ = 0x14;
    (**(code **)(iVar1 + 100))
              (original_dc,DAT_004fe624 + -0x96,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4._0_1_ = 0x13;
    FUN_004b05a5((Tact2010CString *)&param_3);
    iStack_4 = CONCAT31(iStack_4._1_3_,0x12);
    FUN_004b05a5((Tact2010CString *)&param_1);
    iStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if (DAT_00536434 == 1) {
    FUN_00436ba0((int)TVar5.data,param_4,0);
    param_3 = (int)FUN_0041bc70(&TStack_28,DAT_00522b90);
    iStack_4 = 0x15;
    pTVar3 = FUN_0041bc70(&TStack_24,DAT_004fb380);
    iStack_4._0_1_ = 0x16;
    pTVar3 = FUN_004b082f(&TStack_20," wind speed at pointer: ",pTVar3);
    iStack_4._0_1_ = 0x17;
    pTVar3 = FUN_004b07bb(&local_1c,pTVar3,s_direction__004eca38);
    iStack_4._0_1_ = 0x18;
    pTVar3 = FUN_004b0755((Tact2010CString *)&param_2,pTVar3,(Tact2010CString *)param_3);
    iStack_4._0_1_ = 0x19;
    pTVar3 = FUN_004b07bb((Tact2010CString *)&param_1,pTVar3,s__004eca14);
    iStack_4._0_1_ = 0x1a;
    (**(code **)(iVar1 + 100))
              (original_dc,DAT_004fe624 + -0x15e,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4._0_1_ = 0x19;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iStack_4._0_1_ = 0x18;
    FUN_004b05a5((Tact2010CString *)&param_2);
    iStack_4._0_1_ = 0x17;
    FUN_004b05a5(&local_1c);
    iStack_4._0_1_ = 0x16;
    FUN_004b05a5(&TStack_20);
    iStack_4 = CONCAT31(iStack_4._1_3_,0x15);
    FUN_004b05a5(&TStack_24);
    iStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_28);
  }
  if (DAT_00536438 == 1) {
    if (DAT_004da1f8 < 1) {
      uVar4 = FUN_0042fca0((int)TVar5.data,param_4,0);
    }
    else {
      uVar4 = FUN_00430260((int)TVar5.data,param_4,0);
    }
    iVar6 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
    param_4 = (int)FUN_0041bc70(&TStack_18,DAT_00536418);
    iStack_4 = 0x1b;
    param_3 = (int)FUN_0041bc70(&local_2c,iVar6 % 10);
    iStack_4._0_1_ = 0x1c;
    pTVar3 = FUN_0041bc70(&TStack_28,iVar6 / 10);
    iStack_4._0_1_ = 0x1d;
    pTVar3 = FUN_004b082f(&TStack_24," current speed at pointer: ",pTVar3);
    iStack_4._0_1_ = 0x1e;
    pTVar3 = FUN_004b07bb(&TStack_20,pTVar3,(char *)&DAT_004dd054);
    iStack_4._0_1_ = 0x1f;
    pTVar3 = FUN_004b0755(&local_1c,pTVar3,(Tact2010CString *)param_3);
    iStack_4._0_1_ = 0x20;
    pTVar3 = FUN_004b07bb((Tact2010CString *)&param_2,pTVar3,s_direction__004eca38);
    iStack_4._0_1_ = 0x21;
    pTVar3 = FUN_004b0755((Tact2010CString *)&param_1,pTVar3,(Tact2010CString *)param_4);
    iStack_4._0_1_ = 0x22;
    (**(code **)(iVar1 + 100))
              (original_dc,DAT_004fe624 + -0x15e,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    iStack_4._0_1_ = 0x21;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iStack_4._0_1_ = 0x20;
    FUN_004b05a5((Tact2010CString *)&param_2);
    iStack_4._0_1_ = 0x1f;
    FUN_004b05a5(&local_1c);
    iStack_4._0_1_ = 0x1e;
    FUN_004b05a5(&TStack_20);
    iStack_4._0_1_ = 0x1d;
    FUN_004b05a5(&TStack_24);
    iStack_4._0_1_ = 0x1c;
    FUN_004b05a5(&TStack_28);
    iStack_4 = CONCAT31(iStack_4._1_3_,0x1b);
    FUN_004b05a5(&local_2c);
    iStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_18);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


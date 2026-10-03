
void __cdecl FUN_004148f0(int *param_1,int param_2)

{
  code *pcVar1;
  int *original_dc;
  Tact2010CString *pTVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  bool bVar4;
  int iVar5;
  int iVar6;
  int local_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2b78;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_14 = 0x10;
  if (DAT_004f3f5c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f3f5c);
  }
  iVar6 = *original_dc;
  (**(code **)(iVar6 + 0x2c))(original_dc,7);
  iVar3 = param_2;
  Rectangle((HDC)original_dc[1],0,param_2 + -2,DAT_004fe624,DAT_004fe2a8);
  if (DAT_004fe624 < 900) {
    local_14 = 0xe;
  }
  FUN_004b4a1f(original_dc,1);
  param_2 = *(undefined4 *)(iVar6 + 0x38);
  if (DAT_005363e4 == 0) {
    iVar5 = 0x7f0000;
  }
  else {
    iVar5 = 0;
  }
  (*(code *)param_2)(original_dc,iVar5);
  FUN_004b0613((Tact2010CString *)&param_1,s_Major_Options__004dc118);
  pcVar1 = *(code **)(iVar6 + 100);
  uStack_4 = 0;
  (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    iVar6 = 0xff0000;
  }
  else {
    iVar6 = 0;
  }
  (*(code *)param_2)(original_dc,iVar6);
  if (((((DAT_004da190 == 8) || (1 < DAT_005363c0)) || (DAT_005363b8 == 1)) ||
      ((DAT_004fb410 == 1 || (DAT_004da190 < 6)))) || (DAT_00536528 == 1)) {
    pTVar2 = FUN_0041bc70(&TStack_10,DAT_004da1fc);
    uStack_4 = 1;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_1,s_Draft__004dc110,pTVar2);
    uStack_4._0_1_ = 2;
    (*pcVar1)(original_dc,5,iVar3,pTVar2->data,*(int *)(pTVar2->data + -8));
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    FUN_004b05a5((Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((((5 < DAT_004da190) && (DAT_004da190 < 8)) &&
      ((DAT_005364c8 == 0 && (((DAT_005363c0 != 2 && (DAT_005363c0 != 3)) && (DAT_005363b8 == 0)))))
      ) && (DAT_00536528 == 0)) {
    pTVar2 = FUN_0041bc70(&TStack_10,DAT_004faa48);
    uStack_4 = 3;
    pTVar2 = FUN_004b082f((Tact2010CString *)&param_1,s_Length__004dc104,pTVar2);
    uStack_4._0_1_ = 4;
    (*pcVar1)(original_dc,5,iVar3,pTVar2->data,*(int *)(pTVar2->data + -8));
    uStack_4 = CONCAT31(uStack_4._1_3_,3);
    FUN_004b05a5((Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
    if (DAT_004f7ecc == 0xb) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Heavy_displacement_004dc0f0);
      uStack_4 = 5;
      (*pcVar1)(original_dc,DAT_004fe624 / 5 + -10,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004f7ecc == 10) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Moderate_displacement_004dc0d8);
      uStack_4 = 6;
      (*pcVar1)(original_dc,DAT_004fe624 / 5 + -10,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004f7ecc == 9) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Light_displacement_004dc0c4);
      uStack_4 = 7;
      (*pcVar1)(original_dc,DAT_004fe624 / 5 + -10,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004f7ecc < 9) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Ultra_light_displacement_004dc0a8);
      uStack_4 = 8;
      (*pcVar1)(original_dc,DAT_004fe624 / 5 + -10,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004f8d70 < 10) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Less_than_average_sail_004dc090);
      uStack_4 = 9;
      (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5 + 5,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    bVar4 = false;
    if (DAT_004f8d70 == 10) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Average_sail_area_004dc07c);
      uStack_4 = 10;
      (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5 + 5,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
      bVar4 = DAT_004f8d70 == 10;
    }
    if (!bVar4 && 9 < DAT_004f8d70) {
      FUN_004b0613((Tact2010CString *)&param_1,s_More_than_average_sail_004dc064);
      uStack_4 = 0xb;
      (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5 + 5,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da150 < 100) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Fractional_rig_004dc054);
      uStack_4 = 0xc;
      (*pcVar1)(original_dc,(DAT_004fe624 * 3) / 5 + 5,iVar3,(char *)param_1,param_1[-2]);
    }
    else {
      FUN_004b0613((Tact2010CString *)&param_1,s_Masthead_rig_004dc044);
      uStack_4 = 0xd;
      (*pcVar1)(original_dc,(DAT_004fe624 * 3) / 5 + 5,iVar3,(char *)param_1,param_1[-2]);
    }
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if ((DAT_004da190 == 7) ||
       (((DAT_004da190 == 6 && (DAT_005363c0 < 2)) && ((DAT_005364c8 == 0 && (DAT_005363b8 == 0)))))
       ) {
      pTVar2 = FUN_0041bc70(&TStack_10,DAT_004da1fc);
      uStack_4 = 0xe;
      pTVar2 = FUN_004b082f((Tact2010CString *)&param_1,s_Draft__004dc110,pTVar2);
      uStack_4._0_1_ = 0xf;
      (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                pTVar2->data,*(int *)(pTVar2->data + -8));
      uStack_4 = CONCAT31(uStack_4._1_3_,0xe);
      FUN_004b05a5((Tact2010CString *)&param_1);
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_10);
    }
    iVar3 = iVar3 + local_14;
  }
  if (899 < DAT_004fe624) {
    iVar3 = iVar3 + local_14;
  }
  if (DAT_005363e4 == 0) {
    (*(code *)param_2)(original_dc,0x7f00);
  }
  pTVar2 = FUN_0041bc70(&TStack_10,DAT_004da198);
  uStack_4 = 0x10;
  pTVar2 = FUN_004b082f((Tact2010CString *)&param_1,"Difficulty= ",pTVar2);
  uStack_4._0_1_ = 0x11;
  (*pcVar1)(original_dc,5,iVar3,pTVar2->data,*(int *)(pTVar2->data + -8));
  uStack_4 = CONCAT31(uStack_4._1_3_,0x10);
  FUN_004b05a5((Tact2010CString *)&param_1);
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  param_1 = (int *)(DAT_004fe624 / 5 + -10);
  if (DAT_005363e4 == 0) {
    (*(code *)param_2)(original_dc,0x7f);
  }
  if (DAT_004da144 == 1) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Optimist_004dc020);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 2) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Laser_004dc00c);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 3) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Board_004dbff8);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 4) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Snipe_004dbfe4);
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 5) {
    FUN_004b0613(&TStack_10,s_Boat_Type__JY_15_004dbfd0);
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 6) {
    FUN_004b0613(&TStack_10,s_Boat_Type__505_004dbfc0);
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 7) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Skiff_004dbfac);
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 8) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Thistle_004dbf98);
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 9) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Lightning_004dbf80);
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x10) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Star_004dbf70);
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0xb) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Tornado_Catamaran_004dbf50);
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 10) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Non_Spinnaker_Cat_004dbf30);
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x11) {
    FUN_004b0613(&TStack_10,s_Boat_Type__A_Class_Cat_004dbf18);
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0xc) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Keelboat_004dbf04);
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0xd) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Sprit_Offshore_Racer_004dbee4);
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0xe) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Offshore_Racer_004dbec8);
    uStack_4 = 0x21;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x12) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Racer_Cruiser_004dbeac);
    uStack_4 = 0x22;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x13) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Cruising_Canvas_004dbe90);
    uStack_4 = 0x23;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0xf) {
    FUN_004b0613(&TStack_10,s_Boat_Type__America_s_Cup_004dbe74);
    uStack_4 = 0x24;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x14) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Model_Yacht_004dbe5c);
    uStack_4 = 0x25;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x15) {
    FUN_004b0613(&TStack_10,s_Boat_Type__25_ft_Sportboat_004dbe40);
    uStack_4 = 0x26;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x16) {
    FUN_004b0613(&TStack_10,s_Boat_Type__35_ft_Sportboat_004dbe24);
    uStack_4 = 0x27;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x17) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Offshore_Catamaran_004dbe04);
    uStack_4 = 0x28;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x18) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Ideal_18_Keelboat_004dbde4);
    uStack_4 = 0x29;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x19) {
    FUN_004b0613(&TStack_10,s_Boat_Type__Etchells_Keelboat_004dbdc4);
    uStack_4 = 0x2a;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x1a) {
    FUN_004b0613(&TStack_10,s_Boat__E_Scow_004dbdb0);
    uStack_4 = 0x2b;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da144 == 0x1b) {
    FUN_004b0613(&TStack_10,s_Boat__Flying_Scot_004dbd98);
    uStack_4 = 0x2c;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  param_1 = (int *)((DAT_004fe624 * 2) / 5 + 5);
  if (DAT_005363e4 == 0) {
    (*(code *)param_2)(original_dc,0x7f0000);
  }
  if (DAT_004da154 == 1) {
    FUN_004b0613(&TStack_10,s_Wind__light_004dbd8c);
    uStack_4 = 0x2d;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da154 == 2) {
    FUN_004b0613(&TStack_10,s_Wind__moderate_004dbd7c);
    uStack_4 = 0x2e;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da154 == 3) {
    FUN_004b0613(&TStack_10,s_Wind__strong_004dbd6c);
    uStack_4 = 0x2f;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  param_1 = (int *)((DAT_004fe624 * 3) / 5 + 5);
  if (DAT_005363e4 == 0) {
    (*(code *)param_2)(original_dc,0x7f0000);
  }
  if (DAT_004da194 == 2) {
    FUN_004b0613(&TStack_10,s_Fleet__2_004dbd60);
    uStack_4 = 0x30;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da194 == 5) {
    FUN_004b0613(&TStack_10,s_Fleet__5_004dbd54);
    uStack_4 = 0x31;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da194 == 10) {
    FUN_004b0613(&TStack_10,s_Fleet__10_004dbd48);
    uStack_4 = 0x32;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da194 == 0xf) {
    FUN_004b0613(&TStack_10,s_Fleet__15_004dbd3c);
    uStack_4 = 0x33;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da194 == 0x14) {
    FUN_004b0613(&TStack_10,s_Fleet__20_004dbd30);
    uStack_4 = 0x34;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da194 == 0x19) {
    FUN_004b0613(&TStack_10,s_Fleet__25_004dbd24);
    uStack_4 = 0x35;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da194 == 0x1e) {
    FUN_004b0613(&TStack_10,s_Fleet__30_004dbd18);
    uStack_4 = 0x36;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_005363e4 == 0) {
    (*(code *)param_2)(original_dc,0x7f7f00);
  }
  if (DAT_004da140 == 2) {
    if (900 < DAT_004fe624) {
      if (DAT_00536400 == -7) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Two_Players__1_much_faster_004dbcfc);
        uStack_4 = 0x37;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == -4) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Two_Players__1_significantly_fas_004dbcd8);
        uStack_4 = 0x38;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == -2) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Two_Players__1_slightly_faster_004dbcb8);
        uStack_4 = 0x39;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 0) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Two_Players__equal_speed_potenti_004dbc94);
        uStack_4 = 0x3a;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 7) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Two_Players__2_much_faster_004dbc78);
        uStack_4 = 0x3b;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 4) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Two_Players__2_significantly_fas_004dbc54);
        uStack_4 = 0x3c;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 2) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Two_Players__2_slightly_faster_004dbc34);
        uStack_4 = 0x3d;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
    }
    if ((DAT_004da140 == 2) && (DAT_004fe624 < 0x385)) {
      if (DAT_00536400 == -7) {
        FUN_004b0613((Tact2010CString *)&param_1,s_1_much_faster_004dbc24);
        uStack_4 = 0x3e;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == -4) {
        FUN_004b0613((Tact2010CString *)&param_1,s_1_significantly_faster_004dbc0c);
        uStack_4 = 0x3f;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == -2) {
        FUN_004b0613((Tact2010CString *)&param_1,s_1_slightly_faster_004dbbf8);
        uStack_4 = 0x40;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 0) {
        FUN_004b0613((Tact2010CString *)&param_1,s_equal_speed_potential_004dbbe0);
        uStack_4 = 0x41;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 7) {
        FUN_004b0613((Tact2010CString *)&param_1,s_2_much_faster_004dbbd0);
        uStack_4 = 0x42;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 4) {
        FUN_004b0613((Tact2010CString *)&param_1,s_2_significantly_faster_004dbbb8);
        uStack_4 = 0x43;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_00536400 == 2) {
        FUN_004b0613((Tact2010CString *)&param_1,s_2_slightly_faster_004dbba4);
        uStack_4 = 0x44;
        (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
                  (char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
    }
  }
  if (DAT_004da140 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_One_Player_004dbb98);
    uStack_4 = 0x45;
    (*pcVar1)(original_dc,(int)(DAT_004fe624 * 6 + (DAT_004fe624 * 6 >> 0x1f & 7U)) >> 3,iVar3,
              (char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_2)(original_dc,0x7f0000);
  }
  if (DAT_004da188 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Course__Windward___Leeward_004dbb7c);
    uStack_4 = 0x46;
    (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da188 == 2) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Course__Windward___Leeward_Twice_004dbb58);
    uStack_4 = 0x47;
    (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da188 == 3) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Course__Triangle_004dbb44);
    uStack_4 = 0x48;
    (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da188 == 4) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Course__Triangle_Twice_004dbb2c);
    uStack_4 = 0x49;
    (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da188 == 5) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Course__Gold_Cup_004dbb18);
    uStack_4 = 0x4a;
    (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da188 == 6) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Course__Downwind_Finish_W___L_004dbaf8);
    uStack_4 = 0x4b;
    (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da188 == 7) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Course__Downwind_Finish_Twice_Ar_004dbacc);
    uStack_4 = 0x4c;
    (*pcVar1)(original_dc,5,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  param_1 = (int *)((DAT_004fe624 * 2) / 5 + 5);
  if (DAT_005363e4 == 0) {
    (*(code *)param_2)(original_dc,0x7f00);
  }
  if (((DAT_005230dc == 1) && (DAT_004f69b8 == 0)) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Shore_to_North_004dbabc);
    uStack_4 = 0x4d;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (((DAT_005230dc == 2) && (DAT_004f69b8 == 0)) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Shore_to_East_004dbaac);
    uStack_4 = 0x4e;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (((DAT_005230dc == 3) && (DAT_004f69b8 == 0)) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Shore_to_South_004dba9c);
    uStack_4 = 0x4f;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((((DAT_005230dc == 4) && (DAT_004f69b8 == 0)) && (DAT_004da1f8 == 0)) && (DAT_004f4510 == 0))
  {
    FUN_004b0613(&TStack_10,s_Shore_to_West_004dba8c);
    uStack_4 = 0x50;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004f69b8 == 1) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Round_Lake_004dba80);
    uStack_4 = 0x51;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004da19c == 6) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Sound_004dba78);
    uStack_4 = 0x52;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004da19c == 7) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Round_the_Island_004dba64);
    uStack_4 = 0x53;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da19c == 8) {
    if ((DAT_004f8b78 == 0) && (DAT_004da1f8 == 0)) {
      FUN_004b0613(&TStack_10,s_Distance_Race___Along_Shore_004dba48);
      uStack_4 = 0x54;
      (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_10);
    }
    if (((DAT_004da19c == 8) && (DAT_004f8b78 == 1)) && (DAT_004da1f8 == 0)) {
      FUN_004b0613(&TStack_10,s_Distance_Race___Around_Island_004dba28);
      uStack_4 = 0x55;
      (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_10);
    }
  }
  if ((DAT_004da19c == 9) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_River_Mouth_North_004dba14);
    uStack_4 = 0x56;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004da19c == 10) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_River_Mouth_South_004dba00);
    uStack_4 = 0x57;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004f4510 == 1) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,&DAT_004db9fc);
    uStack_4 = 0x58;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004f69b8 == 2) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Banana_Lake_004db9f0);
    uStack_4 = 0x59;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004f69b8 == 3) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Five_Finger_Lake_004db9dc);
    uStack_4 = 0x5a;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if ((DAT_004f69b8 == 4) && (DAT_004da1f8 == 0)) {
    FUN_004b0613(&TStack_10,s_Branching_River_004db9cc);
    uStack_4 = 0x5b;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 1) {
    FUN_004b0613(&TStack_10,s_Northeast_Harbor__ME_004db9b4);
    uStack_4 = 0x5c;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 2) {
    FUN_004b0613(&TStack_10,s_Marblehead__MA_004db9a4);
    uStack_4 = 0x5d;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 3) {
    FUN_004b0613(&TStack_10,s_Newport__RI_004db998);
    uStack_4 = 0x5e;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 4) {
    FUN_004b0613(&TStack_10,s_West_of_Block_Island__RI_004db97c);
    uStack_4 = 0x5f;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 5) {
    FUN_004b0613(&TStack_10,s_Around_Block_Island__RI_004db964);
    uStack_4 = 0x60;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 6) {
    FUN_004b0613(&TStack_10,s_Annapolis__MD_004db954);
    uStack_4 = 0x61;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 7) {
    FUN_004b0613(&TStack_10,s_Essex__CT_004db948);
    uStack_4 = 0x62;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 10) {
    FUN_004b0613(&TStack_10,s_Kingston__ON_004db938);
    uStack_4 = 99;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 9) {
    FUN_004b0613(&TStack_10,s_Charleston__SC_004db928);
    uStack_4 = 100;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0xb) {
    FUN_004b0613(&TStack_10,s_Biscayne_Bay__FL_004db914);
    uStack_4 = 0x65;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0xc) {
    FUN_004b0613(&TStack_10,s_Chicago__IL_004db908);
    uStack_4 = 0x66;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0x67) {
    FUN_004b0613(&TStack_10,s_Thurmond_Lake__GA___SC_004db8f0);
    uStack_4 = 0x67;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0x69) {
    FUN_004b0613(&TStack_10,s_Key_West__FL_004db8e0);
    uStack_4 = 0x68;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0x68) {
    FUN_004b0613(&TStack_10,s_St_Petersburg__FL_004db8cc);
    uStack_4 = 0x69;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 100) {
    FUN_004b0613(&TStack_10,s_Groton__CT_004db8c0);
    uStack_4 = 0x6a;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0x65) {
    FUN_004b0613(&TStack_10,s_Larchmont__NY_004db8b0);
    uStack_4 = 0x6b;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0x66) {
    FUN_004b0613(&TStack_10,s_Edgartown__MA_004db8a0);
    uStack_4 = 0x6c;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 0x6a) {
    FUN_004b0613(&TStack_10,s_Nassau__Bamahas_004db890);
    uStack_4 = 0x6d;
    (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
  }
  if (DAT_004da1f8 == 999) {
    if (DAT_005363e4 == 0) {
      (*(code *)param_2)(original_dc,0xff00ff);
    }
    FUN_004b0613((Tact2010CString *)&param_2,s_Personal_Race_Area_004db87c);
    uStack_4 = 0x6e;
    (*pcVar1)(original_dc,(int)param_1,iVar3,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  FUN_004b4a1f(original_dc,2);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


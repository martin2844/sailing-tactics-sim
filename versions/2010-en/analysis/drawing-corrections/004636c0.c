
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004636c0(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *original_dc;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  int local_18;
  int local_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004ccc90;
  pcStack_8 = FUN_004c5830;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
    local_18 = 0x10;
    iVar3 = 0x16;
    local_1c = 3;
    local_14 = 5;
  }
  else {
    local_18 = 0x14;
    iVar3 = 0x1b;
    local_1c = 10;
    local_14 = 10;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___BIBLIOGRAPHY___004ec168);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_1c,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_Racing_Rules__004ec158);
  uStack_4 = 1;
  (*pcVar1)(original_dc,local_1c,iVar3 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar3 + 2 + iVar3;
  FUN_004b0613(&TStack_10,s_1__U_S__Sailing___The_Racing_Rul_004ec0f8);
  param_1 = (int *)(local_14 + local_1c);
  uStack_4 = 2;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + local_18;
  FUN_004b0613(&TStack_10,s_15_Maritime_Dr__P_O__Box_1260__P_004ec0c0);
  uStack_4 = 3;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_2__Dave_Perry___Understanding_th_004ec080);
  uStack_4 = 4;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + local_18;
  FUN_004b0613(&TStack_10,s_U_S__Sailing_Association__Portsm_004ec054);
  uStack_4 = 5;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_Wind_Prediction__004ec040);
  uStack_4 = 6;
  (*pcVar1)(original_dc,local_1c,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_3__David_Houghton___Wind_Strateg_004ebff4);
  uStack_4 = 7;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_4__Alan_Watts___Wind_and_Sailing_004ebfa8);
  uStack_4 = 8;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_5__Stuart_Walker___Wind_and_Stra_004ebf58);
  uStack_4 = 9;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_6__Frank_Bethwaite___High_Perfor_004ebefc);
  uStack_4 = 10;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_Tactics___Strategy__004ebee4);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,local_1c,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_7__Stuart_Walker___Positioning__T_004ebe7c);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_8__Stuart_Walker___The_Tactics_o_004ebe20);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_9__David_Dellenbaugh___Speed_Sma_004ebdc0);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_10__Dick_Tillman___Laser_Sailing_004ebd64);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_11__Dave_Perry___Winning_in_One_D_004ebd08);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_12__Rick_White___Mary_Wells___Ca_004ebca8);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  FUN_004b0613(&TStack_10,s_13__Jobson__Whidden__and_Loory____004ebc4c);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,(int)param_1,iVar4 + iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_spacebar_or_click_to_exit_b_004ebc1c);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,local_1c,DAT_004faf7c - local_18,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


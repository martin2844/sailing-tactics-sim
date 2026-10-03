
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044d140(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *this;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  int local_18;
  int local_14;
  LPCSTR pCStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_004853e8;
  pcStack_8 = FUN_004805e8;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
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
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___BIBLIOGRAPHY___0049f134);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,local_1c,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_Racing_Rules__0049f124);
  uStack_4 = 1;
  (*pcVar1)(this,local_1c,iVar3 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar3 + 2 + iVar3;
  FUN_0046bf33(&pCStack_10,s_1__U_S__Sailing___The_Racing_Rul_0049f0c4);
  param_1 = (int *)(local_14 + local_1c);
  uStack_4 = 2;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + local_18;
  FUN_0046bf33(&pCStack_10,s_15_Maritime_Dr__P_O__Box_1260__P_0049f08c);
  uStack_4 = 3;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_2__Dave_Perry___Understanding_th_0049f040);
  uStack_4 = 4;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + local_18;
  FUN_0046bf33(&pCStack_10,s_U_S__Sailing_Association__Portsm_0049f010);
  uStack_4 = 5;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&pCStack_10,s_Wind_Prediction__0049effc);
  uStack_4 = 6;
  (*pcVar1)(this,local_1c,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_3__Alan_Watts___Wind_and_Sailing_0049efb0);
  uStack_4 = 7;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_4__Stuart_Walker___Wind_and_Stra_0049ef60);
  uStack_4 = 8;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_5__Frank_Bethwaite___High_Perfor_0049ef04);
  uStack_4 = 9;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&pCStack_10,s_Tactics___Strategy__0049eeec);
  uStack_4 = 10;
  (*pcVar1)(this,local_1c,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_6__Stuart_Walker___Positioning__T_0049ee84);
  uStack_4 = 0xb;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_7__Stuart_Walker___The_Tactics_o_0049ee28);
  uStack_4 = 0xc;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_8__David_Dellenbaugh___Speed_Sma_0049edc8);
  uStack_4 = 0xd;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_9__Dick_Tillman___Laser_Sailing_f_0049ed6c);
  uStack_4 = 0xe;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_10__Dave_Perry___Winning_in_One_D_0049ed10);
  uStack_4 = 0xf;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_11__Rick_White___Mary_Wells___Ca_0049ecb0);
  uStack_4 = 0x10;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  FUN_0046bf33(&pCStack_10,s_12__Jobson__Whidden__and_Loory____0049ec54);
  uStack_4 = 0x11;
  (*pcVar1)(this,(int)param_1,iVar4 + iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
    if (DAT_004ac92c == 0) {
      (**(code **)(*this + 0x38))(this,0xff);
    }
  }
  FUN_0046bf33(&param_1,s_Press_spacebar_or_click_to_exit_b_0049ec24);
  uStack_4 = 0x12;
  (*pcVar1)(this,local_1c,DAT_004a600c - local_18,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


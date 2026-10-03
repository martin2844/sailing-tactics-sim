
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043a5d0(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  undefined4 uVar3;
  CDC *this;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f120;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    local_14 = 0x10;
    iVar4 = 0x16;
    local_10 = 5;
  }
  else {
    iVar4 = 0x1b;
    local_14 = 0x14;
    local_10 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f);
  }
  FUN_0046bf33(&param_1,s_Miscellaneous_rules__0049890c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,5,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Even_a_right_of_way_boat_must_av_004988ac);
  uStack_4 = 1;
  (*pcVar1)(this,5,iVar4 + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar4 + 2 + iVar4;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_It_a_boat_hits_a_mark__she_may_e_0049884c);
  uStack_4 = 2;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + local_14;
  FUN_0046bf33(&param_1,s_of_other_boats_and_making_a_360_d_004987f4);
  uStack_4 = 3;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar4;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_If_there_is_reasonable_doubt_tha_004987a0);
  uStack_4 = 4;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_she_did_not__Rule_18_2__c____00498780);
  uStack_4 = 5;
  (*pcVar1)(this,5,local_14 + iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,local_10,local_14);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043a845;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043a845;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043a845:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  uVar3 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  DAT_004aa734 = 1;
  DAT_004a6ecc = 0xf;
  _DAT_004a77ec = 2;
  DAT_004a7064 = 0x3c;
  DAT_004a633c = 0xf;
  DAT_004ac01c = 0x13b;
  DAT_004a7bcc = 0x2d;
  FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),1,1,DAT_004a72d0,0);
  _DAT_004a6ed0 = 0xf;
  DAT_004a6340 = 0xf;
  DAT_004ac020 = 0x2d;
  DAT_004a7bd0 = 0x2d;
  DAT_004aa738 = 0xffffffff;
  _DAT_004a77f0 = 2;
  DAT_004a7068 = 0x3c;
  FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f10),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),2,1,DAT_004a72d0,0);
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = uVar3;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


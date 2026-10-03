
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043a5d0(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  undefined4 uVar3;
  CDC *pCVar4;
  int unaff_EBP;
  int iVar5;
  int iVar6;
  int *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iVar7;
  int iVar8;
  CDC *pCStack_5c;
  int iStack_4c;
  int iStack_3c;
  CDC *pCStack_2c;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar4 = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f120;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar5 = 0x16;
  }
  else {
    iVar5 = 0x1b;
  }
  if (DAT_004ac92c == 0) {
    pCStack_2c = (CDC *)0x43a64d;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_2c = (CDC *)0x43a65b;
  FUN_0046bf33(&param_1,s_Miscellaneous_rules__0049890c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)pCVar4 + 100);
  pCStack_2c = param_1;
  (*pcVar1)();
  FUN_0046bec5(&iStack_c);
  if (DAT_004ac92c == 0) {
    iStack_3c = 0x43a6a2;
    (**(code **)(*(int *)pCVar4 + 0x38))();
  }
  iStack_3c = 0x43a6b0;
  FUN_0046bf33(&iStack_c,s_Even_a_right_of_way_boat_must_av_004988ac);
  iStack_3c = iStack_c;
  (*pcVar1)();
  FUN_0046bec5((int *)&stack0xffffffe4);
  if (DAT_004ac92c == 0) {
    iStack_4c = 0x43a6f0;
    (**(code **)(*(int *)pCVar4 + 0x38))();
  }
  iStack_4c = 0x43a6fe;
  FUN_0046bf33(&stack0xffffffe4,s_It_a_boat_hits_a_mark__she_may_e_0049884c);
  iStack_4c = unaff_EBP;
  (*pcVar1)();
  FUN_0046bec5((int *)&pCStack_2c);
  iVar6 = iVar5 * 2 + 7;
  pCStack_5c = (CDC *)0x43a73b;
  FUN_0046bf33(&pCStack_2c,s_of_other_boats_and_making_a_360_d_004987f4);
  pCStack_5c = pCStack_2c;
  iVar8 = 5;
  (*pcVar1)(5,iVar6);
  FUN_0046bec5(&iStack_3c);
  iVar6 = iVar6 + iVar5;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar4 + 0x38))(0x7f0000);
  }
  FUN_0046bf33(&iStack_3c,s_If_there_is_reasonable_doubt_tha_004987a0);
  iVar5 = iVar6;
  iVar7 = iStack_3c;
  (*pcVar1)(5,iVar6,iStack_3c,*(undefined4 *)(iStack_3c + -8));
  FUN_0046bec5(&iStack_4c);
  FUN_0046bf33(&iStack_4c,s_she_did_not__Rule_18_2__c____00498780);
  (*pcVar1)(5,iVar8 + iVar6,iStack_4c,*(undefined4 *)(iStack_4c + -8));
  FUN_0046bec5((int *)&pCStack_5c);
  FUN_0044d830((int *)pCVar4,iVar5,iVar8);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043a845;
    hdc = *(HDC *)(pCVar4 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043a845;
    hdc = *(HDC *)(pCVar4 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043a845:
  Rectangle(*(HDC *)(pCVar4 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
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
  FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),1,1,DAT_004a72d0,0);
  _DAT_004a6ed0 = 0xf;
  DAT_004a6340 = 0xf;
  DAT_004ac020 = 0x2d;
  DAT_004a7bd0 = 0x2d;
  DAT_004aa738 = 0xffffffff;
  _DAT_004a77f0 = 2;
  DAT_004a7068 = 0x3c;
  FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484f10),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),2,1,DAT_004a72d0,0);
  FUN_0042f0d0(pCVar4,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = uVar3;
  *unaff_FS_OFFSET = iVar7;
  return;
}


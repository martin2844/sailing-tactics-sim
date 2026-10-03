
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00452660(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  int *original_dc;
  uint uVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_28;
  int local_24;
  int local_20 [2];
  Tact2010CString aTStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c45e8;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar4;
  DAT_005362d4 = 0;
  if (DAT_004fe624 < 700) {
    uVar5 = 0x10;
    local_20[0] = 0x16;
    local_24 = 5;
    local_28 = 10;
  }
  else {
    uVar5 = 0x14;
    local_20[0] = 0x1b;
    local_24 = 0x14;
    local_28 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___BASIC_CONCEPTS___CONSEQUENCES_O_004e67e0);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_24,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar6 = local_20[0] + 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Laylines__A_closehauled_boat_on_a_004e677c);
  uStack_4 = 1;
  (*pcVar1)(original_dc,local_24,iVar6,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar6 = iVar6 + uVar5;
  FUN_004b0613(aTStack_18,s_laylines_are_beating__A_boat_out_004e6718);
  param_1 = (int *)(local_28 + local_24);
  uStack_4 = 2;
  (*pcVar1)(original_dc,(int)param_1,iVar6,aTStack_18[0].data,*(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  iVar6 = iVar6 + local_20[0];
  FUN_004b0613(aTStack_18,s_Equal_position_Line__This_is_a_l_004e66bc);
  uStack_4 = 3;
  (*pcVar1)(original_dc,local_24,iVar6,aTStack_18[0].data,*(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  iVar6 = iVar6 + uVar5;
  FUN_004b0613(aTStack_18,s_line_are_equally_upwind__Provide_004e6660);
  uStack_4 = 4;
  (*pcVar1)(original_dc,(int)param_1,iVar6,aTStack_18[0].data,*(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  iVar6 = iVar6 + uVar5;
  FUN_004b0613(aTStack_18,s_If_boat_A_tacks__they_will_conve_004e6618);
  uStack_4 = 5;
  (*pcVar1)(original_dc,(int)param_1,iVar6,aTStack_18[0].data,*(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0);
  }
  iVar6 = iVar6 + uVar5;
  FUN_004b0613(aTStack_18,s_If_the_wind_shifts__the_equal_po_004e65c0);
  uStack_4 = 6;
  (*pcVar1)(original_dc,(int)param_1,iVar6,aTStack_18[0].data,*(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  iVar6 = iVar6 + uVar5;
  FUN_004b0613(aTStack_18,s_The_boats_are_no_longer_even__Th_004e6560);
  uStack_4 = 7;
  (*pcVar1)(original_dc,(int)param_1,iVar6,aTStack_18[0].data,*(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  FUN_004b0613(aTStack_18,s_distance_between_the_boats__Doub_004e6508);
  uStack_4 = 8;
  (*pcVar1)(original_dc,(int)param_1,uVar5 + iVar6,aTStack_18[0].data,
            *(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  FUN_00463df0(original_dc,local_24,uVar5);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_004529b0;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_004529b0;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_004529b0:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 2;
  FUN_00463c90(original_dc,uVar5);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  local_20[0] = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
  iVar6 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc778);
  if (DAT_005362ec != (HGDIOBJ)0x0) {
    SelectObject((HDC)original_dc[1],DAT_005362ec);
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20[0],iVar6);
  iVar2 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc618);
  iVar3 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
  CDC::LineTo(original_dc,iVar2,iVar3);
  param_1 = (int *)(DAT_004fe624 / 0x32);
  FUN_004b0613(aTStack_18,"LayLine");
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar2 - (int)param_1,iVar3 + uVar5 * -2,aTStack_18[0].data,
            *(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  FUN_004b4d9d(original_dc,(int *)aTStack_18,local_20[0],iVar6);
  iVar2 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
  iVar3 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
  CDC::LineTo(original_dc,iVar2,iVar3);
  param_1 = (int *)(DAT_004fe624 / 0x18);
  FUN_004b0613(aTStack_18,"LayLine");
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2 - (int)param_1,iVar3 + uVar5 * -2,aTStack_18[0].data,
            *(int *)(aTStack_18[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_18);
  aTStack_18[0].data = *(char **)(*original_dc + 0x38);
  (*(code *)aTStack_18[0].data)(original_dc,0);
  FUN_0043faa0(original_dc,local_20[0],iVar6,4,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004dd748);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,DAT_004fe624 / 100 + local_20[0],iVar6 - uVar5 / 2,(char *)param_1,
            param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_004fb9b4 < 2) {
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    iVar6 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    FUN_004b4d9d(original_dc,local_20,0,iVar6);
    CDC::LineTo(original_dc,DAT_004fe624,iVar6);
    (*(code *)aTStack_18[0].data)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)aTStack_18[0].data)(original_dc,0);
  }
  if (DAT_004fb9b4 == 0) {
    DAT_005362d4 = 0;
    iVar6 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    param_1 = (int *)(DAT_004fe624 / 10);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar6,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,iVar6 - (int)param_1,iVar2 + uVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    iVar6 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    DAT_00522ff8 = 1;
    _DAT_004fe820 = 2;
    param_1 = (int *)(DAT_004fe624 / 0xe);
    DAT_004fdff0 = 0x3c;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar6,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,iVar6 - (int)param_1,iVar2 + uVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    iVar6 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc6c0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    _DAT_00522ffc = 1;
    param_1 = (int *)(DAT_004fe624 / 100);
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 10;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x145;
    _DAT_004fecd4 = 0x37;
    FUN_00417aa0(original_dc,iVar6,iVar2,3,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat C:");
    local_20[0] = iVar6 + (int)param_1;
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,local_20[0],iVar2 + uVar5 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b0613((Tact2010CString *)&param_1,"Overstanding");
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,local_20[0],iVar2 - uVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 1) {
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc600),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x2d;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc600),2,1,DAT_004fe2a8,0);
  }
  if (DAT_004fb9b4 == 2) {
    _DAT_004fe81c = 2;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc820),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x2d;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc778),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc820),2,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_004f71c4 = uStack_10;
  DAT_00536458 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


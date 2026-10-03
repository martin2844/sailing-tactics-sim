
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00450590(int *param_1)

{
  code *pcVar1;
  double dVar2;
  undefined4 uVar3;
  int *original_dc;
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
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4300;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
    local_14 = 0x10;
    iVar4 = 0x16;
    local_10 = 5;
  }
  else {
    iVar4 = 0x1b;
    local_14 = 0x14;
    local_10 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Miscellaneous_rules__004e55c0);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,5,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Even_a_right_of_way_boat_must_av_004e5560);
  uStack_4 = 1;
  (*pcVar1)(original_dc,5,iVar4 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar4 + 2 + iVar4;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "If a boat touches a mark, she may promptly sail clear of other boats and make a 360-degree turn including one tack and one jibe"
              );
  uStack_4 = 2;
  (*pcVar1)(original_dc,5,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_to_exonerate_herself_for_the_mar_004e54ac);
  uStack_4 = 3;
  (*pcVar1)(original_dc,5,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = iVar5 + iVar4;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_If_there_is_reasonable_doubt_tha_004e5458);
  uStack_4 = 4;
  (*pcVar1)(original_dc,5,iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,"assume it did not (Rule 18.2(d)).");
  uStack_4 = 5;
  (*pcVar1)(original_dc,5,local_14 + iVar5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_00463df0(original_dc,local_10,local_14);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00450805;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00450805;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00450805:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  uVar3 = DAT_004f71c4;
  DAT_00536458 = 2;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  DAT_00522ff4 = 1;
  DAT_004fc2c4 = 0xf;
  _DAT_004fe81c = 2;
  DAT_004fdfec = 0x3c;
  DAT_004fb384 = 0xf;
  DAT_00535744 = 0x13b;
  DAT_004feccc = 0x2d;
  FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc668),
               (int)(longlong)(_DAT_005230b0 * _DAT_004cc508),1,1,DAT_004fe2a8,0);
  _DAT_004fc2c8 = 0xf;
  DAT_004fb388 = 0xf;
  DAT_00535748 = 0x2d;
  DAT_004fecd0 = 0x2d;
  DAT_00522ff8 = 0xffffffff;
  _DAT_004fe820 = 2;
  DAT_004fdff0 = 0x3c;
  FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc770),
               (int)(longlong)(_DAT_005230b0 * _DAT_004cc508),2,1,DAT_004fe2a8,0);
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_005350dc = 0;
  DAT_004f71c4 = uVar3;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


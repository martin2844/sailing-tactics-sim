
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044d0c0(int *param_1)

{
  int iVar1;
  code *pcVar2;
  double dVar3;
  undefined4 uVar4;
  int *original_dc;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_1c;
  int local_18;
  Tact2010CString local_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4050;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar3;
  if (DAT_004fe624 < 700) {
    iVar5 = 0x10;
    local_18 = 0x16;
    local_1c = 0x10;
    local_14[0].data = &DAT_00000005;
  }
  else {
    local_18 = 0x1b;
    local_1c = 0x14;
    local_14[0].data = (char *)0x14;
    iVar5 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "Same tack, not overlapped: The boat clear astern must keep clear (Rule 12).");
  iVar1 = *original_dc;
  uStack_4 = 0;
  pcVar2 = *(code **)(iVar1 + 100);
  (*pcVar2)(original_dc,0x14,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar1 + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_A_does_not_overlap_because_her_b_004e4390);
  uStack_4 = 1;
  (*pcVar2)(original_dc,0xe,local_18 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_Boat_A_is_clear_astern_and_must_k_004e4364);
  uStack_4 = 2;
  (*pcVar2)(original_dc,0xe,iVar5 + local_18 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_00463df0(original_dc,(int)local_14[0].data,iVar5);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0044d278;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0044d278;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0044d278:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  uVar4 = DAT_004f71c4;
  DAT_00536458 = 2;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,iVar5);
  if ((2 < DAT_004da190) && (DAT_004da190 != 9)) {
    DAT_005350dc = 1;
  }
  if (DAT_004fb9b4 == 0) {
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc8a8);
    iVar1 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    param_1 = (int *)(DAT_004fe624 / 0xe);
    DAT_004fc2c4 = 0xf;
    DAT_004fb384 = 0xf;
    DAT_00522ff4 = 0xffffffff;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    DAT_00535744 = 0x5a;
    DAT_004feccc = 0x5a;
    FUN_00417aa0(original_dc,iVar5,iVar1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(local_14,s_Boat_A__Clear_Astern_004e434c);
    uStack_4 = 3;
    (*pcVar2)(original_dc,iVar5 - (int)param_1,iVar1 + local_1c,local_14[0].data,
              *(int *)(local_14[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_14);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar1 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    DAT_00522ff8 = 0xffffffff;
    param_1 = (int *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_00535748 = 0x5a;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,iVar5,iVar1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(local_14,s_Boat_B__Clear_Ahead_004e4338);
    uStack_4 = 4;
    (*pcVar2)(original_dc,(int)param_1 + iVar5,iVar1 + local_1c,local_14[0].data,
              *(int *)(local_14[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_14);
    (**(code **)(*original_dc + 0x2c))(original_dc,7);
    FUN_004b4d9d(original_dc,(int *)local_14,DAT_005228e0,
                 DAT_005229e0 - ((int)(DAT_004fe2a8 + (DAT_004fe2a8 >> 0x1f & 3U)) >> 2));
    CDC::LineTo(original_dc,DAT_005228e0,DAT_004fe2a8 / 10 + DAT_005229e0);
    FUN_004b0613((Tact2010CString *)&param_1,s_Overlap_Line_004e4064);
    uStack_4 = 5;
    (*pcVar2)(original_dc,DAT_005228e0,DAT_004fe2a8 / 10 + DAT_005229e0,(char *)param_1,param_1[-2])
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  else {
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x5a;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7d0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),2,1,DAT_004fe2a8,0);
    DAT_00522ff4 = 0xffffffff;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x6e;
    DAT_004feccc = 0x6e;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc7e0),1,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_005350dc = 0;
  DAT_004f71c4 = uVar4;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


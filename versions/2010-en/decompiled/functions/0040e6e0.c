
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040e6e0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  code *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  int iStack0000001c;
  Tact2010CString TStack_2c;
  Tact2010CString TStack_28;
  int local_24;
  int iStack_20;
  int iStack_1c;
  int local_18;
  int local_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2278;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_004b4a1f(param_1,1);
  iStack0000001c = DAT_004fe2a8 / 0x1f;
  iVar5 = iStack0000001c + param_3;
  iVar7 = 2 - (int)(longlong)((double)DAT_004fe624 * _DAT_004cc590);
  local_14[0] = param_4 - iVar7;
  local_18 = local_14[0] + -2;
  local_24 = iVar7;
  FUN_00463f50(param_1,local_18,param_3,param_4,iVar5,1,0);
  iVar8 = *param_1;
  (**(code **)(iVar8 + 0x34))(param_1,0x7f7f7f);
  pcVar1 = *(code **)(iVar8 + 0x38);
  (*pcVar1)(param_1,0);
  pcVar2 = *(code **)(iVar8 + 0x2c);
  (*pcVar2)(param_1,7);
  TStack_2c.data = (char *)0x1;
  pcVar3 = (char *)(iStack0000001c / 2);
  TStack_28.data = pcVar3;
  do {
    if (TStack_2c.data == (char *)0x1) {
      iVar7 = param_4 * 4 + iVar7 * -3;
    }
    else {
      iVar7 = param_4 * 4 - iVar7;
    }
    iVar8 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
    if (DAT_00512d68 == 1) {
      iVar7 = (int)(iStack0000001c + (iStack0000001c >> 0x1f & 3U)) >> 2;
    }
    else {
      iVar7 = iStack0000001c / 3;
    }
    iVar4 = iVar7 * 3 + (iVar7 * 3 >> 0x1f & 3U);
    iStack_20 = iVar4 >> 2;
    iStack_1c = iStack_20 - (iVar4 >> 0x1f) >> 1;
    iVar4 = iVar8;
    if ((0 < DAT_004f49a8) && (DAT_00512d68 == 0)) {
      iVar4 = iVar8 - iStack0000001c / 3;
    }
    if ((DAT_004f49a8 < 0) && (DAT_00512d68 == 0)) {
      iVar4 = iVar4 + iStack0000001c / 3;
    }
    (*pcVar2)(param_1,0);
    pcVar6 = Ellipse_exref;
    if (DAT_00512d68 == 1) {
      Ellipse((HDC)param_1[1],iVar8 + iVar7 * -4,(int)(pcVar3 + (param_3 - iVar7)),iVar8 + iVar7 * 4
              ,(int)(pcVar3 + iVar7 + param_3));
    }
    else {
      Ellipse((HDC)param_1[1],iVar8 + iVar7 * -2,(int)(pcVar3 + (param_3 - iVar7)),iVar8 + iVar7 * 2
              ,(int)(pcVar3 + iVar7 + param_3));
      pcVar6 = Ellipse_exref;
    }
    if (DAT_005363e4 == 0) {
      if (DAT_004f4a5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f4a5c);
      }
    }
    else {
      (*pcVar2)(param_1,4);
    }
    (*pcVar6)((HDC)param_1[1],iVar4 - iStack_20,(int)(pcVar3 + (param_3 - iStack_20)),
              iStack_20 + iVar4,(int)(pcVar3 + iStack_20 + param_3));
    (*pcVar2)(param_1,4);
    (*pcVar6)((HDC)param_1[1],iVar4 - iStack_1c,(int)(pcVar3 + (param_3 - iStack_1c)),
              iStack_1c + iVar4,(int)(pcVar3 + iStack_1c + param_3));
    TStack_2c.data = TStack_2c.data + 1;
    iVar7 = local_24;
  } while ((int)TStack_2c.data < 3);
  if ((DAT_004f49a8 == 0) && (DAT_00512d68 == 0)) {
    iVar8 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar8 = 0xffff00;
  }
  else {
    iVar8 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar8);
  iVar7 = local_18;
  iVar8 = iVar5 + iStack0000001c;
  FUN_00463f50(param_1,local_18,iVar5,param_4,iVar8,1,0);
  FUN_004b0613(&TStack_2c,s_ahead_004daef0);
  iVar4 = local_14[0];
  uStack_4 = 0;
  pcVar6 = *(code **)(*param_1 + 100);
  (*pcVar6)(param_1,local_14[0],iVar5,TStack_2c.data,*(int *)(TStack_2c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_2c);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar5);
  CDC::LineTo(param_1,param_4 + -2,iVar5);
  FUN_00463f50(param_1,iVar7,iVar5,param_4,iVar8,0,0);
  if (DAT_004f7084 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  FUN_00444270(param_1,(param_4 - DAT_004fe624 / 0x82) + -2,iVar5 + 2,0xb4,10);
  (*pcVar2)(param_1,7);
  if (((DAT_004f49a8 < 1) || (DAT_004f49a8 == 0xb4)) || (DAT_00512d68 != 0)) {
    if (DAT_005363e4 == 0) {
      iVar5 = 0xffff00;
    }
    else {
      iVar5 = 0xffffff;
    }
  }
  else {
    iVar5 = 0;
  }
  (*pcVar1)(param_1,iVar5);
  iVar5 = iStack0000001c + iVar8;
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,1,0);
  FUN_004b0613(&TStack_2c,&DAT_004dae9c);
  uStack_4 = 1;
  (*pcVar6)(param_1,iVar4,iVar8,TStack_2c.data,*(int *)(TStack_2c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_2c);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar8);
  CDC::LineTo(param_1,param_4 + -2,iVar8);
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,0,0);
  if (DAT_004f7084 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  FUN_00444270(param_1,(param_4 - DAT_004fe624 / 0x32) + -2,(int)(TStack_28.data + iVar8),0x5a,10);
  (*pcVar2)(param_1,7);
  if ((DAT_004f49a8 < 0) && (DAT_00512d68 == 0)) {
    iVar8 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar8 = 0xffff00;
  }
  else {
    iVar8 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar8);
  iVar8 = iStack0000001c + iVar5;
  FUN_00463f50(param_1,iVar7,iVar5,param_4,iVar8,1,0);
  FUN_004b0613(&TStack_2c,s_right_004dae44);
  uStack_4 = 2;
  (*pcVar6)(param_1,iVar4,iVar5,TStack_2c.data,*(int *)(TStack_2c.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_2c);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar5);
  CDC::LineTo(param_1,param_4 + -2,iVar5);
  FUN_00463f50(param_1,iVar7,iVar5,param_4,iVar8,0,0);
  if (DAT_004f7084 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  FUN_00444270(param_1,param_4 + -3,(int)(TStack_28.data + iVar5),0x10e,10);
  (*pcVar2)(param_1,7);
  if ((DAT_004f49a8 == 0xb4) && (DAT_00512d68 == 0)) {
    iVar5 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar5 = 0xffff00;
  }
  else {
    iVar5 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar5);
  iVar5 = iVar8 + iStack0000001c;
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,1,0);
  FUN_004b0613(&TStack_28,s_astern_004dadf4);
  uStack_4 = 3;
  (*pcVar6)(param_1,iVar4,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar8);
  CDC::LineTo(param_1,param_4 + -2,iVar8);
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,0,0);
  if (DAT_004f7084 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  FUN_00444270(param_1,(param_4 - DAT_004fe624 / 0x82) + -2,iVar5 + -1,0,10);
  (*pcVar2)(param_1,7);
  if (DAT_00512d68 == 1) {
    iVar8 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar8 = 0xffff;
  }
  else {
    iVar8 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar8);
  iVar8 = iVar5 + iStack0000001c;
  FUN_00463f50(param_1,iVar7,iVar5,param_4,iVar8,1,0);
  FUN_004b0613(&TStack_28,s_upwn_5_004db028);
  uStack_4 = 4;
  (*pcVar6)(param_1,iVar4,iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar5);
  CDC::LineTo(param_1,param_4 + -2,iVar5);
  FUN_00463f50(param_1,iVar7,iVar5,param_4,iVar8,0,0);
  if (DAT_00512d68 == -1) {
    iVar5 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar5 = 0xffff;
  }
  else {
    iVar5 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar5);
  iVar5 = iStack0000001c + iVar8;
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,1,0);
  FUN_004b0613(&TStack_28,s_dnwn_7_004db020);
  uStack_4 = 5;
  (*pcVar6)(param_1,iVar4,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar8);
  CDC::LineTo(param_1,param_4 + -2,iVar8);
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,0,0);
  if (DAT_00512d68 == 100) {
    iVar8 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar8 = 0xffff00;
  }
  else {
    iVar8 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar8);
  iVar8 = iStack0000001c + iVar5;
  FUN_00463f50(param_1,iVar7,iVar5,param_4,iVar8,1,0);
  FUN_004b0613(&TStack_28,s_boat1_9_004db014);
  uStack_4 = 6;
  (*pcVar6)(param_1,iVar4,iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar5);
  CDC::LineTo(param_1,param_4 + -2,iVar5);
  TStack_2c.data = (char *)(iVar8 + 1);
  FUN_004b4d9d(param_1,local_14,iVar4,(int)TStack_2c.data);
  CDC::LineTo(param_1,param_4 + -2,(int)TStack_2c.data);
  FUN_00463f50(param_1,iVar7,iVar5,param_4,iVar8,0,0);
  if (DAT_00512d68 == 100) {
    iVar5 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar5 = 0xffff00;
  }
  else {
    iVar5 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar5);
  iVar5 = iStack0000001c + iVar8;
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,1,0);
  if (DAT_004fe624 < 0x385) {
    FUN_004b0613(&TStack_28,s_hid_sail_U_004daffc);
    uStack_4 = 8;
    (*pcVar6)(param_1,iVar4,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
  }
  else {
    FUN_004b0613(&TStack_28,s_hide_sail_U_004db008);
    uStack_4 = 7;
    (*pcVar6)(param_1,iVar4,iVar8,TStack_28.data,*(int *)(TStack_28.data + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  (*pcVar2)(param_1,6);
  FUN_004b4d9d(param_1,local_14,iVar4,iVar8);
  CDC::LineTo(param_1,param_4 + -2,iVar8);
  TStack_2c.data = (char *)(iVar5 + 1);
  FUN_004b4d9d(param_1,local_14,iVar4,(int)TStack_2c.data);
  CDC::LineTo(param_1,param_4 + -2,(int)TStack_2c.data);
  FUN_00463f50(param_1,iVar7,iVar8,param_4,iVar5,0,0);
  FUN_0040db60(param_1,param_2,iVar8,param_4,param_5,param_6,iStack0000001c);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


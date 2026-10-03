
void __cdecl FUN_00442270(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  int *original_dc;
  int iVar3;
  Tact2010CString *pTVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString local_40;
  int aiStack_3c [3];
  int aiStack_30 [5];
  int aiStack_1c [4];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  original_dc = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c3140;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_004b045a(&local_40);
  local_4 = 0;
  if (DAT_005363bc != 1) {
    FUN_004b4a1f(param_1,1);
    iVar7 = param_3;
    iVar1 = param_3 + -0x1e;
    if (*(int *)(&DAT_004f71c0 + param_2 * 4) == 3) {
      iVar6 = 0x1f;
    }
    else {
      iVar6 = param_4 + -10;
    }
    if (DAT_005363e4 == 0) {
      iVar3 = *param_1;
      (**(code **)(iVar3 + 0x34))(param_1,0x7f7f00);
      (**(code **)(iVar3 + 0x38))(param_1,0xffff);
    }
    if (DAT_00536450 == 1) {
      (**(code **)(*param_1 + 0x34))(param_1,0x7f7f7f);
    }
    iVar3 = *(int *)(&DAT_00535740 + param_2 * 4);
    if (iVar3 < 100) {
      param_1 = (int *)(iVar7 + -0x28);
    }
    else {
      param_1 = (int *)(iVar7 + -0x2d);
    }
    if (DAT_00536490 == 1) {
      iVar3 = FUN_0041bc20(iVar3 + *(int *)(&DAT_00522ff0 + param_2 * 4) * -0x2d);
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    pTVar4 = FUN_0041bc70((Tact2010CString *)&param_3,iVar3);
    local_4._0_1_ = 1;
    FUN_004b069e(&local_40,pTVar4);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_004b05a5((Tact2010CString *)&param_3);
    (**(code **)(*original_dc + 100))
              (original_dc,(int)param_1,iVar6 + -0x1a,local_40.data,*(int *)(local_40.data + -8));
    iVar5 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_2 * 4));
    aiStack_1c[0] = iVar1 - ((&DAT_004f85c8)[iVar5] * 0x1a) / 100;
    aiStack_30[0] = iVar6 - ((&DAT_004f1740)[iVar5] * 0x1a) / 300;
    iVar3 = (&DAT_004f1740)[iVar5] * 0xd;
    aiStack_1c[3] = iVar3 / 100;
    aiStack_1c[1] = aiStack_1c[3] + iVar1;
    iVar5 = (&DAT_004f85c8)[iVar5] * 0xd;
    aiStack_30[3] = iVar5 / 300;
    aiStack_30[1] = iVar6 - aiStack_30[3];
    aiStack_1c[2] = iVar5 / 100 + iVar1;
    aiStack_30[2] = iVar3 / 300 + iVar6;
    aiStack_1c[3] = iVar1 - aiStack_1c[3];
    aiStack_30[3] = iVar6 + aiStack_30[3];
    pcVar2 = *(code **)(*original_dc + 0x2c);
    (*pcVar2)(original_dc,4);
    (*pcVar2)(original_dc,7);
    Ellipse((HDC)original_dc[1],iVar7 + -0x38,iVar6 + -8,iVar7 + -4,iVar6 + 8);
    if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f7ec4);
    }
    iVar7 = 0;
    do {
      FUN_004b4d9d(original_dc,aiStack_3c,iVar1,iVar6);
      CDC::LineTo(original_dc,*(int *)((int)aiStack_1c + iVar7),*(int *)((int)aiStack_30 + iVar7));
      iVar7 = iVar7 + 4;
    } while (iVar7 < 0x10);
    (*pcVar2)(original_dc,7);
    FUN_004b4a1f(original_dc,2);
    local_4 = 0xffffffff;
    FUN_004b05a5(&local_40);
    *unaff_FS_OFFSET = local_c;
    return;
  }
  local_4 = 0xffffffff;
  FUN_004b05a5(&local_40);
  *unaff_FS_OFFSET = local_c;
  return;
}


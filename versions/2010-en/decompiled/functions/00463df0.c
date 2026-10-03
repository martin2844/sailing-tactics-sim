
void __cdecl FUN_00463df0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *original_dc;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar3 = DAT_004fb9b4;
  iVar1 = DAT_004da18c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c5878;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < iVar1) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*param_1 + 0x38))(param_1,0);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_Advance_Button__or_press_A_004ec250);
    iVar3 = param_3;
    iVar1 = *original_dc;
    pcVar2 = *(code **)(iVar1 + 100);
    uStack_4 = 0;
    (*pcVar2)(original_dc,3,DAT_004faf7c - param_3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar1 + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,"Click Advance Button (or press A).");
    uStack_4 = 1;
    (*pcVar2)(original_dc,3,DAT_004faf7c - iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press___for_next_topic__Press___f_004ec1c4);
  uStack_4 = 2;
  (**(code **)(*original_dc + 100))
            (original_dc,3,DAT_004faf7c - param_3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


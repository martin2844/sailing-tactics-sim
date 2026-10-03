
void __cdecl FUN_0044d830(int param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar3 = DAT_004a6774;
  iVar1 = DAT_00491184;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00480638;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < iVar1) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)param_1 + 0x38))((void *)param_1,0);
    }
    FUN_0046bf33(&param_1,s_Click_Advance_Button__or_press_A_0049f21c);
    iVar3 = param_3;
    iVar1 = *(int *)this;
    pcVar2 = *(code **)(iVar1 + 100);
    uStack_4 = 0;
    (*pcVar2)((void *)this,3,DAT_004a600c - param_3,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar1 + 0x38))((void *)this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_Advance_Button__or_press_A_0049f1f8);
    uStack_4 = 1;
    (*pcVar2)((void *)this,3,DAT_004a600c - iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))((void *)param_1,0xff);
  }
  FUN_0046bf33(&param_1,s_Press___for_next_topic__Press___f_0049f190);
  uStack_4 = 2;
  (**(code **)(*(int *)this + 100))
            ((void *)this,3,DAT_004a600c - param_3,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}



void __cdecl FUN_004094c0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  int this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d870;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)param_1;
  pcVar2 = *(code **)(iVar1 + 0x2c);
  (*pcVar2)((void *)param_1,4);
  (*pcVar2)((void *)this,6);
  Rectangle(*(HDC *)(this + 4),param_2,param_3,param_4,param_3 + 0x14);
  param_3 = *(undefined4 *)(iVar1 + 0x34);
  (*(code *)param_3)((void *)this,0);
  pcVar2 = *(code **)(iVar1 + 0x38);
  (*pcVar2)((void *)this,0xffffff);
  FUN_0046bf33(&param_1,s___WIND_CHART___00491a44);
  pcVar3 = *(code **)(iVar1 + 100);
  uStack_4 = 0;
  (*pcVar3)((void *)this,1,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  if (DAT_004ac92c == 0) {
    (*pcVar2)((void *)this,0xffff);
    FUN_0046bf33(&param_1,s_Mixing_00491a3c);
    uStack_4 = 1;
    (*pcVar3)((void *)this,200,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    (*pcVar2)((void *)this,0xff00ff);
    FUN_0046bf33(&param_1,s_Convergence_00491a30);
    uStack_4 = 2;
    (*pcVar3)((void *)this,0x118,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    (*pcVar2)((void *)this,0xff00);
    FUN_0046bf33(&param_1,s_Divergence_00491a24);
    uStack_4 = 3;
    (*pcVar3)((void *)this,0x186,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    (*pcVar2)((void *)this,0xff);
    FUN_0046bf33(&param_1,&DAT_00491a1c);
    uStack_4 = 4;
    (*pcVar3)((void *)this,500,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    (*pcVar2)((void *)this,0xffff00);
    FUN_0046bf33(&param_1,s_Channeled_00491a10);
    uStack_4 = 5;
    (*pcVar3)((void *)this,0x226,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  else {
    FUN_0046bf33(&param_1,s_Transient_puff_vectors_are_black_004919ec);
    uStack_4 = 6;
    (*pcVar3)((void *)this,200,1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  if (DAT_004ac92c == 0) {
    (*pcVar2)((void *)this,0x7f);
    (*(code *)param_3)((void *)this,0xffffff);
  }
  FUN_0046bf33(&param_1,s_Movement_suspended__Click_mouse_o_004918bc);
  uStack_4 = 7;
  (*pcVar3)((void *)this,1,DAT_004a72d0 / 0x1b,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


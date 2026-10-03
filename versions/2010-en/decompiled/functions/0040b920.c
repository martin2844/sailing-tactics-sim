
void __cdecl FUN_0040b920(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  int *original_dc;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2000;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *param_1;
  pcVar2 = *(code **)(iVar1 + 0x2c);
  (*pcVar2)(param_1,4);
  (*pcVar2)(original_dc,6);
  Rectangle((HDC)original_dc[1],param_2,param_3,param_4,param_3 + 0x14);
  param_3 = *(undefined4 *)(iVar1 + 0x34);
  (*(code *)param_3)(original_dc,0);
  pcVar2 = *(code **)(iVar1 + 0x38);
  (*pcVar2)(original_dc,0xffffff);
  FUN_004b0613((Tact2010CString *)&param_1,s___WIND_CHART___004dacc8);
  pcVar3 = *(code **)(iVar1 + 100);
  uStack_4 = 0;
  (*pcVar3)(original_dc,1,1,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (*pcVar2)(original_dc,0x7fff);
    FUN_004b0613((Tact2010CString *)&param_1,s_Mixing_004dacc0);
    uStack_4 = 1;
    (*pcVar3)(original_dc,200,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0xff00ff);
    FUN_004b0613((Tact2010CString *)&param_1,s_Convergence_004dacb4);
    uStack_4 = 2;
    (*pcVar3)(original_dc,0x118,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0xff00);
    FUN_004b0613((Tact2010CString *)&param_1,s_Divergence_004daca8);
    uStack_4 = 3;
    (*pcVar3)(original_dc,0x186,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0xff);
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004daca0);
    uStack_4 = 4;
    (*pcVar3)(original_dc,500,1,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0xffff00);
    FUN_004b0613((Tact2010CString *)&param_1,s_Channeled_004dac94);
    uStack_4 = 5;
    (*pcVar3)(original_dc,0x226,1,(char *)param_1,param_1[-2]);
  }
  else {
    FUN_004b0613((Tact2010CString *)&param_1,s_Transient_puff_vectors_are_black_004dac70);
    uStack_4 = 6;
    (*pcVar3)(original_dc,200,1,(char *)param_1,param_1[-2]);
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (*pcVar2)(original_dc,0x7f);
    (*(code *)param_3)(original_dc,0xffffff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Movement_suspended__Click_mouse_o_004da994);
  uStack_4 = 7;
  (*pcVar3)(original_dc,1,(DAT_004fe2a8 - DAT_004fe2a8 / 10) + -5,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


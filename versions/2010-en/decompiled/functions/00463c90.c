
void __cdecl FUN_00463c90(int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int top;
  HGDIOBJ h;
  int *original_dc;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  h = DAT_004fe07c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c5850;
  *unaff_FS_OFFSET = &uStack_c;
  top = DAT_004faf7c;
  if (h != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],h);
  }
  iVar1 = *original_dc;
  (**(code **)(iVar1 + 0x2c))(original_dc,7);
  Rectangle((HDC)original_dc[1],0,top,DAT_004fe624 / 3 + 4,top + 3 + param_2);
  param_2 = *(undefined4 *)(iVar1 + 0x34);
  (*(code *)param_2)(original_dc,0x7f7f7f);
  pcVar2 = *(code **)(iVar1 + 0x38);
  (*pcVar2)(original_dc,0);
  if (DAT_004fb9b4 == DAT_004da18c) {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(original_dc,0xffff00);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_Here_to_Restore_Positions_004ec1a0);
    uStack_4 = 0;
    (**(code **)(iVar1 + 100))(original_dc,2,top + 2,(char *)param_1,param_1[-2]);
  }
  else {
    if (DAT_005363e4 == 0) {
      (*pcVar2)(original_dc,0xffff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_Here_to_Advance_Positions_004ec17c);
    uStack_4 = 1;
    (**(code **)(iVar1 + 100))(original_dc,2,top + 2,(char *)param_1,param_1[-2]);
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  (*(code *)param_2)(original_dc,0xffffff);
  (*pcVar2)(original_dc,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


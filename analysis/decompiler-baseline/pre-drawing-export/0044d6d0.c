
void __cdecl FUN_0044d6d0(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int top;
  HGDIOBJ h;
  code *unaff_EBP;
  int *unaff_FS_OFFSET;
  code *pcVar3;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  h = DAT_004a70e4;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00480610;
  *unaff_FS_OFFSET = (int)&iStack_c;
  top = DAT_004a600c;
  if (h != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],h);
  }
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x2c))(7);
  Rectangle((HDC)param_1[1],0,top,DAT_004a763c / 3 + 4,top + 3 + (int)param_1);
  (**(code **)(iVar1 + 0x34))(0x7f7f7f);
  pcVar2 = *(code **)(iVar1 + 0x38);
  (*pcVar2)(0);
  if (DAT_004a6774 == DAT_00491184) {
    if (DAT_004ac92c == 0) {
      (*pcVar2)(0xffff00);
    }
    FUN_0046bf33(&pcStack_8,s_Click_Here_to_Restore_Positions_0049f16c);
    pcVar3 = pcStack_8;
    (**(code **)(iVar1 + 100))(2,top + 2,pcStack_8,*(undefined4 *)(pcStack_8 + -8));
  }
  else {
    if (DAT_004ac92c == 0) {
      (*pcVar2)(0xffff);
    }
    FUN_0046bf33(&pcStack_8,s_Click_Here_to_Advance_Positions_0049f148);
    pcVar3 = pcStack_8;
    (**(code **)(iVar1 + 100))(2,top + 2,pcStack_8,*(undefined4 *)(pcStack_8 + -8));
  }
  FUN_0046bec5((int *)&stack0xffffffe8);
  (*unaff_EBP)(0xffffff);
  (*pcVar2)(0);
  *unaff_FS_OFFSET = (int)pcVar3;
  return;
}


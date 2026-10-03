
void __cdecl FUN_0044d6d0(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int top;
  HGDIOBJ h;
  int this;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  h = DAT_004a70e4;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00480610;
  *unaff_FS_OFFSET = &uStack_c;
  top = DAT_004a600c;
  if (h != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),h);
  }
  iVar1 = *(int *)this;
  (**(code **)(iVar1 + 0x2c))((void *)this,7);
  Rectangle(*(HDC *)(this + 4),0,top,DAT_004a763c / 3 + 4,top + 3 + param_2);
  param_2 = *(undefined4 *)(iVar1 + 0x34);
  (*(code *)param_2)((void *)this,0x7f7f7f);
  pcVar2 = *(code **)(iVar1 + 0x38);
  (*pcVar2)((void *)this,0);
  if (DAT_004a6774 == DAT_00491184) {
    if (DAT_004ac92c == 0) {
      (*pcVar2)((void *)this,0xffff00);
    }
    FUN_0046bf33(&param_1,s_Click_Here_to_Restore_Positions_0049f16c);
    uStack_4 = 0;
    (**(code **)(iVar1 + 100))((void *)this,2,top + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  else {
    if (DAT_004ac92c == 0) {
      (*pcVar2)((void *)this,0xffff);
    }
    FUN_0046bf33(&param_1,s_Click_Here_to_Advance_Positions_0049f148);
    uStack_4 = 1;
    (**(code **)(iVar1 + 100))((void *)this,2,top + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  (*(code *)param_2)((void *)this,0xffffff);
  (*pcVar2)((void *)this,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}


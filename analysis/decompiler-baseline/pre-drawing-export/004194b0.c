
void __cdecl FUN_004194b0(CDC *param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  if (((DAT_004ac904 != 1) && (DAT_004ac13c < param_5)) && (param_4 * DAT_004ac928 < 2)) {
    if (DAT_004ac900 == 1) {
      FUN_00419640(param_1,param_2,param_3,param_4);
      return;
    }
    if (param_4 < 2) {
      uVar2 = DAT_004a7044 / 2 >> 0x1f;
      iVar1 = (DAT_004a7044 / 2 ^ uVar2) - uVar2;
    }
    else {
      iVar1 = 0;
    }
    if (DAT_004a7044 < 1) {
      DAT_004aa708 = (((DAT_004aa1bc + DAT_004aa1a4) / 2) * iVar1 + DAT_004aa1a4) / (iVar1 + 1);
      DAT_004abe68 = (((DAT_004aa2a4 + DAT_004aa2bc) / 2) * iVar1 + DAT_004aa2a4) / (iVar1 + 1);
    }
    else {
      DAT_004aa708 = (((DAT_004aa1dc + DAT_004aa1a4) / 2) * iVar1 + DAT_004aa1a4) / (iVar1 + 1);
      DAT_004abe68 = (((DAT_004aa2a4 + DAT_004aa2dc) / 2) * iVar1 + DAT_004aa2a4) / (iVar1 + 1);
    }
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,&param_2,DAT_004aa1a0,DAT_004aa2a0);
    CDC::LineTo(param_1,DAT_004aa708,DAT_004abe68);
    (**(code **)(*(int *)param_1 + 0x2c))(7);
  }
  return;
}


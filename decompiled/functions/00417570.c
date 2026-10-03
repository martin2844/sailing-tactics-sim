
void __cdecl
FUN_00417570(CDC *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,int param_7)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  HDC hdc;
  HGDIOBJ h;
  int local_8 [2];
  
  if (DAT_004ac98c == 1) {
    pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
    (*pcVar1)(param_1,6);
    (*pcVar1)(param_1,0);
    FUN_00423640((int)param_1,2,param_2,param_3 + -1);
    return;
  }
  if (DAT_004ac92c != 0) {
    if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
    }
    goto LAB_0041768d;
  }
  uVar5 = (int)param_4 >> 0x1f;
  if (((param_4 ^ uVar5) - uVar5 & 1 ^ uVar5) == uVar5) {
    if (DAT_004a39fc != (HGDIOBJ)0x0) {
      hdc = *(HDC *)(param_1 + 4);
      h = DAT_004a39fc;
LAB_00417617:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_004a676c != (HGDIOBJ)0x0) {
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a676c;
    goto LAB_00417617;
  }
  if ((param_7 == 1) && (DAT_004a4374 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4374);
  }
  if ((param_7 == 2) && (DAT_004a676c != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a676c);
  }
LAB_0041768d:
  iVar3 = *(int *)(&DAT_004aa730 + param_4 * 4);
  iVar4 = *(int *)(&DAT_004a7bc8 + param_4 * 4);
  iVar2 = FUN_00415a20(0x14);
  iVar3 = FUN_00413cb0((-((iVar3 * iVar4 * 2) / 3) - param_5) + -10 + iVar2);
  iVar4 = FUN_00413cb0(iVar3);
  iVar3 = (&DAT_004a54a0)[iVar4];
  iVar4 = (&DAT_004a3450)[iVar4];
  iVar2 = param_6 / 0xf;
  if ((*(int *)(&DAT_004a4e88 + param_4 * 4) == 3) || (500 < DAT_004ac980)) {
    iVar2 = (iVar2 * 2) / 3;
  }
  FUN_004706bd(param_1,local_8,param_2,param_3);
  CDC::LineTo(param_1,(iVar2 * iVar3) / 100 + param_2,(iVar2 * iVar4) / 300 + param_3);
  return;
}


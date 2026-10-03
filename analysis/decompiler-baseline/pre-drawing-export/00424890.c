
void __cdecl FUN_00424890(CDC *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ h;
  
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar1)(7);
  if ((param_3 == 3) || (param_3 == 5)) {
    if (DAT_004a3a14 == (HGDIOBJ)0x0) goto LAB_004248ef;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a3a14;
  }
  else {
    if (DAT_004a6234 == (HGDIOBJ)0x0) goto LAB_004248ef;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a6234;
  }
  SelectObject(hdc,h);
LAB_004248ef:
  if ((param_3 == 2) && (DAT_004a3a14 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a14);
  }
  if ((DAT_004ac92c == 1) || (param_3 == 2)) {
    (*pcVar1)(0);
  }
  iVar2 = (int)(8 / (longlong)*(int *)(&DAT_004a8660 + param_5 * 4));
  if (iVar2 < 3) {
    iVar2 = 3;
  }
  if (param_4 == 3) {
    iVar2 = 4;
  }
  if (param_3 == 2) {
    iVar2 = iVar2 + 1;
  }
  FUN_00423640((int)param_1,iVar2,(int)param_1,param_2);
  if (((param_3 == 2) && (param_4 == 1)) && (*(int *)(&DAT_004a8660 + param_5 * 4) < 8)) {
    FUN_00423aa0(param_1,(int)param_1,param_2,0,1);
  }
  return;
}


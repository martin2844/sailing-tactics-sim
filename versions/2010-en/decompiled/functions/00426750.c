
void FUN_00426750(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int local_8 [2];
  
  if (param_4 == 0) {
    if (DAT_005363e4 == 0) {
      if (DAT_0053516c == (HGDIOBJ)0x0) goto LAB_004267ac;
      hdc = (HDC)param_1[1];
      h = DAT_0053516c;
    }
    else {
      if (DAT_004f7ec4 == (HGDIOBJ)0x0) goto LAB_004267ac;
      hdc = (HDC)param_1[1];
      h = DAT_004f7ec4;
    }
    SelectObject(hdc,h);
  }
LAB_004267ac:
  if (param_5 == 1) {
    iVar1 = DAT_004f4cdc * DAT_00522ff4;
    iVar3 = DAT_004f4b44;
  }
  else {
    iVar1 = *(int *)(&DAT_004f4cd8 + param_5 * 4) * *(int *)(&DAT_00522ff0 + param_5 * 4);
    iVar3 = DAT_004f4bb8;
  }
  iVar2 = FUN_0041e000(0x14);
  iVar1 = FUN_0041bc20(iVar2 + -10 + (-(iVar1 / 2) - iVar3));
  iVar3 = (&DAT_004f85c8)[iVar1];
  iVar2 = DAT_004fe624 / 0x8c;
  iVar1 = (&DAT_004f1740)[iVar1];
  FUN_004b4d9d(param_1,local_8,param_2,param_3);
  CDC::LineTo(param_1,(iVar3 * iVar2) / 100 + param_2,(iVar1 * iVar2) / 300 + param_3);
  return;
}


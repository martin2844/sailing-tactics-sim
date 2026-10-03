
void FUN_00434c60(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ h;
  
  if (((DAT_004da1f8 == 5) && (2 < param_4)) && (param_4 < 6)) {
    if (((param_4 == 3) && (DAT_004da214 == 1)) && (DAT_004f3864 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f3864);
    }
    if (((param_4 == 3) && (DAT_004da214 == -1)) && (DAT_005233b4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005233b4);
    }
    if (param_4 == 4) {
      (**(code **)(*param_1 + 0x2c))(param_1,0);
    }
    if (param_4 == 5) {
      if ((DAT_004da214 == 1) && (DAT_005233b4 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_005233b4);
      }
      if ((DAT_004da214 == -1) && (DAT_004f3864 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f3864);
      }
    }
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    FUN_00433a70(param_1,4,param_2,param_3);
    return;
  }
  if ((((DAT_0053527c == 1) && (DAT_00536408 == 0)) && (param_4 == 4)) && (DAT_004da194 < 0xf)) {
    return;
  }
  if (DAT_0053527c == 1) {
    if ((DAT_00536408 == 0) && (param_4 == 5)) {
      return;
    }
    if (((DAT_00536408 == 1) && (0 < DAT_005364e0)) && (param_4 == 5)) {
      return;
    }
  }
  if (((param_4 == DAT_004da194 + 7) || (param_4 == DAT_004da194 + 6)) && (DAT_004f452c == 0)) {
    return;
  }
  if (DAT_004f452c == 1) {
    if (param_4 == 5) {
      return;
    }
    if (((param_4 == 1) && (DAT_00536408 == 1)) && ((DAT_004da188 != 2 && (DAT_005363f8 != 1)))) {
      return;
    }
  }
  if (((DAT_004da194 < 0xf) && (param_4 == 4)) && (DAT_004da168 == 1)) {
    return;
  }
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  if ((param_4 == 3) || (param_4 == 5)) {
    if (DAT_004ff034 == (HGDIOBJ)0x0) goto LAB_00434e79;
    hdc = (HDC)param_1[1];
    h = DAT_004ff034;
  }
  else {
    if (DAT_004fb25c == (HGDIOBJ)0x0) goto LAB_00434e79;
    hdc = (HDC)param_1[1];
    h = DAT_004fb25c;
  }
  SelectObject(hdc,h);
LAB_00434e79:
  if ((param_4 == 2) && (DAT_004f3864 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f3864);
  }
  if ((param_4 == DAT_004da194 + 7) || (param_4 == DAT_004da194 + 6)) {
    if (DAT_004f41ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f41ec);
    }
    if (DAT_00522f1c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_00522f1c);
    }
  }
  if ((DAT_005363e4 == 1) || (param_4 == 2)) {
    (*pcVar1)(param_1,0);
  }
  iVar2 = (int)(8 / (longlong)*(int *)(&DAT_0050f6d0 + param_6 * 4));
  if (iVar2 < 3) {
    iVar2 = 3;
  }
  if (param_5 == 3) {
    iVar2 = 4;
  }
  if (param_4 == 2) {
    iVar2 = iVar2 + 2;
  }
  FUN_00433a70(param_1,iVar2,param_2,param_3);
  if (((param_4 == 2) && (param_5 == 1)) && (*(int *)(&DAT_0050f6d0 + param_6 * 4) < 8)) {
    FUN_00433f70(param_1,param_2,param_3,0,1);
  }
  return;
}



void __cdecl
FUN_00442fd0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HDC hdc;
  HGDIOBJ h;
  int local_c;
  
  if (DAT_005363b0 == 0) {
    return;
  }
  iVar4 = 1;
  if (DAT_00536450 == 1) {
    return;
  }
  if (DAT_005363e4 == 0) {
    if (((DAT_004da1f8 == 0x6a) || (DAT_004da1f8 == 0x69)) ||
       ((DAT_00536524 == 1 && (DAT_004da1f8 == 999)))) {
      if (DAT_004fb9a4 == (HGDIOBJ)0x0) goto LAB_00443081;
      hdc = (HDC)param_1[1];
      h = DAT_004fb9a4;
    }
    else {
      if (DAT_004fe80c == (HGDIOBJ)0x0) goto LAB_00443081;
      hdc = (HDC)param_1[1];
      h = DAT_004fe80c;
    }
  }
  else {
    if (DAT_004f7084 == (HGDIOBJ)0x0) goto LAB_00443081;
    hdc = (HDC)param_1[1];
    h = DAT_004f7084;
  }
  SelectObject(hdc,h);
LAB_00443081:
  if ((DAT_004da174 < 0xc) && (DAT_004da140 == 1)) {
    iVar3 = 200;
    local_c = 200;
  }
  else {
    local_c = 100;
    iVar3 = 100;
  }
  if ((0xb < DAT_004da174) && (DAT_004da140 == 2)) {
    local_c = 0x32;
    iVar3 = 0x32;
  }
  iVar2 = (DAT_004fe2a8 / 10 + param_6) - DAT_004f4b48;
  piVar1 = param_1;
  if (DAT_004da140 == 1) {
    if (iVar3 != 0) {
      do {
        if (((DAT_005364e8 < 10) || ((0x14 < DAT_005364e8 && (DAT_005364e8 < 0x1e)))) ||
           ((0x28 < DAT_005364e8 && (DAT_005364e8 < 0x32)))) {
          iVar3 = iVar4 * 4;
        }
        else {
          iVar3 = iVar4 * 4 + 0x50;
        }
        if (DAT_004da140 == 1) {
          piVar1 = (int *)((*(int *)((int)&DAT_00512d70 + iVar3) * DAT_004fe624) / 100);
        }
        if (DAT_004da140 == 2) {
          if (param_2 == 1) {
            piVar1 = (int *)(((&DAT_00512d78)[iVar4] * DAT_004fe624) / 400 + DAT_004fe624 / 2);
          }
          if (param_2 == 2) {
            piVar1 = (int *)(((&DAT_00512d70)[iVar4 / 2] * DAT_004fe624) / 200);
          }
        }
        FUN_00424320(param_1,piVar1,param_6 - ((&DAT_00512d70)[iVar4 / 2] * iVar2) / 100,1);
        iVar4 = iVar4 + 1;
      } while (iVar4 <= local_c);
      return;
    }
  }
  else {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      if (DAT_004da140 == 2) {
        if (param_2 == 1) {
          iVar4 = FUN_0041e000(DAT_004fe624 / 2);
          piVar1 = (int *)(iVar4 + DAT_004fe624 / 2);
        }
        if (param_2 == 2) {
          piVar1 = (int *)FUN_0041e000(DAT_004fe624 / 2);
        }
      }
      iVar4 = FUN_0041e000(iVar2);
      FUN_00424320(param_1,piVar1,param_6 - iVar4,1);
    }
  }
  return;
}


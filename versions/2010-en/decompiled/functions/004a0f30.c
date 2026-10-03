
uint FUN_004a0f30(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_004a1053:
    param_2[3] = uVar1 | 0x20;
    return 0xffffffff;
  }
  iVar7 = 0;
  if ((uVar1 & 1) != 0) {
    param_2[1] = 0;
    if ((uVar1 & 0x10) == 0) goto LAB_004a1053;
    *param_2 = param_2[2];
    param_2[3] = uVar1 & 0xfffffffe;
  }
  uVar1 = param_2[3];
  param_2[1] = 0;
  param_2[3] = uVar1 & 0xffffffef | 2;
  if ((uVar1 & 0x10c) == 0) {
    if ((param_2 == (int *)&DAT_004f0750) || (param_2 == (int *)&DAT_004f0770)) {
      iVar5 = FUN_004a3740(uVar2);
      if (iVar5 != 0) goto LAB_004a0fa3;
    }
    FUN_004a36e0(piVar4);
  }
LAB_004a0fa3:
  if ((piVar4[3] & 0x108U) == 0) {
    iVar5 = 1;
    iVar7 = FUN_004a3450(uVar2,&param_1,1);
  }
  else {
    iVar3 = piVar4[2];
    iVar5 = *piVar4 - iVar3;
    *piVar4 = iVar3 + 1;
    piVar4[1] = piVar4[6] + -1;
    if (iVar5 < 1) {
      if (uVar2 == 0xffffffff) {
        puVar6 = &DAT_004ee0a8;
      }
      else {
        puVar6 = (undefined *)((&DAT_00539940)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
      }
      if ((puVar6[4] & 0x20) != 0) {
        FUN_004a3350(uVar2,0,2);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    else {
      iVar7 = FUN_004a3450(uVar2,iVar3,iVar5);
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
  }
  if (iVar7 != iVar5) {
    piVar4[3] = piVar4[3] | 0x20;
    return 0xffffffff;
  }
  return param_1 & 0xff;
}


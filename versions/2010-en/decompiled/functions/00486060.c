
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00486060(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8 [2];
  
  FUN_0043e730(0,18750.0,750.0,param_2,5);
  iVar3 = DAT_00523660;
  iVar1 = DAT_004fed58;
  FUN_0043e730(0,18750.0,975.0,param_2,5);
  iVar4 = DAT_00523660;
  iVar2 = DAT_004fed58;
  if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f7ec4);
  }
  FUN_004b4d9d(param_1,local_8,iVar1,iVar3 + -1);
  CDC::LineTo(param_1,iVar2,iVar4 + -1);
  FUN_00441fb0(param_1,iVar1,iVar3,1);
  FUN_00441fb0(param_1,iVar2,iVar4,1);
  DAT_004f4690 = 0xffffe890;
  DAT_004fb418 = 0x2fc1;
  DAT_004f4698 = 0xffffea07;
  DAT_004fb4ac = 0x32af;
  _DAT_00536224 = 0xffffe2b4;
  _DAT_004f6d44 = 0x2409;
  _DAT_004fb9d4 = 0xffffe890;
  _DAT_004f720c = 0x2fc1;
  _DAT_004fb9f4 = 0xffffea07;
  _DAT_004f71f4 = 0x32af;
  _DAT_00536214 = 0xffffefe3;
  _DAT_004f6d54 = 0x3e67;
  FUN_004865c0(param_1,1,param_2);
  FUN_0043e730(0,-1724.0,675.0,param_2,5);
  FUN_00482810(param_1,DAT_004fed58,DAT_00523660,1,param_2);
  FUN_0043e730(0,-1875.0,2550.0,param_2,5);
  FUN_00482810(param_1,DAT_004fed58,DAT_00523660,1,param_2);
  FUN_0043e730(0,1687.0,1425.0,param_2,5);
  FUN_00482810(param_1,DAT_004fed58,DAT_00523660,10,param_2);
  return;
}


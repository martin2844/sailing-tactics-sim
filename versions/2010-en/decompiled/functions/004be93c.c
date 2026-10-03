
void __thiscall FUN_004be93c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  tagRECT local_14;
  
  *(undefined4 *)(param_1 + 100) = param_3;
  uVar3 = CONCAT31((uint3)((uint)param_3 >> 8) & 0xffff00,0x4e);
  uVar1 = FUN_004af3eb();
  if ((uVar1 & 0x40000) != 0) {
    uVar3 = uVar3 | 0x100;
  }
  iVar2 = FUN_004bfff8();
  if ((*(byte *)(iVar2 + 0x18) & 0x10) == 0) {
    FUN_004af183(0x10);
  }
  SetRectEmpty(&local_14);
  FUN_004ace41("msctls_statusbar32",0,uVar3,&local_14,param_2,param_4,0);
  return;
}


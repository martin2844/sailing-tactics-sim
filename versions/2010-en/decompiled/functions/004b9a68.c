
bool __thiscall FUN_004b9a68(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  tagRECT local_14;
  
  *(undefined4 *)(param_1 + 100) = param_3;
  iVar1 = FUN_004bfff8();
  if ((*(byte *)(iVar1 + 0x18) & 2) == 0) {
    iVar1 = FUN_004af183(2);
  }
  else {
    iVar1 = 1;
  }
  bVar2 = false;
  if (iVar1 != 0) {
    SetRectEmpty(&local_14);
    iVar1 = FUN_004ace41("AfxControlBar42s",0,param_3,&local_14,param_2,param_4,0);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


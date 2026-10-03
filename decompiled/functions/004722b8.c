
int __thiscall FUN_004722b8(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00471f61(this,0);
    if (-1 < iVar2) {
      puVar1 = *(undefined4 **)(*(int *)((int)this + 0x5c) + iVar2 * 0x14 + 0x10);
      uVar3 = puVar1[-2];
      if (param_1 < (int)uVar3) {
        uVar3 = param_1 - 1;
      }
      FUN_00457850(param_2,puVar1,uVar3);
    }
    *(undefined1 *)(uVar3 + (int)param_2) = 0;
    iVar2 = uVar3 + 1;
  }
  return iVar2;
}


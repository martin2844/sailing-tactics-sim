
void __thiscall FUN_004b667a(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 0x5c) + 8 + param_2 * 0x14);
  iVar1 = *(int *)(param_1 + 0x5c) + param_2 * 0x14;
  if (uVar2 != param_3) {
    *(uint *)(iVar1 + 8) = param_3;
    if (((param_3 ^ uVar2) & 0x8000000) == 0) {
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
      FUN_004b66c5(param_2,*(undefined4 *)(iVar1 + 0x10),1);
    }
    else {
      FUN_004bebe0(1,0);
    }
  }
  return;
}


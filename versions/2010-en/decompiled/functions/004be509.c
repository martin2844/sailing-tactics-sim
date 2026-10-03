
void FUN_004be509(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    puVar3 = &DAT_004d0728;
    do {
      iVar1 = FUN_004bc506(*puVar3);
      if (iVar1 != 0) {
        uVar4 = 0xffffffff;
        uVar2 = GetDlgCtrlID(*(HWND *)(param_1 + 0x1c));
        iVar1 = FUN_004ba69e(uVar2 & 0xffff,uVar4);
        if (0 < iVar1) break;
      }
      if (((*(uint *)(param_1 + 100) ^ puVar3[1]) & 0xf000) == 0) {
        FUN_004bc506(*puVar3);
      }
      puVar3 = puVar3 + 2;
    } while ((int)puVar3 < 0x4d0748);
  }
  FUN_004b9d6b(param_1,param_3);
  return;
}


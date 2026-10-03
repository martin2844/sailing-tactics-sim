
void FUN_004a65c0(undefined2 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 local_c;
  undefined4 uStack_a;
  undefined2 uStack_6;
  undefined4 local_4;
  
  iVar3 = 0x4f1188;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar3 = 0x4f12e8;
    }
    if (param_3 == 0) {
      *param_1 = 0;
    }
    while (param_2 != 0) {
      iVar3 = iVar3 + 0x54;
      uVar1 = param_2 & 7;
      param_2 = (int)param_2 >> 3;
      if (uVar1 != 0) {
        puVar2 = (undefined4 *)(iVar3 + uVar1 * 0xc);
        if (0x7fff < *(ushort *)(iVar3 + uVar1 * 0xc)) {
          local_c = (undefined2)*puVar2;
          uStack_a._0_2_ = (undefined2)((uint)*puVar2 >> 0x10);
          uStack_a._2_2_ = (undefined2)puVar2[1];
          uStack_6 = (undefined2)((uint)puVar2[1] >> 0x10);
          local_4 = puVar2[2];
          uStack_a = CONCAT22(uStack_a._2_2_,(undefined2)uStack_a) + -1;
          puVar2 = (undefined4 *)&local_c;
        }
        FUN_004a6300(param_1,puVar2);
      }
    }
  }
  return;
}


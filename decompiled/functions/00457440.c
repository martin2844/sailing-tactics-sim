
int __cdecl FUN_00457440(byte *param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  if (DAT_004aea6c != 0) {
    FUN_0045b730(0x19);
    pbVar3 = param_2;
    while( true ) {
      param_2._0_2_ = (ushort)*param_1;
      pbVar5 = param_1 + 1;
      if ((*(byte *)((int)&DAT_004ae968 + (ushort)param_2 + 1) & 4) != 0) {
        bVar1 = *pbVar5;
        if (bVar1 == 0) {
          param_2._0_2_ = 0;
        }
        else {
          pbVar5 = param_1 + 2;
          param_2._0_2_ = CONCAT11(*param_1,bVar1);
        }
      }
      uVar2 = (ushort)*pbVar3;
      pbVar4 = pbVar3 + 1;
      if ((*(byte *)((int)&DAT_004ae968 + uVar2 + 1) & 4) != 0) {
        bVar1 = *pbVar4;
        if (bVar1 == 0) {
          uVar2 = 0;
        }
        else {
          pbVar4 = pbVar3 + 2;
          uVar2 = CONCAT11(*pbVar3,bVar1);
        }
      }
      if ((ushort)param_2 != uVar2) break;
      pbVar3 = pbVar4;
      param_1 = pbVar5;
      if ((ushort)param_2 == 0) {
        FUN_0045b7b0(0x19);
        return 0;
      }
    }
    FUN_0045b7b0(0x19);
    return (-(uint)(uVar2 < (ushort)param_2) & 2) - 1;
  }
  while( true ) {
    bVar1 = *param_1;
    bVar6 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = param_1[1];
    bVar6 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar6) - (uint)(bVar6 != 0);
}


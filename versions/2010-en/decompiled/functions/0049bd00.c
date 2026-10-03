
int FUN_0049bd00(byte *param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  if (DAT_005385c4 != 0) {
    FUN_0049fe10(0x19);
    while( true ) {
      uVar2 = (ushort)*param_1;
      pbVar5 = param_1 + 1;
      if ((*(byte *)((int)&DAT_005384c0 + uVar2 + 1) & 4) != 0) {
        bVar1 = *pbVar5;
        if (bVar1 == 0) {
          uVar2 = 0;
        }
        else {
          pbVar5 = param_1 + 2;
          uVar2 = CONCAT11(*param_1,bVar1);
        }
      }
      uVar3 = (ushort)*param_2;
      pbVar4 = param_2 + 1;
      if ((*(byte *)((int)&DAT_005384c0 + uVar3 + 1) & 4) != 0) {
        bVar1 = *pbVar4;
        if (bVar1 == 0) {
          uVar3 = 0;
        }
        else {
          pbVar4 = param_2 + 2;
          uVar3 = CONCAT11(*param_2,bVar1);
        }
      }
      if (uVar2 != uVar3) break;
      param_2 = pbVar4;
      param_1 = pbVar5;
      if (uVar2 == 0) {
        FUN_0049fe90(0x19);
        return 0;
      }
    }
    FUN_0049fe90(0x19);
    return (-(uint)(uVar3 < uVar2) & 2) - 1;
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


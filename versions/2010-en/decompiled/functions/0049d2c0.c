
byte * FUN_0049d2c0(byte *param_1,uint param_2)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  pbVar5 = (byte *)0x0;
  if (DAT_005385c4 == 0) {
    pbVar5 = (byte *)_strrchr((char *)param_1,param_2);
    return pbVar5;
  }
  FUN_0049fe10(0x19);
  do {
    bVar3 = *param_1;
    if ((*(byte *)((int)&DAT_005384c0 + bVar3 + 1) & 4) == 0) {
      pbVar4 = param_1;
      bVar2 = bVar3;
      if (param_2 == bVar3) {
LAB_0049d338:
        pbVar5 = pbVar4;
        bVar3 = bVar2;
      }
    }
    else {
      bVar2 = param_1[1];
      pbVar4 = param_1 + 1;
      if (bVar2 == 0) {
        bVar3 = bVar2;
        if (pbVar5 == (byte *)0x0) goto LAB_0049d338;
      }
      else {
        uVar1 = CONCAT11(bVar3,bVar2);
        bVar3 = bVar2;
        if (param_2 == uVar1) {
          pbVar5 = param_1;
        }
      }
    }
    param_1 = pbVar4 + 1;
    if (bVar3 == 0) {
      FUN_0049fe90(0x19);
      return pbVar5;
    }
  } while( true );
}


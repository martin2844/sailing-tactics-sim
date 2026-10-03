
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_0045de70(byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  iVar2 = _DAT_004afde8;
  if (DAT_004aec48 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_0045debe;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_0045debe:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_004afde8 = _DAT_004afde8 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_004afde4;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_004afde8 = iVar2;
      FUN_0045b730(0x13);
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_0045df1f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_0045e1e0(uVar8);
      uVar7 = FUN_0045e1e0(uVar7);
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_0045df1f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_004afde8 = _DAT_004afde8 + -1;
      UNLOCK();
    }
    else {
      FUN_0045b7b0(0x13);
    }
  }
  return uVar7;
}


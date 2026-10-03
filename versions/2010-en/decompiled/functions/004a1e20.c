
void FUN_004a1e20(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  DWORD DVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  
  FUN_0049fe10(0xc);
  DAT_005387c0 = 0;
  DAT_004f0520 = 0xffffffff;
  DAT_004f0510 = 0xffffffff;
  pbVar3 = (byte *)FUN_004a3b10(&DAT_004d0e38);
  if (pbVar3 == (byte *)0x0) {
    FUN_0049fe90(0xc);
    DVar4 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_005387c8);
    if (DVar4 == 0xffffffff) {
      return;
    }
    DAT_005387c0 = 1;
    DAT_004f0478 = DAT_005387c8 * 0x3c;
    if (DAT_0053880e != 0) {
      DAT_004f0478 = DAT_004f0478 + DAT_0053881c * 0x3c;
    }
    if ((DAT_00538862 == 0) || (DAT_00538870 == 0)) {
      DAT_004f047c = 0;
      DAT_004f0480 = 0;
    }
    else {
      DAT_004f047c = 1;
      DAT_004f0480 = (DAT_00538870 - DAT_0053881c) * 0x3c;
    }
    FUN_004a3860(PTR_DAT_004f0508,&DAT_005387cc,0x40);
    FUN_004a3860(PTR_DAT_004f050c,&DAT_00538820,0x40);
    PTR_DAT_004f050c[0x3f] = 0;
    PTR_DAT_004f0508[0x3f] = 0;
    return;
  }
  if (*pbVar3 != 0) {
    pbVar8 = pbVar3;
    pbVar9 = DAT_00538874;
    if (DAT_00538874 != (byte *)0x0) {
      do {
        bVar1 = *pbVar8;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_004a1f77:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_004a1f7c;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_004a1f77;
        pbVar8 = pbVar8 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_004a1f7c:
      if (iVar5 == 0) goto LAB_004a20e9;
    }
    FUN_0049bfd0(DAT_00538874);
    uVar6 = 0xffffffff;
    pbVar8 = pbVar3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar1 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar1 != 0);
    DAT_00538874 = (byte *)FUN_0049bf00(~uVar6);
    if (DAT_00538874 != (byte *)0x0) {
      uVar6 = 0xffffffff;
      pbVar8 = pbVar3;
      do {
        pbVar9 = pbVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pbVar9 = pbVar8 + 1;
        bVar1 = *pbVar8;
        pbVar8 = pbVar9;
      } while (bVar1 != 0);
      uVar6 = ~uVar6;
      pbVar8 = pbVar9 + -uVar6;
      pbVar9 = DAT_00538874;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
        pbVar8 = pbVar8 + 4;
        pbVar9 = pbVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pbVar9 = *pbVar8;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      }
      FUN_0049fe90(0xc);
      _strncpy(PTR_DAT_004f0508,(char *)pbVar3,3);
      pbVar8 = pbVar3 + 3;
      PTR_DAT_004f0508[3] = 0;
      bVar1 = *pbVar8;
      if (bVar1 == 0x2d) {
        pbVar8 = pbVar3 + 4;
      }
      iVar5 = FUN_0049ca80(pbVar8);
      DAT_004f0478 = iVar5 * 0xe10;
      for (; (bVar2 = *pbVar8, bVar2 == 0x2b || (('/' < (char)bVar2 && ((char)bVar2 < ':'))));
          pbVar8 = pbVar8 + 1) {
      }
      if (*pbVar8 == 0x3a) {
        pbVar8 = pbVar8 + 1;
        iVar5 = FUN_0049ca80(pbVar8);
        DAT_004f0478 = DAT_004f0478 + iVar5 * 0x3c;
        bVar2 = *pbVar8;
        while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
          pbVar3 = pbVar8 + 1;
          pbVar8 = pbVar8 + 1;
          bVar2 = *pbVar3;
        }
        if (*pbVar8 == 0x3a) {
          pbVar8 = pbVar8 + 1;
          iVar5 = FUN_0049ca80(pbVar8);
          DAT_004f0478 = DAT_004f0478 + iVar5;
          bVar2 = *pbVar8;
          while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
            pbVar3 = pbVar8 + 1;
            pbVar8 = pbVar8 + 1;
            bVar2 = *pbVar3;
          }
        }
      }
      if (bVar1 == 0x2d) {
        DAT_004f0478 = -DAT_004f0478;
      }
      DAT_004f047c = (int)(char)*pbVar8;
      if (DAT_004f047c == 0) {
        *PTR_DAT_004f050c = 0;
        return;
      }
      _strncpy(PTR_DAT_004f050c,(char *)pbVar8,3);
      PTR_DAT_004f050c[3] = 0;
      return;
    }
  }
LAB_004a20e9:
  FUN_0049fe90(0xc);
  return;
}


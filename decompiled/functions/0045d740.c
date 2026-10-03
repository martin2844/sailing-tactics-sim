
void FUN_0045d740(void)

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
  
  FUN_0045b730(0xc);
  DAT_004aec68 = 0;
  DAT_004a2360 = 0xffffffff;
  DAT_004a2350 = 0xffffffff;
  pbVar3 = (byte *)FUN_0045f430(&DAT_00489190);
  if (pbVar3 == (byte *)0x0) {
    FUN_0045b7b0(0xc);
    DVar4 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_004aec70);
    if (DVar4 == 0xffffffff) {
      return;
    }
    DAT_004aec68 = 1;
    DAT_004a22b8 = DAT_004aec70 * 0x3c;
    if (DAT_004aecb6 != 0) {
      DAT_004a22b8 = DAT_004a22b8 + DAT_004aecc4 * 0x3c;
    }
    if ((DAT_004aed0a == 0) || (DAT_004aed18 == 0)) {
      DAT_004a22bc = 0;
      DAT_004a22c0 = 0;
    }
    else {
      DAT_004a22bc = 1;
      DAT_004a22c0 = (DAT_004aed18 - DAT_004aecc4) * 0x3c;
    }
    FUN_0045f180(PTR_DAT_004a2348,(LPCWSTR)&DAT_004aec74,0x40);
    FUN_0045f180(PTR_DAT_004a234c,(LPCWSTR)&DAT_004aecc8,0x40);
    PTR_DAT_004a234c[0x3f] = 0;
    PTR_DAT_004a2348[0x3f] = 0;
    return;
  }
  if (*pbVar3 != 0) {
    pbVar8 = pbVar3;
    pbVar9 = DAT_004aed1c;
    if (DAT_004aed1c != (byte *)0x0) {
      do {
        bVar1 = *pbVar8;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_0045d897:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0045d89c;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_0045d897;
        pbVar8 = pbVar8 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_0045d89c:
      if (iVar5 == 0) goto LAB_0045da09;
    }
    FUN_00457710(DAT_004aed1c);
    uVar6 = 0xffffffff;
    pbVar8 = pbVar3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar1 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar1 != 0);
    DAT_004aed1c = (byte *)FUN_00457640(~uVar6);
    if (DAT_004aed1c != (byte *)0x0) {
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
      pbVar9 = DAT_004aed1c;
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
      FUN_0045b7b0(0xc);
      _strncpy(PTR_DAT_004a2348,(char *)pbVar3,3);
      pbVar8 = pbVar3 + 3;
      PTR_DAT_004a2348[3] = 0;
      bVar1 = *pbVar8;
      if (bVar1 == 0x2d) {
        pbVar8 = pbVar3 + 4;
      }
      iVar5 = FUN_004581c0(pbVar8);
      DAT_004a22b8 = iVar5 * 0xe10;
      for (; (bVar2 = *pbVar8, bVar2 == 0x2b || (('/' < (char)bVar2 && ((char)bVar2 < ':'))));
          pbVar8 = pbVar8 + 1) {
      }
      if (*pbVar8 == 0x3a) {
        pbVar8 = pbVar8 + 1;
        iVar5 = FUN_004581c0(pbVar8);
        DAT_004a22b8 = DAT_004a22b8 + iVar5 * 0x3c;
        bVar2 = *pbVar8;
        while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
          pbVar3 = pbVar8 + 1;
          pbVar8 = pbVar8 + 1;
          bVar2 = *pbVar3;
        }
        if (*pbVar8 == 0x3a) {
          pbVar8 = pbVar8 + 1;
          iVar5 = FUN_004581c0(pbVar8);
          DAT_004a22b8 = DAT_004a22b8 + iVar5;
          bVar2 = *pbVar8;
          while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
            pbVar3 = pbVar8 + 1;
            pbVar8 = pbVar8 + 1;
            bVar2 = *pbVar3;
          }
        }
      }
      if (bVar1 == 0x2d) {
        DAT_004a22b8 = -DAT_004a22b8;
      }
      DAT_004a22bc = (int)(char)*pbVar8;
      if (DAT_004a22bc == 0) {
        *PTR_DAT_004a234c = 0;
        return;
      }
      _strncpy(PTR_DAT_004a234c,(char *)pbVar8,3);
      PTR_DAT_004a234c[3] = 0;
      return;
    }
  }
LAB_0045da09:
  FUN_0045b7b0(0xc);
  return;
}


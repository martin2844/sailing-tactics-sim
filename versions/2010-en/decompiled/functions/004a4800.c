
undefined4 FUN_004a4800(void)

{
  BYTE *pBVar1;
  undefined2 *puVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  BYTE *pBVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined2 *local_1c;
  undefined2 *local_18;
  _cpinfo local_14;
  
  iVar10 = 0;
  puVar9 = (undefined2 *)0x0;
  if (DAT_005387a0 == 0) {
    PTR_DAT_004f0250 = &DAT_004f025a;
    PTR_DAT_004f0254 = &DAT_004f025a;
    FUN_0049bfd0(DAT_005388ac);
    FUN_0049bfd0(DAT_005388b0);
    DAT_005388ac = (undefined2 *)0x0;
    DAT_005388b0 = (undefined2 *)0x0;
    return 0;
  }
  if ((DAT_005387b0 != 0) || (iVar3 = FUN_004a5ee0(0,DAT_005388c4,0xb,&DAT_005387b0), iVar3 == 0)) {
    local_18 = (undefined2 *)FUN_0049bf00(0x202);
    local_1c = (undefined2 *)FUN_0049bf00(0x202);
    iVar10 = FUN_0049bf00(0x101);
    puVar9 = (undefined2 *)FUN_0049bf00(0x202);
    if ((local_18 != (undefined2 *)0x0) &&
       (((local_1c != (undefined2 *)0x0 && (iVar10 != 0)) && (puVar9 != (undefined2 *)0x0)))) {
      iVar3 = 0;
      do {
        *(char *)(iVar3 + iVar10) = (char)iVar3;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x100);
      BVar4 = GetCPInfo(DAT_005387b0,&local_14);
      if ((BVar4 != 0) && (local_14.MaxCharSize < 3)) {
        DAT_004f045c = local_14.MaxCharSize & 0xffff;
        if ((1 < DAT_004f045c) && (local_14.LeadByte[0] != '\0')) {
          pBVar6 = local_14.LeadByte + 1;
          do {
            if (*pBVar6 == 0) break;
            uVar5 = (uint)pBVar6[-1];
            if (uVar5 <= *pBVar6) {
              do {
                *(undefined1 *)(uVar5 + iVar10) = 0;
                uVar5 = uVar5 + 1;
              } while ((int)uVar5 <= (int)(uint)*pBVar6);
            }
            pBVar1 = pBVar6 + 1;
            pBVar6 = pBVar6 + 2;
          } while (*pBVar1 != 0);
        }
        puVar2 = local_18 + 1;
        iVar3 = FUN_004a1cb0(1,iVar10,0x100,puVar2,0,0);
        if (iVar3 != 0) {
          *local_18 = 0;
          iVar3 = 0;
          puVar7 = puVar9;
          do {
            *puVar7 = (short)iVar3;
            puVar7 = puVar7 + 1;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 0x100);
          puVar7 = local_1c + 1;
          iVar3 = FUN_004a1b20(1,puVar9,0x100,puVar7,0,0);
          if (iVar3 != 0) {
            *local_1c = 0;
            if ((1 < (int)DAT_004f045c) && (local_14.LeadByte[0] != '\0')) {
              pBVar6 = local_14.LeadByte + 1;
              do {
                if (*pBVar6 == 0) break;
                uVar5 = (uint)pBVar6[-1];
                if (uVar5 <= *pBVar6) {
                  puVar8 = local_18 + uVar5 + 1;
                  do {
                    *puVar8 = 0x8000;
                    uVar5 = uVar5 + 1;
                    puVar8 = puVar8 + 1;
                  } while ((int)uVar5 <= (int)(uint)*pBVar6);
                }
                pBVar1 = pBVar6 + 1;
                pBVar6 = pBVar6 + 2;
              } while (*pBVar1 != 0);
            }
            PTR_DAT_004f0250 = (undefined *)puVar2;
            PTR_DAT_004f0254 = (undefined *)puVar7;
            if (DAT_005388ac != (undefined2 *)0x0) {
              FUN_0049bfd0(DAT_005388ac);
            }
            DAT_005388ac = local_18;
            if (DAT_005388b0 != (undefined2 *)0x0) {
              FUN_0049bfd0(DAT_005388b0);
            }
            DAT_005388b0 = local_1c;
            FUN_0049bfd0(iVar10);
            FUN_0049bfd0(puVar9);
            return 0;
          }
        }
      }
    }
  }
  FUN_0049bfd0(local_18);
  FUN_0049bfd0(local_1c);
  FUN_0049bfd0(iVar10);
  FUN_0049bfd0(puVar9);
  return 1;
}


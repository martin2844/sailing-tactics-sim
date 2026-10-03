
undefined4 FUN_00460120(void)

{
  BYTE *pBVar1;
  LPWORD pWVar2;
  LPWORD pWVar3;
  int iVar4;
  BOOL BVar5;
  uint uVar6;
  BYTE *pBVar7;
  LPCWSTR pWVar8;
  undefined2 *puVar9;
  LPCWSTR pWVar10;
  LPCSTR pCVar11;
  undefined2 *local_1c;
  undefined2 *local_18;
  _cpinfo local_14;
  
  pCVar11 = (LPCSTR)0x0;
  pWVar10 = (LPCWSTR)0x0;
  if (DAT_004aec48 == 0) {
    PTR_DAT_004a2090 = &DAT_004a209a;
    PTR_DAT_004a2094 = &DAT_004a209a;
    FUN_00457710((undefined *)DAT_004aed54);
    FUN_00457710((undefined *)DAT_004aed58);
    DAT_004aed54 = (undefined2 *)0x0;
    DAT_004aed58 = (undefined2 *)0x0;
    return 0;
  }
  if ((DAT_004aec58 != 0) ||
     (iVar4 = FUN_00461800(0,(uint)DAT_004aed6c,0xb,(char *)&DAT_004aec58), iVar4 == 0)) {
    local_18 = (undefined2 *)FUN_00457640(0x202);
    local_1c = (undefined2 *)FUN_00457640(0x202);
    pCVar11 = (LPCSTR)FUN_00457640(0x101);
    pWVar10 = (LPCWSTR)FUN_00457640(0x202);
    if ((local_18 != (undefined2 *)0x0) &&
       (((local_1c != (undefined2 *)0x0 && (pCVar11 != (LPCSTR)0x0)) && (pWVar10 != (LPCWSTR)0x0))))
    {
      iVar4 = 0;
      do {
        pCVar11[iVar4] = (CHAR)iVar4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x100);
      BVar5 = GetCPInfo(DAT_004aec58,&local_14);
      if ((BVar5 != 0) && (local_14.MaxCharSize < 3)) {
        DAT_004a229c = local_14.MaxCharSize & 0xffff;
        if ((1 < DAT_004a229c) && (local_14.LeadByte[0] != '\0')) {
          pBVar7 = local_14.LeadByte + 1;
          do {
            if (*pBVar7 == 0) break;
            uVar6 = (uint)pBVar7[-1];
            if (uVar6 <= *pBVar7) {
              do {
                pCVar11[uVar6] = '\0';
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 <= (int)(uint)*pBVar7);
            }
            pBVar1 = pBVar7 + 1;
            pBVar7 = pBVar7 + 2;
          } while (*pBVar1 != 0);
        }
        pWVar2 = local_18 + 1;
        BVar5 = FUN_0045d5d0(1,pCVar11,0x100,pWVar2,0,0);
        if (BVar5 != 0) {
          *local_18 = 0;
          iVar4 = 0;
          pWVar8 = pWVar10;
          do {
            *pWVar8 = (WCHAR)iVar4;
            pWVar8 = pWVar8 + 1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < 0x100);
          pWVar3 = local_1c + 1;
          BVar5 = FUN_0045d440(1,pWVar10,0x100,pWVar3,0,0);
          if (BVar5 != 0) {
            *local_1c = 0;
            if ((1 < (int)DAT_004a229c) && (local_14.LeadByte[0] != '\0')) {
              pBVar7 = local_14.LeadByte + 1;
              do {
                if (*pBVar7 == 0) break;
                uVar6 = (uint)pBVar7[-1];
                if (uVar6 <= *pBVar7) {
                  puVar9 = local_18 + uVar6 + 1;
                  do {
                    *puVar9 = 0x8000;
                    uVar6 = uVar6 + 1;
                    puVar9 = puVar9 + 1;
                  } while ((int)uVar6 <= (int)(uint)*pBVar7);
                }
                pBVar1 = pBVar7 + 1;
                pBVar7 = pBVar7 + 2;
              } while (*pBVar1 != 0);
            }
            PTR_DAT_004a2090 = (undefined *)pWVar2;
            PTR_DAT_004a2094 = (undefined *)pWVar3;
            if (DAT_004aed54 != (undefined2 *)0x0) {
              FUN_00457710((undefined *)DAT_004aed54);
            }
            DAT_004aed54 = local_18;
            if (DAT_004aed58 != (undefined2 *)0x0) {
              FUN_00457710((undefined *)DAT_004aed58);
            }
            DAT_004aed58 = local_1c;
            FUN_00457710(pCVar11);
            FUN_00457710((undefined *)pWVar10);
            return 0;
          }
        }
      }
    }
  }
  FUN_00457710((undefined *)local_18);
  FUN_00457710((undefined *)local_1c);
  FUN_00457710(pCVar11);
  FUN_00457710((undefined *)pWVar10);
  return 1;
}


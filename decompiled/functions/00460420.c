
undefined4 __cdecl FUN_00460420(DWORD *param_1)

{
  DWORD *pDVar1;
  bool bVar2;
  DWORD *pDVar3;
  DWORD *pDVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  undefined4 *puVar9;
  bool bVar10;
  DWORD local_4;
  
  pDVar3 = param_1;
  bVar2 = false;
  pDVar4 = param_1;
  switch(param_1) {
  case (DWORD *)0x2:
    puVar9 = &DAT_004aed84;
    bVar2 = true;
    pcVar8 = DAT_004aed84;
    break;
  default:
    return 0xffffffff;
  case (DWORD *)0x4:
  case (DWORD *)0x8:
  case (DWORD *)0xb:
    pDVar4 = FUN_00459ed0();
    uVar5 = FUN_00460630((int)param_1,pDVar4[0x14]);
    puVar9 = (undefined4 *)(uVar5 + 8);
    pcVar8 = (code *)*puVar9;
    break;
  case (DWORD *)0xf:
    puVar9 = &DAT_004aed90;
    bVar2 = true;
    pcVar8 = DAT_004aed90;
    break;
  case (DWORD *)0x15:
    puVar9 = &DAT_004aed88;
    bVar2 = true;
    pcVar8 = DAT_004aed88;
    break;
  case (DWORD *)0x16:
    puVar9 = &DAT_004aed8c;
    bVar2 = true;
    pcVar8 = DAT_004aed8c;
  }
  if (bVar2) {
    FUN_0045b730(1);
  }
  if (pcVar8 == (code *)0x1) {
    if (!bVar2) {
      return 0;
    }
    FUN_0045b7b0(1);
    return 0;
  }
  if (pcVar8 == (code *)0x0) {
    if (bVar2) {
      FUN_0045b7b0(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    pDVar1 = (DWORD *)pDVar4[0x15];
    bVar10 = param_1 == (DWORD *)0x8;
    pDVar4[0x15] = 0;
    param_1 = pDVar1;
    if (bVar10) {
      local_4 = pDVar4[0x16];
      pDVar4[0x16] = 0x8c;
      goto LAB_00460553;
    }
  }
  else {
LAB_00460553:
    if (pDVar3 == (DWORD *)0x8) {
      if (DAT_0049fed8 < DAT_0049fedc + DAT_0049fed8) {
        iVar7 = DAT_0049fed8 * 0xc;
        iVar6 = DAT_0049fed8;
        do {
          iVar6 = iVar6 + 1;
          *(undefined4 *)(pDVar4[0x14] + 8 + iVar7) = 0;
          iVar7 = iVar7 + 0xc;
        } while (iVar6 < DAT_0049fedc + DAT_0049fed8);
      }
      goto LAB_00460598;
    }
  }
  *puVar9 = 0;
LAB_00460598:
  if (bVar2) {
    FUN_0045b7b0(1);
  }
  if (pDVar3 == (DWORD *)0x8) {
    (*pcVar8)(8,pDVar4[0x16]);
  }
  else {
    (*pcVar8)(pDVar3);
    if ((pDVar3 != (DWORD *)0xb) && (pDVar3 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar4[0x15] = (DWORD)param_1;
  if (pDVar3 == (DWORD *)0x8) {
    pDVar4[0x16] = local_4;
  }
  return 0;
}


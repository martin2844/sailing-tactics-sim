
int * FUN_004a03a0(uint param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  undefined **ppuVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  
  piVar10 = (int *)PTR_LOOP_004f0240;
  do {
    if (piVar10[4] != -1) {
      piVar5 = (int *)piVar10[2];
      iVar9 = ((int)piVar5 + (-0x18 - (int)piVar10) >> 3) * 0x1000 + piVar10[4];
      for (; piVar5 < piVar10 + 0x806; piVar5 = piVar5 + 2) {
        if (((int)param_1 <= *piVar5) && (param_1 < (uint)piVar5[1])) {
          piVar3 = (int *)FUN_004a05e0(iVar9,*piVar5,param_1);
          if (piVar3 != (int *)0x0) {
            PTR_LOOP_004f0240 = (undefined *)piVar10;
            *piVar5 = *piVar5 - param_1;
            piVar10[2] = (int)piVar5;
            return piVar3;
          }
          piVar5[1] = param_1;
        }
        iVar9 = iVar9 + 0x1000;
      }
      piVar3 = (int *)piVar10[2];
      iVar9 = piVar10[4];
      for (piVar5 = piVar10 + 6; piVar5 < piVar3; piVar5 = piVar5 + 2) {
        if (((int)param_1 <= *piVar5) && (param_1 < (uint)piVar5[1])) {
          piVar4 = (int *)FUN_004a05e0(iVar9,*piVar5,param_1);
          if (piVar4 != (int *)0x0) {
            PTR_LOOP_004f0240 = (undefined *)piVar10;
            *piVar5 = *piVar5 - param_1;
            piVar10[2] = (int)piVar5;
            return piVar4;
          }
          piVar5[1] = param_1;
        }
        iVar9 = iVar9 + 0x1000;
      }
    }
    piVar10 = (int *)*piVar10;
  } while (piVar10 != (int *)PTR_LOOP_004f0240);
  ppuVar8 = &PTR_LOOP_004ee220;
  while ((ppuVar8[4] == (undefined *)0xffffffff || (ppuVar8[3] == (undefined *)0x0))) {
    ppuVar8 = (undefined **)*ppuVar8;
    if (ppuVar8 == &PTR_LOOP_004ee220) {
      puVar6 = (undefined *)FUN_004a0040();
      if (puVar6 == (undefined *)0x0) {
        return (int *)0x0;
      }
      piVar10 = *(int **)(puVar6 + 0x10);
      *(char *)(piVar10 + 2) = (char)param_1;
      PTR_LOOP_004f0240 = puVar6;
      *piVar10 = (int)piVar10 + param_1 + 8;
      piVar10[1] = 0xf0 - param_1;
      *(uint *)(puVar6 + 0x18) = *(int *)(puVar6 + 0x18) - (param_1 & 0xff);
      return piVar10 + 0x40;
    }
  }
  ppuVar2 = (undefined **)ppuVar8[3];
  puVar6 = *ppuVar2;
  piVar10 = (int *)(ppuVar8[4] + ((int)ppuVar2 + (-0x18 - (int)ppuVar8) >> 3) * 0x1000);
  ppuVar7 = ppuVar2;
  for (iVar9 = 0; (puVar6 == (undefined *)0xffffffff && (iVar9 < 0x10)); iVar9 = iVar9 + 1) {
    puVar6 = ppuVar7[2];
    ppuVar7 = ppuVar7 + 2;
  }
  piVar5 = VirtualAlloc(piVar10,iVar9 << 0xc,0x1000,4);
  if (piVar5 != piVar10) {
    return (int *)0x0;
  }
  ppuVar7 = ppuVar2;
  if (0 < iVar9) {
    piVar5 = piVar10 + 1;
    do {
      *piVar5 = 0xf0;
      piVar5[-1] = (int)(piVar5 + 1);
      *(undefined1 *)(piVar5 + 0x3d) = 0xff;
      *ppuVar7 = (undefined *)0xf0;
      ppuVar7[1] = (undefined *)0xf1;
      piVar5 = piVar5 + 0x400;
      ppuVar7 = ppuVar7 + 2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  ppuVar1 = ppuVar8 + 0x806;
  bVar11 = false;
  if (ppuVar7 < ppuVar1) {
    do {
      if (*ppuVar7 == (undefined *)0xffffffff) break;
      ppuVar7 = ppuVar7 + 2;
    } while (ppuVar7 < ppuVar1);
    bVar11 = ppuVar7 < ppuVar1;
  }
  PTR_LOOP_004f0240 = (undefined *)ppuVar8;
  ppuVar8[3] = (undefined *)(-(uint)bVar11 & (uint)ppuVar7);
  *(char *)(piVar10 + 2) = (char)param_1;
  ppuVar8[2] = (undefined *)ppuVar2;
  *ppuVar2 = *ppuVar2 + -param_1;
  piVar10[1] = piVar10[1] - param_1;
  *piVar10 = (int)piVar10 + param_1 + 8;
  return piVar10 + 0x40;
}


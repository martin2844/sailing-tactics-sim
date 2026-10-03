
undefined4 __thiscall FUN_004b1972(undefined4 *param_1,LPCSTR param_2,undefined2 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  WCHAR local_54 [32];
  undefined2 *local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_1[1] == 0) {
    uVar2 = 0;
  }
  else {
    local_c = param_1;
    puVar3 = GlobalLock((HGLOBAL)*param_1);
    local_8 = (uint)(*(short *)((int)puVar3 + 2) == -1);
    if (*(short *)((int)puVar3 + 2) == -1) {
      local_10 = puVar3[3];
    }
    else {
      local_10 = *puVar3;
    }
    local_10 = local_10 & 0x40;
    iVar8 = (-(uint)(local_8 != 0) & 2) + 1;
    if (local_8 == 0) {
      *puVar3 = *puVar3 | 0x40;
    }
    else {
      puVar3[3] = puVar3[3] | 0x40;
    }
    iVar4 = MultiByteToWideChar(0,0,param_2,-1,local_54,0x20);
    iVar4 = iVar8 * 2 + iVar4 * 2;
    puVar5 = (undefined2 *)FUN_004b17f6(puVar3);
    iVar6 = 0;
    local_14 = puVar5;
    if (local_10 != 0) {
      iVar6 = FUN_0049c650(puVar5 + iVar8);
      iVar6 = iVar8 * 2 + 2 + iVar6 * 2;
    }
    local_10 = iVar6 + 3 + (int)puVar5 & 0xfffffffc;
    uVar9 = (int)puVar5 + iVar4 + 3 & 0xfffffffc;
    if (local_8 == 0) {
      cVar7 = (char)puVar3[2];
    }
    else {
      cVar7 = (char)puVar3[4];
    }
    if ((iVar4 != iVar6) && (cVar7 != '\0')) {
      FUN_0049c740(uVar9,local_10,(int)puVar3 + (local_c[1] - local_10));
    }
    *local_14 = param_3;
    FUN_0049c740(local_14 + iVar8,local_54,iVar4 + iVar8 * -2);
    puVar1 = local_c;
    local_c[1] = local_c[1] + (uVar9 - local_10);
    GlobalUnlock((HGLOBAL)*local_c);
    puVar1[2] = 0;
    uVar2 = 1;
  }
  return uVar2;
}


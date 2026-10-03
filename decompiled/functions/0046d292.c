
undefined4 __thiscall FUN_0046d292(void *this,LPCSTR param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  undefined4 *puVar10;
  WCHAR local_54 [32];
  undefined2 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (*(int *)((int)this + 4) == 0) {
    uVar2 = 0;
  }
  else {
    local_c = this;
    puVar3 = GlobalLock(*(HGLOBAL *)this);
    local_8 = (uint)(*(short *)((int)puVar3 + 2) == -1);
    if (*(short *)((int)puVar3 + 2) == -1) {
      uVar4 = puVar3[3];
    }
    else {
      uVar4 = *puVar3;
    }
    local_10 = (undefined4 *)(uVar4 & 0x40);
    iVar9 = (-(uint)(local_8 != 0) & 2) + 1;
    if (local_8 == 0) {
      *puVar3 = *puVar3 | 0x40;
    }
    else {
      puVar3[3] = puVar3[3] | 0x40;
    }
    iVar5 = MultiByteToWideChar(0,0,param_1,-1,local_54,0x20);
    iVar5 = iVar9 * 2 + iVar5 * 2;
    puVar6 = (undefined2 *)FUN_0046d116((int)puVar3);
    iVar7 = 0;
    local_14 = puVar6;
    if (local_10 != (undefined4 *)0x0) {
      iVar7 = FUN_00457d90(puVar6 + iVar9);
      iVar7 = iVar9 * 2 + 2 + iVar7 * 2;
    }
    local_10 = (undefined4 *)(iVar7 + 3 + (int)puVar6 & 0xfffffffc);
    puVar10 = (undefined4 *)((int)puVar6 + iVar5 + 3 & 0xfffffffc);
    if (local_8 == 0) {
      cVar8 = (char)puVar3[2];
    }
    else {
      cVar8 = (char)puVar3[4];
    }
    if ((iVar5 != iVar7) && (cVar8 != '\0')) {
      FUN_00457e80(puVar10,local_10,(int)puVar3 + (local_c[1] - (int)local_10));
    }
    *local_14 = param_2;
    FUN_00457e80((undefined4 *)(local_14 + iVar9),(undefined4 *)local_54,iVar5 + iVar9 * -2);
    puVar1 = local_c;
    local_c[1] = (int)puVar10 + (local_c[1] - (int)local_10);
    GlobalUnlock((HGLOBAL)*local_c);
    puVar1[2] = 0;
    uVar2 = 1;
  }
  return uVar2;
}


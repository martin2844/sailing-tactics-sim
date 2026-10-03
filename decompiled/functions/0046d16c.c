
int __cdecl FUN_0046d16c(uint *param_1)

{
  short *psVar1;
  int iVar2;
  ushort *puVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  bool bVar7;
  
  bVar7 = *(short *)((int)param_1 + 2) == -1;
  psVar1 = (short *)FUN_0046d116((int)param_1);
  if (*(short *)((int)param_1 + 2) == -1) {
    uVar6 = param_1[3];
  }
  else {
    uVar6 = *param_1;
  }
  if ((uVar6 & 0x40) != 0) {
    iVar2 = FUN_00457d90(psVar1 + (-(uint)bVar7 & 2) + 1);
    psVar1 = psVar1 + (-(uint)bVar7 & 2) + 1 + iVar2 + 1;
  }
  if (bVar7) {
    bVar4 = (byte)param_1[4];
  }
  else {
    bVar4 = (byte)param_1[2];
  }
  if (bVar4 != 0) {
    uVar6 = (uint)bVar4;
    do {
      puVar3 = (ushort *)(((int)psVar1 + 3U & 0xfffffffc) + (-(uint)bVar7 & 6) + 0x12);
      uVar5 = *puVar3;
      if (uVar5 == 0xffff) {
        puVar3 = puVar3 + 2;
      }
      else {
        while (puVar3 = puVar3 + 1, uVar5 != 0) {
          uVar5 = *puVar3;
        }
      }
      uVar5 = *puVar3;
      if (uVar5 == 0xffff) {
        puVar3 = puVar3 + 2;
      }
      else {
        while (puVar3 = puVar3 + 1, uVar5 != 0) {
          uVar5 = *puVar3;
        }
      }
      uVar6 = uVar6 - 1;
      psVar1 = (short *)((int)puVar3 + *puVar3 + 2);
    } while (uVar6 != 0);
  }
  return (int)psVar1 - (int)param_1;
}


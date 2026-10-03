
undefined4 __fastcall FUN_00467b78(int param_1)

{
  short sVar1;
  HMODULE hModule;
  int iVar2;
  HRSRC hResInfo;
  HGLOBAL hResData;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  short sVar6;
  
  puVar3 = *(uint **)(param_1 + 0x48);
  hResData = *(HGLOBAL *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x40) != 0) {
    iVar2 = FUN_0047b918();
    hModule = *(HMODULE *)(iVar2 + 0xc);
    hResInfo = FindResourceA(hModule,*(LPCSTR *)(param_1 + 0x40),&DAT_00000005);
    hResData = LoadResource(hModule,hResInfo);
  }
  if (hResData != (HGLOBAL)0x0) {
    puVar3 = LockResource(hResData);
  }
  uVar4 = 1;
  if (puVar3 != (uint *)0x0) {
    uVar5 = *puVar3;
    if (*(short *)((int)puVar3 + 2) == -1) {
      uVar5 = puVar3[3];
      sVar1 = *(short *)((int)puVar3 + 0x12);
      sVar6 = (short)puVar3[5];
    }
    else {
      sVar1 = *(short *)((int)puVar3 + 10);
      sVar6 = (short)puVar3[3];
    }
    if ((((uVar5 & 0x1801) == 0) && (sVar1 == 0)) && (sVar6 == 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  return uVar4;
}


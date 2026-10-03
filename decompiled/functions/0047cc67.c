
void __fastcall FUN_0047cc67(int param_1)

{
  byte *pbVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  CHAR *pCVar5;
  CHAR local_310 [256];
  byte local_210 [260];
  CHAR local_10c [260];
  byte *local_8;
  
  iVar2 = FUN_0047b918();
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0x68);
  GetModuleFileNameA(*(HMODULE *)(param_1 + 0x68),(LPSTR)local_210,0x104);
  local_8 = FUN_00458bc0(local_210,0x2e);
  *local_8 = 0;
  FUN_0047cd84(local_210,local_10c,0x104);
  if (*(int *)(param_1 + 0x88) == 0) {
    pcVar3 = FUN_00457bc0(local_10c);
    *(char **)(param_1 + 0x88) = pcVar3;
  }
  if (*(int *)(param_1 + 0x78) == 0) {
    iVar4 = FUN_0046d8e5(0xe000,local_310,0x100);
    if (iVar4 == 0) {
      pCVar5 = *(CHAR **)(param_1 + 0x88);
    }
    else {
      pCVar5 = local_310;
    }
    pcVar3 = FUN_00457bc0(pCVar5);
    *(char **)(param_1 + 0x78) = pcVar3;
  }
  pbVar1 = local_8;
  *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x78);
  if (*(int *)(param_1 + 0x8c) == 0) {
    lstrcpyA((LPSTR)local_8,".HLP");
    pcVar3 = FUN_00457bc0((char *)local_210);
    *(char **)(param_1 + 0x8c) = pcVar3;
    *pbVar1 = 0;
  }
  if (*(int *)(param_1 + 0x90) == 0) {
    lstrcatA(local_10c,".INI");
    pcVar3 = FUN_00457bc0(local_10c);
    *(char **)(param_1 + 0x90) = pcVar3;
  }
  return;
}


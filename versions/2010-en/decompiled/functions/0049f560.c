
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049f560(void)

{
  int iVar1;
  char *pcVar2;
  int local_8;
  int local_4;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00538610,0x104);
  _DAT_005384ac = &DAT_00538610;
  pcVar2 = DAT_00539a4c;
  if (*DAT_00539a4c == '\0') {
    pcVar2 = &DAT_00538610;
  }
  FUN_0049f600(pcVar2,0,0,&local_8,&local_4);
  iVar1 = FUN_0049bf00(local_4 + local_8 * 4);
  if (iVar1 == 0) {
    __amsg_exit(8);
  }
  FUN_0049f600(pcVar2,iVar1,iVar1 + local_8 * 4,&local_8,&local_4);
  DAT_00538494 = iVar1;
  DAT_00538490 = local_8 + -1;
  return;
}


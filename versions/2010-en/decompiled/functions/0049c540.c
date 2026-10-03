
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c540(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  undefined4 *puVar2;
  UINT uExitCode;
  
  FUN_0049c600();
  if (DAT_005384bc == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_005384b8 = 1;
  DAT_005384b4 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00539a48 != (undefined4 *)0x0) &&
       (puVar2 = (undefined4 *)(DAT_00539a44 + -4), puVar1 = DAT_00539a48, DAT_00539a48 <= puVar2))
    {
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          puVar1 = DAT_00539a48;
        }
        puVar2 = puVar2 + -1;
      } while (puVar1 <= puVar2);
    }
    FUN_0049c620(&DAT_004da0d4,&DAT_004da0dc);
  }
  FUN_0049c620(&DAT_004da0e0,&DAT_004da0e8);
  if (param_3 != 0) {
    FUN_0049c610();
    return;
  }
  DAT_005384bc = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00457c80(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  undefined4 *puVar2;
  UINT uExitCode;
  
  FUN_00457d40();
  if (DAT_004ae964 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004ae960 = 1;
  DAT_004ae95c = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_004aff08 != (undefined4 *)0x0) &&
       (puVar2 = (undefined4 *)(DAT_004aff04 + -4), puVar1 = DAT_004aff08, DAT_004aff08 <= puVar2))
    {
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          puVar1 = DAT_004aff08;
        }
        puVar2 = puVar2 + -1;
      } while (puVar1 <= puVar2);
    }
    FUN_00457d60((undefined4 *)&DAT_004910c4,(undefined4 *)&DAT_004910cc);
  }
  FUN_00457d60((undefined4 *)&DAT_004910d0,(undefined4 *)&DAT_004910d8);
  if (param_3 != 0) {
    FUN_00457d50();
    return;
  }
  DAT_004ae964 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


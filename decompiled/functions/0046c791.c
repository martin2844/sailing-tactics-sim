
void __fastcall FUN_0046c791(int param_1)

{
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  FUN_0046be50((int *)(param_1 + 0xc));
  return;
}


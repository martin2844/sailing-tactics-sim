
void FUN_004a7130(undefined4 param_1,undefined4 param_2)

{
  DWORD dwThreadId;
  
  DAT_00538914 = param_2;
  DAT_0053890c = param_1;
  dwThreadId = GetCurrentThreadId();
  DAT_00538910 = SetWindowsHookExA(4,FUN_004a7080,DAT_00539a9c,dwThreadId);
  return;
}


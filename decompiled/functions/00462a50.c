
void __cdecl FUN_00462a50(undefined4 param_1,undefined4 param_2)

{
  DWORD dwThreadId;
  
  DAT_004aedbc = param_2;
  DAT_004aedb4 = param_1;
  dwThreadId = GetCurrentThreadId();
  DAT_004aedb8 = SetWindowsHookExA(4,FUN_004629a0,DAT_004aff5c,dwThreadId);
  return;
}


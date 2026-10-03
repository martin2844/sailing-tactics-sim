
bool FUN_00464290(void)

{
  int iVar1;
  HWND in_stack_00000014;
  CHAR local_10 [16];
  
  if ((0x35e < DAT_004aff60) && (in_stack_00000014 != (HWND)0x0)) {
    GetClassNameA(in_stack_00000014,local_10,0x10);
    iVar1 = lstrcmpA(local_10,"ComboBox");
    return (bool)('\x01' - (iVar1 == 0));
  }
  return true;
}


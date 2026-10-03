
void __fastcall FUN_004783a9(int *param_1)

{
  if ((*(byte *)(param_1 + 0x2e) & 1) != 0) {
    (**(code **)(*param_1 + 0xec))(param_1[0x2a]);
  }
  if ((*(byte *)(param_1 + 0x2e) & 2) != 0) {
    (**(code **)(*param_1 + 0xe8))(1);
  }
  if ((param_1[0x2e] & 8U) != 0) {
    (**(code **)(*param_1 + 0xd0))(param_1[0x2e] & 4);
    UpdateWindow((HWND)param_1[7]);
  }
  if (param_1[0x24] != param_1[0x25]) {
    FUN_00477d86(param_1,param_1[0x24]);
  }
  param_1[0x2e] = 0;
  return;
}


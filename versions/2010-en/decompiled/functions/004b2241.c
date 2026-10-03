
void __thiscall FUN_004b2241(int param_1,int param_2)

{
  FUN_004b0530();
  for (; param_2 < *(int *)(param_1 + 4) + -1; param_2 = param_2 + 1) {
    FUN_004b069e((Tact2010CString *)(*(int *)(param_1 + 8) + param_2 * 4),
                 (Tact2010CString *)(*(int *)(param_1 + 8) + 4 + param_2 * 4));
  }
  FUN_004b0530();
  return;
}


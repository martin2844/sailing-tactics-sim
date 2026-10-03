
void __fastcall FUN_004b1d48(int param_1)

{
  undefined4 *puVar1;
  undefined1 local_10 [4];
  int local_c;
  int *local_8;
  
  local_c = -(uint)(*(int *)(param_1 + 0x28) != 0);
  while (local_c != 0) {
    FUN_004ab7d0(&local_c,local_10,&local_8);
    puVar1 = (undefined4 *)((int)local_8 + *(int *)(param_1 + 0x3c));
    *puVar1 = 0;
    if (*(int *)(param_1 + 0x40) == 2) {
      puVar1[1] = 0;
    }
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(1);
    }
  }
  RemoveAll();
  return;
}



void __fastcall FUN_0046d668(int param_1)

{
  undefined4 *puVar1;
  int local_10;
  int local_c;
  int *local_8;
  
  local_c = -(uint)(*(int *)(param_1 + 0x28) != 0);
  if (local_c != 0) {
    do {
      FUN_004670f0((void *)(param_1 + 0x1c),&local_c,&local_10,(int *)&local_8);
      puVar1 = (undefined4 *)((int)local_8 + *(int *)(param_1 + 0x3c));
      *puVar1 = 0;
      if (*(int *)(param_1 + 0x40) == 2) {
        puVar1[1] = 0;
      }
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 4))(1);
      }
    } while (local_c != 0);
  }
  RemoveAll(param_1 + 0x1c);
  return;
}


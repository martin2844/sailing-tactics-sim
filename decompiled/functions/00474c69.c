
void __fastcall FUN_00474c69(void *param_1)

{
  void *local_8;
  void *pvStack_4;
  
  local_8 = param_1;
  pvStack_4 = param_1;
  FUN_00474e53(param_1);
  (**(code **)(**(int **)((int)param_1 + 0x68) + 0xc4))
            (&local_8,*(int *)((int)param_1 + 0x40) - *(int *)((int)param_1 + 0x38),0x42);
  FUN_00479eb8(*(void **)((int)param_1 + 0x6c),*(void **)((int)param_1 + 0x68),
               *(int *)((int)param_1 + 0x48),*(int *)((int)param_1 + 0x4c),
               (uint)((ushort)*(undefined4 *)((int)param_1 + 0x70) & 0x40 | 0x2004));
  return;
}


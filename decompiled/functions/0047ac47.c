
undefined4 __fastcall FUN_0047ac47(void *param_1)

{
  int iVar1;
  
  if ((*(int *)((int)param_1 + 0xac) == 0) || (*(int *)(*(int *)((int)param_1 + 0xac) + 0x10) != 5))
  {
    iVar1 = FUN_0047b918();
    if (*(char *)(iVar1 + 0x14) == '\0') {
      FUN_0047ac0b(param_1);
    }
  }
  if (*(code **)((int)param_1 + 0xbc) != (code *)0x0) {
    (**(code **)((int)param_1 + 0xbc))();
  }
  return *(undefined4 *)((int)param_1 + 0x38);
}



void __fastcall FUN_0047ac0b(void *param_1)

{
  int iVar1;
  
  if (*(int **)((int)param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)((int)param_1 + 0xa8) + 0x10))();
  }
  if (*(int *)((int)param_1 + 0xb4) != 0) {
    iVar1 = FUN_0047b918();
    FUN_004727dd(param_1,"Settings","PreviewPages",*(undefined4 *)(*(int *)(iVar1 + 4) + 0xb4));
  }
  return;
}



void __thiscall FUN_004afb0c(int param_1,LPCSTR param_2)

{
  UINT UVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_004b55a5(*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x1c),param_2);
  }
  else if (*(int *)(param_1 + 0x10) == 0) {
    UVar1 = GetMenuState(*(HMENU *)(*(int *)(param_1 + 0xc) + 4),*(UINT *)(param_1 + 8),0x400);
    ModifyMenuA(*(HMENU *)(*(int *)(param_1 + 0xc) + 4),*(UINT *)(param_1 + 8),
                UVar1 & 0xfffff6fb | 0x400,*(UINT_PTR *)(param_1 + 4),param_2);
  }
  return;
}


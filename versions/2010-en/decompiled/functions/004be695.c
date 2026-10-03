
uint __thiscall FUN_004be695(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  BOOL BVar5;
  undefined4 *puVar6;
  uint in_stack_00000014;
  int *in_stack_00000018;
  tagRECT local_14;
  
  piVar3 = in_stack_00000018;
  in_stack_00000014 = in_stack_00000014 & 0xf040;
  if (in_stack_00000018 != (int *)0x0) {
    *in_stack_00000018 = 0;
  }
  puVar6 = *(undefined4 **)(param_1 + 0x70);
  do {
    do {
      if (puVar6 == (undefined4 *)0x0) {
        return 0;
      }
      puVar1 = (undefined4 *)*puVar6;
      piVar2 = (int *)puVar6[2];
      iVar4 = (**(code **)(*piVar2 + 0xd8))();
      puVar6 = puVar1;
    } while ((((iVar4 == 0) || (BVar5 = IsWindowVisible((HWND)piVar2[7]), BVar5 == 0)) ||
             ((piVar2[0x19] & in_stack_00000014 & 0xf000) == 0)) ||
            ((piVar2[0x1e] != 0 && ((piVar2[0x19] & in_stack_00000014 & 0x40) == 0))));
    GetWindowRect((HWND)piVar2[7],&local_14);
    if (local_14.right == local_14.left) {
      local_14.right = local_14.right + 1;
    }
    if (local_14.bottom == local_14.top) {
      local_14.bottom = local_14.bottom + 1;
    }
    BVar5 = IntersectRect(&local_14,&local_14,(RECT *)&stack0x00000004);
  } while (BVar5 == 0);
  if (piVar3 != (int *)0x0) {
    *piVar3 = (int)piVar2;
  }
  return piVar2[0x19] & in_stack_00000014;
}


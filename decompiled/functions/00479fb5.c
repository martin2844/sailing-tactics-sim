
uint __thiscall FUN_00479fb5(void *this)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 *puVar5;
  uint in_stack_00000014;
  int *in_stack_00000018;
  tagRECT local_14;
  
  in_stack_00000014 = in_stack_00000014 & 0xf040;
  if (in_stack_00000018 != (int *)0x0) {
    *in_stack_00000018 = 0;
  }
  puVar5 = *(undefined4 **)((int)this + 0x70);
  do {
    do {
      if (puVar5 == (undefined4 *)0x0) {
        return 0;
      }
      puVar1 = (undefined4 *)*puVar5;
      piVar2 = (int *)puVar5[2];
      iVar3 = (**(code **)(*piVar2 + 0xd8))();
      puVar5 = puVar1;
    } while ((((iVar3 == 0) || (BVar4 = IsWindowVisible((HWND)piVar2[7]), BVar4 == 0)) ||
             ((piVar2[0x19] & in_stack_00000014 & 0xf000) == 0)) ||
            ((piVar2[0x1e] != 0 && ((piVar2[0x19] & in_stack_00000014 & 0x40) == 0))));
    GetWindowRect((HWND)piVar2[7],&local_14);
    if (local_14.right == local_14.left) {
      local_14.right = local_14.right + 1;
    }
    if (local_14.bottom == local_14.top) {
      local_14.bottom = local_14.bottom + 1;
    }
    BVar4 = IntersectRect(&local_14,&local_14,(RECT *)&stack0x00000004);
  } while (BVar4 == 0);
  if (in_stack_00000018 != (int *)0x0) {
    *in_stack_00000018 = (int)piVar2;
  }
  return piVar2[0x19] & in_stack_00000014;
}


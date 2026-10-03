
void __thiscall FUN_00470ca1(void *this,uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)((int)this + 0x24);
  local_8 = *(int *)((int)this + 0x28) - (int)puVar1;
  uVar2 = param_1 + local_8;
  if (*(int *)((int)this + 8) == 0) {
    puVar3 = *(undefined4 **)((int)this + 0x2c);
    if (puVar3 < puVar1) {
      if (0 < (int)local_8) {
        FUN_00457e80(puVar3,puVar1,local_8);
        puVar3 = *(undefined4 **)((int)this + 0x2c);
        *(undefined4 **)((int)this + 0x24) = puVar3;
        *(int *)((int)this + 0x28) = local_8 + (int)puVar3;
      }
      iVar5 = *(int *)((int)this + 0x1c) - local_8;
      iVar6 = local_8 + (int)puVar3;
      do {
        iVar4 = (**(code **)(**(int **)((int)this + 0x20) + 0x3c))(iVar6,iVar5);
        local_8 = local_8 + iVar4;
        iVar6 = iVar6 + iVar4;
        iVar5 = iVar5 - iVar4;
        if ((iVar4 == 0) || (iVar5 == 0)) break;
      } while (local_8 < param_1);
      *(int *)((int)this + 0x24) = *(int *)((int)this + 0x2c);
      *(uint *)((int)this + 0x28) = local_8 + *(int *)((int)this + 0x2c);
    }
  }
  else {
    if (local_8 != 0) {
      (**(code **)(**(int **)((int)this + 0x20) + 0x30))(-local_8,1);
    }
    (**(code **)(**(int **)((int)this + 0x20) + 0x58))
              (0,*(undefined4 *)((int)this + 0x1c),(undefined4 *)((int)this + 0x2c),
               (int *)((int)this + 0x28));
    *(undefined4 *)((int)this + 0x24) = *(undefined4 *)((int)this + 0x2c);
  }
  if ((uint)(*(int *)((int)this + 0x28) - *(int *)((int)this + 0x24)) < uVar2) {
    FUN_00471ee6();
  }
  return;
}


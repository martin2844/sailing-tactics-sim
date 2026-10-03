
void __thiscall FUN_00466ae4(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)((int)this + 0x10) == 0) {
    iVar1 = FUN_00466bf9((undefined4 *)((int)this + 0x14),*(int *)((int)this + 0x18),0xc);
    iVar3 = *(int *)((int)this + 0x18);
    puVar2 = (undefined4 *)(iVar1 + -8 + iVar3 * 0xc);
    if (-1 < iVar3 + -1) {
      do {
        *puVar2 = *(undefined4 *)((int)this + 0x10);
        *(undefined4 **)((int)this + 0x10) = puVar2;
        puVar2 = puVar2 + -3;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  puVar2 = *(undefined4 **)((int)this + 0x10);
  *(undefined4 *)((int)this + 0x10) = *puVar2;
  puVar2[1] = param_1;
  *puVar2 = param_2;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  puVar2[2] = 0;
  return;
}


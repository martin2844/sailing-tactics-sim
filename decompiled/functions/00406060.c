
void * __thiscall FUN_00406060(void *this,undefined4 *param_1)

{
  if (*(uint *)((int)this + 0x28) < *(int *)((int)this + 0x24) + 4U) {
    FUN_00470ca1(this,(*(int *)((int)this + 0x24) - *(uint *)((int)this + 0x28)) + 4);
  }
  *param_1 = **(undefined4 **)((int)this + 0x24);
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 4;
  return this;
}


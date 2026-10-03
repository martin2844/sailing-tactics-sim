
uint __thiscall FUN_0047602d(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)((int)this + 0x80) + param_1 * 4);
  return uVar1 & -(uint)((short)(uVar1 >> 0x10) != 0);
}


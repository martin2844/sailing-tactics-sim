
void __thiscall FUN_0047a2c6(void *this,int param_1)

{
  if ((DAT_004ae694 != 0) && ((*(uint *)((int)this + 100) & 0xff00) == 0x8200)) {
    *(uint *)((int)this + 100) = *(uint *)((int)this + 100) & 0xfffff07f;
  }
  FUN_0047c2b4(this,param_1);
  return;
}


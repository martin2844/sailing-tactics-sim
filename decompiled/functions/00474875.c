
void __thiscall FUN_00474875(void *this,int param_1,int param_2)

{
  int dy;
  uint uVar1;
  int dx;
  
  dx = param_1 - *(int *)((int)this + 4);
  dy = param_2 - *(int *)((int)this + 8);
  OffsetRect((LPRECT)((int)this + 0x28),dx,dy);
  OffsetRect((LPRECT)((int)this + 0x48),dx,dy);
  OffsetRect((LPRECT)((int)this + 0x38),dx,dy);
  OffsetRect((LPRECT)((int)this + 0x58),dx,dy);
  *(int *)((int)this + 4) = param_1;
  *(int *)((int)this + 8) = param_2;
  if (*(int *)((int)this + 0x80) == 0) {
    uVar1 = FUN_00475004((int)this);
  }
  else {
    uVar1 = 0;
  }
  *(uint *)((int)this + 0x74) = uVar1;
  FUN_00474e9c(this,0);
  return;
}


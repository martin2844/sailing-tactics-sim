
void __thiscall FUN_00473720(void *this,int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)((int)this + 100);
  if ((uVar1 & 0x100) != 0) {
    *param_1 = *param_1 + DAT_004ae648;
  }
  if ((uVar1 & 0x200) != 0) {
    param_1[1] = param_1[1] + DAT_004ae64c;
  }
  if ((uVar1 & 0x400) != 0) {
    param_1[2] = param_1[2] - DAT_004ae648;
  }
  if ((uVar1 & 0x800) != 0) {
    param_1[3] = param_1[3] - DAT_004ae64c;
  }
  if (param_2 == 0) {
    *param_1 = *param_1 + *(int *)((int)this + 0x48);
    param_1[1] = param_1[1] + *(int *)((int)this + 0x40);
    param_1[2] = param_1[2] - *(int *)((int)this + 0x4c);
    iVar2 = *(int *)((int)this + 0x44);
  }
  else {
    *param_1 = *param_1 + *(int *)((int)this + 0x40);
    param_1[1] = param_1[1] + *(int *)((int)this + 0x48);
    param_1[2] = param_1[2] - *(int *)((int)this + 0x44);
    iVar2 = *(int *)((int)this + 0x4c);
  }
  param_1[3] = param_1[3] - iVar2;
  return;
}


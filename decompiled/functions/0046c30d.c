
int __thiscall FUN_0046c30d(void *this,byte param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = FUN_00457780(*(byte **)this,(uint)param_1);
  if (pbVar1 == (byte *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = (int)pbVar1 - *(int *)this;
  }
  return iVar2;
}


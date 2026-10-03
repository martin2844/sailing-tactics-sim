
int __thiscall FUN_0046c32e(void *this,byte *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = FUN_00457db0(*(byte **)this,param_1);
  if (pcVar1 == (char *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = (int)pcVar1 - *(int *)this;
  }
  return iVar2;
}


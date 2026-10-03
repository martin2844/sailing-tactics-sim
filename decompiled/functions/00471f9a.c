
void __thiscall FUN_00471f9a(void *this,int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(*(int *)((int)this + 0x5c) + 8 + param_1 * 0x14);
  iVar2 = *(int *)((int)this + 0x5c) + param_1 * 0x14;
  if (uVar3 != param_2) {
    *(uint *)(iVar2 + 8) = param_2;
    if (((param_2 ^ uVar3) & 0x8000000) == 0) {
      puVar1 = (uint *)(iVar2 + 0xc);
      *puVar1 = *puVar1 | 1;
      FUN_00471fe5();
    }
    else {
      FUN_0047a500(this,1,0);
    }
  }
  return;
}


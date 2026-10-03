
undefined4 __thiscall FUN_0046d0a2(void *this,undefined4 *param_1,int param_2)

{
  HGLOBAL hMem;
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  *(int *)((int)this + 4) = param_2;
  hMem = GlobalAlloc(0x40,param_2 + 0x40);
  *(HGLOBAL *)this = hMem;
  uVar3 = 0;
  if (hMem != (HGLOBAL)0x0) {
    puVar1 = GlobalLock(hMem);
    FUN_00457850(puVar1,param_1,*(uint *)((int)this + 4));
    if (*(short *)((int)puVar1 + 2) == -1) {
      uVar2 = puVar1[3];
    }
    else {
      uVar2 = *puVar1;
    }
    *(uint *)((int)this + 8) = ~uVar2 >> 6 & 1;
    GlobalUnlock(*(HGLOBAL *)this);
    uVar3 = 1;
  }
  return uVar3;
}


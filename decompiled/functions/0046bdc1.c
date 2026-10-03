
void __thiscall FUN_0046bdc1(void *this,int param_1)

{
  undefined **ppuVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    ppuVar1 = FUN_0046bd74();
    puVar2 = (undefined4 *)*ppuVar1;
  }
  else {
    puVar2 = (undefined4 *)FUN_0046b505(param_1 + 0xd);
    *puVar2 = 1;
    *(undefined1 *)((int)puVar2 + param_1 + 0xc) = 0;
    puVar2[1] = param_1;
    puVar2[2] = param_1;
    puVar2 = puVar2 + 3;
  }
  *(undefined4 **)this = puVar2;
  return;
}


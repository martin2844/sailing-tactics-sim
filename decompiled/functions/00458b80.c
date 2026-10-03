
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00458b80(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_004ae968;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_004aea6c = 0;
  DAT_004aea70 = 0;
  _DAT_004aea78 = 0;
  _DAT_004aea7c = 0;
  _DAT_004aea80 = 0;
  return;
}


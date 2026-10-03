
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049d280(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_005384c0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_005385c4 = 0;
  DAT_005385c8 = 0;
  _DAT_005385d0 = 0;
  _DAT_005385d4 = 0;
  _DAT_005385d8 = 0;
  return;
}



void FUN_004bc2e9(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  uVar1 = FUN_004b0956(0xff);
  iVar2 = FUN_004b1fc5(param_1,uVar1,0x100);
  if (iVar2 != 0) {
    puVar3 = (undefined1 *)FUN_0049c040(uVar1,10);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0;
    }
  }
  FUN_004b09a5(0xffffffff);
  return;
}


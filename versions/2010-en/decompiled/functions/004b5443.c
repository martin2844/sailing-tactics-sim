
undefined4 FUN_004b5443(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  CHAR local_104 [256];
  
  iVar1 = FUN_004b1fc5(param_1,local_104,0x100);
  uVar3 = 0;
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)FUN_0049c040(local_104,10);
    if (puVar2 != (undefined1 *)0x0) {
      iVar1 = FUN_0049cb20(puVar2 + 1);
      *param_2 = iVar1;
      iVar1 = MulDiv(iVar1,DAT_005381ac,0x48);
      *param_2 = iVar1;
      *puVar2 = 0;
    }
    lstrcpynA((LPSTR)(param_2 + 7),local_104,0x20);
    uVar3 = 1;
  }
  return uVar3;
}


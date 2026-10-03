
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a4310(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar1 = DAT_005388d2;
  if (DAT_005387a8 == 0) {
    FUN_0049bfd0(DAT_0053889c);
    FUN_0049bfd0(DAT_005388a0);
    FUN_0049bfd0(DAT_005388a4);
    DAT_0053889c = 0;
    DAT_005388a0 = 0;
    DAT_005388a4 = 0;
    uVar5 = FUN_0049bf00(2);
    *(undefined4 *)PTR_PTR_004f11e0 = uVar5;
    if (*(undefined2 **)PTR_PTR_004f11e0 == (undefined2 *)0x0) {
      return 0xffffffff;
    }
    **(undefined2 **)PTR_PTR_004f11e0 = DAT_004dd054;
    uVar5 = FUN_0049bf00(2);
    *(undefined4 *)(PTR_PTR_004f11e0 + 4) = uVar5;
    if (*(undefined1 **)(PTR_PTR_004f11e0 + 4) == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    **(undefined1 **)(PTR_PTR_004f11e0 + 4) = 0;
    uVar5 = FUN_0049bf00(2);
    *(undefined4 *)(PTR_PTR_004f11e0 + 8) = uVar5;
    if (*(undefined1 **)(PTR_PTR_004f11e0 + 8) == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    **(undefined1 **)(PTR_PTR_004f11e0 + 8) = 0;
  }
  else {
    iVar2 = FUN_004a5ee0(1,DAT_005388d2,0xe,&DAT_0053889c);
    iVar3 = FUN_004a5ee0(1,uVar1,0xf,&DAT_005388a0);
    iVar4 = FUN_004a5ee0(1,uVar1,0x10,&DAT_005388a4);
    FUN_004a4750(DAT_005388a4);
    if ((iVar2 != 0 || iVar3 != 0) || iVar4 != 0) {
      FUN_0049bfd0(DAT_0053889c);
      FUN_0049bfd0(DAT_005388a0);
      FUN_0049bfd0(DAT_005388a4);
      DAT_0053889c = 0;
      DAT_005388a0 = 0;
      DAT_005388a4 = 0;
      return 0xffffffff;
    }
    if (*(undefined **)PTR_PTR_004f11e0 != &DAT_004f11a8) {
      FUN_0049bfd0(*(undefined **)PTR_PTR_004f11e0);
      FUN_0049bfd0(*(undefined4 *)(PTR_PTR_004f11e0 + 4));
      FUN_0049bfd0(*(undefined4 *)(PTR_PTR_004f11e0 + 8));
    }
    *(undefined4 *)PTR_PTR_004f11e0 = DAT_0053889c;
    *(undefined4 *)(PTR_PTR_004f11e0 + 4) = DAT_005388a0;
    *(undefined4 *)(PTR_PTR_004f11e0 + 8) = DAT_005388a4;
  }
  _DAT_004f0464 = 1;
  DAT_004f0460 = **(undefined1 **)PTR_PTR_004f11e0;
  return 0;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0045fc30(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = (uint)DAT_004aed7a;
  if (DAT_004aec50 == 0) {
    FUN_00457710(DAT_004aed44);
    FUN_00457710(DAT_004aed48);
    FUN_00457710(DAT_004aed4c);
    DAT_004aed44 = (undefined *)0x0;
    DAT_004aed48 = (undefined *)0x0;
    DAT_004aed4c = (char *)0x0;
    uVar4 = FUN_00457640(2);
    *(undefined4 *)PTR_PTR_004a3020 = uVar4;
    if (*(undefined2 **)PTR_PTR_004a3020 == (undefined2 *)0x0) {
      return 0xffffffff;
    }
    **(undefined2 **)PTR_PTR_004a3020 = DAT_0049300c;
    uVar4 = FUN_00457640(2);
    *(undefined4 *)(PTR_PTR_004a3020 + 4) = uVar4;
    if (*(undefined1 **)(PTR_PTR_004a3020 + 4) == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    **(undefined1 **)(PTR_PTR_004a3020 + 4) = 0;
    uVar4 = FUN_00457640(2);
    *(undefined4 *)(PTR_PTR_004a3020 + 8) = uVar4;
    if (*(undefined1 **)(PTR_PTR_004a3020 + 8) == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    **(undefined1 **)(PTR_PTR_004a3020 + 8) = 0;
  }
  else {
    iVar1 = FUN_00461800(1,uVar5,0xe,(char *)&DAT_004aed44);
    iVar2 = FUN_00461800(1,uVar5,0xf,(char *)&DAT_004aed48);
    iVar3 = FUN_00461800(1,uVar5,0x10,(char *)&DAT_004aed4c);
    FUN_00460070(DAT_004aed4c);
    if ((iVar1 != 0 || iVar2 != 0) || iVar3 != 0) {
      FUN_00457710(DAT_004aed44);
      FUN_00457710(DAT_004aed48);
      FUN_00457710(DAT_004aed4c);
      DAT_004aed44 = (undefined *)0x0;
      DAT_004aed48 = (undefined *)0x0;
      DAT_004aed4c = (char *)0x0;
      return 0xffffffff;
    }
    if (*(undefined **)PTR_PTR_004a3020 != &DAT_004a2fe8) {
      FUN_00457710(*(undefined **)PTR_PTR_004a3020);
      FUN_00457710(*(undefined **)(PTR_PTR_004a3020 + 4));
      FUN_00457710(*(undefined **)(PTR_PTR_004a3020 + 8));
    }
    *(undefined **)PTR_PTR_004a3020 = DAT_004aed44;
    *(undefined **)(PTR_PTR_004a3020 + 4) = DAT_004aed48;
    *(char **)(PTR_PTR_004a3020 + 8) = DAT_004aed4c;
  }
  _DAT_004a22a4 = 1;
  DAT_004a22a0 = **(undefined1 **)PTR_PTR_004a3020;
  return 0;
}


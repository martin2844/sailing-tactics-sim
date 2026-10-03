
undefined4 FUN_004a4b00(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 local_4;
  
  iVar2 = param_1;
  bVar1 = false;
  iVar3 = param_1;
  switch(param_1) {
  case 2:
    puVar7 = &DAT_005388dc;
    bVar1 = true;
    pcVar6 = DAT_005388dc;
    break;
  default:
    return 0xffffffff;
  case 4:
  case 8:
  case 0xb:
    iVar3 = FUN_0049e5b0();
    iVar4 = FUN_004a4d10(param_1,*(undefined4 *)(iVar3 + 0x50));
    puVar7 = (undefined4 *)(iVar4 + 8);
    pcVar6 = (code *)*puVar7;
    break;
  case 0xf:
    puVar7 = &DAT_005388e8;
    bVar1 = true;
    pcVar6 = DAT_005388e8;
    break;
  case 0x15:
    puVar7 = &DAT_005388e0;
    bVar1 = true;
    pcVar6 = DAT_005388e0;
    break;
  case 0x16:
    puVar7 = &DAT_005388e4;
    bVar1 = true;
    pcVar6 = DAT_005388e4;
  }
  if (bVar1) {
    FUN_0049fe10(1);
  }
  if (pcVar6 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_0049fe90(1);
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_0049fe90(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
    iVar4 = *(int *)(iVar3 + 0x54);
    bVar8 = param_1 == 8;
    *(undefined4 *)(iVar3 + 0x54) = 0;
    param_1 = iVar4;
    if (bVar8) {
      local_4 = *(undefined4 *)(iVar3 + 0x58);
      *(undefined4 *)(iVar3 + 0x58) = 0x8c;
      goto LAB_004a4c33;
    }
  }
  else {
LAB_004a4c33:
    if (iVar2 == 8) {
      if (DAT_004ee098 < DAT_004ee09c + DAT_004ee098) {
        iVar5 = DAT_004ee098 * 0xc;
        iVar4 = DAT_004ee098;
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(*(int *)(iVar3 + 0x50) + 8 + iVar5) = 0;
          iVar5 = iVar5 + 0xc;
        } while (iVar4 < DAT_004ee09c + DAT_004ee098);
      }
      goto LAB_004a4c78;
    }
  }
  *puVar7 = 0;
LAB_004a4c78:
  if (bVar1) {
    FUN_0049fe90(1);
  }
  if (iVar2 == 8) {
    (*pcVar6)(8,*(undefined4 *)(iVar3 + 0x58));
  }
  else {
    (*pcVar6)(iVar2);
    if ((iVar2 != 0xb) && (iVar2 != 4)) {
      return 0;
    }
  }
  *(int *)(iVar3 + 0x54) = param_1;
  if (iVar2 == 8) {
    *(undefined4 *)(iVar3 + 0x58) = local_4;
  }
  return 0;
}


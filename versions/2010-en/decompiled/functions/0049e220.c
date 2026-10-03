
void FUN_0049e220(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d09f8;
  pcStack_10 = FUN_0049e908;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (((*(int *)(param_3 + 4) != 0) && (*(char *)(*(int *)(param_3 + 4) + 8) != '\0')) &&
     (*(int *)(param_3 + 8) != 0)) {
    piVar1 = (int *)(param_2 + 0xc + *(int *)(param_3 + 8));
    local_8 = 0;
    if ((*param_3 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          iVar2 = FUN_004a2620(*(undefined4 *)(param_1 + 0x18),1);
          if ((iVar2 != 0) && (iVar2 = FUN_004a2640(piVar1,1), iVar2 != 0)) {
            uVar3 = FUN_0049e4b0(*(undefined4 *)(param_1 + 0x18),param_4 + 8,
                                 *(undefined4 *)(param_4 + 0x14));
            FUN_0049c740(piVar1,uVar3);
            goto LAB_0049e410;
          }
        }
        else {
          iVar2 = FUN_004a2620(*(undefined4 *)(param_1 + 0x18),1);
          if (((iVar2 != 0) && (iVar2 = FUN_004a2640(piVar1,1), iVar2 != 0)) &&
             (iVar2 = FUN_004a2660(*(undefined4 *)(param_4 + 0x18)), iVar2 != 0)) {
            if ((*param_4 & 4) == 0) {
              uVar3 = FUN_0049e4b0(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
              FUN_0049b0c0(piVar1,*(undefined4 *)(param_4 + 0x18),uVar3);
            }
            else {
              uVar3 = FUN_0049e4b0(*(undefined4 *)(param_1 + 0x18),param_4 + 8,1);
              FUN_0049b0c0(piVar1,*(undefined4 *)(param_4 + 0x18),uVar3);
            }
            goto LAB_0049e410;
          }
        }
      }
      else {
        iVar2 = FUN_004a2620(*(undefined4 *)(param_1 + 0x18),1);
        if ((iVar2 != 0) && (iVar2 = FUN_004a2640(piVar1,1), iVar2 != 0)) {
          FUN_0049c740(piVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_4 + 0x14));
          if ((*(int *)(param_4 + 0x14) == 4) && (*piVar1 != 0)) {
            iVar2 = FUN_0049e4b0(*piVar1,param_4 + 8);
            *piVar1 = iVar2;
          }
          goto LAB_0049e410;
        }
      }
    }
    else {
      iVar2 = FUN_004a2620(*(undefined4 *)(param_1 + 0x18),1);
      if ((iVar2 != 0) && (iVar2 = FUN_004a2640(piVar1,1), iVar2 != 0)) {
        iVar2 = *(int *)(param_1 + 0x18);
        *piVar1 = iVar2;
        iVar2 = FUN_0049e4b0(iVar2,param_4 + 8);
        *piVar1 = iVar2;
        goto LAB_0049e410;
      }
    }
    FUN_0049e6c0();
  }
LAB_0049e410:
  *unaff_FS_OFFSET = local_14;
  return;
}


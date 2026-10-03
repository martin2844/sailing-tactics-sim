
void FUN_0049dba0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 char param_6,undefined4 param_7,undefined4 param_8)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  uint local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int *local_8;
  int local_4;
  
  iVar5 = *(int *)(param_2 + 8);
  local_10 = iVar5;
  if ((iVar5 < -1) || (*(int *)(param_5 + 4) <= iVar5)) {
    FUN_0049e6c0();
  }
  if (*param_1 == -0x1f928c9d) {
    if (((param_1[4] == 3) && (param_1[5] == 0x19930520)) && (param_1[7] == 0)) {
      iVar2 = FUN_0049e5b0();
      if (*(int *)(iVar2 + 0x6c) == 0) {
        return;
      }
      iVar2 = FUN_0049e5b0();
      param_1 = *(int **)(iVar2 + 0x6c);
      iVar2 = FUN_0049e5b0();
      param_3 = *(undefined4 *)(iVar2 + 0x70);
      iVar2 = FUN_004a2620(param_1,1);
      if (iVar2 == 0) {
        FUN_0049e6c0();
      }
      if (*param_1 != -0x1f928c9d) goto LAB_0049de16;
      if (((param_1[4] == 3) && (param_1[5] == 0x19930520)) && (param_1[7] == 0)) {
        FUN_0049e6c0();
      }
    }
    if (((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) && (param_1[5] == 0x19930520)) {
      local_1c = (int *)FUN_0049b360(param_5,param_7,iVar5,&local_20,&local_c);
      if (local_20 < local_c) {
        do {
          if ((*local_1c <= iVar5) && (iVar5 <= local_1c[1])) {
            local_14 = local_1c[3];
            pbVar7 = (byte *)local_1c[4];
            if (0 < local_14) {
              local_8 = *(int **)(param_1[7] + 0xc) + 1;
              local_4 = **(int **)(param_1[7] + 0xc);
              do {
                local_18 = local_4;
                if (0 < local_4) {
                  iVar5 = *(int *)(pbVar7 + 4);
                  piVar4 = local_8;
                  do {
                    if ((iVar5 == 0) || (pbVar3 = (byte *)(iVar5 + 8), *(char *)(iVar5 + 8) == '\0')
                       ) {
LAB_0049dd6f:
                      bVar8 = true;
                    }
                    else {
                      iVar2 = *(int *)((byte *)*piVar4 + 4);
                      if (iVar5 == iVar2) {
LAB_0049dd4a:
                        if (((((*(byte *)*piVar4 & 2) == 0) || ((*pbVar7 & 8) != 0)) &&
                            (((*(uint *)param_1[7] & 1) == 0 || ((*pbVar7 & 1) != 0)))) &&
                           (((*(uint *)param_1[7] & 2) == 0 || ((*pbVar7 & 2) != 0))))
                        goto LAB_0049dd6f;
                        bVar8 = false;
                      }
                      else {
                        pbVar6 = (byte *)(iVar2 + 8);
                        do {
                          bVar1 = *pbVar3;
                          bVar8 = bVar1 < *pbVar6;
                          if (bVar1 != *pbVar6) {
LAB_0049dd2d:
                            iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                            goto LAB_0049dd32;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar3[1];
                          bVar8 = bVar1 < pbVar6[1];
                          if (bVar1 != pbVar6[1]) goto LAB_0049dd2d;
                          pbVar3 = pbVar3 + 2;
                          pbVar6 = pbVar6 + 2;
                        } while (bVar1 != 0);
                        iVar2 = 0;
LAB_0049dd32:
                        if (iVar2 == 0) goto LAB_0049dd4a;
                        bVar8 = false;
                      }
                    }
                    if (bVar8) {
                      FUN_0049e000(param_1,param_2,param_3,param_4,param_5,pbVar7,*piVar4,local_1c,
                                   param_7,param_8);
                      iVar5 = local_10;
                      goto LAB_0049dddf;
                    }
                    piVar4 = piVar4 + 1;
                    local_18 = local_18 + -1;
                  } while (0 < local_18);
                }
                local_14 = local_14 + -1;
                pbVar7 = pbVar7 + 0x10;
                iVar5 = local_10;
              } while (0 < local_14);
            }
          }
LAB_0049dddf:
          local_20 = local_20 + 1;
          local_1c = local_1c + 5;
        } while (local_20 < local_c);
      }
      if (param_6 == '\0') {
        return;
      }
      FUN_0049e430(param_1,1);
      return;
    }
  }
LAB_0049de16:
  if (param_6 != '\0') {
    FUN_0049e630();
    return;
  }
  FUN_0049de60(param_1,param_2,param_3,param_4,param_5,iVar5,param_7,param_8);
  return;
}


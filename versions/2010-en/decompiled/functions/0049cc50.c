
uint FUN_0049cc50(byte *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  byte bVar6;
  byte *local_8;
  uint local_4;
  
  local_4 = 0;
  bVar6 = *param_1;
  pbVar1 = param_1;
  while( true ) {
    local_8 = pbVar1 + 1;
    if (DAT_004f045c < 2) {
      uVar2 = (byte)PTR_DAT_004f0250[(uint)bVar6 * 2] & 8;
    }
    else {
      uVar2 = FUN_004a0b90(bVar6,8);
    }
    if (uVar2 == 0) break;
    bVar6 = *local_8;
    pbVar1 = local_8;
  }
  if (bVar6 == 0x2d) {
    param_4 = param_4 | 2;
  }
  else if (bVar6 != 0x2b) goto LAB_0049ccdb;
  bVar6 = *local_8;
  local_8 = pbVar1 + 2;
LAB_0049ccdb:
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (param_3 == 0) {
    if (bVar6 == 0x30) {
      if ((*local_8 == 0x78) || (param_3 = 8, *local_8 == 0x58)) {
        param_3 = 0x10;
      }
    }
    else {
      param_3 = 10;
    }
  }
  if (((param_3 == 0x10) && (bVar6 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58)))) {
    bVar6 = local_8[1];
    local_8 = local_8 + 2;
  }
  uVar2 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    if (DAT_004f045c < 2) {
      uVar3 = (byte)PTR_DAT_004f0250[(uint)bVar6 * 2] & 4;
    }
    else {
      uVar3 = FUN_004a0b90(bVar6,4);
    }
    if (uVar3 == 0) {
      if (DAT_004f045c < 2) {
        uVar3 = *(ushort *)(PTR_DAT_004f0250 + (uint)bVar6 * 2) & 0x103;
      }
      else {
        uVar3 = FUN_004a0b90((uint)bVar6,0x103);
      }
      if (uVar3 == 0) {
LAB_0049ce14:
        local_8 = local_8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            local_8 = param_1;
          }
          local_4 = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && (0x80000000 < local_4)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < local_4)))))))) {
          puVar5 = (undefined4 *)FUN_0049d3d0();
          *puVar5 = 0x22;
          if ((param_4 & 1) == 0) {
            local_4 = ((param_4 & 2) != 0) + 0x7fffffff;
          }
          else {
            local_4 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = local_8;
        }
        if ((param_4 & 2) != 0) {
          local_4 = -local_4;
        }
        return local_4;
      }
      iVar4 = FUN_004a0c70((int)(char)bVar6);
      uVar3 = iVar4 - 0x37;
    }
    else {
      uVar3 = (int)(char)bVar6 - 0x30;
    }
    if (param_3 <= uVar3) goto LAB_0049ce14;
    if ((local_4 < uVar2) ||
       ((local_4 == uVar2 && (uVar3 <= (uint)(0xffffffff % (ulonglong)param_3))))) {
      local_4 = local_4 * param_3 + uVar3;
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    bVar6 = *local_8;
    local_8 = local_8 + 1;
  } while( true );
}


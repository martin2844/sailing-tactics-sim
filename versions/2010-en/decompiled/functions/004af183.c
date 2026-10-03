
int FUN_004af183(byte param_1)

{
  int iVar1;
  int iVar2;
  uint local_2c;
  code *local_28;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  char *local_8;
  
  iVar2 = 0;
  _memset(&local_2c,0,0x28);
  local_28 = DefWindowProcA_exref;
  iVar1 = FUN_004bfff8();
  local_1c = *(undefined4 *)(iVar1 + 8);
  local_14 = DAT_005381d0;
  iVar1 = FUN_004bfff8();
  if ((param_1 & 1) == 0) {
    if ((param_1 & 0x20) == 0) {
      if ((param_1 & 2) == 0) {
        if ((param_1 & 4) == 0) {
          if ((param_1 & 8) == 0) {
            if ((param_1 & 0x10) != 0) {
              Ordinal_17();
              *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 0x10;
              iVar2 = 1;
            }
          }
          else {
            local_2c = 0xb;
            local_10 = 6;
            iVar2 = AfxRegisterWithIcon(&local_2c,"AfxFrameOrView42s",0x7a02);
            if (iVar2 != 0) {
              *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 8;
            }
          }
        }
        else {
          local_10 = 0;
          local_2c = 8;
          iVar2 = AfxRegisterWithIcon(&local_2c,"AfxMDIFrame42s",0x7a01);
          if (iVar2 != 0) {
            *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 4;
          }
        }
      }
      else {
        local_2c = 0;
        local_8 = "AfxControlBar42s";
        local_10 = 0x10;
        iVar2 = FUN_004ad3d6(&local_2c);
        if (iVar2 != 0) {
          *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 2;
        }
      }
    }
    else {
      local_2c = local_2c | 0x8b;
      local_8 = "AfxOleControl42s";
      iVar2 = FUN_004ad3d6(&local_2c);
      if (iVar2 != 0) {
        *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 0x20;
      }
    }
  }
  else {
    local_2c = 0xb;
    local_8 = "AfxWnd42s";
    iVar2 = FUN_004ad3d6(&local_2c);
    if (iVar2 != 0) {
      *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 1;
    }
  }
  return iVar2;
}


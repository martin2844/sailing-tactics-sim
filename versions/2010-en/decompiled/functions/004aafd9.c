
undefined4 FUN_004aafd9(HWND param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 != (HWND)0x0) {
    iVar1 = FUN_004c04f2(FUN_0049a32a);
    if (*(int *)(iVar1 + 0x18) != 0) {
      FUN_004af334(param_1);
      *(undefined4 *)(iVar1 + 0x18) = 0;
    }
    if (param_2 == 0x110) {
      uVar2 = FUN_004abab0(param_1,0x110,param_3,param_4);
      return uVar2;
    }
    if ((param_2 == DAT_00538448) || ((param_2 == 0x111 && ((short)param_3 == 0x40e)))) {
      SendMessageA(param_1,0x111,0xe146,0);
      return 1;
    }
    if (0xbfff < param_2) {
      piVar3 = (int *)FUN_004ac7d4(param_1);
      iVar1 = FUN_004b1618(&PTR_s_CFileDialog_004cfdd0);
      if ((iVar1 == 0) || ((*(byte *)((int)piVar3 + 0x92) & 8) == 0)) {
        if (param_2 == DAT_00538438) {
          uVar2 = (**(code **)(*piVar3 + 0xd8))(param_4);
          return uVar2;
        }
        if (param_2 == DAT_00538444) {
          if (DAT_005381ec != 0) {
            piVar3[0x7d] = param_4;
          }
          uVar2 = (**(code **)(*piVar3 + 0xdc))();
          piVar3[0x7d] = 0;
          return uVar2;
        }
        if (param_2 == DAT_00538440) {
          (**(code **)(*piVar3 + 0xe0))(param_3,param_4 & 0xffff,param_4 >> 0x10);
        }
        else if (param_2 == DAT_0053843c) {
          uVar2 = (**(code **)(*piVar3 + 0xd8))();
          return uVar2;
        }
      }
    }
  }
  return 0;
}


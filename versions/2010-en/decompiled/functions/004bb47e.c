
undefined4 __thiscall
FUN_004bb47e(int *param_1,undefined4 param_2,char *param_3,undefined4 param_4,int *param_5,
            int param_6,LPCSTR param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  HMENU hMenu;
  undefined4 uVar2;
  
  uVar2 = 0;
  hMenu = (HMENU)0x0;
  if (param_7 != (LPCSTR)0x0) {
    iVar1 = FUN_004bfff8();
    hMenu = LoadMenuA(*(HINSTANCE *)(iVar1 + 0xc),param_7);
    if (hMenu == (HMENU)0x0) {
      (**(code **)(*param_1 + 0xac))();
      return 0;
    }
  }
  FUN_004b06ed((Tact2010CString *)(param_1 + 0x2b),param_3);
  if (param_6 != 0) {
    uVar2 = *(undefined4 *)(param_6 + 0x1c);
  }
  iVar1 = FUN_004acd4b(param_8,param_2,param_3,param_4,*param_5,param_5[1],param_5[2] - *param_5,
                       param_5[3] - param_5[1],uVar2,hMenu,param_9);
  if (iVar1 == 0) {
    if (hMenu != (HMENU)0x0) {
      DestroyMenu(hMenu);
    }
    return 0;
  }
  return 1;
}


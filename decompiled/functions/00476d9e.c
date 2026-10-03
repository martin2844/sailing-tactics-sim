
undefined4 __thiscall
FUN_00476d9e(void *this,LPCSTR param_1,LPCSTR param_2,DWORD param_3,int *param_4,int param_5,
            LPCSTR param_6,DWORD param_7,LPVOID param_8)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  HMENU hMenu;
  HWND pHVar3;
  
  pHVar3 = (HWND)0x0;
  hMenu = (HMENU)0x0;
  if (param_6 != (LPCSTR)0x0) {
    iVar2 = FUN_0047b918();
    hMenu = LoadMenuA(*(HINSTANCE *)(iVar2 + 0xc),param_6);
    if (hMenu == (HMENU)0x0) {
      (**(code **)(*(int *)this + 0xac))();
      return 0;
    }
  }
  FUN_0046c00d((void *)((int)this + 0xac),param_2);
  if (param_5 != 0) {
    pHVar3 = *(HWND *)(param_5 + 0x1c);
  }
  bVar1 = FUN_0046866b(this,param_7,param_1,param_2,param_3,*param_4,param_4[1],
                       param_4[2] - *param_4,param_4[3] - param_4[1],pHVar3,hMenu,param_8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (hMenu != (HMENU)0x0) {
      DestroyMenu(hMenu);
    }
    return 0;
  }
  return 1;
}


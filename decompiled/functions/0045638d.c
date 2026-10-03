
void __thiscall FUN_0045638d(void *this,int param_1,uint param_2)

{
  bool bVar1;
  HWND pHVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    pHVar2 = (HWND)0x0;
  }
  else {
    pHVar2 = *(HWND *)(param_1 + 0x1c);
  }
  bVar1 = FUN_0046866b(this,0,"tooltips_class32",(LPCSTR)0x0,param_2 | 0x80000000,-0x80000000,
                       -0x80000000,-0x80000000,-0x80000000,pHVar2,(HMENU)0x0,(LPVOID)0x0);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    if (param_1 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x1c);
    }
    *(undefined4 *)((int)this + 0x20) = uVar3;
  }
  return;
}


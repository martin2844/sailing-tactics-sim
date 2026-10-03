
undefined4 __thiscall
FUN_0046667e(void *this,undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  LRESULT LVar3;
  
  iVar1 = FUN_00469628(this,param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = param_2[2];
    if (iVar1 == -0x25f) {
      (**(code **)(*(int *)this + 0xf0))();
    }
    else {
      if (iVar1 == -0x25e) {
        uVar2 = (**(code **)(*(int *)this + 0xdc))();
      }
      else {
        if (iVar1 == -0x25d) {
          LVar3 = SendMessageA(*(HWND *)((int)this + 0x1c),0x111,0xe146,0);
          if (LVar3 != 0) {
            return 1;
          }
          SendMessageA(*(HWND *)((int)this + 0x1c),0x365,0,0);
          return 1;
        }
        if (iVar1 != -0x25c) {
          if (iVar1 == -0x25b) {
            (**(code **)(*(int *)this + 0xec))();
            return 1;
          }
          if (iVar1 != -0x25a) {
            if (iVar1 == -0x259) {
              (**(code **)(*(int *)this + 0xe4))();
              return 1;
            }
            return 0;
          }
          (**(code **)(*(int *)this + 0xe8))();
          return 1;
        }
        uVar2 = (**(code **)(*(int *)this + 0xd8))(param_2[4]);
      }
      *param_3 = uVar2;
    }
  }
  return 1;
}


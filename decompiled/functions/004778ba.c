
void FUN_004778ba(int *param_1,int param_2,int param_3)

{
  CWnd *this;
  int iVar1;
  uint uVar2;
  
  this = FUN_004786de((int)param_1);
  if (param_3 == 0) {
    FUN_0046adfd(param_1,0,0,0,0,0,(-(uint)(param_2 != 0) & 0xffffffc0) + 0x80 | 0x17);
    (**(code **)(*param_1 + 0xcc))(param_2);
    if ((param_2 != 0) || (iVar1 = FUN_004786ef(param_1), iVar1 == 0)) {
      (**(code **)(*(int *)this + 0xd0))(0);
    }
  }
  else {
    (**(code **)(*param_1 + 0xcc))(param_2);
    *(uint *)(this + 0xb8) = *(uint *)(this + 0xb8) | 0xc;
  }
  iVar1 = FUN_004786ef(param_1);
  if (iVar1 == 0) {
    return;
  }
  if ((int *)param_1[0x1c] == (int *)0x0) {
    uVar2 = (uint)(param_2 != 0);
  }
  else {
    uVar2 = (**(code **)(*(int *)param_1[0x1c] + 0xe8))();
  }
  if ((uVar2 == 1) && (param_2 != 0)) {
    *(undefined4 *)(this + 0x88) = 0xffffffff;
    if (param_3 == 0) {
      iVar1 = 8;
LAB_00477995:
      FUN_0046ae4c(this,iVar1);
      return;
    }
    *(undefined4 *)(this + 0x88) = 8;
  }
  else {
    if (uVar2 == 0) {
      *(undefined4 *)(this + 0x88) = 0xffffffff;
      if (param_3 != 0) {
        *(undefined4 *)(this + 0x88) = 0;
        return;
      }
      iVar1 = 0;
      goto LAB_00477995;
    }
    if (param_3 != 0) {
      return;
    }
  }
  (**(code **)(*(int *)this + 0xd0))(0);
  return;
}


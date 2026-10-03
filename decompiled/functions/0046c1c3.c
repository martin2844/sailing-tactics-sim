
void __thiscall FUN_0046c1c3(void *this,uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = *(undefined4 **)this;
    if (((int)puVar1[-3] < 2) && ((int)(param_1 + puVar1[-2]) <= (int)puVar1[-1])) {
      FUN_00457850((undefined4 *)(puVar1[-2] + (int)puVar1),param_2,param_1);
      *(int *)(*(int *)this + -8) = *(int *)(*(int *)this + -8) + param_1;
      *(undefined1 *)(*(int *)(*(int *)this + -8) + *(int *)this) = 0;
    }
    else {
      FUN_0046c034(this,puVar1[-2],puVar1,param_1,param_2);
      FUN_0046be2d(puVar1 + -3);
    }
  }
  return;
}


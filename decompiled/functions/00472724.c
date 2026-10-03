
undefined4 __thiscall FUN_00472724(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x84))
                    (*(undefined4 *)
                      (*(int *)(*(int *)((int)this + 0xa8) + 8) + (param_1 + -0xe110) * 4));
  if (iVar1 == 0) {
    (**(code **)**(undefined4 **)((int)this + 0xa8))(param_1 + -0xe110);
  }
  return 1;
}


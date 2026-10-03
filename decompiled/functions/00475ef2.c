
void __thiscall FUN_00475ef2(void *this,undefined4 param_1,int *param_2)

{
  tagRECT local_14;
  
  SetRectEmpty(&local_14);
  FUN_00473720(this,&local_14.left,*(uint *)((int)this + 100) & 0xa000);
  *param_2 = *param_2 + local_14.left;
  param_2[1] = param_2[1] + local_14.top;
  param_2[2] = param_2[2] + local_14.right;
  param_2[3] = param_2[3] + local_14.bottom;
  return;
}


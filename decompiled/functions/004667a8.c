
undefined4 * __thiscall FUN_004667a8(void *this,ushort *param_1,undefined4 param_2)

{
  if (*param_1 < 0x76c) {
    *(undefined4 *)this = 0;
  }
  else {
    FUN_0046675c(&param_1,(uint)*param_1,(uint)param_1[1],(uint)param_1[3],(uint)param_1[4],
                 (uint)param_1[5],(uint)param_1[6],param_2);
    *(ushort **)this = param_1;
  }
  return this;
}


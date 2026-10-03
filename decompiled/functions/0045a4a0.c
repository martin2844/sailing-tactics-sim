
void __cdecl FUN_0045a4a0(int param_1,uint *param_2,byte *param_3)

{
  uint local_8;
  uint local_4;
  
  if (param_1 != 0) {
    FUN_0045e780(&local_8,param_3);
    *param_2 = local_8;
    param_2[1] = local_4;
    return;
  }
  FUN_0045e7c0((uint *)&param_3,param_3);
  *param_2 = (uint)param_3;
  return;
}


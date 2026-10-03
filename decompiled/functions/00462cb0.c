
void __cdecl FUN_00462cb0(HDC param_1,int *param_2,ushort param_3)

{
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  local_4 = param_2[3];
  FUN_00462b70(param_1,&local_10,7,1,param_3 & 0xf);
  local_10 = local_10 + -1;
  local_c = local_c + -1;
  local_8 = local_8 + 1;
  local_4 = local_4 + 1;
  FUN_00462b70(param_1,&local_10,2,0,param_3);
  return;
}



int __thiscall FUN_004b4a8f(int param_1,int param_2)

{
  undefined4 local_8;
  
  local_8 = param_1;
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    local_8 = SetMapMode(*(HDC *)(param_1 + 4),param_2);
  }
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    local_8 = SetMapMode(*(HDC *)(param_1 + 8),param_2);
  }
  return local_8;
}



void __thiscall FUN_004b04a1(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = (undefined4 *)FUN_004b0454();
    puVar1 = (undefined4 *)*puVar1;
  }
  else {
    puVar1 = (undefined4 *)FUN_004afbe5(param_2 + 0xd);
    *puVar1 = 1;
    *(undefined1 *)((int)puVar1 + param_2 + 0xc) = 0;
    puVar1[1] = param_2;
    puVar1[2] = param_2;
    puVar1 = puVar1 + 3;
  }
  *param_1 = puVar1;
  return;
}


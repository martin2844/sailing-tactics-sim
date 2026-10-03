
void FUN_004ab2d9(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_004afbe5(param_2 * param_3 + 4);
  *puVar1 = *param_1;
  *param_1 = puVar1;
  return;
}


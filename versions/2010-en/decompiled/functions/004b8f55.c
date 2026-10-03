
void __thiscall FUN_004b8f55(int param_1,int param_2,int param_3)

{
  int dy;
  undefined4 uVar1;
  int dx;
  
  dx = param_2 - *(int *)(param_1 + 4);
  dy = param_3 - *(int *)(param_1 + 8);
  OffsetRect((LPRECT)(param_1 + 0x28),dx,dy);
  OffsetRect((LPRECT)(param_1 + 0x48),dx,dy);
  OffsetRect((LPRECT)(param_1 + 0x38),dx,dy);
  OffsetRect((LPRECT)(param_1 + 0x58),dx,dy);
  *(int *)(param_1 + 4) = param_2;
  *(int *)(param_1 + 8) = param_3;
  if (*(int *)(param_1 + 0x80) == 0) {
    uVar1 = FUN_004b96e4();
  }
  else {
    uVar1 = 0;
  }
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  FUN_004b957c(0);
  return;
}


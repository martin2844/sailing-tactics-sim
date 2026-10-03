
void __thiscall FUN_0046ed91(void *this,undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  CHAR local_208 [256];
  byte local_108 [260];
  
  FUN_0046cc20();
  FUN_0046c00d((undefined4 *)((int)this + 0x20),(LPCSTR)local_108);
  *(undefined4 *)((int)this + 0x4c) = 0;
  iVar2 = FUN_0046ce82(local_108,local_208,0x100);
  if (iVar2 == 0) {
    (**(code **)(*(int *)this + 0x58))(local_208);
  }
  if (param_2 != 0) {
    uVar1 = *(undefined4 *)((int)this + 0x20);
    iVar2 = FUN_0047b918();
    (**(code **)(**(int **)(iVar2 + 4) + 0x88))(uVar1);
  }
  return;
}


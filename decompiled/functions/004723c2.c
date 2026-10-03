
void __thiscall FUN_004723c2(void *this,int *param_1)

{
  uint uVar1;
  undefined **local_2c;
  undefined4 *local_28;
  uint local_24;
  void *local_18;
  uint local_c;
  
  CCmdUI::CCmdUI((CCmdUI *)&local_2c);
  local_c = *(uint *)((int)this + 0x58);
  local_2c = &PTR_FUN_00486504;
  local_24 = 0;
  local_18 = this;
  if (local_c != 0) {
    do {
      local_28 = *(undefined4 **)(*(int *)((int)this + 0x5c) + local_24 * 0x14);
      uVar1 = FUN_0046afc3(this,local_28,0xffffffff,&local_2c,(undefined4 *)0x0);
      if (uVar1 == 0) {
        FUN_0046b482(&local_2c,param_1,0);
      }
      local_24 = local_24 + 1;
    } while (local_24 < local_c);
  }
  FUN_0046a7e4();
  return;
}


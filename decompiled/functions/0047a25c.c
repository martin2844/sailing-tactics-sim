
void __thiscall FUN_0047a25c(void *this,int param_1,undefined4 param_2,HMENU param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  tagRECT local_14;
  
  *(undefined4 *)((int)this + 100) = param_2;
  uVar3 = CONCAT31((uint3)((uint)param_2 >> 8) & 0xffff00,0x4e);
  uVar1 = FUN_0046ad0b(param_1);
  if ((uVar1 & 0x40000) != 0) {
    uVar3 = uVar3 | 0x100;
  }
  iVar2 = FUN_0047b918();
  if ((*(byte *)(iVar2 + 0x18) & 0x10) == 0) {
    FUN_0046aaa3(0x10);
  }
  SetRectEmpty(&local_14);
  FUN_00468761(this,"msctls_statusbar32",(LPCSTR)0x0,uVar3,&local_14.left,param_1,param_3,
               (LPVOID)0x0);
  return;
}



bool __thiscall FUN_00475388(void *this,int param_1,uint param_2,HMENU param_3)

{
  int iVar1;
  bool bVar2;
  tagRECT local_14;
  
  *(uint *)((int)this + 100) = param_2;
  iVar1 = FUN_0047b918();
  if ((*(byte *)(iVar1 + 0x18) & 2) == 0) {
    iVar1 = FUN_0046aaa3(2);
  }
  else {
    iVar1 = 1;
  }
  bVar2 = false;
  if (iVar1 != 0) {
    SetRectEmpty(&local_14);
    iVar1 = FUN_00468761(this,"AfxControlBar42s",(LPCSTR)0x0,param_2,&local_14.left,param_1,param_3,
                         (LPVOID)0x0);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


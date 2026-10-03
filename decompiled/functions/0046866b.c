
bool __thiscall
FUN_0046866b(void *this,DWORD param_1,LPCSTR param_2,LPCSTR param_3,DWORD param_4,int param_5,
            int param_6,int param_7,int param_8,HWND param_9,HMENU param_10,LPVOID param_11)

{
  int iVar1;
  int iVar2;
  HWND pHVar3;
  bool bVar4;
  LPVOID local_34;
  HINSTANCE local_30;
  HMENU local_2c;
  HWND local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  DWORD local_14;
  LPCSTR local_10;
  LPCSTR local_c;
  DWORD local_8;
  
  local_8 = param_1;
  local_c = param_2;
  local_10 = param_3;
  local_14 = param_4;
  local_18 = param_5;
  local_1c = param_6;
  local_20 = param_7;
  local_24 = param_8;
  local_28 = param_9;
  local_2c = param_10;
  iVar1 = FUN_0047b918();
  local_30 = *(HINSTANCE *)(iVar1 + 8);
  iVar1 = *(int *)this;
  local_34 = param_11;
  iVar2 = (**(code **)(iVar1 + 100))(&local_34);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0xac))();
    bVar4 = false;
  }
  else {
    FUN_004685dd((int)this);
    pHVar3 = CreateWindowExA(local_8,local_c,local_10,local_14,local_18,local_1c,local_20,local_24,
                             local_28,local_2c,local_30,local_34);
    iVar2 = FUN_00468629();
    if (iVar2 == 0) {
      (**(code **)(iVar1 + 0xac))();
    }
    bVar4 = pHVar3 != (HWND)0x0;
  }
  return bVar4;
}


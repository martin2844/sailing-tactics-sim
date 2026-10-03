
undefined4 __thiscall FUN_00477778(void *this,HWND param_1,LPARAM param_2)

{
  LPCSTR lpString2;
  LPARAM lParam;
  int iVar1;
  CHAR local_214 [520];
  uint local_c;
  HGLOBAL local_8;
  
  UnpackDDElParam(1000,param_2,&local_c,(PUINT_PTR)&local_8);
  lpString2 = GlobalLock(local_8);
  lstrcpynA(local_214,lpString2,0x208);
  GlobalUnlock(local_8);
  lParam = ReuseDDElParam(param_2,1000,0x3e4,0x8000,(UINT_PTR)local_8);
  PostMessageA(param_1,0x3e4,*(WPARAM *)((int)this + 0x1c),lParam);
  iVar1 = FUN_0046ae73((int)this);
  if (iVar1 != 0) {
    iVar1 = FUN_0047b918();
    (**(code **)(**(int **)(iVar1 + 4) + 0x9c))(local_214);
  }
  return 0;
}


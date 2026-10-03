
undefined4 * __thiscall FUN_004667f4(void *this,FILETIME *param_1,undefined4 param_2)

{
  BOOL BVar1;
  _SYSTEMTIME local_1c;
  _FILETIME local_c;
  
  BVar1 = FileTimeToLocalFileTime(param_1,&local_c);
  if ((BVar1 != 0) && (BVar1 = FileTimeToSystemTime(&local_c,&local_1c), BVar1 != 0)) {
    FUN_004667a8(&param_1,&local_1c.wYear,param_2);
    *(FILETIME **)this = param_1;
    return this;
  }
  *(undefined4 *)this = 0;
  return this;
}


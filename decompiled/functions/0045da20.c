
/* Library Function - Single Match
    __isindst
   
   Library: Visual Studio 1998 Release */

int __cdecl __isindst(tm *_Time)

{
  bool bVar1;
  undefined3 extraout_var;
  
  FUN_0045b730(0xb);
  bVar1 = FUN_0045da50(&_Time->tm_sec);
  FUN_0045b7b0(0xb);
  return CONCAT31(extraout_var,bVar1);
}


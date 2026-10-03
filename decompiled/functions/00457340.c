
/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_004ae920 == 1) {
    FUN_0045b4e0();
  }
  FUN_0045b520(param_1);
  (*(code *)PTR___exit_0049fae4)(0xff);
  return;
}


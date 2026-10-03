
/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00538478 == 1) {
    FUN_0049fbc0();
  }
  FUN_0049fc00(param_1);
  (*(code *)PTR___exit_004edcac)(0xff);
  return;
}


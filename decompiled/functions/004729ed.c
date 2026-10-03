
/* Library Function - Single Match
    public: void __thiscall CControlBar::ResetTimer(unsigned int,unsigned int)
   
   Library: Visual Studio 2003 Release */

void __thiscall CControlBar::ResetTimer(CControlBar *this,uint param_1,uint param_2)

{
  KillTimer(*(HWND *)(this + 0x1c),0xe000);
  KillTimer(*(HWND *)(this + 0x1c),0xe001);
  SetTimer(*(HWND *)(this + 0x1c),param_1,param_2,(TIMERPROC)0x0);
  return;
}


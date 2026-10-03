
/* Library Function - Single Match
    public: void __thiscall CSimpleException::InitString(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CSimpleException::InitString(CSimpleException *this)

{
  int iVar1;
  
  *(undefined4 *)(this + 0xc) = 1;
  iVar1 = FUN_0046d8e5(*(UINT *)(this + 0x94),(LPSTR)(this + 0x14),0x80);
  *(uint *)(this + 0x10) = (uint)(iVar1 != 0);
  return;
}


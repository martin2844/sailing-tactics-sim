
/* Library Function - Single Match
    struct AFX_MSGMAP_ENTRY const * __stdcall AfxFindMessageEntry(struct AFX_MSGMAP_ENTRY const
   *,unsigned int,unsigned int,unsigned int)
   
   Library: Visual Studio */

AFX_MSGMAP_ENTRY *
AfxFindMessageEntry(AFX_MSGMAP_ENTRY *param_1,uint param_2,uint param_3,uint param_4)

{
  while( true ) {
    if (*(int *)(param_1 + 0x10) == 0) {
      return (AFX_MSGMAP_ENTRY *)0x0;
    }
    if ((((param_2 == *(uint *)param_1) && (param_3 == *(uint *)(param_1 + 4))) &&
        (*(uint *)(param_1 + 8) <= param_4)) && (param_4 <= *(uint *)(param_1 + 0xc))) break;
    param_1 = param_1 + 0x18;
  }
  return param_1;
}


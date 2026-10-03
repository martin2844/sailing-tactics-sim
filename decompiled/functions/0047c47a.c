
void FUN_0047c47a(void)

{
  undefined4 *puVar1;
  int *piVar2;
  code *pcVar3;
  LPCSTR lpSubKey;
  undefined4 *puVar4;
  int iVar5;
  LPSTR lpData;
  LSTATUS LVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  PLONG lpcbData;
  
  FUN_00457418();
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar5 = FUN_0047b918();
  FUN_0046ced8(*(HMODULE *)(iVar5 + 8),(void *)(unaff_EBP + -0x24));
  puVar4 = *(undefined4 **)(extraout_ECX + 8);
  while (puVar4 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar4;
    piVar2 = (int *)puVar4[2];
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x20));
    pcVar3 = *(code **)(*piVar2 + 0x6c);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(code **)(unaff_EBP + -0x1c) = pcVar3;
    iVar5 = (*pcVar3)(unaff_EBP + -0x14,5);
    if ((iVar5 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) != 0)) {
      iVar5 = (**(code **)(unaff_EBP + -0x1c))(unaff_EBP + -0x20,6);
      if (iVar5 == 0) {
        FUN_0046bfbe((void *)(unaff_EBP + -0x20),(int *)(unaff_EBP + -0x14));
      }
      FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\DefaultIcon");
      FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
      iVar5 = (**(code **)(unaff_EBP + -0x1c))(unaff_EBP + -0x10,0);
      if ((iVar5 == 0) || (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) == 0)) {
        FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\shell\\open\\%s");
        FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
        FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\shell\\print\\%s");
        FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
        FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\shell\\printto\\%s");
        FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
      }
      FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\shell\\open\\%s");
      FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
      FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\shell\\print\\%s");
      FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
      FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\shell\\printto\\%s");
      FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
      (**(code **)(unaff_EBP + -0x1c))(unaff_EBP + -0x18,4);
      lpSubKey = *(LPCSTR *)(unaff_EBP + -0x18);
      if (*(int *)(lpSubKey + -8) != 0) {
        lpcbData = (PLONG)(unaff_EBP + -0x28);
        *(undefined4 *)(unaff_EBP + -0x28) = 0x208;
        lpData = (LPSTR)FUN_0046c276((void *)(unaff_EBP + -0x10),0x208);
        LVar6 = RegQueryValueA((HKEY)0x80000000,lpSubKey,lpData,lpcbData);
        FUN_0046c2c5((void *)(unaff_EBP + -0x10),-1);
        if (((LVar6 != 0) || (*(int *)(*(byte **)(unaff_EBP + -0x10) + -8) == 0)) ||
           (iVar5 = FUN_00457440(*(byte **)(unaff_EBP + -0x10),*(byte **)(unaff_EBP + -0x14)),
           iVar5 == 0)) {
          FUN_00466415((void *)(unaff_EBP + -0x10),(byte *)"%s\\ShellNew");
          FUN_0047c397(*(HKEY *)(unaff_EBP + -0x10));
          FUN_0047c397(*(HKEY *)(unaff_EBP + -0x18));
        }
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0046bec5((int *)(unaff_EBP + -0x20));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_0046bec5((int *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046bec5((int *)(unaff_EBP + -0x18));
    puVar4 = puVar1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + -0x24));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}


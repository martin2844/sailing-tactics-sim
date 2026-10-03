
undefined4 FUN_00473c72(void)

{
  void *this;
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  BOOL BVar5;
  undefined4 uVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_0046bf33((void *)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047a888();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x2c) = 4;
  puVar1 = (undefined4 *)FUN_004660f8();
  iVar2 = FUN_00457440((byte *)*puVar1,(byte *)"[open(\"");
  FUN_0046bec5((int *)(unaff_EBP + -0x14));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    piVar3 = (int *)FUN_0046607b();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
    *(undefined1 *)(unaff_EBP + -4) = 1;
LAB_00473d67:
    FUN_0046bec5((int *)(unaff_EBP + -0x14));
LAB_00473dd9:
    iVar2 = FUN_0046c30d((void *)(unaff_EBP + 8),0x22);
    if (iVar2 != -1) {
      piVar3 = (int *)FUN_004660f8();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0046bfbe((void *)(unaff_EBP + -0x28),piVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046bec5((int *)(unaff_EBP + -0x14));
      piVar3 = (int *)FUN_0046607b();
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046bec5((int *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      iVar2 = FUN_0047b918();
      if (*(int *)(*(int *)(iVar2 + 4) + 0xac) == 0) {
        iVar2 = FUN_0047b918();
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(iVar2 + 4) + 0xac);
      }
      else {
        iVar2 = FUN_0047b918();
        iVar2 = *(int *)(iVar2 + 4);
        iVar4 = FUN_0047b918();
        *(undefined4 *)(*(int *)(iVar4 + 4) + 0x74) = *(undefined4 *)(iVar2 + 0xac);
        iVar2 = FUN_0047b918();
        *(int *)(*(int *)(iVar2 + 4) + 0xac) = unaff_EBP + -0x3c;
      }
      if (*(int *)(unaff_EBP + -0x2c) == 1) {
        iVar2 = FUN_0047b918();
        this = *(void **)(*(int *)(iVar2 + 4) + 0x1c);
        iVar2 = FUN_0047b918();
        iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0x74);
        if ((iVar2 == -1) || (iVar2 == 1)) {
          BVar5 = IsIconic(*(HWND *)((int)this + 0x1c));
          iVar2 = (-(uint)(BVar5 != 0) & 4) + 5;
        }
        FUN_0046ae4c(this,iVar2);
        if (iVar2 != 6) {
          SetForegroundWindow(*(HWND *)((int)this + 0x1c));
        }
        iVar2 = FUN_0047b918();
        (**(code **)(**(int **)(iVar2 + 4) + 0x84))(*(undefined4 *)(unaff_EBP + -0x28));
        iVar2 = FUN_00478738();
        if (iVar2 == 0) {
          FUN_00478729(1);
        }
        iVar2 = FUN_0047b918();
        *(undefined4 *)(*(int *)(iVar2 + 4) + 0x74) = 0xffffffff;
      }
      else if (*(int *)(unaff_EBP + -0x2c) == 3) {
        puVar1 = (undefined4 *)FUN_004660f8();
        iVar2 = FUN_00457440((byte *)*puVar1,&DAT_00487a44);
        FUN_0046bec5((int *)(unaff_EBP + -0x18));
        if (iVar2 == 0) {
          piVar3 = (int *)FUN_0046607b();
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0046bec5((int *)(unaff_EBP + -0x18));
          iVar2 = FUN_0046c30d((void *)(unaff_EBP + 8),0x22);
          if (iVar2 != -1) {
            piVar3 = (int *)FUN_004660f8();
            *(undefined1 *)(unaff_EBP + -4) = 8;
            FUN_0046bfbe((void *)(unaff_EBP + -0x24),piVar3);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_0046bec5((int *)(unaff_EBP + -0x18));
            piVar3 = (int *)FUN_0046607b();
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_0046bec5((int *)(unaff_EBP + -0x18));
            puVar1 = (undefined4 *)FUN_004660f8();
            iVar2 = FUN_00457440((byte *)*puVar1,&DAT_00487a44);
            FUN_0046bec5((int *)(unaff_EBP + -0x18));
            if (iVar2 == 0) {
              piVar3 = (int *)FUN_0046607b();
              *(undefined1 *)(unaff_EBP + -4) = 10;
              FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_0046bec5((int *)(unaff_EBP + -0x18));
              iVar2 = FUN_0046c30d((void *)(unaff_EBP + 8),0x22);
              if (iVar2 != -1) {
                piVar3 = (int *)FUN_004660f8();
                *(undefined1 *)(unaff_EBP + -4) = 0xb;
                FUN_0046bfbe((void *)(unaff_EBP + -0x20),piVar3);
                *(undefined1 *)(unaff_EBP + -4) = 1;
                FUN_0046bec5((int *)(unaff_EBP + -0x18));
                piVar3 = (int *)FUN_0046607b();
                *(undefined1 *)(unaff_EBP + -4) = 0xc;
                FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
                *(undefined1 *)(unaff_EBP + -4) = 1;
                FUN_0046bec5((int *)(unaff_EBP + -0x18));
                puVar1 = (undefined4 *)FUN_004660f8();
                iVar2 = FUN_00457440((byte *)*puVar1,&DAT_00487a44);
                FUN_0046bec5((int *)(unaff_EBP + -0x18));
                if (iVar2 == 0) {
                  piVar3 = (int *)FUN_0046607b();
                  *(undefined1 *)(unaff_EBP + -4) = 0xd;
                  FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  FUN_0046bec5((int *)(unaff_EBP + -0x18));
                  iVar2 = FUN_0046c30d((void *)(unaff_EBP + 8),0x22);
                  if (iVar2 != -1) {
                    piVar3 = (int *)FUN_004660f8();
                    *(undefined1 *)(unaff_EBP + -4) = 0xe;
                    FUN_0046bfbe((void *)(unaff_EBP + -0x1c),piVar3);
                    *(undefined1 *)(unaff_EBP + -4) = 1;
                    FUN_0046bec5((int *)(unaff_EBP + -0x18));
                    piVar3 = (int *)FUN_0046607b();
                    *(undefined1 *)(unaff_EBP + -4) = 0xf;
                    FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
                    *(undefined1 *)(unaff_EBP + -4) = 1;
                    FUN_0046bec5((int *)(unaff_EBP + -0x18));
                    goto LAB_00474187;
                  }
                }
              }
            }
          }
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
      else {
LAB_00474187:
        iVar2 = FUN_0047b918();
        piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 4) + 0x84))
                                  (*(undefined4 *)(unaff_EBP + -0x28));
        iVar2 = FUN_0047b918();
        *(int *)(*(int *)(iVar2 + 4) + 0xac) = unaff_EBP + -0x3c;
        iVar2 = FUN_0047b918();
        SendMessageA(*(HWND *)(*(int *)(*(int *)(iVar2 + 4) + 0x1c) + 0x1c),0x111,0xe108,0);
        iVar2 = FUN_0047b918();
        *(undefined4 *)(*(int *)(iVar2 + 4) + 0xac) = 0;
        (**(code **)(*piVar3 + 0x84))();
        iVar2 = FUN_00478738();
        if (iVar2 == 0) {
          iVar2 = FUN_0047b918();
          PostMessageA(*(HWND *)(*(int *)(*(int *)(iVar2 + 4) + 0x1c) + 0x1c),0x10,0,0);
        }
      }
      iVar2 = FUN_0047b918();
      iVar2 = *(int *)(iVar2 + 4);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(iVar2 + 0xac) = *(undefined4 *)(unaff_EBP + -0x14);
      FUN_0047a913();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + 8));
      uVar6 = *(undefined4 *)(unaff_EBP + -0x10);
      goto LAB_0047424f;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_004660f8();
    iVar2 = FUN_00457440((byte *)*puVar1,(byte *)"[print(\"");
    FUN_0046bec5((int *)(unaff_EBP + -0x14));
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = 2;
      piVar3 = (int *)FUN_0046607b();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      goto LAB_00473d67;
    }
    puVar1 = (undefined4 *)FUN_004660f8();
    iVar2 = FUN_00457440((byte *)*puVar1,(byte *)"[printto(\"");
    FUN_0046bec5((int *)(unaff_EBP + -0x14));
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = 3;
      piVar3 = (int *)FUN_0046607b();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0046bfbe((void *)(unaff_EBP + 8),piVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046bec5((int *)(unaff_EBP + -0x14));
      goto LAB_00473dd9;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0047a913();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046bec5((int *)(unaff_EBP + 8));
  uVar6 = 0;
LAB_0047424f:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar6;
}



undefined4 FUN_0047379d(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  WPARAM wParam;
  LRESULT LVar4;
  undefined4 uVar5;
  void *this;
  void *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  INT_PTR IVar6;
  
  FUN_00457418();
  *(void **)(unaff_EBP + -0x10) = this;
  iVar1 = FUN_0046acae(this,100);
  SendMessageA(*(HWND *)(iVar1 + 0x1c),0x184,0,0);
  puVar2 = *(undefined4 **)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x5c) + 4);
  if (puVar2 != (undefined4 *)0x0) {
    while( true ) {
      uVar5 = puVar2[2];
      *(undefined4 *)(unaff_EBP + -0x1c) = *puVar2;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar5;
      FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x14));
      iVar3 = **(int **)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar3 = (**(code **)(iVar3 + 0x6c))(unaff_EBP + -0x14,2);
      if ((iVar3 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) != 0)) {
        wParam = SendMessageA(*(HWND *)(iVar1 + 0x1c),0x180,0,*(int *)(unaff_EBP + -0x14));
        if (wParam == 0xffffffff) {
          FUN_004679cb(*(void **)(unaff_EBP + -0x10),-1);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_0046bec5((int *)(unaff_EBP + -0x14));
          uVar5 = 0;
          goto LAB_00473888;
        }
        SendMessageA(*(HWND *)(iVar1 + 0x1c),0x19a,wParam,*(LPARAM *)(unaff_EBP + -0x18));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046bec5((int *)(unaff_EBP + -0x14));
      if (*(int *)(unaff_EBP + -0x1c) == 0) break;
      puVar2 = *(undefined4 **)(unaff_EBP + -0x1c);
    }
  }
  LVar4 = SendMessageA(*(HWND *)(iVar1 + 0x1c),0x18b,0,0);
  if (LVar4 == 0) {
    this_00 = *(void **)(unaff_EBP + -0x10);
    IVar6 = -1;
  }
  else {
    if (LVar4 != 1) {
      SendMessageA(*(HWND *)(iVar1 + 0x1c),0x186,0,0);
      goto LAB_00473880;
    }
    LVar4 = SendMessageA(*(HWND *)(iVar1 + 0x1c),0x199,0,0);
    this_00 = *(void **)(unaff_EBP + -0x10);
    IVar6 = 1;
    *(LRESULT *)((int)this_00 + 0x60) = LVar4;
  }
  FUN_004679cb(this_00,IVar6);
LAB_00473880:
  uVar5 = FUN_00467af2(*(void **)(unaff_EBP + -0x10));
LAB_00473888:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}


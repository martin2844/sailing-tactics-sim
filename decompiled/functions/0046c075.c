
TactCString * FUN_0046c075(TactCString *param_1,TactCString *param_2,TactCString *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  TactCString *pTVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
  puVar1 = (undefined4 *)**(undefined4 **)(unaff_EBP + 0x10);
  puVar2 = (undefined4 *)**(undefined4 **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0046c034((void *)(unaff_EBP + -0x10),puVar2[-2],puVar2,puVar1[-2],puVar1);
  FUN_0046bd8a(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(unaff_EBP + -0x10));
  pTVar3 = *(TactCString **)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return pTVar3;
}


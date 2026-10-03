
void FUN_0048b7e0(int *param_1)

{
  int iVar1;
  int iVar2;
  Tact2010CString *pTVar3;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c5f90;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = DAT_004fe2a8 / 0x1e;
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x38))();
  pTVar3 = FUN_0041bc70((Tact2010CString *)&stack0xffffffec,DAT_0051158c);
  pcStack_8 = (code *)0x0;
  pTVar3 = FUN_004b082f((Tact2010CString *)&stack0x00000000,s_offshore_004ecae0,pTVar3);
  pcStack_8 = (code *)CONCAT31(pcStack_8._1_3_,1);
  (**(code **)(iVar1 + 100))(10,iVar2 + 0x28,pTVar3->data);
  FUN_004b05a5(&TStack_10);
  FUN_004b05a5((Tact2010CString *)&stack0xffffffdc);
  *unaff_FS_OFFSET = 0;
  return;
}



undefined4 * FUN_00466428(void)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  FUN_004677b8(this,0,*(undefined4 *)(unaff_EBP + 0x1c));
  *this = &PTR_FUN_00488254;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a(this + 0x2b);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *this = &PTR_FUN_0048815c;
  _memset(this + 0x17,0,0x4c);
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(this + 0x3c) = 0;
  *(undefined1 *)(this + 0x2c) = 0;
  this[0x7d] = 0;
  this[0x2a] = iVar2;
  this[0x17] = 0x4c;
  this[0xf] = 0x7005 - (uint)(iVar2 != 0);
  this[0x26] = *(undefined4 *)(unaff_EBP + 0xc);
  uVar1 = *(uint *)(unaff_EBP + 0x14);
  this[0x1e] = this + 0x3c;
  this[0x24] = this[0x24] | uVar1 | 0x20;
  this[0x1f] = 0x104;
  this[0x20] = this + 0x2c;
  this[0x21] = 0x40;
  if (DAT_004ae694 == 0) {
    iVar2 = FUN_00467a9b();
    if (iVar2 != 0) {
      this[0x24] = this[0x24] | 0x10;
    }
    if (DAT_004ae694 == 0) goto LAB_00466512;
  }
  *(byte *)((int)this + 0x92) = *(byte *)((int)this + 0x92) | 8;
  iVar2 = FUN_0047b918();
  this[0x19] = *(undefined4 *)(iVar2 + 0xc);
LAB_00466512:
  iVar2 = *(int *)(unaff_EBP + 0x10);
  this[0x28] = FUN_004668f9;
  if (iVar2 != 0) {
    lstrcpynA((LPSTR)(this + 0x3c),*(LPCSTR *)(unaff_EBP + 0x10),0x104);
  }
  if (*(int *)(unaff_EBP + 0x18) != 0) {
    FUN_0046c00d(this + 0x2b,*(LPCSTR *)(unaff_EBP + 0x18));
    pbVar3 = (byte *)FUN_0046c276(this + 0x2b,0);
    while( true ) {
      pbVar3 = FUN_00457780(pbVar3,0x7c);
      if (pbVar3 == (byte *)0x0) break;
      *pbVar3 = 0;
      pbVar3 = pbVar3 + 1;
    }
    this[0x1a] = this[0x2b];
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return this;
}


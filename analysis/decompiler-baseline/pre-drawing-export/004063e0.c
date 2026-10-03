
void __cdecl FUN_004063e0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  HDC hdc;
  int iVar1;
  code *pcVar2;
  bool bVar3;
  HRGN h;
  HDC unaff_EBP;
  int unaff_ESI;
  HGDIOBJ unaff_retaddr;
  
  bVar3 = 699 < DAT_004a763c;
  hdc = (HDC)param_1[1];
  h = CreateRectRgn(param_2,param_3,param_4,param_5);
  SelectObject(hdc,h);
  iVar1 = *param_1;
  pcVar2 = *(code **)(iVar1 + 0x2c);
  (*pcVar2)(7);
  (*pcVar2)(0);
  Rectangle((HDC)param_1[1],(int)unaff_retaddr,param_3,param_2,(int)h);
  (**(code **)(iVar1 + 0x38))(0x7f0000);
  if (DAT_004a7bd0 < 0xaa - DAT_004a5f18) {
    FUN_00406c90(param_1,param_3,(int)unaff_retaddr,unaff_ESI);
  }
  else {
    FUN_004064d0(param_1,param_3,(int)unaff_retaddr,unaff_ESI);
  }
  SelectObject(unaff_EBP,(HGDIOBJ)((bVar3 - 1 & 0xfffffffc) + 0x14));
  DeleteObject(unaff_retaddr);
  return;
}


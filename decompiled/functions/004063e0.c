
void __cdecl
FUN_004063e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  HDC hdc;
  int iVar1;
  code *pcVar2;
  int iVar3;
  HRGN h;
  HGDIOBJ h_00;
  
  hdc = *(HDC *)(param_1 + 4);
  iVar3 = ((699 < DAT_004a763c) - 1 & 0xfffffffc) + 0x14;
  h = CreateRectRgn(param_2,param_3,param_4,param_5);
  h_00 = SelectObject(hdc,h);
  iVar1 = *(int *)param_1;
  pcVar2 = *(code **)(iVar1 + 0x2c);
  (*pcVar2)((void *)param_1,7);
  (*pcVar2)((void *)param_1,0);
  Rectangle(*(HDC *)(param_1 + 4),param_2,param_3,param_4,param_5);
  (**(code **)(iVar1 + 0x38))((void *)param_1,0x7f0000);
  if (DAT_004a7bd0 < 0xaa - DAT_004a5f18) {
    FUN_00406c90((int *)param_1,param_3,param_2,iVar3);
  }
  else {
    FUN_004064d0((int *)param_1,param_3,param_2,iVar3);
  }
  SelectObject(hdc,h_00);
  DeleteObject(h);
  return;
}


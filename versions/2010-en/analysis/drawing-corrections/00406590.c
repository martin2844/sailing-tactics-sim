
void __cdecl
FUN_00406590(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  HDC hdc;
  int iVar1;
  code *pcVar2;
  int iVar3;
  HRGN h;
  HGDIOBJ h_00;
  
  hdc = (HDC)param_1[1];
  iVar3 = ((699 < DAT_004fe624) - 1 & 0xfffffffc) + 0x14;
  h = CreateRectRgn(param_2,param_3,param_4,param_5);
  h_00 = SelectObject(hdc,h);
  iVar1 = *param_1;
  pcVar2 = *(code **)(iVar1 + 0x2c);
  (*pcVar2)(param_1,7);
  (*pcVar2)(param_1,0);
  Rectangle((HDC)param_1[1],param_2,param_3,param_4,param_5);
  (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
  if (DAT_004fecd0 < 0xaa - DAT_004fae68) {
    FUN_00406e40(param_1,param_3,param_2,iVar3);
  }
  else {
    FUN_00406680(param_1,param_3,param_2,iVar3);
  }
  SelectObject(hdc,h_00);
  DeleteObject(h);
  return;
}


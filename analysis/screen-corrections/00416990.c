
void __cdecl FUN_00416990(int *param_1,int param_2)

{
  if (DAT_004ac92c == 0) {
    if (param_2 == 1) {
      (**(code **)(*param_1 + 0x38))(param_1,0xff);
    }
    if (param_2 == 2) {
      (**(code **)(*param_1 + 0x38))(param_1,0xff00);
    }
    if (((param_2 == 3) || (param_2 == 0xc)) || (param_2 == 0x15)) {
      (**(code **)(*param_1 + 0x38))(param_1,0x7f7f);
    }
    if (((param_2 == 4) || (param_2 == 0xd)) || ((param_2 == 0x16 || (param_2 == 0)))) {
      (**(code **)(*param_1 + 0x38))(param_1,0x7f7f7f);
    }
    if (((param_2 == 5) || (param_2 == 0xe)) || (param_2 == 0x17)) {
      (**(code **)(*param_1 + 0x38))(param_1,0x7f7f);
    }
    if (((param_2 == 6) || (param_2 == 0xf)) || (param_2 == 0x18)) {
      (**(code **)(*param_1 + 0x38))(param_1,0xff00ff);
    }
    if (((param_2 == 7) || (param_2 == 0x10)) || (param_2 == 0x19)) {
      (**(code **)(*param_1 + 0x38))(param_1,0);
    }
    if (((param_2 == 8) || (param_2 == 0x11)) || (param_2 == 0x1a)) {
      (**(code **)(*param_1 + 0x38))(param_1,0x7f);
    }
    if (((param_2 == 9) || (param_2 == 0x12)) || (param_2 == 0x1b)) {
      (**(code **)(*param_1 + 0x38))(param_1,0x7f00);
    }
    if (((param_2 == 10) || (param_2 == 0x13)) || (param_2 == 0x1c)) {
      (**(code **)(*param_1 + 0x38))(param_1,0x7f007f);
    }
    if (((param_2 == 0xb) || (param_2 == 0x14)) || (0x1c < param_2)) {
      (**(code **)(*param_1 + 0x38))(param_1,0xffff00);
      return;
    }
  }
  else {
    (**(code **)(*param_1 + 0x38))(param_1,0);
  }
  return;
}



undefined4 FUN_00476980(HWND__ *param_1,HWND__ *param_2)

{
  do {
    if (param_1 == param_2) {
      return 1;
    }
    param_2 = AfxGetParentOwner(param_2);
  } while (param_2 != (HWND__ *)0x0);
  return 0;
}


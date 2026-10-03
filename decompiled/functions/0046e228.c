
undefined4 FUN_0046e228(uint param_1)

{
  int iVar1;
  bool bVar2;
  
  if (0x10b < param_1) {
    if (param_1 == 0x3e3) {
      return 10;
    }
    if (param_1 == 0x3e4) {
      return 10;
    }
    if (param_1 == 0x3e5) {
      return 10;
    }
    if (param_1 == 999) {
      return 5;
    }
    return 1;
  }
  if (param_1 == 0x10b) {
    return 3;
  }
  if (param_1 < 0x3f) {
    if (param_1 == 0x3e) {
      return 8;
    }
    switch(param_1) {
    case 0:
      return 0;
    default:
      return 1;
    case 2:
    case 6:
    case 0x12:
      return 2;
    case 3:
    case 0xf:
    case 0x11:
    case 0x22:
    case 0x34:
    case 0x35:
    case 0x37:
      goto LAB_0046e312;
    case 4:
    case 0x24:
      return 4;
    case 5:
    case 0xc:
    case 0x13:
    case 0x1d:
    case 0x36:
    case 0x3a:
      return 5;
    case 0xb:
    case 0x1a:
    case 0x3c:
      return 6;
    case 0x10:
      return 7;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x39:
    case 0x3b:
      goto LAB_0046e312;
    case 0x18:
    case 0x19:
    case 0x1b:
    case 0x1e:
      return 9;
    case 0x20:
      return 0xb;
    case 0x21:
      return 0xc;
    case 0x26:
      return 0xe;
    case 0x27:
      return 0xd;
    }
  }
  if (param_1 < 0x6c) {
    if (param_1 == 0x6b) {
      return 2;
    }
    if (param_1 < 0x48) {
      if (param_1 == 0x47) {
        return 5;
      }
      if (param_1 == 0x40) {
        return 5;
      }
      if (param_1 == 0x41) {
        return 5;
      }
      if (param_1 == 0x42) {
        return 6;
      }
      if (param_1 == 0x43) {
        return 3;
      }
      iVar1 = param_1 - 0x44;
      if (iVar1 == 0) {
        return 4;
      }
LAB_0046e2e8:
      bVar2 = iVar1 == 2;
      goto LAB_0046e2ea;
    }
    if (param_1 == 0x50) {
      return 5;
    }
    if (param_1 == 0x52) {
      return 5;
    }
    if (param_1 == 0x55) {
      return 3;
    }
    if (param_1 == 0x56) {
      return 5;
    }
    bVar2 = param_1 == 0x58;
  }
  else {
    if (param_1 < 0x70) {
      if (param_1 == 0x6f) {
        return 3;
      }
      if (param_1 == 0x6c) {
        return 0xc;
      }
      return 1;
    }
    if (0x90 < param_1) {
      if (param_1 < 0x9b) {
        if (param_1 == 0x9a) {
          return 3;
        }
        if (param_1 == 0x91) {
          return 7;
        }
        return 1;
      }
      if (0xa7 < param_1) {
        if (param_1 == 0xaa) {
          return 5;
        }
        if (param_1 == 0xb6) {
          return 6;
        }
        if (param_1 == 0xb7) {
          return 5;
        }
        if (param_1 == 0xbf) {
          return 6;
        }
        if (param_1 == 0xc1) {
          return 6;
        }
        iVar1 = param_1 - 0xce;
        if (iVar1 == 0) {
          return 3;
        }
        goto LAB_0046e2e8;
      }
      if (param_1 == 0xa7) {
        return 0xc;
      }
      bVar2 = param_1 == 0xa1;
LAB_0046e2ea:
      if (!bVar2) {
        return 1;
      }
LAB_0046e312:
      return 3;
    }
    if (param_1 == 0x90) {
      return 3;
    }
    if (0x7b < param_1) {
      if (param_1 == 0x7c) {
        return 3;
      }
      if (param_1 == 0x7d) {
        return 3;
      }
      if (param_1 == 0x83) {
        return 9;
      }
      if (param_1 == 0x84) {
        return 9;
      }
      return 1;
    }
    if (param_1 == 0x7b) {
      return 3;
    }
    if (param_1 == 0x70) {
      return 0xd;
    }
    if (param_1 == 0x71) {
      return 4;
    }
    if (param_1 == 0x72) {
      return 6;
    }
    bVar2 = param_1 == 0x75;
  }
  if (!bVar2) {
    return 1;
  }
LAB_0046e312:
  return 10;
}


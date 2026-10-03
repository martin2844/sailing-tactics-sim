
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_0046616f(void *this,byte *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  byte *pbVar5;
  uint uVar6;
  undefined3 extraout_var;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  bool bVar10;
  int local_10;
  int *local_c;
  
  piVar2 = param_2;
  local_10 = 0;
  bVar3 = *param_1;
  pbVar5 = param_1;
  piVar8 = param_2;
  do {
    if (bVar3 == 0) {
      FUN_0046c276(this,local_10);
      FUN_00458cf0(*(undefined1 **)this,(char *)param_1,piVar2);
      FUN_0046c2c5(this,-1);
      return;
    }
    if (*pbVar5 == 0x25) {
      pbVar5 = FUN_00457e60(pbVar5);
      bVar3 = *pbVar5;
      if (bVar3 == 0x25) goto LAB_00466396;
      piVar9 = (int *)0x0;
      param_2 = (int *)0x0;
      piVar7 = piVar8;
      while (bVar3 != 0) {
        if (bVar3 == 0x23) {
          local_10 = local_10 + 2;
        }
        else if (bVar3 == 0x2a) {
          param_2 = (int *)*piVar7;
          piVar7 = piVar7 + 1;
        }
        else if ((((bVar3 != 0x2d) && (bVar3 != 0x2b)) && (bVar3 != 0x30)) && (bVar3 != 0x20))
        break;
        pbVar5 = FUN_00457e60(pbVar5);
        bVar3 = *pbVar5;
      }
      if (param_2 == (int *)0x0) {
        param_2 = (int *)FUN_00458260(pbVar5);
        while ((*pbVar5 != 0 && (uVar6 = FUN_00458d80((int)(char)*pbVar5), uVar6 != 0))) {
          pbVar5 = FUN_00457e60(pbVar5);
        }
      }
      local_c = (int *)0x0;
      if (*pbVar5 == 0x2e) {
        pbVar5 = FUN_00457e60(pbVar5);
        if (*pbVar5 == 0x2a) {
          local_c = (int *)*piVar7;
          piVar7 = piVar7 + 1;
          pbVar5 = FUN_00457e60(pbVar5);
        }
        else {
          local_c = (int *)FUN_00458260(pbVar5);
          while ((*pbVar5 != 0 && (uVar6 = FUN_00458d80((int)(char)*pbVar5), uVar6 != 0))) {
            pbVar5 = FUN_00457e60(pbVar5);
          }
        }
      }
      bVar3 = *pbVar5;
      uVar6 = 0;
      if (((bVar3 == 0x46) || (bVar3 == 0x4c)) || (bVar3 == 0x4e)) {
LAB_0046627b:
        pbVar5 = FUN_00457e60(pbVar5);
      }
      else {
        if (bVar3 == 0x68) {
          uVar6 = 0x10000;
          goto LAB_0046627b;
        }
        if (bVar3 == 0x6c) {
          uVar6 = 0x20000;
          goto LAB_0046627b;
        }
      }
      uVar6 = uVar6 | (int)(char)*pbVar5;
      piVar8 = piVar7;
      if ((int)uVar6 < 0x54) {
        if (uVar6 == 0x53) goto LAB_004662da;
        bVar10 = uVar6 == 0x43;
LAB_004662b5:
        if (bVar10) {
LAB_0046630e:
          piVar9 = (int *)0x2;
          piVar8 = piVar7 + 1;
        }
      }
      else {
        if (0x73 < (int)uVar6) {
          if ((int)uVar6 < 0x10054) {
            if (uVar6 == 0x10053) goto LAB_004662ed;
            bVar10 = uVar6 == 0x10043;
            goto LAB_004662b5;
          }
          if (uVar6 != 0x10063) {
            if (uVar6 == 0x10073) goto LAB_004662ed;
            if (uVar6 != 0x20043) {
              if (uVar6 != 0x20053) {
                if (uVar6 == 0x20063) goto LAB_0046630e;
                if (uVar6 != 0x20073) goto LAB_00466314;
              }
LAB_004662da:
              if ((short *)*piVar7 == (short *)0x0) goto LAB_004662f7;
              piVar9 = (int *)FUN_00457d90((short *)*piVar7);
              goto LAB_00466302;
            }
          }
          goto LAB_0046630e;
        }
        if (uVar6 == 0x73) {
LAB_004662ed:
          if ((LPCSTR)*piVar7 == (LPCSTR)0x0) {
LAB_004662f7:
            piVar9 = (int *)&DAT_00000006;
          }
          else {
            piVar9 = (int *)lstrlenA((LPCSTR)*piVar7);
LAB_00466302:
            piVar8 = piVar7 + 1;
            if (0 < (int)piVar9) goto LAB_00466314;
            piVar9 = (int *)0x1;
          }
          piVar8 = piVar7 + 1;
        }
        else if (uVar6 == 99) goto LAB_0046630e;
      }
LAB_00466314:
      if (piVar9 == (int *)0x0) {
        bVar3 = *pbVar5;
        if ((char)bVar3 < 'Y') {
          if (bVar3 == 0x58) {
LAB_00466371:
            piVar8 = piVar8 + 1;
            piVar9 = (int *)0x20;
          }
          else {
            if (bVar3 != 0x47) goto LAB_0046638c;
LAB_00466352:
            piVar8 = piVar8 + 2;
            piVar9 = (int *)0x80;
          }
          local_c = (int *)((int)local_c + (int)param_2);
          bVar10 = SBORROW4((int)local_c,(int)piVar9);
          iVar1 = (int)local_c - (int)piVar9;
          goto LAB_00466383;
        }
        if ((char)bVar3 < 'j') {
          if ((bVar3 == 0x69) || (bVar3 == 100)) goto LAB_00466371;
          if (('d' < (char)bVar3) && ((char)bVar3 < 'h')) goto LAB_00466352;
        }
        else if (bVar3 == 0x6e) {
          piVar8 = piVar8 + 1;
        }
        else if (((bVar3 == 0x6f) || (bVar3 == 0x70)) || ((bVar3 == 0x75 || (bVar3 == 0x78))))
        goto LAB_00466371;
      }
      else {
        if ((int)piVar9 <= (int)param_2) {
          piVar9 = param_2;
        }
        if (local_c == (int *)0x0) goto LAB_0046638c;
        bVar10 = SBORROW4((int)piVar9,(int)local_c);
        iVar1 = (int)piVar9 - (int)local_c;
LAB_00466383:
        if (bVar10 == iVar1 < 0) {
          piVar9 = local_c;
        }
      }
LAB_0046638c:
      local_10 = local_10 + (int)piVar9;
    }
    else {
LAB_00466396:
      cVar4 = FUN_00458d60(pbVar5);
      local_10 = local_10 + CONCAT31(extraout_var,cVar4);
    }
    pbVar5 = FUN_00457e60(pbVar5);
    bVar3 = *pbVar5;
  } while( true );
}



void __thiscall FUN_00473572(void *this,void *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  COLORREF CVar5;
  uint uVar6;
  int iVar7;
  int local_30;
  int local_2c;
  int local_24;
  
  uVar4 = *(uint *)((int)this + 100);
  if ((uVar4 & 0xf00) != 0) {
    local_30 = param_2[2];
    local_2c = param_2[3];
    local_24 = param_2[1];
    iVar7 = param_2[3];
    CVar5 = DAT_004ae664;
    if (DAT_004ae694 == 0) {
      CVar5 = DAT_004ae670;
    }
    if ((uVar4 & 0x80) != 0) {
      local_30 = local_30 + -1;
      local_2c = local_2c + -1;
    }
    uVar1 = uVar4 & 0x200;
    if (uVar1 != 0) {
      local_24 = local_24 + DAT_004ae64c;
    }
    uVar2 = uVar4 & 0x800;
    if (uVar2 != 0) {
      iVar7 = iVar7 - DAT_004ae64c;
    }
    uVar3 = uVar4 & 0x100;
    if (uVar3 != 0) {
      FUN_00478aeb(param_1,0,local_24,1,iVar7 - local_24,CVar5);
    }
    if (uVar1 != 0) {
      FUN_00478aeb(param_1,0,0,param_2[2],1,CVar5);
    }
    uVar6 = uVar4 & 0x400;
    if (uVar6 != 0) {
      FUN_00478aeb(param_1,local_30,local_24,-1,iVar7 - local_24,CVar5);
    }
    if (uVar2 != 0) {
      FUN_00478aeb(param_1,0,local_2c,param_2[2],-1,CVar5);
    }
    CVar5 = DAT_004ae668;
    if ((uVar4 & 0x80) != 0) {
      if (uVar3 != 0) {
        FUN_00478aeb(param_1,1,local_24,1,iVar7 - local_24,DAT_004ae668);
      }
      if (uVar1 != 0) {
        FUN_00478aeb(param_1,0,1,param_2[2],1,CVar5);
      }
      if (uVar6 != 0) {
        FUN_00478aeb(param_1,param_2[2],local_24,-1,iVar7 - local_24,CVar5);
      }
      if (uVar2 != 0) {
        FUN_00478aeb(param_1,0,param_2[3],param_2[2],-1,CVar5);
      }
    }
    if (uVar3 != 0) {
      *param_2 = *param_2 + DAT_004ae648;
    }
    if (uVar1 != 0) {
      param_2[1] = param_2[1] + DAT_004ae64c;
    }
    if (uVar6 != 0) {
      param_2[2] = param_2[2] - DAT_004ae648;
    }
    if (uVar2 != 0) {
      param_2[3] = param_2[3] - DAT_004ae64c;
    }
  }
  return;
}


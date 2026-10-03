/* Closed controller oracle for the exact preserved 2010 English executable.
 * Command 2 calls only the validated MFC message-map table or these fixed input
 * handlers. The original MFC Default and TLS lookup execute unchanged against
 * an owned window/vtable and a real isolated TLS slot; executable bytes and
 * original readonly vtables are never changed. Two temporary mutable framework
 * bindings are restored before complete-state hashing and recorded separately.
 * Full modal-window lifecycles are intentionally excluded from this command.
 */
#define CONTROLLER_EVENT_BYTES 65536u
#define CONTROLLER_WINDOW 0x20000001u
static uint8_t controller_events[CONTROLLER_EVENT_BYTES];
static uint32_t controller_event_length;
static uint32_t controller_vtable[48],controller_view[16],controller_ui_vtable[2],controller_ui[4];
static uint32_t controller_tls_manager[2],controller_tls_container[4],controller_tls_slots[2];
static uint8_t controller_thread_state[0x118];
static uint32_t controller_tls_initialized;
static volatile uintptr_t controller_target __attribute__((used));
static volatile uintptr_t controller_output __attribute__((used));
static volatile uintptr_t controller_stack __attribute__((used));
static volatile uintptr_t controller_this __attribute__((used));

struct controller_entry { uint32_t command,address,update; };
#include "native_controller_table.h"

static void controller_event(uint32_t op,const void *bytes,uint32_t count) {
  if (count>CONTROLLER_EVENT_BYTES-8 || controller_event_length>CONTROLLER_EVENT_BYTES-8-count)
    fail("controller event evidence exceeds fixed bound");
  memcpy(controller_events+controller_event_length,&op,4);
  memcpy(controller_events+controller_event_length+4,&count,4);
  memcpy(controller_events+controller_event_length+8,bytes,count);
  controller_event_length+=8+count;
}
static BOOL WINAPI controller_invalidate(HWND window,const RECT *rectangle,BOOL erase) {
  if ((uintptr_t)window!=CONTROLLER_WINDOW) fail("controller used an unowned window handle");
  int32_t values[7]={(int32_t)(uintptr_t)window,rectangle!=NULL,0,0,0,0,erase};
  if (rectangle) {values[2]=rectangle->left;values[3]=rectangle->top;values[4]=rectangle->right;values[5]=rectangle->bottom;}
  controller_event(1,values,sizeof(values));return TRUE;
}
static uint32_t __attribute__((thiscall)) controller_default(void *window,uint32_t message,uint32_t wparam,uint32_t lparam) {
  if (window!=controller_view) fail("MFC Default used an unowned window object");
  uint32_t values[4]={message,wparam,lparam,1};controller_event(2,values,sizeof(values));return 1;
}
static void __attribute__((thiscall)) controller_enable(void *ui,int32_t enabled) {
  if (ui!=controller_ui) fail("CCmdUI Enable used an unowned object");
  controller_event(3,&enabled,4);
}
static void __attribute__((thiscall)) controller_check(void *ui,int32_t checked) {
  if (ui!=controller_ui) fail("CCmdUI Check used an unowned object");
  controller_event(4,&checked,4);
}

/* A distinct thiscall thunk with only reviewed fixed targets from this header. */
static void __attribute__((naked,noinline)) invoke_controller(uintptr_t target __attribute__((unused)),const uint32_t *words __attribute__((unused)),uint32_t count __attribute__((unused)),void *output __attribute__((unused)),void *owned_this __attribute__((unused))) {
  __asm__ volatile(
    ".intel_syntax noprefix\n"
    "push ebp\n push ebx\n push esi\n push edi\n"
    "mov DWORD PTR [_controller_stack],esp\n"
    "mov eax,DWORD PTR [esp+20]\n mov DWORD PTR [_controller_target],eax\n"
    "mov eax,DWORD PTR [esp+32]\n mov DWORD PTR [_controller_output],eax\n"
    "mov eax,DWORD PTR [esp+36]\n mov DWORD PTR [_controller_this],eax\n"
    "mov esi,DWORD PTR [esp+24]\n mov ecx,DWORD PTR [esp+28]\n"
    "lea eax,[ecx*4+16]\n sub esp,eax\n and esp,-16\n add esp,4\n"
    "mov edi,esp\n cld\n rep movsd\n"
    "xor eax,eax\n xor ebx,ebx\n xor edx,edx\n xor esi,esi\n xor edi,edi\n xor ebp,ebp\n"
    "mov ecx,DWORD PTR [_controller_this]\n push 0x202\n popfd\n"
    "call DWORD PTR [_controller_target]\n"
    "mov ecx,DWORD PTR [_controller_output]\n mov DWORD PTR [ecx],eax\n mov DWORD PTR [ecx+4],edx\n"
    "mov esp,DWORD PTR [_controller_stack]\n pop edi\n pop esi\n pop ebx\n pop ebp\n ret\n"
    ".att_syntax prefix\n");
}

static void prepare_controller_objects(void) {
  if (!controller_tls_initialized) {
    DWORD slot=TlsAlloc();
    if (slot==TLS_OUT_OF_INDEXES) fail("owned MFC thread slot allocation failed");
    controller_tls_manager[0]=slot;
    controller_tls_slots[1]=(uint32_t)(uintptr_t)controller_thread_state;
    controller_tls_container[2]=2;
    controller_tls_container[3]=(uint32_t)(uintptr_t)controller_tls_slots;
    if (!TlsSetValue(slot,controller_tls_container)) fail("owned MFC thread slot binding failed");
    controller_tls_initialized=1;
  }
  memset(controller_view,0,sizeof(controller_view));memset(controller_vtable,0,sizeof(controller_vtable));
  controller_vtable[0xa8/4]=(uint32_t)(uintptr_t)controller_default;
  controller_view[0]=(uint32_t)(uintptr_t)controller_vtable;controller_view[0x1c/4]=CONTROLLER_WINDOW;
  controller_ui_vtable[0]=(uint32_t)(uintptr_t)controller_enable;
  controller_ui_vtable[1]=(uint32_t)(uintptr_t)controller_check;
  memset(controller_ui,0,sizeof(controller_ui));controller_ui[0]=(uint32_t)(uintptr_t)controller_ui_vtable;
  bind_import("InvalidateRect",(uintptr_t)controller_invalidate);
  controller_event_length=0;
}

static uint32_t controller_lookup(uint32_t id,int update) {
  for (unsigned index=0;index<sizeof(controller_entries)/sizeof(controller_entries[0]);index++) {
    if (controller_entries[index].command==id) {
      uint32_t target=update?controller_entries[index].update:controller_entries[index].address;
      if (!target) fail("modal entry requires a separately declared original window host");
      return target;
    }
  }
  fail("controller command is outside the exact message-map whitelist");return 0;
}
static uint32_t controller_dialog_lookup(uint32_t identifier) {
  for (unsigned index=0;index<sizeof(controller_dialog_entries)/sizeof(controller_dialog_entries[0]);index++)
    if (controller_dialog_entries[index][0]==identifier) return controller_dialog_entries[index][1];
  fail("dialog radio is outside the exact message-map whitelist");return 0;
}

/* Request after command2: kind,id,flags,seed,count, words[count], patchCount,
 * [absolute data address,byteCount,bytes]. No caller pointers are accepted.
 * Kinds:1key,2menu,3update,4left,5right,6move,7wheel,8radio,9save,10restore.
 * Response: same72-byte numerical envelope (kind as first word), deltas, then
 * eventByteCount/events and two raw framework binding rows of four U32 each.
 */
static void run_controller_case(void) {
  uint32_t kind,identifier,flags,seed,count,words[4]={0},patches;
  read_exact(&kind,4);read_exact(&identifier,4);read_exact(&flags,4);read_exact(&seed,4);read_exact(&count,4);
  const uint32_t arities[11]={0,3,0,0,3,3,3,4,0,0,0};
  if (!kind || kind>10 || flags>3 || count!=arities[kind] || ((kind==1 || (kind>=4 && kind<=7) || kind>=9) && identifier))
    fail("controller kind or argument count is outside the fixed contract");
  read_exact(words,count*4);
  if (flags&1) { release_global_strings();cstring_active=0; }
  if (flags&1) {
    uint32_t tls_index;memcpy(&tls_index,(void *)TLS_ADDRESS,4);
    memcpy((void *)DATA_BASE,baseline,DATA_BYTES);memcpy((void *)TLS_ADDRESS,&tls_index,4);
  }
  if (flags&2) memcpy(tls_record+0x14,&seed,4);
  read_exact(&patches,4);
  if (patches>1024) fail("controller data patches exceed fixed bound");
  for (uint32_t index=0;index<patches;index++) {
    uint32_t address,length;read_exact(&address,4);read_exact(&length,4);
    if (address<DATA_BASE || address>=DATA_BASE+DATA_BYTES || !length || length>DATA_BASE+DATA_BYTES-address ||
        (address<TLS_ADDRESS+4 && address+length>TLS_ADDRESS) ||
        (address<0x538014 && address+length>0x538010) || (address<0x53814c && address+length>0x538148))
      fail("controller patch overlaps runtime binding or immutable data");
    read_exact((void *)(uintptr_t)address,length);
  }
  prepare_controller_objects();
  uint32_t target,call_count=count;
  if (kind==1) target=0x491db0;
  else if (kind==2) target=controller_lookup(identifier,0);
  else if (kind==3) {target=controller_lookup(identifier,1);words[0]=(uint32_t)(uintptr_t)controller_ui;call_count=1;}
  else if (kind==4) target=0x493350;
  else if (kind==5) target=0x4934b0;
  else if (kind==6) target=0x4964c0;
  else if (kind==7) target=0x497600;
  else if (kind==8) target=controller_dialog_lookup(identifier);
  else {
    if (*(int32_t *)0x4da194>30) fail("snapshot boat count exceeds original bounded storage");
    target=kind==9?0x4645a0:0x464180;
  }
  memset(controller_thread_state,0,sizeof(controller_thread_state));
  uint32_t message=kind==1?0x100:kind==4?0x201:kind==5?0x204:kind==6?0x200:kind==7?0x20a:0x111;
  uint32_t wparam=kind==1?words[0]:kind==7?(words[0]&0xffff)|(words[1]<<16):kind>=4&&kind<=6?words[0]:identifier;
  uint32_t lparam=kind==1?(words[1]&0xffff)|(words[2]<<16):kind==7?(words[2]&0xffff)|(words[3]<<16):kind>=4&&kind<=6?(words[1]&0xffff)|(words[2]<<16):0;
  memcpy(controller_thread_state+0x38,&message,4);memcpy(controller_thread_state+0x3c,&wparam,4);memcpy(controller_thread_state+0x40,&lparam,4);
  normalize_data(before);
  uint32_t bindings[8]={0x538010,0,1,0,0x538148,0,(uint32_t)(uintptr_t)controller_tls_manager,0};
  memcpy(&bindings[1],(void *)0x538010,4);memcpy(&bindings[5],(void *)0x538148,4);
  memcpy((void *)0x538010,&bindings[2],4);memcpy((void *)0x538148,&bindings[6],4);
  uint8_t returns[28]={0},digest[32];uint16_t control;
  x87_reset();verify_text_unchanged();invoke_controller(target,words,call_count,returns,controller_view);
  __asm__ volatile("fnstcw %0" : "=m"(control));
  memcpy(&bindings[3],(void *)0x538010,4);memcpy(&bindings[7],(void *)0x538148,4);
  if (bindings[3]!=bindings[2] || bindings[7]!=bindings[6]) fail("original controller mutated host-owned MFC thread binding");
  memcpy((void *)0x538010,&bindings[1],4);memcpy((void *)0x538148,&bindings[5],4);
  verify_text_unchanged();hash_data(digest);
  uint32_t rng;memcpy(&rng,tls_record+0x14,4);
  size_t length=0;append_u32(&length,kind);append(&length,returns,8);append_u32(&length,rng);
  append(&length,returns+8,18);append(&length,&control,2);append(&length,digest,32);
  uint32_t changes=0;size_t count_offset=length;append_u32(&length,changes);
  for (uint32_t offset=0;offset<DATA_BYTES;) {
    if (before[offset]==normalized[offset]) {offset++;continue;}
    uint32_t first=offset;while (offset<DATA_BYTES && before[offset]!=normalized[offset]) offset++;
    uint32_t width=offset-first;append_u32(&length,DATA_BASE+first);append_u32(&length,width);
    append(&length,before+first,width);append(&length,normalized+first,width);changes++;
  }
  memcpy(response+count_offset,&changes,4);
  append_u32(&length,controller_event_length);append(&length,controller_events,controller_event_length);
  append(&length,bindings,sizeof(bindings));
  /* Optional observations for a controller inside a retained original race.
   * Standalone controller replies retain their existing byte-for-byte schema.
   * Neither the original string objects nor their allocator are replaced. */
  if (global_strings_live) {
    append_u32(&length,0x52545343u); /* little-endian CSTR */
    append_u32(&length,36);
    for (uint32_t index=0;index<36;index++) {
      uint32_t address=index?0x4fec30+(index-1)*4:0x4fdfd4,pointer,size=0;
      memcpy(&pointer,(void *)(uintptr_t)address,4);
      if (!pointer) fail("retained controller CString has no original data pointer");
      while (size<4096 && ((const uint8_t *)(uintptr_t)pointer)[size]) size++;
      if (size==4096) fail("retained controller CString exceeds fixed text bound");
      append_u32(&length,address);append_u32(&length,pointer);append_u32(&length,size);
      append(&length,(void *)(uintptr_t)pointer,size);
    }
  }
  uint32_t command=2,response_length=(uint32_t)length;
  write_exact(&command,4);write_exact(&response_length,4);write_exact(response,length);
}

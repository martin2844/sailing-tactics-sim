/* Fixed, bounded original-code oracle for the preserved 2010 English edition.
 * Its dedicated PE section owns the original preferred address range. The
 * target file and executable section are never modified. No target address is
 * supplied by the protocol: only the reviewed routine IDs below are callable.
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wincrypt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>

_Static_assert(sizeof(void *) == 4, "Original code requires i386");
#define IMAGE_BYTES 0x21c000u
#define DATA_BASE 0x4da000u
#define DATA_BYTES 0x60588u
#define TLS_ADDRESS 0x4ee000u
#define MAX_REPLY (DATA_BYTES * 6u + 2097152u + 65536u)
static const uint8_t expected_sha[32] = {
  0xd7,0x07,0xa1,0xe1,0xb5,0x89,0x4a,0xdf,0x88,0x04,0x70,0xdd,0x3a,0xf3,0x10,0x4b,
  0xc2,0xe2,0x56,0xaa,0xfa,0xa8,0x93,0x20,0x90,0xb8,0xa1,0x1d,0x13,0x7a,0xc7,0x87};
__attribute__((section(".tact_original"),used,aligned(4096)))
static uint8_t original_storage[IMAGE_BYTES];
static uint8_t tls_record[0x74];
static uint8_t *baseline, *before, *normalized, *response;
static uint8_t *file_image, *module;
static DWORD file_size;
static IMAGE_NT_HEADERS32 *headers;
static HCRYPTPROV state_hash_provider;
static uint32_t original_tls_value;
static uint32_t cstring_active,cstring_initialized;
static uint32_t global_strings_live;
static const uint32_t global_string_ranges[][2]={{0x4fdfd4,4},{0x4fec30,35*4}};
static const uint32_t cstring_ranges[][2]={
  {0x4ee160,0x80},{0x4ee220,0x2024},{0x538720,0x60},{0x53992c,4},{0x53878c,4},
};
static uint8_t cstring_saved[0x80+0x2024+0x60+4+4];
static volatile uintptr_t invoke_target __attribute__((used));
static volatile uintptr_t invoke_output __attribute__((used));
static volatile uintptr_t invoke_saved_stack __attribute__((used));
static volatile uint32_t invoke_float __attribute__((used));

static void fail(const char *message) {
  fprintf(stderr,"native-reference-2010: %s (Win32 error %lu)\n",message,(unsigned long)GetLastError());
  exit(2);
}
static void read_exact(void *target,size_t length) {
  if (fread(target,1,length,stdin)!=length) fail("truncated protocol input");
}
static void write_exact(const void *source,size_t length) {
  if (fwrite(source,1,length,stdout)!=length) fail("protocol output failed");
}
static void x87_reset(void) {
  const uint16_t control=0x027f;
  __asm__ volatile("fninit\n\tfldcw %0" : : "m"(control) : "memory");
}
static void append(size_t *length,const void *source,size_t count) {
  if (count>MAX_REPLY-*length) fail("response exceeds fixed bound");
  memcpy(response+*length,source,count);*length+=count;
}
static void append_u32(size_t *length,uint32_t value) { append(length,&value,4); }
static void normalize_data(uint8_t *target) {
  memcpy(target,(void *)(uintptr_t)DATA_BASE,DATA_BYTES);
  memcpy(target+TLS_ADDRESS-DATA_BASE,&original_tls_value,4);
  if (cstring_active || global_strings_live) for (unsigned index=0;index<sizeof(cstring_ranges)/sizeof(cstring_ranges[0]);index++) {
    uint32_t offset=cstring_ranges[index][0]-DATA_BASE,width=cstring_ranges[index][1];
    memcpy(target+offset,baseline+offset,width);
  }
  if (cstring_active || global_strings_live) for (unsigned index=0;index<sizeof(global_string_ranges)/sizeof(global_string_ranges[0]);index++) {
    uint32_t offset=global_string_ranges[index][0]-DATA_BASE,width=global_string_ranges[index][1];
    memcpy(target+offset,baseline+offset,width);
  }
}
static void hash_data(uint8_t digest[32]) {
  HCRYPTHASH hash;DWORD length=32;
  normalize_data(normalized);
  if (!CryptCreateHash(state_hash_provider,CALG_SHA_256,0,0,&hash) ||
      !CryptHashData(hash,normalized,DATA_BYTES,0) ||
      !CryptGetHashParam(hash,HP_HASHVAL,digest,&length,0)) fail("mutable SHA256 failed");
  CryptDestroyHash(hash);
}

/* ABI-neutral invocation preserves the host stack regardless of original
 * cdecl/stdcall cleanup. Registers start at zero; original stack words are
 * copied unchanged. ST0 is captured only for known floating return routines.
 */
static void __attribute__((naked,noinline)) invoke_original_words(uintptr_t target __attribute__((unused)),const void *words __attribute__((unused)),uint32_t count __attribute__((unused)),void *output __attribute__((unused)),uint32_t floating __attribute__((unused))) {
  __asm__ volatile(
    ".intel_syntax noprefix\n"
    "push ebp\n push ebx\n push esi\n push edi\n"
    "mov DWORD PTR [_invoke_saved_stack],esp\n"
    "mov eax,DWORD PTR [esp+20]\n mov DWORD PTR [_invoke_target],eax\n"
    "mov eax,DWORD PTR [esp+32]\n mov DWORD PTR [_invoke_output],eax\n"
    "mov eax,DWORD PTR [esp+36]\n mov DWORD PTR [_invoke_float],eax\n"
    "mov esi,DWORD PTR [esp+24]\n mov ecx,DWORD PTR [esp+28]\n"
    "lea eax,[ecx*4+16]\n sub esp,eax\n and esp,-16\n add esp,4\n"
    "mov edi,esp\n cld\n rep movsd\n"
    "xor eax,eax\n xor ebx,ebx\n xor ecx,ecx\n xor edx,edx\n xor esi,esi\n xor edi,edi\n xor ebp,ebp\n"
    "push 0x202\n popfd\n call DWORD PTR [_invoke_target]\n"
    "mov ecx,DWORD PTR [_invoke_output]\n mov DWORD PTR [ecx],eax\n mov DWORD PTR [ecx+4],edx\n"
    "cmp DWORD PTR [_invoke_float],0\n je 1f\n fst QWORD PTR [ecx+8]\n fstp TBYTE PTR [ecx+16]\n"
    "1:\n mov esp,DWORD PTR [_invoke_saved_stack]\n pop edi\n pop esi\n pop ebx\n pop ebp\n ret\n"
    ".att_syntax prefix\n");
}

/* The original layout/hash/protection/import loader is followed below. */
static void load_and_hash(const char *path) {
    HANDLE file=CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    HCRYPTPROV provider=0; HCRYPTHASH hash=0;
    DWORD received, hash_size=32; uint8_t digest[32];
    if (file==INVALID_HANDLE_VALUE) fail("opening original 2010 English executable failed");
    file_size=GetFileSize(file,NULL);
    if (file_size==INVALID_FILE_SIZE || file_size<sizeof(IMAGE_DOS_HEADER) || file_size>16*1024*1024) fail("invalid original size");
    file_image=(uint8_t *)malloc(file_size);
    if (!file_image || !ReadFile(file,file_image,file_size,&received,NULL) || received!=file_size) fail("reading preserved original failed");
    CloseHandle(file);
    if (!CryptAcquireContextA(&provider,NULL,NULL,PROV_RSA_AES,CRYPT_VERIFYCONTEXT) ||
        !CryptCreateHash(provider,CALG_SHA_256,0,0,&hash) ||
        !CryptHashData(hash,file_image,file_size,0) ||
        !CryptGetHashParam(hash,HP_HASHVAL,digest,&hash_size,0)) fail("SHA256 calculation failed");
    CryptDestroyHash(hash); CryptReleaseContext(provider,0);
    if (hash_size!=32 || memcmp(digest,expected_sha,32)) fail("preserved original SHA256 mismatch");
    IMAGE_DOS_HEADER *dos=(IMAGE_DOS_HEADER *)file_image;
    if (dos->e_magic!=IMAGE_DOS_SIGNATURE || dos->e_lfanew<0 || (DWORD)dos->e_lfanew>file_size-sizeof(IMAGE_NT_HEADERS32)) fail("invalid loaded PE header");
    headers=(IMAGE_NT_HEADERS32 *)(file_image+dos->e_lfanew);
    if (headers->Signature!=IMAGE_NT_SIGNATURE || headers->OptionalHeader.Magic!=IMAGE_NT_OPTIONAL_HDR32_MAGIC || headers->FileHeader.Machine!=IMAGE_FILE_MACHINE_I386) fail("expected i386 PE32 module");
    if (headers->OptionalHeader.ImageBase!=0x400000 || headers->OptionalHeader.SizeOfImage!=IMAGE_BYTES || headers->OptionalHeader.SizeOfHeaders>file_size) fail("expected exact preserved image layout");
    module=original_storage;
    if ((uintptr_t)module!=0x400000) fail("dedicated host-owned original-image storage is not at 0x400000");
    memset(module,0,sizeof(original_storage));
    memcpy(module,file_image,headers->OptionalHeader.SizeOfHeaders);
    IMAGE_SECTION_HEADER *section=IMAGE_FIRST_SECTION(headers);
    for (unsigned index=0;index<headers->FileHeader.NumberOfSections;index++,section++) {
        uint32_t extent=section->Misc.VirtualSize>section->SizeOfRawData?section->Misc.VirtualSize:section->SizeOfRawData;
        if (section->PointerToRawData>file_size || section->SizeOfRawData>file_size-section->PointerToRawData || section->VirtualAddress>IMAGE_BYTES || extent>IMAGE_BYTES-section->VirtualAddress) fail("invalid preserved section extent");
        memcpy(module+section->VirtualAddress,file_image+section->PointerToRawData,section->SizeOfRawData);
        DWORD protection=PAGE_NOACCESS, ignored;
        if (section->Characteristics&IMAGE_SCN_MEM_EXECUTE) protection=(section->Characteristics&IMAGE_SCN_MEM_WRITE)?PAGE_EXECUTE_READWRITE:PAGE_EXECUTE_READ;
        else if (section->Characteristics&IMAGE_SCN_MEM_WRITE) protection=PAGE_READWRITE;
        else if (section->Characteristics&IMAGE_SCN_MEM_READ) protection=PAGE_READONLY;
        if (extent && !VirtualProtect(module+section->VirtualAddress,extent,protection,&ignored)) fail("setting original section protections failed");
    }
    DWORD ignored;
    if (!VirtualProtect(module,headers->OptionalHeader.SizeOfHeaders,PAGE_READONLY,&ignored)) fail("protecting original header failed");
    headers=(IMAGE_NT_HEADERS32 *)(module+dos->e_lfanew);
}
static void verify_text_unchanged(void) {
    IMAGE_SECTION_HEADER *section=IMAGE_FIRST_SECTION(headers);
    unsigned matched=0;
    for (unsigned index=0;index<headers->FileHeader.NumberOfSections;index++,section++) {
        if (memcmp(section->Name,".text",5)) continue;
        if (section->PointerToRawData>file_size || section->SizeOfRawData>file_size-section->PointerToRawData ||
            section->VirtualAddress>headers->OptionalHeader.SizeOfImage || section->SizeOfRawData>headers->OptionalHeader.SizeOfImage-section->VirtualAddress) fail("invalid text extent");
        if (memcmp(module+section->VirtualAddress,file_image+section->PointerToRawData,section->SizeOfRawData)) fail("loaded original text differs from preserved bytes");
        matched++;
    }
    if (matched!=1) fail("expected one preserved text section");
}
static uint32_t resolve_imports(void) {
    IMAGE_DATA_DIRECTORY directory=headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    uint32_t count=0;
    if (!directory.VirtualAddress || directory.VirtualAddress>=headers->OptionalHeader.SizeOfImage) fail("missing original import directory");
    IMAGE_IMPORT_DESCRIPTOR *descriptor=(IMAGE_IMPORT_DESCRIPTOR *)(module+directory.VirtualAddress);
    for (;descriptor->Name;descriptor++) {
        HMODULE library=LoadLibraryA((char *)(module+descriptor->Name));
        if (!library) fail("loading original imported library failed");
        if (!descriptor->OriginalFirstThunk) fail("expected original import lookup table");
        IMAGE_THUNK_DATA32 *lookup=(IMAGE_THUNK_DATA32 *)(module+descriptor->OriginalFirstThunk);
        IMAGE_THUNK_DATA32 *iat=(IMAGE_THUNK_DATA32 *)(module+descriptor->FirstThunk);
        for (;lookup->u1.AddressOfData;lookup++,iat++) {
            FARPROC procedure;
            if (IMAGE_SNAP_BY_ORDINAL32(lookup->u1.Ordinal)) procedure=GetProcAddress(library,(LPCSTR)(uintptr_t)IMAGE_ORDINAL32(lookup->u1.Ordinal));
            else procedure=GetProcAddress(library,(LPCSTR)((IMAGE_IMPORT_BY_NAME *)(module+lookup->u1.AddressOfData))->Name);
            if (!procedure) fail("resolving original import failed");
            DWORD protection, ignored;
            if (!VirtualProtect(iat,sizeof(*iat),PAGE_READWRITE,&protection)) fail("making import data writable failed");
            iat->u1.Function=(DWORD)(uintptr_t)procedure;
            if (!VirtualProtect(iat,sizeof(*iat),protection,&ignored)) fail("restoring import data protection failed");
            count++;
        }
    }
    return count;
}

static void bind_import(const char *name,uintptr_t target) {
  IMAGE_DATA_DIRECTORY directory=headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
  IMAGE_IMPORT_DESCRIPTOR *descriptor=(IMAGE_IMPORT_DESCRIPTOR *)(module+directory.VirtualAddress);
  uint32_t matches=0;
  for (;descriptor->Name;descriptor++) {
    IMAGE_THUNK_DATA32 *lookup=(IMAGE_THUNK_DATA32 *)(module+descriptor->OriginalFirstThunk);
    IMAGE_THUNK_DATA32 *iat=(IMAGE_THUNK_DATA32 *)(module+descriptor->FirstThunk);
    for (;lookup->u1.AddressOfData;lookup++,iat++) {
      if (IMAGE_SNAP_BY_ORDINAL32(lookup->u1.Ordinal)) continue;
      const char *actual=(const char *)((IMAGE_IMPORT_BY_NAME *)(module+lookup->u1.AddressOfData))->Name;
      if (strcmp(name,actual)) continue;
      DWORD protection,ignored;
      if (!VirtualProtect(iat,sizeof(*iat),PAGE_READWRITE,&protection)) fail("IAT observer binding failed");
      iat->u1.Function=(DWORD)target;
      if (!VirtualProtect(iat,sizeof(*iat),protection,&ignored)) fail("IAT protection restore failed");
      matches++;
    }
  }
  if (matches!=1) fail("observer import does not identify one original slot");
}

#include "native_gdi_trace.h"

/* Only the original named IAT data slot is bound. Sound arguments are finite
 * resource IDs; no executable byte or original read-only vtable is changed. */
static uint32_t sound_count,sound_events[256][3];
static BOOL WINAPI __attribute__((noinline)) observe_sound(LPCSTR resource,HMODULE instance,DWORD flags) {
  uintptr_t id=(uintptr_t)resource;
  if (id>65535 || sound_count>=256) fail("sound request exceeds resource/event bounds");
  sound_events[sound_count][0]=(uint32_t)id;
  sound_events[sound_count][1]=(uint32_t)(uintptr_t)instance;
  sound_events[sound_count++][2]=flags;
  return TRUE;
}

static void save_cstring_runtime(void) {
  size_t offset=0;
  for (unsigned index=0;index<sizeof(cstring_ranges)/sizeof(cstring_ranges[0]);index++) {
    uint32_t width=cstring_ranges[index][1];
    if (width>sizeof(cstring_saved)-offset) fail("original runtime save bounds differ");
    memcpy(cstring_saved+offset,(void *)(uintptr_t)cstring_ranges[index][0],width);offset+=width;
  }
}
static void prepare_cstring_runtime(void) {
  if (!cstring_initialized) {
    ((void (__cdecl *)(void))0x49fde0)();
    if (!((int32_t (__cdecl *)(void))0x49fb80)()) fail("original CRT heap initialization failed");
    save_cstring_runtime();cstring_initialized=1;
  } else {
    size_t offset=0;
    for (unsigned index=0;index<sizeof(cstring_ranges)/sizeof(cstring_ranges[0]);index++) {
      uint32_t width=cstring_ranges[index][1];
      memcpy((void *)(uintptr_t)cstring_ranges[index][0],cstring_saved+offset,width);offset+=width;
    }
  }
  cstring_active=1;
}

static void release_global_strings(void) {
  if (!global_strings_live) return;
  ((void (__cdecl *)(void))0x402330)();
  ((void (__cdecl *)(void))0x4023a0)();
  global_strings_live=0;save_cstring_runtime();
}

#include "native_controller_trace.h"

/* services: bit0 GDI/CDC, bit1 ordered sound requests, bit2 original CString. */
struct routine { uintptr_t address; uint32_t words, floating, services; };
/* A closed, edition-specific list; extending it requires source review. */
static const struct routine routines[] = {
  {0,0,0,0}, {0x420c00,0,0,0}, /* complete boat options */
  {0x41bc20,1,0,0},          /* one-step degree wrap */
  {0x41bc40,2,1,0},          /* one-step radians wrap */
  {0x41e000,1,0,0},          /* original scaled CRT random */
  {0x464940,0,0,0},          /* speed divisor */
  {0x41e040,0,0,0},          /* integer trigonometric tables */
  {0x4413e0,0,0,0},          /* 449 wind random values */
  {0x49b7b0,0,0,0},          /* original CRT rand */
  {0x49b7a0,1,0,0},          /* original CRT srand */
  {0x427540,0,0,0},          /* complete global wind */
  {0x427e30,3,0,0},          /* wind schedule */
  {0x427ee0,2,0,0},          /* bearing from integer vector */
  {0x413bc0,1,0,1},          /* original start screen */
  {0x428b70,1,0,1},          /* original results screen */
  {0x4298f0,1,0,1},          /* original forecast screen */
  {0x406590,7,0,1},          /* advice CDC + six integer arguments */
  {0x427f10,1,0,1},          /* pause/tutorial dispatcher */
  {0x416910,1,0,1},          /* demo/info screen */
  {0x426ab0,0,0,0},          /* wind initialization */
  {0x427090,0,0,0},          /* tide initialization */
  {0x441400,0,0,0},          /* wind source initialization */
  {0x42b0b0,1,0,0},          /* wind patch respawn */
  {0x445860,1,0,1},          /* first original tutorial page */
  {0x446250,1,0,1}, /* tutorial page 2 */
  {0x446a70,1,0,1}, /* tutorial page 3 */
  {0x4471e0,1,0,1}, /* tutorial page 4 */
  {0x4479f0,1,0,1}, /* tutorial page 5 */
  {0x448100,1,0,1}, /* tutorial page 6 */
  {0x448970,1,0,1}, /* tutorial page 7 */
  {0x4495e0,1,0,1}, /* tutorial page 8 */
  {0x4676f0,1,0,0}, /* venue 1 point constructor */
  {0x4711b0,1,0,0}, /* venue 2 point constructor */
  {0x471f40,1,0,0}, /* venue 3 point constructor */
  {0x4729d0,1,0,0}, /* venue 4 point constructor */
  {0x4732c0,1,0,0}, /* venue 6 point constructor */
  {0x473ed0,1,0,0}, /* venue 7 point constructor */
  {0x4756c0,1,0,0}, /* venue 9 point constructor */
  {0x474b60,1,0,0}, /* venue 10 point constructor */
  {0x476db0,1,0,0}, /* venue 11 point constructor */
  {0x4762a0,1,0,0}, /* venue 12 point constructor */
  {0x479e00,1,0,0}, /* venue 100 point constructor */
  {0x479120,1,0,0}, /* venue 101 point constructor */
  {0x477b00,1,0,0}, /* venue 102 point constructor */
  {0x47c240,1,0,0}, /* venue 103 point constructor */
  {0x47aa70,1,0,0}, /* venue 104 point constructor */
  {0x47b5d0,1,0,0}, /* venue 105 point constructor */
  {0x478760,1,0,0}, /* venue 106 point constructor */
  {0x42da80,0,0,0}, /* shoreline construction */
  {0x42d280,0,0,0}, /* ellipse construction */
  {0x464a30,0,0,0}, /* advanced terrain construction */
  {0x48b8a0,1,0,0}, /* complete custom venue */
  {0x42c060,0,0,0}, /* complete course configuration */
  {0x43e160,0,0,2}, /* first-player rudder, including sound */
  {0x43df50,0,0,2}, /* complete first-player steering */
  {0x43e510,0,0,2}, /* complete second-player steering */
  {0x439e80,5,1,0}, /* distance: I32 + two F64, extended return */
  {0x431960,1,0,0}, /* reset boat at start line */
  {0x444760,0,0,0}, /* complete 30-boat trail history */
  {0x465e10,1,0,0}, /* projected waypoint history */
  {0x42f220,4,0,0}, /* integer point projection */
  {0x42f270,2,1,0}, /* shoreline metric */
  {0x42f330,3,1,0}, /* spatial metric */
  {0x42f480,2,1,0}, /* radial metric */
  {0x47d5f0,5,1,0}, /* complete venue metric */
  {0x47def0,8,0,0}, /* horizontal strip */
  {0x47dfa0,8,0,0}, /* vertical strip */
  {0x437570,1,0,2}, /* complete race target advancement */
  {0x4662d0,8,1,0}, /* clamped point distance */
  {0x466230,5,1,0}, /* nearest waypoint distance */
  {0x465ff0,1,0,0}, /* full waypoint respawn */
  {0x43cf60,0,0,2}, /* original integration and all numeric children */
  {0x406680,4,0,1}, /* jibe advice: CDC + three I32 */
  {0x406e40,4,0,1}, /* tack advice: CDC + three I32 */
  {0x41f3e0,2,0,1}, /* per-boat text color */
  {0x463c90,2,0,1}, /* advanced tutorial button */
  {0x463df0,3,0,1}, /* advanced tutorial hint */
  {0x43f9f0,1,0,0}, /* full scene depth ordering */
  {0x43fa60,3,0,0}, /* scene depth helper */
  {0x488b90,4,0,0}, /* complete attenuation scan */
  {0x431200,2,0,0}, /* shoreline current directions */
  {0x42fca0,3,0,0}, /* basic current with boat feedback */
  {0x40f240,6,0,1}, /* primary HUD CDC + five I32 */
  {0x412d30,6,0,1}, /* second HUD CDC + five I32 */
  {0x430260,3,0,0}, /* complete venue current */
  {0x42dea0,1,0,0}, /* complete start/course geometry */
  {0x42f530,0,0,2}, /* complete starting placement, current and targets */
  {0x42b2e0,0,0,6}, /* original boats, names and placement */
  {0x41be70,0,0,6}, /* original complete race initialization */
  {0x43bb70,2,1,0}, /* complete apparent wind */
  {0x41e3a0,1,0,0}, /* signed degree helper */
  {0x435f90,1,0,0}, /* update tack */
  {0x437520,1,0,0}, /* close-hauled heading */
  {0x437d40,1,1,0}, /* extended signed start distance */
  {0x439ec0,3,0,0}, /* full signed I64 relative projection */
  {0x43ec20,6,1,0}, /* F64,F64,I32,I32 target-relative bearing */
  {0x464050,2,0,0}, /* signed I64 ahead/astern */
};
static void run_case(void) {
  uint32_t id,flags,seed,count,words[16],patches;
  read_exact(&id,4);read_exact(&flags,4);read_exact(&seed,4);read_exact(&count,4);
  if (!id || id>=sizeof(routines)/sizeof(routines[0]) || count!=routines[id].words || count>16 || flags>3)
    fail("unsupported fixed routine or argument count");
  read_exact(words,count*4);
  if (flags&1) release_global_strings();
  cstring_active=0;
  if (flags&1) {
    uint32_t tls_index;memcpy(&tls_index,(void *)TLS_ADDRESS,4);
    memcpy((void *)DATA_BASE,baseline,DATA_BYTES);memcpy((void *)TLS_ADDRESS,&tls_index,4);
  }
  if (flags&2) memcpy(tls_record+0x14,&seed,4);
  read_exact(&patches,4);
  if (patches>4096) fail("too many bounded mutable patches");
  for (uint32_t index=0;index<patches;index++) {
    uint32_t address,length;read_exact(&address,4);read_exact(&length,4);
    if (address<DATA_BASE || address>=DATA_BASE+DATA_BYTES || !length ||
        length>DATA_BASE+DATA_BYTES-address || (address<TLS_ADDRESS+4 && address+length>TLS_ADDRESS))
      fail("patch changes immutable data or runtime TLS binding");
    read_exact((void *)(uintptr_t)address,length);
  }
  uint8_t *runtime_before=NULL;
  if (routines[id].services&1) {
    int32_t host[5];uint32_t pixels;
    read_exact(host,sizeof(host));read_exact(&pixels,4);
    if (host[0]<0 || host[0]>128 || host[1]<-16384 || host[1]>16384 ||
        host[2]<-16384 || host[2]>16384 || host[4]!=1 || pixels>1024)
      fail("GDI host inputs exceed fixed bounds");
    gdi_menu_height=host[0];gdi_cursor.x=host[1];gdi_cursor.y=host[2];
    gdi_tick_start=(uint32_t)host[3];gdi_tick_step=1;gdi_pixel_count=pixels;gdi_white_sampler=0;
    read_exact(gdi_pixel_values,pixels*4);
    bind_gdi_runtime();reset_gdi_trace();
    words[0]=(uint32_t)(uintptr_t)gdi_cdc;
  }
  if (routines[id].services&5) {
    prepare_cstring_runtime();
    if (!global_strings_live) {
      ((void (__cdecl *)(void))0x402310)();
      ((void (__cdecl *)(void))0x402370)();
      global_strings_live=1;
    }
    runtime_before=malloc(DATA_BYTES);
    if (!runtime_before) fail("runtime evidence allocation failed");
    memcpy(runtime_before,(void *)DATA_BASE,DATA_BYTES);
  }
  if (routines[id].services&2) {
    bind_import("PlaySoundA",(uintptr_t)observe_sound);sound_count=0;
  }
  normalize_data(before);
  uint8_t returns[28]={0},digest[32];uint16_t control;
  x87_reset();verify_text_unchanged();
  invoke_original_words(routines[id].address,words,count,returns,routines[id].floating);
  __asm__ volatile("fnstcw %0" : "=m"(control));
  verify_text_unchanged();hash_data(digest);
  uint32_t rng;memcpy(&rng,tls_record+0x14,4);
  size_t length=0;append_u32(&length,id);append(&length,returns,8);append_u32(&length,rng);
  append(&length,returns+8,18);append(&length,&control,2);append(&length,digest,32);
  uint32_t changes=0;size_t count_offset=length;append_u32(&length,changes);
  for (uint32_t offset=0;offset<DATA_BYTES;) {
    if (before[offset]==normalized[offset]) { offset++;continue; }
    uint32_t first=offset;
    while (offset<DATA_BYTES && before[offset]!=normalized[offset]) offset++;
    uint32_t size=offset-first;append_u32(&length,DATA_BASE+first);append_u32(&length,size);
    append(&length,before+first,size);append(&length,normalized+first,size);changes++;
  }
  memcpy(response+count_offset,&changes,4);
  if (routines[id].services&1) {
    append_u32(&length,gdi_event_bytes);append(&length,gdi_events,gdi_event_bytes);
  }
  if (routines[id].services&5) {
    uint32_t runtime_changes=0;size_t runtime_offset=length;append_u32(&length,runtime_changes);
    for (unsigned index=0;index<sizeof(cstring_ranges)/sizeof(cstring_ranges[0]);index++) {
      uint32_t offset=cstring_ranges[index][0]-DATA_BASE,end=offset+cstring_ranges[index][1];
      const uint8_t *actual=(const uint8_t *)DATA_BASE;
      while (offset<end) {
        if (runtime_before[offset]==actual[offset]) { offset++;continue; }
        uint32_t first=offset;
        while (offset<end && runtime_before[offset]!=actual[offset]) offset++;
        uint32_t size=offset-first;append_u32(&length,DATA_BASE+first);append_u32(&length,size);
        append(&length,runtime_before+first,size);append(&length,actual+first,size);runtime_changes++;
      }
    }
    memcpy(response+runtime_offset,&runtime_changes,4);free(runtime_before);save_cstring_runtime();
    append_u32(&length,36);
    for (uint32_t index=0;index<36;index++) {
      uint32_t address=index?0x4fec30+(index-1)*4:0x4fdfd4,pointer,size=0;
      memcpy(&pointer,(void *)(uintptr_t)address,4);
      if (!pointer) fail("original global CString has no data pointer");
      while (size<4096 && ((const uint8_t *)(uintptr_t)pointer)[size]) size++;
      if (size==4096) fail("original global CString exceeds bounded text contract");
      append_u32(&length,address);append_u32(&length,pointer);append_u32(&length,size);
      append(&length,(void *)(uintptr_t)pointer,size);
    }
    if (routines[id].services&1) {
      append_u32(&length,gdi_call_count);append(&length,gdi_call_sites,gdi_call_count*12);
    }
  }
  if (routines[id].services&2) {
    append_u32(&length,sound_count);append(&length,sound_events,sound_count*12);
  }
  uint32_t command=1,response_length=(uint32_t)length;
  write_exact(&command,4);write_exact(&response_length,4);write_exact(response,length);
}

int main(int argc,char **argv) {
  if (argc!=2) { fprintf(stderr,"Usage: native-reference-2010.exe ORIGINAL_2010_EN_EXE\n");return 2; }
  if ((uintptr_t)original_storage!=0x400000 || (uintptr_t)GetModuleHandleA(NULL)!=0x300000)
    fail("host and owned original image have unexpected addresses");
  MEMORY_BASIC_INFORMATION owned;
  if (!VirtualQuery(original_storage,&owned,sizeof(owned)) || owned.AllocationBase!=(void *)0x300000 || owned.Type!=MEM_IMAGE)
    fail("original storage is not owned by host PE");
  _setmode(_fileno(stdin),_O_BINARY);_setmode(_fileno(stdout),_O_BINARY);setvbuf(stdout,NULL,_IONBF,0);
  SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX|SEM_NOOPENFILEERRORBOX);
  load_and_hash(argv[1]);verify_text_unchanged();uint32_t imports=resolve_imports();
  if (imports!=358) { fprintf(stderr,"actual imported slots: %lu\n",(unsigned long)imports);fail("import count differs from preserved edition"); }
  memcpy(&original_tls_value,(void *)TLS_ADDRESS,4);
  uint32_t tls_index=TlsAlloc();
  if (tls_index==TLS_OUT_OF_INDEXES || !TlsSetValue(tls_index,tls_record)) fail("isolated original CRT thread record failed");
  memcpy((void *)TLS_ADDRESS,&tls_index,4);uint32_t seed=1;memcpy(tls_record+0x14,&seed,4);
  baseline=malloc(DATA_BYTES);before=malloc(DATA_BYTES);normalized=malloc(DATA_BYTES);response=malloc(MAX_REPLY);
  gdi_events=malloc(GDI_BYTES);
  if (!baseline || !before || !normalized || !response || !gdi_events) fail("bounded evidence allocation failed");
  if (!CryptAcquireContextA(&state_hash_provider,NULL,NULL,PROV_RSA_AES,CRYPT_VERIFYCONTEXT)) fail("hash provider failed");
  x87_reset();((void (__cdecl *)(void))0x41e040)();verify_text_unchanged();normalize_data(baseline);
  write_exact("TACT2010",8);
  uint32_t hello[7]={1,0x400000,IMAGE_BYTES,0x027f,imports,DATA_BASE,DATA_BYTES};
  write_exact(hello,sizeof(hello));write_exact(baseline,DATA_BYTES);
  uint32_t command,operations=0;
  while (fread(&command,1,4,stdin)==4) {
    if (++operations>100000) fail("command count exceeds fixed bound");
    if (!command) {
      verify_text_unchanged();uint32_t ending[3]={0,4,1};write_exact(ending,sizeof(ending));
      CryptReleaseContext(state_hash_provider,0);TlsFree(tls_index);return 0;
    }
    if (command==1) run_case();
    else if (command==2) run_controller_case();
    else fail("unsupported protocol command");
  }
  fail("protocol ended without integrity command");return 2;
}

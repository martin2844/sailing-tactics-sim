/* Bounded native reference for original 2002 routines. No code/file patching.
 * Build host PE at 0x300000; dedicated owned storage is linked at 0x400000.
 * stdin/stdout protocol is little-endian binary, diagnostics use stderr.
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
#include "native_encounter_schema.h"
#ifndef TACT_X87_CONTROL_WORD
#define TACT_X87_CONTROL_WORD 0x037f
#endif
_Static_assert(TACT_X87_CONTROL_WORD==0x037f || TACT_X87_CONTROL_WORD==0x027f,
               "Only separately documented original precision modes are supported");

_Static_assert(sizeof(void *) == 4, "The preserved executable needs an i386 runner");
_Static_assert(sizeof(long double) >= 10, "Current metric returns need an x87 80-bit value");
static const uint8_t expected_sha[32] = {
    0x88,0x1d,0xc8,0x5d,0xc7,0x50,0x0a,0x5a,0xd0,0x9e,0x09,0x09,0x1d,0x4d,0xd5,0x3f,
    0x8c,0x09,0x1f,0x56,0x30,0xd5,0xfa,0xbd,0xcc,0x88,0x7c,0xc4,0xb0,0x07,0xac,0xea};
static uint8_t tls_record[0x74];
static uint8_t *file_image, *module;
static uint8_t *image_snapshot;
static uint8_t *normalization_snapshot;
static uint8_t *encounter_baseline;
static uint8_t *mutable_pristine;
static uint32_t original_tls_value;
static HCRYPTPROV state_hash_provider;
static volatile uintptr_t invoke_target __attribute__((used));
static volatile uintptr_t invoke_output __attribute__((used));
static volatile uintptr_t invoke_saved_stack __attribute__((used));
static volatile uint32_t invoke_float __attribute__((used));
__attribute__((section(".tact_original"),used,aligned(4096)))
static uint8_t original_storage[0x111000];
static DWORD file_size;
static IMAGE_NT_HEADERS32 *headers;
static const uint32_t wind_inputs[24] = {
    0x4a4be4,0x4a609c,0x4a7758,0x4a79ec,0x4a4958,0x4aa804,0x4a4378,0x4a4430,
    0x4a70dc,0x4abc7c,0x4a5b9c,0x4ac9ac,0x4a5b80,0x4a4168,0x4a8020,0x4ac1dc,
    0x4ac9e8,0x4abae4,0x4aa590,0x4aa978,0x4911c4,0x4911c8,0x4a4f8c,0x4ac840};
static const uint32_t wind_doubles[3] = {0x4ab8b8,0x4aa6f0,0x4aa948};
static const uint32_t wind_outputs[14] = {
    0x4ac568,0x4aa390,0x4a70f0,0x4a71a4,0x4a888c,0x4a4f8c,0x4ac840,
    0x4ac9e8,0x4abae4,0x4aa590,0x4aa978,0x4911c4,0x4911c8,0x4aa298};
static const uint32_t boat_inputs[10] = {
    0x491144,0x4ac918,0x4ac91c,0x4ac920,0x4ac924,0x491188,0x4a5ba4,0x49114c,0x491194,0x4ac990};
static const uint32_t boat_outputs[14] = {
    0x491188,0x4a5ba4,0x49114c,0x491194,0x4ac990,0x4a4eec,0x4a5b90,
    0x491150,0x4ac900,0x4ac904,0x4ac908,0x4ac90c,0x4ac910,0x4ac914};
static const uint32_t current_inputs[30] = {
    0x4a60a0,0x4a4168,0x4a5b80,0x4a864c,0x4a8020,0x4ac94c,0x4a4be4,0x4ac1dc,
    0x4a5a4c,0x4ac284,0x4a3a08,0x4a4958,0x4aae1c,0x491194,0x4aa804,0x4aa290,
    0x4ac85c,0x4a67bc,0x4a67c4,0x4a67c0,0x491158,0x4a4378,0x4abae8,0x4ac840,
    0x4aa298,0x4aa800,0x4aa720,0x4aa960,0x4aa284,0x4a71a8};
static const uint32_t current_outputs[5] = {0x4aa800,0x4aa720,0x4aa960,0x4aa284,0x4a71a8};
static const uint32_t movement_inputs[6] = {0x49118c,0x491168,0x4a5b80,0x491190,0x491194,0x4a5a4c};
static const uint32_t movement_indexed_i32[4] = {0x4a4888,0x4a6f48,0x4a6e48,0x4a7868};
static const uint32_t steering_inputs[50] = {
    0x4aa824,0x4a72d0,0x4a5ba0,0x4a3f04,0x4aa808,0x4ab150,0x4a4f80,0x4a70ec,
    0x4a763c,0x491140,0x49114c,0x491188,0x491170,0x4a7044,0x4a7064,0x4a7068,
    0x4aa734,0x4aa738,0x4abe74,0x4abe78,0x4a4dfc,0x4a4e00,0x4abf9c,0x4abfa0,
    0x4a496c,0x4a4970,0x4a684c,0x4a6850,0x4a8914,0x4a8918,0x4a7bcc,0x4a7bd0,
    0x4aa5b4,0x4a5f14,0x4a5f18,0x4ac01c,0x4ac020,0x4a3a1c,0x4a3a20,0x4a5b80,
    0x4ac9c0,0x4ac1d4,0x4a774c,0x4aa97c,0x4ab188,0x4a4414,0x4a67b0,0x4a6840,
    0x4a4e8c,0x4ac8fc};
static const uint32_t steering_outputs[19] = {
    0x4a7044,0x4a4dfc,0x4a4e00,0x4abf9c,0x4abfa0,0x4a496c,0x4a4970,0x4a684c,
    0x4a6850,0x4a8914,0x4a8918,0x4ac01c,0x4ac020,0x4a3a1c,0x4a3a20,0x4a774c,
    0x4aa97c,0x4ab188,0x4a4414};
static uint32_t sound_records[16][3], sound_count, sound_bound;
static void bind_gdi_runtime(void);
static uint32_t gdi_bound;
static uint32_t cstring_active, hud_string_active;

static void fail(const char *message) {
    fprintf(stderr,"native-reference: %s (Win32 error %lu)\n",message,(unsigned long)GetLastError());
    exit(2);
}
static void read_exact(void *destination, size_t count) {
    if (fread(destination,1,count,stdin) != count) fail("truncated protocol input");
}
static void write_exact(const void *source, size_t count) {
    if (fwrite(source,1,count,stdout) != count) fail("protocol output failed");
}
static void reply(uint32_t command, const void *payload, uint32_t length) {
    write_exact(&command,4); write_exact(&length,4); write_exact(payload,length);
}
static void x87_reset(void) {
    const uint16_t control=TACT_X87_CONTROL_WORD;
    __asm__ volatile("fninit\n\tfldcw %0" : : "m"(control) : "memory");
}
static int32_t read_i32(uint32_t address) { int32_t value; memcpy(&value,(void *)(uintptr_t)address,4); return value; }
static void write_i32(uint32_t address, int32_t value) { memcpy((void *)(uintptr_t)address,&value,4); }
static void put_i32(uint8_t *buffer, size_t offset, int32_t value) { memcpy(buffer+offset,&value,4); }
static BOOL WINAPI capture_sound(LPCSTR resource, HMODULE handle, DWORD flags) {
    if (sound_count>=16) fail("sound request count exceeds bounded recorder");
    sound_records[sound_count][0]=(uint32_t)(uintptr_t)resource;
    sound_records[sound_count][1]=(uint32_t)(uintptr_t)handle;
    sound_records[sound_count][2]=flags; sound_count++;
    return TRUE;
}
static void restore_encounter_data(void) {
    normalization_snapshot=NULL;
    cstring_active=0;hud_string_active=0;
    IMAGE_SECTION_HEADER *section=IMAGE_FIRST_SECTION(headers);
    for (unsigned index=0;index<headers->FileHeader.NumberOfSections;index++,section++) {
        if (!(section->Characteristics&IMAGE_SCN_MEM_WRITE)) continue;
        uint32_t extent=section->Misc.VirtualSize>section->SizeOfRawData?section->Misc.VirtualSize:section->SizeOfRawData;
        memcpy(module+section->VirtualAddress,encounter_baseline+section->VirtualAddress,extent);
    }
    /* Runtime binding for exactly the known sound import; no text is changed. */
    if (sound_bound) *(uint32_t *)0x4b1c18=(uint32_t)(uintptr_t)capture_sound;
    if (gdi_bound) bind_gdi_runtime();
}
static void bounded_append(uint8_t *buffer, size_t *length, const void *bytes, size_t count) {
    if (count>262144-*length) fail("original-state evidence exceeds bounded response size");
    memcpy(buffer+*length,bytes,count); *length+=count;
}
#include "native_cstring_runtime.h"

static void append_image_delta(uint8_t *output, size_t *length) {
    uint32_t changes=0; size_t count_offset=*length;
    bounded_append(output,length,&changes,4);
    uint32_t offset=0;
    while (offset<0x111000) {
        uint32_t runtime_end=cstring_range_end(0x400000+offset);
        if (runtime_end) { offset=runtime_end-0x400000; continue; }
        if (offset+64<=0x111000 && !memcmp(image_snapshot+offset,module+offset,64)) { offset+=64; continue; }
        if (image_snapshot[offset]==module[offset]) { offset++; continue; }
        uint32_t first=offset;
        while (offset<0x111000 && !cstring_range_end(0x400000+offset) && image_snapshot[offset]!=module[offset]) offset++;
        uint32_t address=0x400000+first, count=offset-first;
        bounded_append(output,length,&address,4); bounded_append(output,length,&count,4);
        bounded_append(output,length,image_snapshot+first,count); bounded_append(output,length,module+first,count); changes++;
    }
    memcpy(output+count_offset,&changes,4);
}
/* Match the emulation reference's zero entry registers. Only fixed dispatch
 * below supplies the target. Host registers/stack are restored after return.
 * Original argument words and original instructions are executed unchanged.
 */
static void __attribute__((naked,noinline)) invoke_original_words(uintptr_t target __attribute__((unused)), const void *words __attribute__((unused)), uint32_t count __attribute__((unused)), void *output __attribute__((unused)), uint32_t floating __attribute__((unused))) {
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
static void apply_mutable_patches(void) {
    uint32_t patches; read_exact(&patches,4);
    if (patches>4096) fail("mutable-state patch count exceeds fixed bound");
    for (uint32_t index=0;index<patches;index++) {
        uint32_t offset,length; read_exact(&offset,4); read_exact(&length,4);
        if (offset>=0x1d000 || !length || length>0x1d000-offset || (offset<0xee44 && offset+length>0xee40)) fail("mutable-state patch exceeds data scope or changes runtime TLS index");
        read_exact((void *)(uintptr_t)(0x491000+offset),length);
    }
}
static void hash_mutable_state(uint8_t digest[32]) {
    HCRYPTHASH hash; DWORD length=32;
    const uint8_t *state=(const uint8_t *)0x491000;
    if (cstring_active) {
        memcpy(cstring_hash_copy,state,0x1d000);
        for (unsigned index=0;index<sizeof(cstring_runtime_ranges)/sizeof(cstring_runtime_ranges[0]);index++) {
            uint32_t address=cstring_runtime_ranges[index][0],width=cstring_runtime_ranges[index][1];
            if (address>=0x491000 && address+width<=0x4ae000)
                memcpy(cstring_hash_copy+address-0x491000,(normalization_snapshot?normalization_snapshot:image_snapshot)+address-0x400000,width);
        }
        if (hud_string_active)
            memcpy(cstring_hash_copy+0x4a7048-0x491000,(normalization_snapshot?normalization_snapshot:image_snapshot)+0x4a7048-0x400000,4);
        state=cstring_hash_copy;
    }
    if (!CryptCreateHash(state_hash_provider,CALG_SHA_256,0,0,&hash) ||
        !CryptHashData(hash,state,0xee40,0) ||
        !CryptHashData(hash,(const BYTE *)&original_tls_value,4,0) ||
        !CryptHashData(hash,state+0xee44,0x1d000-0xee44,0) ||
        !CryptGetHashParam(hash,HP_HASHVAL,digest,&length,0)) fail("mutable-state SHA256 failed");
    CryptDestroyHash(hash);
}

#include "native_gdi_trace.h"

static void load_and_hash(const char *path) {
    HANDLE file=CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    HCRYPTPROV provider=0; HCRYPTHASH hash=0;
    DWORD received, hash_size=32; uint8_t digest[32];
    if (file==INVALID_HANDLE_VALUE) fail("opening original 2002 executable failed");
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
    if (headers->OptionalHeader.ImageBase!=0x400000 || headers->OptionalHeader.SizeOfImage!=0x111000 || headers->OptionalHeader.SizeOfHeaders>file_size) fail("expected exact preserved image layout");
    module=original_storage;
    if ((uintptr_t)module!=0x400000) fail("dedicated host-owned original-image storage is not at 0x400000");
    memset(module,0,sizeof(original_storage));
    memcpy(module,file_image,headers->OptionalHeader.SizeOfHeaders);
    IMAGE_SECTION_HEADER *section=IMAGE_FIRST_SECTION(headers);
    for (unsigned index=0;index<headers->FileHeader.NumberOfSections;index++,section++) {
        uint32_t extent=section->Misc.VirtualSize>section->SizeOfRawData?section->Misc.VirtualSize:section->SizeOfRawData;
        if (section->PointerToRawData>file_size || section->SizeOfRawData>file_size-section->PointerToRawData || section->VirtualAddress>0x111000 || extent>0x111000-section->VirtualAddress) fail("invalid preserved section extent");
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

#include "native_frame_chain.h"

int main(int argc, char **argv) {
    uint32_t command, imports, tls_index, operations=0;
    uint8_t response[320];
    if (argc!=2) { fprintf(stderr,"Usage: native-reference-2002.exe ORIGINAL_2002_EXE\n"); return 2; }
    /* The host loader owns this explicit PE data section before Wine creates
     * other mappings. Never unmap or replace an unknown existing allocation.
     * Host headers/code are below it, at their separate 0x300000 image base.
     */
    if ((uintptr_t)original_storage!=0x400000 || (uintptr_t)GetModuleHandleA(NULL)!=0x300000)
        fail("expected dedicated fixed host/original section layout");
    MEMORY_BASIC_INFORMATION owned;
    if (!VirtualQuery(original_storage,&owned,sizeof(owned)) || owned.AllocationBase!=(void *)0x300000 || owned.Type!=MEM_IMAGE)
        fail("original storage is not owned by the reference host image");
    _setmode(_fileno(stdin),_O_BINARY); _setmode(_fileno(stdout),_O_BINARY); setvbuf(stdout,NULL,_IONBF,0);
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX|SEM_NOOPENFILEERRORBOX);
    load_and_hash(argv[1]); verify_text_unchanged(); imports=resolve_imports();
    original_tls_value=(uint32_t)read_i32(0x49fe40);
    tls_index=TlsAlloc();
    if (tls_index==TLS_OUT_OF_INDEXES || !TlsSetValue(tls_index,tls_record)) fail("isolated CRT thread record failed");
    memcpy((void *)0x49fe40,&tls_index,4);
    uint32_t seed=1; memcpy(tls_record+0x14,&seed,4);
    image_snapshot=(uint8_t *)malloc(0x111000);
    encounter_baseline=(uint8_t *)malloc(0x111000);
    mutable_pristine=(uint8_t *)malloc(0x1d000);
    if (!image_snapshot || !encounter_baseline || !mutable_pristine) fail("allocating original image snapshots failed");
    memcpy(mutable_pristine,(void *)0x491000,0x1d000);
    if (!CryptAcquireContextA(&state_hash_provider,NULL,NULL,PROV_RSA_AES,CRYPT_VERIFYCONTEXT)) fail("mutable-state hash provider failed");
    x87_reset(); ((int32_t (__cdecl *)(void))0x415a60)();
    memcpy(encounter_baseline,module,0x111000);
    verify_text_unchanged();
    write_exact("TACT2002",8);
    uint32_t hello[6]={2,(uint32_t)(uintptr_t)module,tls_index,imports,TACT_X87_CONTROL_WORD,1}; write_exact(hello,sizeof(hello));
    while (fread(&command,4,1,stdin)==1) {
        if (++operations>131072) fail("bounded command limit exceeded");
        if (command==0) {
            verify_text_unchanged(); uint32_t success=1; reply(0,&success,4);
            TlsSetValue(tls_index,NULL); TlsFree(tls_index); CryptReleaseContext(state_hash_provider,0); free(mutable_pristine); free(encounter_baseline); free(image_snapshot); free(file_image); return 0;
        } else if (command==18) {
            run_frame_chain_command();
        } else if (command==17) {
            /* Export only the two fixed original lookup arrays initialized by
             * unchanged 0x415a60 under this runner's declared control word. */
            uint8_t tables[362*8];
            memcpy(tables,(void *)0x4a54a0,362*4);
            memcpy(tables+362*4,(void *)0x4a3450,362*4);
            verify_text_unchanged();reply(17,tables,sizeof(tables));
        } else if (command==1) {
            int32_t table[302]; read_exact(table,sizeof(table)); memcpy((void *)0x4a9450,table,sizeof(table));
            uint32_t success=1; reply(1,&success,4);
        } else if (command==2) {
            uint32_t mask, double_mask, replace_seed, incoming_seed; int32_t values[24]; double doubles[3];
            read_exact(&mask,4); read_exact(values,sizeof(values)); read_exact(&double_mask,4); read_exact(doubles,sizeof(doubles)); read_exact(&replace_seed,4); read_exact(&incoming_seed,4);
            if (mask>>24 || double_mask>>3 || replace_seed>1) fail("invalid wind input mask");
            for (unsigned index=0;index<24;index++) if (mask&(1u<<index)) write_i32(wind_inputs[index],values[index]);
            for (unsigned index=0;index<3;index++) if (double_mask&(1u<<index)) memcpy((void *)(uintptr_t)wind_doubles[index],doubles+index,8);
            if (replace_seed) memcpy(tls_record+0x14,&incoming_seed,4);
            if (read_i32(0x4911c4)<0 || read_i32(0x4911c4)>301 || read_i32(0x4911c8)<0 || read_i32(0x4911c8)>301) fail("wind table index outside bounded fixture domain");
            x87_reset(); int32_t result=((int32_t (__cdecl *)(void))0x41b5d0)();
            for (unsigned index=0;index<14;index++) put_i32(response,index*4,read_i32(wind_outputs[index]));
            memcpy(response+56,(void *)0x4aa6f0,8); memcpy(response+64,tls_record+0x14,4); put_i32(response,68,result); reply(2,response,72);
        } else if (command==3) {
            int32_t values[10]; read_exact(values,sizeof(values));
            for (unsigned index=0;index<10;index++) write_i32(boat_inputs[index],values[index]);
            x87_reset(); int32_t result=((int32_t (__cdecl *)(void))0x417790)();
            for (unsigned index=0;index<14;index++) put_i32(response,index*4,read_i32(boat_outputs[index]));
            memcpy(response+56,(void *)0x4ab0c0,8); put_i32(response,64,result); reply(3,response,68);
        } else if (command==4) {
            int32_t values[4]; read_exact(values,sizeof(values));
            if (values[1]<1 || values[1]>30 || values[2]<0 || values[2]>361) fail("apparent-wind input outside bounded fixture domain");
            write_i32(0x4a7bc8+values[1]*4,values[2]); write_i32(0x4a6338+values[1]*4,values[3]);
            x87_reset(); volatile double pressure=((double (__cdecl *)(int32_t,int32_t))0x429df0)(values[0],values[1]);
            memcpy(response,(const void *)&pressure,8); put_i32(response,8,read_i32(0x4ab9e8+values[1]*4)); put_i32(response,12,read_i32(0x4a47f8+values[1]*4)); reply(4,response,16);
        } else if (command==5) {
            int32_t values[2]; read_exact(values,sizeof(values)); x87_reset();
            int32_t result=((int32_t (__cdecl *)(int32_t,int32_t))0x41bb10)(values[0],values[1]); reply(5,&result,4);
        } else if (command==6) {
            double value; read_exact(&value,8); x87_reset();
            volatile double result=((double (__cdecl *)(double))0x413cd0)(value); reply(6,(const void *)&result,8);
        } else if (command==7) {
            /* The fixture geometry is synthetic, not a recovered course. */
            int32_t shoreline_x[64], shoreline_y[64]; double radial[181];
            read_exact(shoreline_x,sizeof(shoreline_x)); read_exact(shoreline_y,sizeof(shoreline_y)); read_exact(radial,sizeof(radial));
            memcpy((void *)0x4a6490,shoreline_x,sizeof(shoreline_x));
            memcpy((void *)0x4a68c8,shoreline_y,sizeof(shoreline_y));
            memcpy((void *)0x4a8028,radial,sizeof(radial));
            uint32_t success=1; reply(7,&success,4);
        } else if (command==8) {
            uint32_t routine; int32_t arguments[4], values[30], strengths[2]; double axes[2], cached;
            read_exact(&routine,4); read_exact(arguments,sizeof(arguments)); read_exact(values,sizeof(values));
            read_exact(axes,sizeof(axes)); read_exact(&cached,8); read_exact(strengths,sizeof(strengths));
            int32_t x=arguments[0], y=arguments[1], boat=arguments[2], selector=arguments[3];
            if (routine>5 || boat<0 || boat>3 || (routine==5 && (selector<0 || selector>1))) fail("current routine outside bounded fixture domain");
            for (unsigned index=0;index<30;index++) write_i32(current_inputs[index],values[index]);
            memcpy((void *)0x4a6470,axes,8); memcpy((void *)0x4abe60,axes+1,8);
            memcpy((void *)(uintptr_t)(0x4a7f28+boat*8),&cached,8);
            write_i32(0x4ac208+boat*4,strengths[0]); write_i32(0x4a4778+boat*4,strengths[1]);
            x87_reset();
            if (routine>=1 && routine<=3) {
                static const uintptr_t metrics[3]={0x420b70,0x420c40,0x420d10};
                volatile long double extended=((long double (__cdecl *)(int32_t,int32_t,int32_t))metrics[routine-1])(x,y,boat);
                volatile double rounded=(double)extended;
                memcpy(response+40,(const void *)&rounded,8); memcpy(response+48,(const void *)&extended,10);
            } else {
                int32_t result;
                if (routine==0) result=((int32_t (__cdecl *)(int32_t,int32_t,int32_t))0x421560)(x,y,boat);
                else if (routine==4) result=((int32_t (__cdecl *)(int32_t,int32_t))0x421ae0)(x,y);
                else result=((int32_t (__cdecl *)(int32_t,int32_t,int32_t))0x421b80)(selector,x,y);
                put_i32(response,40,result);
            }
            memcpy(response,&routine,4);
            for (unsigned index=0;index<5;index++) put_i32(response,4+index*4,read_i32(current_outputs[index]));
            put_i32(response,24,read_i32(0x4ac208+boat*4)); put_i32(response,28,read_i32(0x4a4778+boat*4));
            memcpy(response+32,(void *)(uintptr_t)(0x4a7f28+boat*8),8);
            reply(8,response,(routine>=1 && routine<=3)?58:44);
        } else if (command==9) {
            int32_t boat; double values[4]; read_exact(&boat,4); read_exact(values,sizeof(values));
            if (boat<0 || boat>30) fail("distance boat outside bounded fixture domain");
            memcpy((void *)(uintptr_t)(0x4a49e8+boat*8),values+2,8);
            memcpy((void *)(uintptr_t)(0x4a4ae0+boat*8),values+3,8);
            memcpy(image_snapshot,module,0x111000); x87_reset();
            volatile long double extended=((long double (__cdecl *)(int32_t,double,double))0x428ab0)(boat,values[0],values[1]);
            volatile double rounded=(double)extended;
            memcpy(response,(const void *)&rounded,8); memcpy(response+8,(const void *)&extended,10);
            uint32_t unchanged=memcmp(image_snapshot,module,0x111000)==0; memcpy(response+18,&unchanged,4); reply(9,response,22);
        } else if (command==10) {
            int32_t boat, values[6], indexed[4]; uint32_t incoming_seed; double doubles[4];
            read_exact(&boat,4); read_exact(&incoming_seed,4); read_exact(values,sizeof(values));
            read_exact(indexed,sizeof(indexed)); read_exact(doubles,sizeof(doubles));
            if (boat<0 || boat>30) fail("prestart boat outside bounded fixture domain");
            for (unsigned index=0;index<6;index++) write_i32(movement_inputs[index],values[index]);
            for (unsigned index=0;index<4;index++) write_i32(movement_indexed_i32[index]+boat*4,indexed[index]);
            memcpy((void *)0x4ac1f8,doubles,8); memcpy((void *)0x4ab0c0,doubles+1,8);
            memcpy((void *)(uintptr_t)(0x4a49e8+boat*8),doubles+2,8);
            memcpy((void *)(uintptr_t)(0x4a4ae0+boat*8),doubles+3,8); memcpy(tls_record+0x14,&incoming_seed,4);
            memcpy(image_snapshot,module,0x111000); x87_reset();
            int32_t result=((int32_t (__cdecl *)(int32_t))0x42a3b0)(boat);
            put_i32(response,0,result); memcpy(response+4,tls_record+0x14,4);
            uint32_t unchanged=memcmp(image_snapshot,module,0x111000)==0; memcpy(response+8,&unchanged,4); reply(10,response,12);
        } else if (command==11) {
            /* Only this known import's data slot is rebound to the recorder.
             * Original calls, return convention and .text remain unchanged.
             */
            FARPROC expected=GetProcAddress(GetModuleHandleA("WINMM.dll"),"PlaySoundA");
            DWORD previous, ignored;
            if (sound_bound || !expected || *(uint32_t *)0x4b1c18!=(uint32_t)(uintptr_t)expected) fail("unexpected preserved PlaySoundA IAT binding");
            if (!VirtualProtect((void *)0x4b1c18,4,PAGE_READWRITE,&previous)) fail("making known sound import data writable failed");
            *(uint32_t *)0x4b1c18=(uint32_t)(uintptr_t)capture_sound;
            if (!VirtualProtect((void *)0x4b1c18,4,previous,&ignored)) fail("restoring sound import data protection failed");
            sound_bound=1; reply(11,&sound_bound,4);
        } else if (command==12) {
            uint32_t routine, double_mask; uint64_t mask; int32_t values[50]; double doubles[2];
            read_exact(&routine,4); read_exact(&mask,8); read_exact(values,sizeof(values));
            read_exact(&double_mask,4); read_exact(doubles,sizeof(doubles));
            if (!sound_bound || routine>2 || mask>>50 || double_mask>>2) fail("invalid bounded steering request");
            for (unsigned index=0;index<50;index++) if (mask&((uint64_t)1<<index)) write_i32(steering_inputs[index],values[index]);
            if (double_mask&1) memcpy((void *)0x4a78e8,doubles,8);
            if (double_mask&2) memcpy((void *)0x4ab0c8,doubles+1,8);
            static const uintptr_t routines[3]={0x42ba00,0x42b7f0,0x42bda0};
            sound_count=0; x87_reset(); int32_t result=((int32_t (__cdecl *)(void))routines[routine])();
            for (unsigned index=0;index<19;index++) put_i32(response,index*4,read_i32(steering_outputs[index]));
            memcpy(response+76,(void *)0x4a78e8,8); put_i32(response,84,result);
            memcpy(response+88,&sound_count,4); memcpy(response+92,sound_records,sound_count*12);
            reply(12,response,92+sound_count*12);
        } else if (command==13) {
            uint32_t routine, seed_value, globals[ENCOUNTER_GLOBAL_COUNT];
            int32_t boats[2], args[3]; uint8_t output[262144], floating[18]; int64_t returned=0;
            size_t length=0;
            read_exact(&routine,4); read_exact(boats,sizeof(boats)); read_exact(args,sizeof(args)); read_exact(&seed_value,4);
            if (!sound_bound || routine>=ENCOUNTER_ROUTINE_COUNT || boats[0]<0 || boats[0]>30 || boats[1]<0 || boats[1]>30 || boats[0]==boats[1]) fail("invalid fixed encounter routine request");
            if ((routine==5?args[1]:args[0])!=boats[0] || (routine==1 && args[2]!=boats[1]) || (routine==2 && args[1]!=boats[1])) fail("encounter arguments do not match bounded boat indices");
            restore_encounter_data(); read_exact(globals,sizeof(globals));
            for (unsigned index=0;index<ENCOUNTER_GLOBAL_COUNT;index++) memcpy((void *)(uintptr_t)encounter_globals[index],globals+index,4);
            for (unsigned boat=0;boat<2;boat++) for (unsigned index=0;index<ENCOUNTER_INDEXED_COUNT;index++) {
                uint8_t value[8]; read_exact(value,encounter_widths[index]);
                memcpy((void *)(uintptr_t)(encounter_indexed[index]+boats[boat]*encounter_widths[index]),value,encounter_widths[index]);
            }
            memcpy(tls_record+0x14,&seed_value,4); sound_count=0;
            memcpy(image_snapshot,module,0x111000); x87_reset();
            uintptr_t target=encounter_routines[routine]; uint32_t kind=encounter_return_kinds[routine];
            if (kind==2) {
                volatile long double extended=((long double (__cdecl *)(int32_t))target)(args[0]);
                volatile double rounded=(double)extended;
                memcpy(floating,(const void *)&rounded,8); memcpy(floating+8,(const void *)&extended,10);
            } else if (kind==1) {
                if (encounter_argument_counts[routine]==3) returned=((int64_t (__cdecl *)(int32_t,int32_t,int32_t))target)(args[0],args[1],args[2]);
                else returned=((int64_t (__cdecl *)(int32_t,int32_t))target)(args[0],args[1]);
            } else if (kind==3) {
                if (encounter_argument_counts[routine]==3) ((void (__cdecl *)(int32_t,int32_t,int32_t))target)(args[0],args[1],args[2]);
                else ((void (__cdecl *)(int32_t))target)(args[0]);
            } else {
                if (encounter_argument_counts[routine]==2) returned=((int32_t (__cdecl *)(int32_t,int32_t))target)(args[0],args[1]);
                else returned=((int32_t (__cdecl *)(int32_t))target)(args[0]);
            }
            bounded_append(output,&length,&routine,4);
            for (unsigned index=0;index<ENCOUNTER_GLOBAL_COUNT;index++) bounded_append(output,&length,(void *)(uintptr_t)encounter_globals[index],4);
            for (unsigned boat=0;boat<2;boat++) for (unsigned index=0;index<ENCOUNTER_INDEXED_COUNT;index++)
                bounded_append(output,&length,(void *)(uintptr_t)(encounter_indexed[index]+boats[boat]*encounter_widths[index]),encounter_widths[index]);
            bounded_append(output,&length,tls_record+0x14,4);
            if (kind==2) bounded_append(output,&length,floating,18);
            else if (kind!=3) bounded_append(output,&length,&returned,kind==1?8:4);
            bounded_append(output,&length,&sound_count,4); bounded_append(output,&length,sound_records,sound_count*12);
            /* Complete mapped-image final delta, including unexpected data writes.
             * Skip equal chunks, then emit exact contiguous differing byte runs.
             */
            append_image_delta(output,&length); reply(13,output,(uint32_t)length);
        } else if (command==14) {
            /* Fixed mutable data blocks + fixed reviewed routine dispatch.
             * The protocol never supplies code addresses or code bytes.
             */
            uint32_t routine, seed_value; int32_t args[8]; double doubles[4];
            uint8_t output[262144], captured[26], digest[32]; size_t length=0;
            static const uintptr_t targets[51]={0x42a530,0x42a2d0,0x429f40,0x426150,0x42c400,0x428c60,0x4249a0,0x425600,0x425910,0x427030,0x427fd0,0x42adb0,0x412f60,0x413100,0x41b170,0x41b510,0x42e0a0,0x41e9c0,0x4280c0,0x4286e0,0x428a30,0x41fd90,0x41f5b0,0x44e470,0x41f0b0,0x4201a0,0x41eb80,0x420dd0,0x413f00,0x4313a0,0x426ad0,0x420b20,0x4139d0,0x413a20,0x413370,0x44dfe0,0x44dbc0,0x414010,0x42c210,0x42c2e0,0x42bfc0,0x4060a0,0x42ad00,0x415ac0,0x415c40,0x42cf70,0x42d0c0,0x4304d0,0x42cca0,0x42cd00,0x42cf50};
            static const uint8_t word_counts[51]={3,1,1,3,6,1,1,3,3,2,1,0,4,4,0,0,0,1,4,3,1,0,0,0,0,1,0,0,0,0,1,4,1,13,4,0,0,8,5,8,7,2,2,0,0,1,1,0,1,3,0};
            uint32_t words[16]={0}, kind=3;
            read_exact(&routine,4); read_exact(args,sizeof(args)); read_exact(doubles,sizeof(doubles)); read_exact(&seed_value,4);
            if (!sound_bound || routine>=51) fail("unknown fixed mutable-state routine");
            restore_encounter_data();
            memcpy((void *)0x491000,mutable_pristine,0x1d000); apply_mutable_patches();
            if (read_i32(0x49118c)<0 || read_i32(0x49118c)>30) fail("mutable-state boat count outside bounded domain");
            int32_t boat=-1;
            if (routine==0) { boat=args[1]; if (args[0]<0 || args[0]>30) fail("collision peer outside bounded domain"); }
            else if (routine==3 || routine==7 || routine==8) boat=args[2];
            else if (routine==4 || routine==9) boat=args[1];
            else if (routine==1 || routine==2 || routine==5 || routine==6 || routine==10) boat=args[0];
            else if (routine==18 || routine==19) { boat=args[2]; if (args[1]<0 || args[1]>30) fail("avoidance peer outside bounded domain"); }
            else if (routine==30) boat=args[0];
            else if (routine==33) boat=args[1];
            else if (routine==34) boat=args[0];
            else if (routine==37) boat=args[0];
            else if (routine==38 || routine==45 || routine==46) boat=args[0];
            else if (routine>=39 && routine<=42) boat=args[1];
            uint32_t has_boat=(routine<=10 || routine==18 || routine==19 || routine==30 || routine==33 || routine==34 || routine==37 || (routine>=38 && routine<=42) || routine==45 || routine==46);
            if (has_boat && (boat<0 || boat>30) && !(routine==33 && (boat==-1 || boat==INT32_MIN || boat==INT32_MAX))) fail("mutable-state boat index outside bounded domain");
            if (routine==17 && (args[0]<0 || args[0]>400)) fail("wind patch outside bounded domain");
            if (routine==32 && (args[0]<-2 || args[0]>2)) fail("crew selector outside bounded domain");
            if (routine==33 && (args[0]<0 || args[0]>64)) fail("crew index outside bounded domain");
            memcpy(tls_record+0x14,&seed_value,4); sound_count=0;
            memcpy(image_snapshot,module,0x111000); x87_reset();
            if (routine==4) { memcpy(words,doubles,16); memcpy(words+4,args,8); kind=2; }
            else if (routine==12 || routine==13) memcpy(words,doubles,16);
            else if (routine==33) { memcpy(words,doubles,32); memcpy(words+8,args,20); }
            else if (routine==34) { memcpy(words,doubles,8); memcpy(words+2,args,8); }
            else if (routine==37) { memcpy(words,doubles,8); memcpy(words+2,args,16); memcpy(words+6,doubles+1,8); }
            else if (routine==38) { memcpy(words,doubles,16);memcpy(words+4,args,4); }
            else if (routine==39) { memcpy(words,doubles,8);memcpy(words+2,args,4);memcpy(words+3,doubles+1,16);memcpy(words+7,args+1,4); }
            else if (routine==40) { memcpy(words,args,4);memcpy(words+1,doubles,16);memcpy(words+5,args+1,8); }
            else memcpy(words,args,sizeof(args));
            if (routine==32 || routine==38 || routine==41) kind=2;
            if (routine==3 || routine==7 || routine==8 || routine==25 || routine==42) kind=0;
            invoke_original_words(targets[routine],words,word_counts[routine],captured,kind==2);
            if (*(uint32_t *)0x49fe40!=tls_index) fail("original call changed runtime TLS index");
            bounded_append(output,&length,&routine,4); bounded_append(output,&length,&kind,4);
            bounded_append(output,&length,captured,4); /* residual EAX always recorded */
            if (kind==2) bounded_append(output,&length,captured+8,18);
            bounded_append(output,&length,tls_record+0x14,4); bounded_append(output,&length,&sound_count,4);
            bounded_append(output,&length,sound_records,sound_count*12);
            hash_mutable_state(digest); bounded_append(output,&length,digest,32);
            append_image_delta(output,&length); reply(14,output,(uint32_t)length);
        } else if (command==15 || command==19) {
            uint32_t routine,seed_value,kind=3;int32_t args[16];double doubles[4];uint32_t words[25]={0};
            uint8_t output[262144],captured[26],digest[32];size_t length=0;
            static const uintptr_t targets[130]={0x416420,0x417be0,0x41a450,0x41af70,0x419d50,0x415590,0x4166e0,0x423670,0x423640,0x424890,0x423aa0,0x423830,0x415de0,0x416070,0x416300,0x417d30,0x417fb0,0x418890,0x418a10,0x417eb0,0x418580,0x419ca0,0x419b40,0x4194b0,0x419640,0x4198f0,0x417570,0x412810,0x419db0,0x4156f0,0x414d00,0x416ad0,0x41a5d0,0x418b80,0x418120,0x416d10,0x431890,0x431440,0x421d90,0x411000,0x422970,0x4232e0,0x422cf0,0x44f630,0x4226c0,0x44f320,0x430f30,0x430eb0,0x430570,0x407e40,0x4094c0,0x409050,0x408c70,0x42cd40,0x42c550,0x42c7b0,0x40a360,0x40b130,0x409760,0x40b990,0x40db30,0x40c3b0,0x40e9a0,0x4060f0,0x42fe00,0x42f930,0x42fe40,0x431b30,0x42d120,0x42d8a0,0x42e190,0x42e550,0x42e750,0x42e870,0x42e970,0x42eb40,0x42ede0,0x42f0d0,0x410090,0x4063e0,0x406c90,0x4064d0,0x41d890,0x41c940,0x40f4a0,0x416990,0x44d6d0,0x44d830,0x432000,0x432920,0x4330f0,0x4337a0,0x433ea0,0x434470,0x434c10,0x4354d0,0x435b50,0x436300,0x436960,0x4372d0,0x437950,0x438330,0x438c30,0x439600,0x439f20,0x43a5d0,0x43a9b0,0x43b910,0x43c100,0x43ccd0,0x43e070,0x43f460,0x440d20,0x442740,0x443bf0,0x445830,0x445ee0,0x446570,0x446a90,0x4479e0,0x449ef0,0x44b220,0x44b9e0,0x44c120,0x44c950,0x44d140,0x41beb0,0x41bb40,0x404880,0x404020};
            static const char *signatures[130]={"I","","I","I","III","IIIIIIIIII","I","IIIII","III","IIIII","IIII","IIII","DII","DII","DIII","DII","DII","DII","DII","DIIII","DD","IDII","IDIII","DII","DI","DIIII","IIIIII","DII","IDIII","IIIID","DIDIII","DIII","DIII","IIDIII","DII","IDIIIDIII","IIDIIIIIII","IIIIII","IIDIIIIIIII","IIIIII","","","","","IIDIIII","IIDIIII","IIII","IIII","III","IIIIII","III","III","III","IIII","IIII","IIIIII","IIIIII","IIIIII","IIIIII","IIIIII","IIIIII","IIIII","IIIII","I","IIII","IIIII","IIIII","IIIIII","IIIIIIIII","IIIIIIIIIIII","III","II","II","II","III","III","III","IIIII","","IIIIII","III","III","","","","I","I","II","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","IIIII",""};
            read_exact(&routine,4);read_exact(args,sizeof(args));read_exact(doubles,sizeof(doubles));read_exact(&seed_value,4);
            if (!sound_bound || routine>=130) fail("unknown fixed GDI drawing routine");
            if(command==19 && routine!=128)fail("only the fixed full scene has standalone retained-stack observation");
            restore_encounter_data();memcpy((void *)0x491000,mutable_pristine,0x1d000);
            apply_mutable_patches();
            read_exact(&gdi_pixel_count,4);
            if (gdi_pixel_count>1024) fail("synthetic GetPixel input count exceeds fixed bound");
            read_exact(gdi_pixel_values,gdi_pixel_count*4);
            read_exact(&gdi_menu_height,4);read_exact(&gdi_cursor,sizeof(gdi_cursor));
            read_exact(&gdi_tick_start,4);read_exact(&gdi_tick_step,4);
            if (gdi_menu_height<0 || gdi_menu_height>128 || gdi_cursor.x<-16384 || gdi_cursor.x>16384 ||
                gdi_cursor.y<-16384 || gdi_cursor.y>16384 || gdi_tick_step!=1)
                fail("owned cursor/menu/timer inputs exceed fixed bounds");
            bind_gdi_runtime();reset_gdi_trace();
            gdi_white_sampler=0;
            if(command==19){chain_shore_count=0;enable_chain_hardware_observation(0);}
            memcpy(tls_record+0x14,&seed_value,4);sound_count=0;
            memcpy(image_snapshot,module,0x111000);x87_reset();
            if (routine==38 || routine==48 || (routine>=49 && routine<=52) || (routine>=56 && routine<=62) || routine>=68) { prepare_cstring_runtime();x87_reset(); }
            if ((routine>=56 && routine<=62) || routine==129) {
                hud_string_active=1;
                ((void (__attribute__((thiscall)) *)(void *))0x46bd7a)((void *)0x4a7048);
            }
            uint32_t word_count=1,integer=0,floating=0;
            words[0]=(uint32_t)(uintptr_t)gdi_cdc;
            for (const char *kind_pointer=signatures[routine];*kind_pointer;kind_pointer++) {
                if (*kind_pointer=='D') { memcpy(words+word_count,doubles+floating++,8);word_count+=2; }
                else words[word_count++]=(uint32_t)args[integer++];
            }
            invoke_original_words(targets[routine],words,word_count,captured,0);
            if (*(uint32_t *)0x49fe40!=tls_index) fail("drawing call changed runtime TLS index");
            if (cstring_active) save_cstring_runtime();
            if (gdi_pixel_cursor!=gdi_pixel_count) fail("explicit pixel input count does not match original GetPixel calls");
            bounded_append(output,&length,&routine,4);bounded_append(output,&length,&kind,4);
            bounded_append(output,&length,captured,4);bounded_append(output,&length,tls_record+0x14,4);
            bounded_append(output,&length,&sound_count,4);bounded_append(output,&length,sound_records,sound_count*12);
            hash_mutable_state(digest);bounded_append(output,&length,digest,32);append_image_delta(output,&length);
            bounded_append(output,&length,&gdi_event_bytes,4);bounded_append(output,&length,gdi_events,gdi_event_bytes);
            append_cstring_runtime_delta(output,&length);
            bounded_append(output,&length,&hud_string_active,4);
            uint32_t string_pointer=0,string_length=0;
            if (hud_string_active) {
                string_pointer=*(uint32_t *)0x4a7048;
                if (!string_pointer) fail("original HUD CString has no native data pointer");
                while (string_length<4096 && *(const char *)(uintptr_t)(string_pointer+string_length)) string_length++;
                if (string_length==4096) fail("original HUD text exceeds its fixed capture bound");
            }
            bounded_append(output,&length,&string_pointer,4);
            bounded_append(output,&length,&string_length,4);
            if (string_length) bounded_append(output,&length,(const void *)(uintptr_t)string_pointer,string_length);
            uint32_t elapsed_ticks=gdi_tick_calls?gdi_tick_calls-1:0;
            bounded_append(output,&length,&elapsed_ticks,4);
            if(command==19){bounded_append(output,&length,&chain_shore_count,4);bounded_append(output,&length,chain_shore_rows,chain_shore_count*28);}
            reply(command,output,(uint32_t)length);
            if (hud_string_active) {
                ((void (__attribute__((thiscall)) *)(void *))0x46bec5)((void *)0x4a7048);
                save_cstring_runtime();
            }
        } else if (command==16) {
            /* Only the three reviewed original signed-angle/text helpers.
             * Neither an output pointer nor executable address comes from stdin.
             */
            uint32_t routine;int32_t integer,object=0;double scalar;
            uint32_t words[3]={0},correct_pointer=0,unchanged=1,string_pointer=0,string_length=0;
            uint8_t output[262144],captured[26];size_t length=0;
            static const uintptr_t targets[3]={0x415dc0,0x413d00,0x413d90};
            read_exact(&routine,4);read_exact(&integer,4);read_exact(&scalar,8);
            if (routine>=3) fail("unknown fixed signed-angle/string routine");
            restore_encounter_data();memcpy(image_snapshot,module,0x111000);
            if (routine) {
                prepare_cstring_runtime();
                ((void (__attribute__((thiscall)) *)(void *))0x46bd7a)(&object);
                words[0]=(uint32_t)(uintptr_t)&object;
                if (routine==1) words[1]=(uint32_t)integer;
                else memcpy(words+1,&scalar,8);
            } else words[0]=(uint32_t)integer;
            x87_reset();invoke_original_words(targets[routine],words,routine==0?1:(routine==1?2:3),captured,0);
            if (routine) {
                correct_pointer=(*(uint32_t *)captured==(uint32_t)(uintptr_t)&object);
                string_pointer=(uint32_t)object;
                if (!string_pointer) fail("original numeric formatter has no native CString data");
                while (string_length<4096 && *(const char *)(uintptr_t)(string_pointer+string_length)) string_length++;
                if (string_length==4096) fail("original numeric text exceeds its fixed capture bound");
                save_cstring_runtime();
            }
            for (uint32_t offset=0;offset<0x111000;offset++) {
                uint32_t runtime_end=cstring_range_end(0x400000+offset);
                if (runtime_end) { offset=runtime_end-0x400000-1;continue; }
                if (module[offset]!=image_snapshot[offset]) { unchanged=0;break; }
            }
            bounded_append(output,&length,&routine,4);bounded_append(output,&length,captured,4);
            bounded_append(output,&length,&correct_pointer,4);bounded_append(output,&length,&unchanged,4);
            bounded_append(output,&length,&string_pointer,4);bounded_append(output,&length,&string_length,4);
            if (string_length) bounded_append(output,&length,(const void *)(uintptr_t)string_pointer,string_length);
            append_cstring_runtime_delta(output,&length);reply(16,output,(uint32_t)length);
            if (routine) {
                ((void (__attribute__((thiscall)) *)(void *))0x46bec5)(&object);
                save_cstring_runtime();
            }
        } else fail("unknown bounded protocol command");
    }
    fail("protocol stream ended without final verification command");
    return 2;
}

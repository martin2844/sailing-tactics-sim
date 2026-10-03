/* Observe this exact original EXE's real loader/startup, using only hardware
 * execution breakpoints. Never write target instructions or target CW.
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wincrypt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const uint8_t expected_sha[32]={
0x88,0x1d,0xc8,0x5d,0xc7,0x50,0x0a,0x5a,0xd0,0x9e,0x09,0x09,0x1d,0x4d,0xd5,0x3f,
0x8c,0x09,0x1f,0x56,0x30,0xd5,0xfa,0xbd,0xcc,0x88,0x7c,0xc4,0xb0,0x07,0xac,0xea};
static const uintptr_t addresses[4]={0x42d120,0x42d651,0x42d668,0x42d67d};
static HANDLE process_handle,thread_handles[128];
static DWORD thread_ids[128],thread_count;
static uint32_t current_first,consumed_mask;
static HWND owned_window;static DWORD owned_process;
static BOOL CALLBACK find_owned_window(HWND hwnd,LPARAM ignored) {(void)ignored;DWORD id;GetWindowThreadProcessId(hwnd,&id);if(id==owned_process && IsWindowVisible(hwnd)){char title[256],kind[128];GetWindowTextA(hwnd,title,sizeof(title));GetClassNameA(hwnd,kind,sizeof(kind));printf("{\"event\":\"owned-window\",\"hwnd\":%lu,\"title\":\"%s\",\"class\":\"%s\"}\n",(unsigned long)(uintptr_t)hwnd,title,kind);if(strstr(title,"SAILING TACTICS")){owned_window=hwnd;return FALSE;}}return TRUE;}
static int32_t target_i32(uintptr_t address);
static BOOL CALLBACK post_owned_reset(HWND hwnd,LPARAM ignored){(void)ignored;DWORD id;char kind[128];GetWindowThreadProcessId(hwnd,&id);GetClassNameA(hwnd,kind,sizeof(kind));if(id==owned_process && strstr(kind,"Afx:")){PostMessageA(hwnd,WM_KEYDOWN,0x4e,0);PostMessageA(hwnd,WM_KEYUP,0x4e,0);}return TRUE;}
static uint8_t *original;
static DWORD original_size;

static void fail(const char *message) {
    fprintf(stderr,"startup-precision: %s; Win32 error %lu\n",message,(unsigned long)GetLastError());
    exit(2);
}
static void hash_bytes(const uint8_t *bytes,DWORD size,uint8_t digest[32]) {
    HCRYPTPROV provider;HCRYPTHASH hash;DWORD width=32;
    if (!CryptAcquireContextA(&provider,NULL,NULL,PROV_RSA_AES,CRYPT_VERIFYCONTEXT) ||
        !CryptCreateHash(provider,CALG_SHA_256,0,0,&hash) || !CryptHashData(hash,bytes,size,0) ||
        !CryptGetHashParam(hash,HP_HASHVAL,digest,&width,0)) fail("SHA256 failed");
    CryptDestroyHash(hash);CryptReleaseContext(provider,0);
}
static void validate_original(const char *path) {
    HANDLE file=CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
    if (file==INVALID_HANDLE_VALUE) fail("opening fixed original failed");
    original_size=GetFileSize(file,NULL);
    if (original_size<0x80000 || original_size>0x200000) fail("unexpected original size");
    original=(uint8_t *)malloc(original_size);DWORD received;
    if (!original || !ReadFile(file,original,original_size,&received,NULL) || received!=original_size)
        fail("reading original failed");
    CloseHandle(file);uint8_t digest[32];hash_bytes(original,original_size,digest);
    if (memcmp(digest,expected_sha,32)) fail("original SHA256 does not match fixed 2002 image");
}
static HANDLE thread_for(DWORD id) {
    for (DWORD index=0;index<thread_count;index++) if (thread_ids[index]==id) return thread_handles[index];
    fail("unknown original thread");return NULL;
}
static void add_thread(DWORD id,HANDLE handle) {
    if (thread_count>=128) fail("original thread count exceeds fixed bound");
    thread_ids[thread_count]=id;thread_handles[thread_count++]=handle;
    CONTEXT context;memset(&context,0,sizeof(context));context.ContextFlags=CONTEXT_DEBUG_REGISTERS;
    if (!GetThreadContext(handle,&context)) fail("reading new thread debug registers failed");
    context.Dr0=(DWORD)addresses[0];context.Dr1=(DWORD)addresses[1];
    context.Dr2=(DWORD)addresses[2];context.Dr3=(DWORD)addresses[3];context.Dr6=0;context.Dr7=0x55;
    if (!SetThreadContext(handle,&context)) fail("setting hardware execution breakpoints failed");
}
static void verify_target_text(void) {
    IMAGE_DOS_HEADER *dos=(IMAGE_DOS_HEADER *)original;
    IMAGE_NT_HEADERS32 *header=(IMAGE_NT_HEADERS32 *)(original+dos->e_lfanew);
    IMAGE_SECTION_HEADER *section=IMAGE_FIRST_SECTION(header);
    unsigned verified=0;
    for (unsigned index=0;index<header->FileHeader.NumberOfSections;index++,section++) {
        if (memcmp(section->Name,".text",5)) continue;
        uint8_t *loaded=(uint8_t *)malloc(section->SizeOfRawData);SIZE_T received;
        if (!loaded || !ReadProcessMemory(process_handle,(void *)(uintptr_t)(0x400000+section->VirtualAddress),
                                         loaded,section->SizeOfRawData,&received) || received!=section->SizeOfRawData)
            fail("reading real application's original text failed");
        if (memcmp(loaded,original+section->PointerToRawData,section->SizeOfRawData))
            fail("real application instructions changed");
        free(loaded);verified++;
    }
    if (verified!=1) fail("expected one original text section");
}
static int32_t target_i32(uintptr_t address) {int32_t value;SIZE_T count;if(!ReadProcessMemory(process_handle,(void *)address,&value,4,&count)||count!=4)fail("reading fixed original stack/state failed");return value;}
int main(int argc,char **argv) {
    if (argc!=3 && argc!=4) fail("expected preserved original path, directory, and optional owned Wine process ID");
    validate_original(argv[1]);setvbuf(stdout,NULL,_IONBF,0);
    STARTUPINFOA startup;PROCESS_INFORMATION child;memset(&startup,0,sizeof(startup));startup.cb=sizeof(startup);
    char command[1024];if (strlen(argv[1])>1000) fail("unexpected original path length");
    snprintf(command,sizeof(command),"\"%s\"",argv[1]);
    if (argc==4) {
        char *end;unsigned long supplied=strtoul(argv[3],&end,10);
        if (!supplied || *end || supplied>0xffffffffUL) fail("invalid owned process ID");
        child.dwProcessId=(DWORD)supplied;
        process_handle=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ,FALSE,child.dwProcessId);
        if (!process_handle) fail("opening previously launched owned process failed");
        char path[1024];DWORD width=sizeof(path);
        if (!QueryFullProcessImageNameA(process_handle,0,path,&width) || _stricmp(path,argv[1]))
            fail("owned process does not identify the preserved original path");
        verify_target_text();
        if (!DebugActiveProcess(child.dwProcessId)) fail("attaching to previously launched owned process failed");
    } else {
        if (!CreateProcessA(argv[1],command,NULL,NULL,FALSE,DEBUG_ONLY_THIS_PROCESS,NULL,argv[2],&startup,&child))
            fail("starting intact original through normal Windows loader failed");
        process_handle=child.hProcess;CloseHandle(child.hThread);
    }
    if (!DebugSetProcessKillOnExit(FALSE)) fail("setting owned debug lifetime failed");
    printf("{\"event\":\"started\",\"processId\":%lu}\n",(unsigned long)child.dwProcessId);
    DWORD started=GetTickCount();BOOL exited=FALSE;
    BOOL menu_posted=FALSE;owned_process=child.dwProcessId;
    while (GetTickCount()-started<60000 && (consumed_mask&3)!=3) {
        DEBUG_EVENT event;if (!WaitForDebugEvent(&event,1000)) {
            if (GetLastError()==ERROR_SEM_TIMEOUT) continue;
            fail("waiting for original debug event failed");
        }
        DWORD status=DBG_CONTINUE;
        if (event.dwDebugEventCode==CREATE_PROCESS_DEBUG_EVENT) {
            if ((uintptr_t)event.u.CreateProcessInfo.lpBaseOfImage!=0x400000)
                fail("real original image did not load at its preferred base");
            if (event.u.CreateProcessInfo.hFile) CloseHandle(event.u.CreateProcessInfo.hFile);
            add_thread(event.dwThreadId,event.u.CreateProcessInfo.hThread);
            verify_target_text();
        } else if (event.dwDebugEventCode==CREATE_THREAD_DEBUG_EVENT) {
            add_thread(event.dwThreadId,event.u.CreateThread.hThread);
        } else if (event.dwDebugEventCode==LOAD_DLL_DEBUG_EVENT) {
            if (event.u.LoadDll.hFile) CloseHandle(event.u.LoadDll.hFile);
        } else if (event.dwDebugEventCode==EXCEPTION_DEBUG_EVENT) {
            DWORD code=event.u.Exception.ExceptionRecord.ExceptionCode;
            if (code==EXCEPTION_SINGLE_STEP) {
                HANDLE thread=thread_for(event.dwThreadId);CONTEXT context;memset(&context,0,sizeof(context));
                context.ContextFlags=CONTEXT_CONTROL|CONTEXT_INTEGER|CONTEXT_FLOATING_POINT|CONTEXT_DEBUG_REGISTERS;
                if (!GetThreadContext(thread,&context)) fail("reading real original x87 context failed");
                if(context.Eip==0x42d120){
                    verify_target_text();current_first=(uint32_t)target_i32(context.Esp+12);
                    if(current_first>360)fail("shore first outside original array");
                    printf("{\"event\":\"shore-entry\",\"entryEsp\":%lu,\"first\":%lu,\"last\":%ld,\"camera\":%ld,\"centerProjectedY\":%ld,\"previousX\":%ld,\"previousTreeY\":%ld,\"course\":%ld,\"island\":%ld,\"class\":%ld,\"variant\":%ld,\"basicShore\":%ld,\"controlWord\":\"%04lx\",\"textUnchanged\":true}\n",(unsigned long)context.Esp,(unsigned long)current_first,(long)target_i32(context.Esp+16),(long)target_i32(context.Esp+20),(long)target_i32(context.Esp-0xb6c),(long)target_i32(context.Esp-0xb54+current_first*4),(long)target_i32(context.Esp-0x2d8+current_first*4),(long)target_i32(0x491194),(long)target_i32(0x4a5a4c),(long)target_i32(0x491188),(long)target_i32(0x4a864c),(long)target_i32(0x4ac928),(unsigned long)(context.FloatSave.ControlWord&0xffff));
                    context.Dr2=context.Dr3=0;context.Dr7=5;
                }else if(context.Eip==0x42d651){
                    uint32_t index=(uint32_t)target_i32(context.Esp+0x10);
                    if(index==current_first){
                        int32_t first=target_i32(target_i32(context.Esp+0x18));int32_t next=target_i32(0x4a9458+index*4);
                        if(first<=25){context.Dr2=0x42d668;context.Dr3=0x42d67d;}
                        else if(next<=50){context.Dr2=0x42d6c5;context.Dr3=0x42d6dd;}
                        else if(first>50&&next<75){context.Dr2=0x42d711;context.Dr3=0x42d72a;}
                        else if(first>=75){context.Dr2=0x42d74b;context.Dr3=0x42d773;}
                        if(context.Dr2)context.Dr7=0x55;
                        printf("{\"event\":\"first-tree-branch\",\"index\":%lu,\"random1\":%ld,\"random2\":%ld,\"readX\":%lu,\"readY\":%lu}\n",(unsigned long)index,(long)first,(long)next,(unsigned long)context.Dr2,(unsigned long)context.Dr3);
                    }
                }else if(context.Eip==context.Dr2){
                    uint32_t address=context.Eip==0x42d668?context.Ecx-4:context.Esp+context.Ecx*4+0x30;
                    printf("{\"event\":\"consumed-retained-input\",\"field\":\"previousX\",\"instruction\":%lu,\"address\":%lu,\"value\":%ld,\"index\":%lu}\n",(unsigned long)context.Eip,(unsigned long)address,(long)target_i32(address),(unsigned long)current_first);consumed_mask|=1;context.Dr7&=~0x10u;
                }else if(context.Eip==context.Dr3){
                    printf("{\"event\":\"consumed-retained-input\",\"field\":\"previousTreeY\",\"instruction\":%lu,\"address\":%lu,\"value\":%ld,\"index\":%lu}\n",(unsigned long)context.Eip,(unsigned long)(context.Edi-4),(long)target_i32(context.Edi-4),(unsigned long)current_first);consumed_mask|=2;context.Dr7&=~0x40u;
                }
                context.Dr6=0;context.EFlags|=0x10000;
                context.ContextFlags=CONTEXT_CONTROL|CONTEXT_DEBUG_REGISTERS;
                if (!SetThreadContext(thread,&context)) fail("resuming observed hardware point failed");
            } else if (code!=EXCEPTION_BREAKPOINT) {
                status=DBG_EXCEPTION_NOT_HANDLED;
                if (!event.u.Exception.dwFirstChance)
                    printf("{\"event\":\"unhandled-exception\",\"code\":\"%08lx\",\"address\":\"%08lx\"}\n",
                           (unsigned long)code,(unsigned long)(uintptr_t)event.u.Exception.ExceptionRecord.ExceptionAddress);
            }
        } else if (event.dwDebugEventCode==EXIT_PROCESS_DEBUG_EVENT) {
            exited=TRUE;printf("{\"event\":\"exited\",\"code\":%lu}\n",(unsigned long)event.u.ExitProcess.dwExitCode);
        }
        if (!ContinueDebugEvent(event.dwProcessId,event.dwThreadId,status)) fail("continuing original event failed");
        if(exited)break;
        if(!menu_posted && event.dwDebugEventCode==CREATE_PROCESS_DEBUG_EVENT){EnumWindows(find_owned_window,0);if(!owned_window)fail("owned original window not found");EnumChildWindows(owned_window,post_owned_reset,0);if(!PostMessageA(owned_window,WM_COMMAND,32801,0)||!PostMessageA(owned_window,WM_COMMAND,32771,0))fail("normal menu message failed");menu_posted=TRUE;printf("{\"event\":\"normal-menu-event\",\"commandId\":32801}\n");}
    }
    if (!exited) {
        /* Clear only this probe's hardware registers, then detach and leave the
         * normal original application running. No wineserver/global stop. */
        for (DWORD index=0;index<thread_count;index++) {
            HANDLE thread=thread_handles[index];if (SuspendThread(thread)==(DWORD)-1) continue;
            CONTEXT context;memset(&context,0,sizeof(context));context.ContextFlags=CONTEXT_DEBUG_REGISTERS;
            if (GetThreadContext(thread,&context)) {
                context.Dr0=context.Dr1=context.Dr2=context.Dr3=context.Dr6=context.Dr7=0;
                SetThreadContext(thread,&context);
            }
            ResumeThread(thread);
        }
        if (!DebugActiveProcessStop(child.dwProcessId)) fail("detaching owned original process failed");
    }
    if(!exited)printf("{\"event\":\"final-state\",\"course\":%ld,\"island\":%ld,\"appState\":%ld,\"demoState\":%ld}\n",(long)target_i32(0x491194),(long)target_i32(0x4a5a4c),(long)target_i32(0x4ac8f8),(long)target_i32(0x4ac980));
    printf("{\"event\":\"complete\",\"observedMask\":%lu,\"exited\":%s}\n",(unsigned long)consumed_mask,exited?"true":"false");
    CloseHandle(process_handle);free(original);return 0;
}

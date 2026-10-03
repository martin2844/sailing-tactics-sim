/* Actual first island predecessor reads in the fixed, intact 2010 English app.
 * Normal Windows loader and original menu/keyboard routing in a private CWD.
 * Only ReadProcessMemory and per-thread hardware execution points observe
 * original allocated local arrays. No instructions, game state or CW written.
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wincrypt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const uint8_t source_sha[32]={
0xd7,0x07,0xa1,0xe1,0xb5,0x89,0x4a,0xdf,0x88,0x04,0x70,0xdd,0x3a,0xf3,0x10,0x4b,
0xc2,0xe2,0x56,0xaa,0xfa,0xa8,0x93,0x20,0x90,0xb8,0xa1,0x1d,0x13,0x7a,0xc7,0x87};
static HANDLE process_handle,threads[128];
static DWORD process_id,thread_ids[128],thread_count;
static uint8_t *original;static DWORD original_size;
static HWND main_window,view_window,dialog_window;
static uint32_t points[4]={0x440400,0x44092e,0,0};
static unsigned phase,samples,mask;static uint32_t entry_esp,first_index,return_address;
static BOOL attached,exited;

static void clear_points(void) {
 /* Stop through the debugger API before reading contexts. Suspending a Wine
  * thread inside an active GDI service can otherwise wait indefinitely. */
 if(!DebugBreakProcess(process_handle))return;
 DWORD started=GetTickCount();
 while(GetTickCount()-started<10000) {
  DEBUG_EVENT event;if(!WaitForDebugEvent(&event,100))continue;
  if(event.dwDebugEventCode==EXCEPTION_DEBUG_EVENT) {
   for(DWORD index=0;index<thread_count;index++) {
    CONTEXT context;memset(&context,0,sizeof(context));context.ContextFlags=CONTEXT_CONTROL|CONTEXT_DEBUG_REGISTERS;
    if(GetThreadContext(threads[index],&context)) {
     context.Dr0=context.Dr1=context.Dr2=context.Dr3=context.Dr6=context.Dr7=0;context.EFlags|=0x10000;
     SetThreadContext(threads[index],&context);
    }
   }
   ContinueDebugEvent(event.dwProcessId,event.dwThreadId,DBG_CONTINUE);return;
  }
  if(event.dwDebugEventCode==CREATE_THREAD_DEBUG_EVENT)CloseHandle(event.u.CreateThread.hThread);
  if(event.dwDebugEventCode==LOAD_DLL_DEBUG_EVENT&&event.u.LoadDll.hFile)CloseHandle(event.u.LoadDll.hFile);
  ContinueDebugEvent(event.dwProcessId,event.dwThreadId,DBG_CONTINUE);
 }
}
static void fail(const char *message) {
 fprintf(stderr,"live-shore-observer: %s; Win32 error %lu\n",message,(unsigned long)GetLastError());
 if(attached && !exited) {clear_points();DebugActiveProcessStop(process_id);}
 exit(2);
}
static void read_at(uint32_t address,void *out,size_t size) {
 SIZE_T read;if(!ReadProcessMemory(process_handle,(void *)(uintptr_t)address,out,size,&read)||read!=size)
  fail("fixed original memory observation failed");
}
static uint32_t read_u32(uint32_t address) {uint32_t value;read_at(address,&value,4);return value;}
static void hash_bytes(const uint8_t *bytes,DWORD size,uint8_t digest[32]) {
 HCRYPTPROV p;HCRYPTHASH h;DWORD n=32;
 if(!CryptAcquireContextA(&p,NULL,NULL,PROV_RSA_AES,CRYPT_VERIFYCONTEXT)||
 !CryptCreateHash(p,CALG_SHA_256,0,0,&h)||!CryptHashData(h,bytes,size,0)||
 !CryptGetHashParam(h,HP_HASHVAL,digest,&n,0))fail("SHA256 failed");
 CryptDestroyHash(h);CryptReleaseContext(p,0);
}
static void verify_text(void) {
 IMAGE_DOS_HEADER *dos=(IMAGE_DOS_HEADER *)original;
 IMAGE_NT_HEADERS32 *nt=(IMAGE_NT_HEADERS32 *)(original+dos->e_lfanew);
 IMAGE_SECTION_HEADER *s=IMAGE_FIRST_SECTION(nt);unsigned found=0;
 for(unsigned i=0;i<nt->FileHeader.NumberOfSections;i++,s++) if(!memcmp(s->Name,".text",5)) {
  uint8_t *bytes=(uint8_t *)malloc(s->SizeOfRawData);if(!bytes)fail("allocation failed");
  read_at(0x400000+s->VirtualAddress,bytes,s->SizeOfRawData);
  if(memcmp(bytes,original+s->PointerToRawData,s->SizeOfRawData))fail("original .text changed");
  free(bytes);found++;
 }
 if(found!=1)fail("expected one fixed original .text section");
}
static void validate_source(const char *path) {
 HANDLE f=CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
 if(f==INVALID_HANDLE_VALUE)fail("opening exact source failed");
 original_size=GetFileSize(f,NULL);if(original_size<0x100000||original_size>0x200000)fail("fixed source size differs");
 original=(uint8_t *)malloc(original_size);DWORD n;
 if(!original||!ReadFile(f,original,original_size,&n,NULL)||n!=original_size)fail("reading exact source failed");
 CloseHandle(f);uint8_t sha[32];hash_bytes(original,original_size,sha);
 if(memcmp(sha,source_sha,32))fail("source is not the exact preserved English2010 target");
}
static HANDLE thread_for(DWORD id) {
 for(DWORD i=0;i<thread_count;i++)if(thread_ids[i]==id)return threads[i];
 fail("unknown target thread");return NULL;
}
static void assign_points(CONTEXT *c) {
 c->Dr0=points[0];c->Dr1=points[1];c->Dr2=points[2];c->Dr3=points[3];c->Dr6=0;c->Dr7=0;
 for(unsigned i=0;i<4;i++)if(points[i])c->Dr7|=1u<<(i*2);
}
static void add_thread(DWORD id,HANDLE thread) {
 if(thread_count==128)fail("thread bound exceeded");
 threads[thread_count]=thread;thread_ids[thread_count++]=id;
 CONTEXT c;memset(&c,0,sizeof(c));c.ContextFlags=CONTEXT_DEBUG_REGISTERS;
 if(!GetThreadContext(thread,&c)||c.Dr7)fail("target thread already has debug registers in use");
 assign_points(&c);if(!SetThreadContext(thread,&c))fail("setting fixed hardware points failed");
}
static BOOL CALLBACK find_window(HWND window,LPARAM modal) {
 DWORD pid;GetWindowThreadProcessId(window,&pid);
 if(pid!=process_id||!IsWindowVisible(window))return TRUE;
 char name[128];GetClassNameA(window,name,sizeof(name));
 if(modal) {if(!strcmp(name,"#32770")) {dialog_window=window;return FALSE;}}
 else if(!GetWindow(window,GW_OWNER)&&strncmp(name,"#",1)) {main_window=window;return FALSE;}
 return TRUE;
}

static void log_state(const char *event) {
 printf("{\"event\":\"%s\",\"course\":%ld,\"selector\":%ld,\"boatClass\":%ld,\"raw4da188\":%ld,\"displaySetting\":%ld,\"island\":%ld,\"variant\":%ld,\"appState\":%ld,\"forecast\":%ld,\"popup\":%ld,\"tutorial\":%ld,\"frozen\":%ld}\n",event,
 (long)read_u32(0x4da19c),(long)read_u32(0x4da144),(long)read_u32(0x4da190),(long)read_u32(0x4da188),(long)read_u32(0x4da174),(long)read_u32(0x4f8b78),(long)read_u32(0x50040c),(long)read_u32(0x5363b0),(long)read_u32(0x5363f0),(long)read_u32(0x5233a8),(long)read_u32(0x536444),(long)read_u32(0x5363b4));
}
static void key(unsigned code) {
 if(!PostMessageA(view_window,WM_KEYDOWN,code,1)||!PostMessageA(view_window,WM_KEYUP,code,0xc0000001))fail("normal owned key message failed");
 printf("{\"event\":\"normal-key\",\"key\":%u}\n",code);
}
static void menu(unsigned command) {
 if(!PostMessageA(main_window,WM_COMMAND,command,0))fail("normal owned menu message failed");
 printf("{\"event\":\"normal-menu\",\"command\":%u}\n",command);
}
static void observe(CONTEXT *c) {
 if(c->Eip==0x440400) {
  if(read_u32(0x4f8b78)!=1||read_u32(0x4da174)>=13) {c->EFlags|=0x10000;return;}
  verify_text();entry_esp=c->Esp;return_address=read_u32(c->Esp);first_index=read_u32(c->Esp+12);mask=0;
  if(first_index>180)fail("first shore index outside fixed original array");
  points[1]=0x44092e;points[2]=points[3]=0;
  printf("{\"event\":\"shore-entry\",\"sample\":%u,\"entryEsp\":%lu,\"returnAddress\":%lu,\"first\":%lu,\"last\":%ld,\"camera\":%ld,\"centerProjectedY\":%ld,\"previousX\":%ld,\"previousTreeY\":%ld,\"xAddress\":%lu,\"yAddress\":%lu,\"controlWord\":%lu,\"textUnchanged\":true}\n",samples,(unsigned long)c->Esp,(unsigned long)return_address,(unsigned long)first_index,(long)read_u32(c->Esp+16),(long)read_u32(c->Esp+20),(long)read_u32(c->Esp-0xb6c),(long)read_u32(c->Esp-0xb54+first_index*4),(long)read_u32(c->Esp-0x880+first_index*4),(unsigned long)(c->Esp-0xb54+first_index*4),(unsigned long)(c->Esp-0x880+first_index*4),(unsigned long)(c->FloatSave.ControlWord&0xffff));
  log_state("shore-context");
  printf("{\"event\":\"shore-gates\",\"raw4f69b8\":%ld,\"vegetationSuppression\":%ld,\"raw5363e4\":%ld,\"raw536450\":%ld}\n",(long)read_u32(0x4f69b8),(long)read_u32(0x5363e0),(long)read_u32(0x5363e4),(long)read_u32(0x536450));
 } else if(c->Eip==0x44092e) {
  uint32_t index=read_u32(c->Esp+0x10);
  if(index==first_index) {
   int32_t random1=(int32_t)read_u32(read_u32(c->Esp+0x18));int32_t random2=(int32_t)read_u32(0x512d78+index*4);
   if(random1<=25){points[2]=0x440945;points[3]=0x440961;}
   else if(random2<=50){points[2]=0x4409a2;points[3]=0x4409ba;}
   else if(random1>50&&random2<75){points[2]=0x4409ee;points[3]=0x440a07;}
   else if(random1>=75){points[2]=0x440a28;points[3]=0x440a50;}
   printf("{\"event\":\"first-tree-branch\",\"sample\":%u,\"index\":%lu,\"random1\":%ld,\"random2\":%ld,\"readX\":%lu,\"readY\":%lu}\n",samples,(unsigned long)index,(long)random1,(long)random2,(unsigned long)points[2],(unsigned long)points[3]);
   /* A first random value 26..74 with random2>74 reads neither slot.
    * Keep the branch point for the second iteration at this same index. */
   if(points[2]&&points[3])points[1]=0;
  }
 } else if(c->Eip==points[2]&&!(mask&1)) {
  uint32_t address=c->Eip==0x440945?c->Ecx-4:c->Esp+c->Ecx*4+0x30;
  if(address!=entry_esp-0xb54+first_index*4)fail("original X read is not expected retained array slot");
  printf("{\"event\":\"consumed-retained-input\",\"sample\":%u,\"field\":\"previousX\",\"instruction\":%lu,\"address\":%lu,\"value\":%ld}\n",samples,(unsigned long)c->Eip,(unsigned long)address,(long)read_u32(address));mask|=1;points[2]=0;
 } else if(c->Eip==points[3]&&!(mask&2)) {
  uint32_t address=c->Edi-4;
  if(address!=entry_esp-0x880+first_index*4)fail("original Y read is not expected retained array slot");
  printf("{\"event\":\"consumed-retained-input\",\"sample\":%u,\"field\":\"previousTreeY\",\"instruction\":%lu,\"address\":%lu,\"value\":%ld}\n",samples,(unsigned long)c->Eip,(unsigned long)address,(long)read_u32(address));mask|=2;points[3]=0;
 }
 if(mask==3&&points[1]!=return_address) {points[1]=return_address;points[2]=points[3]=0;}
 else if(mask==3&&c->Eip==return_address) {
  printf("{\"event\":\"shore-return\",\"sample\":%u,\"previousX\":%ld,\"previousTreeY\":%ld,\"centerProjectedY\":%ld}\n",samples,(long)read_u32(entry_esp-0xb54+first_index*4),(long)read_u32(entry_esp-0x880+first_index*4),(long)read_u32(entry_esp-0xb6c));
  samples++;mask=0;points[1]=0x44092e;
 }
 c->EFlags|=0x10000;
}
int main(int argc,char **argv) {
 if(argc!=3)fail("expected exact original path and empty private working directory");
 validate_source(argv[1]);setvbuf(stdout,NULL,_IONBF,0);
 STARTUPINFOA si;PROCESS_INFORMATION pi;memset(&si,0,sizeof(si));si.cb=sizeof(si);
 char command[1024];if(strlen(argv[1])>1000)fail("source path too long");snprintf(command,sizeof(command),"\"%s\"",argv[1]);
 if(!CreateProcessA(argv[1],command,NULL,NULL,FALSE,DEBUG_ONLY_THIS_PROCESS,NULL,argv[2],&si,&pi))fail("normal original launch failed");
 process_id=pi.dwProcessId;process_handle=pi.hProcess;CloseHandle(pi.hThread);
 attached=TRUE;if(!DebugSetProcessKillOnExit(FALSE))fail("setting owned lifetime failed");
 printf("{\"event\":\"started\",\"processId\":%lu}\n",(unsigned long)process_id);
 DWORD started=GetTickCount(),last_action=started;
 while(GetTickCount()-started<20000&&samples<3) {
  DEBUG_EVENT e;BOOL received=WaitForDebugEvent(&e,50);
  if(received) {
   DWORD status=DBG_CONTINUE;
   if(e.dwDebugEventCode==CREATE_PROCESS_DEBUG_EVENT) {
    if((uintptr_t)e.u.CreateProcessInfo.lpBaseOfImage!=0x400000)fail("original image base changed");
    if(e.u.CreateProcessInfo.hFile)CloseHandle(e.u.CreateProcessInfo.hFile);
    add_thread(e.dwThreadId,e.u.CreateProcessInfo.hThread);verify_text();
   } else if(e.dwDebugEventCode==CREATE_THREAD_DEBUG_EVENT)add_thread(e.dwThreadId,e.u.CreateThread.hThread);
   else if(e.dwDebugEventCode==LOAD_DLL_DEBUG_EVENT) {if(e.u.LoadDll.hFile)CloseHandle(e.u.LoadDll.hFile);}
   else if(e.dwDebugEventCode==EXCEPTION_DEBUG_EVENT) {
    DWORD code=e.u.Exception.ExceptionRecord.ExceptionCode;
    if(code==EXCEPTION_SINGLE_STEP) {
     HANDLE t=thread_for(e.dwThreadId);CONTEXT c;memset(&c,0,sizeof(c));c.ContextFlags=CONTEXT_FULL|CONTEXT_FLOATING_POINT|CONTEXT_DEBUG_REGISTERS;
     if(!GetThreadContext(t,&c))fail("reading original context failed");
     BOOL found=FALSE;for(unsigned i=0;i<4;i++)if(points[i]&&c.Eip==points[i])found=TRUE;
     if(!found)fail("unexpected single-step point");
     observe(&c);assign_points(&c);c.ContextFlags=CONTEXT_CONTROL|CONTEXT_DEBUG_REGISTERS;
     if(!SetThreadContext(t,&c))fail("resuming observation failed");
    } else if(code!=EXCEPTION_BREAKPOINT)status=DBG_EXCEPTION_NOT_HANDLED;
   } else if(e.dwDebugEventCode==EXIT_PROCESS_DEBUG_EVENT) {exited=TRUE;fail("intact original exited during bounded observation");}
   if(!ContinueDebugEvent(e.dwProcessId,e.dwThreadId,status))fail("continuing original event failed");
  } else if(GetLastError()!=ERROR_SEM_TIMEOUT)fail("debug wait failed");
  DWORD now=GetTickCount();
  if(!main_window) {EnumWindows(find_window,0);if(main_window) {view_window=GetDlgItem(main_window,0xe900);if(!view_window)fail("original view HWND unavailable");last_action=now;}}
  if(main_window&&phase==0&&now-last_action>250) {log_state("before-ui");menu(32801);phase=1;last_action=now;}
  else if(phase==1&&now-last_action>250) {menu(32771);phase=2;last_action=now;}
  else if(phase==2&&now-last_action>250) {
   if(read_u32(0x5363f0)||read_u32(0x5233a8)||read_u32(0x536444))key(32);
   if(read_u32(0x5363e0)){menu(32983);}menu(32970);phase=3;last_action=now;log_state("after-ui");
  } else if(phase==3&&now-last_action>1000&&samples==0) {
   log_state("waiting-ui");if(read_u32(0x5363f0)||read_u32(0x5233a8)||read_u32(0x536444))key(32);
   menu(32970);last_action=now;
  }
 }
 verify_text();clear_points();if(!DebugActiveProcessStop(process_id))fail("detaching owned app failed");attached=FALSE;
 printf("{\"event\":\"complete\",\"samples\":%u,\"textUnchanged\":true,\"targetGameMemoryWrites\":0}\n",samples);
 PostMessageA(main_window,WM_CLOSE,0,0);
 CloseHandle(process_handle);free(original);return samples==3?0:3;
}

/* Bounded actual CDialog lifecycles in the fixed, intact 2010 English app.
 * Normal Windows loader, original MFC routing, actual radio/OK/Cancel controls.
 * Observation uses only ReadProcessMemory and per-thread hardware points.
 * No target instructions, game state, executable, or control word is written.
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
typedef struct {uint32_t resource,command,control,radio,result;} Scenario;
static const Scenario scenarios[]={
 {132,32823,1008,0x401040,1},{132,32823,1013,0x401090,2},
 {132,32823,1024,0x4010b0,1},{132,32823,1025,0x401100,2},
 {131,32779,1006,0x4013a0,1},{131,32779,1000,0x401430,2},
 {131,32779,1004,0x401400,1},{131,32779,1003,0x4014c0,2},
};
static const uint32_t fields[]={0x4da140,0x4da144,0x4da16c,0x4da190,0x4da194,
 0x5363b0,0x5363b4,0x5363c0,0x5363d0,0x5363d4,0x5363d8,0x5363dc,
 0x536400,0x536420,0x53642c,0x536470,0x5364c8,0x536528};
static HANDLE process_handle,threads[128];
static DWORD process_id,thread_ids[128],thread_count;
static uint8_t *original;static DWORD original_size;
static HWND main_window,view_window,dialog_window;
static uint32_t points[4];static unsigned case_index,phase,hits;
static BOOL attached,exited;

static void clear_points(void) {
 for(DWORD i=0;i<thread_count;i++) {
  if(SuspendThread(threads[i])==(DWORD)-1) continue;
  CONTEXT c;memset(&c,0,sizeof(c));c.ContextFlags=CONTEXT_DEBUG_REGISTERS;
  if(GetThreadContext(threads[i],&c)) {c.Dr0=c.Dr1=c.Dr2=c.Dr3=c.Dr6=c.Dr7=0;SetThreadContext(threads[i],&c);}
  ResumeThread(threads[i]);
 }
}
static void fail(const char *message) {
 fprintf(stderr,"modal-observer: %s; Win32 error %lu\n",message,(unsigned long)GetLastError());
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
static void install_points(void) {
 for(DWORD i=0;i<thread_count;i++) {
  if(SuspendThread(threads[i])==(DWORD)-1)continue;
  CONTEXT c;memset(&c,0,sizeof(c));c.ContextFlags=CONTEXT_DEBUG_REGISTERS;
  if(!GetThreadContext(threads[i],&c))fail("reading hardware context failed");
  assign_points(&c);if(!SetThreadContext(threads[i],&c))fail("updating fixed hardware points failed");
  ResumeThread(threads[i]);
 }
}
static BOOL CALLBACK find_window(HWND window,LPARAM modal) {
 DWORD pid;GetWindowThreadProcessId(window,&pid);
 if(pid!=process_id||!IsWindowVisible(window))return TRUE;
 char name[128];GetClassNameA(window,name,sizeof(name));
 if(modal) {if(!strcmp(name,"#32770")) {dialog_window=window;return FALSE;}}
 else if(!GetWindow(window,GW_OWNER)&&strncmp(name,"#",1)) {main_window=window;return FALSE;}
 return TRUE;
}
static void state(const char *point,const CONTEXT *context) {
 verify_text();uint8_t *block=(uint8_t *)malloc(0x60588),sha[32];if(!block)fail("state allocation failed");
 read_at(0x4da000,block,0x60588);hash_bytes(block,0x60588,sha);free(block);
 printf("{\"event\":\"observation\",\"case\":%u,\"point\":\"%s\",\"address\":%lu,\"eax\":%lu,\"controlWord\":%lu,\"mainWindow\":%lu,\"viewWindow\":%lu,\"dialogWindow\":%lu,\"textUnchanged\":true,\"mutableSha256\":\"",
 case_index,point,context?(unsigned long)context->Eip:0,context?(unsigned long)context->Eax:0,
 context?(unsigned long)(context->FloatSave.ControlWord&0xffff):0,(unsigned long)(uintptr_t)main_window,
 (unsigned long)(uintptr_t)view_window,(unsigned long)(uintptr_t)dialog_window);
 for(unsigned i=0;i<32;i++)printf("%02x",sha[i]);
 printf("\",\"fields\":[");
 for(unsigned i=0;i<sizeof(fields)/sizeof(fields[0]);i++)printf("%s[%lu,%lu]",i?",":"",(unsigned long)fields[i],(unsigned long)read_u32(fields[i]));
 printf("]");
 if(context&&!strcmp(point,"invalidate")) {uint32_t args[3];read_at(context->Esp,args,sizeof(args));
  printf(",\"invalidateArgs\":[%lu,%lu,%lu]",(unsigned long)args[0],(unsigned long)args[1],(unsigned long)args[2]);}
 if(context&&!strcmp(point,"end-dialog")) {uint32_t args[2];read_at(context->Esp,args,sizeof(args));
  printf(",\"endDialogArgs\":[%lu,%lu]",(unsigned long)args[0],(unsigned long)args[1]);}
 printf("}\n");
}
static void prepare_case(void) {
 const Scenario *s=&scenarios[case_index];dialog_window=NULL;hits=0;
 points[0]=s->resource==132?0x4901d0:0x4911c0;
 points[1]=s->radio+(s->resource==132?0x0a:0x12);
 points[2]=s->resource==132?0x490207:0x4911f7;
 points[3]=s->resource==131?(s->result==1?0x40150a:0x40153a):0;
 install_points();phase=1;
 printf("{\"event\":\"scenario\",\"case\":%u,\"resource\":%lu,\"command\":%lu,\"control\":%lu,\"result\":%lu}\n",case_index,(unsigned long)s->resource,(unsigned long)s->command,(unsigned long)s->control,(unsigned long)s->result);
 state("before-command",NULL);
 if(!PostMessageA(main_window,WM_COMMAND,s->command,0))fail("posting original menu command failed");
}
int main(int argc,char **argv) {
 if(argc!=3&&argc!=4)fail("expected original path, private working directory, optional exact owned PID");
 validate_source(argv[1]);setvbuf(stdout,NULL,_IONBF,0);
 if(argc==4) {
  char *end;unsigned long pid=strtoul(argv[3],&end,10);if(!pid||*end)fail("invalid PID");process_id=pid;
  process_handle=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ,FALSE,process_id);if(!process_handle)fail("opening owned app failed");
  char path[1024];DWORD n=sizeof(path);if(!QueryFullProcessImageNameA(process_handle,0,path,&n)||_stricmp(path,argv[1]))fail("owned app path does not match exact target");
  verify_text();if(!DebugActiveProcess(process_id))fail("attaching owned app failed");
 } else {
  STARTUPINFOA si;PROCESS_INFORMATION pi;memset(&si,0,sizeof(si));si.cb=sizeof(si);
  char command[1024];if(strlen(argv[1])>1000)fail("source path too long");snprintf(command,sizeof(command),"\"%s\"",argv[1]);
  if(!CreateProcessA(argv[1],command,NULL,NULL,FALSE,DEBUG_ONLY_THIS_PROCESS,NULL,argv[2],&si,&pi))fail("normal original launch failed");
  process_id=pi.dwProcessId;process_handle=pi.hProcess;CloseHandle(pi.hThread);
 }
 attached=TRUE;if(!DebugSetProcessKillOnExit(FALSE))fail("setting owned lifetime failed");
 printf("{\"event\":\"started\",\"processId\":%lu}\n",(unsigned long)process_id);
 DWORD started=GetTickCount(),last_action=started;unsigned bootstrap=0;
 while(GetTickCount()-started<90000&&case_index<sizeof(scenarios)/sizeof(scenarios[0])) {
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
     if(!GetThreadContext(t,&c))fail("reading fixed original context failed");
     BOOL found=FALSE;const Scenario *s=&scenarios[case_index];
     for(unsigned i=0;i<4;i++)if(points[i]&&c.Eip==points[i]) {
      found=TRUE;
      if(i==0&&c.Eip==(s->resource==132?0x4901d0u:0x4911c0u)) {state("command-entry",&c);points[0]=0x4ac0c4;hits|=1;}
      else if(i==0&&c.Eip==0x4ac0c4) {state("end-dialog",&c);points[0]=0x4ac0ca;hits|=64;}
      else if(i==0) {state("end-dialog-return",&c);points[0]=0;hits|=128;}
      else if(i==1&&s->resource==131&&c.Eip==s->radio+0x12) {state("invalidate",&c);points[1]=s->radio+0x22;hits|=256;}
      else if(i==1) {state("radio-return",&c);points[1]=0;hits|=2;}
      else if(i==3) {state("invalidate",&c);points[3]=0;hits|=4;}
      else if(c.Eip==(s->resource==132?0x490207u:0x4911f7u)) {state("modal-return",&c);points[2]=s->resource==132?0x490219:0x491209;hits|=8;}
      else if(c.Eip==(s->resource==132?0x490219u:0x491209u)) {state("invalidate",&c);points[2]=s->resource==132?0x49021f:0x49121d;hits|=16;}
      else {state("tail-complete",&c);points[2]=0;hits|=32;}
     }
     if(!found)fail("unexpected single-step point");
     assign_points(&c);c.EFlags|=0x10000;c.ContextFlags=CONTEXT_CONTROL|CONTEXT_DEBUG_REGISTERS;
     if(!SetThreadContext(t,&c))fail("resuming observation failed");
    } else if(code!=EXCEPTION_BREAKPOINT)status=DBG_EXCEPTION_NOT_HANDLED;
   } else if(e.dwDebugEventCode==EXIT_PROCESS_DEBUG_EVENT) {exited=TRUE;fail("intact original exited during modal sequence");}
   if(!ContinueDebugEvent(e.dwProcessId,e.dwThreadId,status))fail("continuing original event failed");
  } else if(GetLastError()!=ERROR_SEM_TIMEOUT)fail("debug wait failed");
  DWORD now=GetTickCount();
  if(!main_window) {EnumWindows(find_window,0);if(main_window) {view_window=GetDlgItem(main_window,0xe900);if(!view_window)fail("original active view HWND unavailable");last_action=now;}}
  if(main_window&&bootstrap==0&&now-last_action>250) {
   if(read_u32(0x5363b0)!=0||read_u32(0x536470)!=0)fail("modal proof requires normal original setup state");
   if(!PostMessageA(main_window,WM_COMMAND,32789,0))fail("posting original Custom class selection failed");
   bootstrap=1;last_action=now;
  } else if(bootstrap==1&&now-last_action>250) {
   if(read_u32(0x4da190)!=6||read_u32(0x5364c8)||read_u32(0x536528)||read_u32(0x5363c0))fail("original Design and Helm commands are not enabled");
   bootstrap=2;phase=0;last_action=now;
  }
  if(bootstrap==2&&phase==0&&now-last_action>100) {
   if(read_u32(0x53642c)) {PostMessageA(view_window,WM_KEYDOWN,0x46,1);PostMessageA(view_window,WM_KEYUP,0x46,0xc0000001);}
   PostMessageA(view_window,WM_KEYDOWN,0x46,1);PostMessageA(view_window,WM_KEYUP,0x46,0xc0000001);
   phase=5;last_action=now;
  } else if(phase==5&&now-last_action>100) {
   if(read_u32(0x5363b4)!=1||read_u32(0x53642c)!=1)fail("normal F input did not freeze setup before modal");
   prepare_case();last_action=now;
  } else if(phase==1&&(hits&1)) {
   dialog_window=NULL;EnumWindows(find_window,1);
   if(dialog_window) {const Scenario *s=&scenarios[case_index];HWND control=GetDlgItem(dialog_window,s->control);if(!control)fail("original radio control not found");
    if(!PostMessageA(control,BM_CLICK,0,0))fail("normal radio click failed");
    phase=2;last_action=now;}
  } else if(phase==2&&(hits&2)) {
   const Scenario *s=&scenarios[case_index];HWND button=GetDlgItem(dialog_window,s->result);if(!button)fail("original modal close button unavailable");
   if(!PostMessageA(button,BM_CLICK,0,0))fail("normal OK/Cancel click failed");
   phase=3;last_action=now;
  } else if(phase==3&&(hits&32)) {
   unsigned expected=scenarios[case_index].resource==131?511:251;if(hits!=expected)fail("bounded modal hardware observations incomplete");
   case_index++;phase=0;last_action=now;
  }
 }
 verify_text();clear_points();if(!DebugActiveProcessStop(process_id))fail("detaching exact owned app failed");attached=FALSE;
 printf("{\"event\":\"complete\",\"cases\":%u,\"textUnchanged\":true,\"targetGameMemoryWrites\":0}\n",case_index);
 CloseHandle(process_handle);free(original);return case_index==8?0:3;
}

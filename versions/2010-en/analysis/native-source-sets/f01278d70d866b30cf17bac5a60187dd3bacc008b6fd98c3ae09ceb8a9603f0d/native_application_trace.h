/* Closed constructor/archive oracle. Only original402440 and4036a0 execute.
 * Original CFile/CArchive, allocator, RNG, integer trig and GDI attachment code
 * run unchanged. Named OS time/metrics/GDI requests use bounded host bindings;
 * actual archive I/O is restricted to a private p.tac in the host's directory.
 */
static uint32_t application_owned_document[64],application_module_state[0x1074/4];
static uint32_t application_module_thread[0x84/4],application_slots[3];
static uint32_t application_height,application_epoch,application_event_count;
static SYSTEMTIME application_clock;
static uint32_t application_events[128][6];
static uint32_t application_handles[90];
static uint32_t application_object_count;
static uint32_t application_save_counter;

static void application_event(uint32_t type,uint32_t a,uint32_t b,uint32_t c,uint32_t d,uint32_t e) {
 if(application_event_count>=128)fail("application host request count exceeds bound");
 uint32_t *row=application_events[application_event_count++];row[0]=type;row[1]=a;row[2]=b;row[3]=c;row[4]=d;row[5]=e;
}
static HANDLE WINAPI application_open(LPCSTR name,DWORD access,DWORD sharing,LPSECURITY_ATTRIBUTES security,DWORD disposition,DWORD attributes,HANDLE template_file) {
 if(strcmp(name,"p.tac"))fail("constructor archive is outside the single private filename");
 application_event(1,access,sharing,disposition,attributes,0);
 return CreateFileA(name,access,sharing,security,disposition,attributes,template_file);
}
static int WINAPI application_metrics(int index) {
 if(index!=1)fail("constructor metric is outside the fixed screen-height input");
 application_event(2,(uint32_t)index,application_height,0,0,0);return (int)application_height;
}
static void WINAPI application_local_time(LPSYSTEMTIME time) {*time=application_clock;}
static void WINAPI application_system_time(LPSYSTEMTIME time) {*time=application_clock;}
static DWORD WINAPI application_timezone(LPTIME_ZONE_INFORMATION zone) {
 memset(zone,0,sizeof(*zone));return TIME_ZONE_ID_UNKNOWN;
}
static HPEN WINAPI application_pen(int style,int width,COLORREF color) {
 if(application_object_count>=90)fail("constructor GDI object count exceeds bound");
 HPEN (WINAPI *create_pen)(int,int,COLORREF)=(HPEN (WINAPI *)(int,int,COLORREF))(uintptr_t)GetProcAddress(GetModuleHandleA("gdi32.dll"),"CreatePen");
 if(!create_pen)fail("native CreatePen unavailable");
 HPEN handle=create_pen(style,width,color);if(!handle)fail("native pen creation failed");
 application_handles[application_object_count++]=(uint32_t)(uintptr_t)handle;
 application_event(3,(uint32_t)style,(uint32_t)width,color,(uint32_t)(uintptr_t)handle,0);return handle;
}
static HBRUSH WINAPI application_brush(COLORREF color) {
 if(application_object_count>=90)fail("constructor GDI object count exceeds bound");
 HBRUSH (WINAPI *create_brush)(COLORREF)=(HBRUSH (WINAPI *)(COLORREF))(uintptr_t)GetProcAddress(GetModuleHandleA("gdi32.dll"),"CreateSolidBrush");
 if(!create_brush)fail("native CreateSolidBrush unavailable");
 HBRUSH handle=create_brush(color);if(!handle)fail("native brush creation failed");
 application_handles[application_object_count++]=(uint32_t)(uintptr_t)handle;
 application_event(4,color,(uint32_t)(uintptr_t)handle,0,0,0);return handle;
}
static void application_bindings(uint32_t saved[2]) {
 prepare_controller_objects();
 memset(controller_thread_state,0,sizeof(controller_thread_state));
 memset(application_module_state,0,sizeof(application_module_state));memset(application_module_thread,0,sizeof(application_module_thread));
 uint8_t out[28]={0};invoke_controller(0x4bfbf9,NULL,0,out,controller_thread_state);
 invoke_controller(0x4bfe0d,NULL,0,out,application_module_thread);
 application_slots[0]=0;application_slots[1]=(uint32_t)(uintptr_t)controller_thread_state;
 application_slots[2]=(uint32_t)(uintptr_t)application_module_thread;
 controller_tls_container[2]=3;controller_tls_container[3]=(uint32_t)(uintptr_t)application_slots;
 application_module_state[0x1070/4]=2;
 uint32_t module_pointer=(uint32_t)(uintptr_t)application_module_state;
 memcpy(controller_thread_state+4,&module_pointer,4);
 saved[0]=*(uint32_t *)0x538010;saved[1]=*(uint32_t *)0x538148;
 *(uint32_t *)0x538010=1;*(uint32_t *)0x538148=(uint32_t)(uintptr_t)controller_tls_manager;
}
static void application_normalize(uint8_t *out,const uint8_t *raw) {
 memcpy(out,raw,DATA_BYTES);memcpy(out+TLS_ADDRESS-DATA_BASE,&original_tls_value,4);
 for(unsigned i=0;i<sizeof(cstring_ranges)/sizeof(cstring_ranges[0]);i++) {
  uint32_t offset=cstring_ranges[i][0]-DATA_BASE,width=cstring_ranges[i][1];memcpy(out+offset,baseline+offset,width);
 }
 /* Every logical handle is its exact original CGdiObject handle-slot address.
  * Actual native handles remain in the separate ordered request evidence. */
 for(unsigned i=0;i<application_object_count;i++) {
  uint32_t matches=0,address=0;
  for(uint32_t offset=0;offset+4<=DATA_BYTES;offset+=4) {
   uint32_t value;memcpy(&value,raw+offset,4);
   if(value==application_handles[i]) {matches++;address=DATA_BASE+offset;}
  }
  if(matches!=1)fail("native GDI handle does not identify one original data slot");
  memcpy(out+address-DATA_BASE,&address,4);
  for(uint32_t j=0;j<application_event_count;j++) {
   uint32_t *event=application_events[j];
   if((event[0]==3&&event[4]==application_handles[i])||(event[0]==4&&event[2]==application_handles[i]))event[5]=address;
  }
 }
}
static void application_append_state(size_t *length,const uint8_t *prior,const uint8_t *actual) {
 uint8_t hash[32];HCRYPTHASH h;DWORD n=32;
 if(!CryptCreateHash(state_hash_provider,CALG_SHA_256,0,0,&h)||!CryptHashData(h,actual,DATA_BYTES,0)||!CryptGetHashParam(h,HP_HASHVAL,hash,&n,0))fail("application state hash failed");
 CryptDestroyHash(h);append(length,hash,32);uint32_t count=0;size_t slot=*length;append_u32(length,0);
 for(uint32_t offset=0;offset<DATA_BYTES;) {
  if(prior[offset]==actual[offset]) {offset++;continue;}
  uint32_t first=offset;while(offset<DATA_BYTES&&prior[offset]!=actual[offset])offset++;
  uint32_t width=offset-first;append_u32(length,DATA_BASE+first);append_u32(length,width);
  append(length,prior+first,width);append(length,actual+first,width);count++;
 }
 memcpy(response+slot,&count,4);
}
/* command3: epoch,screenHeight,archiveBytes(0|636),archive,patchCount,
 * bounded [dataAddress,width,bytes]. Exactly one request per fresh owned host.
 * Response: normalized prepared-before block; constructor state; save state;
 * exact saved636-byte archive; ordered bounded host events; raw runtime deltas.
 */
static void run_application_case(void) {
 if(application_save_counter++)fail("constructor requires a fresh isolated host for each case");
 uint32_t archive_bytes,patches;uint8_t archive[636];
 read_exact(&application_epoch,4);read_exact(&application_height,4);read_exact(&archive_bytes,4);
 if(application_epoch>0x7fffffffu||application_height>4096||(archive_bytes!=0&&archive_bytes!=636))fail("constructor input outside fixed domain");
 if(archive_bytes)read_exact(archive,636);
 DeleteFileA("p.tac");
 if(archive_bytes) {
  HANDLE f=CreateFileA("p.tac",GENERIC_WRITE,0,NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);DWORD n;
  if(f==INVALID_HANDLE_VALUE||!WriteFile(f,archive,636,&n,NULL)||n!=636||!CloseHandle(f))fail("private original input archive preparation failed");
 }
 read_exact(&patches,4);if(patches>3)fail("application data patch count exceeds fixed fields");
 for(uint32_t i=0;i<patches;i++) {
  uint32_t address,width;read_exact(&address,4);read_exact(&width,4);
  if(width!=4||(address!=0x4da16c&&address!=0x536420&&address!=0x4da178))fail("application patch is outside edition, session, or retained speed inputs");
  read_exact((void *)(uintptr_t)address,width);
 }
 application_event_count=application_object_count=0;
 bind_import("CreateFileA",(uintptr_t)application_open);bind_import("GetSystemMetrics",(uintptr_t)application_metrics);
 bind_import("GetLocalTime",(uintptr_t)application_local_time);bind_import("GetSystemTime",(uintptr_t)application_system_time);
 bind_import("GetTimeZoneInformation",(uintptr_t)application_timezone);
 bind_import("CreatePen",(uintptr_t)application_pen);bind_import("CreateSolidBrush",(uintptr_t)application_brush);
 uint64_t ticks=((uint64_t)application_epoch+11644473600ull)*10000000ull;FILETIME time={(DWORD)ticks,(DWORD)(ticks>>32)};
 if(!FileTimeToSystemTime(&time,&application_clock))fail("bounded UTC input conversion failed");
 prepare_cstring_runtime();uint8_t returns[28]={0};uint32_t zero=0,framework_saved[2];
 x87_reset();invoke_original_words(0x49b7e0,&zero,1,returns,0);
 uint32_t seed;memcpy(&seed,returns,4);if(seed!=application_epoch)fail("original time conversion differs from explicit UTC input");
 application_bindings(framework_saved);
 /* Framework bindings are host objects, restored for image comparisons. */
 *(uint32_t *)0x538010=framework_saved[0];*(uint32_t *)0x538148=framework_saved[1];
 uint8_t *prepared=malloc(DATA_BYTES),*constructor=malloc(DATA_BYTES),*saved=malloc(DATA_BYTES),*raw_before=malloc(DATA_BYTES),*raw_after=malloc(DATA_BYTES);
 if(!prepared||!constructor||!saved||!raw_before||!raw_after)fail("application evidence allocation failed");
 memcpy(raw_before,(void *)DATA_BASE,DATA_BYTES);application_normalize(prepared,raw_before);
 *(uint32_t *)0x538010=1;*(uint32_t *)0x538148=(uint32_t)(uintptr_t)controller_tls_manager;
 memset(application_owned_document,0,sizeof(application_owned_document));
 x87_reset();invoke_controller(0x402440,NULL,0,returns,application_owned_document);verify_text_unchanged();
 *(uint32_t *)0x538010=framework_saved[0];*(uint32_t *)0x538148=framework_saved[1];
 memcpy(raw_after,(void *)DATA_BASE,DATA_BYTES);application_normalize(constructor,raw_after);
 uint32_t constructor_rng;memcpy(&constructor_rng,tls_record+0x14,4);uint16_t cw;__asm__ volatile("fnstcw %0":"=m"(cw));
 *(uint32_t *)0x538010=1;*(uint32_t *)0x538148=(uint32_t)(uintptr_t)controller_tls_manager;
 invoke_controller(0x4036a0,NULL,0,returns,application_owned_document);verify_text_unchanged();
 *(uint32_t *)0x538010=framework_saved[0];*(uint32_t *)0x538148=framework_saved[1];
 uint8_t *save_raw=malloc(DATA_BYTES);if(!save_raw)fail("save evidence allocation failed");
 memcpy(save_raw,(void *)DATA_BASE,DATA_BYTES);application_normalize(saved,save_raw);
 HANDLE f=CreateFileA("p.tac",GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);DWORD n;
 if(f==INVALID_HANDLE_VALUE||GetFileSize(f,NULL)!=636||!ReadFile(f,archive,636,&n,NULL)||n!=636||!CloseHandle(f))fail("original saved archive does not contain exactly636 bytes");
 size_t length=0;append_u32(&length,seed);append_u32(&length,constructor_rng);append_u32(&length,cw);append_u32(&length,DATA_BYTES);append(&length,prepared,DATA_BYTES);
 application_append_state(&length,prepared,constructor);application_append_state(&length,constructor,saved);
 append(&length,archive,636);append_u32(&length,application_event_count);append(&length,application_events,application_event_count*sizeof(application_events[0]));
 /* Preserve every raw runtime change, including allocator/handle identities. */
 application_append_state(&length,prepared,raw_before);application_append_state(&length,raw_before,raw_after);application_append_state(&length,raw_after,save_raw);
 uint32_t command=3,width=(uint32_t)length;write_exact(&command,4);write_exact(&width,4);write_exact(response,length);
 free(prepared);free(constructor);free(saved);free(raw_before);free(raw_after);free(save_raw);
}

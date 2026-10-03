/* Fixed original initialization -> retained 100-frame chains. No game code,
 * stack data, frame clocks, positions or RNG results are patched between calls.
 * Hardware execution observations read the real owned caller stack; a fixed
 * hardware stop returns the reviewed paint calibration fragment to this host.
 */
#include "native_chain_handles.h"
static uint32_t chain_active,chain_frames,chain_profiles;
static uint8_t *chain_comparison;
static uint32_t chain_shore_rows[32][7],chain_shore_count;
static uintptr_t calibration_saved_stack __attribute__((used));
static void __attribute__((naked,noinline)) calibration_return(void) {
    __asm__ volatile("movl _calibration_saved_stack,%esp\n\tpopl %edi\n\tpopl %esi\n\tpopl %ebx\n\tpopl %ebp\n\tret");
}
static void __attribute__((naked,noinline)) invoke_calibration(int32_t height __attribute__((unused))) {
    __asm__ volatile("pushl %ebp\n\tpushl %ebx\n\tpushl %esi\n\tpushl %edi\n\tmovl %esp,_calibration_saved_stack\n\tmovl 20(%esp),%ecx\n\txorl %ebx,%ebx\n\tmovl $0x403c62,%eax\n\tjmp *%eax");
}
static LONG CALLBACK chain_hardware_observer(PEXCEPTION_POINTERS exception) {
    CONTEXT *context=exception->ContextRecord;
    if(exception->ExceptionRecord->ExceptionCode!=EXCEPTION_SINGLE_STEP) return EXCEPTION_CONTINUE_SEARCH;
    if(context->Eip==0x403cbf) {
        context->Eip=(DWORD)(uintptr_t)calibration_return;context->Dr7&=~4u;
    } else if(context->Eip==0x42d120) {
        if(chain_shore_count>=32)fail("original frame exceeds fixed shoreline observation bound");
        uint32_t esp=context->Esp;int32_t first=*(int32_t *)(uintptr_t)(esp+12);
        if(first<0||first>360)fail("observed shoreline index exceeds original array bounds");
        MEMORY_BASIC_INFORMATION stack;
        if(!VirtualQuery((void *)(uintptr_t)(esp-0xb84),&stack,sizeof(stack)) || stack.State!=MEM_COMMIT ||
           (uintptr_t)stack.BaseAddress>esp-0xb84 || (uintptr_t)stack.BaseAddress+stack.RegionSize<esp+48)
            fail("owned original shoreline frame is not readable stack storage");
        uint32_t *row=chain_shore_rows[chain_shore_count++];
        row[0]=esp;row[1]=(uint32_t)first;row[2]=*(uint32_t *)(uintptr_t)(esp+16);
        row[3]=*(uint32_t *)(uintptr_t)(esp+20);row[4]=*(uint32_t *)(uintptr_t)(esp-0xb6c);
        row[5]=*(uint32_t *)(uintptr_t)(esp-0xb54+first*4);row[6]=*(uint32_t *)(uintptr_t)(esp-0x2d8+first*4);
    } else return EXCEPTION_CONTINUE_SEARCH;
    context->Dr6=0;context->EFlags|=0x10000;return EXCEPTION_CONTINUE_EXECUTION;
}
typedef struct {HANDLE main_thread,finished;uint32_t calibration,okay;} ChainDebugRequest;
static DWORD WINAPI set_owned_hardware_registers(void *opaque) {
    ChainDebugRequest *request=(ChainDebugRequest *)opaque;
    if(SuspendThread(request->main_thread)==(DWORD)-1){SetEvent(request->finished);return 0;}
    CONTEXT context;memset(&context,0,sizeof(context));context.ContextFlags=CONTEXT_DEBUG_REGISTERS;
    if(GetThreadContext(request->main_thread,&context)) {
        context.Dr0=0x42d120;context.Dr1=request->calibration?0x403cbf:0;context.Dr2=context.Dr3=context.Dr6=0;
        context.Dr7=request->calibration?5:1;
        request->okay=SetThreadContext(request->main_thread,&context);
    }
    ResumeThread(request->main_thread);SetEvent(request->finished);return 0;
}
static void enable_chain_hardware_observation(uint32_t calibration) {
    static void *handler;
    if(!handler) {handler=AddVectoredExceptionHandler(1,chain_hardware_observer);if(!handler)fail("installing owned hardware observer failed");}
    ChainDebugRequest request;memset(&request,0,sizeof(request));request.calibration=calibration;
    request.main_thread=OpenThread(THREAD_SUSPEND_RESUME|THREAD_GET_CONTEXT|THREAD_SET_CONTEXT,FALSE,GetCurrentThreadId());
    request.finished=CreateEventA(NULL,TRUE,FALSE,NULL);
    if(!request.main_thread||!request.finished)fail("creating bounded owned-thread observation failed");
    HANDLE worker=CreateThread(NULL,0,set_owned_hardware_registers,&request,0,NULL);
    if(!worker||WaitForSingleObject(request.finished,10000)!=WAIT_OBJECT_0||!request.okay)fail("setting owned hardware execution registers failed");
    if(WaitForSingleObject(worker,10000)!=WAIT_OBJECT_0)fail("owned observation worker did not finish");
    CloseHandle(worker);CloseHandle(request.finished);CloseHandle(request.main_thread);
}
static uint32_t chain_control_word(void){uint16_t word;__asm__ volatile("fnstcw %0":"=m"(word));return word;}
static void append_chain_state(uint8_t *output,size_t *length,const uint8_t captured[26]) {
    uint32_t routine=129,kind=3;uint8_t digest[32];
    bounded_append(output,length,&routine,4);bounded_append(output,length,&kind,4);
    bounded_append(output,length,captured,4);bounded_append(output,length,tls_record+0x14,4);
    bounded_append(output,length,&sound_count,4);bounded_append(output,length,sound_records,sound_count*12);
    hash_mutable_state(digest);bounded_append(output,length,digest,32);append_image_delta(output,length);
    bounded_append(output,length,&gdi_event_bytes,4);bounded_append(output,length,gdi_events,gdi_event_bytes);
    append_cstring_runtime_delta(output,length);
    uint32_t pointer=*(uint32_t *)0x4a7048,width=0;
    if(!pointer)fail("retained native HUD CString has no data");
    while(width<4096&&*(const char *)(uintptr_t)(pointer+width))width++;
    if(width==4096)fail("retained native HUD text exceeds fixed bound");
    bounded_append(output,length,&hud_string_active,4);bounded_append(output,length,&pointer,4);
    bounded_append(output,length,&width,4);bounded_append(output,length,(const void *)(uintptr_t)pointer,width);
    uint32_t elapsed=gdi_tick_calls?gdi_tick_calls-1:0;bounded_append(output,length,&elapsed,4);
}
static void run_frame_chain_command(void) {
    uint32_t operation;read_exact(&operation,4);
    if(TACT_X87_CONTROL_WORD!=0x027f)fail("retained original application chains require verified startup CW027f");
    uint8_t output[262144],captured[26]={0};size_t length=0;uint32_t before_cw,after_cw;
    bounded_append(output,&length,&operation,4);
    if(operation==0) {
        uint32_t seed;int32_t config[16];read_exact(&seed,4);read_exact(config,sizeof(config));
        if(++chain_profiles>3 || config[0]<1||config[0]>15||config[1]<1||config[1]>8||config[2]<0||config[2]>4||
           config[3]<1||config[3]>2||config[4]<1||config[4]>30||config[5]<1||config[5]>3||config[6]<0||config[6]>2||
           config[7]!=8||config[8]!=171||config[9]<1||config[9]>10||config[10]!=1024||config[11]!=768||config[12]!=24||
           config[13]||config[14]||config[15])fail("initial chain settings exceed fixed reviewed profiles");
        if(chain_active){((void (__attribute__((thiscall)) *)(void *))0x46bec5)((void *)0x4a7048);save_cstring_runtime();}
        restore_encounter_data();
        static const uint32_t setting_addresses[13]={0x491144,0x491194,0x4a4958,0x491140,0x49118c,0x4a4e8c,0x4a5a4c,0x49116c,0x491170,0x4911cc,0x4a763c,0x4a3f04,0x4aaa1c};
        for(unsigned i=0;i<13;i++)write_i32(setting_addresses[i],config[i]);
        write_i32(0x4a4e90,config[5]);write_i32(0x491178,config[7]);write_i32(0x491174,config[8]);
        write_i32(0x4a3f84,config[10]);write_i32(0x4ac8f8,2);write_i32(0x4ac1d4,0x400000);
        for(unsigned i=0;i<sizeof(chain_handle_slots)/sizeof(chain_handle_slots[0]);i++)write_i32(chain_handle_slots[i],chain_handle_slots[i]);
        bind_gdi_runtime();reset_gdi_trace();gdi_white_sampler=1;gdi_pixel_count=1024;
        gdi_menu_height=20;gdi_cursor.x=gdi_cursor.y=0;gdi_tick_start=0;gdi_tick_step=1;
        memcpy(tls_record+0x14,&seed,4);sound_count=0;
        if(!chain_comparison){chain_comparison=(uint8_t *)malloc(0x111000);if(!chain_comparison)fail("chain comparison allocation failed");}
        memcpy(chain_comparison,module,0x111000);normalization_snapshot=chain_comparison;
        uint32_t block_size=0x1d000;bounded_append(output,&length,&block_size,4);
        memcpy(chain_comparison+0x49fe40-0x400000,&original_tls_value,4);
        bounded_append(output,&length,chain_comparison+0x491000-0x400000,block_size);
        memcpy(image_snapshot,module,0x111000);x87_reset();prepare_cstring_runtime();x87_reset();hud_string_active=1;
        ((void (__attribute__((thiscall)) *)(void *))0x46bd7a)((void *)0x4a7048);
        before_cw=chain_control_word();chain_shore_count=0;enable_chain_hardware_observation(1);
        invoke_original_words(0x415a60,NULL,0,captured,0);
        invoke_original_words(0x42e080,NULL,0,captured,0);
        invoke_original_words(0x417790,NULL,0,captured,0);
        invoke_calibration(config[11]);
        invoke_original_words(0x413f00,NULL,0,captured,0);
        write_i32(0x4aa980,0); /* Declared normal start-UI transition after original initializer. */
        chain_active=1;chain_frames=0;
    } else if(operation==1) {
        uint32_t snapshot;read_exact(&snapshot,4);read_exact(&gdi_menu_height,4);read_exact(&gdi_cursor,sizeof(gdi_cursor));read_exact(&gdi_tick_start,4);
        if(!chain_active||++chain_frames>100||snapshot>1||gdi_menu_height<0||gdi_menu_height>128||gdi_cursor.x<-16384||gdi_cursor.x>16384||gdi_cursor.y<-16384||gdi_cursor.y>16384)fail("retained frame event exceeds fixed bounds");
        if(snapshot)write_i32(0x4ac9ec,1);
        memcpy(image_snapshot,module,0x111000);sound_count=0;reset_gdi_trace();gdi_white_sampler=1;gdi_pixel_count=1024;
        chain_shore_count=0;before_cw=chain_control_word();
        uint32_t dc=(uint32_t)(uintptr_t)gdi_cdc;invoke_original_words(0x404020,&dc,1,captured,0);
    } else fail("unknown fixed retained-chain operation");
    after_cw=chain_control_word();if(before_cw!=0x027f||after_cw!=0x027f)fail("original chain changed verified startup arithmetic context");
    save_cstring_runtime();verify_text_unchanged();
    size_t state_length_offset=length;uint32_t state_length=0;bounded_append(output,&length,&state_length,4);
    size_t state_begin=length;append_chain_state(output,&length,captured);state_length=(uint32_t)(length-state_begin);
    memcpy(output+state_length_offset,&state_length,4);
    bounded_append(output,&length,&chain_shore_count,4);bounded_append(output,&length,chain_shore_rows,chain_shore_count*28);
    bounded_append(output,&length,&before_cw,4);bounded_append(output,&length,&after_cw,4);reply(18,output,(uint32_t)length);
}

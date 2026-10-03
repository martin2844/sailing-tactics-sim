/* Observe the original first-tree predecessor reads only after 440400 has
 * allocated its local frame. The owned VEH writes no target code/data or x87
 * settings; its exception stack is below ESP and the observed arrays are above.
 * All hardware points are fixed original instructions, selected by the actual
 * original branch. There is no caller-supplied target or stack replacement.
 */
static uint32_t retained_shore_case;
static HANDLE retained_shore_thread;
static uint32_t retained_shore_x_point,retained_shore_y_point;
static uint32_t retained_shore_index,retained_shore_first,retained_shore_last;
static uint32_t retained_shore_camera,retained_shore_entry,retained_shore_x_address;
static int32_t retained_shore_x;
static unsigned retained_shore_x_read;

static void retained_shore_debug_points(CONTEXT *context) {
  context->Dr0=0x44092e;
  context->Dr1=retained_shore_x_point;
  context->Dr2=retained_shore_y_point;
  context->Dr3=0;
  context->Dr6=0;
  context->Dr7=1u|(retained_shore_x_point?4u:0u)|(retained_shore_y_point?16u:0u);
}

static LONG CALLBACK observe_retained_shore_read(PEXCEPTION_POINTERS exception) {
  if(exception->ExceptionRecord->ExceptionCode!=EXCEPTION_SINGLE_STEP)
    return EXCEPTION_CONTINUE_SEARCH;
  CONTEXT *context=exception->ContextRecord;
  if(context->Eip==0x44092e) {
    uint32_t first=*(uint32_t *)(uintptr_t)(context->Esp+0xb90);
    uint32_t index=*(uint32_t *)(uintptr_t)(context->Esp+0x10);
    if(first>180||index>180)fail("retained original shore index differs");
    if(index==first) {
      int32_t random1=*(int32_t *)(uintptr_t)*(uint32_t *)(uintptr_t)(context->Esp+0x18);
      int32_t random2=*(int32_t *)(uintptr_t)(0x512d78+index*4);
      retained_shore_x_point=retained_shore_y_point=0;
      if(random1<=25){retained_shore_x_point=0x440945;retained_shore_y_point=0x440961;}
      else if(random2<=50){retained_shore_x_point=0x4409a2;retained_shore_y_point=0x4409ba;}
      else if(random1>50&&random2<75){retained_shore_x_point=0x4409ee;retained_shore_y_point=0x440a07;}
      else if(random1>=75){retained_shore_x_point=0x440a28;retained_shore_y_point=0x440a50;}
      retained_shore_index=index;retained_shore_first=first;
      retained_shore_last=*(uint32_t *)(uintptr_t)(context->Esp+0xb94);
      retained_shore_camera=*(uint32_t *)(uintptr_t)(context->Esp+0xb98);
      retained_shore_entry=context->Esp+0xb84;
      retained_shore_x_read=0;
    }
  } else if(retained_shore_x_point&&context->Eip==retained_shore_x_point) {
    uint32_t address=context->Eip==0x440945?context->Ecx-4:context->Esp+context->Ecx*4+0x30;
    if(address!=retained_shore_entry-0xb54+retained_shore_first*4)
      fail("retained original X read address differs");
    retained_shore_x=*(int32_t *)(uintptr_t)address;
    retained_shore_x_address=address;
    retained_shore_x_read=1;
    retained_shore_x_point=0;
  } else if(retained_shore_y_point&&context->Eip==retained_shore_y_point) {
    uint32_t address=context->Edi-4;
    if(!retained_shore_x_read||address!=retained_shore_entry-0x880+retained_shore_first*4)
      fail("retained original Y read address differs");
    fprintf(stderr,"{\"event\":\"original-retained-shore-read\",\"case\":%lu,\"index\":%lu,\"first\":%lu,\"last\":%ld,\"camera\":%ld,\"instruction\":%lu,\"address\":%lu,\"previousTreeY\":%ld,\"xAddress\":%lu,\"previousX\":%ld,\"entryEsp\":%lu,\"controlWord\":%lu}\n",
      (unsigned long)retained_shore_case,(unsigned long)retained_shore_index,
      (unsigned long)retained_shore_first,(long)retained_shore_last,
      (long)retained_shore_camera,(unsigned long)context->Eip,(unsigned long)address,
      (long)*(int32_t *)(uintptr_t)address,(unsigned long)retained_shore_x_address,
      (long)retained_shore_x,(unsigned long)retained_shore_entry,
      (unsigned long)(context->FloatSave.ControlWord&0xffff));
    retained_shore_y_point=0;retained_shore_x_read=0;
  } else return EXCEPTION_CONTINUE_SEARCH;
  retained_shore_debug_points(context);
  context->EFlags|=0x10000;
  return EXCEPTION_CONTINUE_EXECUTION;
}

static DWORD WINAPI install_retained_shore_reads(LPVOID unused) {
  (void)unused;
  if(SuspendThread(retained_shore_thread)==(DWORD)-1)fail("suspending own retained oracle thread failed");
  CONTEXT context;memset(&context,0,sizeof(context));context.ContextFlags=CONTEXT_DEBUG_REGISTERS;
  if(!GetThreadContext(retained_shore_thread,&context)||context.Dr7)
    fail("own retained oracle hardware registers are unavailable");
  retained_shore_debug_points(&context);
  if(!SetThreadContext(retained_shore_thread,&context))fail("installing fixed retained shore points failed");
  if(ResumeThread(retained_shore_thread)==(DWORD)-1)fail("resuming own retained oracle thread failed");
  return 0;
}

static void initialize_retained_shore_reads(void) {
  if(!AddVectoredExceptionHandler(1,observe_retained_shore_read))fail("retained shore observer registration failed");
  if(!DuplicateHandle(GetCurrentProcess(),GetCurrentThread(),GetCurrentProcess(),
                      &retained_shore_thread,THREAD_ALL_ACCESS,FALSE,0))fail("opening own retained oracle thread failed");
  HANDLE worker=CreateThread(NULL,0,install_retained_shore_reads,NULL,0,NULL);
  if(!worker||WaitForSingleObject(worker,10000)!=WAIT_OBJECT_0)fail("fixed retained shore observer startup failed");
  CloseHandle(worker);
}

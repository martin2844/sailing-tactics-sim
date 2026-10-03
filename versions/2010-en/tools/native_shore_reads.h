/* Observe only the four verified predecessor-Y reads inside the already
 * allocated original 440400 frame. The VEH runs below the current ESP; the
 * observed arrays are above it. We deliberately do not trap function entry,
 * where exception delivery could overwrite the future uninitialized frame.
 * Original code, game memory and x87 settings remain unchanged.
 */
static DWORD shore_observation_case;
static HANDLE shore_main_thread;
static const uint32_t shore_y_reads[4]={0x440961,0x4409ba,0x440a07,0x440a50};
static LONG CALLBACK observe_original_shore_read(PEXCEPTION_POINTERS exception) {
  if(exception->ExceptionRecord->ExceptionCode!=EXCEPTION_SINGLE_STEP)
    return EXCEPTION_CONTINUE_SEARCH;
  CONTEXT *context=exception->ContextRecord;
  unsigned branch=4;
  for(unsigned index=0;index<4;index++)if(context->Eip==shore_y_reads[index])branch=index;
  if(branch==4)return EXCEPTION_CONTINUE_SEARCH;
  uint32_t first=*(uint32_t *)(uintptr_t)(context->Esp+0xb90);
  uint32_t index=*(uint32_t *)(uintptr_t)(context->Esp+0x10);
  uint32_t y_address=context->Edi-4;
  if(first>180||index>180||y_address!=context->Esp+0x304+index*4)
    fail("verified original shore read frame differs");
  if(index==first) {
    uint32_t x_address=context->Esp+0x30+index*4;
    fprintf(stderr,"{\"event\":\"original-shore-read\",\"case\":%lu,\"index\":%lu,\"first\":%lu,\"last\":%ld,\"camera\":%ld,\"instruction\":%lu,\"address\":%lu,\"previousTreeY\":%ld,\"xAddress\":%lu,\"previousXAtYRead\":%ld,\"entryEsp\":%lu,\"controlWord\":%lu}\n",
      (unsigned long)shore_observation_case,(unsigned long)index,(unsigned long)first,
      (long)*(int32_t *)(uintptr_t)(context->Esp+0xb94),
      (long)*(int32_t *)(uintptr_t)(context->Esp+0xb98),
      (unsigned long)context->Eip,(unsigned long)y_address,
      (long)*(int32_t *)(uintptr_t)y_address,(unsigned long)x_address,
      (long)*(int32_t *)(uintptr_t)x_address,(unsigned long)(context->Esp+0xb84),
      (unsigned long)(context->FloatSave.ControlWord&0xffff));
  }
  context->Dr6=0;context->EFlags|=0x10000;
  return EXCEPTION_CONTINUE_EXECUTION;
}
static DWORD WINAPI install_original_shore_reads(LPVOID unused) {
  (void)unused;
  if(SuspendThread(shore_main_thread)==(DWORD)-1)fail("suspending own oracle thread failed");
  CONTEXT context;memset(&context,0,sizeof(context));context.ContextFlags=CONTEXT_DEBUG_REGISTERS;
  if(!GetThreadContext(shore_main_thread,&context)||context.Dr7)
    fail("own oracle hardware registers are unavailable");
  context.Dr0=shore_y_reads[0];context.Dr1=shore_y_reads[1];
  context.Dr2=shore_y_reads[2];context.Dr3=shore_y_reads[3];context.Dr6=0;context.Dr7=0x55;
  if(!SetThreadContext(shore_main_thread,&context))fail("installing fixed own oracle hardware points failed");
  if(ResumeThread(shore_main_thread)==(DWORD)-1)fail("resuming own oracle thread failed");
  return 0;
}
static void initialize_original_shore_reads(void) {
  if(!AddVectoredExceptionHandler(1,observe_original_shore_read))fail("own bounded observer registration failed");
  if(!DuplicateHandle(GetCurrentProcess(),GetCurrentThread(),GetCurrentProcess(),
                      &shore_main_thread,THREAD_ALL_ACCESS,FALSE,0))fail("opening own oracle thread failed");
  HANDLE worker=CreateThread(NULL,0,install_original_shore_reads,NULL,0,NULL);
  if(!worker||WaitForSingleObject(worker,10000)!=WAIT_OBJECT_0)fail("fixed own observer startup failed");
  CloseHandle(worker);
}

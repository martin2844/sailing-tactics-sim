/* Native CRT/CString lifecycle for fixed original drawing calls.
 * Original allocator, CString, formatter and exception instructions execute.
 * Only host heap/critical-section bookkeeping is comparison-normalized. Its
 * raw before/after bytes are retained separately in every command-15 reply.
 */
static const uint32_t cstring_runtime_ranges[][2] = {
    {0x49ffa0, 0x80}, /* Original CRT lock-pointer table. */
    {0x4a0060, 0x2024}, /* Original CRT small-block-heap root and descriptors. */
    {0x4aebc8, 0x60}, /* Four original, statically allocated critical sections. */
    {0x4afdec, 4}, /* Original CRT process heap handle. */
    {0x4aec34, 4}, /* Original SBH free-page counter (0045bc60/0045bb30). */
};
static uint8_t cstring_saved_locks[0x80], cstring_saved_heap[0x2024];
static uint8_t cstring_saved_critical[0x60], cstring_saved_handle[4], cstring_saved_free_pages[4];
static uint8_t *cstring_saved_ranges[] = {
    cstring_saved_locks, cstring_saved_heap, cstring_saved_critical, cstring_saved_handle, cstring_saved_free_pages};
static uint32_t cstring_initialized;
static uint8_t *cstring_hash_copy;

static void save_cstring_runtime(void) {
    for (unsigned index=0; index<sizeof(cstring_runtime_ranges)/sizeof(cstring_runtime_ranges[0]); index++)
        memcpy(cstring_saved_ranges[index], (void *)(uintptr_t)cstring_runtime_ranges[index][0],
               cstring_runtime_ranges[index][1]);
}
static void prepare_cstring_runtime(void) {
    if (!cstring_initialized) {
        /* These are original CRT startup leaves, not the game entrypoint. */
        ((void (__cdecl *)(void))0x45b700)();
        if (!((int32_t (__cdecl *)(void))0x45b3c0)())
            fail("original CRT heap initialization failed");
        cstring_hash_copy=(uint8_t *)malloc(0x1d000);
        if (!cstring_hash_copy) fail("CString comparison state allocation failed");
        save_cstring_runtime(); cstring_initialized=1;
    } else {
        for (unsigned index=0; index<sizeof(cstring_runtime_ranges)/sizeof(cstring_runtime_ranges[0]); index++)
            memcpy((void *)(uintptr_t)cstring_runtime_ranges[index][0], cstring_saved_ranges[index],
                   cstring_runtime_ranges[index][1]);
    }
    cstring_active=1;
}
static uint32_t cstring_range_end(uint32_t address) {
    if (!cstring_active) return 0;
    if (hud_string_active && 0x4a7048<=address && address<0x4a704c) return 0x4a704c;
    for (unsigned index=0; index<sizeof(cstring_runtime_ranges)/sizeof(cstring_runtime_ranges[0]); index++) {
        uint32_t first=cstring_runtime_ranges[index][0], last=first+cstring_runtime_ranges[index][1];
        if (first<=address && address<last) return last;
    }
    return 0;
}
static void append_cstring_runtime_delta(uint8_t *output, size_t *length) {
    uint32_t count=0; size_t count_offset=*length;
    bounded_append(output,length,&cstring_active,4);
    bounded_append(output,length,&count,4);
    if (cstring_active) for (unsigned index=0; index<sizeof(cstring_runtime_ranges)/sizeof(cstring_runtime_ranges[0]); index++) {
        uint32_t offset=cstring_runtime_ranges[index][0]-0x400000;
        uint32_t end=offset+cstring_runtime_ranges[index][1];
        while (offset<end) {
            if (image_snapshot[offset]==module[offset]) { offset++; continue; }
            uint32_t first=offset;
            while (offset<end && image_snapshot[offset]!=module[offset]) offset++;
            uint32_t address=first+0x400000, width=offset-first;
            bounded_append(output,length,&address,4);bounded_append(output,length,&width,4);
            bounded_append(output,length,image_snapshot+first,width);
            bounded_append(output,length,module+first,width);count++;
        }
    }
    memcpy(output+count_offset+4,&count,4);
}

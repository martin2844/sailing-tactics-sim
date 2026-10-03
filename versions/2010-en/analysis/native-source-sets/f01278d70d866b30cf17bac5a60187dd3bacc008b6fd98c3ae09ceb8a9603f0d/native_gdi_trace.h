static uint32_t gdi_call_sites[4096][3], gdi_call_count;
static void observe_gdi_call(uintptr_t return_address,uint32_t service,uint32_t pop_bytes) {
    if (return_address<0x401000 || return_address>=0x4c7316) return;
    for (uint32_t index=0;index<gdi_call_count;index++) {
        if (gdi_call_sites[index][0]==return_address && gdi_call_sites[index][1]==service) {
            if (gdi_call_sites[index][2]!=pop_bytes) fail("conflicting native ABI observations");
            return;
        }
    }
    if (gdi_call_count>=4096) fail("native GDI callsite count exceeds bound");
    gdi_call_sites[gdi_call_count][0]=(uint32_t)return_address;
    gdi_call_sites[gdi_call_count][1]=service;
    gdi_call_sites[gdi_call_count][2]=pop_bytes;gdi_call_count++;
}
#define OBSERVE_GDI(service,pop_bytes) observe_gdi_call((uintptr_t)__builtin_return_address(0),service,pop_bytes)
/* Observational GDI/framework runtime for fixed unchanged 2010 English drawing calls.
 * Binary events preserve signed coordinates, logical handle values and order.
 * This records requests; it does not assert Windows pixel/font raster identity.
 */
static uint8_t *gdi_events;
#define GDI_BYTES 2097152u
static uint32_t gdi_event_bytes;
static uint32_t gdi_vtable[32], gdi_cdc[4];
static POINT gdi_position;
static uint32_t gdi_text_color, gdi_background_color;
static int32_t gdi_background_mode;
static uint32_t gdi_pixel_values[1024], gdi_pixel_count, gdi_pixel_cursor;
static uint32_t gdi_white_sampler;
static int32_t gdi_menu_height=20;
static POINT gdi_cursor;
static uint32_t gdi_tick_start,gdi_tick_step=1,gdi_tick_calls;
#define TRACE_CLIP_REGION ((uintptr_t)0x30000001)
#define TRACE_PREVIOUS_REGION ((uintptr_t)0x30000002)

static void record_gdi(uint32_t op, const void *bytes, uint32_t count) {
    if (count>GDI_BYTES-8 || gdi_event_bytes>GDI_BYTES-8-count)
        fail("GDI event evidence exceeds fixed bound");
    memcpy(gdi_events+gdi_event_bytes,&op,4);
    memcpy(gdi_events+gdi_event_bytes+4,&count,4);
    memcpy(gdi_events+gdi_event_bytes+8,bytes,count);
    gdi_event_bytes+=8+count;
}
static __attribute__((noinline)) uint32_t __attribute__((thiscall)) trace_stock(void *dc, int32_t index) {
    OBSERVE_GDI(0x1002c,4);
    (void)dc; record_gdi(1,&index,4); return 0;
}
static __attribute__((noinline)) HGDIOBJ WINAPI trace_select(HDC dc, HGDIOBJ handle) {
    OBSERVE_GDI(0x2,8);
    (void)dc; uint32_t value=(uint32_t)(uintptr_t)handle;
    if ((uintptr_t)handle==TRACE_CLIP_REGION) return (HGDIOBJ)TRACE_PREVIOUS_REGION;
    if ((uintptr_t)handle==TRACE_PREVIOUS_REGION) {
        record_gdi(16,NULL,0); return (HGDIOBJ)TRACE_CLIP_REGION;
    }
    record_gdi(2,&value,4); return NULL;
}
static __attribute__((noinline)) HRGN WINAPI trace_clip_region(int left, int top, int right, int bottom) {
    OBSERVE_GDI(0xf,16);
    int32_t bounds[4]={left,top,right,bottom};record_gdi(15,bounds,16);
    return (HRGN)TRACE_CLIP_REGION;
}
static __attribute__((noinline)) BOOL WINAPI trace_delete_object(HGDIOBJ handle) {
    OBSERVE_GDI(0x14,4); (void)handle;return TRUE; }
static __attribute__((noinline)) BOOL WINAPI trace_move(HDC dc, int x, int y, LPPOINT previous) {
    OBSERVE_GDI(0x3,16);
    (void)dc; if (previous) *previous=gdi_position;
    int32_t coords[2]={x,y}; gdi_position.x=x;gdi_position.y=y;
    record_gdi(3,coords,8); return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_line(HDC dc, int x, int y) {
    OBSERVE_GDI(0x4,12);
    (void)dc; int32_t coords[2]={x,y};gdi_position.x=x;gdi_position.y=y;
    record_gdi(4,coords,8);return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_polygon(HDC dc, const POINT *points, int count) {
    OBSERVE_GDI(0x5,12);
    (void)dc; uint8_t bytes[8196];
    if (count<0 || count>1024) fail("GDI polygon point count outside fixed bound");
    memcpy(bytes,&count,4);memcpy(bytes+4,points,(size_t)count*8);
    record_gdi(5,bytes,4+(uint32_t)count*8);return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_ellipse(HDC dc, int left, int top, int right, int bottom) {
    OBSERVE_GDI(0x6,20);
    (void)dc;int32_t bounds[4]={left,top,right,bottom};record_gdi(6,bounds,16);return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_rectangle(HDC dc, int left, int top, int right, int bottom) {
    OBSERVE_GDI(0x7,20);
    (void)dc;int32_t bounds[4]={left,top,right,bottom};record_gdi(7,bounds,16);return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_arc(HDC dc, int left, int top, int right, int bottom, int start_x, int start_y, int end_x, int end_y) {
    OBSERVE_GDI(0xd,36);
    (void)dc;int32_t values[8]={left,top,right,bottom,start_x,start_y,end_x,end_y};record_gdi(13,values,32);return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_pie(HDC dc, int left, int top, int right, int bottom, int start_x, int start_y, int end_x, int end_y) {
    OBSERVE_GDI(0xe,36);
    (void)dc;int32_t values[8]={left,top,right,bottom,start_x,start_y,end_x,end_y};record_gdi(14,values,32);return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_round_rect(HDC dc, int left, int top, int right, int bottom, int width, int height) {
    OBSERVE_GDI(0x11,28);
    (void)dc;int32_t values[6]={left,top,right,bottom,width,height};record_gdi(17,values,24);return TRUE;
}
static __attribute__((noinline)) BOOL WINAPI trace_beep(UINT type) {
    OBSERVE_GDI(0x12,4); record_gdi(18,&type,4);return TRUE; }
static __attribute__((noinline)) int WINAPI trace_system_metrics(int index) {
    OBSERVE_GDI(0x15,4); return index==15?gdi_menu_height:0; }
static __attribute__((noinline)) BOOL WINAPI trace_cursor_position(LPPOINT point) {
    OBSERVE_GDI(0x16,4); *point=gdi_cursor;return TRUE; }
static __attribute__((noinline)) DWORD WINAPI trace_tick_count(void) {
    OBSERVE_GDI(0x17,0);
    if (gdi_tick_calls>=100000) fail("original timer loop exceeds fixed host-input bound");
    return gdi_tick_start+gdi_tick_step*gdi_tick_calls++;
}
static __attribute__((noinline)) COLORREF WINAPI trace_pixel(HDC dc, int x, int y, COLORREF color) {
    OBSERVE_GDI(0x8,16);
    (void)dc;uint32_t values[3]={(uint32_t)x,(uint32_t)y,color};record_gdi(8,values,12);return color;
}
static __attribute__((noinline)) COLORREF WINAPI trace_read_pixel(HDC dc, int x, int y) {
    OBSERVE_GDI(0x13,12);
    (void)dc;
    if (gdi_pixel_cursor>=gdi_pixel_count) fail("original GetPixel exceeds explicit synthetic read inputs");
    uint32_t color=gdi_white_sampler?0xffffff:gdi_pixel_values[gdi_pixel_cursor];
    gdi_pixel_cursor++;
    uint32_t values[3]={(uint32_t)x,(uint32_t)y,color};record_gdi(19,values,12);return color;
}
static __attribute__((noinline)) COLORREF WINAPI trace_text_color(HDC dc, COLORREF color) {
    OBSERVE_GDI(0x9,8);
    (void)dc;uint32_t previous=gdi_text_color;gdi_text_color=color;record_gdi(9,&color,4);return previous;
}
static __attribute__((noinline)) COLORREF WINAPI trace_background_color(HDC dc, COLORREF color) {
    OBSERVE_GDI(0xa,8);
    (void)dc;uint32_t previous=gdi_background_color;gdi_background_color=color;record_gdi(10,&color,4);return previous;
}
static __attribute__((noinline)) int WINAPI trace_background_mode(HDC dc, int mode) {
    OBSERVE_GDI(0xb,8);
    (void)dc;int previous=gdi_background_mode;gdi_background_mode=mode;record_gdi(11,&mode,4);return previous;
}
static __attribute__((noinline)) BOOL WINAPI trace_text(HDC dc, int x, int y, LPCSTR text, int count) {
    OBSERVE_GDI(0xc,20);
    (void)dc;uint8_t bytes[4108];int32_t coordinates[2]={x,y};
    if (count<0 || count>4096) fail("GDI text length outside fixed bound");
    memcpy(bytes,coordinates,8);memcpy(bytes+8,&count,4);memcpy(bytes+12,text,(size_t)count);
    record_gdi(12,bytes,12+(uint32_t)count);return TRUE;
}
static __attribute__((noinline)) COLORREF __attribute__((thiscall)) trace_cdc_background(void *dc, COLORREF color) {
    OBSERVE_GDI(0x10034,4);
    return trace_background_color((HDC)dc,color);
}
static __attribute__((noinline)) COLORREF __attribute__((thiscall)) trace_cdc_text_color(void *dc, COLORREF color) {
    OBSERVE_GDI(0x10038,4);
    return trace_text_color((HDC)dc,color);
}
static __attribute__((noinline)) BOOL __attribute__((thiscall)) trace_cdc_text(void *dc, int x, int y, LPCSTR text, int count) {
    OBSERVE_GDI(0x10064,16);
    return trace_text((HDC)dc,x,y,text,count);
}
static __attribute__((noinline)) int __attribute__((thiscall)) trace_cdc_background_mode(void *dc, int mode) {
    OBSERVE_GDI(0x10030,4);
    return trace_background_mode((HDC)dc,mode);
}
static void bind_gdi_runtime(void) {
    /* A host-owned observational CDC/vtable; original readonly vtable untouched. */
    memcpy(gdi_vtable,(void *)0x4cecc4,sizeof(gdi_vtable));
    gdi_vtable[0x2c/4]=(uint32_t)(uintptr_t)trace_stock;
    gdi_vtable[0x30/4]=(uint32_t)(uintptr_t)trace_cdc_background_mode;
    gdi_vtable[0x34/4]=(uint32_t)(uintptr_t)trace_cdc_background;
    gdi_vtable[0x38/4]=(uint32_t)(uintptr_t)trace_cdc_text_color;
    gdi_vtable[0x64/4]=(uint32_t)(uintptr_t)trace_cdc_text;
    gdi_cdc[0]=(uint32_t)(uintptr_t)gdi_vtable;gdi_cdc[1]=1;gdi_cdc[2]=0;gdi_cdc[3]=0;
    bind_import("Polygon",(uintptr_t)trace_polygon);
    bind_import("DeleteObject",(uintptr_t)trace_delete_object);
    bind_import("SelectObject",(uintptr_t)trace_select);
    bind_import("CreateRectRgn",(uintptr_t)trace_clip_region);
    bind_import("Rectangle",(uintptr_t)trace_rectangle);
    bind_import("Ellipse",(uintptr_t)trace_ellipse);
    bind_import("RoundRect",(uintptr_t)trace_round_rect);
    bind_import("Pie",(uintptr_t)trace_pie);
    bind_import("SetPixel",(uintptr_t)trace_pixel);
    bind_import("TextOutA",(uintptr_t)trace_text);
    bind_import("Arc",(uintptr_t)trace_arc);
    bind_import("GetPixel",(uintptr_t)trace_read_pixel);
    bind_import("SetBkColor",(uintptr_t)trace_background_color);
    bind_import("SetTextColor",(uintptr_t)trace_text_color);
    bind_import("SetBkMode",(uintptr_t)trace_background_mode);
    bind_import("GetTickCount",(uintptr_t)trace_tick_count);
    bind_import("GetCursorPos",(uintptr_t)trace_cursor_position);
    bind_import("GetSystemMetrics",(uintptr_t)trace_system_metrics);
    bind_import("MoveToEx",(uintptr_t)trace_move);
    bind_import("LineTo",(uintptr_t)trace_line);
    bind_import("MessageBeep",(uintptr_t)trace_beep);

}
static void reset_gdi_trace(void) {
    gdi_call_count=0;gdi_event_bytes=0;gdi_position.x=0;gdi_position.y=0;
    gdi_text_color=0;gdi_background_color=0xffffff;gdi_background_mode=2;
    gdi_pixel_cursor=0;
    gdi_tick_calls=0;
}

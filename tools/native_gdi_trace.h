/* Observational GDI/framework runtime for fixed unchanged 2002 drawing calls.
 * Binary events preserve signed coordinates, logical handle values and order.
 * This records requests; it does not assert Windows pixel/font raster identity.
 */
static uint8_t gdi_events[131072];
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
    if (count>sizeof(gdi_events)-8 || gdi_event_bytes>sizeof(gdi_events)-8-count)
        fail("GDI event evidence exceeds fixed bound");
    memcpy(gdi_events+gdi_event_bytes,&op,4);
    memcpy(gdi_events+gdi_event_bytes+4,&count,4);
    memcpy(gdi_events+gdi_event_bytes+8,bytes,count);
    gdi_event_bytes+=8+count;
}
static uint32_t __attribute__((thiscall)) trace_stock(void *dc, int32_t index) {
    (void)dc; record_gdi(1,&index,4); return 0;
}
static HGDIOBJ WINAPI trace_select(HDC dc, HGDIOBJ handle) {
    (void)dc; uint32_t value=(uint32_t)(uintptr_t)handle;
    if ((uintptr_t)handle==TRACE_CLIP_REGION) return (HGDIOBJ)TRACE_PREVIOUS_REGION;
    if ((uintptr_t)handle==TRACE_PREVIOUS_REGION) {
        record_gdi(16,NULL,0); return (HGDIOBJ)TRACE_CLIP_REGION;
    }
    record_gdi(2,&value,4); return NULL;
}
static HRGN WINAPI trace_clip_region(int left, int top, int right, int bottom) {
    int32_t bounds[4]={left,top,right,bottom};record_gdi(15,bounds,16);
    return (HRGN)TRACE_CLIP_REGION;
}
static BOOL WINAPI trace_delete_object(HGDIOBJ handle) { (void)handle;return TRUE; }
static BOOL WINAPI trace_move(HDC dc, int x, int y, LPPOINT previous) {
    (void)dc; if (previous) *previous=gdi_position;
    int32_t coords[2]={x,y}; gdi_position.x=x;gdi_position.y=y;
    record_gdi(3,coords,8); return TRUE;
}
static BOOL WINAPI trace_line(HDC dc, int x, int y) {
    (void)dc; int32_t coords[2]={x,y};gdi_position.x=x;gdi_position.y=y;
    record_gdi(4,coords,8);return TRUE;
}
static BOOL WINAPI trace_polygon(HDC dc, const POINT *points, int count) {
    (void)dc; uint8_t bytes[8196];
    if (count<0 || count>1024) fail("GDI polygon point count outside fixed bound");
    memcpy(bytes,&count,4);memcpy(bytes+4,points,(size_t)count*8);
    record_gdi(5,bytes,4+(uint32_t)count*8);return TRUE;
}
static BOOL WINAPI trace_ellipse(HDC dc, int left, int top, int right, int bottom) {
    (void)dc;int32_t bounds[4]={left,top,right,bottom};record_gdi(6,bounds,16);return TRUE;
}
static BOOL WINAPI trace_rectangle(HDC dc, int left, int top, int right, int bottom) {
    (void)dc;int32_t bounds[4]={left,top,right,bottom};record_gdi(7,bounds,16);return TRUE;
}
static BOOL WINAPI trace_arc(HDC dc, int left, int top, int right, int bottom, int start_x, int start_y, int end_x, int end_y) {
    (void)dc;int32_t values[8]={left,top,right,bottom,start_x,start_y,end_x,end_y};record_gdi(13,values,32);return TRUE;
}
static BOOL WINAPI trace_pie(HDC dc, int left, int top, int right, int bottom, int start_x, int start_y, int end_x, int end_y) {
    (void)dc;int32_t values[8]={left,top,right,bottom,start_x,start_y,end_x,end_y};record_gdi(14,values,32);return TRUE;
}
static BOOL WINAPI trace_round_rect(HDC dc, int left, int top, int right, int bottom, int width, int height) {
    (void)dc;int32_t values[6]={left,top,right,bottom,width,height};record_gdi(17,values,24);return TRUE;
}
static BOOL WINAPI trace_beep(UINT type) { record_gdi(18,&type,4);return TRUE; }
static int WINAPI trace_system_metrics(int index) { return index==15?gdi_menu_height:0; }
static BOOL WINAPI trace_cursor_position(LPPOINT point) { *point=gdi_cursor;return TRUE; }
static DWORD WINAPI trace_tick_count(void) {
    if (gdi_tick_calls>=100000) fail("original timer loop exceeds fixed host-input bound");
    return gdi_tick_start+gdi_tick_step*gdi_tick_calls++;
}
static COLORREF WINAPI trace_pixel(HDC dc, int x, int y, COLORREF color) {
    (void)dc;uint32_t values[3]={(uint32_t)x,(uint32_t)y,color};record_gdi(8,values,12);return color;
}
static COLORREF WINAPI trace_read_pixel(HDC dc, int x, int y) {
    (void)dc;
    if (gdi_pixel_cursor>=gdi_pixel_count) fail("original GetPixel exceeds explicit synthetic read inputs");
    uint32_t color=gdi_white_sampler?0xffffff:gdi_pixel_values[gdi_pixel_cursor];
    gdi_pixel_cursor++;
    uint32_t values[3]={(uint32_t)x,(uint32_t)y,color};record_gdi(19,values,12);return color;
}
static COLORREF WINAPI trace_text_color(HDC dc, COLORREF color) {
    (void)dc;uint32_t previous=gdi_text_color;gdi_text_color=color;record_gdi(9,&color,4);return previous;
}
static COLORREF WINAPI trace_background_color(HDC dc, COLORREF color) {
    (void)dc;uint32_t previous=gdi_background_color;gdi_background_color=color;record_gdi(10,&color,4);return previous;
}
static int WINAPI trace_background_mode(HDC dc, int mode) {
    (void)dc;int previous=gdi_background_mode;gdi_background_mode=mode;record_gdi(11,&mode,4);return previous;
}
static BOOL WINAPI trace_text(HDC dc, int x, int y, LPCSTR text, int count) {
    (void)dc;uint8_t bytes[4108];int32_t coordinates[2]={x,y};
    if (count<0 || count>4096) fail("GDI text length outside fixed bound");
    memcpy(bytes,coordinates,8);memcpy(bytes+8,&count,4);memcpy(bytes+12,text,(size_t)count);
    record_gdi(12,bytes,12+(uint32_t)count);return TRUE;
}
static COLORREF __attribute__((thiscall)) trace_cdc_background(void *dc, COLORREF color) {
    return trace_background_color((HDC)dc,color);
}
static COLORREF __attribute__((thiscall)) trace_cdc_text_color(void *dc, COLORREF color) {
    return trace_text_color((HDC)dc,color);
}
static BOOL __attribute__((thiscall)) trace_cdc_text(void *dc, int x, int y, LPCSTR text, int count) {
    return trace_text((HDC)dc,x,y,text,count);
}
static void bind_gdi_runtime(void) {
    /* A host-owned observational CDC/vtable; original readonly vtable untouched. */
    memcpy(gdi_vtable,(void *)0x487024,sizeof(gdi_vtable));
    gdi_vtable[0x2c/4]=(uint32_t)(uintptr_t)trace_stock;
    gdi_vtable[0x34/4]=(uint32_t)(uintptr_t)trace_cdc_background;
    gdi_vtable[0x38/4]=(uint32_t)(uintptr_t)trace_cdc_text_color;
    gdi_vtable[0x64/4]=(uint32_t)(uintptr_t)trace_cdc_text;
    gdi_cdc[0]=(uint32_t)(uintptr_t)gdi_vtable;gdi_cdc[1]=1;gdi_cdc[2]=0;gdi_cdc[3]=0;
    *(uint32_t *)0x4b16e0=(uint32_t)(uintptr_t)trace_polygon;
    *(uint32_t *)0x4b16dc=(uint32_t)(uintptr_t)trace_delete_object;
    *(uint32_t *)0x4b16e8=(uint32_t)(uintptr_t)trace_select;
    *(uint32_t *)0x4b16ec=(uint32_t)(uintptr_t)trace_clip_region;
    *(uint32_t *)0x4b16f0=(uint32_t)(uintptr_t)trace_rectangle;
    *(uint32_t *)0x4b16f4=(uint32_t)(uintptr_t)trace_ellipse;
    *(uint32_t *)0x4b16f8=(uint32_t)(uintptr_t)trace_round_rect;
    *(uint32_t *)0x4b16fc=(uint32_t)(uintptr_t)trace_pie;
    *(uint32_t *)0x4b1700=(uint32_t)(uintptr_t)trace_pixel;
    *(uint32_t *)0x4b1704=(uint32_t)(uintptr_t)trace_text;
    *(uint32_t *)0x4b1708=(uint32_t)(uintptr_t)trace_arc;
    *(uint32_t *)0x4b170c=(uint32_t)(uintptr_t)trace_read_pixel;
    *(uint32_t *)0x4b1710=(uint32_t)(uintptr_t)trace_background_color;
    *(uint32_t *)0x4b1714=(uint32_t)(uintptr_t)trace_text_color;
    *(uint32_t *)0x4b1734=(uint32_t)(uintptr_t)trace_background_mode;
    *(uint32_t *)0x4b1910=(uint32_t)(uintptr_t)trace_tick_count;
    *(uint32_t *)0x4b1bb8=(uint32_t)(uintptr_t)trace_cursor_position;
    *(uint32_t *)0x4b1bbc=(uint32_t)(uintptr_t)trace_system_metrics;
    *(uint32_t *)0x4b1760=(uint32_t)(uintptr_t)trace_move;
    *(uint32_t *)0x4b1764=(uint32_t)(uintptr_t)trace_line;
    *(uint32_t *)0x4b1bb4=(uint32_t)(uintptr_t)trace_beep;
    gdi_bound=1;
}
static void reset_gdi_trace(void) {
    gdi_event_bytes=0;gdi_position.x=0;gdi_position.y=0;
    gdi_text_color=0;gdi_background_color=0xffffff;gdi_background_mode=2;
    gdi_pixel_cursor=0;
    gdi_tick_calls=0;
}

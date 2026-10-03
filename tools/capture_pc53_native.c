/* Separate current-hardware evidence for the intact program's startup CW027f.
 * Fixed arithmetic constructions, original constant bytes supplied as hex.
 * No application instructions are replaced by this standalone probe. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
typedef struct { uint8_t bytes[10]; } raw80;
static void prepare(void) {
    const uint16_t cw=0x027f;
    __asm__ volatile("fninit\n\tfldcw %0" : : "m"(cw) : "st");
}
static int parse(const char *hex,double *out) {
    if(strlen(hex)!=16)return 0;
    for(unsigned i=0;i<8;i++){unsigned byte;if(sscanf(hex+2*i,"%2x",&byte)!=1)return 0;((uint8_t*)out)[i]=byte;}
    return 1;
}
static void print(const void *bytes,unsigned width) {
    for(unsigned i=0;i<width;i++)printf("%02x",((const uint8_t*)bytes)[i]);
}
int main(void) {
    char mode[16],factor_hex[20],scale_hex[20],kind_hex[20];
    int32_t angle,force,sport,kind;
    double factor,scale,offset,stored;
    raw80 input,sine,cosine;
    while(scanf("%15s",mode)==1) {
        prepare();
        if(!strcmp(mode,"force")) {
            if(scanf("%" SCNd32 " %" SCNd32 " %" SCNd32 " %" SCNd32 " %19s %19s %19s",&angle,&force,&sport,&kind,factor_hex,scale_hex,kind_hex)!=7 ||
               !parse(factor_hex,&factor)||!parse(scale_hex,&scale)||!parse(kind_hex,&offset))return 2;
            __asm__ volatile("fildl %0" : : "m"(angle) : "st");
            if(sport)__asm__ volatile("fsubl %0" : : "m"(scale) : "st");
            if(kind)__asm__ volatile("fsubl %0" : : "m"(offset) : "st");
            __asm__ volatile("fildl %2\n\tfaddp\n\tfmull %3\n\tfld %%st(0)\n\tfstpt %0\n\tfsin\n\tfstpt %1"
                : "=m"(input),"=m"(sine) : "m"(force),"m"(factor) : "st","st(1)");
            print(&input,10);putchar(' ');print(&sine,10);putchar('\n');continue;
        }
        if(scanf("%" SCNd32 " %19s %19s",&angle,factor_hex,scale_hex)!=3 ||
           !parse(factor_hex,&factor)||!parse(scale_hex,&scale))return 2;
        if(!strcmp(mode,"stored")) {
            __asm__ volatile("fildl %1\n\tfmull %2\n\tfstpl %0"
                : "=m"(stored) : "m"(angle),"m"(factor) : "st");
            __asm__ volatile("fldl %2\n\tfsin\n\tfstpt %0\n\tfldl %2\n\tfcos\n\tfstpt %1"
                : "=m"(sine),"=m"(cosine) : "m"(stored) : "st");
        } else if(!strcmp(mode,"raw")) {
            __asm__ volatile("fildl %2\n\tfsin\n\tfstpt %0\n\tfildl %2\n\tfcos\n\tfstpt %1"
                : "=m"(sine),"=m"(cosine) : "m"(angle) : "st");
        } else if(!strcmp(mode,"scaled")||!strcmp(mode,"extended")) {
            __asm__ volatile("fildl %0" : : "m"(angle) : "st");
            if(!strcmp(mode,"scaled"))__asm__ volatile("fmull %0" : : "m"(scale) : "st");
            __asm__ volatile("fmull %2\n\tfld %%st(0)\n\tfsin\n\tfstpt %0\n\tfcos\n\tfstpt %1"
                : "=m"(sine),"=m"(cosine) : "m"(factor) : "st","st(1)");
        } else return 2;
        print(&sine,10);putchar(' ');print(&cosine,10);putchar('\n');
    }
    return ferror(stdin)?2:0;
}

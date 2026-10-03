/* Original 0x42964c integer lever/force with conditional binary64 offsets. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef struct { uint8_t bytes[10]; } raw80;
static int parse(const char *hex, double *value) {
    if (strlen(hex) != 16) return 0;
    for (unsigned i=0;i<8;i++) { unsigned b; if(sscanf(hex+i*2,"%2x",&b)!=1)return 0; ((uint8_t*)value)[i]=b; }
    return 1;
}
static void hex(raw80 value) { for(unsigned i=0;i<10;i++)printf("%02x",value.bytes[i]); }
int main(void) {
    int32_t lever,force;
    int sport,kind;
    char f[20],s[20],k[20];
    double factor,sport_offset,class_offset;
    const uint16_t cw=0x037f;
    while(scanf("%d %d %d %d %19s %19s %19s",&lever,&force,&sport,&kind,f,s,k)==7) {
        raw80 radians,sine;
        if(!parse(f,&factor)||!parse(s,&sport_offset)||!parse(k,&class_offset))return 2;
        __asm__ volatile("fninit\n\tfldcw %0\n\tfildl %1" : : "m"(cw),"m"(lever) : "st");
        if(sport) __asm__ volatile("fsubl %0" : : "m"(sport_offset) : "st");
        if(kind) __asm__ volatile("fsubl %0" : : "m"(class_offset) : "st");
        __asm__ volatile("fildl %0\n\tfaddp\n\tfmull %1\n\tfld %%st(0)" : : "m"(force),"m"(factor) : "st","st(1)");
        /* FST m80 only has a popping encoding, so duplicate before storing. */
        __asm__ volatile("fstpt %0\n\tfsin\n\tfstpt %1" : "=m"(radians),"=m"(sine) : : "st");
        hex(radians);putchar(' ');hex(sine);putchar('\n');
    }
    return ferror(stdin)?2:0;
}

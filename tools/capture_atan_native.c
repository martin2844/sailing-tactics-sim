/* Native FPATAN evidence; inputs/output are explicit m80 byte images. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef struct { uint8_t bytes[10]; } raw80;
static int parse(const char *hex,raw80 *value) {
    if(strlen(hex)!=20)return 0;
    for(unsigned i=0;i<10;i++){unsigned b;if(sscanf(hex+i*2,"%2x",&b)!=1)return 0;value->bytes[i]=b;}
    return 1;
}
int main(void) {
    char y_hex[24],x_hex[24]; const uint16_t cw=0x037f;
    while(scanf("%23s %23s",y_hex,x_hex)==2) {
        raw80 y,x,result;double stored;
        if(!parse(y_hex,&y)||!parse(x_hex,&x))return 2;
        __asm__ volatile("fninit\n\tfldcw %4\n\tfldt %2\n\tfldt %3\n\tfpatan\n\tfstl %1\n\tfstpt %0"
            : "=m"(result),"=m"(stored) : "m"(y),"m"(x),"m"(cw) : "st","st(1)");
        for(unsigned i=0;i<10;i++) { printf("%02x",result.bytes[i]); }
        putchar(' ');
        for(unsigned i=0;i<8;i++) { printf("%02x",((uint8_t*)&stored)[i]); }
        putchar('\n');
    }
    return ferror(stdin)?2:0;
}

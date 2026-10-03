/* Native FSIN/FCOS input and result evidence for continuous rendering phases. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef struct { uint8_t bytes[10]; } raw80;
static int parse(const char *hex,raw80 *value) {
    if(strlen(hex)!=20)return 0;
    for(unsigned i=0;i<10;i++){unsigned b;if(sscanf(hex+i*2,"%2x",&b)!=1)return 0;value->bytes[i]=b;}
    return 1;
}
static void print(const void *value,unsigned size) {
    for(unsigned i=0;i<size;i++){printf("%02x",((const uint8_t*)value)[i]);}
}
int main(void) {
    char input_hex[24];const uint16_t cw=0x037f;
    while(scanf("%23s",input_hex)==1) {
        raw80 input,sine,cosine;double sine_stored,cosine_stored;
        if(!parse(input_hex,&input))return 2;
        __asm__ volatile("fninit\n\tfldcw %5\n\tfldt %4\n\tfsin\n\tfstl %2\n\tfstpt %0\n\tfldt %4\n\tfcos\n\tfstl %3\n\tfstpt %1"
            : "=m"(sine),"=m"(cosine),"=m"(sine_stored),"=m"(cosine_stored) : "m"(input),"m"(cw) : "st");
        print(&sine,10);putchar(' ');print(&cosine,10);putchar(' ');
        print(&sine_stored,8);putchar(' ');print(&cosine_stored,8);putchar('\n');
    }
    return ferror(stdin)?2:0;
}

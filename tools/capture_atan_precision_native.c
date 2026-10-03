/* Precision-control independence of the actual FPATAN instruction. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef struct{uint8_t bytes[10];} raw80;
static int parse(const char *hex,raw80 *value){
    if(strlen(hex)!=20)return 0;
    for(unsigned n=0;n<10;n++){unsigned b;if(sscanf(hex+2*n,"%2x",&b)!=1)return 0;value->bytes[n]=b;}
    return 1;
}
int main(void){
    unsigned word;char first[24],second[24];
    while(scanf("%x %23s %23s",&word,first,second)==3){
        raw80 y,x,result;double stored;uint16_t control=(uint16_t)word;
        if(!parse(first,&y)||!parse(second,&x))return 2;
        __asm__ volatile("fninit\n\tfldcw %4\n\tfldt %2\n\tfldt %3\n\tfpatan\n\tfstl %1\n\tfstpt %0"
            :"=m"(result),"=m"(stored):"m"(y),"m"(x),"m"(control):"st","st(1)");
        for(unsigned n=0;n<10;n++)printf("%02x",result.bytes[n]);putchar(' ');
        for(unsigned n=0;n<8;n++)printf("%02x",((uint8_t*)&stored)[n]);putchar('\n');
    }
    return ferror(stdin)?2:0;
}

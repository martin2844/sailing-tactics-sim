/* Actual x87 arithmetic with an explicitly selected precision-control word.
 * Operand loads remain m80; only arithmetic instructions obey PC. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef struct{uint8_t bytes[10];} raw80;
static int parse(const char *text,raw80 *value){
    if(strlen(text)!=20)return 0;
    for(unsigned n=0;n<10;n++){unsigned byte;if(sscanf(text+2*n,"%2x",&byte)!=1)return 0;value->bytes[n]=byte;}
    return 1;
}
static void print(const void *value,unsigned count){for(unsigned n=0;n<count;n++)printf("%02x",((const uint8_t*)value)[n]);}
#define BINARY(opcode) __asm__ volatile("fldt %2\n\tfldt %3\n\t.byte " opcode "\n\tfstl %1\n\tfstpt %0" : "=m"(result),"=m"(stored):"m"(left),"m"(right):"st","st(1)")
int main(void){
    unsigned word;char operation[16],first[24],second[24];
    while(scanf("%x %15s %23s %23s",&word,operation,first,second)==4){
        raw80 left,right,result;double stored;uint16_t control=(uint16_t)word;
        if(!parse(first,&left)||!parse(second,&right)||(control&0xc00))return 2;
        __asm__ volatile("fninit\n\tfldcw %0"::"m"(control):"st");
        if(!strcmp(operation,"add")){BINARY("0xde,0xc1");}
        else if(!strcmp(operation,"subtract")){BINARY("0xde,0xe9");}
        else if(!strcmp(operation,"multiply")){BINARY("0xde,0xc9");}
        else if(!strcmp(operation,"divide")){BINARY("0xde,0xf9");}
        else if(!strcmp(operation,"sqrt")){
            __asm__ volatile("fldt %2\n\tfsqrt\n\tfstl %1\n\tfstpt %0":"=m"(result),"=m"(stored):"m"(left):"st");
        }else return 2;
        print(&result,10);putchar(' ');print(&stored,8);putchar('\n');
    }
    return ferror(stdin)?2:0;
}

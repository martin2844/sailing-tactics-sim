/* Bounded native x87 probe for 0x465f39..0x465f52 and __ftol 0x49b970.
 * IMUL/ADD keep the low signed DWORD. FSQRT's masked invalid result is
 * converted using FISTP QWORD; the caller only stores EAX (low DWORD).
 * Run: cc native-chart-x87.c -o /tmp/tact-chart-x87 && /tmp/tact-chart-x87
 */
#include <stdint.h>
#include <stdio.h>
static int64_t native_conversion(int32_t input) {
  int64_t output; unsigned short oldcw,cw;
  __asm__ volatile("fnstcw %0":"=m"(oldcw));
  cw=oldcw|0x0c01; /* truncate, mask invalid as the application's CRT does */
  __asm__ volatile("fldcw %2; fildl %1; fsqrt; fistpq %0; fldcw %3"
    :"=m"(output):"m"(input),"m"(cw),"m"(oldcw):"st");
  return output;
}
int main(void) {
  const int32_t inputs[]={0,25,2147395600,-2147483647,-1};
  const uint32_t expected[]={0,5,46340,0,0};
  for(unsigned n=0;n<5;n++){
    int64_t result=native_conversion(inputs[n]);
    printf("%d -> %lld -> low DWORD %u\n",inputs[n],(long long)result,(uint32_t)result);
    if((uint32_t)result!=expected[n])return 1;
  }
  return 0;
}

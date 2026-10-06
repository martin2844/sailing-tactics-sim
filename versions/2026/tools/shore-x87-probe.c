// Execute the original FDIV -> stored double -> FMUL -> __ftol sequence.
#include <inttypes.h>
#include <stdio.h>
static void probe(double numerator, double denominator, double multiplier) {
  const unsigned short nearest53=0x027f, truncate53=0x0e7f;
  double slope;
  uint64_t result;
  unsigned short status;
  __asm__ volatile(
    "fninit\n\tfldcw %[nearest]\n\tfldl %[numerator]\n\t"
    "fdivl %[denominator]\n\tfstpl %[slope]\n\tfldl %[multiplier]\n\t"
    "fmull %[slope]\n\tfldcw %[truncate]\n\tfistpq %[result]\n\t"
    "fnstsw %[status]\n\tfninit"
    : [slope] "=m" (slope), [result] "=m" (result), [status] "=m" (status)
    : [nearest] "m" (nearest53), [truncate] "m" (truncate53),
      [numerator] "m" (numerator), [denominator] "m" (denominator),
      [multiplier] "m" (multiplier)
    : "st", "memory");
  printf("{\"numerator\":%.0f,\"denominator\":%.0f,\"multiplier\":%.0f,"
         "\"result\":\"%016" PRIx64 "\",\"lowDWORD\":%" PRIu32 ",\"status\":%u}",
         numerator,denominator,multiplier,result,(uint32_t)result,status);
}
int main(void) {
  printf("[");probe(0,0,0);printf(",");probe(40,0,0);printf(",");
  probe(-40,0,0);printf(",");probe(40,100,50);printf("]\n");
  return 0;
}

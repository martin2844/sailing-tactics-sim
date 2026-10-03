/* Two original x87 angle construction paths, precision64/nearest-even. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#if !defined(__i386__) && !defined(__x86_64__)
#error This reference capture needs native x87 instructions
#endif
typedef struct { uint8_t bytes[10]; } raw80;
static void prepare(void) {
    const uint16_t cw = 0x037f;
    __asm__ volatile("fninit\n\tfldcw %0" : : "m"(cw) : "st");
}
static int parse(const char *hex, double *value) {
    if (strlen(hex) != 16) return 0;
    for (unsigned i = 0; i < 8; i++) {
        unsigned byte;
        if (sscanf(hex + i * 2, "%2x", &byte) != 1) return 0;
        ((uint8_t *)value)[i] = byte;
    }
    return 1;
}
static void print80(raw80 value) {
    for (unsigned i = 0; i < 10; i++) printf("%02x", value.bytes[i]);
}
int main(void) {
    int32_t angle;
    char mode[16], factor_hex[20], scale_hex[20];
    while (scanf("%15s %" SCNd32 " %19s %19s", mode, &angle, factor_hex, scale_hex) == 4) {
        double factor, scale, stored;
        raw80 sine, cosine;
        if (!parse(factor_hex, &factor) || !parse(scale_hex, &scale)) return 2;
        if (!strcmp(mode, "stored")) {
            prepare();
            __asm__ volatile("fildl %1\n\tfmull %2\n\tfstpl %0"
                : "=m"(stored) : "m"(angle), "m"(factor) : "st");
            __asm__ volatile("fldl %2\n\tfsin\n\tfstpt %0\n\tfldl %2\n\tfcos\n\tfstpt %1"
                : "=m"(sine), "=m"(cosine) : "m"(stored) : "st");
        } else if (!strcmp(mode, "raw")) {
            prepare();
            __asm__ volatile("fildl %2\n\tfsin\n\tfstpt %0\n\tfildl %2\n\tfcos\n\tfstpt %1"
                : "=m"(sine), "=m"(cosine) : "m"(angle) : "st");
        } else if (!strcmp(mode, "scaled")) {
            prepare();
            __asm__ volatile("fildl %2\n\tfmull %3\n\tfmull %4\n\tfld %%st(0)\n\tfsin\n\tfstpt %0\n\tfcos\n\tfstpt %1"
                : "=m"(sine), "=m"(cosine) : "m"(angle), "m"(scale), "m"(factor) : "st", "st(1)");
        } else return 2;
        print80(sine); putchar(' '); print80(cosine); putchar('\n');
    }
    return ferror(stdin) ? 2 : 0;
}

/* Native x87 probes. All arithmetic uses the supplied x87 instructions, with
 * precision64 / nearest-even (control word 0x037f), independent of C FP math.
 * This is current-machine reference evidence, not historical-CPU equivalence.
 */
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#if !defined(__i386__) && !defined(__x86_64__)
#error Native x87 probes require an x86 host
#endif
#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error Native probe byte images require a little-endian host
#endif

typedef struct { uint8_t bytes[10]; } raw80;

static void prepare(void) {
    const uint16_t control = 0x037f;
    __asm__ volatile("fninit\n\tfldcw %0" : : "m"(control) : "st");
}

static int parse_hex(const char *text, void *output, size_t size) {
    if (strlen(text) != size * 2) return 0;
    uint8_t *bytes = output;
    for (size_t i = 0; i < size; i++) {
        unsigned value;
        if (sscanf(text + i * 2, "%2x", &value) != 1) return 0;
        bytes[i] = (uint8_t)value;
    }
    return 1;
}

static void print_hex(const void *value, size_t size) {
    const uint8_t *bytes = value;
    for (size_t i = 0; i < size; i++) printf("%02x", bytes[i]);
}

#define BINARY(opcode) __asm__ volatile( \
    "fldt %2\n\tfldt %3\n\t.byte " opcode "\n\tfstl %1\n\tfstpt %0" \
    : "=m"(result), "=m"(stored) : "m"(left), "m"(right) : "st", "st(1)")

int main(void) {
    char operation[16], first[32], second[32];
    while (scanf("%15s", operation) == 1) {
        raw80 left, right, result;
        double stored;
        prepare();
        if (!strcmp(operation, "trig")) {
            int32_t angle;
            double factor;
            if (scanf("%" SCNd32 " %31s", &angle, first) != 2 || !parse_hex(first, &factor, 8)) return 2;
            __asm__ volatile("fildl %1\n\tfldl %2\n\t.byte 0xde,0xc9\n\t.byte 0xd9,0xfe\n\tfstpt %0"
                : "=m"(result) : "m"(angle), "m"(factor) : "st", "st(1)");
            print_hex(&result, 10); printf(" ");
            prepare();
            __asm__ volatile("fildl %1\n\tfldl %2\n\t.byte 0xde,0xc9\n\t.byte 0xd9,0xff\n\tfstpt %0"
                : "=m"(result) : "m"(angle), "m"(factor) : "st", "st(1)");
            print_hex(&result, 10); printf("\n");
            continue;
        }
        if (!strcmp(operation, "calibration")) {
            int32_t length, fifteen = 15;
            if (scanf("%" SCNd32, &length) != 1) return 2;
            __asm__ volatile("fildl %2\n\tfildl %3\n\t.byte 0xde,0xf9\n\t.byte 0xd9,0xfa\n\tfstl %1\n\tfstpt %0"
                : "=m"(result), "=m"(stored) : "m"(fifteen), "m"(length) : "st", "st(1)");
        } else {
            if (scanf("%31s", first) != 1 || !parse_hex(first, &left, 10)) return 2;
            if (!strcmp(operation, "ftol")) {
                int64_t integer;
                const uint16_t truncation_control = 0x0f7f, normal_control = 0x037f;
                __asm__ volatile("fldt %1\n\tfldcw %2\n\tfistpq %0\n\tfldcw %3"
                    : "=m"(integer) : "m"(left), "m"(truncation_control), "m"(normal_control) : "st");
                printf("%" PRId64 " %" PRId32 "\n", integer, (int32_t)(uint32_t)integer);
                continue;
            }
            if (!strcmp(operation, "sqrt")) {
                __asm__ volatile("fldt %2\n\t.byte 0xd9,0xfa\n\tfstl %1\n\tfstpt %0"
                    : "=m"(result), "=m"(stored) : "m"(left) : "st");
            } else {
                if (scanf("%31s", second) != 1 || !parse_hex(second, &right, 10)) return 2;
                if (!strcmp(operation, "add")) { BINARY("0xde,0xc1"); }
                else if (!strcmp(operation, "subtract")) { BINARY("0xde,0xe9"); }
                else if (!strcmp(operation, "multiply")) { BINARY("0xde,0xc9"); }
                else if (!strcmp(operation, "divide")) { BINARY("0xde,0xf9"); }
                else return 2;
            }
        }
        print_hex(&result, 10); printf(" "); print_hex(&stored, 8); printf("\n");
    }
    return ferror(stdin) ? 2 : 0;
}

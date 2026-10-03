/* Generated from capture_encounter_fixtures.py: fixed 2002 leaves. */
#define ENCOUNTER_GLOBAL_COUNT 22
#define ENCOUNTER_INDEXED_COUNT 10
#define ENCOUNTER_ROUTINE_COUNT 7
static const uint32_t encounter_globals[ENCOUNTER_GLOBAL_COUNT] = {0x49118c,0x491140,0x4911cc,0x4a5b80,0x4aa594,0x4aa59c,0x4a70f8,0x4a72c8,0x4aa294,0x4aa388,0x4aa38c,0x4aa588,0x4aa288,0x4aa384,0x4aa998,0x4a4be0,0x4a4f84,0x4ac9c0,0x4ac1d4,0x491194,0x4ac9a8,0x4a4eb0};
static const uint32_t encounter_indexed[ENCOUNTER_INDEXED_COUNT] = {0x4a5420,0x4a4888,0x4a6f48,0x4ac018,0x4aa730,0x4aa5b0,0x4a7bc8,0x4a5f10,0x4a49e8,0x4a4ae0};
static const uint8_t encounter_widths[ENCOUNTER_INDEXED_COUNT] = {4,4,4,4,4,4,4,4,8,8};
static const uintptr_t encounter_routines[ENCOUNTER_ROUTINE_COUNT] = {0x421c40,0x428af0,0x44da90,0x42a8a0,0x42a950,0x42abb0,0x426f50};
static const uint8_t encounter_argument_counts[ENCOUNTER_ROUTINE_COUNT] = {1,3,2,1,1,2,1};
/* 0=I32/residual EAX, 1=I64 EDX:EAX, 2=ST0 m80, 3=void */
static const uint8_t encounter_return_kinds[ENCOUNTER_ROUTINE_COUNT] = {0,1,1,0,0,0,2};

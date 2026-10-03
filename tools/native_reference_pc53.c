/* Separate original-application precision mode. The default reference runner
 * remains precision64; this executable always declares precision53 in hello. */
#define TACT_X87_CONTROL_WORD 0x027f
#include "native_reference_2002.c"

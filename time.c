#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint64_t Duration;

const Duration NANO_SECOND = 1;
const Duration MICRO_SECOND = 1000 * NANO_SECOND;
const Duration MILLI_SECOND = 1000 * MICRO_SECOND;
const Duration SECOND = 1000 * MILLI_SECOND;
const Duration MINUTE = 60 * SECOND;
const Duration HOUR = 60 * MINUTE;

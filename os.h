

#ifndef OS_H
#define OS_H

#if defined(_WIN32)

static const char *OS = "windows";

#elif defined(__linux__)

static const char *OS = "linux";

#elif defined(__APPLE__)

static const OS = "apple";

#else

static const OS = "unknow";

#endif

#if defined(__x86_64__) || defined(_M_X64)

static const char *ARCH = "x86_64";

#elif defined(__i386__) || defined(_M_IX86)

static const char *ARCH = "x86";

#elif defined(__aarch64__) || defined(_M_ARM64)

static const char *ARCH = "arm64";

#elif defined(__arm__) || defined(_M_ARM)

static const char *ARCH = "arm";

#else

static const char *ARCH = "unknown";

#endif

#endif

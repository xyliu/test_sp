#ifndef _LIBS_CUTILS_LOG_H
#define _LIBS_CUTILS_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#define CONDITION(cond)     (__builtin_expect((cond)!=0, 0))

#ifndef ALOG_ASSERT
#define ALOG_ASSERT(cond, ...)  ((void)0)
#endif

#ifndef ALOG
#define ALOG printf
#endif

#ifndef ALOGE
#define ALOGE ALOG
#endif

#ifndef ALOGD
#define ALOGD ALOG
#endif

#ifndef LOG_ALWAYS_FATAL
#define LOG_ALWAYS_FATAL ALOG
#endif

#ifdef __cplusplus
}
#endif

#endif

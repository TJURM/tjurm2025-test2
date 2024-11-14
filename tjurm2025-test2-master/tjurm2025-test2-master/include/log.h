/*
 * Created by lxq, 2021-7-23
 */

#ifndef __LOG_H__
#define __LOG_H__

#include <cstdio>

/* Define log level
 * 0: None
 * 1: Error, output error log (red) and variable log (white)
 * 2: Warning, output both error (red), variable (white), and warning log (yellow)
 * 3: Message, output all kinds of log for debug
 */
#define LOG_LEVEL 3

/* log apis */
#define LOG_ERROR(format, ...)         __LOG_ERROR__(format, ##__VA_ARGS__)
#define LOG_WARN(format, ...)          __LOG_WARN__(format, ##__VA_ARGS__)
#define LOG_MSG(format, ...)           __LOG_MSG__(format, ##__VA_ARGS__)
#define LOG_VAR(var_name, format, ...) __LOG_VAR__(var_name, format, ##__VA_ARGS__)


/* =========================== Log implementation ========================== */

/* utils */
#define __LOCATION__            "At " __FILE__ ":" "%d "
#define __OUTPUT__(format, ...) fprintf(stdout, format, ##__VA_ARGS__)

/* log levels */
#define __NONE__    0
#define __ERROR__   1
#define __WARN__    2
#define __MSG__     3

/* check whether log level is valid */
#if LOG_LEVEL < __NONE__
    #pragma message ( \
        "[Warning from log.h]: Detect log level < 0, set log level to 0 (None)" \
    )
    #undef LOG_LEVEL
    #define LOG_LEVEL __NONE__
#elif LOG_LEVEL > __MSG__
    #pragma message ( \
        "[Warning from log.h]: Detect log level > 3, set log level to 3 (Message)" \
    )
    #undef LOG_LEVEL
    #define LOG_LEVEL __MSG__
#endif

#if LOG_LEVEL == __NONE__
    #define __LOG_LEVEL__ __NONE__
#elif LOG_LEVEL == __ERROR__
    #define __LOG_LEVEL__ __ERROR__
#elif LOG_LEVEL == __WARN__
    #define __LOG_LEVEL__ __WARN__
#else
    #define __LOG_LEVEL__ __MSG__
#endif

/* output string format
 * [file] [line] [color] [log type] [origin format string] [\n+]
 */
#define __TO_ERROR__(format) \
    "\033[1;31m" "[Error]  " "\033[0m: " format "\n"

#define __TO_WARN__(format) \
    "\033[1;33m" "[Warning]" "\033[0m: " format "\n"

#define __TO_MSG__(format) \
    "\033[1;34m" "[Message]" "\033[0m: " format "\n"

#define __TO_VAR__(var_name, format) \
    "\033[1;37m" "[Var: " var_name "]" "\033[0m: " format "\n"

/* log error */
#if __LOG_LEVEL__ >= __ERROR__
    #define __LOG_ERROR__(format, ...) \
            __OUTPUT__(__TO_ERROR__(format), ##__VA_ARGS__)
#else
    #define __LOG_ERROR__(format, ...) ((void)0)
#endif

/* log warning */
#if __LOG_LEVEL__ >= __WARN__
    #define __LOG_WARN__(format, ...) \
            __OUTPUT__(__TO_WARN__(format), ##__VA_ARGS__)
#else
    #define __LOG_WARN__(format, ...) ((void)0)
#endif

/* log message */
#if __LOG_LEVEL__ >= __MSG__
    #define __LOG_MSG__(format, ...) \
            __OUTPUT__(__TO_MSG__(format), ##__VA_ARGS__)
#else
    #define __LOG_MSG__(format, ...) ((void)0)
#endif

/* log variable */
#if __LOG_LEVEL__ >= __ERROR__
    #define __LOG_VAR__(var_name, format, ...) \
            __OUTPUT__(__TO_VAR__(var_name, format), ##__VA_ARGS__)
#else
    #define __LOG_VAR__(var_name, format, ...) ((void)0)
#endif

#endif

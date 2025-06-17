/*
 * File: log.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Provides a template to build C programs.
 *
 */

#ifndef __LOG_H__
#define __LOG_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <assert.h> // assert
#include <ctype.h>
#include <limits.h>  // INT_MAX, INT_MIN
#include <stdarg.h>  // va_args, va_end, va_start, va_list
#include <stdbool.h> // bool, true, false
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>  // printf, puts
#include <stdlib.h> // malloc, realloc, calloc, free
#include <string.h> // strlen, memcpy, strcpy
#include <time.h>   // time

enum log_level {
    INFO = 0,
    DEBUG = 1,
    TRACE = 2,
    WARNING = 3,
    ERROR = 4,
    FATAL = 5
};

void log_start(const char *file);
void log_end();

void set_log_level(enum log_level level);
void log_message(enum log_level level, const char *file, unsigned int line,
                 const char *function, const char *format, ...);

#define INFO(format, ...)                                                      \
    log_message(INFO, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define DEBUG(format, ...)                                                     \
    log_message(DEBUG, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define TRACE(format, ...)                                                     \
    log_message(TRACE, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define WARNING(format, ...)                                                   \
    log_message(WARNING, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define ERROR(format, ...)                                                     \
    log_message(ERROR, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define FATAL(format, ...)                                                     \
    log_message(FATAL, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __LOG_H__

/*
 * File: log.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Program implementation.
 *
 */

#include "log.h"
// #include "libs/aec.h"

static FILE *log_file = NULL;

static enum log_level current_log_level = INFO;

void log_start(const char *file) {
    if (file) {
        log_file = fopen(file, "a");
        if (!log_file) {
            fprintf(stderr, "Failed to open log file: %s\n", file);
            exit(EXIT_FAILURE);
        }
    } else {
        log_file = stdout; // default to standard output
    }
}

void log_end(void) {
    if (log_file && log_file != stdout) {
        fclose(log_file);
        log_file = NULL;
    }
}

void set_log_level(enum log_level level) { current_log_level = level; }

void log_message(enum log_level level, const char *file, unsigned int line,
                 const char *function, const char *format, ...) {

    if (!log_file) {
        fprintf(stderr, "Logging not initialized.\n");
        return;
    }
    time_t now;
    char *time_str;
    now = time(NULL);
    time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';

    const char *level_strings[] = {
        [INFO] = "[INFO]",       [DEBUG] = "[DEBUG]", [TRACE] = "[TRACE]",
        [WARNING] = "[WARNING]", [ERROR] = "[ERROR]", [FATAL] = "[FATAL]"};

    fprintf(log_file, "%s [%s:%d %s()] %s ", time_str, file, line, function,
            level_strings[level]);

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    fprintf(log_file, "\n");

    fflush(log_file); // write the message immediately
}

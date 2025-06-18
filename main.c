/*
 * File: main.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Entry point to the program.
 *
 */

#include "log.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    log_start(NULL);

    INFO("Hello, World!");

    log_end();

    return 0;
}

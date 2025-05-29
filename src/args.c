#include "args.h"
#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void args_checker(int argc, char *argv[], int *lineNumbering, int *binaryMode, char **filename)
{
    if (argc < 2 || argc > 3) {
        const char *msg = "Usage: mini-cat [-n] [-b|--binary] <file>\n";
        write(STDERR_FILENO, msg, strlen(msg));
        exit(EXIT_FAILURE);
    }

    *lineNumbering = 0;
    *binaryMode    = 0;
    *filename      = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            *lineNumbering = 1;
        }
        else if (strcmp(argv[i], "-b") == 0
              || strcmp(argv[i], "--binary") == 0) {
            *binaryMode = 1;
        }
        else if (argv[i][0] != '-') {
            if (*filename) {
                const char *err = "Error: multiple filenames\n";
                write(STDERR_FILENO, err, strlen(err));
                exit(EXIT_FAILURE);
            }
            *filename = argv[i];
        }
        else {
            dprintf(STDERR_FILENO,
                "Error: unknown option '%s'\n", argv[i]);
            exit(EXIT_FAILURE);
        }
    }

    if (!*filename) {
        const char *err = "Error: no input file specified\n";
        write(STDERR_FILENO, err, strlen(err));
        exit(EXIT_FAILURE);
    }
}

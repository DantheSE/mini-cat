#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "args.h"
#include "reader.h"

int main(int argc, char *argv[]) {
    int lineNumbering, binaryMode;
    char *filename;

    args_checker(argc, argv, &lineNumbering, &binaryMode, &filename);

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    dump_with_line_numbers(fd, lineNumbering);
    close(fd);
    return EXIT_SUCCESS;
}

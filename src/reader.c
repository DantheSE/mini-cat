#include "reader.h"
#include "utils.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define BUFSIZE 1024

void dump_with_line_numbers(int fd, int number_lines) {
    char buf[BUFSIZE];
    ssize_t bytes_read;
    int line_num = 1;
    int at_line_start = 1;

    while ((bytes_read = read(fd, buf, BUFSIZE)) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (number_lines && at_line_start) {
                char numbuf[16];
                numToString(line_num++, numbuf);
                write(STDOUT_FILENO, numbuf, strlen(numbuf));
                write(STDOUT_FILENO, "\t", 1);
                at_line_start = 0;
            }
            if (write(STDOUT_FILENO, &buf[i], 1) != 1) {
                perror("write");
                return;
            }
            if (buf[i] == '\n') {
                at_line_start = 1;
            }
        }
    }
    if (bytes_read < 0) {
        perror("read");
    }
}

#include "utils.h"

char *numToString(int num, char *buf) {
    int len = 0;
    if (num == 0) {
        buf[len++] = '0';
        buf[len]   = '\0';
        return buf;
    }
    int tmp = num;
    while (tmp) {
        tmp /= 10;
        len++;
    }
    buf[len] = '\0';
    while (num) {
        buf[--len] = '0' + (num % 10);
        num /= 10;
    }
    return buf;
}

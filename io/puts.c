// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <unistd.h>

int puts(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        char c = str[len];
        write(1, &c, 1);
        len++;
    }
    char newline = '\n';
    write(1, &newline, 1);
    return len + 1;
}

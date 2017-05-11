#include "vmware.h"
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>

char * read_stdin() {
    size_t buffer_size = 256;
    size_t left = buffer_size;
    char * buffer = malloc(left);
    size_t read;
    size_t offset = 0;

    if (buffer == NULL) {
		err(1, "malloc");
        return NULL;
    }
    
    while (1) {
        read = fread(buffer + offset, 1, left, stdin);
        if (read < left && feof(stdin)) {
            break;
        }
        left -= read;
        offset += read;

        if (left == 0) {
            left = buffer_size;
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);

            if (buffer == NULL) {
                err(1, "malloc");
                return NULL;
            }
        }
    }
    return buffer;
}

int main(int argc, char ** argv) {
    char * to_write = read_stdin();
    if (to_write) {
        vmware_set_clipboard(to_write);
        free(to_write);
    }
}

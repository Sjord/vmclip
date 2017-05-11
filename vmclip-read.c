#include "vmware.h"
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>

int main() {
    char * cb_contents;
    if (vmware_get_clipboard(&cb_contents)) {
        printf("%s", cb_contents);
        free(cb_contents);
    }
}

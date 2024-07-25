#include "gluegl_util.h"

#include <stdio.h>
#include <stdlib.h>

void gluegl_util_read_file(const char *path, char *buffer) {
    FILE *handle = fopen(path, "r");
    if (!handle) {
        fprintf(stderr, "gluegl: Failed to open file \"%s\"\n", path);
        exit(1);
    }

    fseek(handle, 0L, SEEK_END);
    long size = ftell(handle);
    rewind(handle);

    if (!fread(buffer, size, 1, handle)) {
        fprintf(stderr, "gluegl: Failed to read file \"%s\"\n", path);
        exit(1);
    }

    buffer[size] = '\0';

    fclose(handle);
}
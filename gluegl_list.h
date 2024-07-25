/**
 * A basic O(1) indexed stack allocated void* list
 */

#ifndef GLUEGL_GLUEGL_LIST_H
#define GLUEGL_GLUEGL_LIST_H

#include <stdint.h>

#define MAX_ELEMENT_COUNT 512

typedef struct {
    size_t element_count;
    void *elements[512];
} gluegl_list_t;

gluegl_list_t *gluegl_list_create();

void gluegl_list_append(gluegl_list_t *list, void *element);
void gluegl_list_free(gluegl_list_t *list, void (*element_free)(void *element));

#endif //GLUEGL_GLUEGL_LIST_H

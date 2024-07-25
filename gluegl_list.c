#include "gluegl_list.h"

#include <malloc.h>
#include <stdio.h>

gluegl_list_t *gluegl_list_create() {
    gluegl_list_t *list = malloc(sizeof(gluegl_list_t));

    if (list) {
        list->element_count = 0;
    }

    return list;
}

void gluegl_list_append(gluegl_list_t *list, void *element) {
    if (!list || !element) {
        fprintf(stderr, "gluegl: Either list is null or element is null\n");
        return;
    }

    if (list->element_count >= MAX_ELEMENT_COUNT) {
        fprintf(stderr, "gluegl: Reached maximum list size. Not appending.\n");
        return;
    }

    list->elements[list->element_count] = element;
    list->element_count++;
}

void gluegl_list_free(gluegl_list_t *list, void (*element_free)(void *element)) {
    if (!list || !element_free)
        return;

    size_t i;
    for (i = 0; i < list->element_count; i++) {
        element_free(list->elements[i]);
    }

    free(list);
}

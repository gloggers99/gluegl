#include "gluegl_shader.h"

#include "gluegl_util.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>

gluegl_shader_t *gluegl_shader_load_files(const char *vertex_shader_path, const char *fragment_shader_path) {
    char vertex_shader_file_buffer[5120];
    char fragment_shader_file_buffer[5120];

    gluegl_util_read_file(vertex_shader_path, vertex_shader_file_buffer);
    gluegl_util_read_file(fragment_shader_path, fragment_shader_file_buffer);

    return gluegl_shader_load(vertex_shader_file_buffer, fragment_shader_file_buffer);
}

gluegl_shader_t *gluegl_shader_load(char *vertex_shader_source, char *fragment_shader_source) {
    gluegl_shader_t *shader = malloc(sizeof(gluegl_shader_t));

    shader->vertex_shader_source = strdup(vertex_shader_source);
    shader->fragment_shader_source = strdup(fragment_shader_source);

    return shader;
}

void gluegl_shader_free(gluegl_shader_t *shader) {
    if (!shader)
        return;

    if (shader->name)
        free(shader->name);

    if (shader->vertex_shader_source)
        free(shader->vertex_shader_source);

    if (shader->fragment_shader_source)
        free(shader->fragment_shader_source);

    free(shader);
}

/* this is some preprocessor black magic */
void __gluegl_shader_todo_free(__gluegl_shader_todo_t *shader_todo) {
    if (!shader_todo)
        return;

    if (shader_todo->name)
        free(shader_todo->name);

    if (shader_todo->vertex_shader_path)
        free(shader_todo->vertex_shader_path);

    if (shader_todo->fragment_shader_path)
        free(shader_todo->fragment_shader_path);

    free(shader_todo);
}

gluegl_list_t *__gluegl_shader_global_list = NULL;

void __attribute__((constructor)) __gluegl_shader_global_list_create() {
    if (!__gluegl_shader_global_list)
        __gluegl_shader_global_list = gluegl_list_create();
}

void __attribute__((destructor)) __gluegl_shader_global_list_destroy() {
    if (__gluegl_shader_global_list)
        gluegl_list_free(__gluegl_shader_global_list, (void (*)(void*))__gluegl_shader_todo_free);
}

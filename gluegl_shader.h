#ifndef GLUEGL_GLUEGL_SHADER_H
#define GLUEGL_GLUEGL_SHADER_H

#include "gluegl_list.h"

#include <string.h>
#include <malloc.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

typedef struct {
    char *name;

    GLuint vertex_shader;
    char *vertex_shader_source;

    GLuint fragment_shader;
    char *fragment_shader_source;

    GLuint shader_program;
} gluegl_shader_t;

gluegl_shader_t *gluegl_shader_load_files(const char *vertex_shader_path, const char *fragment_shader_path);
gluegl_shader_t *gluegl_shader_load(char *vertex_shader_source, char *fragment_shader_source);
void gluegl_shader_free(gluegl_shader_t *shader);

/* enable quick import of shaders through a new keyword */
/* the __ is generally disallowed, but we want nobody touching the following methods and structs. */
typedef struct {
    char *name;
    char *vertex_shader_path;
    char *fragment_shader_path;
} __gluegl_shader_todo_t;

void __gluegl_shader_todo_free(__gluegl_shader_todo_t *shader_todo);

extern gluegl_list_t *__gluegl_shader_global_list;

void __gluegl_shader_global_list_create();
void __gluegl_shader_global_list_destroy();

#define import(import_as, vertex_path, fragment_path) \
        {                                             \
            __gluegl_shader_todo_t *__todo = malloc(sizeof(__gluegl_shader_todo_t)); \
            if (__todo) {                                                      \
                __todo->name = strdup(import_as);                              \
                __todo->vertex_shader_path = strdup(vertex_path);              \
                __todo->fragment_shader_path = strdup(fragment_path);          \
                gluegl_list_append(__gluegl_shader_global_list, __todo);                    \
            }                                             \
        }

#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)

#define shaders                                                         \
    __attribute__((constructor)) static void CONCATENATE(__gluegl_shader_global_list_init_, __COUNTER__)()

#endif //GLUEGL_GLUEGL_SHADER_H

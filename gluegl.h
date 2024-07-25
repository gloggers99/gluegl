#ifndef GLUEGL_GLUEGL_H
#define GLUEGL_GLUEGL_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "gluegl_shader.h"
#include "gluegl_util.h"

void gluegl_error_callback(int error, const char *description);

typedef struct {
    GLFWwindow *window;
    double delta_time;
} gluegl_t;

gluegl_t *gluegl_init(int width, int height, char *title, GLFWmonitor *monitor, GLFWwindow *window);
void gluegl_free(gluegl_t *gluegl);

void gluegl_loop(gluegl_t *gluegl, int (*loop)(gluegl_t *gluegl));

#endif //GLUEGL_GLUEGL_H

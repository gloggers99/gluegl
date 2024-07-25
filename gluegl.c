#include "gluegl.h"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <malloc.h>

void gluegl_error_callback(int error, const char *description) {
    fprintf(stderr, "gluegl: OpenGL Error %i: \"%s\"\n", error, description);
}

gluegl_t *gluegl_init(int width, int height, char *title, GLFWmonitor *monitor, GLFWwindow *window) {
    gluegl_t *gluegl = malloc(sizeof(gluegl_t));

    gluegl->delta_time = 0.0;

    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "gluegl: Failed to initialize GLFW!\n");
        free(gluegl);
        return NULL;
    }

    glfwSetErrorCallback(gluegl_error_callback);

    gluegl->window = glfwCreateWindow(width, height, title, monitor, window);
    if (gluegl->window == NULL) {
        fprintf(stderr, "gluegl: Failed to create window!\n");
        free(gluegl);
        return NULL;
    }

    glfwMakeContextCurrent(gluegl->window);
    gladLoadGL(glfwGetProcAddress);

    return gluegl;
}

void gluegl_free(gluegl_t *gluegl) {
    if (gluegl->window)
        glfwDestroyWindow(gluegl->window);
    glfwTerminate();
    free(gluegl);
}

void gluegl_loop(gluegl_t *gluegl, int (*loop)(gluegl_t *gluegl)) {
    double last_frame = 0.0;
    double current_frame;
    while (!glfwWindowShouldClose(gluegl->window)) {
        current_frame = glfwGetTime();
        gluegl->delta_time = current_frame - last_frame;
        last_frame = current_frame;

        int result = loop(gluegl);
        if (result) {
            fprintf(stderr, "gluegl: Loop ended with code: %i\n", result);
            break;
        }
    }
}
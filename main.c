#include "gluegl.h"

#include <stdio.h>

shaders {
    import("asdf")
    import_as("test", "test_shader.vert", "test_shader.frag")
};

int loop(gluegl_t *gluegl) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glfwSwapBuffers(gluegl->window);
    glfwPollEvents();

    return 0;
}

int main(void) {
    gluegl_t *gluegl = gluegl_init(800, 600, "gluegl", NULL, NULL);
    printf("%s\n", ((__gluegl_shader_todo_t*)__gluegl_shader_global_list->elements[0])->vertex_shader_path);
    gluegl_loop(gluegl, loop);
    gluegl_free(gluegl);

    return 0;
}

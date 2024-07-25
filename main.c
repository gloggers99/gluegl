#include <stdio.h>

#include "gluegl.h"

shaders {
    import("test", "test.vert", "test.frag")
    import("test2", "test2.vert", "test2.frag")
}

int loop(gluegl_t *gluegl) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glfwSwapBuffers(gluegl->window);
    glfwPollEvents();

    return 0;
}

int main(void) {
    gluegl_t *gluegl = gluegl_init(800, 600, "gluegl", NULL, NULL);
    gluegl_loop(gluegl, loop);
    gluegl_free(gluegl);

    return 0;
}

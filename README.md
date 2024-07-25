# gluegl
## quickstart:
```c
#include "gluegl.h"

int draw(gluegl_t *gluegl) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glfwSwapBuffers(gluegl->window);
    glfwPollEvents();

    /* returning anything other than 0 will exit the loop */
    return 0;
}

int main(void) {
    /* initialize the gluegl_t struct */
    /* gluegl_init(width, height, title, monitor, share) */
    gluegl_t *gluegl = gluegl_init(800, 600, "gluegl", NULL, NULL);
    
    /* start a loop with the function we declared above ^ */
    /* gluegl_loop(gluegl_t*, void (*loop_function)(gluegl_t*)) */
    gluegl_loop(gluegl, draw);
    
    /* free the gluegl_t and safely quit glfw and gl context */
    gluegl_free(gluegl);

    return 0;
}

```
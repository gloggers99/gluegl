cmake_minimum_required(VERSION 3.28)
project(gluegl C)

set(CMAKE_C_STANDARD 99)

add_executable(gluegl main.c
        gluegl.c
        gluegl.h
        gluegl_shader.c
        gluegl_shader.h
        gluegl_util.c
        gluegl_util.h
        gluegl_list.c
        gluegl_list.h)
target_include_directories(gluegl PUBLIC include)
target_link_libraries(gluegl glfw3)
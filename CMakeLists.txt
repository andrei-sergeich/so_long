cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/main.c
        src/so_long.c
        src/count_parse_check.c)

set(MLX_FILES
        mlx/mlx.h
        mlx/mlx_int.h
        mlx/libmlx.a
        mlx/mlx_new_window.h
        mlx/mlx_opengl.h
        mlx/mlx_png.h
        )

set(HEADER include/so_long.h)

#include_directories(mlx)
include_directories(libft)

add_executable(so_long ${SOURCE_FILES} ${MLX_FILES} ${HEADER})

#add_subdirectory(mlx)
add_subdirectory(libft)

#target_link_libraries(so_long mlx)
target_link_libraries(so_long libft)
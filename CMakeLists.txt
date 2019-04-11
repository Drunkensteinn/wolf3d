cmake_minimum_required(VERSION 3.12)
project(Wolf3D C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -O3")

aux_source_directory(libft LIBFT_SRC)
add_library(ft STATIC ${LIBFT_SRC} includes/wolf3d.h includes/errors.h)

add_executable(Wolf3D src/main.c  src/draw.c src/preparation.c src/print.c src/utils.c src/validation.c src/init.c src/rotation_and_move.c src/textures.c)
target_link_libraries(Wolf3D ft)
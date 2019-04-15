cmake_minimum_required(VERSION 3.12)
project(Wolf3D C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -O3")

aux_source_directory(libft LIBFT_SRC)
add_library(ft STATIC ${LIBFT_SRC} includes/wolf3d.h includes/errors.h includes/keys.h)

add_executable(Wolf3D src/main.c  src/draw.c src/preparation.c src/print.c src/draw_utils.c src/validation.c src/init.c src/rotation_and_move.c src/textures.c src/preparation_utils.c src/vector_utils.c src/validation_utils.c src/validation_list_utils.c src/validation_fill.c src/validation_source.c src/key_kontroller.c src/draw_calculations.c src/draw_textures.c src/intersection_algorithm.c src/intersection_algorithm_extra.c src/draw_untextured.c)
target_link_libraries(Wolf3D ft)
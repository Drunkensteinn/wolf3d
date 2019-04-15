# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:38:51 by ablizniu          #+#    #+#              #
#    Updated: 2019/04/15 14:28:15 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WOLF_NAME = wolf3d

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3

# Libraries and Includes

WOLF_LIBRARIES = -lmlx -framework OpenGL -framework AppKit
WOLF_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)


# Headers

HEADERS_DIRECTORY = ./includes/

WOLF_HEADERS_LIST = \
	wolf3d.h \
	keys.h \
	errors.h
WOLF_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(WOLF_HEADERS_LIST))

# Sources

WOLF_SOURCES_DIRECTORY = ./src/
WOLF_SOURCES_LIST = \
				draw.c \
				draw_calculations.c \
				draw_textures.c \
				draw_untextured.c \
				draw_utils.c \
				init.c \
				intersection_algorithm.c \
				intersection_algorithm_extra.c \
				key_controller.c \
				main.c \
				preparation.c \
				preparation_utils.c \
				print.c \
				rotation_and_move.c \
				textures.c \
				validation.c \
				validation_fill.c \
				validation_list_utils.c \
				validation_source.c \
				validation_utils.c \
				vector_utils.c
WOLF_SOURCES = $(addprefix $(WOLF_SOURCES_DIRECTORY), $(WOLF_SOURCES_LIST))

# Objects

OBJECTS_DIRECTORY = ./objects/


WOLF_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)wolf/
WOLF_OBJECTS_LIST = $(patsubst %.c, %.o, $(WOLF_SOURCES_LIST))
WOLF_OBJECTS	= $(addprefix $(WOLF_OBJECTS_DIRECTORY), $(WOLF_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(WOLF_NAME)

$(WOLF_NAME): $(LIBFT) $(WOLF_OBJECTS_DIRECTORY) $(WOLF_OBJECTS)
	@$(CC) $(FLAGS) $(LIBFT) $(WOLF_LIBRARIES) $(WOLF_INCLUDES) $(WOLF_OBJECTS) -o $(WOLF_NAME)
	@echo "\n$(WOLF_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(WOLF_NAME): $(GREEN)$(WOLF_NAME) was created$(RESET)"

$(WOLF_OBJECTS_DIRECTORY):
	@mkdir -p $(WOLF_OBJECTS_DIRECTORY)
	@echo "$(WOLF_NAME): $(GREEN)$(WOLF_OBJECTS_DIRECTORY) was created$(RESET)"

$(WOLF_OBJECTS_DIRECTORY)%.o : $(WOLF_SOURCES_DIRECTORY)%.c $(WOLF_HEADERS)
	@$(CC) $(FLAGS) -c $(WOLF_INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(GREEN)$(LIBFT) was created$(RESET)"
	@$(MAKE) -C $(LIBFT_DIRECTORY)

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@echo "$(WOLF_NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(WOLF_NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(WOLF_NAME)
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	@echo "$(WOLF_NAME): $(RED)$(WOLF_NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
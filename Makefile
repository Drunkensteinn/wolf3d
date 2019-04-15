# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:38:51 by ablizniu          #+#    #+#              #
#    Updated: 2019/04/15 12:56:32 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d
LIB_PATH := libft/
HDRS_PATH := includes/
OBJ_PATH := ./obj/objs/

CC := clang
FLAGS := -Wall -Wextra -Werror -O3  -lmlx -framework OpenGL -framework AppKit
IFLAGS := -I $(HDRS_PATH) -I $(LIB_PATH)
LFLAGS := -lft -L $(LIB_PATH)

LIB := $(LIB_PATH)libft.a
HDRS := errors keys wolf3d
FILES := draw \
		draw_calculations \
		draw_textures \
		draw_untextured \
		draw_utils \
		init \
		intersection_algorithm \
		intersection_algorithm_extra \
		key_kontroller \
		main \
		preparation \
		preparation_utils \
		print \
		rotation_and_move \
		textures \
		validation \
		validation_fill \
		validation_list_utils \
		validation_source \
		validation_utils \
		vector_utils

SRCS += $(addsuffix .c, $(FILES))
HDRS :=	$(addprefix $(HDRS_PATH), $(addsuffix .h, $(HDRS)))
OBJS := $(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
				$(CC) $(FLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

$(LIB):
				$(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c $(HDRS)
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
				@rm -rf $(OBJS)
				@$(MAKE) -sC $(LIB_PATH) clean

fclean: clean
				@rm -rf $(NAME)
				@rm -rf $(OBJ_PATH) $(OBJS) obj/
				@$(MAKE) -sC $(LIB_PATH) fclean

re:
				@$(MAKE) fclean
				@$(MAKE) all
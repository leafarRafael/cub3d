# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:04 by rbutzke           #+#    #+#              #
#    Updated: 2024/09/03 12:53:57 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Program name
NAME			:= cub3d

#-----------------------------------------------------------------------------------------
# Path to MLX42
LIBMLX			:= ./lib/MLX42
LIB_MLX			:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

#-----------------------------------------------------------------------------------------
# Path to LIBFT
LIBFT			:= ./lib/lib_get_print/libft.a
PATH_MAKE_LIB	:= ./lib/lib_get_print

#-----------------------------------------------------------------------------------------
# Path to LIBFT_LIST
LINKED_LIST		:= ./lib/lib_list.a
MAKE_LINKED_L	:= ./lib/linked_list
MAKE_M_LIST		:= ./lib/matrix_list

#-----------------------------------------------------------------------------------------
# Path to the static library
BINARY			:= ./src/cub3D.a

#-----------------------------------------------------------------------------------------
# Compiler and flags
CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra -O3 -g3
OFLAGS			:= -c

#-----------------------------------------------------------------------------------------
# clean comand and flag
CLEAN_CMD		:= rm -Rf

#-----------------------------------------------------------------------------------------
# Paths to the subdirectories containing source files
PATH_MAKE_OBJ	:= src

#-----------------------------------------------------------------------------------------
# Paths to test maps

MAPS = $(addprefix maps/invalid/, empty.cub file_invalid.cub id_rgb_dup_after_all_set.cub \
		id_rgb_dup_before_all_set.cub id_rgb_missing.cub id_rgb_without_content.cub \
		id_rgb_without_content_just_spaces.cub id_wall_dup_after_all_set.cub \
		id_wall_dup_before_all_set.cub id_wall_missing.cub id_wall_without_content.cub \
		id_wall_without_content_just_spaces.cub map_leaky_borders.cub map_leaky_not_rectangular.cub \
		map_more_then_one_player.cub map_multiple_player.cub map_no_extension map_no_player.cub \
		rgb0_invalid.cub rgb1_invalid.cub rgb2_invalid.cub rgb3_invalid.cub rgb4_invalid.cub rgb5_invalid.cub)

#-----------------------------------------------------------------------------------------
# Default rule to create the executable
all: $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to link the static library and create the executable
$(NAME):
	@$(CC) $(BINARY) $(LIB_MLX) $(LIBFT) $(LINKED_LIST) -o $(NAME)
	@printf "\nExecutable %s created successfully\n" $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to create the static library by compiling source files in subdirectories
$(NAME): object libmlx linked_list libft matrix_list


#-----------------------------------------------------------------------------------------
# Rule to create object
object:
	@$(MAKE) -C $(PATH_MAKE_OBJ) --no-print-directory

object_clean:
	@$(MAKE) -C $(PATH_MAKE_OBJ) clean --no-print-directory

#-----------------------------------------------------------------------------------------
# Rule to create the static library MLX42
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

#-----------------------------------------------------------------------------------------
# Rule to create the static library Matrix List
matrix_list:
	@$(MAKE) -C $(MAKE_M_LIST) --no-print-directory

matrix_list_clean:
	@$(MAKE) -C $(MAKE_M_LIST) clean --no-print-directory

matrix_list_fclean:
	@$(MAKE) -C $(MAKE_M_LIST) fclean --no-print-directory

matrix_list_re:
	@$(MAKE) -C $(MAKE_M_LIST) re --no-print-directory


#-----------------------------------------------------------------------------------------
# Rule to create the static library Linked List
linked_list:
	@$(MAKE) -C $(MAKE_LINKED_L) --no-print-directory

linked_list_clean:
	@$(MAKE) -C $(MAKE_LINKED_L) clean --no-print-directory

linked_list_fclean:
	@$(MAKE) -C $(MAKE_LINKED_L) fclean --no-print-directory

linked_list_re:
	@$(MAKE) -C $(MAKE_LINKED_L) re --no-print-directory

#-----------------------------------------------------------------------------------------
# Rule to create the static library LIBFT

libft:
	@$(MAKE) -C $(PATH_MAKE_LIB) --no-print-directory

libft_clean:
	@$(MAKE) -C $(PATH_MAKE_LIB) clean --no-print-directory

libft_fclean:
	@$(MAKE) -C $(PATH_MAKE_LIB) fclean --no-print-directory

libft_re:
	@$(MAKE) -C $(PATH_MAKE_LIB) re --no-print-directory

#-----------------------------------------------------------------------------------------
# Rule to clean
clean: object_clean
	@$(CLEAN_CMD) $(BINARY)

fclean: clean libft_fclean linked_list_fclean matrix_list_fclean
	@$(CLEAN_CMD) $(NAME)

re: fclean all
#-----------------------------------------------------------------------------------------
# Rule to test maps
valgrind:
	@for map in $(MAPS); do \
		echo "\n\e[0;35mRunning Valgrind with map: $$map\033[0m"; \
		valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME) $$map; \
	done



.PHONY: all clean fclean re object_clean object valgrind
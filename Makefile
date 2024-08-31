# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:04 by rbutzke           #+#    #+#              #
#    Updated: 2024/08/31 15:52:13 by rbutzke          ###   ########.fr        #
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

MAPS = $(addprefix maps/, dup0.identifier.cub dup1.identifier.cub empty.cub identifier.without.cub \
	id.without_content.cub map_badly_form_color.cub map_badly_form_texture.cub map.cub map_duplicate_color.cub \
	map_duplicate_WE.cub map_element_incomplete.cub map_element_more_then_complete.cub \
	map_leaky_borders.cub map_leaky_not_rectangular.cub map_missing_color.cub map_missing_one_element.cub \
	map_missing_texture.cub map_multiple_F.cub map_multiple_player.cub map_multiple_textures.cub \
	map_no_extension map_no_player.cub map_OK.cub map_OK_not_rectangular.cub maps.ber maps.cub \
	map_with_double_element_after_file_content_is_set.cub map.without.cub map_wrong_bg_badly_formatted.cub \
	map_wrong_bg_color_with_char.cub map_wrong_bg_numbers.cub map_wrong_texture_path.cub no_content.cub \
	rgb0.invalid.cub rgb1.invalid.cub rgb2.invalid.cub rgb3.invalid.cub)

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
		valgrind -q --leak-check=full ./$(NAME) $$map; \
	done



.PHONY: all clean fclean re object_clean object valgrind
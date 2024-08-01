# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:04 by rbutzke           #+#    #+#              #
#    Updated: 2024/08/01 11:44:15 by rbutzke          ###   ########.fr        #
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
# Default rule to create the executable
all: $(NAME)

#-----------------------------------------------------------------------------------------	
# Rule to link the static library and create the executable
$(NAME):
	@$(CC) $(BINARY) $(LIB_MLX) -o $(NAME)
	@printf "\nExecutable %s created successfully\n" $(NAME)

#-----------------------------------------------------------------------------------------	
# Rule to create the static library by compiling source files in subdirectories
$(NAME): object libmlx

#-----------------------------------------------------------------------------------------	
# Rule ti create object
object:
	@$(MAKE) -C $(PATH_MAKE_OBJ) --no-print-directory

object_clean:
	@$(MAKE) -C $(PATH_MAKE_OBJ) clean --no-print-directory

#-----------------------------------------------------------------------------------------
# Rule to create the static library MLX42
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

#-----------------------------------------------------------------------------------------
# Rule to clean
clean: object_clean
	@$(CLEAN_CMD) $(BINARY)

fclean: clean
	@$(CLEAN_CMD) $(NAME)

re: fclean all

.PHONY: all clean fclean re object_clean object
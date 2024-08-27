# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:48 by rbutzke           #+#    #+#              #
#    Updated: 2024/08/27 17:43:51 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME			:= cub3D.a

#-----------------------------------------------------------------------------------------
# Compiler and flags
CFLAGS			:= -Wall -Werror -Wextra -O3 -MMD -g3
CC				:= cc
O_FLAGS			:= -c

#-----------------------------------------------------------------------------------------
# Command to clean up files
CMD_CLEAN		:= rm -Rf

#-----------------------------------------------------------------------------------------
# DIRECTORY and Header file
UTILS			:= utils/
PARSE			:= parse/
ERROR			:= parse/error/
VALID_FILE		:= parse/valid_file/
HOOK_MOVE		:= hook_move/
CTRL			:= hook_move/controls/
RENDER_IMAGE	:= render_image/
RAYCASTING		:= raycasting/
DDA				:= raycasting/dda/
TEXTURE			:= pixels_texture/
INCLUDE			:= ../includes
MLX42			:= ../lib/MLX42/include/MLX42/
LIBFT			:= ../lib/lib_get_print/includes/
LINKED_L		:= ../lib/linked_list/include/
LINKED_M		:= ../lib/matrix_list/include/

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES		:= -I $(RAYCASTING)\
				-I $(DDA)\
				-I $(INCLUDE)\
				-I $(UTILS)\
				-I $(PARSE)\
				-I $(HOOK_MOVE)\
				-I $(MLX42)\
				-I $(LIBFT)\
				-I $(RENDER_IMAGE)\
				-I $(TEXTURE)\
				-I $(ERROR)\
				-I $(VALID_FILE)\
				-I $(LINKED_L)\
				-I $(LINKED_M)\
				-I $(CTRL)

#-----------------------------------------------------------------------------------------
# Source files
FILE_UTILS		:= utils.c
FILE_PARSE		:= parse.c coordinates.c\
					get_file.c get_texture_path.c\
					get_ceiling_floor.c
FILE_ERROR		:= error.c
FILE_VALID		:= valid_file.c
FILE_HOOK		:= hook.c
FILE_CTRL		:= move_up.c move_down.c move_left.c move_right.c\
					rotate_right.c rotate_left.c
RENDER			:= render_ceiling_floor.c render_texture_image.c
FILE_RAY		:= ray_casting.c
FILE_DDA		:= dda.c side.c find_collision.c
FILE_TEXTURE	:= pixels_texture.c arrange_rgba.c

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES		:= $(addprefix $(RENDER_IMAGE), $(RENDER))\
					$(addprefix $(RAYCASTING), $(FILE_RAY))\
					$(addprefix $(DDA), $(FILE_DDA))\
					$(addprefix $(UTILS), $(FILE_UTILS))\
					$(addprefix $(PARSE), $(FILE_PARSE))\
					$(addprefix $(CTRL), $(FILE_CTRL))\
					$(addprefix $(HOOK_MOVE), $(FILE_HOOK))\
					$(addprefix $(TEXTURE), $(FILE_TEXTURE))\
					$(addprefix $(VALID_FILE), $(FILE_VALID))\
					$(addprefix $(ERROR), $(FILE_ERROR))\
					main.c\

#-----------------------------------------------------------------------------------------
NUM_FILES	:= $(words $(SRC_FILES))

#-----------------------------------------------------------------------------------------
# Directory for object files
OBJS		:= objs
O_FILE		:= $(SRC_FILES:%.c=$(OBJS)/%.o)
DEP_FILES   := $(O_FILE:%.o=%.d)

#-----------------------------------------------------------------------------------------
# Default rule to create the static library
all: $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to create the static library
$(NAME): $(O_FILE)
	@ar -rc $(NAME) $(O_FILE)
	@echo ""

#-----------------------------------------------------------------------------------------
# Rule to compile source files into object files
$(OBJS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@printf "Creating the program binaries   [%s]\r" $(shell echo "$$(($(COUNT) * 100 / $(NUM_FILES)))%")

#-----------------------------------------------------------------------------------------
# Include dependency files
#-include $(DEP_FILES)

#-----------------------------------------------------------------------------------------
# Rule to clean
clean:
	@$(CMD_CLEAN) $(OBJS) $(NAME)
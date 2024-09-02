# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:48 by rbutzke           #+#    #+#              #
#    Updated: 2024/09/02 15:30:22 by rbutzke          ###   ########.fr        #
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
VALID			:= parse/valid_arguments/
READ_FILE		:= parse/read_file/
GET_ATTR		:= parse/get_attr/
VALID_MAP		:= parse/is_valid_map/
NORMALIZE_MAP	:= parse/normalize_map/
ERROR_HANDLER	:= error_handler/
PLAYER			:= parse/player/
FLOOD_FILL_MAP	:= parse/flood_fill/
LOAD_MLX		:= load_mlx/
SET_RGB			:= set_rgb/
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
				-I$(INCLUDE)\
				-I $(UTILS)\
				-I $(PARSE)\
				-I $(VALID)\
				-I $(READ_FILE)\
				-I $(HOOK_MOVE)\
				-I $(MLX42)\
				-I $(LIBFT)\
				-I $(LINKED_L)\
				-I $(LINKED_M)\
				-I $(RENDER_IMAGE)\
				-I $(TEXTURE)\
				-I $(GET_ATTR)\
				-I $(VALID_MAP)\
				-I $(NORMALIZE_MAP)\
				-I $(PLAYER)\
				-I $(FLOOD_FILL_MAP)\
				-I $(ERROR_HANDLER)\
				-I $(LOAD_MLX)\
				-I $(SET_RGB)\
				-I $(CTRL)

#-----------------------------------------------------------------------------------------
# Source files
FILE_UTILS		:= utils.c
FILE_ERROR		:= error_handler.c
FILE_PARSE		:= parse.c
FILE_VALID_MAP	:= is_valid_map.c
FILE_ATTR		:= get_attr.c set_ceiling_floor.c set_path_texture.c
FILE_VALID		:= valid_arguments.c
FILE_NORMALIZE	:= normalize_map.c
FILE_PLAYER		:= set_player.c
FILE_FLOOD_FILL	:= flood_fill.c
FILE_READ		:= read_file.c
FILE_LOAD_MLX	:= init_atributes_mlx.c
FILE_SET_RGB	:= set_rgb.c
FILE_HOOK		:= hook.c
RENDER			:= render_ceiling_floor.c render_texture_image.c
FILE_RAY		:= ray_casting.c
FILE_DDA		:= dda.c side.c find_collision.c
FILE_TEXTURE	:= pixels_texture.c arrange_rgba.c
FILE_CTRL		:= move_up.c move_down.c move_left.c move_right.c\
					rotate_right.c rotate_left.c

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
					$(addprefix $(VALID), $(FILE_VALID))\
					$(addprefix $(READ_FILE), $(FILE_READ))\
					$(addprefix $(GET_ATTR), $(FILE_ATTR))\
					$(addprefix $(VALID_MAP), $(FILE_VALID_MAP))\
					$(addprefix $(NORMALIZE_MAP), $(FILE_NORMALIZE))\
					$(addprefix $(PLAYER), $(FILE_PLAYER))\
					$(addprefix $(FLOOD_FILL_MAP), $(FILE_FLOOD_FILL))\
					$(addprefix $(ERROR_HANDLER), $(FILE_ERROR))\
					$(addprefix $(LOAD_MLX), $(FILE_LOAD_MLX))\
					$(addprefix $(SET_RGB), $(FILE_SET_RGB))\
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
-include $(DEP_FILES)

#-----------------------------------------------------------------------------------------
# Rule to clean
clean:
	@$(CMD_CLEAN) $(OBJS) $(NAME)
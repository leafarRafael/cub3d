NAME			:= ../lib_list.a

SRC				:= ./src/init_matrix.c\
				./src/init_line_lst.c\
				./src/add_line_front.c\
				./src/add_line_back.c\
				./src/remove_especific_list_in_matrix.c\
				./src/remove_lst_front.c\
				./src/remove_lst_back.c\
				./src/delete_matrix.c\
				./src/cpy_mtrllst_to_cmtrx.c\
				./src/cpy_cmtrx_to_mtrx_lst.c\
				./src/find_str_in_matrixlst.c\
				./src/mlst_insert_lnode_between.c\
				./src/remove_and_return_lline.c\
				./src/add_nodeline_back.c\
				./src/add_nodeline_front.c\

NUM_FILES		:= $(words $(SRC))
OBJS			:= ./objs_matrix_list
INCLUDES		:= -I ./include -I ../linked_list/include
O_FILE			:= $(SRC:%.c=$(OBJS)/%.o)
CC				:= cc
CFLAGS 			:= -Wall -Werror -Wextra
O_FLAGS 		:= -c
CMD_CLEAN		:= rm -Rf

all : $(NAME)

$(NAME): $(O_FILE)
	@ar -rc $(NAME) $(O_FILE)
	@echo ""

$(OBJS)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@printf "[%s] Matrix_list progress\r" $(shell echo 	"$$(($(COUNT) * 100 / $(NUM_FILES)))%")

clean:
	@$(CMD_CLEAN) $(OBJS)

fclean: clean
	@$(CMD_CLEAN) $(NAME)

re: fclean all

.PHONI: all clean fclean re

NAME		=	btc

GREEN		=	\033[1;32m
RED			=	\033[1;31m
DEFAULT		=	\033[0m

OBJ_DIR		=	objs
SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d)

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)
vpath %.hpp $(foreach dir, $(INC_DIR), $(dir):)

SRCS		=	main.cpp			\
				BitcoinExchange.cpp



OBJS		=	$(SRCS:%.cpp=${OBJ_DIR}/%.o)

RM			=	rm -rf

CC			=	c++

CFLAGS		=	-Werror -Wall -Wextra -std=c++98 -g3

all:	${NAME}

$(NAME): ${OBJS} ${INC_DIR}
		@${CC} ${CFLAGS} ${OBJS} -I ${INC_DIR} -o ${NAME}
		@echo "$(GREEN)##### btc compiling finished! #####$(DEFAULT)"

$(OBJ_DIR)/%.o: %.cpp ${INC_DIR} | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@ -I ${INC_DIR}

$(OBJ_DIR) :
		@mkdir -p $@

clean:
		@${RM} $(OBJ_DIR)

fclean:		clean
		@${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		@$(MAKE) all -j

.PHONY:		all clean fclean re

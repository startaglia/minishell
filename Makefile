SRC = readline.c
OBJ = ${SRC:.c=.o}

CC = gcc
FLAG = -Wall -Werror -Wextra

INCLUDE = -I /Users/startagl/.brew/opt/readline/include
LIBS = -L /Users/startagl/.brew/opt/readline/lib 

NAME = minishell

%.o : %c
	@${CC} ${FLAG} -c $< -o $@ -g

${NAME} : ${OBJ}
	@${CC} ${FLAG} -lreadline ${OBJ} ${LIBS} ${INCLUDE} -o ${NAME} -g

all : ${NAME}

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all clean

.PHONY : clean fclean all re
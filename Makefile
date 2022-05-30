NAME	= LR
SRCS	= main.c
OBJS	= ${SRCS:.c=.o}
GCC		= gcc
RM		= rm -rf
GLAGS	= -Wall -Wextra -Werror
all:	${NAME}
.c.o:	
		${GCC} ${GFLAGS} -c $< -o ${<:.c=.o}
${NAME}:
		${GCC} ${GFLAGS} ${SRCS} -o ${NAME} -lm
# clean:
# 		${RM} ${OBJS}
fclean:	#clean
		${RM} ${NAME}
re:		fclean all
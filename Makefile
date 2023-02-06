.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	push_swap

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRC		= 	src/

DIR_HEAD 	=	incl/

DIR_LIBFT	=	libft

# ---- Files ---- #

HEAD_LST	=	push_swap.h libft.h

SRCS_LST 	= 	push_swap.c		errors.c 		\
				stacks.c		instructions.c	\
				sort.c			find_limits.c	\
				moves.c			best_stroke.c


OBJS_LST	=	${SRCS_LST:%.c=%.o}

HEAD 		= 	$(addprefix $(DIR_HEAD), $(HEAD_LST))

SRCS 		= 	$(addprefix $(DIR_SRC), $(SRCS_LST))

OBJS 		= 	$(addprefix $(DIR_OBJS), $(OBJS_LST))

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all			:	libft.a ${NAME}

libft.a		:
				make -j -C ${DIR_LIBFT}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} -I $(DIR_HEAD) ${OBJS} -o ${NAME} -L libft/ -lft

# ---- Compiled Rules ---- #


$(DIR_OBJS)%.o	:	$(DIR_SRC)%.c ${HEAD} Makefile | $(DIR_OBJS)
					${CC} ${CFLAGS} -I $(DIR_HEAD) -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}


# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean_libft	:
					make fclean -C ${DIR_LIBFT}

fclean			:	fclean_libft clean
					${RM} ${NAME}

re				:	fclean
					$(MAKE) all
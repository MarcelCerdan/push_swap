.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	push_swap

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_OBJS_BONUS	=	.bonus/

DIR_SRC		= 	src/

DIR_BONUS	=	src_bonus/

DIR_HEAD 	=	incl/

DIR_LIBFT	=	libft

# ---- Files ---- #

HEAD_LST	=	push_swap.h libft.h get_next_line.h

SRCS_LST 	= 	push_swap.c		errors.c 		\
				stacks.c		instructions.c	\
				sort.c			find_limits.c	\
				moves.c			best_stroke.c	\

BONUS_LST	=	checker.c				get_next_line.c	\
				get_next_line_utils.c	sort_checker.c	\
				error_checker.c			stack_checker.c

OBJS_LST	=	${SRCS_LST:%.c=%.o}

OBJS_BONUS_LST	=	${BONUS_LST:%.c=%.o}

HEAD 		= 	$(addprefix $(DIR_HEAD), $(HEAD_LST))

SRCS 		= 	$(addprefix $(DIR_SRC), $(SRCS_LST))

BONUS		=	$(addprefix $(DIR_BONUS), $(BONUS_LST))

OBJS 		= 	$(addprefix $(DIR_OBJS), $(OBJS_LST))

BONUS_OBJS	=	$(addprefix	$(DIR_OBJS_BONUS), $(OBJS_BONUS_LST))

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3
LEAKS	=	-fsanitize=address

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

bonus			:	libft.a ${BONUS_OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} -I $(DIR_HEAD) ${BONUS_OBJS} -o checker -L libft/ -lft

leaks			:	libft.a ${OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} ${LEAKS} -I $(DIR_HEAD) ${OBJS} -o $@ -L libft/ -lft

leaks_bonus		:	 libft.a ${BONUS_OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} ${LEAKS} -I $(DIR_HEAD) ${BONUS_OBJS} -o $@ -L libft/ -lft

# ---- Compiled Rules ---- #


$(DIR_OBJS)%.o	:	$(DIR_SRC)%.c ${HEAD} Makefile | $(DIR_OBJS)
					${CC} ${CFLAGS} -I $(DIR_HEAD) -c $< -o $@

$(DIR_OBJS_BONUS)%.o	:	$(DIR_BONUS)%.c ${HEAD} Makefile | $(DIR_OBJS_BONUS)
					${CC} ${CFLAGS} -I $(DIR_HEAD) -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

${DIR_OBJS_BONUS}		:
					${MKDIR} ${DIR_OBJS_BONUS}


# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}
					${RM} ${DIR_OBJS_BONUS}

fclean_libft	:
					make fclean -C ${DIR_LIBFT}

fclean			:	fclean_libft clean
					${RM} ${NAME}
					${RM} checker

re				:	fclean
					$(MAKE) all
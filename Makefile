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

DIR_LIBFT	=	libft/

# ---- Files ---- #

LIBFT		=	${DIR_LIBFT}libft.a

HEAD_LST	=	push_swap.h libft.h get_next_line.h

SRCS_LST 	= 	push_swap.c			errors.c 		\
				stacks.c			instructions.c	\
				sort.c				find_limits.c	\
				moves.c				best_stroke.c	\
				best_stroke_add.c

BONUS_LST	=	checker.c				get_next_line.c	\
				get_next_line_utils.c	sort_checker.c	\
				error_checker.c			stack_checker.c

OBJS_LST	=	${SRCS_LST:.c=.o}

OBJS_BONUS_LST	=	${BONUS_LST:.c=.o}

HEAD 		= 	$(addprefix $(DIR_HEAD), $(HEAD_LST))

SRCS 		= 	$(addprefix $(DIR_SRC), $(SRCS_LST))

BONUS		=	$(addprefix $(DIR_BONUS), $(BONUS_LST))

OBJS 		= 	$(addprefix $(DIR_OBJS), $(OBJS_LST))

BONUS_OBJS	=	$(addprefix	$(DIR_OBJS_BONUS), $(OBJS_BONUS_LST))

DEPS		=	$(OBJS:.o=.d)

BONUS_DEPS	=	$(BONUS_OBJS:.o=.d)

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LEAKS	=	-fsanitize=address

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
DFLAG	=	-MMD -MP

# ********* RULES ******** #

all			:	${NAME}

-include		$(DEPS)
-include		$(BONUS_DEPS)

${LIBFT}		:	FORCE
					make -j -C ${DIR_LIBFT}

FORCE			:

# ---- Variables Rules ---- #

${NAME}			:	${LIBFT} ${OBJS}
					${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L libft/ -lft

bonus			:	${LIBFT} ${BONUS_OBJS}
					${CC} ${CFLAGS} ${BONUS_OBJS} -o checker -L libft/ -lft

leaks			:	${LIBFT} ${OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} ${LEAKS} -I $(DIR_HEAD) ${OBJS} -o $@ -L libft/ -lft

leaks_bonus		:	 ${LIBFT} ${BONUS_OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} ${LEAKS} -I $(DIR_HEAD) ${BONUS_OBJS} -o $@ -L libft/ -lft

# ---- Compiled Rules ---- #

$(DIR_OBJS)%.o	:	$(DIR_SRC)%.c
					${MKDIR} ${DIR_OBJS}
					${CC} ${CFLAGS} $(DFLAG) -I $(DIR_HEAD) -c $< -o $@

$(DIR_OBJS_BONUS)%.o	:	$(DIR_BONUS)%.c
							${MKDIR} ${DIR_OBJS_BONUS}
							${CC} ${CFLAGS} $(DFLAG) -I $(DIR_HEAD) -c $< -o $@

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
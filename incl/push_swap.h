/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:52:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/17 12:52:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

/*----------INSTRUCTIONS----------*/

# define RA 1
# define RB 2
# define RR 3
# define RRA 4
# define RRB 5
# define RRR 6

# define INF 0
# define SUP 1

typedef struct s_elem
{
	int	index;
	int	nb;
}	t_elem;

typedef struct s_bounds
{
	int	min;
	int	max;
	int	third;
}	t_bounds;

typedef struct s_moves
{
	int	rra;
	int	rrb;
	int	ra;
	int	rb;
	int	total;
}	t_moves;

typedef struct s_strokes
{
	int	elem_index;
	int	index;
	int	rb;
	int	rrb;
	int	ra;
	int	rra;
}		t_strokes;

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

int		find_inf(t_stack *stack, int nb);
int		find_sup(t_stack *stack, int nb);
int		stack_size(t_stack *stack);
int		is_sort(t_stack *stack);
int		sort(t_stack **a);
int		chose_inst(t_stack **a, t_stack **b, int inst);
void	find_third(t_stack *a, t_bounds *bounds);
int		check_stack(t_stack *a, t_bounds *bounds);
void	del_elem(t_stack **stack);
void	*check_args(int ac, char **av, int *args);
void	error(void *elem);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
void	check_rr_rrr(t_strokes st, t_moves *moves);
void	check_rot_rev_rot(t_strokes st, t_moves *moves);
void	move(t_stack **a, t_stack **b, t_moves *moves);
void	put_zero(t_moves *m);
t_stack	**push(t_stack **a, t_stack **b, char *str);
t_stack	**create_elem(int nmb, t_stack **stack);
t_stack	**push_front(t_stack **stack, t_stack *elem);
t_stack	**init_stacks(t_stack **a, t_stack **b);
void	best_stroke(t_stack *a, t_stack *b, t_moves *moves);

#endif

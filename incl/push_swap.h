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

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

int		stack_size(t_stack *stack);
void	del_elem(t_stack **stack);
void	*check_args(int ac, char **av, int *args);
void	error(void *elem);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
t_stack	**push(t_stack **a, t_stack **b);
t_stack	**create_elem(int nmb, t_stack **stack);
t_stack	**push_front(t_stack **stack, t_stack *elem);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:04:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/23 16:04:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	nb;

	if (stack_size(stack) <= 1)
		return ;
	nb = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = nb;
}

t_stack	**push(t_stack **a, t_stack **b)
{
	t_stack	**new_b;

	if (stack_size(*a) == 0)
		return (b);
	new_b = create_elem((*a)->nb, b);
	del_elem(a);
	return (new_b);
}

void	rotate(t_stack *stack)
{
	int		first;

	first = stack->nb;
	while (stack->next)
	{
		stack->nb = stack->next->nb;
		stack = stack->next;
	}
	stack->nb = first;
}

void	rev_rotate(t_stack *stack)
{
	t_stack	*tmp;
	int		*nb;
	int 	i;

	nb = malloc(sizeof(int) * stack_size(stack));
	if (nb == NULL)
		error(NULL);
	i = -1;
	tmp = stack;
	while (tmp)
	{
		nb[++i] = tmp->nb;
		tmp = tmp->next;
	}
	stack->nb = nb[i];
	stack = stack->next;
	i = -1;
	while (stack)
	{
		stack->nb = nb[++i];
		stack = stack->next;
	}
	free(nb);
}

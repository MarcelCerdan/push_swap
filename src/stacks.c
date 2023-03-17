/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:14:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/21 20:14:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	**init_stacks(t_stack **a, t_stack **b)
{
	t_bounds	*bounds;

	bounds = malloc(sizeof(t_bounds));
	check_malloc(bounds, a, b, "init_stack");
	find_third(*a, bounds);
	while ((*a)->next && check_stack(*a, bounds) == 0)
	{
		if ((*a)->nb <= bounds->min + bounds->third)
		{
			b = push(a, b, "pb");
			check_malloc(b, a, b, "init_stack");
			if ((*b)->next && (*a)->nb > bounds->min + 2 * bounds->third)
				chose_inst(a, b, RR);
			else if ((*b)->next)
				chose_inst(a, b, RB);
		}
		else if ((*a)->nb <= bounds->min + 2 * bounds->third)
		{
			b = push(a, b, "pb");
			check_malloc(b, a, b, "init_stack");
		}
		else
			chose_inst(a, b, RA);
	}
	return (free(bounds), b);
}

void	del_elem(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		size++;
	}
	return (size + 1);
}

t_stack	**push_front(t_stack **stack, t_stack *elem)
{
	if (stack == NULL)
	{
		stack = malloc(sizeof(t_stack));
		if (stack == NULL)
			error(NULL);
		elem->next = NULL;
	}
	else
		elem->next = *stack;
	*stack = elem;
	return (stack);
}

t_stack	**create_elem(int nb, t_stack **stack)
{
	t_stack	*elem;

	elem = malloc(sizeof (t_stack));
	if (!elem)
		return (clear_stack(stack), NULL);
	elem->nb = nb;
	elem->next = NULL;
	stack = push_front(stack, elem);
	return (stack);
}

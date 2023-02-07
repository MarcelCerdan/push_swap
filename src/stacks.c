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
	int		third;
	int		flag;

	flag = 0;
	third = find_third(*a);
	while (check_stack(*a, third) == 0)
	{
		if ((*a)->nb <= third)
		{
			b = push(a, b, "pb");
			if ((*a)->next && flag == 1 && (*a)->next->nb > 2 * third)
				chose_inst(a, b, RR);
			else if (flag == 1)
				chose_inst(a, b, RB);
		}
		else if ((*a)->nb <= 2 * third)
		{
			flag = 1;
			b = push(a, b, "pb");
		}
		else
			chose_inst(a, b, RA);
	}
	return (b);
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

	elem = malloc (sizeof (t_stack));
	if (!elem)
		return (NULL);
	elem->nb = nb;
	elem->next = NULL;
	stack = push_front(stack, elem);
	return (stack);
}

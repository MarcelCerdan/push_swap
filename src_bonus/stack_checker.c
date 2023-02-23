/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:48:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/02/10 22:48:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	clear_stack(t_stack **a)
{
	while (*a)
		del_elem(a);
	free(a);
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

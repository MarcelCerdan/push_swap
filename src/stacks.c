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

t_stack	*create_stack_elem(int nb)
{
	t_stack *elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}

void	push_front(t_stack **stack, t_stack *elem)
{
	elem->next = *stack;
	*stack = elem;
}
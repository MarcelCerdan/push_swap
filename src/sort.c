/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:10:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/24 15:10:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->next->nb < stack->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sort(t_stack **a)
{
	t_stack	**b;
	t_moves	*moves;

	b = NULL;
	b = init_stacks(a, b);
	while ((*a)->next)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	while (!is_sort(*a) && *b)
	{
		moves = best_stroke(*a, *b);
		move(a, b, moves);
		free(moves);
	}
	return (0);
}

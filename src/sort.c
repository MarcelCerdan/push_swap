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
	moves = malloc(sizeof(t_moves));
	if (!moves)
		error(NULL);
	if (*a)
	{
		while ((*a)->next)
			b = push(a, b, "pb");
	}
	while (*b)
	{
		best_stroke(*a, *b, moves);
		move(a, b, moves);
	}
	free(moves);
	return (0);
}

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

static void	find_order(t_stack *a, t_bounds *bounds_index)
{
	int			min;
	int			max;

	min = a->nb;
	max = a->nb;
	bounds_index->max = 0;
	bounds_index->min = 0;
	bounds_index->third = 0;
	while (a->next)
	{
		a = a->next;
		bounds_index->third++;
		if (a->nb > max)
		{
			max = a->nb;
			bounds_index->max = bounds_index->third;
		}
		if (a->nb < min)
		{
			min = a->nb;
			bounds_index->min = bounds_index->third;
		}
	}
}

int	small_sort(t_stack **a)
{
	t_bounds	bounds_index;
	int			err;

	find_order(*a, &bounds_index);
	if (bounds_index.max == 2 && bounds_index.min == 1)
		return (swap(a, "sa"), 0);
	else if (bounds_index.max == 0 && bounds_index.min == 2)
	{
		swap(a, "sa");
		err = chose_inst(a, NULL, RRA);
	}
	else if (bounds_index.max == 0 && bounds_index.min == 1)
		err = chose_inst(a, NULL, RA);
	else if (bounds_index.max == 1 && bounds_index.min == 0)
	{
		swap(a, "sa");
		err = chose_inst(a, NULL, RA);
	}
	else if (bounds_index.max == 1 && bounds_index.min == 2)
		err = chose_inst(a, NULL, RRA);
	if (err < 0)
		error_malloc(a, NULL, "small_sort");
	return (0);
}

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

int	sort(t_stack **a, int ac)
{
	t_stack	**b;
	t_moves	*moves;

	b = NULL;
	if (ac > 6)
		b = init_stacks(a, b);
	moves = malloc(sizeof(t_moves));
	if (!moves)
		error_malloc(a, b, "sort");
	if (*a && (*a)->next)
	{
		while ((*a)->next->next)
			b = push(a, b, "pb");
	}
	while (*b)
	{
		if (best_stroke(a, b, moves) < 0)
			return (free(moves), error_malloc(a, b, "best_stroke"), -1);
		move(a, b, moves);
	}
	return (free(moves), clear_stack(b), 0);
}

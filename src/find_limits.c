/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:03:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/25 18:03:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_stack *a, t_bounds *bounds)
{
	while (a)
	{
		if (a->nb <= bounds->min + 2 * bounds->third)
			return (0);
		a = a->next;
	}
	return (1);
}

void	find_third(t_stack *a, t_bounds *bounds)
{
	bounds->min = a->nb;
	bounds->max = bounds->min;
	while (a)
	{
		if (a->nb > bounds->max)
			bounds->max = a->nb;
		if (a->nb < bounds->min)
			bounds->min = a->nb;
		a = a->next;
	}
	if (bounds->min < 0)
		bounds->third = (bounds->max - bounds->min) / 3;
	else
		bounds->third = (bounds->max + bounds->min) / 3;
}

int	find_inf(t_stack *stack, int nb)
{
	int	inf;
	int	index;
	int	inf_index;

	index = 0;
	while (stack && stack->nb > nb)
	{
		stack = stack->next;
		index++;
	}
	if (!stack)
		return (-1);
	inf_index = index;
	inf = stack->nb;
	while (stack)
	{
		if (stack->nb > inf && stack->nb < nb)
		{
			inf = stack->nb;
			inf_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (inf_index);
}

int	find_sup(t_stack *stack, int nb)
{
	int	sup;
	int	index;
	int	sup_index;

	index = 0;
	while (stack && stack->nb < nb)
	{
		stack = stack->next;
		index++;
	}
	if (!stack)
		return (-1);
	sup = stack->nb;
	sup_index = index;
	while (stack)
	{
		if (stack->nb < sup && stack->nb > nb)
		{
			sup = stack->nb;
			sup_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (sup_index);
}

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

int	check_stack(t_stack *a, int third)
{
	while (a)
	{
		if (a->nb <= 2 * third)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_third(t_stack *a)
{
	int		min;
	int		max;

	min = a->nb;
	max = min;
	while (a)
	{
		if (a->nb > max)
			max = a->nb;
		if (a->nb < min)
			min = a->nb;
		a = a->next;
	}
	return ((max + min) / 3);
}

int	find_inf(t_stack *stack, int nb, int index)
{
	int	inf;
	int	inf_index;

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
		if (stack->nb > inf && stack->nb <= nb)
		{
			inf = stack->nb;
			inf_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (inf_index);
}

int	find_sup(t_stack *stack, int nb, int index)
{
	int	sup;
	int	sup_index;

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
		if (stack->nb < sup && stack->nb >= nb)
		{
			sup = stack->nb;
			sup_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (sup_index);
}

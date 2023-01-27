/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_stroke.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:59:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/27 00:59:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_moves	*calc_inst(t_strokes st)
{
	t_moves		*moves;

	moves = malloc(sizeof(t_moves));
	if (!moves)
		error(NULL);
	check_rr_rrr(st, moves);
	check_rot_rev_rot(st, moves);
	return (moves);
}

t_moves	*inst_nb(t_strokes *elem, t_stack *a, t_stack *b, int lim)
{
	elem->rb = elem->index;
	elem->rrb = stack_size(b) - elem->index;
	if (lim == INF)
	{
		elem->ra = elem->index + 1;
		elem->rra = stack_size(a) - elem->index - 1;
	}
	else if (lim == SUP)
	{
		elem->ra = elem->index;
		elem->rra = stack_size(a) - elem->index;
	}
	return (calc_inst(*elem));
}

t_moves	*find_best(t_stack *a, t_stack *b, int nb, int index)
{
	t_strokes	inf;
	t_strokes	sup;
	t_moves		*inf_moves;
	t_moves		*sup_moves;

	inf.index = find_inf (a, nb, index);
	sup.index = find_sup (a, nb, index);
	inf_moves = inst_nb(&inf, a, b, INF);
	sup_moves = inst_nb(&sup, a, b, SUP);
	if (inf_moves->total <= sup_moves->total)
		return (inf_moves);
	return (sup_moves);
}

t_moves	*best_stroke(t_stack *a, t_stack *b)
{
	t_moves	*min;
	t_moves	*current;
	int		index;

	index = 0;
	min = find_best (a, b, b->nb, index);
	while (b->next)
	{
		if (current)
			free(current);
		b = b->next;
		index++;
		current = find_best (a, b, b->nb, index);
		if (current->total < min->total)
			min = current;
	}
	free(current);
	return (min);
}

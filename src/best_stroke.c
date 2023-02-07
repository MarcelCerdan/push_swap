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

static t_moves	*calc_inst(t_strokes st)
{
	t_moves		*moves;

	moves = malloc(sizeof(t_moves));
	if (!moves)
		error(NULL);
	check_rr_rrr(st, moves);
	check_rot_rev_rot(st, moves);
	return (moves);
}

static t_moves	*inst_nb(t_strokes *limit, t_stack *a, t_stack *b, int lim)
{
	limit->rb = limit->elem_index;
	limit->rrb = stack_size(b) - limit->elem_index;
	if (lim == INF)
	{
		limit->ra = limit->index + 1;
		limit->rra = stack_size(a) - limit->index - 1;
	}
	else if (lim == SUP)
	{
		limit->ra = limit->index;
		limit->rra = stack_size(a) - limit->index;
	}
	return (calc_inst(*limit));
}

static t_moves	*find_best(t_stack *a, t_stack *b, int nb, int index)
{
	t_strokes	inf;
	t_strokes	sup;
	t_moves		*inf_moves;
	t_moves		*sup_moves;

	inf.index = find_inf(a, nb);
	sup.index = find_sup(a, nb);
	inf.elem_index = index;
	sup.elem_index = index;
	if (inf.index > -1)
		inf_moves = inst_nb(&inf, a, b, INF);
	if (sup.index > -1)
		sup_moves = inst_nb(&sup, a, b, SUP);
	if (inf.index < 0)
		return (sup_moves);
	if (sup.index < 0)
		return (inf_moves);
	if (inf_moves->total <= sup_moves->total)
		return (inf_moves);
	return (sup_moves);
}

void	best_stroke(t_stack *a, t_stack *b, t_moves *moves)
{
	t_moves	*current;
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = b;
	moves = find_best (a, b, b->nb, index);
	while (tmp->next)
	{
		tmp = tmp->next;
		index++;
		current = find_best(a, b, tmp->nb, index);
		if (current->total < moves->total)
			moves = current;
	}
}

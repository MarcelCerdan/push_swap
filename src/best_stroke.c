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

static void	equal(t_moves *a, t_moves *b, t_moves *clear)
{
	a->ra = b->ra;
	a->rb = b->rb;
	a->rra = b->rra;
	a->rrb = b->rrb;
	a->total = b->total;
	free(b);
	if (clear != NULL)
		free(clear);
}

static t_moves	*calc_inst(t_strokes st)
{
	t_moves		*moves;

	moves = malloc(sizeof(t_moves));
	if (!moves)
		return (moves);
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

static int	find_best(t_stack **a, t_stack **b, t_moves *moves, t_elem *elem)
{
	t_strokes	*inf;
	t_strokes	*sup;
	t_moves		*inf_moves;
	t_moves		*sup_moves;

	inf = malloc(sizeof(t_strokes));
	sup = malloc(sizeof(t_strokes));
	if (!inf || !sup)
		return (free(inf), free(sup), -1);
	inf_moves = NULL;
	sup_moves = NULL;
	init_limits(inf, sup, *a, elem);
	if (inf->index > -1)
		inf_moves = inst_nb(inf, *a, *b, INF);
	if (sup->index > -1)
		sup_moves = inst_nb(sup, *a, *b, SUP);
	if (!inf_moves && !sup_moves)
		return (free(inf), free(sup), free(sup_moves), free(inf_moves), -1);
	if (inf->index < 0)
		equal(moves, sup_moves, inf_moves);
	else if (sup->index < 0 || inf_moves->total <= sup_moves->total)
		equal(moves, inf_moves, sup_moves);
	else
		equal(moves, sup_moves, inf_moves);
	return (free(inf), free(sup), 0);
}

int	best_stroke(t_stack **a, t_stack **b, t_moves *moves)
{
	t_moves	*current;
	t_stack	*tmp;
	t_elem	*elem;

	tmp = *b;
	elem = malloc(sizeof(t_elem));
	if (!elem)
		return (-1);
	elem->index = 0;
	elem->nb = tmp->nb;
	find_best(a, b, moves, elem);
	while (tmp->next)
	{
		current = malloc(sizeof(t_moves));
		if (!current)
			return (free(elem), -1);
		best_stroke_add(&tmp, &elem);
		if (find_best(a, b, current, elem) < 0)
			return (free(elem), free(current), -1);
		if (current->total < moves->total)
			equal(moves, current, NULL);
		else
			free(current);
	}
	return (free(elem), 0);
}

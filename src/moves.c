/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:38:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/27 15:38:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	put_zero(t_moves *m)
{
	m->total = 0;
	m->rrb = 0;
	m->rra = 0;
	m->rb = 0;
	m->ra = 0;
}

void	move(t_stack **a, t_stack **b, t_moves *moves)
{
	if (moves->ra > 0 && moves->rb > 0)
	{
		while (--moves->ra >= 0 && --moves->rb >= 0)
			chose_inst(a, b, RR);
		if (moves->ra >= 0)
			++moves->ra;
		else
			--moves->rb;
	}
	while (--moves->ra >= 0)
		chose_inst(a, b, RA);
	while (--moves->rb >= 0)
		chose_inst(a, b, RB);
	if (moves->rra > 0 && moves->rrb > 0)
	{
		while (--moves->rra >= 0 && --moves->rrb >= 0)
			chose_inst(a, b, RRR);
		if (moves->rra >= 0)
			++moves->rra;
		else
			--moves->rrb;
	}
	while (--moves->rra >= 0)
		chose_inst(a, b, RRA);
	while (--moves->rrb >= 0)
		chose_inst(a, b, RRB);
	push(b, a, "pa");
}

void	check_rr_rrr(t_strokes st, t_moves *moves)
{
	put_zero(moves);
	moves->rra = st.rra;
	moves->rrb = st.rrb;
	if (moves->rra <= moves->rrb)
		moves->total = moves->rrb;
	else
		moves->total = moves->rra;
	if ((st.ra > st.rb && st.ra < moves->total)
		|| (st.rb > st.ra && st.rb < moves->total))
	{
		put_zero(moves);
		moves->ra = st.ra;
		moves->rb = st.rb;
		if (moves->ra <= moves->rb)
			moves->total = moves->rb;
		else
			moves->total = moves->ra;
	}
}

void	check_rot_rev_rot(t_strokes st, t_moves *moves)
{
	if (st.ra + st.rrb < moves->total)
	{
		put_zero(moves);
		moves->ra = st.ra;
		moves->rrb = st.rrb;
		moves->total = moves->ra + moves->rrb;
	}
	if (st.rb + st.rra < moves->total)
	{
		put_zero(moves);
		moves->rb = st.rb;
		moves->rra = st.rra;
		moves->total = moves->rb + moves->rra;
	}
}

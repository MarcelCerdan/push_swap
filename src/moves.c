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

void	move(t_stack **a, t_stack **b, t_moves *moves)
{
	while (moves->ra-- > 1 || moves->rb-- > 1)
		chose_inst(a, b, RR);
	while (moves->ra-- > 1)
		chose_inst(a, b, RA);
	while (moves->rb-- > 1)
		chose_inst(a, b, RB);
	while (moves->rra-- > 1 && moves->rrb-- > 1)
		chose_inst(a, b, RRR);
	while (moves->rra-- > 1)
		chose_inst(a, b, RRA);
	while (moves->rrb-- > 1)
		chose_inst(a, b, RRB);
	push(b, a);
	ft_printf("pa\n");
}

void	check_rr_rrr(t_strokes st, t_moves *moves)
{
	ft_bzero(moves, 1);
	moves->rra = st.rra;
	moves->rrb = st.rrb;
	if (moves->rra <= moves->rrb)
		moves->total = moves->rrb;
	else
		moves->total = moves->rra;
	if (st.ra < moves->total || st.rb < moves->total)
	{
		ft_bzero(moves, 1);
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
		ft_bzero(moves, 1);
		moves->ra = st.ra;
		moves->rrb = st.rrb;
		moves->total = moves->ra + moves->rrb;
	}
	if (st.rb + st.rra < moves->total)
	{
		ft_bzero(moves, 1);
		moves->rb = st.rb;
		moves->rra = st.rra;
		moves->total = moves->rb + moves->rra;
	}
}

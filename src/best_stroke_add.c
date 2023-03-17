/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_stroke_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:38:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/03/17 11:38:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_stroke_add(t_stack **tmp, t_elem **elem)
{
	(*tmp) = (*tmp)->next;
	(*elem)->index++;
	(*elem)->nb = (*tmp)->nb;
}

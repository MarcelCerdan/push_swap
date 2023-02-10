/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:04:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/23 16:04:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	chose_inst(t_stack **a, t_stack **b, int inst)
{
	if (inst == RA)
		return (rotate(*a), ft_printf("ra\n"));
	else if (inst == RB)
		return (rotate(*b), ft_printf("rb\n"));
	else if (inst == RR)
		return (rotate(*a), rotate(*b), ft_printf("rr\n"));
	else if (inst == RRA)
		return (rev_rotate(*a), ft_printf("rra\n"));
	else if (inst == RRB)
		return (rev_rotate(*b), ft_printf("rrb\n"));
	else if (inst == RRR)
		return (rev_rotate(*a), rev_rotate(*b), ft_printf("rrr\n"));
	return (-1);
}

void	swap(t_stack **a, char *str)
{
	int	tmp;

	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	ft_printf(str);
	ft_printf("\n");
}

t_stack	**push(t_stack **a, t_stack **b, char *str)
{
	t_stack	**new_b;

	if (stack_size(*a) == 0)
		return (b);
	new_b = create_elem((*a)->nb, b);
	del_elem(a);
	ft_printf(str);
	ft_printf("\n");
	return (new_b);
}

void	rotate(t_stack *stack)
{
	int		first;

	first = stack->nb;
	while (stack->next)
	{
		stack->nb = stack->next->nb;
		stack = stack->next;
	}
	stack->nb = first;
}

void	rev_rotate(t_stack *stack)
{
	t_stack	*tmp;
	int		*nb;
	int		i;

	nb = malloc(sizeof(int) * stack_size(stack));
	if (!nb)
		error(NULL);
	i = -1;
	tmp = stack;
	while (tmp)
	{
		nb[++i] = tmp->nb;
		tmp = tmp->next;
	}
	free(tmp);
	stack->nb = nb[i];
	stack = stack->next;
	i = -1;
	while (stack)
	{
		stack->nb = nb[++i];
		stack = stack->next;
	}
	free(nb);
}

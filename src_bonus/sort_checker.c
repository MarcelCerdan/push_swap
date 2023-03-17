/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:43:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/02/10 22:43:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

int	b_instructions(t_stack **b, char *line)
{
	int	len;

	len = (int)ft_strlen(line) - 1;
	if (ft_strncmp(line, "rb", 2) == 0 && len == 2)
	{
		if (b)
			rotate(*b);
		return (0);
	}
	else if (ft_strncmp(line, "rrb", 3) == 0 && len == 3)
	{
		if (b)
			if (rev_rotate(*b) < 0)
				return (-1);
		return (0);
	}
	else if (ft_strncmp(line, "sb", 2) == 0 && len == 2)
	{
		if (b)
			swap_checker(b);
		return (0);
	}
	return (1);
}

void	do_rr_rrr(t_stack **a, t_stack **b, char *line, int len)
{
	if (ft_strncmp(line, "rr", 2) == 0 && len == 2)
	{
		if (a)
			rotate(*a);
		if (b)
			rotate(*b);
	}
	else if (ft_strncmp(line, "rrr", 3) == 0 && len == 3)
	{
		if (a)
		{
			if (rev_rotate(*a) < 0)
				return (free(line), error_malloc(a, b, "do_rr_rrr"));
		}
		if (b)
		{
			if (rev_rotate(*b) < 0)
				return (free(line), error_malloc(a, b, "do_rr_rrr"));
		}
	}
	else
	{
		if (b)
			clear_stack(b);
		return (clear_stack(a), error(line));
	}
}

int	is_sort(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->next->nb < stack->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	rotate(t_stack *stack)
{
	int		first;

	if (stack_size(stack) <= 1)
		return ;
	first = stack->nb;
	while (stack->next)
	{
		stack->nb = stack->next->nb;
		stack = stack->next;
	}
	stack->nb = first;
}

int	rev_rotate(t_stack *stack)
{
	t_stack	*tmp;
	int		*nb;
	int		i;

	if (stack_size(stack) <= 1)
		return (0);
	nb = malloc(sizeof(int) * stack_size(stack));
	if (!nb)
		return (-1);
	i = -1;
	tmp = stack;
	while (tmp)
	{
		nb[++i] = tmp->nb;
		tmp = tmp->next;
	}
	stack->nb = nb[i];
	stack = stack->next;
	i = -1;
	while (stack)
	{
		stack->nb = nb[++i];
		stack = stack->next;
	}
	return (free(nb), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:52:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/03/24 13:17:51 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	clear_stack(t_stack **a)
{
	if (a)
	{
		while (*a)
			del_elem(a);
		free(a);
	}
}

static void	skip(t_stack **tmp, int min, int *min_index)
{
	int	index;

	index = 0;
	while (*tmp)
	{
		if ((*tmp)->nb < min)
		{
			min = (*tmp)->nb;
			*min_index = index;
		}
		index++;
		(*tmp) = (*tmp)->next;
	}
}

void	final_rot(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		min_index;
	int		i;

	min_index = 0;
	tmp = *a;
	min = tmp->nb;
	skip(&tmp, min, &min_index);
	i = stack_size(*a) - min_index;
	if (i < min_index)
	{
		while (--i >= 0)
		{
			if (chose_inst(a, NULL, RRA) < 0)
				error_malloc(a, NULL, "final_rot");
		}
	}
	else
	{
		while (--min_index >= 0)
			chose_inst(a, NULL, RA);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		*args;
	t_stack	**a_stack;

	if (ac == 1)
		return (0);
	args = malloc(sizeof (int) * (ac - 1));
	check_malloc(args, NULL, NULL, "main");
	check_args (ac, av, args);
	a_stack = NULL;
	i = -1;
	while (++i < ac - 1)
	{
		a_stack = create_elem(args[i], a_stack);
		if (!a_stack)
			error(args);
	}
	free(args);
	if (is_sort(*a_stack))
		return (clear_stack(a_stack), 0);
	if (ac <= 4)
		return (small_sort(a_stack), clear_stack(a_stack), 0);
	sort(a_stack, ac);
	final_rot(a_stack);
	return (clear_stack(a_stack), 0);
}

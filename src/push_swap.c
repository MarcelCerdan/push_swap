/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:52:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/17 12:52:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void final_rot(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		index;
	int		min_index;
	int		i;

	index = 0;
	min_index = 0;
	tmp = *a;
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
		{
			min = tmp->nb;
			min_index = index;
		}
		index++;
		tmp = tmp->next;
	}
	i = stack_size(*a) - min_index;
	if (i < min_index)
	{
		while (--i >= 0)
			chose_inst(a, NULL, RRA);
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

	args = malloc (sizeof (int) * (ac - 1));
	check_args (ac, av, args);
	a_stack = NULL;
	i = -1;
	while (++i < ac - 1)
		a_stack = create_elem (args[i], a_stack);
	if (is_sort(*a_stack))
		return (0);
	sort(a_stack);
	final_rot(a_stack);
	/*t_stack *tmp = *a_stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}*/
}


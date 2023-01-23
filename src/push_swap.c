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

int	main(int ac, char **av)
{
	int i;
	int *args;
	t_stack **a_stack;
	t_stack **b_stack;

	args = malloc (sizeof (int) * (ac - 1));
	check_args (ac, av, args);
	a_stack = NULL;
	b_stack = NULL;
	i = -1;
	while (++i < ac - 1)
		a_stack = create_elem (args[i], a_stack);
	rev_rotate(*a_stack);
	t_stack *tmp = *a_stack;
	while (tmp)
	{
		ft_printf("B_stack : %d\n", tmp->nb);
		tmp = tmp->next;
	}
}

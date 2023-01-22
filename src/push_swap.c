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
	int		i;
	int		*args;
	t_stack	*a_stack;
	t_stack *tmp;

	if (ac <= 2)
		error();
	args = check_args(ac, av);
	if (args == NULL)
		error();
	i = 0;
	a_stack = create_stack_elem(args[i]);
	while (args[++i])
	{
		tmp = create_stack_elem(args[i]);
		push_front(&a_stack, tmp);
	}
	ft_printf("%d\n", a_stack->next->nb);
}


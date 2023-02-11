/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:37:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/02/10 19:37:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "get_next_line.h"
#include "libft.h"

void	swap_checker(t_stack **a)
{
	int	tmp;

	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
}

t_stack	**push_check(t_stack **a, t_stack **b)
{
	t_stack	**new_b;

	if (stack_size(*a) == 0)
		return (b);
	new_b = create_elem((*a)->nb, b);
	del_elem(a);
	return (new_b);
}

static t_stack	**do_instruction(t_stack **a, t_stack **b, char *line)
{
	int	len;

	len = (int)ft_strlen(line) - 1;
	if (ft_strncmp(line, "pa", 2) == 0 && len == 2)
		push_check(b, a);
	else if (ft_strncmp(line, "pb", 2) == 0 && len == 2)
		b = push_check(a, b);
	else if (ft_strncmp(line, "ra", 2) == 0 && len == 2)
		rotate(*a);
	else if (ft_strncmp(line, "rra", 3) == 0 && len == 3)
		rev_rotate(*a);
	else if (ft_strncmp(line, "sa", 2) == 0 && len == 2)
		swap_checker(a);
	else
		do_rr_rrr(a, b, line, len);
	return (b);
}

static void	check_instructions(t_stack **a)
{
	int		result;
	char	*line;
	t_stack	**b;

	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		result = b_instructions(b, line);
		if (result == 1)
			b = do_instruction(a, b, line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sort(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	int		i;
	int		*args;
	t_stack	**a;

	if (ac == 1)
		return (0);
	args = malloc(sizeof (int) * (ac - 1));
	if (!args)
		error(NULL);
	check_args (ac, av, args);
	a = NULL;
	i = -1;
	while (++i < ac - 1)
		a = create_elem (args[i], a);
	check_instructions(a);
	return (0);
}

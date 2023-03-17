/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:53:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/02/10 22:53:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

void	check_malloc(void *ptr, t_stack **a, t_stack **b, char *str)
{
	if (!ptr)
		error_malloc(a, b, str);
}

void	error_malloc(t_stack **a, t_stack **b, char *str)
{
	if (a != NULL)
		clear_stack(a);
	if (b != NULL)
		clear_stack(b);
	write(2, str, ft_strlen(str));
	write(2, " : malloc error\n", 16);
	exit(1);
}

void	error(void *elem)
{
	if (elem != NULL)
		free(elem);
	write(2, "Error\n", 6);
	exit(1);
}

static void	check_duplicate(int ac, int *args)
{
	int	j;
	int	i;

	j = -1;
	while (++j < ac - 1)
	{
		i = j;
		while (++i < ac - 1)
		{
			if (args[i] == args[j])
				error(args);
		}
	}
}

void	*check_args(int ac, char **av, int *args)
{
	int		i;
	char	*str;

	i = 0;
	while (++i <= (ac - 1))
	{
		args[ac - 1 - i] = ft_atoi(av[i]);
		str = ft_itoa(args[ac - 1 - i]);
		if (!str)
			error(args);
		if ((ft_strncmp(str, av[i], ft_strlen(av[i])) != 0
				&& av[i][0] != '+')
				|| (ft_strncmp(str, av[i] + 1, ft_strlen(av[i]) - 1) != 0
				&& av[i][0] == '+'))
		{
			free(str);
			error(args);
		}
		free(str);
	}
	check_duplicate(ac, args);
	return (args);
}

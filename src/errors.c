/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:00:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/20 14:00:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	check_malloc(void *ptr, void *free)
{
	if (!ptr)
		error(free);
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
			error(NULL);
		if (ft_strncmp(str, av[i], ft_strlen(av[i])) != 0)
			error(args);
		free(str);
	}
	check_duplicate(ac, args);
	return (args);
}

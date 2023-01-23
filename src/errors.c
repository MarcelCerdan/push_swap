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

void	error(void *elem)
{
	if (elem != NULL)
		free(elem);
	write(2, "Error\n", 6);
	exit(1);
}

void	*check_args(int ac, char **av, int *args)
{
	int	i;
	int	j;

	i = 0;
	if (args == NULL || ac <= 2)
		error(args);
	while (++i <= (ac - 1))
	{
		args[ac - 1 - i] = ft_atoi(av[i]);
		if (ft_strncmp(ft_itoa(args[ac - 1 - i]), av[i], ft_strlen(av[i])) != 0)
			error(args);
	}
	args[ac - 1] = 0;
	j = -1;
	while (++j < ac - 1)
	{
		i = j;
		while (++i <= ac - 1)
		{
			if (args[i] == args[j])
				error(args);
		}
	}
	return (args);
}

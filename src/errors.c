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

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	*check_args(int ac, char **av)
{
	int	*args;
	int	i;
	int	j;

	i = 0;
	args = malloc(sizeof(int) * (ac - 1));
	if (args == NULL)
		return (NULL);
	while (++i < ac)
	{
		args[i - 1] = ft_atoi(av[i]);
		if (ft_strncmp(ft_itoa(args[i - 1]), av[i], ft_strlen(av[i])) != 0)
			return (free(args), NULL);
	}
	j = 0;
	while (++j < ac - 1)
	{
		i = j;
		while (++i <= ac - 1)
		{
			if (args[i] == args[j])
				return (free(args), NULL);
		}
	}
	return (args);
}

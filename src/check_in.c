/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:43:28 by lleiria-          #+#    #+#             */
/*   Updated: 2022/06/06 15:36:24 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (ERROR);
		i++;
	}
	return (NICE);
}

int	is_rep(int ac, char **av)
{
	int	i;
	int	n;
	int	nbr;

	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		n = 1;
		while (n < ac)
		{
			if (ft_atoi(av[n]) == nbr && n != i)
				return (ERROR);
			n++;
		}
		i++;
	}
	return (NICE);
}

int	limits(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (ERROR);
		i++;
	}
	return (NICE);
}

int	one_signal(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if ((av[i][0] == '-' || av[i][0] == '+') &&
				(av[i][1] < '0' || av[i][1] > '9' || !av[i][1]))
			return (ERROR);
		i++;
	}
	return (NICE);
}

int	check_in(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac <= 1)
		return (ERROR);
	while (i < ac)
	{
		if (!av[i][0])
			return (ERROR);
		if (!is_nbr(av[i]))
			return (ERROR);
		i++;
	}
	if (!is_rep(ac, av) || !limits(ac, av) || !one_signal(ac, av))
		return (ERROR);
	return (NICE);
}

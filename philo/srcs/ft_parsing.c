/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:37:19 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/09 14:00:52 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parsing(int ac, char **av)
{
	int	i;

	i = 0;
	if (ft_check_nb_args(ac) == 1)
		return (1);
	if (ft_atoi(av[1]) <= 0)
	{
		printf("Error : you should have at least one philosopher\n");
		return (1);
	}
	while (av[++i])
	{
		if (ft_check_empty(av[i]) == 1)
			return (1);
		if (ft_check_args(av[i]) == 1)
			return (1);
		if (ft_atoi(av[i]) > INT_MAX)
		{
			printf("Error : number higher than int max\n");
			return (1);
		}
	}
	return (0);
}

int	ft_check_nb_args(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error : invalid number of arguments\n");
		return (1);
	}
	return (0);
}

int	ft_check_empty(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (av[i] != ' ' && av[i] != '\0')
			return (0);
	}
	printf("Error : empty argument\n");
	return (1);
}

int	ft_check_args(char *av)
{
	int	i;

	i = 0;
	while (av[i] == ' ')
		i++;
	while (av[i] >= '0' && av[i] <= '9')
		i++;
	while (av[i] == ' ')
		i++;
	if (av[i] == 0)
		return (0);
	printf("Error : should be a (positiv) number\n");
	return (1);
}

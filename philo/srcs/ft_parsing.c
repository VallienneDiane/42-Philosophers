/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:37:19 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/02 16:39:41 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parsing(int ac, char **av)
{
	if (ft_nbr_args(ac) == 1)
		return (1);
	if (ft_is_ms(av) == 1)
		return (1);
	return (0);
}

int	ft_nbr_args(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error : invalid number of arguments\n");
		return (1);
	}
	return (0);
}

int	ft_is_ms(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] > '9' || av[i][j] == '-')
			{
				printf("Error : milliseconds should be a (positive) number\n");
				return (1);
			}
		}
	}
	return (0);
}

void	ft_get_param(int ac, char **av, t_param *param)
{
	param->nb_philo = ft_atoi(av[1]);
	param->time_to_die = ft_atoi(av[2]);
	param->time_to_eat = ft_atoi(av[3]);
	param->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		param->nb_must_eat = ft_atoi(av[5]);
}

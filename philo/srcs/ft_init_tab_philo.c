/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:09:24 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/09 13:52:39 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_get_param(int ac, char **av, t_param *param)
{
	param->nb_philo = ft_atoi(av[1]);
	param->time_to_die = ft_atoi(av[2]);
	param->time_to_eat = ft_atoi(av[3]);
	param->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		param->nb_must_eat = ft_atoi(av[5]);
}

int	ft_init_tab_philo(t_param *param)
{
	int		i;
	t_philo	philo;
	t_philo	*tab;

	i = -1;
	tab = malloc(sizeof(t_philo) * param->nb_philo);
	if (!tab)
	{
		free(&param->tab);
		return (0);
	}
	while (++i < param->nb_philo)
	{
		ft_init_mutex(&philo);
		philo.id = i + 1;
		philo.time_last_meal = 0;
		philo.nb_meal = 0;
		philo.lock_fork = 0;
		philo.lock_dead = 0;
		philo.p = param;
		tab[i] = philo;
	}
	param->tab = tab;
	return (0);
}

void	ft_init_mutex(t_philo *philo)
{
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->death, NULL);
	pthread_mutex_init(&philo->meal, NULL);
}

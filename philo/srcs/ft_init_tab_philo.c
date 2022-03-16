/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:09:24 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/08 11:08:02 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

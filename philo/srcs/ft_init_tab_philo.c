/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:09:24 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/02 13:04:03 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_tab_philo(t_param *param)
{
	int i;
	t_philo	philo;
	t_philo	*tab_philo;

	i = -1;
	tab_philo = malloc(sizeof(t_philo) * param->nb_philo);
	if (!tab_philo)
	{
		free(&param->tab_philo);
		return (0);
	}
	while (++i < param->nb_philo)
	{
		philo.id = i + 1;
		philo.time_last_meal = 0;
		philo.nb_meal = 0;
		philo.lock_fork = 0;
		philo.dead = 0;
		philo.param = param;
		pthread_mutex_init(&philo.fork, NULL);
		tab_philo[i] = philo;
	}
	param->tab_philo = tab_philo;
	return (0);
}

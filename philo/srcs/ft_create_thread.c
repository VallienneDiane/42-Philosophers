/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:14:15 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/04 17:59:25 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_routine(void *philo)
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	phil->start = ft_ms();
	phil->time_last_meal = ft_ms();
	if (phil->p->nb_philo == 1)
	{
		printf("\e[1;31m%d ms %d died\n\e[0m", phil->p->time_to_die, phil->id);
		return (0);
	}
	while (1)
	{
		if (ft_philo_eat(phil) == 1)
			break ;
		if (ft_philo_sleep(phil) == 1)
			break ;
		if (ft_philo_think(phil) == 1)
			break ;
	}
	pthread_mutex_lock(&phil->death);
	phil->lock_dead = 1;
	pthread_mutex_unlock(&phil->death);
	ft_destroy_mutex(philo);
	return (0);
}

int	ft_create_thread(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->nb_philo)
	{
		usleep(1 * 100);
		if (pthread_create(&param->tab[i].thread, NULL, \
		ft_routine, &param->tab[i]) != 0)
		{
			printf("Error : failed to create thread");
			return (0);
		}
	}
	i = -1;
	while (++i < param->nb_philo)
	{
		if (pthread_join(param->tab[i].thread, NULL) != 0)
		{
			printf("Error : failed to join threads");
			return (0);
		}
	}
	return (0);
}

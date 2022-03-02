/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:14:15 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/02 13:55:44 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_start_routine(void *philo)
{
	t_philo	*phil;
		
	phil = (t_philo *)philo;
	phil->param->start = ft_get_time();
	phil->time_last_meal = ft_get_time();
	if (phil->param->nb_philo == 1)
	{
		printf("\033[93m%d ms %d died\n\033[0m", phil->param->time_to_die, phil->id);
		return (0);
	}
	while (1)
	{
		if (ft_philo_think(phil) == 1)
			break ;
		if (ft_philo_eat(phil) == 1)
			break ;
		if (ft_philo_sleep(phil) == 1)
			break ;
	}
	phil->dead = 1;
	ft_unlock_destroy(philo);
	return (0);
}

int	ft_create_thread(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->nb_philo)
	{
		usleep(1 * 100);
		if (pthread_create(&param->tab_philo[i].thread, NULL, ft_start_routine, &param->tab_philo[i]) != 0)	
		{
			printf("Error : failed to create thread");
			return (0);
		}
	}
	i = -1;
	while (++i < param->nb_philo)
	{
		if (pthread_join(param->tab_philo[i].thread, NULL) != 0)
		{
			printf("Error : failed to join threads");
			return (0);
		}
	}
	return (0);
}

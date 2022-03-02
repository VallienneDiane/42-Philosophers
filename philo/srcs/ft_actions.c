/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:59:08 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/02 12:55:33 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_think(t_philo *philo)
{
	printf("\033[96m%ld %d is thinking\n\033[0m", (ft_get_time() - philo->param->start), philo->id);
	while (1)
	{
		if (philo->lock_fork == 0)
			break ;
		if (ft_check_death(philo) == 1)
			return (1);
		usleep(1 * 100);	
	}
	philo->lock_fork = 1;
	pthread_mutex_lock(&philo->fork);
	printf("\033[92m%ld %d has taken a fork\n\033[0m", (ft_get_time() - philo->param->start), philo->id);
	while (1)
	{
		if (philo->param->tab_philo[philo->id % philo->param->nb_philo].lock_fork == 0)
			break ;
		if (ft_check_death(philo) == 1)
			return (1);
		usleep(1 * 100);
	}
	philo->param->tab_philo[philo->id % philo->param->nb_philo].lock_fork = 1;
	pthread_mutex_lock(&philo->param->tab_philo[philo->id % philo->param->nb_philo].fork);
	printf("\033[92m%ld %d has taken a fork\n\033[0m", (ft_get_time() - philo->param->start), philo->id);
	return (0);
}

int	ft_philo_eat(t_philo *philo)
{	
	printf("\033[92m%ld %d is eating\n\033[0m", (ft_get_time() - philo->param->start), philo->id);
	philo->nb_meal++;
	if (philo->param->nb_must_eat)
		if (ft_check_nb_meal(philo) == 1)
			return (1);
	philo->time_last_meal = ft_get_time();
	while (ft_get_time() - philo->time_last_meal < philo->param->time_to_eat)
	{
		if (ft_check_death(philo) == 1)
			return (1);
		usleep(1 * 100);
	}
	philo->lock_fork = 0;
	philo->param->tab_philo[philo->id % philo->param->nb_philo].lock_fork = 0;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->param->tab_philo[philo->id % philo->param->nb_philo].fork);
	return (0);
}

int	ft_philo_sleep(t_philo *philo)
{
	int		i;
	
	i = -1;
	printf("\033[95m%ld %d is sleeping\n\033[0m", (ft_get_time() - philo->param->start), philo->id);
	while (ft_get_time() < (philo->param->time_to_sleep + philo->param->time_to_eat + philo->time_last_meal))
	{
		if (ft_check_death(philo) == 1)
			return (1);
		usleep(1 * 100);
	}
	return (0);
}

int	ft_check_death(t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < philo->param->nb_philo)
	{
		if (philo->param->tab_philo[i].dead == 1)
			return (1);
	}
	if ((ft_get_time() - philo->time_last_meal) > philo->param->time_to_die)
	{
		printf("\033[93m%ld %d died\n\033[0m", (ft_get_time() - philo->param->start), philo->id);
		philo->dead = 1;
		return (1);
	}
	return (0);
}

int	ft_check_nb_meal(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->param->nb_philo)
	{
		if (philo->param->tab_philo[i].nb_meal < philo->param->nb_must_eat)
			return (0);
	}
	return (1);
}

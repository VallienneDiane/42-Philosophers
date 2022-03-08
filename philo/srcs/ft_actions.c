/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:59:08 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/08 16:15:00 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_think(t_philo *philo)
{
	printf("\e[1;36m%ld %d is thinking\n\e[0m", ft_ms() - philo->start, philo->id);
	if (ft_check_death(philo) == 1)
		return (1);
	return (0);
}

int	ft_first_fork(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		if (philo->lock_fork == 0)
		{
			philo->lock_fork = 1;
			pthread_mutex_unlock(&philo->fork);
			break ;
		}
		pthread_mutex_unlock(&philo->fork);
		if (ft_check_death(philo) == 1)
			return (1);
		ft_usleep(philo);
	}
	printf("\e[1;35m%ld %d has taken a fork\n\e[0m", \
	ft_ms() - philo->start, philo->id);
	return (0);
}

int	ft_second_fork(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->p->tab[philo->id % philo->p->nb_philo].fork);
		if (philo->p->tab[philo->id % philo->p->nb_philo].lock_fork == 0)
		{
			philo->p->tab[philo->id % philo->p->nb_philo].lock_fork = 1;
			pthread_mutex_unlock(&philo->p->tab[philo->id \
			% philo->p->nb_philo].fork);
			break ;
		}
		pthread_mutex_unlock(&philo->p->tab[philo->id \
		% philo->p->nb_philo].fork);
		if (ft_check_death(philo) == 1)
			return (1);
		ft_usleep(philo);
	}
	printf("\e[1;35m%ld %d has taken a fork\n\e[0m", \
	ft_ms() - philo->start, philo->id);
	printf("\e[1;32m%ld %d is eating\n\e[0m", ft_ms() - philo->start, philo->id);
	pthread_mutex_lock(&philo->meal);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->meal);
	return (0);
}

int	ft_philo_eat(t_philo *philo)
{	
	if (ft_first_fork(philo) == 1)
		return (1);
	if (ft_second_fork(philo) == 1)
		return (1);
	philo->time_last_meal = ft_ms();
	while (ft_ms() - philo->time_last_meal < philo->p->time_to_eat)
	{
		if (ft_check_death(philo) == 1)
			return (1);
		ft_usleep(philo);
	}
	if (philo->p->nb_must_eat)
	{
		if (ft_check_nb_meal(philo) == 1)
			return (1);
	}
	pthread_mutex_lock(&philo->fork);
	philo->lock_fork = 0;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_lock(&philo->p->tab[philo->id % philo->p->nb_philo].fork);
	philo->p->tab[philo->id % philo->p->nb_philo].lock_fork = 0;
	pthread_mutex_unlock(&philo->p->tab[philo->id % philo->p->nb_philo].fork);
	return (0);
}

int	ft_philo_sleep(t_philo *philo)
{
	int		i;

	i = -1;
	printf("\e[1;30m%ld %d is sleeping\n\e[0m", ft_ms() - philo->start, \
	philo->id);
	while (ft_ms() < (philo->p->time_to_sleep + philo->p->time_to_eat + \
	philo->time_last_meal))
	{
		if (ft_check_death(philo) == 1)
			return (1);
		ft_usleep(philo);
	}
	return (0);
}

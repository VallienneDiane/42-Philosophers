/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:07:45 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/08 16:10:58 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(t_philo *philo)
{
	if (philo->p->nb_philo > 50)
		usleep(1000);
	else if (philo->p->nb_philo > 100)
		usleep(10000);
	else
		usleep(100);
}

int	ft_check_death(t_philo *philo)
{
	int		i;

	i = -1;
	while (++i < philo->p->nb_philo)
	{
		pthread_mutex_lock(&philo->p->tab[i].death);
		if (philo->p->tab[i].lock_dead == 1)
		{
			pthread_mutex_unlock(&philo->p->tab[i].death);
			return (1);
		}
		pthread_mutex_unlock(&philo->p->tab[i].death);
	}
	if ((ft_ms() - philo->time_last_meal) >= philo->p->time_to_die)
	{
		printf("\e[1;31m%ld %d died\n\e[0m", (ft_ms() - philo->start), philo->id);
		return (1);
	}
	return (0);
}

int	ft_check_nb_meal(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->p->nb_philo)
	{
		pthread_mutex_lock(&philo->p->tab[i].meal);
		if (philo->p->tab[i].nb_meal < philo->p->nb_must_eat)
		{
			pthread_mutex_unlock(&philo->p->tab[i].meal);
			return (0);
		}
		pthread_mutex_unlock(&philo->p->tab[i].meal);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:07:45 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/07 16:10:32 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		pthread_mutex_lock(&philo->death);
		philo->lock_dead = 1;
		pthread_mutex_unlock(&philo->death);
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
		if (philo->p->tab[i].nb_meal <= philo->p->nb_must_eat)
		{
			pthread_mutex_unlock(&philo->p->tab[i].meal);
			return (0);
		}
		pthread_mutex_unlock(&philo->p->tab[i].meal);
	}
	return (1);
}

void	ft_usleep(t_philo *philo)
{
	if (philo->p->nb_philo > 40)
		usleep(1 * 1000);
	else
		usleep(1 * 100);
}

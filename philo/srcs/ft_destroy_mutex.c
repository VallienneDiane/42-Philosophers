/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:43:40 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:30 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_destroy_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->p->nb_philo)
	{
		pthread_mutex_destroy(&philo->p->tab[i].fork);
		pthread_mutex_destroy(&philo->p->tab[i].death);
		pthread_mutex_destroy(&philo->p->tab[i].meal);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:43:40 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/02 13:53:02 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_unlock_destroy(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->param->nb_philo)
	{
		pthread_mutex_unlock(&philo->param->tab_philo[i].fork);
		pthread_mutex_destroy(&philo->param->tab_philo[i].fork);
	}
}
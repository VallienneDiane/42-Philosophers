/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:55:01 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/25 11:33:43 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_get_time()
{
	struct timeval	time;
	long			ms;
	
	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000;
	ms += (time.tv_usec / 1000);
	return (ms);
}
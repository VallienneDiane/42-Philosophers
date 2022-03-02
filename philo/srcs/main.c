/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:07:48 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/02 13:59:24 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_param	param;
	int		i;

	i = -1;
	if (ft_parsing(ac, av) == 0)
	{
		ft_get_param(ac, av, &param);
		ft_init_tab_philo(&param);
		ft_create_thread(&param);
		free(param.tab_philo);
	}
	return (0);
}

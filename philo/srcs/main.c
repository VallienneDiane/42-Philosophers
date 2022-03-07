/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:07:48 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/07 17:24:52 by dvallien         ###   ########.fr       */
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
		if (ft_create_thread(&param) == 1)
		{
			free(param.tab);
			return (0);
		}
		ft_destroy_mutex(param.tab);
		free(param.tab);
	}
	return (0);
}

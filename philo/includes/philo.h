/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:09:23 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/02 13:06:18 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_param
{
	struct s_philo	*tab_philo;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	long			start;
}		t_param;

typedef	struct s_philo
{
	t_param 		*param;
	int				id;
	long			time_last_meal;
	int				nb_meal;
	int				dead;
	int				lock_fork;
	pthread_t		thread;
	pthread_mutex_t	fork;
}		t_philo;


int			main(int ac, char **av);
int			ft_parsing(int ac, char **av);
int			ft_nbr_args(int ac);
int			ft_is_ms(char **av);
void		ft_get_param(int ac, char **av, t_param *param);
int			ft_init_tab_philo(t_param *param);
int			ft_create_thread(t_param *param);
void		*ft_start_routine(void *philo);
long int	ft_atoi(const char *str);
int			ft_philo_eat(t_philo *philo);
int			ft_philo_sleep(t_philo *philo);
int			ft_philo_think(t_philo *philo);
int			ft_get_time();
void		ft_unlock_destroy(t_philo *philo);
int			ft_check_death(t_philo *philo);
int			ft_check_nb_meal(t_philo *philo);
#endif
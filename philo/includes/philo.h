/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:09:23 by dvallien          #+#    #+#             */
/*   Updated: 2022/03/08 18:03:58 by dvallien         ###   ########.fr       */
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
	struct s_philo	*tab;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
}		t_param;

typedef struct s_philo
{
	t_param			*p;
	long			start;
	int				id;
	long			time_last_meal;
	int				nb_meal;
	int				lock_dead;
	int				lock_fork;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	death;
	pthread_mutex_t	meal;
}		t_philo;

int			main(int ac, char **av);
int			ft_parsing(int ac, char **av);
int			ft_check_nb_args(int ac);
int			ft_check_empty(char *av);
int			ft_check_args(char *av);
void		ft_get_param(int ac, char **av, t_param *param);
int			ft_init_tab_philo(t_param *param);
void		ft_init_mutex(t_philo *philo);
int			ft_create_thread(t_param *param);
void		ft_actions(t_philo *phil);
void		*ft_routine(void *philo);
long int	ft_atoi(const char *str);
int			ft_philo_eat(t_philo *philo);
int			ft_philo_sleep(t_philo *philo);
int			ft_philo_think(t_philo *philo);
int			ft_first_fork(t_philo *philo);
int			ft_second_fork(t_philo *philo);
void		ft_destroy_mutex(t_philo *philo);
int			ft_check_death(t_philo *philo);
int			ft_check_nb_meal(t_philo *philo);
int			ft_ms(void);
void		ft_usleep(t_philo *philo);
#endif
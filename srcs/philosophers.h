/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:21:10 by pgurn             #+#    #+#             */
/*   Updated: 2021/09/27 23:35:09 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos_state
{
	int				num_philos;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_sleep;
	int				num_eat;
	int				cnt;
	int				*lifetime;
	long			start_time;
	pthread_t		*phil;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
}	t_philos_state;

typedef struct s_philos
{
	int			id;
	int			eats;
}	t_philos;

/*
*	Utils(Lib) Functions
*/

size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
void			ft_putnbr_fd(uint64_t n, int fd);

/*
*	Utils(Tim) Functions
*/
long			get_duration(t_philos_state *state);
long			get_time(void);
void			sleep_ms(long ms);

/*
*	Philosophers
*/
void			ft_initialize(t_philos_state *state, int ac, char const **av);
void			ft_start_threads(t_philos_state state);
void			*inspector(void *state);
void			*philo(void *state);
void			ft_eating(t_philos_state *state, t_philos *phil_info);
void			phil_print(t_philos_state *state, int phil_num, char *text);
int				ft_phil_is_dead(t_philos_state *state);
void			free_all(t_philos_state state);

#endif
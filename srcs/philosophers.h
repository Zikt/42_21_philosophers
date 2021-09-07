/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:21:10 by pgurn             #+#    #+#             */
/*   Updated: 2021/09/06 23:01:51 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define EAT 	0
# define SLEEP 	1
# define FORK 	2
# define THINK	3
# define DIED 	4
# define OVER 	5

typedef struct s_philos
{
	int			id;
	int			is_eating;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	pthread_mutex_t mutex;
	pthread_mutex_t	eat_m;
}	t_philos;

typedef struct s_philos_state
{
	int				num_philos;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_sleep;
	int				num_eat;

	uint64_t		start;
	
	t_philos		*philos;
	pthread_mutex_t	*forks_m;
}	t_philos_state;

/*
*	Utils(Lib) Functions
*/

uint64_t		get_time(void);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
void			ft_putnbr_fd(uint64_t n, int fd);

/*
*	Philosophers
*/

int			ft_checker(int ac, char **av);
int			ft_parser(int ac, char **av, t_philos_state **state);
int			initialize(t_philos_state *state, int ac, char const **av);

#endif
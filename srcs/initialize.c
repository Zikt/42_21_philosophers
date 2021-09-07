/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:02:44 by pgurn             #+#    #+#             */
/*   Updated: 2021/09/06 23:10:57 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//init mutexes
static int		ft_init_mutexes(t_state *state)
{
	int i;
	
}

//init philos
static void		ft_init_philos()
{
	int i;

	i = 0;
	while(i < state->num_philos)
	{
		state->philos[i].id = i;
		state->philos[i].is_eating = 0;
		state->philos[i].left_fork = i;
		state->philos[i].right_fork = (i + 1) % state->num_philos;
		state->philos[i].eat_count = 0;
		//State?
		pthread_mutex_init(&state->philos[i].mutex, NULL);
		pthread_mutex_init(&state->philos[i].eat_m, NULL);
		pthread_mutex_lock(&state->philos[i].eat_m);
		i++;
	}
}

int		ft_initialize(t_philos_state *state, int ac, char const **av)
{
	//Set all
	state->num_philos = ft_atoi(av[1]);
	state->t_2_die = ft_atoi(av[2]);
	state->t_2_eat = = ft_atoi(av[3]);
	state->t_2_sleep = ft_atoi(av[4]);
	if (ac == 6)
		state->num_eat = ft_atoi(av[5]);
	else
		state->num_eat = 0;
	//any buufer time needed? Check why???
	state->forks_m = NULL;
	state->philos = NULL;
	if (!(state->philos =
		(t_philo*)malloc(sizeof(*(state->philos)) * state->amount)))
		return (1);
	init_philos(state);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:14:43 by pgurn             #+#    #+#             */
/*   Updated: 2021/09/27 22:53:44 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		ft_eating(t_philos_state *state, t_philos *phil_info)
{
	int		l_fork;
	int		r_fork;

	l_fork = phil_info->id - 1;
	if (phil_info->id == 1)
		r_fork = state->num_philos - 1;
	else
		r_fork = phil_info->id - 2;
	pthread_mutex_lock(&state->forks[r_fork]);
	phil_print(state, phil_info->id, "has taken a fork");
	pthread_mutex_lock(&state->forks[l_fork]);
	phil_print(state, phil_info->id, "has taken a fork");
	state->lifetime[phil_info->id - 1] = get_duration(state);
	phil_print(state, phil_info->id, "is eating");
	sleep_ms(state->t_2_eat);
	pthread_mutex_unlock(&state->forks[l_fork]);
	pthread_mutex_unlock(&state->forks[r_fork]);
}

void		*philo(void *state)
{
	t_philos phil_info;

	phil_info.eats = -1;
	if (((t_philos_state *)state)->num_eat > 0 )
		phil_info.eats = ((t_philos_state *)state)->num_eat;
	phil_info.id = ((t_philos_state *)state)->cnt + 1;
	pthread_mutex_unlock(&((t_philos_state *)state)->lock);
	((t_philos_state *)state)->lifetime[phil_info.id -1] = get_duration(state);
	if (!phil_info.id % 2)
		sleep_ms(((t_philos_state *)state)->t_2_eat / 2);
	while(phil_info.eats)
	{
		phil_print(state, phil_info.id, "is thinking");
		ft_eating(state, &phil_info);
		phil_print(state, phil_info.id, "is sleeping");
		sleep_ms(((t_philos_state *)state)->t_2_sleep);
		if (phil_info.eats > 0)
			phil_info.eats--;
	}
	if (phil_info.eats == 0)
	{
		((t_philos_state *)state)->cnt--;
		((t_philos_state *)state)->lifetime[phil_info.id - 1] = -1;
	}
	return (NULL);
}

void		*ft_inspector(void *state)
{
	int		alive;

	alive = 1;
	while(alive)
	{
		alive = ft_phil_is_dead(state);
		if (((t_philos_state *)state)->cnt <= 0
			&& ((t_philos_state *)state)->t_2_eat > 0 && alive)
			alive = 0;
	}
	sleep_ms(4);
	return (NULL);
}

void		ft_start_threads(t_philos_state state)
{
	pthread_t	inspector_thread;
	
	pthread_mutex_init(&state.lock, NULL);
	pthread_mutex_init(&state.print, NULL);
	state.cnt = 0;
	while(state.cnt < state.num_philos)
		pthread_mutex_init(&state.forks[state.cnt++], NULL);
	state.cnt = 0;
	while(state.cnt < state.num_philos)
	{
		pthread_mutex_lock(&state.lock);
		pthread_create(&state.phil[state.cnt], NULL, philo, (void *)&state);
		pthread_detach(state.phil[state.cnt]);
		state.cnt++;
		pthread_mutex_unlock(&state.lock);
	}
	pthread_mutex_destroy(&state.lock);
	pthread_create(&inspector_thread, NULL, ft_inspector, (void *) &state);
	pthread_join(inspector_thread, NULL);
	pthread_mutex_destroy(&state.print);
	state.cnt = 0;
	while(state.cnt < state.num_philos)
		pthread_mutex_destroy(&state.forks[state.cnt++]);
}


int	main(int ac, char const *av[])
{
	t_philos_state	state;
	
	if (ac < 5 || ac > 6)
	{
		write(2, "wrong number of arguments\n", 26);
		return (1);
	}
	state.num_philos = ft_atoi(av[1]);
	state.t_2_die = ft_atoi(av[2]);
	state.t_2_eat = ft_atoi(av[3]);
	state.t_2_sleep = ft_atoi(av[4]);
	state.num_eat = -1;
	if (ac == 6)
		state.num_eat = ft_atoi(av[5]);
	state.phil = NULL;
	state.forks = NULL;
	state.lifetime = NULL;
	state.start_time = get_time();
	state.phil = (pthread_t *)malloc(sizeof(pthread_t) * state.num_philos);
	state.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * state.num_philos);
	state.lifetime = (int *)malloc(sizeof(int) * state.num_philos);
	if (state.phil && state.forks && state.lifetime)
		ft_start_threads(state);
	free_all(state);
	return (0);
}
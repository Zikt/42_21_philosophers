/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:50:51 by pgurn             #+#    #+#             */
/*   Updated: 2021/09/25 17:05:48 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long		get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

long	get_duration(t_philos_state *state)
{
	struct timeval	curr_time;
	long			start_time;	

	start_time = state->start_time;
	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000) - start_time);
}

void	sleep_ms(long ms)
{
	long	time;

	time = get_time();
	while ((get_time() - time) < ms)
		usleep(100);
}

size_t			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	long long	result;
	int			i;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i++] == '-');
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > 214748365) || (result == 214748365 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		result = (result * 10) + str[i++] - 48;
	}
	return (result * sign);
}

void			ft_putnbr_fd(uint64_t n, int fd)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}

void	phil_print(t_philos_state *state, int phil_num, char *text)
{
	pthread_mutex_lock(&state->print);
	printf("%ld %d %s\n", get_duration(state), phil_num, text);
	pthread_mutex_unlock(&state->print);
}

int	ft_phil_is_dead(t_philos_state *state)
{
	int	count;
	int	time;

	count = 0;
	time = get_duration(state) - 2;
	while (count < state->num_philos)
	{
		if (state->lifetime[count] != -1)
		{
			if ((state->lifetime[count] + state->t_2_die) < time)
			{
				pthread_mutex_lock(&state->print);
				printf("%ld %d died\n", get_duration(state), count + 1);
				return (0);
			}
		}
		count++;
	}
	return (1);
}

void	free_all(t_philos_state state)
{
	if (state.phil)
		free(state.phil);
	if (state.forks)
		free(state.forks);
	if (state.lifetime)
		free(state.lifetime);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:14:43 by pgurn             #+#    #+#             */
/*   Updated: 2021/09/02 13:14:53 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//

int	main(int ac, char const *av[])
{
	t_philos_state	state;
	
	if (ac < 5 || ac > 6)
	{
		write(2, "wrong number of arguments\n", 26);
		return (1);
	}
	//check args via parser
	if (ft_parser(ac, av, &state))
	{
		write (2, "argument error\n", 15);
		return (1);
	}
	//initiate simulation
	ft_start_simulation(state);
	return (0);
}
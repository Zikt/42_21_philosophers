/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:52:07 by pgurn             #+#    #+#             */
/*   Updated: 2021/09/05 19:53:35 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char		*get_message(int type)
{
	if (type == EAT)
		return (" is eating\n");
	else if (type == SLEEP)
		return (" is sleeping\n");
	else if (type == FORK)
		return (" has taken a fork\n");
	else if (type == THINK)
		return (" is thinking\n");
	else if (type == OVER)
		return ("must eat count reached\n");
	return (" died\n");
}

//display message
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:05:06 by pgurn             #+#    #+#             */
/*   Updated: 2021/08/01 18:56:44 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;	
}					t_stack;

typedef struct		s_checker
{
	t_stack			*a;
	t_stack			*b;
	char			*line;
	char			*inst;
	char			**split;
}					t_checker;

/*
** Function prototypes start here
*/


#endif
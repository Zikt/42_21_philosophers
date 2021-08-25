/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:34:51 by pgurn             #+#    #+#             */
/*   Updated: 2021/08/01 18:55:25 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ALLOC_LINE(line)		if(!(line = ft_strnew(0))) return (-1)
# define ALLOC_OVERFLOW(over)	if(!(over = ft_strnew(BUFF_SIZE))) return (-1)
# define BUFF_SIZE	32
# define FD_MAX	1024

# include <stdlib.h>
# include "libft.h"

int			get_next_line(int fd, char **line);
void		strjoinfree(char **s1, char *s2);
void		strdupfree(char **dst, char *src);
void		save_line(char **line, char **overflow, char *endl);
int			read_line(int fd, char *buff, char **line, char **overflow);

#endif